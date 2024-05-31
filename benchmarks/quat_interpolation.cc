// Benchmark quaternion interpolation method.
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

#include <wrenfold/span_eigen.h>

#include "generated/quat_interpolation/sf/quat_interpolate_chain.h"
#include "generated/quat_interpolation/sf/quat_interpolate_first_order.h"
#include "generated/quat_interpolation/sf/quat_local_coordinates_chain.h"
#include "generated/quat_interpolation/sf/quat_local_coordinates_first_order.h"

#include "generated/quat_interpolation/wf/quat_interpolation.h"
#include "generated/quat_interpolation/wf/quat_interpolation_no_conditional.h"
#include "generated/quat_interpolation/wf/quat_interpolation_sffo.h"
#include "generated/quat_interpolation/wf/quat_local_coordinates.h"
#include "generated/quat_interpolation/wf/quat_local_coordinates_sffo.h"

#include "quat_interpolation_ceres.h"
#include "quat_interpolation_handwritten.h"

#include "ceres_utils.h"

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

template <typename F>
void bench_local_coords(benchmark::State& state, F&& func) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  std::size_t index = 0;
  for (auto _ : state) {
    Eigen::Vector3d v_out;
    Eigen::Matrix3d D0_out;
    Eigen::Matrix3d D1_out;

    func(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()], v_out, D0_out, D1_out);

    benchmark::DoNotOptimize(v_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

template <typename F>
void bench_quat_interpolation(benchmark::State& state, F&& func) {
  constexpr std::size_t num_samples = 1000;
  const auto inputs = generate_quaternions(num_samples);

  Eigen::Vector4d q_out;
  Eigen::Matrix3d D0_out;
  Eigen::Matrix3d D1_out;
#if 0
  func(inputs[0], inputs[1], q_out, D0_out, D1_out);
  std::cout << "q_out = " << q_out.transpose() << std::endl;
  std::cout << "D0 = " << D0_out << std::endl;
#endif

  std::size_t index = 0;
  for (auto _ : state) {
    func(inputs[index % inputs.size()], inputs[(index + 1) % inputs.size()], q_out, D0_out, D1_out);

    benchmark::DoNotOptimize(q_out);
    benchmark::DoNotOptimize(D0_out);
    benchmark::DoNotOptimize(D1_out);
    ++index;
  }
}

void BM_QuatLocalCoordsHandwritten(benchmark::State& state) {
  bench_local_coords(state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1,
                               Eigen::Vector3d& v_out, Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
    v_out = handwritten::quaternion_local_coords(Eigen::Quaterniond(q0), Eigen::Quaterniond(q1),
                                                 &D0, &D1);
  });
}

void BM_QuatLocalCoordsSymforceChain(benchmark::State& state) {
  bench_local_coords(state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1,
                               Eigen::Vector3d& v_out, Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
    sym::QuatLocalCoordinatesChain(q0, q1, &v_out, &D0, &D1);
  });
}

void BM_QuatLocalCoordsSymforceFirstOrder(benchmark::State& state) {
  bench_local_coords(state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1,
                               Eigen::Vector3d& v_out, Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
    sym::QuatLocalCoordinatesFirstOrder(q0, q1, &v_out, &D0, &D1);
  });
}

void BM_QuatLocalCoordsWrenfold(benchmark::State& state) {
  bench_local_coords(state, [](auto&&... args) {
    gen::quat_local_coordinates<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_QuatLocalCoordsSFFOWrenfold(benchmark::State& state) {
  bench_local_coords(state, [](auto&&... args) {
    gen::quat_local_coordinates_sffo<double>(std::forward<decltype(args)>(args)...);
  });
}

void BM_QuatLocalCoordsCeres(benchmark::State& state) {
  const auto cost_function =
      utils::make_ceres_cost_function<autodiff_ceres::LocalCoordinatesError, 3, 4, 4>();

  bench_local_coords(
      state, [&cost_function](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1,
                              Eigen::Vector3d& v_out, Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        const std::array<const double*, 2> parameters = {q0.data(), q1.data()};

        Eigen::Matrix<double, 3, 4> D0_quat, D1_quat;
        std::array<double*, 2> jacobians = {D0_quat.data(), D1_quat.data()};
        cost_function->Evaluate(parameters.data(), v_out.data(), jacobians.data());

        // Chain rule to get right-tangent:
        D0.noalias() = D0_quat * handwritten::retract_derivative(Eigen::Quaterniond{q0});
        D1.noalias() = D1_quat * handwritten::retract_derivative(Eigen::Quaterniond{q1});
      });
}

void BM_QuatInterpolationHandwritten(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        handwritten::quaternion_interpolate(q0, q1, 0.312, q_out, &D0, &D1);
      });
}

void BM_QuatInterpolationSymforceChain(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        sym::QuatInterpolateChain(q0, q1, 0.312, &q_out, &D0, &D1);
      });
}

void BM_QuatInterpolationSymforceFirstOrder(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        sym::QuatInterpolateFirstOrder(q0, q1, 0.312, &q_out, &D0, &D1);
      });
}

void BM_QuatInterpolationWrenfold(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0,
                Eigen::Matrix3d& D1) { gen::quat_interpolation(q0, q1, 0.312, q_out, D0, D1); });
}

void BM_QuatInterpolationNoConditionalWrenfold(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        gen::quat_interpolation_no_conditional(q0, q1, 0.312, q_out, D0, D1);
      });
}

void BM_QuatInterpolationSFFOWrenfold(benchmark::State& state) {
  bench_quat_interpolation(
      state, [](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1, Eigen::Vector4d& q_out,
                Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        gen::quat_interpolation_sffo(q0, q1, 0.312, q_out, D0, D1);
      });
}

void BM_QuatInterpolationCeres(benchmark::State& state) {
  const auto cost_function =
      utils::make_ceres_cost_function<autodiff_ceres::QuatInterpolationError, 4, 4, 4>(0.312);

  bench_quat_interpolation(
      state, [&cost_function](const Eigen::Vector4d& q0, const Eigen::Vector4d& q1,
                              Eigen::Vector4d& q_out, Eigen::Matrix3d& D0, Eigen::Matrix3d& D1) {
        const std::array<const double*, 2> parameters = {q0.data(), q1.data()};

        Eigen::Matrix<double, 4, 4> D0_quat, D1_quat;
        std::array<double*, 2> jacobians = {D0_quat.data(), D1_quat.data()};
        cost_function->Evaluate(parameters.data(), q_out.data(), jacobians.data());

        // Chain rule to get right-tangent:
        D0.noalias() = handwritten::local_coordinates_derivative(Eigen::Quaterniond{q_out}) *
                       D0_quat * handwritten::retract_derivative(Eigen::Quaterniond{q0});
        D1.noalias() = handwritten::local_coordinates_derivative(Eigen::Quaterniond{q_out}) *
                       D1_quat * handwritten::retract_derivative(Eigen::Quaterniond{q1});
      });
}

BENCHMARK(BM_QuatInterpolationHandwritten)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationSymforceFirstOrder)
    ->Iterations(1000000)
    ->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationNoConditionalWrenfold)
    ->Iterations(1000000)
    ->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationSFFOWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatInterpolationCeres)->Iterations(1000000)->Unit(benchmark::kNanosecond);

BENCHMARK(BM_QuatLocalCoordsHandwritten)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsSymforceChain)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsSymforceFirstOrder)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsSFFOWrenfold)->Iterations(1000000)->Unit(benchmark::kNanosecond);
BENCHMARK(BM_QuatLocalCoordsCeres)->Iterations(1000000)->Unit(benchmark::kNanosecond);
