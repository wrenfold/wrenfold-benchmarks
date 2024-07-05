// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates_no_conditional(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0,
                                           T4&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _out = wf::make_output_span<3, 1>(out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 92
  // branch: 6
  // call: 2
  // compare: 2
  // divide: 3
  // multiply: 187
  // negate: 6
  // total: 298

  const Scalar v00012 = _q0_xyzw(3, 0);
  const Scalar v00003 = _q1_xyzw(3, 0);
  const Scalar v00009 = _q0_xyzw(2, 0);
  const Scalar v00007 = _q1_xyzw(2, 0);
  const Scalar v00010 = _q1_xyzw(1, 0);
  const Scalar v00006 = _q0_xyzw(1, 0);
  const Scalar v00013 = _q1_xyzw(0, 0);
  const Scalar v00002 = _q0_xyzw(0, 0);
  const Scalar v00021 = v00002 * v00013 + v00006 * v00010 + v00007 * v00009 + v00003 * v00012;
  std::int64_t v00025;
  if (v00021 < static_cast<Scalar>(0)) {
    v00025 = -1;
  } else {
    v00025 = 1;
  }
  const Scalar v00026 = static_cast<Scalar>(v00025);
  const Scalar v00027 = v00021 * v00026;
  const bool v00029 = static_cast<Scalar>(1) < v00027;
  Scalar v00030;
  if (v00029) {
    v00030 = static_cast<Scalar>(1);
  } else {
    v00030 = v00027;
  }
  const Scalar v00032 = static_cast<Scalar>(1) + -(v00030 * v00030);
  const Scalar v00033 = std::sqrt(v00032);
  const Scalar v00035 = std::acos(v00030);
  const Scalar v00269 = v00030 * v00035 * (static_cast<Scalar>(1) / (v00033 * v00033 * v00033)) +
                        -(static_cast<Scalar>(1) / v00032);
  const Scalar v00266 = v00006 * v00013 + v00007 * v00012 + -(v00002 * v00010 + v00003 * v00009);
  const Scalar v00797 = (static_cast<Scalar>(1) / v00033) * v00035;
  const Scalar v00261 = v00002 * v00007 + v00010 * v00012 + -(v00003 * v00006 + v00009 * v00013);
  const Scalar v00256 = v00009 * v00010 + v00012 * v00013 + -(v00002 * v00003 + v00006 * v00007);
  const Scalar v00789 = v00026 * static_cast<Scalar>(2);
  const Scalar v00840 = v00266 * v00269;
  const Scalar v01033 = -v00797;
  const Scalar v00839 = v00261 * v00269;
  const Scalar v00838 = v00256 * v00269;
  const Scalar v00800 = static_cast<Scalar>(0.5) * v00789;
  const Scalar v00795 = (static_cast<Scalar>(-0.5)) * v00789;
  if (static_cast<bool>(_d0)) {
    Scalar v00054;
    Scalar v00065;
    Scalar v00074;
    Scalar v00081;
    if (v00029) {
      v00054 = static_cast<Scalar>(0);
      v00065 = static_cast<Scalar>(0);
      v00074 = static_cast<Scalar>(0);
      v00081 = static_cast<Scalar>(0);
    } else {
      v00054 = v00003 * v00026;
      v00065 = v00007 * v00026;
      v00074 = v00010 * v00026;
      v00081 = v00013 * v00026;
    }
    const Scalar v00561 = v00003 * v01033;
    const Scalar v00985 = v00007 * v00797;
    const Scalar v01010 = v00013 * v00797;
    const Scalar v01000 = v00010 * v00797;
    const Scalar v00587 = v00561 + v00065 * v00840;
    const Scalar v00595 = v00010 * v01033 + v00081 * v00840;
    const Scalar v00583 = v00054 * v00840 + v00985;
    const Scalar v00591 = v00074 * v00840 + v01010;
    const Scalar v00571 = v00013 * v01033 + v00065 * v00839;
    const Scalar v00579 = v00081 * v00839 + v00985;
    const Scalar v00567 = v00054 * v00839 + v01000;
    const Scalar v00575 = v00561 + v00074 * v00839;
    const Scalar v00555 = v00065 * v00838 + v01000;
    const Scalar v00563 = v00561 + v00081 * v00838;
    const Scalar v00551 = v00054 * v00838 + v01010;
    const Scalar v00559 = v00007 * v01033 + v00074 * v00838;
    _d0(0, 0) =
        (v00002 * v00551 + v00006 * v00555) * v00795 + (v00009 * v00559 + v00012 * v00563) * v00800;
    _d0(0, 1) =
        (v00006 * v00551 + v00009 * v00563) * v00795 + (v00002 * v00555 + v00012 * v00559) * v00800;
    _d0(0, 2) =
        (v00002 * v00559 + v00009 * v00551) * v00795 + (v00006 * v00563 + v00012 * v00555) * v00800;
    _d0(1, 0) =
        (v00002 * v00567 + v00006 * v00571) * v00795 + (v00009 * v00575 + v00012 * v00579) * v00800;
    _d0(1, 1) =
        (v00006 * v00567 + v00009 * v00579) * v00795 + (v00002 * v00571 + v00012 * v00575) * v00800;
    _d0(1, 2) =
        (v00002 * v00575 + v00009 * v00567) * v00795 + (v00006 * v00579 + v00012 * v00571) * v00800;
    _d0(2, 0) =
        (v00002 * v00583 + v00006 * v00587) * v00795 + (v00009 * v00591 + v00012 * v00595) * v00800;
    _d0(2, 1) =
        (v00006 * v00583 + v00009 * v00595) * v00795 + (v00002 * v00587 + v00012 * v00591) * v00800;
    _d0(2, 2) =
        (v00002 * v00591 + v00009 * v00583) * v00795 + (v00006 * v00595 + v00012 * v00587) * v00800;
  }
  if (static_cast<bool>(_d1)) {
    Scalar v00157;
    Scalar v00164;
    Scalar v00170;
    Scalar v00177;
    if (v00029) {
      v00157 = static_cast<Scalar>(0);
      v00164 = static_cast<Scalar>(0);
      v00170 = static_cast<Scalar>(0);
      v00177 = static_cast<Scalar>(0);
    } else {
      v00157 = v00012 * v00026;
      v00164 = v00009 * v00026;
      v00170 = v00006 * v00026;
      v00177 = v00002 * v00026;
    }
    const Scalar v00609 = v00012 * v00797;
    const Scalar v00625 = v00009 * v01033;
    const Scalar v00597 = v00002 * v01033;
    const Scalar v00601 = v00006 * v01033;
    const Scalar v00635 = v00609 + v00164 * v00840;
    const Scalar v00643 = v00177 * v00840 + v00006 * v00797;
    const Scalar v00631 = v00625 + v00157 * v00840;
    const Scalar v00639 = v00597 + v00170 * v00840;
    const Scalar v00619 = v00164 * v00839 + v00002 * v00797;
    const Scalar v00627 = v00625 + v00177 * v00839;
    const Scalar v00615 = v00601 + v00157 * v00839;
    const Scalar v00623 = v00609 + v00170 * v00839;
    const Scalar v00603 = v00601 + v00164 * v00838;
    const Scalar v00611 = v00609 + v00177 * v00838;
    const Scalar v00599 = v00597 + v00157 * v00838;
    const Scalar v00607 = v00170 * v00838 + v00009 * v00797;
    _d1(0, 0) =
        (v00013 * v00599 + v00010 * v00603) * v00795 + (v00007 * v00607 + v00003 * v00611) * v00800;
    _d1(0, 1) =
        (v00010 * v00599 + v00007 * v00611) * v00795 + (v00013 * v00603 + v00003 * v00607) * v00800;
    _d1(0, 2) =
        (v00013 * v00607 + v00007 * v00599) * v00795 + (v00010 * v00611 + v00003 * v00603) * v00800;
    _d1(1, 0) =
        (v00013 * v00615 + v00010 * v00619) * v00795 + (v00007 * v00623 + v00003 * v00627) * v00800;
    _d1(1, 1) =
        (v00010 * v00615 + v00007 * v00627) * v00795 + (v00013 * v00619 + v00003 * v00623) * v00800;
    _d1(1, 2) =
        (v00013 * v00623 + v00007 * v00615) * v00795 + (v00010 * v00627 + v00003 * v00619) * v00800;
    _d1(2, 0) =
        (v00013 * v00631 + v00010 * v00635) * v00795 + (v00007 * v00639 + v00003 * v00643) * v00800;
    _d1(2, 1) =
        (v00010 * v00631 + v00007 * v00643) * v00795 + (v00013 * v00635 + v00003 * v00639) * v00800;
    _d1(2, 2) =
        (v00013 * v00639 + v00007 * v00631) * v00795 + (v00010 * v00643 + v00003 * v00635) * v00800;
  }
  const Scalar v00960 = v00789 * v00797;
  _out(0, 0) = v00256 * v00960;
  _out(1, 0) = v00261 * v00960;
  _out(2, 0) = v00266 * v00960;
}

}  // namespace gen
