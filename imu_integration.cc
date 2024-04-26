// Benchmark IMU integration method.
#include <iostream>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <wrenfold/span_eigen.h>

#include "generated/integrate_imu/integrate_imu_chain.h"
#include "generated/integrate_imu/integrate_imu_first_order.h"
#include "generated/integrate_imu/integrate_imu_wf.h"

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

std::vector<integration_input> generate_integration_data(int num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};
  const auto u = [&]() { return dist(engine); };

  std::vector<integration_input> inputs{};
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

static void BM_ImuIntegrationSymforceChain(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_integration_data(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d i_R_k_out;
    Eigen::Vector3d i_p_k_out;
    Eigen::Vector3d i_v_k_out;
    Eigen::Matrix<double, 9, 9> k_D_j_out;
    Eigen::Matrix<double, 9, 6> k_D_measurements;
    Eigen::Matrix<double, 9, 6> k_D_bias;
    sym::IntegrateImuChain<double>(
        inputs[index].i_R_j, inputs[index].i_p_j, inputs[index].i_v_j, inputs[index].gyro_bias,
        inputs[index].accelerometer_bias, inputs[index].angular_velocity,
        inputs[index].linear_acceleration, inputs[index].dt, &i_R_k_out, &i_p_k_out, &i_v_k_out,
        &k_D_j_out, &k_D_measurements, &k_D_bias);

    benchmark::DoNotOptimize(i_R_k_out);
    benchmark::DoNotOptimize(i_p_k_out);
    benchmark::DoNotOptimize(i_v_k_out);
    benchmark::DoNotOptimize(k_D_j_out);
    benchmark::DoNotOptimize(k_D_measurements);
    benchmark::DoNotOptimize(k_D_bias);

    index = (index + 1) % inputs.size();
  }
}

static void BM_ImuIntegrationSymforceFirstOrder(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_integration_data(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d i_R_k_out;
    Eigen::Vector3d i_p_k_out;
    Eigen::Vector3d i_v_k_out;
    Eigen::Matrix<double, 9, 9> k_D_j_out;
    Eigen::Matrix<double, 9, 6> k_D_measurements;
    Eigen::Matrix<double, 9, 6> k_D_bias;
    sym::IntegrateImuFirstOrder<double>(
        inputs[index].i_R_j, inputs[index].i_p_j, inputs[index].i_v_j, inputs[index].gyro_bias,
        inputs[index].accelerometer_bias, inputs[index].angular_velocity,
        inputs[index].linear_acceleration, inputs[index].dt, &i_R_k_out, &i_p_k_out, &i_v_k_out,
        &k_D_j_out, &k_D_measurements, &k_D_bias);

    benchmark::DoNotOptimize(i_R_k_out);
    benchmark::DoNotOptimize(i_p_k_out);
    benchmark::DoNotOptimize(i_v_k_out);
    benchmark::DoNotOptimize(k_D_j_out);
    benchmark::DoNotOptimize(k_D_measurements);
    benchmark::DoNotOptimize(k_D_bias);

    index = (index + 1) % inputs.size();
  }
}

static void BM_ImuIntegrationWrenfold(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_integration_data(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d i_R_k_out;
    Eigen::Vector3d i_p_k_out;
    Eigen::Vector3d i_v_k_out;
    Eigen::Matrix<double, 9, 9> k_D_j_out;
    Eigen::Matrix<double, 9, 6> k_D_measurements;
    Eigen::Matrix<double, 9, 6> k_D_bias;
    gen::integrate_imu<double>(inputs[index].i_R_j, inputs[index].i_p_j, inputs[index].i_v_j,
                               inputs[index].gyro_bias, inputs[index].accelerometer_bias,
                               inputs[index].angular_velocity, inputs[index].linear_acceleration,
                               inputs[index].dt, i_R_k_out, i_p_k_out, i_v_k_out, k_D_j_out,
                               k_D_measurements, k_D_bias);

    benchmark::DoNotOptimize(i_R_k_out);
    benchmark::DoNotOptimize(i_p_k_out);
    benchmark::DoNotOptimize(i_v_k_out);
    benchmark::DoNotOptimize(k_D_j_out);
    benchmark::DoNotOptimize(k_D_measurements);
    benchmark::DoNotOptimize(k_D_bias);

    index = (index + 1) % inputs.size();
  }
}

BENCHMARK(BM_ImuIntegrationSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationSymforceFirstOrder)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_ImuIntegrationWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
