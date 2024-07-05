// Benchmark constant-velocity rolling shutter camera.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>
#include <Eigen/Geometry>

#include <wrenfold/span_eigen.h>

#include "benchmarks/quat_interpolation_handwritten.h"
#include "camera_params_t.h"  //  Must be included before integrate_and_project.h

#include "generated/rolling_shutter_camera/sf/integrate_and_project_chain.h"
#include "generated/rolling_shutter_camera/sf/integrate_and_project_first_order.h"
#include "generated/rolling_shutter_camera/wf/integrate_and_project.h"
#include "generated/rolling_shutter_camera/wf/integrate_and_project_sffo.h"

#include "ceres_utils.h"
#include "rolling_shutter_camera_ceres.h"

struct projection_input {
  Eigen::Quaterniond world_R_imu;
  Eigen::Vector3d world_t_imu;
  Eigen::Quaterniond imu_R_cam;
  Eigen::Vector3d imu_t_cam;
  Eigen::Vector3d angular_velocity_imu;
  Eigen::Vector3d world_v_imu;
  Eigen::Vector3d p_world;
  double row_time;
  camera_params_t camera_params;
};

std::vector<projection_input> generate_projection_inputs(const std::size_t num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};
  const auto u = [&]() { return dist(engine); };

  std::vector<projection_input> inputs{};
  inputs.reserve(num_samples);
  for (std::size_t i = 0; i < num_samples; ++i) {
    projection_input sample{};
    sample.world_R_imu = Eigen::Quaterniond{Eigen::Vector4d{u(), u(), u(), u()}.normalized()};
    sample.world_t_imu = 50.0 * Eigen::Vector3d{u(), u(), u()};
    sample.imu_R_cam = Eigen::Quaterniond{Eigen::Vector4d{u(), u(), u(), u()}.normalized()};
    sample.imu_t_cam = 0.02 * Eigen::Vector3d{u(), u(), u()};
    sample.angular_velocity_imu = 0.1 * Eigen::Vector3d{u(), u(), u()};
    sample.world_v_imu = Eigen::Vector3d{u(), u(), u()};
    sample.p_world = (sample.world_R_imu * sample.imu_R_cam).toRotationMatrix() *
                         Eigen::Vector3d(-1.0, 1.1, 10.0) +
                     sample.world_t_imu;
    sample.row_time = (u() + 1.0) / 2.0 * 0.033;

    sample.camera_params =
        camera_params_t{250.0, 250.0, 319.5, 219.5, 0.01, -0.001, 0.0008, 0.001, -0.0001};
    inputs.push_back(sample);
  }
  return inputs;
}

template <typename F>
void bench_projection(benchmark::State& state, F&& func) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_projection_inputs(num_samples);

  Eigen::Vector2d p_image_out;
  Eigen::Matrix<double, 2, 3> D_world_R_imu;
  Eigen::Matrix<double, 2, 3> D_world_t_imu;
  Eigen::Matrix<double, 2, 3> D_imu_R_cam;
  Eigen::Matrix<double, 2, 3> D_imu_t_cam;
  Eigen::Matrix<double, 2, 3> D_angular_velocity_imu;
  Eigen::Matrix<double, 2, 3> D_world_v_imu;
  Eigen::Matrix<double, 2, 3> D_p_world;

  std::size_t index = 0;
  for (auto _ : state) {
    func(inputs[index].world_R_imu, inputs[index].world_t_imu, inputs[index].imu_R_cam,
         inputs[index].imu_t_cam, inputs[index].angular_velocity_imu, inputs[index].world_v_imu,
         inputs[index].p_world, inputs[index].row_time, inputs[index].camera_params, p_image_out,
         D_world_R_imu, D_world_t_imu, D_imu_R_cam, D_imu_t_cam, D_angular_velocity_imu,
         D_world_v_imu, D_p_world);
    benchmark::DoNotOptimize(p_image_out);
    benchmark::DoNotOptimize(D_world_R_imu);
    benchmark::DoNotOptimize(D_world_t_imu);
    benchmark::DoNotOptimize(D_imu_R_cam);
    benchmark::DoNotOptimize(D_imu_t_cam);
    benchmark::DoNotOptimize(D_angular_velocity_imu);
    benchmark::DoNotOptimize(D_world_v_imu);
    benchmark::DoNotOptimize(D_p_world);
    index = (index + 1) % inputs.size();
  }
}

