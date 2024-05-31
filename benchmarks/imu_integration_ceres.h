// Handwritten implementation of the quaternion interpolation method.
#pragma once
#include <ceres/ceres.h>
#include <ceres/rotation.h>

#include <Eigen/Geometry>

namespace autodiff_ceres {

struct ImuIntegration {
    // We store these as pointers so we can update them in the benchmark loop.
  explicit constexpr ImuIntegration(const double* dt,
                                    const Eigen::Matrix<double, 6, 1>* meas) noexcept
      : dt_(dt), meas_(meas) {}

  template <typename T>
  bool operator()(const T* const nav_state_data, const T* const bias_data,
                  T* integrated_nav_state_data) const {
    const Eigen::Map<const Eigen::Quaternion<T>> i_R_j{nav_state_data};
    const Eigen::Map<const Eigen::Vector3<T>> i_p_j{nav_state_data + 4};
    const Eigen::Map<const Eigen::Vector3<T>> i_v_j{nav_state_data + 7};

    const Eigen::Map<const Eigen::Vector3<T>> gyro_bias{bias_data};
    const Eigen::Map<const Eigen::Vector3<T>> accelerometer_bias{bias_data + 3};

    const auto angular_velocity = meas_->topRows<3>();
    const auto linear_acceleration = meas_->bottomRows<3>();

    Eigen::Map<Eigen::Quaternion<T>> i_R_k_out{integrated_nav_state_data};
    Eigen::Map<Eigen::Vector3<T>> i_p_j_out{integrated_nav_state_data + 4};
    Eigen::Map<Eigen::Vector3<T>> i_v_k_out{integrated_nav_state_data + 7};

    // Integrate rotation:
    const double dt = *dt_;
    const Eigen::Vector3<T> angular_velocity_unbiased = angular_velocity - gyro_bias;
    const Eigen::Vector3<T> w_jk = angular_velocity_unbiased * T(dt);

    Eigen::Quaternion<T> j_R_k;
    ceres::AngleAxisToQuaternion(w_jk.data(), j_R_k.coeffs().data());
    i_R_k_out = i_R_j * j_R_k;

    // Rotate acceleration into frame `i`:
    const Eigen::Vector3<T> accel_unbiased = linear_acceleration - accelerometer_bias;
    const Eigen::Vector3<T> accel_in_i = i_R_j.toRotationMatrix() * accel_unbiased;

    // Integrate position w/ euler integration:
    const auto dt2 = std::abs(dt) * dt / 2;
    i_p_j_out = i_p_j + i_v_j * dt + accel_in_i * dt2;
    i_v_k_out = i_v_j + accel_in_i * dt;

    return true;
  }

 private:
  const double* dt_;
  const Eigen::Matrix<double, 6, 1>* meas_;
};

}  // namespace autodiff_ceres
