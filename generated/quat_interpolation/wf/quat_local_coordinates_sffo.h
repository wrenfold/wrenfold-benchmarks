// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates_sffo(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0, T4&& d1)
{
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
  
  const Scalar v0006 = _q1_xyzw(1, 0);
  const Scalar v0005 = _q0_xyzw(1, 0);
  const Scalar v0003 = _q1_xyzw(0, 0);
  const Scalar v0002 = _q0_xyzw(0, 0);
  const Scalar v0007 = v0005 * v0006;
  const Scalar v0004 = v0002 * v0003;
  const Scalar v0009 = _q1_xyzw(2, 0);
  const Scalar v0008 = _q0_xyzw(2, 0);
  const Scalar v0729 = v0004 + v0007;
  const Scalar v0010 = v0008 * v0009;
  const Scalar v0012 = _q1_xyzw(3, 0);
  const Scalar v0011 = _q0_xyzw(3, 0);
  const Scalar v0730 = v0010 + v0729;
  const Scalar v0013 = v0011 * v0012;
  const Scalar v0731 = v0013 + v0730;
  const std::int64_t v0015 = (static_cast<Scalar>(0) < v0731) - (v0731 < static_cast<Scalar>(0));
  const bool v0017 = v0015 < 0;
  std::int64_t v0018;
  if (v0017) {
    v0018 = v0015;
  } else {
    v0018 = 0;
  }
  const Scalar v0028 = std::abs(v0731);
  const bool v0030 = v0028 < static_cast<Scalar>(0.9999999999999999);
  Scalar v0031;
  if (v0030) {
    v0031 = v0028;
  } else {
    v0031 = static_cast<Scalar>(0.9999999999999999);
  }
  const Scalar v0735 = -v0028;
  const Scalar v0063 = static_cast<Scalar>(0.9999999999999999) + v0735;
  const Scalar v0057 = static_cast<Scalar>(0.5);
  const bool v0065 = static_cast<Scalar>(0) < v0063;
  Scalar v0068;
  if (v0065) {
    v0068 = static_cast<Scalar>(1);
  } else {
    const bool v0066 = v0063 < static_cast<Scalar>(0);
    if (v0066) {
      v0068 = static_cast<Scalar>(-1);
    } else {
      v0068 = v0057;
    }
  }
  const Scalar v0736 = -v0031;
  const Scalar v0721 = v0031 * v0736;
  const Scalar v0034 = static_cast<Scalar>(1) + v0721;
  const Scalar v0035 = std::sqrt(v0034);
  const Scalar v0722 = v0035 * v0035;
  const Scalar v0037 = std::acos(v0031);
  const Scalar v0723 = v0035 * v0722;
  const Scalar v0061 = static_cast<Scalar>(1) / v0034;
  const Scalar v0724 = v0031 * v0037;
  const Scalar v0074 = static_cast<Scalar>(1) / v0723;
  const Scalar v0184 = v0008 * v0012;
  const Scalar v0183 = v0002 * v0006;
  const Scalar v0179 = v0003 * v0008;
  const Scalar v0178 = v0005 * v0012;
  const Scalar v0174 = v0005 * v0009;
  const Scalar v0173 = v0002 * v0012;
  const Scalar v0026 = v0003 * v0011;
  const Scalar v0025 = v0006 * v0008;
  const Scalar v0044 = v0006 * v0011;
  const Scalar v0043 = v0002 * v0009;
  const Scalar v0050 = v0009 * v0011;
  const Scalar v0049 = v0003 * v0005;
  const Scalar v0069 = static_cast<Scalar>(v0015);
  const Scalar v0737 = -v0061;
  const Scalar v0725 = v0074 * v0724;
  const Scalar v0185 = v0183 + v0184;
  const Scalar v0180 = v0178 + v0179;
  const Scalar v0175 = v0173 + v0174;
  const Scalar v0726 = v0025 + v0026;
  const Scalar v0054 = static_cast<Scalar>(-0.5);
  const Scalar v0727 = v0043 + v0044;
  const Scalar v0728 = v0049 + v0050;
  const std::int64_t v0019 = 2 * v0018;
  const Scalar v0417 = v0068 * v0069;
  const Scalar v0205 = v0725 + v0737;
  const Scalar v0734 = -v0185;
  const Scalar v0036 = static_cast<Scalar>(1) / v0035;
  const Scalar v0733 = -v0180;
  const Scalar v0732 = -v0175;
  const Scalar v0195 = v0057 * v0726;
  const Scalar v0191 = v0054 * v0175;
  const Scalar v0276 = v0057 * v0180;
  const Scalar v0272 = v0054 * v0727;
  const Scalar v0262 = v0057 * v0175;
  const Scalar v0258 = v0054 * v0726;
  const Scalar v0238 = v0057 * v0728;
  const Scalar v0234 = v0054 * v0185;
  const Scalar v0215 = v0057 * v0727;
  const Scalar v0211 = v0054 * v0180;
  const Scalar v0224 = v0057 * v0185;
  const Scalar v0220 = v0054 * v0728;
  const std::int64_t v0020 = 1 + v0019;
  const Scalar v0420 = v0205 * v0417;
  const Scalar v0187 = v0728 + v0734;
  const Scalar v0427 = v0036 * v0037;
  const Scalar v0182 = v0727 + v0733;
  const Scalar v0177 = v0726 + v0732;
  const Scalar v0196 = v0191 + v0195;
  const Scalar v0277 = v0272 + v0276;
  const Scalar v0263 = v0258 + v0262;
  const Scalar v0239 = v0234 + v0238;
  const Scalar v0216 = v0211 + v0215;
  const Scalar v0225 = v0220 + v0224;
  const Scalar v0039 = static_cast<Scalar>(v0020);
  const Scalar v0465 = v0187 * v0420;
  const Scalar v0673 = v0427 * v0731;
  const Scalar v0459 = v0182 * v0420;
  const Scalar v0447 = v0177 * v0420;
  const Scalar v0372 = v0196 * v0427;
  const Scalar v0368 = v0277 * v0427;
  const Scalar v0364 = v0263 * v0427;
  const Scalar v0356 = v0239 * v0427;
  const Scalar v0352 = v0216 * v0427;
  const Scalar v0348 = v0225 * v0427;
  const Scalar v0416 = static_cast<Scalar>(2) * v0039;
  if (static_cast<bool>(_d0)) {
    const Scalar v0377 = v0239 * v0465;
    const Scalar v0344 = v0054 * v0673;
    const Scalar v0373 = v0216 * v0465;
    const Scalar v0369 = v0196 * v0465;
    const Scalar v0365 = v0239 * v0459;
    const Scalar v0361 = v0216 * v0459;
    const Scalar v0357 = v0196 * v0459;
    const Scalar v0353 = v0239 * v0447;
    const Scalar v0349 = v0216 * v0447;
    const Scalar v0345 = v0196 * v0447;
    const Scalar v0378 = v0344 + v0377;
    const Scalar v0374 = v0372 + v0373;
    const Scalar v0370 = v0368 + v0369;
    const Scalar v0366 = v0364 + v0365;
    const Scalar v0362 = v0344 + v0361;
    const Scalar v0358 = v0356 + v0357;
    const Scalar v0354 = v0352 + v0353;
    const Scalar v0350 = v0348 + v0349;
    const Scalar v0346 = v0344 + v0345;
    const Scalar v0379 = v0378 * v0416;
    const Scalar v0375 = v0374 * v0416;
    const Scalar v0371 = v0370 * v0416;
    const Scalar v0367 = v0366 * v0416;
    const Scalar v0363 = v0362 * v0416;
    const Scalar v0359 = v0358 * v0416;
    const Scalar v0355 = v0354 * v0416;
    const Scalar v0351 = v0350 * v0416;
    const Scalar v0347 = v0346 * v0416;
    _d0(0, 0) = v0347;
    _d0(0, 1) = v0351;
    _d0(0, 2) = v0355;
    _d0(1, 0) = v0359;
    _d0(1, 1) = v0363;
    _d0(1, 2) = v0367;
    _d0(2, 0) = v0371;
    _d0(2, 1) = v0375;
    _d0(2, 2) = v0379;
  }
  if (static_cast<bool>(_d1)) {
    const Scalar v0413 = v0225 * v0465;
    const Scalar v0380 = v0057 * v0673;
    const Scalar v0409 = v0277 * v0465;
    const Scalar v0405 = v0263 * v0465;
    const Scalar v0401 = v0225 * v0459;
    const Scalar v0397 = v0277 * v0459;
    const Scalar v0393 = v0263 * v0459;
    const Scalar v0389 = v0225 * v0447;
    const Scalar v0385 = v0277 * v0447;
    const Scalar v0381 = v0263 * v0447;
    const Scalar v0414 = v0380 + v0413;
    const Scalar v0410 = v0372 + v0409;
    const Scalar v0406 = v0368 + v0405;
    const Scalar v0402 = v0364 + v0401;
    const Scalar v0398 = v0380 + v0397;
    const Scalar v0394 = v0356 + v0393;
    const Scalar v0390 = v0352 + v0389;
    const Scalar v0386 = v0348 + v0385;
    const Scalar v0382 = v0380 + v0381;
    const Scalar v0415 = v0414 * v0416;
    const Scalar v0411 = v0410 * v0416;
    const Scalar v0407 = v0406 * v0416;
    const Scalar v0403 = v0402 * v0416;
    const Scalar v0399 = v0398 * v0416;
    const Scalar v0395 = v0394 * v0416;
    const Scalar v0391 = v0390 * v0416;
    const Scalar v0387 = v0386 * v0416;
    const Scalar v0383 = v0382 * v0416;
    _d1(0, 0) = v0383;
    _d1(0, 1) = v0387;
    _d1(0, 2) = v0391;
    _d1(1, 0) = v0395;
    _d1(1, 1) = v0399;
    _d1(1, 2) = v0403;
    _d1(2, 0) = v0407;
    _d1(2, 1) = v0411;
    _d1(2, 2) = v0415;
  }
  const Scalar v0662 = v0416 * v0427;
  const Scalar v0052 = v0187 * v0662;
  const Scalar v0046 = v0182 * v0662;
  const Scalar v0040 = v0177 * v0662;
  _out(0, 0) = v0040;
  _out(1, 0) = v0046;
  _out(2, 0) = v0052;
}

} // namespace gen