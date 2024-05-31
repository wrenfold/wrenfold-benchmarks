#pragma once
#include <memory>

#include <ceres/ceres.h>

namespace utils {

template <typename CostFunctor, int NumResiduals, int... Ns, typename... Args>
auto make_ceres_cost_function(Args&&... args) {
  return std::make_unique<ceres::AutoDiffCostFunction<CostFunctor, NumResiduals, Ns...>>(
      new CostFunctor(std::forward<Args>(args)...));
}

}  // namespace utils
