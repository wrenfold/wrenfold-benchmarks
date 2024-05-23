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
  // multiply: 94
  // negate: 3
  // total: 154

  const Scalar v0008 = _q0_xyzw(1, 0);
  const Scalar v0005 = _q1_xyzw(1, 0);
  const Scalar v0012 = _q0_xyzw(0, 0);
  const Scalar v0002 = _q1_xyzw(0, 0);
  const Scalar v0018 = v0005 * v0008;
  const Scalar v0017 = v0002 * v0012;
  const Scalar v0009 = _q1_xyzw(2, 0);
  const Scalar v0004 = _q0_xyzw(2, 0);
  const Scalar v0405 = v0017 + v0018;
  const Scalar v0019 = v0004 * v0009;
  const Scalar v0013 = _q1_xyzw(3, 0);
  const Scalar v0001 = _q0_xyzw(3, 0);
  const Scalar v0406 = v0019 + v0405;
  const Scalar v0020 = v0001 * v0013;
  const Scalar v0407 = v0020 + v0406;
  const std::int64_t v0022 = (static_cast<Scalar>(0) < v0407) - (v0407 < static_cast<Scalar>(0));
  const bool v0024 = v0022 < 0;
  std::int64_t v0025;
  if (v0024) {
    v0025 = v0022;
  } else {
    v0025 = 0;
  }
  const Scalar v0028 = std::abs(v0407);
  const bool v0030 = v0028 < static_cast<Scalar>(0.9999999999999999);
  Scalar v0031;
  if (v0030) {
    v0031 = v0028;
  } else {
    v0031 = static_cast<Scalar>(0.9999999999999999);
  }
  const Scalar v0409 = -v0028;
  const Scalar v0070 = static_cast<Scalar>(0.9999999999999999) + v0409;
  const Scalar v0059 = static_cast<Scalar>(0.5);
  const bool v0072 = static_cast<Scalar>(0) < v0070;
  Scalar v0075;
  if (v0072) {
    v0075 = static_cast<Scalar>(1);
  } else {
    const bool v0073 = v0070 < static_cast<Scalar>(0);
    if (v0073) {
      v0075 = static_cast<Scalar>(-1);
    } else {
      v0075 = v0059;
    }
  }
  const Scalar v0032 = v0031 * v0031;
  const Scalar v0408 = -v0032;
  const Scalar v0035 = static_cast<Scalar>(1) + v0408;
  const std::int64_t v0026 = 2 * v0025;
  const Scalar v0036 = std::sqrt(v0035);
  const Scalar v0182 = v0004 * v0013;
  const Scalar v0181 = v0005 * v0012;
  const std::int64_t v0027 = 1 + v0026;
  const Scalar v0176 = v0008 * v0013;
  const Scalar v0175 = v0002 * v0004;
  const Scalar v0170 = v0012 * v0013;
  const Scalar v0169 = v0008 * v0009;
  const Scalar v0066 = v0036 * v0036;
  const Scalar v0056 = static_cast<Scalar>(-0.5);
  const Scalar v0006 = v0004 * v0005;
  const Scalar v0003 = v0001 * v0002;
  const Scalar v0044 = v0009 * v0012;
  const Scalar v0043 = v0001 * v0005;
  const Scalar v0050 = v0001 * v0009;
  const Scalar v0048 = v0002 * v0008;
  const Scalar v0183 = v0181 + v0182;
  const Scalar v0168 = static_cast<Scalar>(-1);
  const Scalar v0076 = static_cast<Scalar>(v0022);
  const Scalar v0040 = static_cast<Scalar>(v0027);
  const Scalar v0177 = v0175 + v0176;
  const Scalar v0171 = v0169 + v0170;
  const Scalar v0038 = std::acos(v0031);
  const Scalar v0067 = v0036 * v0066;
  const Scalar v0037 = static_cast<Scalar>(1) / v0036;
  const Scalar v0399 = v0003 + v0006;
  const Scalar v0186 = v0059;
  const Scalar v0400 = v0043 + v0044;
  const Scalar v0401 = v0048 + v0050;
  const Scalar v0184 = v0168 * v0183;
  const Scalar v0361 = v0075 * v0076;
  const Scalar v0360 = static_cast<Scalar>(2) * v0040;
  const Scalar v0178 = v0168 * v0177;
  const Scalar v0172 = v0168 * v0171;
  const Scalar v0078 = static_cast<Scalar>(1) / v0035;
  const Scalar v0397 = v0031 * v0038;
  const Scalar v0068 = static_cast<Scalar>(1) / v0067;
  const Scalar v0363 = v0037 * v0038;
  const Scalar v0195 = v0056 * v0171;
  const Scalar v0190 = v0186 * v0399;
  const Scalar v0286 = v0056 * v0400;
  const Scalar v0281 = v0177 * v0186;
  const Scalar v0269 = v0056 * v0399;
  const Scalar v0264 = v0171 * v0186;
  const Scalar v0240 = v0056 * v0183;
  const Scalar v0235 = v0186 * v0401;
  const Scalar v0223 = v0056 * v0177;
  const Scalar v0218 = v0186 * v0400;
  const Scalar v0212 = v0056 * v0401;
  const Scalar v0207 = v0183 * v0186;
  const Scalar v0404 = v0184 + v0401;
  const Scalar v0362 = v0360 * v0361;
  const Scalar v0403 = v0178 + v0400;
  const Scalar v0402 = v0172 + v0399;
  const Scalar v0410 = -v0078;
  const Scalar v0398 = v0068 * v0397;
  const Scalar v0364 = v0360 * v0363;
  const Scalar v0196 = v0190 + v0195;
  const Scalar v0287 = v0281 + v0286;
  const Scalar v0270 = v0264 + v0269;
  const Scalar v0241 = v0235 + v0240;
  const Scalar v0224 = v0218 + v0223;
  const Scalar v0213 = v0207 + v0212;
  const Scalar v0367 = v0362 * v0404;
  const Scalar v0366 = v0362 * v0403;
  const Scalar v0365 = v0362 * v0402;
  const Scalar v0200 = v0398 + v0410;
  const Scalar v0373 = v0196 * v0364;
  const Scalar v0393 = v0287 * v0364;
  const Scalar v0389 = v0270 * v0364;
  const Scalar v0385 = v0241 * v0364;
  const Scalar v0381 = v0224 * v0364;
  const Scalar v0377 = v0213 * v0364;
  if (static_cast<bool>(_d0)) {
    const Scalar v0057 = v0056 * v0407;
    const Scalar v0388 = v0241 * v0367;
    const Scalar v0384 = v0224 * v0367;
    const Scalar v0376 = v0196 * v0367;
    const Scalar v0387 = v0241 * v0366;
    const Scalar v0383 = v0224 * v0366;
    const Scalar v0375 = v0196 * v0366;
    const Scalar v0386 = v0241 * v0365;
    const Scalar v0382 = v0224 * v0365;
    const Scalar v0374 = v0196 * v0365;
    const Scalar v0368 = v0057 * v0364;
    const Scalar v0304 = v0200 * v0388;
    const Scalar v0298 = v0200 * v0384;
    const Scalar v0292 = v0200 * v0376;
    const Scalar v0275 = v0200 * v0387;
    const Scalar v0258 = v0200 * v0383;
    const Scalar v0252 = v0200 * v0375;
    const Scalar v0246 = v0200 * v0386;
    const Scalar v0229 = v0200 * v0382;
    const Scalar v0201 = v0200 * v0374;
    const Scalar v0305 = v0304 + v0368;
    const Scalar v0299 = v0298 + v0373;
    const Scalar v0293 = v0292 + v0393;
    const Scalar v0276 = v0275 + v0389;
    const Scalar v0259 = v0258 + v0368;
    const Scalar v0253 = v0252 + v0385;
    const Scalar v0247 = v0246 + v0381;
    const Scalar v0230 = v0229 + v0377;
    const Scalar v0202 = v0201 + v0368;
    _d0(0, 0) = v0202;
    _d0(0, 1) = v0230;
    _d0(0, 2) = v0247;
    _d0(1, 0) = v0253;
    _d0(1, 1) = v0259;
    _d0(1, 2) = v0276;
    _d0(2, 0) = v0293;
    _d0(2, 1) = v0299;
    _d0(2, 2) = v0305;
  }
  if (static_cast<bool>(_d1)) {
    const Scalar v0138 = v0059 * v0407;
    const Scalar v0380 = v0213 * v0367;
    const Scalar v0396 = v0287 * v0367;
    const Scalar v0392 = v0270 * v0367;
    const Scalar v0379 = v0213 * v0366;
    const Scalar v0395 = v0287 * v0366;
    const Scalar v0391 = v0270 * v0366;
    const Scalar v0378 = v0213 * v0365;
    const Scalar v0394 = v0287 * v0365;
    const Scalar v0390 = v0270 * v0365;
    const Scalar v0369 = v0138 * v0364;
    const Scalar v0358 = v0200 * v0380;
    const Scalar v0352 = v0200 * v0396;
    const Scalar v0346 = v0200 * v0392;
    const Scalar v0340 = v0200 * v0379;
    const Scalar v0334 = v0200 * v0395;
    const Scalar v0328 = v0200 * v0391;
    const Scalar v0322 = v0200 * v0378;
    const Scalar v0316 = v0200 * v0394;
    const Scalar v0310 = v0200 * v0390;
    const Scalar v0359 = v0358 + v0369;
    const Scalar v0353 = v0352 + v0373;
    const Scalar v0347 = v0346 + v0393;
    const Scalar v0341 = v0340 + v0389;
    const Scalar v0335 = v0334 + v0369;
    const Scalar v0329 = v0328 + v0385;
    const Scalar v0323 = v0322 + v0381;
    const Scalar v0317 = v0316 + v0377;
    const Scalar v0311 = v0310 + v0369;
    _d1(0, 0) = v0311;
    _d1(0, 1) = v0317;
    _d1(0, 2) = v0323;
    _d1(1, 0) = v0329;
    _d1(1, 1) = v0335;
    _d1(1, 2) = v0341;
    _d1(2, 0) = v0347;
    _d1(2, 1) = v0353;
    _d1(2, 2) = v0359;
  }
  const Scalar v0372 = v0364 * v0404;
  const Scalar v0371 = v0364 * v0403;
  const Scalar v0370 = v0364 * v0402;
  _out(0, 0) = v0370;
  _out(1, 0) = v0371;
  _out(2, 0) = v0372;
}

}  // namespace gen
