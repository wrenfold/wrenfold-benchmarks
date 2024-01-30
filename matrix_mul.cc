// Bencmark matrix mul method.
#include <iostream>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include "wf_runtime/span_eigen.h"

#include "matrix_mul/matrix_mul_wf.h"

// column-major matrix type
template <std::size_t Rows, std::size_t Cols>
class simple_matrix {
 public:
  simple_matrix() = default;

  simple_matrix(const Eigen::Matrix<double, Rows, Cols>& other) noexcept {
    for (std::size_t i = 0; i < Rows; ++i) {
      for (std::size_t j = 0; j < Cols; ++j) {
        this->operator()(i, j) = other(i, j);
      }
    }
  }

  double& operator()(std::size_t i, std::size_t j) {
    return data_[static_cast<std::size_t>(j) * Rows + static_cast<std::size_t>(i)];
  }
  const double& operator()(std::size_t i, int j) const {
    return data_[static_cast<std::size_t>(j) * Rows + static_cast<std::size_t>(i)];
  }

 private:
  std::array<double, Rows * Cols> data_;
};

template <std::size_t N, std::size_t K, std::size_t M>
simple_matrix<N, M> operator*(const simple_matrix<N, K>& a, const simple_matrix<K, M>& b) {
  simple_matrix<N, M> result{};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < M; ++j) {
      result(i, j) = 0;
      for (std::size_t k = 0; k < K; ++k) {
        result(i, j) += a(i, k) * b(k, j);
      }
    }
  }
  return result;
}

template <std::size_t Dim>
std::vector<Eigen::Matrix<double, Dim, Dim>> generate_matrices(int num_samples) {
  std::default_random_engine engine{0};
  std::uniform_real_distribution<double> dist{-1.0, 1.0};

  std::vector<Eigen::Matrix<double, Dim, Dim>> inputs{};
  for (std::size_t i = 0; i < num_samples; ++i) {
    Eigen::Matrix<double, Dim, Dim> mat{};
    for (int i = 0; i < Dim; ++i) {
      for (int j = 0; j < Dim; ++j) {
        mat(i, j) = dist(engine);
      }
    }
    inputs.push_back(mat);
  }
  return inputs;
}

static void BM_Eigen4(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<4>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix4d out;
    out.noalias() = inputs[index] * inputs[index + 1];
    benchmark::DoNotOptimize(out);
    index++;
    if (index + 1 >= inputs.size()) {
      index = 0;
    }
  }
}

static void BM_Eigen8(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<8>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 8, 8> out;
    out.noalias() = inputs[index] * inputs[index + 1];

    benchmark::DoNotOptimize(out);
    index++;
    if (index + 1 >= inputs.size()) {
      index = 0;
    }
  }
}

static void BM_Wrenfold4(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<4>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 4, 4> out;
    gen::matrix_mul4<double>(inputs[index], inputs[index + 1], out);
    benchmark::DoNotOptimize(out);
    index++;
    if (index + 1 >= inputs.size()) {
      index = 0;
    }
  }
}

static void BM_Wrenfold8(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_matrices<8>(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Matrix<double, 8, 8> out;
    gen::matrix_mul8<double>(inputs[index], inputs[index + 1], out);
    benchmark::DoNotOptimize(out);
    index++;
    if (index + 1 >= inputs.size()) {
      index = 0;
    }
  }
}

static void BM_Simple4(benchmark::State& state) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs_eigen = generate_matrices<4>(num_samples);

  std::vector<simple_matrix<4, 4>> inputs_simple{};
  std::copy(inputs_eigen.begin(), inputs_eigen.end(), std::back_inserter(inputs_simple));

  std::size_t index = 0;
  for (auto _ : state) {
    simple_matrix<4, 4> out = inputs_simple[index] * inputs_simple[index + 1];
    benchmark::DoNotOptimize(out);
    index++;
    if (index + 1 >= inputs_simple.size()) {
      index = 0;
    }
  }
}

BENCHMARK(BM_Eigen4)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_Eigen8)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_Wrenfold4)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_Wrenfold8)->Iterations(5000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_Simple4)->Iterations(5000000)->Unit(benchmark::kNanosecond);
// BENCHMARK(BM_Wrenfold8)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK_MAIN();