// Handwritten implementation of the quaternion interpolation method.
#pragma once
#include <Eigen/Geometry>

// Right-side retraction derivative of q: d[q * exp(w)]/dw evaluated at w = 0
Eigen::Matrix<double, 4, 3> retract_derivative(const Eigen::Quaterniond& q) {
  const double qx = q.x();
  const double qy = q.y();
  const double qz = q.z();
  const double qw = q.w();
  // clang-format off
  return (Eigen::Matrix<double, 4, 3>() <<
   qw / 2, -qz / 2, qy / 2,
   qz / 2, qw / 2, -qx / 2,
  -qy / 2, qx / 2, qw / 2,
  -qx / 2, -qy / 2, -qz / 2)
      .finished();
  // clang-format on
}

// Right-side local coordinates derivative of q: d[log(q-1 * (q + dq))] / dq
// evaluated at dq = 0
Eigen::Matrix<double, 3, 4> local_coordinates_derivative(const Eigen::Quaterniond& q) {
  const double qx = q.x();
  const double qy = q.y();
  const double qz = q.z();
  const double qw = q.w();
  // clang-format off
  return (Eigen::Matrix<double, 3, 4>() <<
    2 * qw, 2 * qz, -2 * qy, -2 * qx,
    -2 * qz, 2 * qw, 2 * qx, -2 * qy,
    2 * qy, -2 * qx, 2 * qw, -2 * qz)
      .finished();
  // clang-format on
}

// Normalize a vector, and produce derivatives of the norm and the normalized vector.
std::tuple<double, Eigen::Vector3d> normalize(const Eigen::Vector3d& v,
                                              Eigen::Matrix<double, 1, 3>* const angle_D_v,
                                              Eigen::Matrix<double, 3, 3>* const normalized_D_v) {
  const double v_norm = v.norm();
  if (angle_D_v) {
    angle_D_v->noalias() = v.transpose() / v_norm;
  }
  if (normalized_D_v) {
    normalized_D_v->noalias() = Eigen::Matrix3d::Identity() / v_norm;
    normalized_D_v->noalias() -= (v * v.transpose()) / (v_norm * v_norm * v_norm);
  }
  return std::make_tuple(v_norm, (v / v_norm).eval());
}

// Compute logmap of quaternion (conversion to rodrigues vector).
// Also output derivative wrt the 4 quaternion elements.
// Note that we don't handle the small angle case here at all.
Eigen::Vector3d quaterion_log(const Eigen::Quaterniond& q, Eigen::Matrix<double, 3, 4>* const D_q) {
  // Normalize the vector component.
  Eigen::RowVector3d v_norm_D_vec;
  Eigen::Matrix3d v_normalized_D_vec;
  const auto [v_norm, v_normalized] = normalize(q.vec(), &v_norm_D_vec, &v_normalized_D_vec);
  const double angle = 2.0 * std::atan2(v_norm, q.w());

  // Derivative is ordered [x,y,z,w]
  if (D_q) {
    const double angle_D_v_norm = 2.0 * q.w() / (v_norm * v_norm + q.w() * q.w());
    const double angle_D_w = -2.0 * v_norm / (v_norm * v_norm + q.w() * q.w());
    const Eigen::RowVector3d angle_D_vec = angle_D_v_norm * v_norm_D_vec;
    D_q->leftCols<3>().noalias() = v_normalized_D_vec * angle + v_normalized * angle_D_vec;
    D_q->rightCols<1>().noalias() = v_normalized * angle_D_w;
  }
  return v_normalized * angle;
}

// Compute exponential map of quaternion (covnersion from rodrigues vector).
// Also output the derivative of the 4 quaternion elements wrt
Eigen::Quaterniond quaternion_exp(const Eigen::Vector3d& w,
                                  Eigen::Matrix<double, 4, 3>* const D_w) {
  Eigen::RowVector3d angle_D_w;
  Eigen::Matrix3d unit_vec_D_w;
  const auto [angle, unit_vec] = normalize(w, &angle_D_w, &unit_vec_D_w);
  const double half_angle = angle / 2.0;
  const double s = std::sin(half_angle);
  const double c = std::cos(half_angle);

  // Derivative rows are ordered [x,y,z,w]
  if (D_w) {
    D_w->topRows<3>().noalias() = s * unit_vec_D_w + unit_vec * (0.5 * c) * angle_D_w;
    D_w->bottomRows<1>().noalias() = -s * 0.5 * angle_D_w;
  }
  return Eigen::Quaterniond(c, s * unit_vec.x(), s * unit_vec.y(), s * unit_vec.z());
}

