// Handwritten implementation of the quaternion interpolation method.
#pragma once
#include <ceres/ceres.h>
#include <ceres/rotation.h>

#include <Eigen/Geometry>

namespace handwritten_ceres {

// TODO: This isn't really tangent space, since we're differentiating the quaternions?
struct LocalCoordinatesError {
  template <typename T>
  bool operator()(const T* const q0_data, const T* const q1_data, T* residuals_data) const {
    const Eigen::Map<const Eigen::Quaternion<T>> q0(q0_data);
    const Eigen::Map<const Eigen::Quaternion<T>> q1(q1_data);
    Eigen::Map<Eigen::Vector3<T>> residuals(residuals_data);

    const Eigen::Quaternion<T> q_delta = q0.conjugate() * q1;
    ceres::QuaternionToAngleAxis(q_delta.coeffs().data(), residuals.data());
    return true;
  }
};

struct QuatInterpolationError {
  explicit constexpr QuatInterpolationError(double alpha) noexcept : alpha_(alpha) {}

  template <typename T>
  bool operator()(const T* const q0_data, const T* const q1_data, T* q_out_data) const {
    const Eigen::Map<const Eigen::Quaternion<T>> q0(q0_data);
    const Eigen::Map<const Eigen::Quaternion<T>> q1(q1_data);
    Eigen::Map<Eigen::Vector4<T>> q_out(q_out_data);

    const Eigen::Quaternion<T> q01 = q0.conjugate() * q1;
    Eigen::Vector3<T> w01;
    ceres::QuaternionToAngleAxis(q01.coeffs().data(), w01.data());

    // Scale tangent-space vector by alpha, and exponentiate:
    w01 = w01 * T(alpha_);
    Eigen::Quaternion<T> q_01_times_alpha;
    ceres::AngleAxisToQuaternion(w01.data(), q_01_times_alpha.coeffs().data());

    // Output the interpolated quaternion.
    q_out = (q0 * q_01_times_alpha).coeffs();
    return true;
  }

 private:
  double alpha_;
};

}  // namespace handwritten_ceres
