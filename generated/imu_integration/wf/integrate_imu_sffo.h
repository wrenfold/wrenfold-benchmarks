// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4,
          typename T5, typename T6, typename T8, typename T9, typename T10, typename T11,
          typename T12, typename T13>
void integrate_imu_sffo(const T0& i_R_j_xyzw, const T1& i_p_j, const T2& i_v_j, const T3& gyro_bias,
                        const T4& accelerometer_bias, const T5& angular_velocity,
                        const T6& linear_acceleration, const Scalar dt, T8&& i_R_k, T9&& i_p_k,
                        T10&& i_v_k, T11&& k_D_j, T12&& k_D_measurements, T13&& k_D_bias) {
  auto _i_R_j_xyzw = wf::make_input_span<4, 1>(i_R_j_xyzw);
  auto _i_p_j = wf::make_input_span<3, 1>(i_p_j);
  auto _i_v_j = wf::make_input_span<3, 1>(i_v_j);
  auto _gyro_bias = wf::make_input_span<3, 1>(gyro_bias);
  auto _accelerometer_bias = wf::make_input_span<3, 1>(accelerometer_bias);
  auto _angular_velocity = wf::make_input_span<3, 1>(angular_velocity);
  auto _linear_acceleration = wf::make_input_span<3, 1>(linear_acceleration);
  auto _i_R_k = wf::make_output_span<4, 1>(i_R_k);
  auto _i_p_k = wf::make_output_span<3, 1>(i_p_k);
  auto _i_v_k = wf::make_output_span<3, 1>(i_v_k);
  auto _k_D_j = wf::make_optional_output_span<9, 9>(k_D_j);
  auto _k_D_measurements = wf::make_optional_output_span<9, 6>(k_D_measurements);
  auto _k_D_bias = wf::make_optional_output_span<9, 6>(k_D_bias);

  // Operation counts:
  // add: 195
  // branch: 3
  // call: 4
  // divide: 3
  // multiply: 390
  // negate: 22
  // total: 617

  const Scalar v00016 = _gyro_bias(2, 0);
  const Scalar v00004 = _gyro_bias(1, 0);
  const Scalar v00010 = _gyro_bias(0, 0);
  const Scalar v00015 = _angular_velocity(2, 0);
  const Scalar v00003 = _angular_velocity(1, 0);
  const Scalar v00009 = _angular_velocity(0, 0);
  const Scalar v00018 = v00015 + -v00016;
  const Scalar v00007 = v00003 + -v00004;
  const Scalar v00012 = v00009 + -v00010;
  const Scalar v00002 = dt;
  const Scalar v00569 = static_cast<Scalar>(9.999999999999999e-33) +
                        (v00012 * v00012 + v00007 * v00007 + v00018 * v00018) * (v00002 * v00002);
  const Scalar v00025 = static_cast<Scalar>(0.5);
  const Scalar v00021 = std::sqrt(v00569);
  const Scalar v00033 = _i_R_j_xyzw(1, 0);
  const Scalar v00035 = _i_R_j_xyzw(3, 0);
  const Scalar v00030 = _i_R_j_xyzw(0, 0);
  const Scalar v00027 = v00021 * v00025;
  const Scalar v00001 = _i_R_j_xyzw(2, 0);
  const Scalar v01913 = v00018 * v00033;
  const Scalar v01909 = v00012 * v00035;
  const Scalar v01914 = v00018 * v00035;
  const Scalar v01902 = v00007 * v00030;
  const Scalar v00028 = std::sin(v00027);
  const Scalar v01903 = v00007 * v00033;
  const Scalar v01865 = v00001 * v00018;
  const Scalar v01904 = v00007 * v00035;
  const Scalar v01864 = v00001 * v00012;
  const Scalar v02326 = v01909 + v01913;
  const Scalar v02351 = -v00030;
  const Scalar v02325 = v01902 + v01914;
  const Scalar v01463 = (static_cast<Scalar>(1) / v00021) * v00028;
  const Scalar v02339 = v01865 + v01903;
  const Scalar v01908 = v00012 * v00030;
  const Scalar v02350 = -v00001;
  const Scalar v02324 = v01864 + v01904;
  const Scalar v02352 = -v00033;
  const Scalar v01656 = v00001 * v00007;
  const Scalar v01664 = v00012 * v00033;
  const Scalar v01471 = v00002 * v01463;
  const Scalar v00591 = v01908 + v02339;
  const Scalar v01669 = v00018 * v00030;
  const Scalar v00066 = _accelerometer_bias(1, 0);
  const Scalar v00061 = _accelerometer_bias(0, 0);
  const Scalar v00074 = _accelerometer_bias(2, 0);
  const Scalar v00031 = std::cos(v00027);
  const Scalar v00082 = std::abs(v00002);
  const Scalar v00268 = v00033 * v00033;
  const Scalar v00259 = v00030 * v00030;
  const Scalar v00269 = v00001 * v00001;
  const Scalar v02045 = v00001 * v00030;
  const Scalar v02046 = v00001 * v00033;
  const Scalar v02088 = v00030 * v00033;
  const Scalar v00065 = _linear_acceleration(1, 0);
  const Scalar v02089 = v00030 * v00035;
  const Scalar v00060 = _linear_acceleration(0, 0);
  const Scalar v00073 = _linear_acceleration(2, 0);
  const Scalar v02047 = v00001 * v00035;
  const Scalar v02100 = v00033 * v00035;
  const Scalar v01743 = v00031 * v00033;
  const Scalar v01741 = v00030 * v00031;
  const Scalar v01685 = v00001 * v00031;
  const Scalar v01468 = v00025 * v00082;
  const Scalar v01462 = v00002 * static_cast<Scalar>(2);
  const Scalar v01464 = v00002 * v00082;
  const Scalar v00130 = static_cast<Scalar>(-0.5);
  const Scalar v02328 = v00259 + v00268;
  const Scalar v02329 = v00259 + v00269;
  const Scalar v02332 = v00268 + v00269;
  const Scalar v00635 = v00035 * v02352 + v02045;
  const Scalar v00622 = v00035 * v02351 + v02046;
  const Scalar v00601 = v00035 * v02350 + v02088;
  const Scalar v00068 = v00065 + -v00066;
  const Scalar v00639 = v02046 + v02089;
  const Scalar v00063 = v00060 + -v00061;
  const Scalar v00076 = v00073 + -v00074;
  const Scalar v02348 = -static_cast<Scalar>(2);
  const Scalar v00618 = v02047 + v02088;
  const Scalar v00605 = v02045 + v02100;
  const Scalar v01086 = v00031 * v02351 + (v01656 + -v02326) * v01471;
  const Scalar v00581 = (v00018 * v02351 + v02324) * v01471 + v01743;
  const Scalar v01148 = v00031 * v02350 + (v01664 + -v02325) * v01471;
  const Scalar v00593 = v00031 * v00035 + -(v00591 * v01471);
  const Scalar v00575 = (v00007 * v02350 + v02326) * v01471 + v01741;
  const Scalar v01104 = v00031 * v02352 + (v01669 + -v02324) * v01471;
  const Scalar v00587 = (v00012 * v02352 + v02325) * v01471 + v01685;
  const Scalar v01581 = v01462 * v01468;
  const Scalar v01568 = v00025 * v01464;
  if (static_cast<bool>(_k_D_j)) {
    const Scalar v01737 = v00025 * v00035;
    const Scalar v00260 = v00035 * v00035;
    const Scalar v02331 = v00260 + v00269;
    const Scalar v02330 = v00260 + v00268;
    const Scalar v02327 = v00259 + v00260;
    const Scalar v01998 = v00130 * v01471;
    const Scalar v01736 = v00025 * v00031;
    const Scalar v00142 = v00130 * v01741;
    const Scalar v00171 = v00130 * v01685;
    const Scalar v00134 = v00035 * v01736;
    const Scalar v00165 = v00130 * v01743;
    const Scalar v00734 = v00142 + (v00012 * v01737 + v00130 * (v01656 + v01913)) * v01471;
    const Scalar v00722 = v00033 * v01736 + (v01669 + v02324) * v01998;
    const Scalar v00728 =
        v00171 + (v00030 * (v00007 * v00025) + v00130 * (v01664 + v01914)) * v01471;
    const Scalar v00740 = v00134 + (v00130 * v01865 + v00025 * (v01903 + v01908)) * v01471;
    const Scalar v00710 = v00134 + (v00130 * v01903 + v00025 * (v01865 + v01908)) * v01471;
    const Scalar v00698 = v00171 + (v00018 * v01737 + v00130 * (v01664 + v01902)) * v01471;
    const Scalar v00704 = v00165 + (v00025 * v01864 + v00130 * (v01669 + v01904)) * v01471;
    const Scalar v00716 = v00030 * v01736 + (v01656 + v02326) * v01998;
    const Scalar v00680 = v00025 * v01685 + (v01664 + v02325) * v01998;
    const Scalar v00656 = v00134 + (v00130 * v01908 + v00025 * v02339) * v01471;
    const Scalar v00668 =
        v00142 + (v00033 * (v00018 * v00025) + v00130 * (v01656 + v01909)) * v01471;
    const Scalar v00692 = v00165 + (v00007 * v01737 + v00130 * (v01669 + v01864)) * v01471;
    const Scalar v01168 = v00063 * v00639 + v00068 * (v00030 * v02350 + v02100);
    const Scalar v00300 = v00063 * (v02328 + -v02331) + v00076 * (static_cast<Scalar>(2) * v00635);
    const Scalar v00295 = v00068 * (v02331 + -v02328) + v00076 * v00639 * v02348;
    const Scalar v00289 = v00063 * (v02330 + -v02329) + v00068 * v00618 * v02348;
    const Scalar v01164 = v00063 * (v00033 * v02350 + v02089) + v00076 * v00618;
    const Scalar v00277 = v00068 * (static_cast<Scalar>(2) * v00622) + v00076 * (v02329 + -v02330);
    const Scalar v00272 = v00063 * (static_cast<Scalar>(2) * v00601) + v00068 * (v02332 + -v02327);
    const Scalar v00263 = v00063 * v00605 * v02348 + v00076 * (v02327 + -v02332);
    const Scalar v01160 = v00068 * v00605 + v00076 * (v00033 * v02351 + v02047);
    _k_D_j(0, 0) = static_cast<Scalar>(2) *
                   (v00593 * v00656 + v00668 * v01086 + v00587 * v00680 + v00692 * v01104);
    _k_D_j(0, 1) = static_cast<Scalar>(2) *
                   (v00593 * v00698 + v00704 * v01086 + v00587 * v00710 + v00716 * v01104);
    _k_D_j(0, 2) = static_cast<Scalar>(2) *
                   (v00593 * v00722 + v00728 * v01086 + v00587 * v00734 + v00740 * v01104);
    _k_D_j(0, 3) = static_cast<Scalar>(0);
    _k_D_j(0, 4) = static_cast<Scalar>(0);
    _k_D_j(0, 5) = static_cast<Scalar>(0);
    _k_D_j(0, 6) = static_cast<Scalar>(0);
    _k_D_j(0, 7) = static_cast<Scalar>(0);
    _k_D_j(0, 8) = static_cast<Scalar>(0);
    _k_D_j(1, 0) = static_cast<Scalar>(2) *
                   (v00593 * v00680 + v00656 * v01148 + v00668 * v01104 + v00575 * v00692);
    _k_D_j(1, 1) = static_cast<Scalar>(2) *
                   (v00593 * v00710 + v00698 * v01148 + v00704 * v01104 + v00575 * v00716);
    _k_D_j(1, 2) = static_cast<Scalar>(2) *
                   (v00593 * v00734 + v00722 * v01148 + v00728 * v01104 + v00575 * v00740);
    _k_D_j(1, 3) = static_cast<Scalar>(0);
    _k_D_j(1, 4) = static_cast<Scalar>(0);
    _k_D_j(1, 5) = static_cast<Scalar>(0);
    _k_D_j(1, 6) = static_cast<Scalar>(0);
    _k_D_j(1, 7) = static_cast<Scalar>(0);
    _k_D_j(1, 8) = static_cast<Scalar>(0);
    _k_D_j(2, 0) = static_cast<Scalar>(2) *
                   (v00593 * v00692 + v00668 * v01148 + v00581 * v00656 + v00680 * v01086);
    _k_D_j(2, 1) = static_cast<Scalar>(2) *
                   (v00593 * v00716 + v00704 * v01148 + v00581 * v00698 + v00710 * v01086);
    _k_D_j(2, 2) = static_cast<Scalar>(2) *
                   (v00593 * v00740 + v00728 * v01148 + v00581 * v00722 + v00734 * v01086);
    _k_D_j(2, 3) = static_cast<Scalar>(0);
    _k_D_j(2, 4) = static_cast<Scalar>(0);
    _k_D_j(2, 5) = static_cast<Scalar>(0);
    _k_D_j(2, 6) = static_cast<Scalar>(0);
    _k_D_j(2, 7) = static_cast<Scalar>(0);
    _k_D_j(2, 8) = static_cast<Scalar>(0);
    _k_D_j(3, 0) = v01160 * v01581;
    _k_D_j(3, 1) = v00263 * v01568;
    _k_D_j(3, 2) = v00272 * v01568;
    _k_D_j(3, 3) = static_cast<Scalar>(1);
    _k_D_j(3, 4) = static_cast<Scalar>(0);
    _k_D_j(3, 5) = static_cast<Scalar>(0);
    _k_D_j(3, 6) = v00002;
    _k_D_j(3, 7) = static_cast<Scalar>(0);
    _k_D_j(3, 8) = static_cast<Scalar>(0);
    _k_D_j(4, 0) = v00277 * v01568;
    _k_D_j(4, 1) = v01164 * v01581;
    _k_D_j(4, 2) = v00289 * v01568;
    _k_D_j(4, 3) = static_cast<Scalar>(0);
    _k_D_j(4, 4) = static_cast<Scalar>(1);
    _k_D_j(4, 5) = static_cast<Scalar>(0);
    _k_D_j(4, 6) = static_cast<Scalar>(0);
    _k_D_j(4, 7) = v00002;
    _k_D_j(4, 8) = static_cast<Scalar>(0);
    _k_D_j(5, 0) = v00295 * v01568;
    _k_D_j(5, 1) = v00300 * v01568;
    _k_D_j(5, 2) = v01168 * v01581;
    _k_D_j(5, 3) = static_cast<Scalar>(0);
    _k_D_j(5, 4) = static_cast<Scalar>(0);
    _k_D_j(5, 5) = static_cast<Scalar>(1);
    _k_D_j(5, 6) = static_cast<Scalar>(0);
    _k_D_j(5, 7) = static_cast<Scalar>(0);
    _k_D_j(5, 8) = v00002;
    _k_D_j(6, 0) = v01160 * v01462;
    _k_D_j(6, 1) = v00002 * v00263;
    _k_D_j(6, 2) = v00002 * v00272;
    _k_D_j(6, 3) = static_cast<Scalar>(0);
    _k_D_j(6, 4) = static_cast<Scalar>(0);
    _k_D_j(6, 5) = static_cast<Scalar>(0);
    _k_D_j(6, 6) = static_cast<Scalar>(1);
    _k_D_j(6, 7) = static_cast<Scalar>(0);
    _k_D_j(6, 8) = static_cast<Scalar>(0);
    _k_D_j(7, 0) = v00002 * v00277;
    _k_D_j(7, 1) = v01164 * v01462;
    _k_D_j(7, 2) = v00002 * v00289;
    _k_D_j(7, 3) = static_cast<Scalar>(0);
    _k_D_j(7, 4) = static_cast<Scalar>(0);
    _k_D_j(7, 5) = static_cast<Scalar>(0);
    _k_D_j(7, 6) = static_cast<Scalar>(0);
    _k_D_j(7, 7) = static_cast<Scalar>(1);
    _k_D_j(7, 8) = static_cast<Scalar>(0);
    _k_D_j(8, 0) = v00002 * v00295;
    _k_D_j(8, 1) = v00002 * v00300;
    _k_D_j(8, 2) = v01168 * v01462;
    _k_D_j(8, 3) = static_cast<Scalar>(0);
    _k_D_j(8, 4) = static_cast<Scalar>(0);
    _k_D_j(8, 5) = static_cast<Scalar>(0);
    _k_D_j(8, 6) = static_cast<Scalar>(0);
    _k_D_j(8, 7) = static_cast<Scalar>(0);
    _k_D_j(8, 8) = static_cast<Scalar>(1);
  }
  const Scalar v00326 = static_cast<Scalar>(-0.25);
  const Scalar v00323 = static_cast<Scalar>(1) / (v00021 * v00021 * v00021);
  const Scalar v01878 = v00002 * static_cast<Scalar>(0.25);
  const Scalar v01487 = v00002 * v00326;
  const Scalar v01486 = v00002 * v00130;
  const Scalar v01466 = v00002 * v00025;
  const Scalar v01744 = v00031 * (static_cast<Scalar>(1) / v00569);
  const Scalar v01520 = v00326 * v01462;
  const Scalar v02072 = v00002 * v01744;
  const Scalar v02149 = v00323 * (v00002 * v00028);
  const Scalar v01735 = v00018 * v01520;
  const Scalar v01711 = v00007 * v01520;
  const Scalar v01730 = v00012 * v01520;
  const Scalar v01587 = v00018 * static_cast<Scalar>(2);
  const Scalar v01207 =
      (v01466 * v01669 + v01486 * v02324) * v02149 + (v01487 * v01669 + v01878 * v02324) * v02072;
  const Scalar v01182 =
      (v01466 * v01656 + v01486 * v02326) * v02149 + (v01487 * v01656 + v01878 * v02326) * v02072;
  const Scalar v02323 = v01462 * (v00591 * (v00326 * v01744 + v00025 * (v00028 * v00323)));
  const Scalar v01222 =
      (v01466 * v01664 + v01486 * v02325) * v02149 + (v01487 * v01664 + v01878 * v02325) * v02072;
  const Scalar v01585 = v00007 * static_cast<Scalar>(2);
  const Scalar v01586 = v00012 * static_cast<Scalar>(2);
  const Scalar v01603 = v00002 * v01086;
  const Scalar v01438 = (v00033 * v01735 + v02351) * v01463 + v01207 * v01587;
  const Scalar v01880 = v00002 * v00581;
  const Scalar v01430 = (v00033 + v01520 * v01669) * v01463 + v01182 * v01587;
  const Scalar v01605 = v00002 * v01148;
  const Scalar v01434 = (v00035 * v01735 + v02350) * v01463 + (v00002 * v00018) * v02323;
  const Scalar v01530 = v00002 * v00593;
  const Scalar v01442 = (v00035 + v00001 * v01735) * v01463 + v01222 * v01587;
  const Scalar v01404 = (v00035 + v00033 * v01711) * v01463 + v01207 * v01585;
  const Scalar v01396 = (v00030 * v01711 + v02350) * v01463 + v01182 * v01585;
  const Scalar v01400 = (v00035 * v01711 + v02352) * v01463 + (v00002 * v00007) * v02323;
  const Scalar v01408 = (v00030 + v01520 * v01656) * v01463 + v01222 * v01585;
  const Scalar v01358 = (v00001 + v01520 * v01664) * v01463 + v01207 * v01586;
  const Scalar v01333 = (v00035 + v00030 * v01730) * v01463 + v01182 * v01586;
  const Scalar v01342 = (v00035 * v01730 + v02351) * v01463 + (v00002 * v00012) * v02323;
  const Scalar v01374 = (v00001 * v01730 + v02352) * v01463 + v01222 * v01586;
  const Scalar v01879 = v00002 * v00575;
  const Scalar v01604 = v00002 * v01104;
  const Scalar v01881 = v00002 * v00587;
  const Scalar v00632 = static_cast<Scalar>(1) + v02328 * v02348;
  const Scalar v00615 = static_cast<Scalar>(1) + v02329 * v02348;
  const Scalar v00598 = static_cast<Scalar>(1) + v02332 * v02348;
  const Scalar v01460 = v01442 * v01530 + v01434 * v01605 + v01430 * v01880 + v01438 * v01603;
  const Scalar v01426 = v01408 * v01530 + v01400 * v01605 + v01396 * v01880 + v01404 * v01603;
  const Scalar v01392 = v01374 * v01530 + v01342 * v01605 + v01333 * v01880 + v01358 * v01603;
  const Scalar v01454 = v01438 * v01530 + v01430 * v01605 + v01434 * v01604 + v01442 * v01879;
  const Scalar v01420 = v01404 * v01530 + v01396 * v01605 + v01400 * v01604 + v01408 * v01879;
  const Scalar v01386 = v01358 * v01530 + v01333 * v01605 + v01342 * v01604 + v01374 * v01879;
  const Scalar v01448 = v01430 * v01530 + v01434 * v01603 + v01438 * v01881 + v01442 * v01604;
  const Scalar v01414 = v01396 * v01530 + v01400 * v01603 + v01404 * v01881 + v01408 * v01604;
  const Scalar v01380 = v01333 * v01530 + v01342 * v01603 + v01358 * v01881 + v01374 * v01604;
  if (static_cast<bool>(_k_D_measurements)) {
    _k_D_measurements(0, 0) = static_cast<Scalar>(2) * v01380;
    _k_D_measurements(0, 1) = static_cast<Scalar>(2) * v01414;
    _k_D_measurements(0, 2) = static_cast<Scalar>(2) * v01448;
    _k_D_measurements(0, 3) = static_cast<Scalar>(0);
    _k_D_measurements(0, 4) = static_cast<Scalar>(0);
    _k_D_measurements(0, 5) = static_cast<Scalar>(0);
    _k_D_measurements(1, 0) = static_cast<Scalar>(2) * v01386;
    _k_D_measurements(1, 1) = static_cast<Scalar>(2) * v01420;
    _k_D_measurements(1, 2) = static_cast<Scalar>(2) * v01454;
    _k_D_measurements(1, 3) = static_cast<Scalar>(0);
    _k_D_measurements(1, 4) = static_cast<Scalar>(0);
    _k_D_measurements(1, 5) = static_cast<Scalar>(0);
    _k_D_measurements(2, 0) = static_cast<Scalar>(2) * v01392;
    _k_D_measurements(2, 1) = static_cast<Scalar>(2) * v01426;
    _k_D_measurements(2, 2) = static_cast<Scalar>(2) * v01460;
    _k_D_measurements(2, 3) = static_cast<Scalar>(0);
    _k_D_measurements(2, 4) = static_cast<Scalar>(0);
    _k_D_measurements(2, 5) = static_cast<Scalar>(0);
    _k_D_measurements(3, 0) = static_cast<Scalar>(0);
    _k_D_measurements(3, 1) = static_cast<Scalar>(0);
    _k_D_measurements(3, 2) = static_cast<Scalar>(0);
    _k_D_measurements(3, 3) = v00598 * v01568;
    _k_D_measurements(3, 4) = v00601 * v01581;
    _k_D_measurements(3, 5) = v00605 * v01581;
    _k_D_measurements(4, 0) = static_cast<Scalar>(0);
    _k_D_measurements(4, 1) = static_cast<Scalar>(0);
    _k_D_measurements(4, 2) = static_cast<Scalar>(0);
    _k_D_measurements(4, 3) = v00618 * v01581;
    _k_D_measurements(4, 4) = v00615 * v01568;
    _k_D_measurements(4, 5) = v00622 * v01581;
    _k_D_measurements(5, 0) = static_cast<Scalar>(0);
    _k_D_measurements(5, 1) = static_cast<Scalar>(0);
    _k_D_measurements(5, 2) = static_cast<Scalar>(0);
    _k_D_measurements(5, 3) = v00635 * v01581;
    _k_D_measurements(5, 4) = v00639 * v01581;
    _k_D_measurements(5, 5) = v00632 * v01568;
    _k_D_measurements(6, 0) = static_cast<Scalar>(0);
    _k_D_measurements(6, 1) = static_cast<Scalar>(0);
    _k_D_measurements(6, 2) = static_cast<Scalar>(0);
    _k_D_measurements(6, 3) = v00002 * v00598;
    _k_D_measurements(6, 4) = v00601 * v01462;
    _k_D_measurements(6, 5) = v00605 * v01462;
    _k_D_measurements(7, 0) = static_cast<Scalar>(0);
    _k_D_measurements(7, 1) = static_cast<Scalar>(0);
    _k_D_measurements(7, 2) = static_cast<Scalar>(0);
    _k_D_measurements(7, 3) = v00618 * v01462;
    _k_D_measurements(7, 4) = v00002 * v00615;
    _k_D_measurements(7, 5) = v00622 * v01462;
    _k_D_measurements(8, 0) = static_cast<Scalar>(0);
    _k_D_measurements(8, 1) = static_cast<Scalar>(0);
    _k_D_measurements(8, 2) = static_cast<Scalar>(0);
    _k_D_measurements(8, 3) = v00635 * v01462;
    _k_D_measurements(8, 4) = v00639 * v01462;
    _k_D_measurements(8, 5) = v00002 * v00632;
  }
  if (static_cast<bool>(_k_D_bias)) {
    const Scalar v02349 = -v00002;
    const Scalar v02353 = -v01462;
    const Scalar v02146 = v00130 * v01464;
    const Scalar v01652 = v00130 * (v00082 * v01462);
    _k_D_bias(0, 0) = v01380 * v02348;
    _k_D_bias(0, 1) = v01414 * v02348;
    _k_D_bias(0, 2) = v01448 * v02348;
    _k_D_bias(0, 3) = static_cast<Scalar>(0);
    _k_D_bias(0, 4) = static_cast<Scalar>(0);
    _k_D_bias(0, 5) = static_cast<Scalar>(0);
    _k_D_bias(1, 0) = v01386 * v02348;
    _k_D_bias(1, 1) = v01420 * v02348;
    _k_D_bias(1, 2) = v01454 * v02348;
    _k_D_bias(1, 3) = static_cast<Scalar>(0);
    _k_D_bias(1, 4) = static_cast<Scalar>(0);
    _k_D_bias(1, 5) = static_cast<Scalar>(0);
    _k_D_bias(2, 0) = v01392 * v02348;
    _k_D_bias(2, 1) = v01426 * v02348;
    _k_D_bias(2, 2) = v01460 * v02348;
    _k_D_bias(2, 3) = static_cast<Scalar>(0);
    _k_D_bias(2, 4) = static_cast<Scalar>(0);
    _k_D_bias(2, 5) = static_cast<Scalar>(0);
    _k_D_bias(3, 0) = static_cast<Scalar>(0);
    _k_D_bias(3, 1) = static_cast<Scalar>(0);
    _k_D_bias(3, 2) = static_cast<Scalar>(0);
    _k_D_bias(3, 3) = v00598 * v02146;
    _k_D_bias(3, 4) = v00601 * v01652;
    _k_D_bias(3, 5) = v00605 * v01652;
    _k_D_bias(4, 0) = static_cast<Scalar>(0);
    _k_D_bias(4, 1) = static_cast<Scalar>(0);
    _k_D_bias(4, 2) = static_cast<Scalar>(0);
    _k_D_bias(4, 3) = v00618 * v01652;
    _k_D_bias(4, 4) = v00615 * v02146;
    _k_D_bias(4, 5) = v00622 * v01652;
    _k_D_bias(5, 0) = static_cast<Scalar>(0);
    _k_D_bias(5, 1) = static_cast<Scalar>(0);
    _k_D_bias(5, 2) = static_cast<Scalar>(0);
    _k_D_bias(5, 3) = v00635 * v01652;
    _k_D_bias(5, 4) = v00639 * v01652;
    _k_D_bias(5, 5) = v00632 * v02146;
    _k_D_bias(6, 0) = static_cast<Scalar>(0);
    _k_D_bias(6, 1) = static_cast<Scalar>(0);
    _k_D_bias(6, 2) = static_cast<Scalar>(0);
    _k_D_bias(6, 3) = v00598 * v02349;
    _k_D_bias(6, 4) = v00601 * v02353;
    _k_D_bias(6, 5) = v00605 * v02353;
    _k_D_bias(7, 0) = static_cast<Scalar>(0);
    _k_D_bias(7, 1) = static_cast<Scalar>(0);
    _k_D_bias(7, 2) = static_cast<Scalar>(0);
    _k_D_bias(7, 3) = v00618 * v02353;
    _k_D_bias(7, 4) = v00615 * v02349;
    _k_D_bias(7, 5) = v00622 * v02353;
    _k_D_bias(8, 0) = static_cast<Scalar>(0);
    _k_D_bias(8, 1) = static_cast<Scalar>(0);
    _k_D_bias(8, 2) = static_cast<Scalar>(0);
    _k_D_bias(8, 3) = v00635 * v02353;
    _k_D_bias(8, 4) = v00639 * v02353;
    _k_D_bias(8, 5) = v00632 * v02349;
  }
  const Scalar v01069 =
      v00076 * v00632 + static_cast<Scalar>(2) * (v00063 * v00635 + v00068 * v00639);
  const Scalar v01064 =
      v00068 * v00615 + static_cast<Scalar>(2) * (v00063 * v00618 + v00076 * v00622);
  const Scalar v01059 =
      v00063 * v00598 + static_cast<Scalar>(2) * (v00068 * v00601 + v00076 * v00605);
  const Scalar v00114 = _i_v_j(2, 0);
  const Scalar v00100 = _i_v_j(1, 0);
  const Scalar v00084 = _i_v_j(0, 0);
  const Scalar v00103 = _i_p_j(2, 0);
  const Scalar v00087 = _i_p_j(1, 0);
  const Scalar v00054 = _i_p_j(0, 0);
  _i_R_k(0, 0) = v00575;
  _i_R_k(1, 0) = v00581;
  _i_R_k(2, 0) = v00587;
  _i_R_k(3, 0) = v00593;
  _i_p_k(0, 0) = v00054 + v00002 * (v00084 + v01059 * v01468);
  _i_p_k(1, 0) = v00087 + v00002 * (v00100 + v01064 * v01468);
  _i_p_k(2, 0) = v00103 + v00002 * (v00114 + v01069 * v01468);
  _i_v_k(0, 0) = v00084 + v00002 * v01059;
  _i_v_k(1, 0) = v00100 + v00002 * v01064;
  _i_v_k(2, 0) = v00114 + v00002 * v01069;
}

}  // namespace gen
