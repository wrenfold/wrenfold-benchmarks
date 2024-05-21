// Benchmark constant-velocity rolling shutter camera.
#include <iostream>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>
#include <Eigen/Geometry>

#include <wrenfold/span_eigen.h>

struct camera_params_t {
  double fx;
  double fy;
  double cx;
  double cy;
  double k1;
  double k2;
  double k3;
  double p1;
  double p2;
};

#include "generated/rolling_shutter_camera/sf/integrate_and_project_chain.h"
#include "generated/rolling_shutter_camera/sf/integrate_and_project_first_order.h"
#include "generated/rolling_shutter_camera/wf/integrate_and_project.h"

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

void BM_RollingShutterCameraSymforceChain(benchmark::State& state) {
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

// void BM_ImuIntegrationSymforceFirstOrder(benchmark::State& state) {
//   bench_imu_integration(
//       state,
//       [](const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
//          const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
//          const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
//          const Eigen::Matrix<double, 3, 1>& angular_velocity,
//          const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt,
//          Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
//          Eigen::Matrix<double, 3, 1>& i_v_k_out, Eigen::Matrix<double, 9, 9>& k_D_j_out,
//          Eigen::Matrix<double, 9, 6>& k_D_measurements_out,
//          Eigen::Matrix<double, 9, 6>& k_D_bias_out) {
//         sym::IntegrateImuFirstOrder<double>(i_R_j_xyzw, i_p_j, i_v_j, gyro_bias,
//         accelerometer_bias,
//                                             angular_velocity, linear_acceleration, dt,
//                                             &i_R_k_out, &i_p_k_out, &i_v_k_out, &k_D_j_out,
//                                             &k_D_measurements_out, &k_D_bias_out);
//       });
// }

void BM_RollingShutterCameraWrenfold(benchmark::State& state) {
  bench_projection(state, [](auto&&... args) {
    gen::integrate_and_project<double>(std::forward<decltype(args)>(args)...);
  });
}

BENCHMARK(BM_RollingShutterCameraSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
// BENCHMARK(BM_ImuIntegrationSymforceFirstOrder)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_RollingShutterCameraWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