void BM_RollingShutterCamera_SymforceChain(benchmark::State& state) {
  bench_projection(
      state,
      [](const Eigen::Quaterniond& world_R_imu_xyzw, const Eigen::Matrix<double, 3, 1>& world_t_imu,
         const Eigen::Quaterniond& imu_R_cam_xyzw, const Eigen::Matrix<double, 3, 1>& imu_t_cam,
         const Eigen::Matrix<double, 3, 1>& angular_velocity_imu,
         const Eigen::Matrix<double, 3, 1>& world_v_imu, const Eigen::Matrix<double, 3, 1>& p_world,
         const double row_time, const camera_params_t& camera, Eigen::Matrix<double, 2, 1>& p_image,
         Eigen::Matrix<double, 2, 3>& D_world_R_imu, Eigen::Matrix<double, 2, 3>& D_world_t_imu,
         Eigen::Matrix<double, 2, 3>& D_imu_R_cam, Eigen::Matrix<double, 2, 3>& D_imu_t_cam,
         Eigen::Matrix<double, 2, 3>& D_angular_velocity_imu,
         Eigen::Matrix<double, 2, 3>& D_world_v_imu, Eigen::Matrix<double, 2, 3>& D_p_world) {
        sym::IntegrateAndProjectChain(
            world_R_imu_xyzw.coeffs(), world_t_imu, imu_R_cam_xyzw.coeffs(), imu_t_cam,
            angular_velocity_imu, world_v_imu, p_world, row_time,
            (Eigen::Matrix<double, 9, 1>() << camera.fx, camera.fy, camera.cx, camera.cy, camera.k1,
             camera.k2, camera.k3, camera.p1, camera.p2)
                .finished(),
            &p_image, &D_world_R_imu, &D_world_t_imu, &D_imu_R_cam, &D_imu_t_cam,
            &D_angular_velocity_imu, &D_world_v_imu, &D_p_world);
      });
}

void BM_RollingShutterCamera_SymforceFirstOrder(benchmark::State& state) {
  bench_projection(
      state,
      [](const Eigen::Quaterniond& world_R_imu_xyzw, const Eigen::Matrix<double, 3, 1>& world_t_imu,
         const Eigen::Quaterniond& imu_R_cam_xyzw, const Eigen::Matrix<double, 3, 1>& imu_t_cam,
         const Eigen::Matrix<double, 3, 1>& angular_velocity_imu,
         const Eigen::Matrix<double, 3, 1>& world_v_imu, const Eigen::Matrix<double, 3, 1>& p_world,
         const double row_time, const camera_params_t& camera, Eigen::Matrix<double, 2, 1>& p_image,
         Eigen::Matrix<double, 2, 3>& D_world_R_imu, Eigen::Matrix<double, 2, 3>& D_world_t_imu,
         Eigen::Matrix<double, 2, 3>& D_imu_R_cam, Eigen::Matrix<double, 2, 3>& D_imu_t_cam,
         Eigen::Matrix<double, 2, 3>& D_angular_velocity_imu,
         Eigen::Matrix<double, 2, 3>& D_world_v_imu, Eigen::Matrix<double, 2, 3>& D_p_world) {
        sym::IntegrateAndProjectFirstOrder(
            world_R_imu_xyzw.coeffs(), world_t_imu, imu_R_cam_xyzw.coeffs(), imu_t_cam,
            angular_velocity_imu, world_v_imu, p_world, row_time,
            (Eigen::Matrix<double, 9, 1>() << camera.fx, camera.fy, camera.cx, camera.cy, camera.k1,
             camera.k2, camera.k3, camera.p1, camera.p2)
                .finished(),
            &p_image, &D_world_R_imu, &D_world_t_imu, &D_imu_R_cam, &D_imu_t_cam,
            &D_angular_velocity_imu, &D_world_v_imu, &D_p_world);
      });
}

