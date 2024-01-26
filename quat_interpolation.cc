// Bencmark quaternion interpolation method.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include "wf_runtime/span_eigen.h"

#include "output/quat_interpolation/quat_interpolate.h"
#include "output/quat_interpolation/quat_interpolate_wf.h"

std::vector<Eigen::Vector4d> generate_quaternions(int num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};

  std::vector<Eigen::Vector4d> inputs{};
  for (std::size_t i = 0; i < num_samples; ++i) {
    inputs.push_back(
        Eigen::Vector4d{dist(engine), dist(engine), dist(engine), dist(engine)}.normalized());
  }
  return inputs;
}

static void BM_QuatInterpolationSymforce(benchmark::State& state) {
  constexpr std::size_t num_samples = 100;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  double sum = 0.0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatInterpolate(inputs[index], inputs[index + 1], 0.312, &q_out, &D0_out, &D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);

    sum += q_out.sum();
    sum += D0_out.sum();
    sum += D1_out.sum();

    index++;
    index = (index % inputs.size());
  }
  benchmark::DoNotOptimize(sum);
}

static void BM_QuatInterpolationWrenfold(benchmark::State& state) {
  constexpr std::size_t num_samples = 100;
  const auto inputs = generate_quaternions(num_samples);
  
  std::size_t index = 0;
  double sum = 0.0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    gen::quaternion_interpolation(inputs[index], inputs[index + 1], 0.312, q_out, D0_out, D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);

    sum += q_out.sum();
    sum += D0_out.sum();
    sum += D1_out.sum();

    index++;
    index = (index % inputs.size());
  }
  benchmark::DoNotOptimize(sum);
}

BENCHMARK(BM_QuatInterpolationSymforce)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);

BENCHMARK_MAIN();
