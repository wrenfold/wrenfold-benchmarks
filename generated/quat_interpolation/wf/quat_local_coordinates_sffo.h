// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates_sffo(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0, T4&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _out = wf::make_output_span<3, 1>(out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 40
  // branch: 6
  // call: 4
  // compare: 4
  // divide: 3
  // multiply: 90
  // negate: 6
  // total: 153

  const Scalar v0012 = _q1_xyzw(3, 0);
  const Scalar v0011 = _q0_xyzw(3, 0);
  const Scalar v0009 = _q1_xyzw(2, 0);
  const Scalar v0008 = _q0_xyzw(2, 0);
  const Scalar v0006 = _q1_xyzw(1, 0);
  const Scalar v0005 = _q0_xyzw(1, 0);
  const Scalar v0003 = _q1_xyzw(0, 0);
  const Scalar v0002 = _q0_xyzw(0, 0);
  const Scalar v0014 = v0002 * v0003 + v0005 * v0006 + v0008 * v0009 + v0011 * v0012;
  const std::int64_t v0015 = (static_cast<Scalar>(0) < v0014) - (v0014 < static_cast<Scalar>(0));
  std::int64_t v0018;
  if (v0015 < 0) {
    v0018 = v0015;
  } else {
    v0018 = 0;
  }
  const Scalar v0028 = std::abs(v0014);
  Scalar v0031;
  if (v0028 < static_cast<Scalar>(0.9999999999999999)) {
    v0031 = v0028;
  } else {
    v0031 = static_cast<Scalar>(0.9999999999999999);
  }
  const Scalar v0063 = static_cast<Scalar>(0.9999999999999999) + -v0028;
  const Scalar v0057 = static_cast<Scalar>(0.5);
  Scalar v0068;
  if (static_cast<Scalar>(0) < v0063) {
    v0068 = static_cast<Scalar>(1);
  } else {
    if (v0063 < static_cast<Scalar>(0)) {
      v0068 = static_cast<Scalar>(-1);
    } else {
      v0068 = v0057;
    }
  }
  const Scalar v0034 = static_cast<Scalar>(1) + -(v0031 * v0031);
  const Scalar v0035 = std::sqrt(v0034);
  const Scalar v0037 = std::acos(v0031);
  const Scalar v0185 = v0002 * v0006 + v0008 * v0012;
  const Scalar v0180 = v0005 * v0012 + v0003 * v0008;
  const Scalar v0175 = v0002 * v0012 + v0005 * v0009;
  const Scalar v0740 = v0006 * v0008 + v0003 * v0011;
  const Scalar v0054 = static_cast<Scalar>(-0.5);
  const Scalar v0741 = v0002 * v0009 + v0006 * v0011;
  const Scalar v0742 = v0003 * v0005 + v0009 * v0011;
  const Scalar v0421 = (v0031 * v0037 * (static_cast<Scalar>(1) / (v0035 * v0035 * v0035)) +
                        -(static_cast<Scalar>(1) / v0034)) *
                       (v0068 * static_cast<Scalar>(v0015));
  const Scalar v0187 = v0742 + -v0185;
  const Scalar v0427 = (static_cast<Scalar>(1) / v0035) * v0037;
  const Scalar v0182 = v0741 + -v0180;
  const Scalar v0177 = v0740 + -v0175;
  const Scalar v0196 = v0054 * v0175 + v0057 * v0740;
  const Scalar v0277 = v0054 * v0741 + v0057 * v0180;
  const Scalar v0263 = v0054 * v0740 + v0057 * v0175;
  const Scalar v0239 = v0054 * v0185 + v0057 * v0742;
  const Scalar v0216 = v0054 * v0180 + v0057 * v0741;
  const Scalar v0225 = v0054 * v0742 + v0057 * v0185;
  const Scalar v0468 = v0187 * v0421;
  const Scalar v0688 = v0014 * v0427;
  const Scalar v0464 = v0182 * v0421;
  const Scalar v0454 = v0177 * v0421;
  const Scalar v0372 = v0196 * v0427;
  const Scalar v0368 = v0277 * v0427;
  const Scalar v0364 = v0263 * v0427;
  const Scalar v0356 = v0239 * v0427;
  const Scalar v0352 = v0216 * v0427;
  const Scalar v0348 = v0225 * v0427;
  const Scalar v0416 = static_cast<Scalar>(2) * static_cast<Scalar>(1 + 2 * v0018);
  if (static_cast<bool>(_d0)) {
    const Scalar v0344 = v0054 * v0688;
    _d0(0, 0) = (v0344 + v0196 * v0454) * v0416;
    _d0(0, 1) = (v0348 + v0216 * v0454) * v0416;
    _d0(0, 2) = (v0352 + v0239 * v0454) * v0416;
    _d0(1, 0) = (v0356 + v0196 * v0464) * v0416;
    _d0(1, 1) = (v0344 + v0216 * v0464) * v0416;
    _d0(1, 2) = (v0364 + v0239 * v0464) * v0416;
    _d0(2, 0) = (v0368 + v0196 * v0468) * v0416;
    _d0(2, 1) = (v0372 + v0216 * v0468) * v0416;
    _d0(2, 2) = (v0344 + v0239 * v0468) * v0416;
  }
  if (static_cast<bool>(_d1)) {
    const Scalar v0380 = v0057 * v0688;
    _d1(0, 0) = (v0380 + v0263 * v0454) * v0416;
    _d1(0, 1) = (v0348 + v0277 * v0454) * v0416;
    _d1(0, 2) = (v0352 + v0225 * v0454) * v0416;
    _d1(1, 0) = (v0356 + v0263 * v0464) * v0416;
    _d1(1, 1) = (v0380 + v0277 * v0464) * v0416;
    _d1(1, 2) = (v0364 + v0225 * v0464) * v0416;
    _d1(2, 0) = (v0368 + v0263 * v0468) * v0416;
    _d1(2, 1) = (v0372 + v0277 * v0468) * v0416;
    _d1(2, 2) = (v0380 + v0225 * v0468) * v0416;
  }
  const Scalar v0678 = v0416 * v0427;
  _out(0, 0) = v0177 * v0678;
  _out(1, 0) = v0182 * v0678;
  _out(2, 0) = v0187 * v0678;
}

}  // namespace gen
