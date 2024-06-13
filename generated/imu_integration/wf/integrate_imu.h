// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4,
          typename T5, typename T6, typename T8, typename T9, typename T10, typename T11,
          typename T12, typename T13>
void integrate_imu(const T0& i_R_j_xyzw, const T1& i_p_j, const T2& i_v_j, const T3& gyro_bias,
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
  // add: 238
  // branch: 5
  // call: 6
  // compare: 1
  // divide: 5
  // multiply: 479
  // negate: 20
  // total: 754

  const Scalar v00016 = _gyro_bias(2, 0);
  const Scalar v00011 = _gyro_bias(1, 0);
  const Scalar v00005 = _gyro_bias(0, 0);
  const Scalar v00015 = _angular_velocity(2, 0);
  const Scalar v00010 = _angular_velocity(1, 0);
  const Scalar v00004 = _angular_velocity(0, 0);
  const Scalar v00018 = v00015 + -v00016;
  const Scalar v00013 = v00010 + -v00011;
  const Scalar v00008 = v00004 + -v00005;
  const Scalar v00003 = dt;
  const Scalar v01581 = v00003 * v00003;
  const Scalar v02622 = (v00008 * v00008 + v00013 * v00013 + v00018 * v00018) * v01581;
  const Scalar v00031 = static_cast<Scalar>(0.25);
  const Scalar v00026 = static_cast<Scalar>(0.5);
  const Scalar v00021 = std::sqrt(v02622);
  const Scalar v00036 = std::sqrt(static_cast<Scalar>(1) + v00031 * v02622);
  const Scalar v00028 = v00021 * v00026;
  const Scalar v00037 = static_cast<Scalar>(1) / v00036;
  const Scalar v00029 = std::sin(v00028);
  const Scalar v01938 = v00026 * v00037;
  const Scalar v01589 = v00003 * v00013;
  const Scalar v01590 = v00003 * v00018;
  const Scalar v01588 = v00003 * v00008;
  const Scalar v01678 = (static_cast<Scalar>(1) / v00021) * v00029;
  const Scalar v00042 = std::cos(v00028);
  const bool v00022 = static_cast<Scalar>(1e-16) < v00021;
  Scalar v00039;
  Scalar v00043;
  Scalar v00048;
  Scalar v00053;
  if (v00022) {
    v00039 = v01589 * v01678;
    v00043 = v00042;
    v00048 = v01590 * v01678;
    v00053 = v01588 * v01678;
  } else {
    v00039 = v01589 * v01938;
    v00043 = v00037;
    v00048 = v01590 * v01938;
    v00053 = v01588 * v01938;
  }
  const Scalar v00045 = _i_R_j_xyzw(1, 0);
  const Scalar v00041 = _i_R_j_xyzw(0, 0);
  const Scalar v00001 = _i_R_j_xyzw(2, 0);
  const Scalar v00050 = _i_R_j_xyzw(3, 0);
  const Scalar v00095 = _accelerometer_bias(1, 0);
  const Scalar v00090 = _accelerometer_bias(0, 0);
  const Scalar v00103 = _accelerometer_bias(2, 0);
  const Scalar v02648 = v00050 * v00053 + (v00041 * v00043 + v00045 * v00048);
  const Scalar v02666 = -v00041;
  const Scalar v02656 = v00048 * v00050 + (v00039 * v00041 + v00001 * v00043);
  const Scalar v02665 = -v00001;
  const Scalar v02652 = v00039 * v00050 + (v00043 * v00045 + v00001 * v00053);
  const Scalar v02667 = -v00045;
  const Scalar v00094 = _linear_acceleration(1, 0);
  const Scalar v00089 = _linear_acceleration(0, 0);
  const Scalar v00102 = _linear_acceleration(2, 0);
  const Scalar v00111 = std::abs(v00003);
  const Scalar v00097 = v00094 + -v00095;
  const Scalar v00092 = v00089 + -v00090;
  const Scalar v00105 = v00102 + -v00103;
  const Scalar v00699 = v00043 * v00050 + -(v00041 * v00053 + v00039 * v00045 + v00001 * v00048);
  const Scalar v01266 = v00001 * v00039 + -v02648;
  const Scalar v00066 = v00048 * v02666 + v02652;
  const Scalar v01274 = v00045 * v00053 + -v02656;
  const Scalar v00055 = v00039 * v02665 + v02648;
  const Scalar v01270 = v00041 * v00048 + -v02652;
  const Scalar v00072 = v00053 * v02667 + v02656;
  const Scalar v02663 = -static_cast<Scalar>(2);
  const Scalar v00154 = static_cast<Scalar>(-0.5);
  const Scalar v00286 = static_cast<Scalar>(-0.25);
  const Scalar v01579 = v00003 * v00111;
  if (static_cast<bool>(_k_D_j)) {
    const Scalar v02668 = -v00050;
    const Scalar v02382 = v00001 * v00092;
    const Scalar v02466 = v00045 * v00105;
    const Scalar v02460 = v00041 * v00097;
    const Scalar v02495 = v00105 * static_cast<Scalar>(4);
    const Scalar v02493 = v00097 * static_cast<Scalar>(4);
    const Scalar v02491 = v00092 * static_cast<Scalar>(4);
    const Scalar v01449 = v00043 * v00699;
    const Scalar v01425 = v00053 * v01266;
    const Scalar v01484 = v00048 * v01274;
    const Scalar v01421 = v00039 * v00699;
    const Scalar v01464 = v00053 * v01274;
    const Scalar v01422 = v00048 * v01266;
    const Scalar v01430 = v00043 * v01266;
    const Scalar v01475 = v00039 * v01274;
    const Scalar v01429 = v00053 * v00699;
    const Scalar v01432 = v00048 * v01270;
    const Scalar v01469 = v00043 * v01274;
    const Scalar v01444 = v00048 * v00699;
    const Scalar v01441 = v00053 * v01270;
    const Scalar v01450 = v00039 * v01270;
    const Scalar v01436 = v00043 * v01270;
    const Scalar v01440 = v00039 * v01266;
    const Scalar v00965 = v00041 * v00092;
    const Scalar v00933 = v00045 * v00097;
    const Scalar v00934 = v00001 * v00105;
    const Scalar v02171 = v00050 * static_cast<Scalar>(2);
    const Scalar v00997 = v00933 + v00965;
    const Scalar v01008 = v02495 * v02666 + static_cast<Scalar>(2) * (v02382 + v00050 * v00097);
    const Scalar v01681 = v00001 * static_cast<Scalar>(2);
    const Scalar v00993 = v02460 + v00092 * v02667;
    const Scalar v01003 =
        v02495 * v02667 + static_cast<Scalar>(2) * (v00092 * v02668 + v00001 * v00097);
    const Scalar v01731 = v00041 * static_cast<Scalar>(2);
    const Scalar v01732 = v00045 * static_cast<Scalar>(2);
    const Scalar v00963 = v02493 * v02665 + static_cast<Scalar>(2) * (v02466 + v00050 * v00092);
    const Scalar v00972 =
        v02493 * v02666 + static_cast<Scalar>(2) * (v00105 * v02668 + v00045 * v00092);
    const Scalar v00957 = v02382 + v00105 * v02666;
    const Scalar v00966 = v00934 + v00965;
    const Scalar v00927 =
        v02491 * v02665 + static_cast<Scalar>(2) * (v00097 * v02668 + v00041 * v00105);
    const Scalar v00935 = v00933 + v00934;
    const Scalar v00921 = v02466 + v00097 * v02665;
    const Scalar v00932 = v02491 * v02667 + static_cast<Scalar>(2) * (v02460 + v00050 * v00105);
    const Scalar v01501 =
        (v01484 + v00039 * v00066) * v02663 + static_cast<Scalar>(2) * (v01425 + v01449);
    const Scalar v01519 =
        (v01422 + v01464) * v02663 + static_cast<Scalar>(2) * (v01421 + v00043 * v00066);
    const Scalar v01472 = v01440 + v01444 + v01469 + v00053 * v00066;
    const Scalar v01510 =
        (v01429 + v01475) * v02663 + static_cast<Scalar>(2) * (v01430 + v00048 * v00066);
    const Scalar v01482 =
        (v01432 + v01475) * v02663 + static_cast<Scalar>(2) * (v01429 + v00043 * v00055);
    const Scalar v01492 =
        (v01441 + v01444) * v02663 + static_cast<Scalar>(2) * (v01469 + v00039 * v00055);
    const Scalar v01466 = v01421 + v01436 + v01464 + v00048 * v00055;
    const Scalar v01487 =
        (v01450 + v00053 * v00055) * v02663 + static_cast<Scalar>(2) * (v01449 + v01484);
    const Scalar v01439 =
        (v01421 + v01422) * v02663 + static_cast<Scalar>(2) * (v00053 * v00072 + v01436);
    const Scalar v01453 =
        (v01425 + v00048 * v00072) * v02663 + static_cast<Scalar>(2) * (v01449 + v01450);
    const Scalar v01433 = v01429 + v01430 + v00039 * v00072 + v01432;
    const Scalar v01448 =
        (v01440 + v01441) * v02663 + static_cast<Scalar>(2) * (v01444 + v00043 * v00072);
    const Scalar v01105 = v00045 * v01008 + v00997 * v02171;
    const Scalar v01101 = v00041 * v01003 + v00993 * v01681;
    const Scalar v01096 = v00997 * v01731 + v00050 * v01003;
    const Scalar v01092 = v00993 * v01732 + v00001 * v01008;
    const Scalar v01087 = v00001 * v01003 + v00050 * v01008;
    const Scalar v01643 = static_cast<Scalar>(2) * v00154;
    const Scalar v01332 = v00041 * v00993 + v00045 * v00997;
    const Scalar v01078 = v00045 * v00972 + v00050 * v00963;
    const Scalar v01323 = v00041 * v00966 + v00001 * v00957;
    const Scalar v01069 = v00041 * v00963 + v00966 * v02171;
    const Scalar v01065 = v00957 * v01732 + v00001 * v00972;
    const Scalar v01060 = v00966 * v01681 + v00050 * v00972;
    const Scalar v01056 = v00957 * v01731 + v00045 * v00963;
    const Scalar v01051 = v00935 * v01732 + v00050 * v00927;
    const Scalar v01047 = v00041 * v00932 + v00921 * v01681;
    const Scalar v01042 = v00041 * v00927 + v00050 * v00932;
    const Scalar v01287 = v00045 * v00921 + v00001 * v00935;
    const Scalar v01033 = v00001 * v00932 + v00935 * v02171;
    const Scalar v01029 = v00921 * v01731 + v00045 * v00927;
    const Scalar v01733 = static_cast<Scalar>(2) * v00286;
    _k_D_j(0, 0) =
        v00154 * (v01433 * v01731 + v00045 * v01439) + v00026 * (v00001 * v01448 + v00050 * v01453);
    _k_D_j(0, 1) =
        v00154 * (v01433 * v01732 + v00001 * v01453) + v00026 * (v00041 * v01439 + v00050 * v01448);
    _k_D_j(0, 2) =
        v00154 * (v00041 * v01448 + v01433 * v01681) + v00026 * (v00045 * v01453 + v00050 * v01439);
    _k_D_j(0, 3) = static_cast<Scalar>(0);
    _k_D_j(0, 4) = static_cast<Scalar>(0);
    _k_D_j(0, 5) = static_cast<Scalar>(0);
    _k_D_j(0, 6) = static_cast<Scalar>(0);
    _k_D_j(0, 7) = static_cast<Scalar>(0);
    _k_D_j(0, 8) = static_cast<Scalar>(0);
    _k_D_j(1, 0) =
        v00154 * (v01466 * v01731 + v00045 * v01482) + v00026 * (v00001 * v01487 + v00050 * v01492);
    _k_D_j(1, 1) =
        v00154 * (v01466 * v01732 + v00001 * v01492) + v00026 * (v00041 * v01482 + v00050 * v01487);
    _k_D_j(1, 2) =
        v00154 * (v00041 * v01487 + v01466 * v01681) + v00026 * (v00045 * v01492 + v00050 * v01482);
    _k_D_j(1, 3) = static_cast<Scalar>(0);
    _k_D_j(1, 4) = static_cast<Scalar>(0);
    _k_D_j(1, 5) = static_cast<Scalar>(0);
    _k_D_j(1, 6) = static_cast<Scalar>(0);
    _k_D_j(1, 7) = static_cast<Scalar>(0);
    _k_D_j(1, 8) = static_cast<Scalar>(0);
    _k_D_j(2, 0) =
        v00154 * (v01472 * v01731 + v00045 * v01501) + v00026 * (v00001 * v01510 + v00050 * v01519);
    _k_D_j(2, 1) =
        v00154 * (v01472 * v01732 + v00001 * v01519) + v00026 * (v00041 * v01501 + v00050 * v01510);
    _k_D_j(2, 2) =
        v00154 * (v00041 * v01510 + v01472 * v01681) + v00026 * (v00045 * v01519 + v00050 * v01501);
    _k_D_j(2, 3) = static_cast<Scalar>(0);
    _k_D_j(2, 4) = static_cast<Scalar>(0);
    _k_D_j(2, 5) = static_cast<Scalar>(0);
    _k_D_j(2, 6) = static_cast<Scalar>(0);
    _k_D_j(2, 7) = static_cast<Scalar>(0);
    _k_D_j(2, 8) = static_cast<Scalar>(0);
    _k_D_j(3, 0) = (v00286 * v01029 + v00031 * v01033) * v01579;
    _k_D_j(3, 1) = (v01287 * v01733 + v00031 * v01042) * v01579;
    _k_D_j(3, 2) = (v00286 * v01047 + v00031 * v01051) * v01579;
    _k_D_j(3, 3) = static_cast<Scalar>(1);
    _k_D_j(3, 4) = static_cast<Scalar>(0);
    _k_D_j(3, 5) = static_cast<Scalar>(0);
    _k_D_j(3, 6) = v00003;
    _k_D_j(3, 7) = static_cast<Scalar>(0);
    _k_D_j(3, 8) = static_cast<Scalar>(0);
    _k_D_j(4, 0) = (v00286 * v01056 + v00031 * v01060) * v01579;
    _k_D_j(4, 1) = (v00286 * v01065 + v00031 * v01069) * v01579;
    _k_D_j(4, 2) = (v01323 * v01733 + v00031 * v01078) * v01579;
    _k_D_j(4, 3) = static_cast<Scalar>(0);
    _k_D_j(4, 4) = static_cast<Scalar>(1);
    _k_D_j(4, 5) = static_cast<Scalar>(0);
    _k_D_j(4, 6) = static_cast<Scalar>(0);
    _k_D_j(4, 7) = v00003;
    _k_D_j(4, 8) = static_cast<Scalar>(0);
    _k_D_j(5, 0) = (v01332 * v01733 + v00031 * v01087) * v01579;
    _k_D_j(5, 1) = (v00286 * v01092 + v00031 * v01096) * v01579;
    _k_D_j(5, 2) = (v00286 * v01101 + v00031 * v01105) * v01579;
    _k_D_j(5, 3) = static_cast<Scalar>(0);
    _k_D_j(5, 4) = static_cast<Scalar>(0);
    _k_D_j(5, 5) = static_cast<Scalar>(1);
    _k_D_j(5, 6) = static_cast<Scalar>(0);
    _k_D_j(5, 7) = static_cast<Scalar>(0);
    _k_D_j(5, 8) = v00003;
    _k_D_j(6, 0) = v00003 * (v00154 * v01029 + v00026 * v01033);
    _k_D_j(6, 1) = v00003 * (v01287 * v01643 + v00026 * v01042);
    _k_D_j(6, 2) = v00003 * (v00154 * v01047 + v00026 * v01051);
    _k_D_j(6, 3) = static_cast<Scalar>(0);
    _k_D_j(6, 4) = static_cast<Scalar>(0);
    _k_D_j(6, 5) = static_cast<Scalar>(0);
    _k_D_j(6, 6) = static_cast<Scalar>(1);
    _k_D_j(6, 7) = static_cast<Scalar>(0);
    _k_D_j(6, 8) = static_cast<Scalar>(0);
    _k_D_j(7, 0) = v00003 * (v00154 * v01056 + v00026 * v01060);
    _k_D_j(7, 1) = v00003 * (v00154 * v01065 + v00026 * v01069);
    _k_D_j(7, 2) = v00003 * (v01323 * v01643 + v00026 * v01078);
    _k_D_j(7, 3) = static_cast<Scalar>(0);
    _k_D_j(7, 4) = static_cast<Scalar>(0);
    _k_D_j(7, 5) = static_cast<Scalar>(0);
    _k_D_j(7, 6) = static_cast<Scalar>(0);
    _k_D_j(7, 7) = static_cast<Scalar>(1);
    _k_D_j(7, 8) = static_cast<Scalar>(0);
    _k_D_j(8, 0) = v00003 * (v01332 * v01643 + v00026 * v01087);
    _k_D_j(8, 1) = v00003 * (v00154 * v01092 + v00026 * v01096);
    _k_D_j(8, 2) = v00003 * (v00154 * v01101 + v00026 * v01105);
    _k_D_j(8, 3) = static_cast<Scalar>(0);
    _k_D_j(8, 4) = static_cast<Scalar>(0);
    _k_D_j(8, 5) = static_cast<Scalar>(0);
    _k_D_j(8, 6) = static_cast<Scalar>(0);
    _k_D_j(8, 7) = static_cast<Scalar>(0);
    _k_D_j(8, 8) = static_cast<Scalar>(1);
  }
  const Scalar v01578 = v00003 * static_cast<Scalar>(2);
  const Scalar v01583 = v00003 * v01578;
  const Scalar v01875 = v00008 * v01583;
  const Scalar v01907 = v00013 * v01583;
  const Scalar v01937 = v00018 * v01583;
  const Scalar v02050 = v00013 * v01581;
  Scalar v00433;
  Scalar v00438;
  Scalar v00444;
  Scalar v00453;
  Scalar v00484;
  Scalar v00488;
  Scalar v00494;
  Scalar v00534;
  Scalar v00541;
  if (v00022) {
    const Scalar v01522 = v00029 * v00154 * (static_cast<Scalar>(1) / (v00021 * v00021 * v00021)) +
                          v00031 * v00042 * (static_cast<Scalar>(1) / v02622);
    const Scalar v02059 = v00018 * v01581;
    const Scalar v02632 = v01522 * (v00008 * v01578);
    const Scalar v02234 = v00286 * v01678;
    v00433 = v02050 * v02632;
    v00438 = v01875 * v02234;
    v00444 = v02059 * v02632;
    v00453 = v00003 * (v01875 * (v00008 * v01522) + v01678);
    v00484 = v00003 * (v01907 * (v00013 * v01522) + v01678);
    v00488 = v01907 * v02234;
    v00494 = (v00013 * v01578) * (v01522 * v02059);
    v00534 = v01937 * v02234;
    v00541 = v00003 * (v01937 * (v00018 * v01522) + v01678);
  } else {
    const Scalar v00431 = static_cast<Scalar>(1) / (v00036 * v00036 * v00036);
    const Scalar v00427 = static_cast<Scalar>(-0.0625);
    const Scalar v01761 = v00427 * v00431;
    const Scalar v01648 = v00431 * v01578;
    const Scalar v02056 = v00018 * v00427;
    const Scalar v02643 = v01648 * (v00008 * v01581);
    const Scalar v02552 = (static_cast<Scalar>(-0.125)) * (v00431 * v01583);
    v00433 = (v00013 * v00427) * v02643;
    v00438 = v00008 * v02552;
    v00444 = v02056 * v02643;
    v00453 = v00003 * (v01761 * (v00008 * v01875) + v01938);
    v00484 = v00003 * (v01761 * (v00013 * v01907) + v01938);
    v00488 = v00013 * v02552;
    v00494 = v02050 * (v01648 * v02056);
    v00534 = v00018 * v02552;
    v00541 = v00003 * (v01761 * (v00018 * v01937) + v01938);
  }
  const Scalar v00495 = v00045 * v00494;
  const Scalar v00470 = v00041 * v00433;
  const Scalar v01130 = v00001 * v00444;
  const Scalar v00718 = v00041 * v00041;
  const Scalar v00700 = v00045 * v00045;
  const Scalar v00701 = v00001 * v00001;
  const Scalar v00519 = v00050 * v00494;
  const Scalar v00472 = v00050 * v00444;
  const Scalar v00466 = v00050 * v00433;
  const Scalar v00561 = v00519 + v00541 * v02666 + v00045 * v00534 + v01130;
  const Scalar v00549 = v00472 + v00494 * v02665 + v00041 * v00534 + v00045 * v00541;
  const Scalar v01185 = v00050 * v00534 + -(v00495 + v00001 * v00541 + v00041 * v00444);
  const Scalar v00567 = v00444 * v02667 + v00001 * v00534 + v00050 * v00541 + v00041 * v00494;
  const Scalar v00514 = v00494 * v02666 + v00045 * v00488 + v00050 * v00484 + v00001 * v00433;
  const Scalar v00502 = v00466 + v00484 * v02665 + v00041 * v00488 + v00495;
  const Scalar v01159 = v00050 * v00488 + -(v00470 + v00045 * v00484 + v00001 * v00494);
  const Scalar v00520 = v00433 * v02667 + v00041 * v00484 + v00001 * v00488 + v00519;
  const Scalar v00467 = v00444 * v02666 + v00045 * v00438 + v00001 * v00453 + v00466;
  const Scalar v00455 = v00433 * v02665 + v00041 * v00438 + v00050 * v00453 + v00045 * v00444;
  const Scalar v01133 = v00050 * v00438 + -(v00041 * v00453 + v01130 + v00045 * v00433);
  const Scalar v00473 = v00453 * v02667 + v00470 + v00001 * v00438 + v00472;
  const Scalar v00727 = v00001 * v00045;
  const Scalar v00709 = v00001 * v00041;
  const Scalar v00706 = v00041 * v00045;
  const Scalar v01593 = v00026 * v00111;
  const Scalar v00738 = static_cast<Scalar>(1) + (v00700 + v00718) * v02663;
  const Scalar v00745 = v00727 + v00041 * v00050;
  const Scalar v00741 = v00709 + v00050 * v02667;
  const Scalar v00728 = v00050 * v02666 + v00727;
  const Scalar v00721 = static_cast<Scalar>(1) + (v00701 + v00718) * v02663;
  const Scalar v00724 = v00706 + v00001 * v00050;
  const Scalar v00711 = v00709 + v00045 * v00050;
  const Scalar v00707 = v00050 * v02665 + v00706;
  const Scalar v00704 = static_cast<Scalar>(1) + (v00700 + v00701) * v02663;
  const Scalar v01576 = v00567 * v00699 + v01185 * v01274 + v00066 * v00549 + v00561 * v01266;
  const Scalar v01558 = v00520 * v00699 + v01159 * v01274 + v00066 * v00502 + v00514 * v01266;
  const Scalar v01540 = v00473 * v00699 + v01133 * v01274 + v00066 * v00455 + v00467 * v01266;
  const Scalar v01570 = v00561 * v00699 + v00549 * v01274 + v01185 * v01270 + v00055 * v00567;
  const Scalar v01552 = v00514 * v00699 + v00502 * v01274 + v01159 * v01270 + v00055 * v00520;
  const Scalar v01534 = v00467 * v00699 + v00455 * v01274 + v01133 * v01270 + v00055 * v00473;
  const Scalar v01564 = v00549 * v00699 + v01185 * v01266 + v00072 * v00561 + v00567 * v01270;
  const Scalar v01546 = v00502 * v00699 + v01159 * v01266 + v00072 * v00514 + v00520 * v01270;
  const Scalar v01528 = v00455 * v00699 + v01133 * v01266 + v00072 * v00467 + v00473 * v01270;
  if (static_cast<bool>(_k_D_measurements)) {
    const Scalar v02111 = v00026 * v01579;
    const Scalar v01801 = v01578 * v01593;
    _k_D_measurements(0, 0) = static_cast<Scalar>(2) * v01528;
    _k_D_measurements(0, 1) = static_cast<Scalar>(2) * v01546;
    _k_D_measurements(0, 2) = static_cast<Scalar>(2) * v01564;
    _k_D_measurements(0, 3) = static_cast<Scalar>(0);
    _k_D_measurements(0, 4) = static_cast<Scalar>(0);
    _k_D_measurements(0, 5) = static_cast<Scalar>(0);
    _k_D_measurements(1, 0) = static_cast<Scalar>(2) * v01534;
    _k_D_measurements(1, 1) = static_cast<Scalar>(2) * v01552;
    _k_D_measurements(1, 2) = static_cast<Scalar>(2) * v01570;
    _k_D_measurements(1, 3) = static_cast<Scalar>(0);
    _k_D_measurements(1, 4) = static_cast<Scalar>(0);
    _k_D_measurements(1, 5) = static_cast<Scalar>(0);
    _k_D_measurements(2, 0) = static_cast<Scalar>(2) * v01540;
    _k_D_measurements(2, 1) = static_cast<Scalar>(2) * v01558;
    _k_D_measurements(2, 2) = static_cast<Scalar>(2) * v01576;
    _k_D_measurements(2, 3) = static_cast<Scalar>(0);
    _k_D_measurements(2, 4) = static_cast<Scalar>(0);
    _k_D_measurements(2, 5) = static_cast<Scalar>(0);
    _k_D_measurements(3, 0) = static_cast<Scalar>(0);
    _k_D_measurements(3, 1) = static_cast<Scalar>(0);
    _k_D_measurements(3, 2) = static_cast<Scalar>(0);
    _k_D_measurements(3, 3) = v00704 * v02111;
    _k_D_measurements(3, 4) = v00707 * v01801;
    _k_D_measurements(3, 5) = v00711 * v01801;
    _k_D_measurements(4, 0) = static_cast<Scalar>(0);
    _k_D_measurements(4, 1) = static_cast<Scalar>(0);
    _k_D_measurements(4, 2) = static_cast<Scalar>(0);
    _k_D_measurements(4, 3) = v00724 * v01801;
    _k_D_measurements(4, 4) = v00721 * v02111;
    _k_D_measurements(4, 5) = v00728 * v01801;
    _k_D_measurements(5, 0) = static_cast<Scalar>(0);
    _k_D_measurements(5, 1) = static_cast<Scalar>(0);
    _k_D_measurements(5, 2) = static_cast<Scalar>(0);
    _k_D_measurements(5, 3) = v00741 * v01801;
    _k_D_measurements(5, 4) = v00745 * v01801;
    _k_D_measurements(5, 5) = v00738 * v02111;
    _k_D_measurements(6, 0) = static_cast<Scalar>(0);
    _k_D_measurements(6, 1) = static_cast<Scalar>(0);
    _k_D_measurements(6, 2) = static_cast<Scalar>(0);
    _k_D_measurements(6, 3) = v00003 * v00704;
    _k_D_measurements(6, 4) = v00707 * v01578;
    _k_D_measurements(6, 5) = v00711 * v01578;
    _k_D_measurements(7, 0) = static_cast<Scalar>(0);
    _k_D_measurements(7, 1) = static_cast<Scalar>(0);
    _k_D_measurements(7, 2) = static_cast<Scalar>(0);
    _k_D_measurements(7, 3) = v00724 * v01578;
    _k_D_measurements(7, 4) = v00003 * v00721;
    _k_D_measurements(7, 5) = v00728 * v01578;
    _k_D_measurements(8, 0) = static_cast<Scalar>(0);
    _k_D_measurements(8, 1) = static_cast<Scalar>(0);
    _k_D_measurements(8, 2) = static_cast<Scalar>(0);
    _k_D_measurements(8, 3) = v00741 * v01578;
    _k_D_measurements(8, 4) = v00745 * v01578;
    _k_D_measurements(8, 5) = v00003 * v00738;
  }
  if (static_cast<bool>(_k_D_bias)) {
    const Scalar v02664 = -v00003;
    const Scalar v02669 = -v01578;
    const Scalar v02179 = v00154 * v01579;
    const Scalar v01760 = v00154 * (v00111 * v01578);
    _k_D_bias(0, 0) = v01528 * v02663;
    _k_D_bias(0, 1) = v01546 * v02663;
    _k_D_bias(0, 2) = v01564 * v02663;
    _k_D_bias(0, 3) = static_cast<Scalar>(0);
    _k_D_bias(0, 4) = static_cast<Scalar>(0);
    _k_D_bias(0, 5) = static_cast<Scalar>(0);
    _k_D_bias(1, 0) = v01534 * v02663;
    _k_D_bias(1, 1) = v01552 * v02663;
    _k_D_bias(1, 2) = v01570 * v02663;
    _k_D_bias(1, 3) = static_cast<Scalar>(0);
    _k_D_bias(1, 4) = static_cast<Scalar>(0);
    _k_D_bias(1, 5) = static_cast<Scalar>(0);
    _k_D_bias(2, 0) = v01540 * v02663;
    _k_D_bias(2, 1) = v01558 * v02663;
    _k_D_bias(2, 2) = v01576 * v02663;
    _k_D_bias(2, 3) = static_cast<Scalar>(0);
    _k_D_bias(2, 4) = static_cast<Scalar>(0);
    _k_D_bias(2, 5) = static_cast<Scalar>(0);
    _k_D_bias(3, 0) = static_cast<Scalar>(0);
    _k_D_bias(3, 1) = static_cast<Scalar>(0);
    _k_D_bias(3, 2) = static_cast<Scalar>(0);
    _k_D_bias(3, 3) = v00704 * v02179;
    _k_D_bias(3, 4) = v00707 * v01760;
    _k_D_bias(3, 5) = v00711 * v01760;
    _k_D_bias(4, 0) = static_cast<Scalar>(0);
    _k_D_bias(4, 1) = static_cast<Scalar>(0);
    _k_D_bias(4, 2) = static_cast<Scalar>(0);
    _k_D_bias(4, 3) = v00724 * v01760;
    _k_D_bias(4, 4) = v00721 * v02179;
    _k_D_bias(4, 5) = v00728 * v01760;
    _k_D_bias(5, 0) = static_cast<Scalar>(0);
    _k_D_bias(5, 1) = static_cast<Scalar>(0);
    _k_D_bias(5, 2) = static_cast<Scalar>(0);
    _k_D_bias(5, 3) = v00741 * v01760;
    _k_D_bias(5, 4) = v00745 * v01760;
    _k_D_bias(5, 5) = v00738 * v02179;
    _k_D_bias(6, 0) = static_cast<Scalar>(0);
    _k_D_bias(6, 1) = static_cast<Scalar>(0);
    _k_D_bias(6, 2) = static_cast<Scalar>(0);
    _k_D_bias(6, 3) = v00704 * v02664;
    _k_D_bias(6, 4) = v00707 * v02669;
    _k_D_bias(6, 5) = v00711 * v02669;
    _k_D_bias(7, 0) = static_cast<Scalar>(0);
    _k_D_bias(7, 1) = static_cast<Scalar>(0);
    _k_D_bias(7, 2) = static_cast<Scalar>(0);
    _k_D_bias(7, 3) = v00724 * v02669;
    _k_D_bias(7, 4) = v00721 * v02664;
    _k_D_bias(7, 5) = v00728 * v02669;
    _k_D_bias(8, 0) = static_cast<Scalar>(0);
    _k_D_bias(8, 1) = static_cast<Scalar>(0);
    _k_D_bias(8, 2) = static_cast<Scalar>(0);
    _k_D_bias(8, 3) = v00741 * v02669;
    _k_D_bias(8, 4) = v00745 * v02669;
    _k_D_bias(8, 5) = v00738 * v02664;
  }
  const Scalar v01259 =
      v00105 * v00738 + static_cast<Scalar>(2) * (v00092 * v00741 + v00097 * v00745);
  const Scalar v01254 =
      v00097 * v00721 + static_cast<Scalar>(2) * (v00092 * v00724 + v00105 * v00728);
  const Scalar v01249 =
      v00092 * v00704 + static_cast<Scalar>(2) * (v00097 * v00707 + v00105 * v00711);
  const Scalar v00143 = _i_v_j(2, 0);
  const Scalar v00129 = _i_v_j(1, 0);
  const Scalar v00113 = _i_v_j(0, 0);
  const Scalar v00077 = static_cast<Scalar>(1) / std::sqrt(v00699 * v00699 + v00066 * v00066 +
                                                           v00072 * v00072 + v00055 * v00055);
  const Scalar v00132 = _i_p_j(2, 0);
  const Scalar v00116 = _i_p_j(1, 0);
  const Scalar v00083 = _i_p_j(0, 0);
  _i_R_k(0, 0) = v00055 * v00077;
  _i_R_k(1, 0) = v00066 * v00077;
  _i_R_k(2, 0) = v00072 * v00077;
  _i_R_k(3, 0) = v00077 * v00699;
  _i_p_k(0, 0) = v00083 + v00003 * (v00113 + v01249 * v01593);
  _i_p_k(1, 0) = v00116 + v00003 * (v00129 + v01254 * v01593);
  _i_p_k(2, 0) = v00132 + v00003 * (v00143 + v01259 * v01593);
  _i_v_k(0, 0) = v00113 + v00003 * v01249;
  _i_v_k(1, 0) = v00129 + v00003 * v01254;
  _i_v_k(2, 0) = v00143 + v00003 * v01259;
}

}  // namespace gen
