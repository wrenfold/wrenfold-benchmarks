// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T3, typename T4, typename T5>
void quat_interpolation_no_conditional(const T0& q0_xyzw, const T1& q1_xyzw, const Scalar alpha,
                                       T3&& q_out, T4&& d0, T5&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _q_out = wf::make_output_span<4, 1>(q_out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 323
  // branch: 6
  // call: 5
  // compare: 2
  // divide: 7
  // multiply: 566
  // negate: 25
  // total: 934

  const Scalar v00013 = _q0_xyzw(3, 0);
  const Scalar v00005 = _q1_xyzw(3, 0);
  const Scalar v00011 = _q1_xyzw(2, 0);
  const Scalar v00001 = _q0_xyzw(2, 0);
  const Scalar v00014 = _q1_xyzw(1, 0);
  const Scalar v00004 = _q0_xyzw(1, 0);
  const Scalar v00010 = _q0_xyzw(0, 0);
  const Scalar v00008 = _q1_xyzw(0, 0);
  const Scalar v00021 = v00005 * v00013;
  const Scalar v00020 = v00001 * v00011;
  const Scalar v00019 = v00004 * v00014;
  const Scalar v00018 = v00008 * v00010;
  const Scalar v08911 = v00018 + v00019;
  const Scalar v00022 = v08911 + (v00020 + v00021);
  std::int64_t v00026;
  if (v00022 < static_cast<Scalar>(0)) {
    v00026 = -1;
  } else {
    v00026 = 1;
  }
  const Scalar v00027 = static_cast<Scalar>(v00026);
  const Scalar v00028 = v00022 * v00027;
  const bool v00030 = static_cast<Scalar>(1) < v00028;
  Scalar v00031;
  if (v00030) {
    v00031 = static_cast<Scalar>(1);
  } else {
    v00031 = v00028;
  }
  const Scalar v00949 = v00001 * v00008;
  const Scalar v00948 = v00004 * v00005;
  const Scalar v00959 = v00004 * v00011;
  const Scalar v00958 = v00005 * v00010;
  const Scalar v00954 = v00001 * v00005;
  const Scalar v00953 = v00010 * v00014;
  const Scalar v00002 = alpha;
  const Scalar v07781 = v00013 * v00014;
  const Scalar v07755 = v00010 * v00011;
  const Scalar v07754 = v00008 * v00013;
  const Scalar v07558 = v00001 * v00014;
  const Scalar v07780 = v00011 * v00013;
  const Scalar v07585 = v00004 * v00008;
  const Scalar v02870 = v00002 * v00027;
  const Scalar v00043 = std::acos(v00031);
  const Scalar v00033 = static_cast<Scalar>(1) + v00031 * -v00031;
  const Scalar v00952 = v07755 + v07781 + -(v00948 + v00949);
  const Scalar v00962 = v07558 + v07754 + -(v00958 + v00959);
  const Scalar v00957 = v07585 + v07780 + -(v00953 + v00954);
  const Scalar v02874 = v00043 * v02870;
  const Scalar v00037 = static_cast<Scalar>(1) / v00033;
  const Scalar v03527 = static_cast<Scalar>(4) * v02874;
  const Scalar v02107 = v00957 * v00957 + v00962 * v00962 + v00952 * v00952;
  const Scalar v00967 = v02107 * v03527 * (v00037 * v02874);
  const Scalar v00056 = static_cast<Scalar>(0.5);
  const Scalar v00054 = std::sqrt(v00967);
  const Scalar v00058 = v00054 * v00056;
  const Scalar v00034 = std::sqrt(v00033);
  const Scalar v00064 = std::cos(v00058);
  const Scalar v08933 = v00001 * v00962 + v00013 * v00952;
  const Scalar v05704 = v00010 * v00957;
  const Scalar v00083 = static_cast<Scalar>(-0.5);
  const Scalar v08947 = -v00010;
  const Scalar v08934 = v00010 * v00952 + v00013 * v00957;
  const Scalar v05498 = v00004 * v00962;
  const Scalar v08946 = -v00004;
  const Scalar v08932 = v00004 * v00957 + v00013 * v00962;
  const Scalar v05421 = v00001 * v00952;
  const Scalar v08945 = -v00001;
  const Scalar v00035 = static_cast<Scalar>(1) / v00034;
  const Scalar v00059 = std::sin(v00058);
  const Scalar v05095 = v00064 * (static_cast<Scalar>(1) / v00967);
  const Scalar v00096 = static_cast<Scalar>(1) / (v00034 * v00034 * v00034);
  const Scalar v04785 = v00031 * v00043;
  const Scalar v02989 = v00035 * v02874;
  const Scalar v00989 = v00010 * v00962 + v00004 * v00952 + v00001 * v00957;
  const Scalar v05019 = v00059 * (static_cast<Scalar>(1) / (v00054 * v00054 * v00054));
  const Scalar v02917 = (static_cast<Scalar>(1) / v00054) * v00059;
  const Scalar v02205 = v05704 + -v08933;
  const Scalar v05954 = v00096 * v04785;
  const Scalar v00977 = v00957 * v08947 + v08933;
  const Scalar v08953 = -v00043;
  const Scalar v04786 = v00031 * v00096;
  const Scalar v02236 = v05498 + -v08934;
  const Scalar v00983 = v00962 * v08946 + v08934;
  const Scalar v02154 = v05421 + -v08932;
  const Scalar v00971 = v00952 * v08945 + v08932;
  const Scalar v04850 = v00989 * v02989;
  const Scalar v02187 = v00083 * v05095 + v05019;
  const Scalar v00142 = static_cast<Scalar>(-0.25);
  const Scalar v04531 = static_cast<Scalar>(4) * (v02917 * v02989);
  const Scalar v08944 = -static_cast<Scalar>(2);
  const Scalar v05703 = v00010 * v00064;
  const Scalar v05420 = v00001 * v00064;
  const Scalar v04536 = static_cast<Scalar>(2) * v00064;
  const Scalar v05497 = v00004 * v00064;
  const Scalar v04339 = v00037 * v03527;
  const Scalar v02468 = v02205 * v05019 + (v00083 * v05704 + v00056 * v08933) * v05095;
  const Scalar v02200 = v00977 * v05954 + v00037 * v02205;
  const Scalar v03544 = v00043 * v00142;
  const Scalar v02477 = v02236 * v05019 + (v00083 * v05498 + v00056 * v08934) * v05095;
  const Scalar v03311 = static_cast<Scalar>(2) * v02917;
  const Scalar v02231 = v00037 * v02236 + v00983 * v05954;
  const Scalar v02450 = v02154 * v05019 + (v00083 * v05421 + v00056 * v08932) * v05095;
  const Scalar v02149 = v00037 * v02154 + v00971 * v05954;
  const Scalar v03167 = static_cast<Scalar>(2) * v02870;
  const Scalar v04640 =
      (v02107 * v02870) *
      (static_cast<Scalar>(8) * ((static_cast<Scalar>(1) / (v00033 * v00033)) * v04785 + -v00096));
  const Scalar v04548 = static_cast<Scalar>(2) * v04339;
  const Scalar v04389 = v02468 * v02874;
  const Scalar v04355 = static_cast<Scalar>(2) * v02200;
  const Scalar v04752 = v00004 * v03544;
  const Scalar v04553 = v00989 * (v00037 + v04786 * v08953);
  const Scalar v02935 = v00035 * v00043;
  const Scalar v04398 = v02477 * v02874;
  const Scalar v08955 = -v03311;
  const Scalar v04356 = static_cast<Scalar>(2) * v02231;
  const Scalar v04747 = v00001 * v03544;
  const Scalar v04383 = v02450 * v02874;
  const Scalar v04354 = static_cast<Scalar>(2) * v02149;
  const Scalar v04959 = v00010 * v03544;
  const Scalar v03388 = v02870 * v02917;
  const Scalar v04899 = (v00013 * v00142 * v02917 + v02187 * v04850) * v02874;
  const Scalar v04922 = v02917 * v03167;
  const Scalar v01061 = v05703 * v08944 + v02154 * v04531;
  const Scalar v01520 = v05420 * v08944 + v02236 * v04531;
  const Scalar v00997 = v00013 * v04536 + v04531 * -v00989;
  const Scalar v01559 = v00004 * v04536 + v00977 * v04531;
  const Scalar v01526 = v00010 * v04536 + v00971 * v04531;
  const Scalar v01121 = v05497 * v08944 + v02205 * v04531;
  const Scalar v01091 = v00001 * v04536 + v00983 * v04531;
  if (static_cast<bool>(_d0)) {
    Scalar v00090;
    Scalar v00224;
    Scalar v00307;
    Scalar v00387;
    if (v00030) {
      v00090 = static_cast<Scalar>(0);
      v00224 = static_cast<Scalar>(0);
      v00307 = static_cast<Scalar>(0);
      v00387 = static_cast<Scalar>(0);
    } else {
      v00090 = v00005 * v00027;
      v00224 = v00011 * v00027;
      v00307 = v00014 * v00027;
      v00387 = v00008 * v00027;
    }
    const Scalar v08948 = -v00013;
    const Scalar v08924 = v00953 + v00957;
    const Scalar v08920 = v00948 + v00952;
    const Scalar v08926 = v00954 + v00957;
    const Scalar v08930 = v00959 + v00962;
    const Scalar v08922 = v00949 + v00952;
    const Scalar v08928 = v00958 + v00962;
    const Scalar v02682 =
        (v00014 * v00962 + -(v00008 * v00952 + v00005 * v00957)) * v04548 + v00224 * v04640;
    const Scalar v02769 =
        (v00011 * v00952 + -(v00014 * v00957 + v00005 * v00962)) * v04548 + v00387 * v04640;
    const Scalar v02625 =
        (v00008 * v00962 + v00014 * v00952 + v00011 * v00957) * v04548 + v00090 * v04640;
    const Scalar v02727 =
        (v00008 * v00957 + -(v00011 * v00962 + v00005 * v00952)) * v04548 + v00307 * v04640;
    const Scalar v02309 = (v02682 * v04752 + v00224 * v04355) * v03388 +
                          ((v00008 * v08948 + v07558 + v08928) * v03311 + v02682 * v04389) * v02989;
    const Scalar v02699 =
        (((v00954 + v07585) + -v08924) * v02935 + v00224 * v04553) * v04922 + v02682 * v04899;
    const Scalar v02319 = v00064 + (v02682 * v04747 + v00224 * v04356) * v03388 +
                          ((v00021 + v08911) * v08955 + v02682 * v04398) * v02989;
    const Scalar v02275 = (v02682 * v04959 + v00224 * v04354) * v03388 +
                          (((v00949 + v07781) + -v08920) * v03311 + v02682 * v04383) * v02989;
    const Scalar v02423 = (v02769 * v04752 + v00387 * v04355) * v03388 +
                          (((v00953 + v07780) + -v08926) * v03311 + v02769 * v04389) * v02989;
    const Scalar v02783 =
        (((v00958 + v07558) + -v08930) * v02935 + v00387 * v04553) * v04922 + v02769 * v04899;
    const Scalar v02433 = (v02769 * v04747 + v00387 * v04356) * v03388 +
                          ((v00014 * v08948 + v07755 + v08920) * v03311 + v02769 * v04398) * v02989;
    const Scalar v02396 = v00064 + (v02769 * v04959 + v00387 * v04354) * v03388 +
                          ((v00021 + (v00019 + v00020)) * v08955 + v02769 * v04383) * v02989;
    const Scalar v02220 = (v02625 * v04752 + v00090 * v04355) * v03388 +
                          ((v00011 * v08947 + v07781 + v08922) * v03311 + v02625 * v04389) * v02989;
    const Scalar v02644 = v00064 +
                          ((v00035 * (v00020 + v08911) + v04786 * (v00090 * v00989)) * v08953 +
                           v00090 * (v00037 * v00989)) *
                              v04922 +
                          v02625 * v04899;
    const Scalar v02251 = (v02625 * v04747 + v00090 * v04356) * v03388 +
                          ((v00008 * v08946 + v07780 + v08924) * v03311 + v02625 * v04398) * v02989;
    const Scalar v02169 = (v02625 * v04959 + v00090 * v04354) * v03388 +
                          ((v00014 * v08945 + v07754 + v08930) * v03311 + v02625 * v04383) * v02989;
    const Scalar v02362 = v00064 + (v02727 * v04752 + v00307 * v04355) * v03388 +
                          ((v00021 + (v00018 + v00020)) * v08955 + v02727 * v04389) * v02989;
    const Scalar v02741 =
        (((v00948 + v07755) + -v08922) * v02935 + v00307 * v04553) * v04922 + v02727 * v04899;
    const Scalar v02376 = (v02727 * v04747 + v00307 * v04356) * v03388 +
                          (((v00959 + v07754) + -v08928) * v03311 + v02727 * v04398) * v02989;
    const Scalar v02339 = (v02727 * v04959 + v00307 * v04354) * v03388 +
                          ((v00011 * v08948 + v07585 + v08926) * v03311 + v02727 * v04383) * v02989;
    const Scalar v00534 = v01559 * v02275 + v00997 * v02319 + v01520 * v02699 + v01061 * v02309;
    const Scalar v00546 = v01559 * v02396 + v00997 * v02433 + v01520 * v02783 + v01061 * v02423;
    const Scalar v00528 = v01559 * v02169 + v00997 * v02251 + v01520 * v02644 + v01061 * v02220;
    const Scalar v00540 = v01559 * v02339 + v00997 * v02376 + v01520 * v02741 + v01061 * v02362;
    const Scalar v00494 = v00997 * v02309 + v01520 * v02275 + v01121 * v02699 + v01526 * v02319;
    const Scalar v00506 = v00997 * v02423 + v01520 * v02396 + v01121 * v02783 + v01526 * v02433;
    const Scalar v00488 = v00997 * v02220 + v01520 * v02169 + v01121 * v02644 + v01526 * v02251;
    const Scalar v00500 = v00997 * v02362 + v01520 * v02339 + v01121 * v02741 + v01526 * v02376;
    const Scalar v00304 = v00997 * v02275 + v01061 * v02699 + v01091 * v02309 + v01121 * v02319;
    const Scalar v00461 = v00997 * v02396 + v01061 * v02783 + v01091 * v02423 + v01121 * v02433;
    const Scalar v00220 = v00997 * v02169 + v01061 * v02644 + v01091 * v02220 + v01121 * v02251;
    const Scalar v00384 = v00997 * v02339 + v01061 * v02741 + v01091 * v02362 + v01121 * v02376;
    _d0(0, 0) =
        v00083 * (v00010 * v00220 + v00004 * v00304) + v00056 * (v00001 * v00384 + v00013 * v00461);
    _d0(0, 1) =
        v00083 * (v00004 * v00220 + v00001 * v00461) + v00056 * (v00010 * v00304 + v00013 * v00384);
    _d0(0, 2) =
        v00083 * (v00010 * v00384 + v00001 * v00220) + v00056 * (v00004 * v00461 + v00013 * v00304);
    _d0(1, 0) =
        v00083 * (v00010 * v00488 + v00004 * v00494) + v00056 * (v00001 * v00500 + v00013 * v00506);
    _d0(1, 1) =
        v00083 * (v00004 * v00488 + v00001 * v00506) + v00056 * (v00010 * v00494 + v00013 * v00500);
    _d0(1, 2) =
        v00083 * (v00010 * v00500 + v00001 * v00488) + v00056 * (v00004 * v00506 + v00013 * v00494);
    _d0(2, 0) =
        v00083 * (v00010 * v00528 + v00004 * v00534) + v00056 * (v00001 * v00540 + v00013 * v00546);
    _d0(2, 1) =
        v00083 * (v00004 * v00528 + v00001 * v00546) + v00056 * (v00010 * v00534 + v00013 * v00540);
    _d0(2, 2) =
        v00083 * (v00010 * v00540 + v00001 * v00528) + v00056 * (v00004 * v00546 + v00013 * v00534);
  }
  if (static_cast<bool>(_d1)) {
    Scalar v00562;
    Scalar v00642;
    Scalar v00719;
    Scalar v00793;
    if (v00030) {
      v00562 = static_cast<Scalar>(0);
      v00642 = static_cast<Scalar>(0);
      v00719 = static_cast<Scalar>(0);
      v00793 = static_cast<Scalar>(0);
    } else {
      v00562 = v00013 * v00027;
      v00642 = v00001 * v00027;
      v00719 = v00004 * v00027;
      v00793 = v00010 * v00027;
    }
    const Scalar v02820 = v00983 * v04548 + v00642 * v04640;
    const Scalar v05889 = v00035 * v08944;
    const Scalar v01635 = v00004 * v00004;
    const Scalar v01634 = v00010 * v00010;
    const Scalar v02856 = v00971 * v04548 + v00793 * v04640;
    const Scalar v01636 = v00001 * v00001;
    const Scalar v02806 = v00989 * v04339 * v08944 + v00562 * v04640;
    const Scalar v02838 = v00977 * v04548 + v00719 * v04640;
    const Scalar v08935 = v01634 + v01635;
    const Scalar v01783 = v00013 * v00013;
    const Scalar v05559 = v00004 * v02874;
    const Scalar v02823 = v00001 * v05889 + v00142 * v02820;
    const Scalar v06095 = v00642 * v03167;
    const Scalar v05863 = v00013 * v02874;
    const Scalar v05793 = v00010 * v02874;
    const Scalar v06170 = v00793 * v03167;
    const Scalar v02859 = v00010 * v05889 + v00142 * v02856;
    const Scalar v05477 = v00001 * v02874;
    const Scalar v02809 = v00013 * v05889 + v00142 * v02806;
    const Scalar v06035 = v00562 * v03167;
    const Scalar v06139 = v00719 * v03167;
    const Scalar v02841 = v00004 * v05889 + v00142 * v02838;
    const Scalar v03770 = v02874 * v02989;
    const Scalar v06709 = v02468 * v03770;
    const Scalar v05122 = v00989 * v02187;
    const Scalar v06689 = v02450 * v03770;
    const Scalar v06724 = v02477 * v03770;
    const Scalar v02516 = (v02200 * v06095 + v02823 * v05559) * v02917 + v02820 * v06709;
    const Scalar v02507 = (v02823 * v05863 + v04553 * v06095) * v02917 + v05122 * (v02820 * v03770);
    const Scalar v02526 = (v02820 * v04747 + v00642 * v04356) * v03388 +
                          ((v01783 + v08935) * v03311 + v02820 * v04398) * v02989;
    const Scalar v02498 = (v02823 * v05793 + v02149 * v06095) * v02917 + v02820 * v06689;
    const Scalar v02611 = (v02859 * v05559 + v02200 * v06170) * v02917 + v02856 * v06709;
    const Scalar v02602 = (v02859 * v05863 + v04553 * v06170) * v02917 + v05122 * (v02856 * v03770);
    const Scalar v02620 = (v02859 * v05477 + v02231 * v06170) * v02917 + v02856 * v06724;
    const Scalar v02593 = (v02856 * v04959 + v00793 * v04354) * v03388 +
                          ((v01783 + (v01635 + v01636)) * v03311 + v02856 * v04383) * v02989;
    const Scalar v02470 = (v02200 * v06035 + v02809 * v05559) * v02917 + v02806 * v06709;
    const Scalar v02815 = (v00562 * v04553 + (v01636 + v08935) * v02935) * v04922 + v02806 * v04899;
    const Scalar v02479 = (v02231 * v06035 + v02809 * v05477) * v02917 + v02806 * v06724;
    const Scalar v02452 = (v02809 * v05793 + v02149 * v06035) * v02917 + v02806 * v06689;
    const Scalar v02564 = (v02838 * v04752 + v00719 * v04355) * v03388 +
                          ((v01783 + (v01634 + v01636)) * v03311 + v02838 * v04389) * v02989;
    const Scalar v02554 = (v02841 * v05863 + v04553 * v06139) * v02917 + v05122 * (v02838 * v03770);
    const Scalar v02573 = (v02841 * v05477 + v02231 * v06139) * v02917 + v02838 * v06724;
    const Scalar v02545 = (v02841 * v05793 + v02149 * v06139) * v02917 + v02838 * v06689;
    const Scalar v00922 = v01559 * v02498 + v00997 * v02526 + v01520 * v02507 + v01061 * v02516;
    const Scalar v00934 = v01559 * v02593 + v00997 * v02620 + v01520 * v02602 + v01061 * v02611;
    const Scalar v00916 = v01559 * v02452 + v00997 * v02479 + v01520 * v02815 + v01061 * v02470;
    const Scalar v00928 = v01559 * v02545 + v00997 * v02573 + v01520 * v02554 + v01061 * v02564;
    const Scalar v00887 = v00997 * v02516 + v01520 * v02498 + v01121 * v02507 + v01526 * v02526;
    const Scalar v00899 = v00997 * v02611 + v01520 * v02593 + v01121 * v02602 + v01526 * v02620;
    const Scalar v00881 = v00997 * v02470 + v01520 * v02452 + v01121 * v02815 + v01526 * v02479;
    const Scalar v00893 = v00997 * v02564 + v01520 * v02545 + v01121 * v02554 + v01526 * v02573;
    const Scalar v00715 = v00997 * v02498 + v01061 * v02507 + v01091 * v02516 + v01121 * v02526;
    const Scalar v00864 = v00997 * v02593 + v01061 * v02602 + v01091 * v02611 + v01121 * v02620;
    const Scalar v00638 = v00997 * v02452 + v01061 * v02815 + v01091 * v02470 + v01121 * v02479;
    const Scalar v00790 = v00997 * v02545 + v01061 * v02554 + v01091 * v02564 + v01121 * v02573;
    _d1(0, 0) =
        v00083 * (v00008 * v00638 + v00014 * v00715) + v00056 * (v00011 * v00790 + v00005 * v00864);
    _d1(0, 1) =
        v00083 * (v00014 * v00638 + v00011 * v00864) + v00056 * (v00008 * v00715 + v00005 * v00790);
    _d1(0, 2) =
        v00083 * (v00008 * v00790 + v00011 * v00638) + v00056 * (v00014 * v00864 + v00005 * v00715);
    _d1(1, 0) =
        v00083 * (v00008 * v00881 + v00014 * v00887) + v00056 * (v00011 * v00893 + v00005 * v00899);
    _d1(1, 1) =
        v00083 * (v00014 * v00881 + v00011 * v00899) + v00056 * (v00008 * v00887 + v00005 * v00893);
    _d1(1, 2) =
        v00083 * (v00008 * v00893 + v00011 * v00881) + v00056 * (v00014 * v00899 + v00005 * v00887);
    _d1(2, 0) =
        v00083 * (v00008 * v00916 + v00014 * v00922) + v00056 * (v00011 * v00928 + v00005 * v00934);
    _d1(2, 1) =
        v00083 * (v00014 * v00916 + v00011 * v00934) + v00056 * (v00008 * v00922 + v00005 * v00928);
    _d1(2, 2) =
        v00083 * (v00008 * v00928 + v00011 * v00916) + v00056 * (v00014 * v00934 + v00005 * v00922);
  }
  const Scalar v05414 = v02989 * v03311;
  _q_out(0, 0) = v00971 * v05414 + v05703;
  _q_out(1, 0) = v00977 * v05414 + v05497;
  _q_out(2, 0) = v00983 * v05414 + v05420;
  _q_out(3, 0) = v04850 * v08955 + v00013 * v00064;
}

}  // namespace gen
