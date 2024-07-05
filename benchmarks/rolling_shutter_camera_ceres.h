// Ceres implemnetation of rolling shutter camera.
#pragma once
#include <ceres/ceres.h>
#include <ceres/rotation.h>

#include <Eigen/Geometry>

#include "camera_params_t.h"

namespace autodiff_ceres {

struct RollingShutterCameraProjection {
  // We store these as pointers so we can update them in the benchmark loop.
  explicit constexpr RollingShutterCameraProjection(const double* row_time,
                                                    const camera_params_t* intrinsics) noexcept
      : row_time_(row_time), intrinsics_(intrinsics) {}

  template <typename T>
  bool operator()(const T* const camera_state_data, const T* const extrinsics_data,
                  const T* const point_data, T* p_image_data) const {
    const Eigen::Map<const Eigen::Quaternion<T>> world_R_imu{camera_state_data};
    const Eigen::Map<const Eigen::Vector3<T>> world_t_imu{camera_state_data + 4};
    const Eigen::Map<const Eigen::Vector3<T>> angular_velocity_imu{camera_state_data + 7};
    const Eigen::Map<const Eigen::Vector3<T>> world_v_imu{camera_state_data + 10};

    const Eigen::Map<const Eigen::Quaternion<T>> imu_R_cam{extrinsics_data};
    const Eigen::Map<const Eigen::Vector3<T>> imu_t_cam{extrinsics_data + 4};

    const Eigen::Map<const Eigen::Vector3<T>> p_world{point_data};

    const Eigen::Vector3<T> angular_velocity_imu_times_row_time =
        angular_velocity_imu * (*row_time_);
    Eigen::Quaternion<T> imu_R_imu_at_row;
    ceres::AngleAxisToQuaternion(angular_velocity_imu_times_row_time.data(),
                                 imu_R_imu_at_row.coeffs().data());

    // Integrate to the specified row:
    const Eigen::Quaternion<T> world_R_imu_at_row = world_R_imu * imu_R_imu_at_row;
    const Eigen::Vector3<T> world_t_imu_at_row = world_t_imu + world_v_imu * (*row_time_);

    // Apply extrinsic transform:
    const Eigen::Quaternion<T> world_R_cam = world_R_imu_at_row * imu_R_cam;
    const Eigen::Vector3<T> world_t_cam =
        world_t_imu_at_row + world_R_imu_at_row.toRotationMatrix() * imu_t_cam;

    // Transform point into camera frame:
    const Eigen::Vector3<T> p_cam =
        world_R_cam.conjugate().toRotationMatrix() * (p_world - world_t_cam);

    // Project into the iimage and apply distortion:
    const Eigen::Vector2<T> p_image_plane = p_cam.template head<2>() / p_cam[2];
    const T r2 = p_image_plane.squaredNorm();
    const T r4 = r2 * r2;
    const T r6 = r4 * r2;
    const T& x = p_image_plane.x();
    const T& y = p_image_plane.y();
    const T xy = x * y;
    const T radial_coeff =
        (T(1) + intrinsics_->k1 * r2 + intrinsics_->k2 * r4 + intrinsics_->k3 * r6);
    const T x_d =
        radial_coeff * x + T(2) * intrinsics_->p1 * xy + intrinsics_->p2 * (r2 + T(2) * x * x);
    const T y_d =
        radial_coeff * y + T(2) * intrinsics_->p1 * (r2 + T(2) * y * y) + intrinsics_->p2 * xy;

    Eigen::Map<Eigen::Vector2<T>>{p_image_data} = Eigen::Vector2<T>(x_d, y_d);
    return true;
  }

 private:
  const double* row_time_;
  const camera_params_t* intrinsics_;
};

}  // namespace autodiff_ceres
