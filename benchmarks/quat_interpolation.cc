// Benchmark quaternion interpolation method.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <wrenfold/span_eigen.h>

#include "generated/quat_interpolation/quat_interpolate_chain.h"
#include "generated/quat_interpolation/quat_interpolate_first_order.h"
#include "generated/quat_interpolation/quat_interpolate_wf.h"
#include "generated/quat_interpolation/quat_local_coordinates_chain.h"
#include "generated/quat_interpolation/quat_local_coordinates_first_order.h"

#include "quat_interpolation_handwritten.h"

std::vector<Eigen::Vector4d> generate_quaternions(const std::size_t num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};

  std::vector<Eigen::Vector4d> inputs{};
  inputs.reserve(num_samples);
  for (std::size_t i = 0; i < num_samples; ++i) {
    inputs.push_back(
        Eigen::Vector4d{dist(engine), dist(engine), dist(engine), dist(engine)}.normalized());
  }
  return inputs;
}

static void BM_QuatLocalCoordsHandwritten(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector3d v_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    v_out = quaternion_local_coords(Eigen::Quaterniond(inputs[index % inputs.size()]),
                                    Eigen::Quaterniond(inputs[(index + 1) % inputs.size()]),
                                    &D0_out, &D1_out);

    benchmark::DoNotOptimize(v_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatLocalCoordsSymforceChain(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector3d v_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatLocalCoordinatesChain(inputs[index % inputs.size()],
                                   inputs[(index + 1) % inputs.size()], &v_out, &D0_out, &D1_out);

    benchmark::DoNotOptimize(v_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}
static void BM_QuatLocalCoordsSymforceFirstOrder(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector3d v_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatLocalCoordinatesFirstOrder(inputs[index % inputs.size()],
                                        inputs[(index + 1) % inputs.size()], &v_out, &D0_out,
                                        &D1_out);

    benchmark::DoNotOptimize(v_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatLocalCoordsWrenfold(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector3d v_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    gen::quaternion_local_coordinates<double>(
        inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()], v_out, D0_out, D1_out);
    benchmark::DoNotOptimize(v_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatInterpolationSymforceChain(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatInterpolateChain(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()],
                              0.312, &q_out, &D0_out, &D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatInterpolationHandwritten(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    quaternion_interpolate_manual(inputs[index % inputs.size()],
                                  inputs[(index + 1) % inputs.size()], 0.312, q_out, &D0_out,
                                  &D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatInterpolationSymforceFirstOrder(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatInterpolateFirstOrder(inputs[index % inputs.size()],
                                   inputs[(index + 1) % inputs.size()], 0.312, &q_out, &D0_out,
                                   &D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

static void BM_QuatInterpolationWrenfold(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    gen::quaternion_interpolation(inputs[index % inputs.size()],
                                  inputs[(index + 1) % inputs.size()], 0.312, q_out, D0_out,
                                  D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

#if 0
static void BM_QuatInterpolationWrenfoldNoConditional(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    gen::quaternion_interpolation_no_conditional(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()], 0.312, q_out,
                                                 D0_out, D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}
#endif

BENCHMARK(BM_QuatInterpolationHandwritten)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationSymforceFirstOrder)
    ->Iterations(1000000)
    ->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);

BENCHMARK(BM_QuatLocalCoordsHandwritten)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsSymforceFirstOrder)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);

// BENCHMARK(BM_QuatInterpolationWrenfoldNoConditional)
//     ->Iterations(1000000)
//     ->Unit(benchmark::kNanosecond);
