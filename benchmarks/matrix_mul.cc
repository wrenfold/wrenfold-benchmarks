// Benchmark matrix multiplication.
// Using symbolic code generation on code that is heavy on matrix multiplation may not
// make much sense. Frameworks like Eigen produce code that leverages SIMD more effectively.
// That said, this benchmark is instructive in understanding how we can improve.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <wrenfold/span_eigen.h>

#include "generated/matrix_mul/matrix_mul_wf.h"

template <Eigen::Index Row, Eigen::Index Col = Row>
std::vector<Eigen::Matrix<double, Row, Col>> generate_matrices(const std::size_t num_samples) {
  std::default_random_engine engine{0};  // NOLINT
  std::uniform_real_distribution<double> dist{-1.0, 1.0};

  std::vector<Eigen::Matrix<double, Row, Col>> inputs{};
  for (std::size_t i = 0; i < num_samples; ++i) {
    Eigen::Matrix<double, Row, Col> mat{};
    mat = mat.unaryExpr([&dist, &engine](double) { return dist(engine); });
    inputs.push_back(mat);
  }
  return inputs;
}

static void BM_MatMulEigen4(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<4>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix4d out;
    out.noalias() = inputs[index % inputs.size()] * inputs[(index + 1) % inputs.size()];
    benchmark::DoNotOptimize(out);
    ++index;
  }
}

static void BM_MatMulEigen8(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<8>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 8, 8> out;
    out.noalias() = inputs[index % inputs.size()] * inputs[(index + 1) % inputs.size()];
    benchmark::DoNotOptimize(out);
    ++index;
  }
}

static void BM_MatMulWrenfold4(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<4>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 4, 4> out;
    gen::matrix_mul4<double>(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()],
                             out);
    benchmark::DoNotOptimize(out);
    ++index;
  }
}

static void BM_MatMulWrenfold8(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<8>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 8, 8> out;
    gen::matrix_mul8<double>(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()],
                             out);
    benchmark::DoNotOptimize(out);
    ++index;
  }
}

static void BM_MatMulTriMulEigen(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;

  const auto A = generate_matrices<2, 4>(num_samples);
  const auto B = generate_matrices<4, 3>(num_samples);
  const auto C = generate_matrices<3, 2>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix2d out{};
    out.noalias() = A[index] * B[index] * C[index];
    benchmark::DoNotOptimize(out);
    index = (index + 1) % num_samples;
  }
}

static void BM_MatMulTriMulWrenfold1(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;

  const auto A = generate_matrices<2, 4>(num_samples);
  const auto B = generate_matrices<4, 3>(num_samples);
  const auto C = generate_matrices<3, 2>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix2d out{};
    gen::tri_matrix_mul_1<double>(A[index], B[index], C[index], out);
    benchmark::DoNotOptimize(out);
    index = (index + 1) % num_samples;
  }
}

BENCHMARK(BM_MatMulEigen4)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_MatMulEigen8)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_MatMulWrenfold4)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_MatMulWrenfold8)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_MatMulTriMulEigen)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_MatMulTriMulWrenfold1)->Iterations(5000000)->Unit(benchmark::kNanosecond);