void BM_RollingShutterCamera_Wrenfold(benchmark::State& state) {
  bench_projection(state, [](auto&&... args) {
    gen::integrate_and_project<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_RollingShutterCamera_SFOWrenfold(benchmark::State& state) {
  bench_projection(state, [](auto&&... args) {
    gen::integrate_and_project_sffo<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_RollingShutterCamera_Ceres(benchmark::State& state) {
  double row_time{};
  camera_params_t intrinsics{};
  const auto cost_function =
      utils::make_ceres_cost_function<autodiff_ceres::RollingShutterCameraProjection, 2, 13, 7, 3>(
          &row_time, &intrinsics);

  bench_projection(
      state,
      [&](const Eigen::Quaterniond& world_R_imu_xyzw,
          const Eigen::Matrix<double, 3, 1>& world_t_imu, const Eigen::Quaterniond& imu_R_cam_xyzw,
          const Eigen::Matrix<double, 3, 1>& imu_t_cam,
          const Eigen::Matrix<double, 3, 1>& angular_velocity_imu,
          const Eigen::Matrix<double, 3, 1>& world_v_imu,
          const Eigen::Matrix<double, 3, 1>& p_world, const double row_time_in,
          const camera_params_t& camera, Eigen::Matrix<double, 2, 1>& p_image,
          Eigen::Matrix<double, 2, 3>& D_world_R_imu, Eigen::Matrix<double, 2, 3>& D_world_t_imu,
          Eigen::Matrix<double, 2, 3>& D_imu_R_cam, Eigen::Matrix<double, 2, 3>& D_imu_t_cam,
          Eigen::Matrix<double, 2, 3>& D_angular_velocity_imu,
          Eigen::Matrix<double, 2, 3>& D_world_v_imu, Eigen::Matrix<double, 2, 3>& D_p_world) {
        // Update variables shared with the cost function above via pointer:
        row_time = row_time_in;
        intrinsics = camera;

        const auto camera_state = (Eigen::Matrix<double, 13, 1>() << world_R_imu_xyzw.coeffs(),
                                   world_t_imu, angular_velocity_imu, world_v_imu)
                                      .finished();
        const auto extrinsics =
            (Eigen::Matrix<double, 7, 1>() << imu_R_cam_xyzw.coeffs(), imu_t_cam).finished();

        const std::array<const double*, 3> parameters = {camera_state.data(), extrinsics.data(),
                                                         p_world.data()};

        Eigen::Matrix<double, 2, 13> p_image_D_camera_state = Eigen::Matrix<double, 2, 13>::Zero();
        Eigen::Matrix<double, 2, 7> p_image_D_extrinsics = Eigen::Matrix<double, 2, 7>::Zero();
        std::array<double*, 3> jacobians = {p_image_D_camera_state.data(),
                                            p_image_D_extrinsics.data(), D_p_world.data()};
        cost_function->Evaluate(parameters.data(), p_image.data(), jacobians.data());

        // Transform jacobians
        const auto D_imu_rotation = handwritten::retract_derivative(world_R_imu_xyzw);
        const auto D_extrinsic_rotation = handwritten::retract_derivative(imu_R_cam_xyzw);

        D_world_R_imu = p_image_D_camera_state.leftCols<4>() * D_imu_rotation;
        D_world_t_imu = p_image_D_camera_state.middleCols<3>(4);
        D_angular_velocity_imu = p_image_D_camera_state.middleCols<3>(7);
        D_world_v_imu = p_image_D_camera_state.rightCols<3>();

        D_imu_R_cam = p_image_D_extrinsics.leftCols<4>() * D_extrinsic_rotation;
        D_imu_t_cam = p_image_D_extrinsics.rightCols<3>();
      });
}

BENCHMARK(BM_RollingShutterCamera_SymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_RollingShutterCamera_Wrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_RollingShutterCamera_Ceres)->Iterations(1000000)->Unit(benchmark::kNanosecond);

#ifdef INCLUDE_FIRST_ORDER_IMPLEMENTATIONS
BENCHMARK(BM_RollingShutterCamera_SymforceFirstOrder)
    ->Iterations(1000000)
    ->Unit(benchmark::kNanosecond);
BENCHMARK(BM_RollingShutterCamera_SFOWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
#endif  // INCLUDE_FIRST_ORDER_IMPLEMENTATIONS