// Compute log(q0^-1 * q1), and return rodrigues vector and derivatives wrt right-tangent space of
// q0 and q1.
Eigen::Vector3d quaternion_local_coords(const Eigen::Quaterniond& q0, const Eigen::Quaterniond& q1,
                                        Eigen::Matrix<double, 3, 3>* const D0,
                                        Eigen::Matrix<double, 3, 3>* const D1) {
  // Compute q0^-1 * q1:
  const Eigen::Quaterniond q_delta = q0.conjugate() * q1;

  Eigen::Matrix<double, 3, 4> w_D_q_delta;
  const Eigen::Vector3d w = quaterion_log(q_delta, &w_D_q_delta);
  if (D0) {
    const Eigen::Matrix<double, 4, 4> q_delta_D_q0 =
        (Eigen::Matrix<double, 4, 4>() << -q1.w(), -q1.z(), q1.y(), q1.x(), q1.z(), -q1.w(),
         -q1.x(), q1.y(), -q1.y(), q1.x(), -q1.w(), q1.z(), q1.x(), q1.y(), q1.z(), q1.w())
            .finished();
    D0->noalias() = w_D_q_delta * q_delta_D_q0 * retract_derivative(q0);
  }
  if (D1) {
    const Eigen::Matrix<double, 4, 4> q_delta_D_q1 =
        (Eigen::Matrix<double, 4, 4>() << q0.w(), q0.z(), -q0.y(), -q0.x(), -q0.z(), q0.w(), q0.x(),
         -q0.y(), q0.y(), -q0.x(), q0.w(), -q0.z(), q0.x(), q0.y(), q0.z(), q0.w())
            .finished();
    D1->noalias() = w_D_q_delta * q_delta_D_q1 * retract_derivative(q1);
  }
  return w;
}

// Hand-written quaternion interpolation with chain rule.
void quaternion_interpolate_manual(const Eigen::Matrix<double, 4, 1>& q0_xyzw,
                                   const Eigen::Matrix<double, 4, 1>& q1_xyzw, const double alpha,
                                   Eigen::Matrix<double, 4, 1>& q_out_,
                                   Eigen::Matrix<double, 3, 3>* const D0 = nullptr,
                                   Eigen::Matrix<double, 3, 3>* const D1 = nullptr) {
  const Eigen::Quaterniond q0{q0_xyzw.data()};
  const Eigen::Quaterniond q1{q1_xyzw.data()};

  Eigen::Matrix3d w01_D_q0;
  Eigen::Matrix3d w01_D_q1;
  const Eigen::Vector3d w01 = quaternion_local_coords(q0, q1, &w01_D_q0, &w01_D_q1);

  Eigen::Matrix<double, 4, 3> q_delta_D_w01_times_alpha;
  const Eigen::Quaterniond q_delta = quaternion_exp(w01 * alpha, &q_delta_D_w01_times_alpha);
  const Eigen::Quaterniond q_out = q0 * q_delta;

  const Eigen::Matrix<double, 4, 4> q_out_D_q_delta =
      (Eigen::Matrix<double, 4, 4>() << q0.w(), -q0.z(), q0.y(), q0.x(), q0.z(), q0.w(), -q0.x(),
       q0.y(), -q0.y(), q0.x(), q0.w(), q0.z(), -q0.x(), -q0.y(), -q0.z(), q0.w())
          .finished();

  const Eigen::Matrix<double, 4, 3> q_out_D_w01 =
      q_out_D_q_delta * q_delta_D_w01_times_alpha * alpha;

  if (D0) {
    const Eigen::Matrix<double, 4, 4> q_out_D_q0 =
        (Eigen::Matrix<double, 4, 4>() << q_delta.w(), q_delta.z(), -q_delta.y(), q_delta.x(),
         -q_delta.z(), q_delta.w(), q_delta.x(), q_delta.y(), q_delta.y(), -q_delta.x(),
         q_delta.w(), q_delta.z(), -q_delta.x(), -q_delta.y(), -q_delta.z(), q_delta.w())
            .finished();

    D0->noalias() = local_coordinates_derivative(q_out) * (q_out_D_q0 * retract_derivative(q0)) +
                    local_coordinates_derivative(q_out) * (q_out_D_w01 * w01_D_q0);
  }
  if (D1) {
    D1->noalias() = local_coordinates_derivative(q_out) * q_out_D_w01 * w01_D_q1;
  }
  q_out_ = q_out.coeffs();
}
