// Bencmark quaternion interpolation method.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include "output/quat_interpolation/quat_interpolate.h"

static void BM_QuatInterpolationSymforce(benchmark::State& state) {
  constexpr std::size_t num_samples = 100;

  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};

  std::vector<Eigen::Vector4d> inputs{};
  for (std::size_t i = 0; i < num_samples; ++i) {
    inputs.push_back(
        Eigen::Vector4d{dist(engine), dist(engine), dist(engine), dist(engine)}.normalized());
  }

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector4d q_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;
    sym::QuatInterpolate(inputs[index], inputs[index + 1], 0.312, &q_out, &D0_out, &D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);

    index++;
    index = (index % num_samples);
  }
}

BENCHMARK(BM_QuatInterpolationSymforce)->Iterations(1000000)->Unit(benchmark::kNanosecond);

BENCHMARK_MAIN();
