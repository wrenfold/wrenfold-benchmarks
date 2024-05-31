// Benchmark IMU integration method.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <wrenfold/span_eigen.h>

#include "generated/imu_integration/sf/integrate_imu_chain.h"
#include "generated/imu_integration/sf/integrate_imu_first_order.h"
#include "generated/imu_integration/wf/integrate_imu.h"
#include "generated/imu_integration/wf/integrate_imu_sffo.h"

#include "imu_integration_ceres.h"
#include "imu_integration_handwritten.h"
#include "quat_interpolation_handwritten.h"

#include "ceres_utils.h"

struct integration_input {
  Eigen::Vector4d i_R_j;
  Eigen::Vector3d i_p_j;
  Eigen::Vector3d i_v_j;
  Eigen::Vector3d gyro_bias;
  Eigen::Vector3d accelerometer_bias;
  Eigen::Vector3d angular_velocity;
  Eigen::Vector3d linear_acceleration;
  double dt;
};

std::vector<integration_input> generate_integration_data(const std::size_t num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};
  const auto u = [&]() { return dist(engine); };

  std::vector<integration_input> inputs{};
  inputs.reserve(num_samples);
  for (std::size_t i = 0; i < num_samples; ++i) {
    integration_input sample{};
    sample.i_R_j = Eigen::Vector4d{u(), u(), u(), u()}.normalized();
    sample.i_p_j = 50.0 * Eigen::Vector3d{u(), u(), u()};
    sample.i_v_j = 5.0 * Eigen::Vector3d{u(), u(), u()};
    sample.gyro_bias = 0.02 * Eigen::Vector3d{u(), u(), u()};
    sample.accelerometer_bias = 0.2 * Eigen::Vector3d{u(), u(), u()};
    sample.angular_velocity = Eigen::Vector3d{u(), u(), u()};
    sample.linear_acceleration = 10.0 * Eigen::Vector3d{u(), u(), u()};
    sample.dt = (u() + 1.0) / 2.0 * 0.1 + 0.01;
    inputs.push_back(sample);
  }
  return inputs;
}

template <typename F>
void bench_imu_integration(benchmark::State& state, F&& func) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_integration_data(num_samples);

  Eigen::Vector4d i_R_k_out;
  Eigen::Vector3d i_p_k_out;
  Eigen::Vector3d i_v_k_out;
  Eigen::Matrix<double, 9, 9> k_D_j_out;
  Eigen::Matrix<double, 9, 6> k_D_measurements;
  Eigen::Matrix<double, 9, 6> k_D_bias;

  std::size_t index = 0;
  for (auto _ : state) {
    func(inputs[index].i_R_j, inputs[index].i_p_j, inputs[index].i_v_j, inputs[index].gyro_bias,
         inputs[index].accelerometer_bias, inputs[index].angular_velocity,
         inputs[index].linear_acceleration, inputs[index].dt, i_R_k_out, i_p_k_out, i_v_k_out,
         k_D_j_out, k_D_measurements, k_D_bias);
    benchmark::DoNotOptimize(i_R_k_out);
    benchmark::DoNotOptimize(i_p_k_out);
    benchmark::DoNotOptimize(i_v_k_out);
    benchmark::DoNotOptimize(k_D_j_out);
    benchmark::DoNotOptimize(k_D_measurements);
    benchmark::DoNotOptimize(k_D_bias);
    index = (index + 1) % inputs.size();
  }
}

void BM_ImuIntegrationSymforceChain(benchmark::State& state) {
  bench_imu_integration(
      state,
      [](const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
         const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
         const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
         const Eigen::Matrix<double, 3, 1>& angular_velocity,
         const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt,
         Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
         Eigen::Matrix<double, 3, 1>& i_v_k_out, Eigen::Matrix<double, 9, 9>& k_D_j_out,
         Eigen::Matrix<double, 9, 6>& k_D_measurements_out,
         Eigen::Matrix<double, 9, 6>& k_D_bias_out) {
        sym::IntegrateImuChain<double>(i_R_j_xyzw, i_p_j, i_v_j, gyro_bias, accelerometer_bias,
                                       angular_velocity, linear_acceleration, dt, &i_R_k_out,
                                       &i_p_k_out, &i_v_k_out, &k_D_j_out, &k_D_measurements_out,
                                       &k_D_bias_out);
      });
}

void BM_ImuIntegrationSymforceFirstOrder(benchmark::State& state) {
  bench_imu_integration(
      state,
      [](const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
         const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
         const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
         const Eigen::Matrix<double, 3, 1>& angular_velocity,
         const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt,
         Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
         Eigen::Matrix<double, 3, 1>& i_v_k_out, Eigen::Matrix<double, 9, 9>& k_D_j_out,
         Eigen::Matrix<double, 9, 6>& k_D_measurements_out,
         Eigen::Matrix<double, 9, 6>& k_D_bias_out) {
        sym::IntegrateImuFirstOrder<double>(i_R_j_xyzw, i_p_j, i_v_j, gyro_bias, accelerometer_bias,
                                            angular_velocity, linear_acceleration, dt, &i_R_k_out,
                                            &i_p_k_out, &i_v_k_out, &k_D_j_out,
                                            &k_D_measurements_out, &k_D_bias_out);
      });
}

