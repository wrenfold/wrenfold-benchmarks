// Handwritten implementation of the IMU integration.
#pragma once
#include <Eigen/Geometry>

#include "quat_interpolation_handwritten.h"

namespace handwritten {

inline Eigen::Quaterniond quaternion_mul(const Eigen::Quaterniond& q_a,
                                         const Eigen::Quaterniond& q_b,
                                         Eigen::Matrix<double, 4, 4>* D_a,
                                         Eigen::Matrix<double, 4, 4>* D_b) {
  if (D_a) {
    *D_a = (Eigen::Matrix<double, 4, 4>() << q_b.w(), -q_b.x(), -q_b.y(), -q_b.z(), q_b.x(),
            q_b.w(), q_b.z(), -q_b.y(), q_b.y(), -q_b.z(), q_b.w(), q_b.x(), q_b.z(), q_b.y(),
            -q_b.x(), q_b.w())
               .finished();
  }
  if (D_b) {
    *D_b = (Eigen::Matrix<double, 4, 4>() << q_a.w(), -q_a.x(), -q_a.y(), -q_a.z(), q_a.x(),
            q_a.w(), -q_a.z(), q_a.y(), q_a.y(), q_a.z(), q_a.w(), -q_a.x(), q_a.z(), -q_a.y(),
            q_a.x(), q_a.w())
               .finished();
  }
  return q_a * q_b;
}

// 3x4 derivative of R(q) * v wrt 4 elements of `q`, ordered [w,x,y,z]:
inline Eigen::Matrix<double, 3, 4> quaternion_vec_rotation_deriv(const Eigen::Quaterniond& q_a,
                                                                 const Eigen::Vector3d& v) {
  return (Eigen::Matrix<double, 3, 4>() << 2 * q_a.y() * v.z() - 2 * q_a.z() * v.y(),
          2 * q_a.y() * v.y() + 2 * q_a.z() * v.z(),
          2 * q_a.w() * v.z() + 2 * q_a.x() * v.y() - 4 * q_a.y() * v.x(),
          -2 * q_a.w() * v.y() + 2 * q_a.x() * v.z() - 4 * q_a.z() * v.x(),
          -2 * q_a.x() * v.z() + 2 * q_a.z() * v.x(),
          -2 * q_a.w() * v.z() - 4 * q_a.x() * v.y() + 2 * q_a.y() * v.x(),
          2 * q_a.x() * v.x() + 2 * q_a.z() * v.z(),
          2 * q_a.w() * v.x() + 2 * q_a.y() * v.z() - 4 * q_a.z() * v.y(),
          2 * q_a.x() * v.y() - 2 * q_a.y() * v.x(),
          2 * q_a.w() * v.y() - 4 * q_a.x() * v.z() + 2 * q_a.z() * v.x(),
          -2 * q_a.w() * v.x() - 4 * q_a.y() * v.z() + 2 * q_a.z() * v.y(),
          2 * q_a.x() * v.x() + 2 * q_a.y() * v.y())
      .finished();
}

// TODO: This has not been fully tested for correctness yet.
inline void integrate_imu(
    const Eigen::Matrix<double, 4, 1>& i_R_j_xyzw, const Eigen::Matrix<double, 3, 1>& i_p_j,
    const Eigen::Matrix<double, 3, 1>& i_v_j, const Eigen::Matrix<double, 3, 1>& gyro_bias,
    const Eigen::Matrix<double, 3, 1>& accelerometer_bias,
    const Eigen::Matrix<double, 3, 1>& angular_velocity,
    const Eigen::Matrix<double, 3, 1>& linear_acceleration, const double dt,
    // Output states:
    Eigen::Matrix<double, 4, 1>& i_R_k_out, Eigen::Matrix<double, 3, 1>& i_p_k_out,
    Eigen::Matrix<double, 3, 1>& i_v_k_out,
    // Optional derivatives:
    Eigen::Matrix<double, 9, 9>* k_D_j_out, Eigen::Matrix<double, 9, 6>* k_D_measurements_out,
    Eigen::Matrix<double, 9, 6>* k_D_bias_out) {
  const Eigen::Quaterniond i_R_j{i_R_j_xyzw};

  // Integrate rotation:
  const Eigen::Vector3d angular_velocity_unbiased = angular_velocity - gyro_bias;

  Eigen::Matrix<double, 4, 3> j_R_k__D__ang_vel_unbiased_times_dt;
  const Eigen::Quaterniond j_R_k = quaternion_exp(
      angular_velocity_unbiased * dt,
      k_D_measurements_out || k_D_bias_out ? &j_R_k__D__ang_vel_unbiased_times_dt : nullptr);

  Eigen::Matrix<double, 4, 4> i_R_k__D__i_R_j;
  Eigen::Matrix<double, 4, 4> i_R_k__D__j_R_k;
  const Eigen::Quaterniond i_R_k =
      quaternion_mul(i_R_j, j_R_k, k_D_j_out ? &i_R_k__D__i_R_j : nullptr,
                     k_D_measurements_out || k_D_bias_out ? &i_R_k__D__j_R_k : nullptr);
  i_R_k_out = i_R_k.coeffs();

  // Rotate acceleration into frame `i`:
  const auto i_R_j_mat = i_R_j.toRotationMatrix();
  const Eigen::Vector3d accel_unbiased = linear_acceleration - accelerometer_bias;
  const Eigen::Vector3d accel_in_i = i_R_j_mat * accel_unbiased;

  // Derivative of accel_in_i wrt the tangent-space perturbation in i_R_j.
  const Eigen::Matrix<double, 3, 3> accel_in_i__D__i_R_j =
      quaternion_vec_rotation_deriv(i_R_j, accel_unbiased) * retract_derivative(i_R_j);

  // Integrate position w/ euler integration:
  const auto dt2 = std::abs(dt) * dt / 2;
  i_p_k_out = i_p_j + i_v_j * dt + accel_in_i * dt2;
  i_v_k_out = i_v_j + accel_in_i * dt;

  if (k_D_j_out) {
    // Derivative is ordered [rot, pos, vel].
    // Rotation:
    k_D_j_out->topLeftCorner<3, 3>() =
        local_coordinates_derivative(i_R_k) * i_R_k__D__i_R_j * retract_derivative(i_R_j);
    k_D_j_out->topRightCorner<3, 6>().setZero();

    // Position:
    k_D_j_out->middleRows<3>(3).leftCols<3>() = accel_in_i__D__i_R_j * dt2;
    k_D_j_out->middleRows<3>(3).middleCols<3>(3).setIdentity();
    k_D_j_out->middleRows<3>(3).rightCols<3>() = Eigen::Matrix3d::Identity() * dt;

    // Velocity:
    k_D_j_out->bottomRows<3>().leftCols<3>() = accel_in_i__D__i_R_j * dt;
    k_D_j_out->bottomRows<3>().middleCols<3>(3).setZero();
    k_D_j_out->bottomRows<3>().rightCols<3>().setIdentity();
  }

  if (k_D_measurements_out || k_D_bias_out) {
    Eigen::Matrix<double, 9, 6> k_D_measurements;

    // Rotation:
    const double ang_vel_unbiased_times_dt__D__ang_vel_unbiased = dt;
    k_D_measurements.topRows<3>().leftCols<3>() =
        local_coordinates_derivative(i_R_k) * i_R_k__D__j_R_k *
        j_R_k__D__ang_vel_unbiased_times_dt * ang_vel_unbiased_times_dt__D__ang_vel_unbiased;
    k_D_measurements.topRows<3>().leftCols<3>().setZero();

    // Position:
    k_D_measurements.middleRows<3>(3).leftCols<3>().setZero();
    k_D_measurements.middleRows<3>(3).rightCols<3>() = i_R_j_mat * dt2;

    // Velocity:
    k_D_measurements.bottomRows<3>(3).leftCols<3>().setZero();
    k_D_measurements.bottomRows<3>(3).rightCols<3>() = i_R_j_mat * dt;

    if (k_D_measurements_out) {
      *k_D_measurements_out = k_D_measurements;
    }
    if (k_D_bias_out) {
      *k_D_bias_out = -k_D_measurements;
    }
  }
}

}  // namespace handwritten
