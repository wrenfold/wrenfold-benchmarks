// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0, T4&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _out = wf::make_output_span<3, 1>(out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 92
  // branch: 9
  // call: 2
  // compare: 3
  // divide: 3
  // multiply: 209
  // negate: 6
  // total: 324

  const Scalar v0011 = _q0_xyzw(3, 0);
  const Scalar v0002 = _q1_xyzw(3, 0);
  const Scalar v0008 = _q0_xyzw(2, 0);
  const Scalar v0006 = _q1_xyzw(2, 0);
  const Scalar v0009 = _q1_xyzw(1, 0);
  const Scalar v0005 = _q0_xyzw(1, 0);
  const Scalar v0012 = _q1_xyzw(0, 0);
  const Scalar v0001 = _q0_xyzw(0, 0);
  const Scalar v0021 = v0001 * v0012 + v0005 * v0009 + v0006 * v0008 + v0002 * v0011;
  std::int64_t v0025;
  if (v0021 < static_cast<Scalar>(0)) {
    v0025 = -1;
  } else {
    v0025 = 1;
  }
  const Scalar v0026 = static_cast<Scalar>(v0025);
  const Scalar v0027 = v0021 * v0026;
  const bool v0029 = static_cast<Scalar>(1) < v0027;
  Scalar v0030;
  if (v0029) {
    v0030 = static_cast<Scalar>(1);
  } else {
    v0030 = v0027;
  }
  const Scalar v0032 = static_cast<Scalar>(1) + -(v0030 * v0030);
  const Scalar v0033 = std::sqrt(v0032);
  const Scalar v0037 = std::acos(v0030);
  const bool v0034 = static_cast<Scalar>(1e-16) < v0033;
  Scalar v0040;
  if (v0034) {
    v0040 = (static_cast<Scalar>(1) / v0033) * v0037 * static_cast<Scalar>(2);
  } else {
    v0040 = static_cast<Scalar>(2);
  }
  const Scalar v0785 =
      static_cast<Scalar>(2) * (v0030 * v0037 * (static_cast<Scalar>(1) / (v0033 * v0033 * v0033)) +
                                -(static_cast<Scalar>(1) / v0032));
  const Scalar v0278 = v0005 * v0012 + v0006 * v0011 + -(v0001 * v0009 + v0002 * v0008);
  const Scalar v0800 = -v0040;
  const Scalar v0273 = v0001 * v0006 + v0009 * v0011 + -(v0002 * v0005 + v0008 * v0012);
  const Scalar v0268 = v0008 * v0009 + v0011 * v0012 + -(v0001 * v0002 + v0005 * v0006);
  const Scalar v0081 = static_cast<Scalar>(0.5);
  const Scalar v0055 = static_cast<Scalar>(-0.5);
  if (static_cast<bool>(_d0)) {
    Scalar v0067;
    Scalar v0077;
    Scalar v0088;
    Scalar v0098;
    if (v0034) {
      Scalar v0059;
      Scalar v0073;
      Scalar v0084;
      Scalar v0094;
      if (v0029) {
        v0059 = static_cast<Scalar>(0);
        v0073 = static_cast<Scalar>(0);
        v0084 = static_cast<Scalar>(0);
        v0094 = static_cast<Scalar>(0);
      } else {
        v0059 = v0002 * v0026;
        v0073 = v0006 * v0026;
        v0084 = v0009 * v0026;
        v0094 = v0012 * v0026;
      }
      v0067 = v0059 * v0785;
      v0077 = v0073 * v0785;
      v0088 = v0084 * v0785;
      v0098 = v0094 * v0785;
    } else {
      v0067 = static_cast<Scalar>(0);
      v0077 = static_cast<Scalar>(0);
      v0088 = static_cast<Scalar>(0);
      v0098 = static_cast<Scalar>(0);
    }
    const Scalar v0307 = v0002 * v0800;
    const Scalar v0790 = v0006 * v0040;
    const Scalar v0793 = v0012 * v0040;
    const Scalar v0792 = v0009 * v0040;
    const Scalar v0387 = v0307 + v0077 * v0278;
    const Scalar v0395 = v0009 * v0800 + v0098 * v0278;
    const Scalar v0383 = v0067 * v0278 + v0790;
    const Scalar v0391 = v0088 * v0278 + v0793;
    const Scalar v0344 = v0012 * v0800 + v0077 * v0273;
    const Scalar v0352 = v0098 * v0273 + v0790;
    const Scalar v0340 = v0067 * v0273 + v0792;
    const Scalar v0348 = v0307 + v0088 * v0273;
    const Scalar v0293 = v0077 * v0268 + v0792;
    const Scalar v0309 = v0307 + v0098 * v0268;
    const Scalar v0285 = v0067 * v0268 + v0793;
    const Scalar v0301 = v0006 * v0800 + v0088 * v0268;
    _d0(0, 0) =
        v0026 * (v0055 * (v0001 * v0285 + v0005 * v0293) + v0081 * (v0008 * v0301 + v0011 * v0309));
    _d0(0, 1) =
        v0026 * (v0055 * (v0005 * v0285 + v0008 * v0309) + v0081 * (v0001 * v0293 + v0011 * v0301));
    _d0(0, 2) =
        v0026 * (v0055 * (v0001 * v0301 + v0008 * v0285) + v0081 * (v0005 * v0309 + v0011 * v0293));
    _d0(1, 0) =
        v0026 * (v0055 * (v0001 * v0340 + v0005 * v0344) + v0081 * (v0008 * v0348 + v0011 * v0352));
    _d0(1, 1) =
        v0026 * (v0055 * (v0005 * v0340 + v0008 * v0352) + v0081 * (v0001 * v0344 + v0011 * v0348));
    _d0(1, 2) =
        v0026 * (v0055 * (v0001 * v0348 + v0008 * v0340) + v0081 * (v0005 * v0352 + v0011 * v0344));
    _d0(2, 0) =
        v0026 * (v0055 * (v0001 * v0383 + v0005 * v0387) + v0081 * (v0008 * v0391 + v0011 * v0395));
    _d0(2, 1) =
        v0026 * (v0055 * (v0005 * v0383 + v0008 * v0395) + v0081 * (v0001 * v0387 + v0011 * v0391));
    _d0(2, 2) =
        v0026 * (v0055 * (v0001 * v0391 + v0008 * v0383) + v0081 * (v0005 * v0395 + v0011 * v0387));
  }
  if (static_cast<bool>(_d1)) {
    Scalar v0169;
    Scalar v0179;
    Scalar v0189;
    Scalar v0199;
    if (v0034) {
      Scalar v0165;
      Scalar v0175;
      Scalar v0185;
      Scalar v0195;
      if (v0029) {
        v0165 = static_cast<Scalar>(0);
        v0175 = static_cast<Scalar>(0);
        v0185 = static_cast<Scalar>(0);
        v0195 = static_cast<Scalar>(0);
      } else {
        v0165 = v0011 * v0026;
        v0175 = v0008 * v0026;
        v0185 = v0005 * v0026;
        v0195 = v0001 * v0026;
      }
      v0169 = v0165 * v0785;
      v0179 = v0175 * v0785;
      v0189 = v0185 * v0785;
      v0199 = v0195 * v0785;
    } else {
      v0169 = static_cast<Scalar>(0);
      v0179 = static_cast<Scalar>(0);
      v0189 = static_cast<Scalar>(0);
      v0199 = static_cast<Scalar>(0);
    }
    const Scalar v0452 = v0011 * v0040;
    const Scalar v0495 = v0008 * v0800;
    const Scalar v0428 = v0001 * v0800;
    const Scalar v0436 = v0005 * v0800;
    const Scalar v0532 = v0452 + v0179 * v0278;
    const Scalar v0540 = v0199 * v0278 + v0005 * v0040;
    const Scalar v0528 = v0495 + v0169 * v0278;
    const Scalar v0536 = v0428 + v0189 * v0278;
    const Scalar v0489 = v0179 * v0273 + v0001 * v0040;
    const Scalar v0497 = v0495 + v0199 * v0273;
    const Scalar v0485 = v0436 + v0169 * v0273;
    const Scalar v0493 = v0452 + v0189 * v0273;
    const Scalar v0438 = v0436 + v0179 * v0268;
    const Scalar v0454 = v0452 + v0199 * v0268;
    const Scalar v0430 = v0428 + v0169 * v0268;
    const Scalar v0446 = v0189 * v0268 + v0008 * v0040;
    _d1(0, 0) =
        v0026 * (v0055 * (v0012 * v0430 + v0009 * v0438) + v0081 * (v0006 * v0446 + v0002 * v0454));
    _d1(0, 1) =
        v0026 * (v0055 * (v0009 * v0430 + v0006 * v0454) + v0081 * (v0012 * v0438 + v0002 * v0446));
    _d1(0, 2) =
        v0026 * (v0055 * (v0012 * v0446 + v0006 * v0430) + v0081 * (v0009 * v0454 + v0002 * v0438));
    _d1(1, 0) =
        v0026 * (v0055 * (v0012 * v0485 + v0009 * v0489) + v0081 * (v0006 * v0493 + v0002 * v0497));
    _d1(1, 1) =
        v0026 * (v0055 * (v0009 * v0485 + v0006 * v0497) + v0081 * (v0012 * v0489 + v0002 * v0493));
    _d1(1, 2) =
        v0026 * (v0055 * (v0012 * v0493 + v0006 * v0485) + v0081 * (v0009 * v0497 + v0002 * v0489));
    _d1(2, 0) =
        v0026 * (v0055 * (v0012 * v0528 + v0009 * v0532) + v0081 * (v0006 * v0536 + v0002 * v0540));
    _d1(2, 1) =
        v0026 * (v0055 * (v0009 * v0528 + v0006 * v0540) + v0081 * (v0012 * v0532 + v0002 * v0536));
    _d1(2, 2) =
        v0026 * (v0055 * (v0012 * v0536 + v0006 * v0528) + v0081 * (v0009 * v0540 + v0002 * v0532));
  }
  const Scalar v0787 = v0026 * v0040;
  _out(0, 0) = v0268 * v0787;
  _out(1, 0) = v0273 * v0787;
  _out(2, 0) = v0278 * v0787;
}

}  // namespace gen