void BM_ImuIntegrationWrenfold(benchmark::State& state) {
  bench_imu_integration(state, [](auto&&... args) {
    gen::integrate_imu<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_ImuIntegrationSFFOWrenfold(benchmark::State& state) {
  bench_imu_integration(state, [](auto&&... args) {
    gen::integrate_imu_sffo<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_ImuIntegrationHandwritten(benchmark::State& state) {
  bench_imu_integration(
      state,
      [](const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
         const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
         const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
         const Eigen::Matrix<double, 3, 1>& angular_velocity,
         const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt,
         Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
         Eigen::Matrix<double, 3, 1>& i_v_k_out, Eigen::Matrix<double, 9, 9>& k_D_j_out,
         Eigen::Matrix<double, 9, 6>& k_D_measurements_out,
         Eigen::Matrix<double, 9, 6>& k_D_bias_out) {
        handwritten::integrate_imu(i_R_j_xyzw, i_p_j, i_v_j, gyro_bias, accelerometer_bias,
                                   angular_velocity, linear_acceleration, dt, i_R_k_out, i_p_k_out,
                                   i_v_k_out, &k_D_j_out, &k_D_measurements_out, &k_D_bias_out);
      });
}

void BM_ImuIntegrationCeres(benchmark::State& state) {
  double dt;
  Eigen::Matrix<double, 6, 1> meas;
  const auto cost_function =
      utils::make_ceres_cost_function<autodiff_ceres::ImuIntegration, 10, 10, 6>(&dt, &meas);

  bench_imu_integration(
      state,
      [&](const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
          const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
          const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
          const Eigen::Matrix<double, 3, 1>& angular_velocity,
          const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt_in,
          Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
          Eigen::Matrix<double, 3, 1>& i_v_k_out, Eigen::Matrix<double, 9, 9>& k_D_j_out,
          Eigen::Matrix<double, 9, 6>& k_D_measurements_out,
          Eigen::Matrix<double, 9, 6>& k_D_bias_out) {
        // Update dt + measurements (cost_function has a pointer to this value).
        dt = dt_in;
        meas.topRows<3>() = angular_velocity;
        meas.bottomRows<3>() = linear_acceleration;

        const auto nav_state_initial =
            (Eigen::Matrix<double, 10, 1>() << i_R_j_xyzw, i_p_j, i_v_j).finished();
        const auto biases =
            (Eigen::Matrix<double, 6, 1>() << gyro_bias, accelerometer_bias).finished();
        Eigen::Matrix<double, 10, 1> nav_state_final = Eigen::Matrix<double, 10, 1>::Zero();

        const std::array<const double*, 2> parameters = {nav_state_initial.data(), biases.data()};

        // The three output jacobians, specified wrt the 4 quaternion elements.
        Eigen::Matrix<double, 10, 10> final_D_initial;
        Eigen::Matrix<double, 10, 6> final_D_bias;
        std::array<double*, 2> jacobians = {final_D_initial.data(), final_D_bias.data()};
        cost_function->Evaluate(parameters.data(), nav_state_final.data(), jacobians.data());

        i_R_k_out = nav_state_final.head<4>();
        i_p_k_out = nav_state_final.middleRows<3>(4);
        i_v_k_out = nav_state_final.tail<3>();

        // Transform jacobians to the tangent space:
        const auto A = handwritten::local_coordinates_derivative(Eigen::Quaterniond{i_R_k_out});
        const auto B = handwritten::retract_derivative(Eigen::Quaterniond{i_R_j_xyzw});

        k_D_j_out.topLeftCorner<3, 3>() = A * final_D_initial.topLeftCorner<4, 4>() * B;
        k_D_j_out.topRightCorner<3, 6>() = A * final_D_initial.topLeftCorner<4, 6>();
        k_D_j_out.bottomLeftCorner<6, 3>() = final_D_initial.bottomLeftCorner<6, 4>() * B;
        k_D_j_out.bottomRightCorner<6, 6>() = final_D_initial.bottomRightCorner<6, 6>();

        k_D_bias_out.topRows<3>() = A * final_D_bias.topRows<4>();
        k_D_bias_out.bottomRows<6>() = final_D_bias.bottomRows<6>();

        // We do a minor handwritten optimization here, and apply our knowledge that k_D_meas is
        // the negation of k_D_bias.
        k_D_measurements_out = -k_D_bias_out;
      });
}

BENCHMARK(BM_ImuIntegrationSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationSymforceFirstOrder)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationSFFOWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationHandwritten)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationCeres)->Iterations(1000000)->Unit(benchmark::kNanosecond);
