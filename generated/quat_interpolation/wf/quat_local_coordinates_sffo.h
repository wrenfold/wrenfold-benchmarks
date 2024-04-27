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
  // add: 75
  // branch: 6
  // call: 4
  // compare: 4
  // divide: 3
  // multiply: 127
  // negate: 8
  // total: 227
  
  const Scalar v0006 = _q1_xyzw(1, 0);
  const Scalar v0005 = _q0_xyzw(1, 0);
  const Scalar v0003 = _q1_xyzw(0, 0);
  const Scalar v0002 = _q0_xyzw(0, 0);
  const Scalar v0007 = v0005 * v0006;
  const Scalar v0004 = v0002 * v0003;
  const Scalar v0009 = _q1_xyzw(2, 0);
  const Scalar v0008 = _q0_xyzw(2, 0);
  const Scalar v0014 = v0004 + v0007;
  const Scalar v0010 = v0008 * v0009;
  const Scalar v0012 = _q1_xyzw(3, 0);
  const Scalar v0011 = _q0_xyzw(3, 0);
  const Scalar v0015 = v0010 + v0014;
  const Scalar v0013 = v0011 * v0012;
  const Scalar v0016 = v0013 + v0015;
  const std::int64_t v0017 = (static_cast<Scalar>(0) < v0016) - (v0016 < static_cast<Scalar>(0));
  const bool v0019 = v0017 < 0;
  std::int64_t v0020;
  if (v0019) {
    v0020 = v0017;
  } else {
    v0020 = 0;
  }
  const Scalar v0023 = std::abs(v0016);
  const bool v0025 = v0023 < static_cast<Scalar>(0.9999999999999999);
  Scalar v0026;
  if (v0025) {
    v0026 = v0023;
  } else {
    v0026 = static_cast<Scalar>(0.9999999999999999);
  }
  const Scalar v0092 = -v0023;
  const Scalar v0093 = static_cast<Scalar>(0.9999999999999999) + v0092;
  const Scalar v0098 = static_cast<Scalar>(0.5);
  const bool v0095 = static_cast<Scalar>(0) < v0093;
  Scalar v0101;
  if (v0095) {
    v0101 = static_cast<Scalar>(1);
  } else {
    const bool v0096 = v0093 < static_cast<Scalar>(0);
    if (v0096) {
      v0101 = static_cast<Scalar>(-1);
    } else {
      v0101 = v0098;
    }
  }
  const std::int64_t v0021 = 2 * v0020;
  const Scalar v0037 = v0026 * v0026;
  const std::int64_t v0022 = 1 + v0021;
  const Scalar v0038 = -v0037;
  const Scalar v0115 = static_cast<Scalar>(v0017);
  const Scalar v0043 = static_cast<Scalar>(v0022);
  const Scalar v0040 = v0038 + static_cast<Scalar>(1);
  const Scalar v0116 = v0043 * v0115;
  const Scalar v0041 = std::sqrt(v0040);
  const Scalar v0076 = static_cast<Scalar>(-0.5);
  const Scalar v0064 = v0008 * v0012;
  const Scalar v0062 = v0002 * v0006;
  const Scalar v0051 = v0003 * v0008;
  const Scalar v0049 = v0005 * v0012;
  const Scalar v0030 = v0005 * v0009;
  const Scalar v0028 = v0002 * v0012;
  const Scalar v0117 = v0101 * v0116;
  const Scalar v0124 = v0041 * v0041;
  const Scalar v0079 = v0005 * v0076;
  const Scalar v0077 = v0002 * v0076;
  const Scalar v0083 = v0011 * v0076;
  const Scalar v0081 = v0008 * v0076;
  const Scalar v0065 = -v0064;
  const Scalar v0063 = -v0062;
  const Scalar v0052 = -v0051;
  const Scalar v0050 = -v0049;
  const Scalar v0031 = -v0030;
  const Scalar v0029 = -v0028;
  const Scalar v0129 = static_cast<Scalar>(2) * v0117;
  const Scalar v0027 = std::acos(v0026);
  const Scalar v0125 = v0041 * v0124;
  const Scalar v0107 = v0009 * v0079;
  const Scalar v0105 = v0012 * v0077;
  const Scalar v0108 = v0008 * v0098;
  const Scalar v0280 = v0006 * v0083;
  const Scalar v0278 = v0009 * v0077;
  const Scalar v0187 = v0005 * v0098;
  const Scalar v0249 = v0003 * v0083;
  const Scalar v0247 = v0006 * v0081;
  const Scalar v0141 = v0002 * v0098;
  const Scalar v0186 = v0012 * v0081;
  const Scalar v0184 = v0006 * v0077;
  const Scalar v0155 = v0003 * v0081;
  const Scalar v0153 = v0012 * v0079;
  const Scalar v0140 = v0009 * v0083;
  const Scalar v0138 = v0003 * v0079;
  const Scalar v0068 = v0063 + v0065;
  const Scalar v0066 = v0003 * v0005;
  const Scalar v0055 = v0050 + v0052;
  const Scalar v0053 = v0002 * v0009;
  const Scalar v0034 = v0029 + v0031;
  const Scalar v0032 = v0006 * v0008;
  const Scalar v0130 = v0027 * v0129;
  const Scalar v0126 = static_cast<Scalar>(1) / v0125;
  const Scalar v0112 = v0105 + v0107;
  const Scalar v0109 = v0006 * v0108;
  const Scalar v0110 = v0011 * v0098;
  const Scalar v0045 = v0043 * static_cast<Scalar>(2);
  const Scalar v0285 = v0278 + v0280;
  const Scalar v0282 = v0012 * v0187;
  const Scalar v0254 = v0247 + v0249;
  const Scalar v0251 = v0012 * v0141;
  const Scalar v0191 = v0184 + v0186;
  const Scalar v0188 = v0003 * v0187;
  const Scalar v0160 = v0153 + v0155;
  const Scalar v0157 = v0009 * v0141;
  const Scalar v0145 = v0138 + v0140;
  const Scalar v0142 = v0006 * v0141;
  const Scalar v0119 = v0117 * static_cast<Scalar>(-2);
  const Scalar v0103 = static_cast<Scalar>(1) / v0040;
  const Scalar v0069 = v0066 + v0068;
  const Scalar v0067 = v0009 * v0011;
  const Scalar v0056 = v0053 + v0055;
  const Scalar v0054 = v0006 * v0011;
  const Scalar v0035 = v0032 + v0034;
  const Scalar v0033 = v0003 * v0011;
  const Scalar v0131 = v0126 * v0130;
  const Scalar v0113 = v0109 + v0112;
  const Scalar v0111 = v0003 * v0110;
  const Scalar v0046 = v0027 * v0045;
  const Scalar v0042 = static_cast<Scalar>(1) / v0041;
  const Scalar v0286 = v0282 + v0285;
  const Scalar v0284 = v0003 * v0108;
  const Scalar v0255 = v0251 + v0254;
  const Scalar v0253 = v0009 * v0187;
  const Scalar v0192 = v0188 + v0191;
  const Scalar v0190 = v0009 * v0110;
  const Scalar v0161 = v0157 + v0160;
  const Scalar v0159 = v0006 * v0110;
  const Scalar v0146 = v0142 + v0145;
  const Scalar v0144 = v0012 * v0108;
  const Scalar v0120 = v0103 * v0119;
  const Scalar v0070 = v0067 + v0069;
  const Scalar v0057 = v0054 + v0056;
  const Scalar v0036 = v0033 + v0035;
  const Scalar v0132 = v0026 * v0131;
  const Scalar v0114 = v0111 + v0113;
  const Scalar v0090 = v0042 * v0046;
  const Scalar v0287 = v0284 + v0286;
  const Scalar v0256 = v0253 + v0255;
  const Scalar v0193 = v0190 + v0192;
  const Scalar v0162 = v0159 + v0161;
  const Scalar v0147 = v0144 + v0146;
  const Scalar v0296 = v0070 * v0120;
  const Scalar v0218 = v0057 * v0120;
  const Scalar v0121 = v0036 * v0120;
  const Scalar v0304 = v0070 * v0132;
  const Scalar v0311 = v0090 * v0114;
  const Scalar v0291 = v0090 * v0287;
  const Scalar v0260 = v0090 * v0256;
  const Scalar v0226 = v0057 * v0132;
  const Scalar v0213 = v0090 * v0193;
  const Scalar v0182 = v0090 * v0162;
  const Scalar v0133 = v0036 * v0132;
  const Scalar v0151 = v0090 * v0147;
  if (static_cast<bool>(_d0)) {
    const Scalar v0080 = v0006 * v0079;
    const Scalar v0078 = v0003 * v0077;
    const Scalar v0085 = v0078 + v0080;
    const Scalar v0082 = v0009 * v0081;
    const Scalar v0086 = v0082 + v0085;
    const Scalar v0084 = v0012 * v0083;
    const Scalar v0087 = v0084 + v0086;
    const Scalar v0333 = v0193 * v0296;
    const Scalar v0091 = v0087 * v0090;
    const Scalar v0317 = v0162 * v0296;
    const Scalar v0297 = v0114 * v0296;
    const Scalar v0266 = v0193 * v0218;
    const Scalar v0235 = v0162 * v0218;
    const Scalar v0219 = v0114 * v0218;
    const Scalar v0199 = v0121 * v0193;
    const Scalar v0168 = v0121 * v0162;
    const Scalar v0122 = v0114 * v0121;
    const Scalar v0342 = v0091 + v0333;
    const Scalar v0341 = v0193 * v0304;
    const Scalar v0326 = v0311 + v0317;
    const Scalar v0325 = v0162 * v0304;
    const Scalar v0306 = v0291 + v0297;
    const Scalar v0305 = v0114 * v0304;
    const Scalar v0275 = v0260 + v0266;
    const Scalar v0274 = v0193 * v0226;
    const Scalar v0244 = v0091 + v0235;
    const Scalar v0243 = v0162 * v0226;
    const Scalar v0228 = v0213 + v0219;
    const Scalar v0227 = v0114 * v0226;
    const Scalar v0208 = v0182 + v0199;
    const Scalar v0207 = v0133 * v0193;
    const Scalar v0177 = v0151 + v0168;
    const Scalar v0176 = v0133 * v0162;
    const Scalar v0135 = v0091 + v0122;
    const Scalar v0134 = v0114 * v0133;
    const Scalar v0343 = v0341 + v0342;
    const Scalar v0327 = v0325 + v0326;
    const Scalar v0307 = v0305 + v0306;
    const Scalar v0276 = v0274 + v0275;
    const Scalar v0245 = v0243 + v0244;
    const Scalar v0229 = v0227 + v0228;
    const Scalar v0209 = v0207 + v0208;
    const Scalar v0178 = v0176 + v0177;
    const Scalar v0136 = v0134 + v0135;
    _d0(0, 0) = v0136;
    _d0(0, 1) = v0178;
    _d0(0, 2) = v0209;
    _d0(1, 0) = v0229;
    _d0(1, 1) = v0245;
    _d0(1, 2) = v0276;
    _d0(2, 0) = v0307;
    _d0(2, 1) = v0327;
    _d0(2, 2) = v0343;
  }
  if (static_cast<bool>(_d1)) {
    const Scalar v0348 = v0006 * v0187;
    const Scalar v0346 = v0003 * v0141;
    const Scalar v0353 = v0346 + v0348;
    const Scalar v0350 = v0009 * v0108;
    const Scalar v0354 = v0350 + v0353;
    const Scalar v0352 = v0012 * v0110;
    const Scalar v0355 = v0352 + v0354;
    const Scalar v0493 = v0147 * v0296;
    const Scalar v0359 = v0090 * v0355;
    const Scalar v0477 = v0287 * v0296;
    const Scalar v0461 = v0256 * v0296;
    const Scalar v0445 = v0147 * v0218;
    const Scalar v0429 = v0218 * v0287;
    const Scalar v0413 = v0218 * v0256;
    const Scalar v0397 = v0121 * v0147;
    const Scalar v0381 = v0121 * v0287;
    const Scalar v0365 = v0121 * v0256;
    const Scalar v0502 = v0359 + v0493;
    const Scalar v0501 = v0147 * v0304;
    const Scalar v0486 = v0311 + v0477;
    const Scalar v0485 = v0287 * v0304;
    const Scalar v0470 = v0291 + v0461;
    const Scalar v0469 = v0256 * v0304;
    const Scalar v0454 = v0260 + v0445;
    const Scalar v0453 = v0147 * v0226;
    const Scalar v0438 = v0359 + v0429;
    const Scalar v0437 = v0226 * v0287;
    const Scalar v0422 = v0213 + v0413;
    const Scalar v0421 = v0226 * v0256;
    const Scalar v0406 = v0182 + v0397;
    const Scalar v0405 = v0133 * v0147;
    const Scalar v0390 = v0151 + v0381;
    const Scalar v0389 = v0133 * v0287;
    const Scalar v0374 = v0359 + v0365;
    const Scalar v0373 = v0133 * v0256;
    const Scalar v0503 = v0501 + v0502;
    const Scalar v0487 = v0485 + v0486;
    const Scalar v0471 = v0469 + v0470;
    const Scalar v0455 = v0453 + v0454;
    const Scalar v0439 = v0437 + v0438;
    const Scalar v0423 = v0421 + v0422;
    const Scalar v0407 = v0405 + v0406;
    const Scalar v0391 = v0389 + v0390;
    const Scalar v0375 = v0373 + v0374;
    _d1(0, 0) = v0375;
    _d1(0, 1) = v0391;
    _d1(0, 2) = v0407;
    _d1(1, 0) = v0423;
    _d1(1, 1) = v0439;
    _d1(1, 2) = v0455;
    _d1(2, 0) = v0471;
    _d1(2, 1) = v0487;
    _d1(2, 2) = v0503;
  }
  const Scalar v0073 = v0046 * v0070;
  const Scalar v0060 = v0046 * v0057;
  const Scalar v0047 = v0036 * v0046;
  const Scalar v0074 = v0042 * v0073;
  const Scalar v0061 = v0042 * v0060;
  const Scalar v0048 = v0042 * v0047;
  _out(0, 0) = v0048;
  _out(1, 0) = v0061;
  _out(2, 0) = v0074;
}

} // namespace gen