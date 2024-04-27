// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0, T4&& d1)
{
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _out = wf::make_output_span<3, 1>(out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 99
  // branch: 9
  // call: 2
  // compare: 3
  // divide: 3
  // multiply: 174
  // negate: 14
  // total: 304
  
  const Scalar v0005 = _q1_xyzw(1, 0);
  const Scalar v0004 = _q0_xyzw(1, 0);
  const Scalar v0002 = _q1_xyzw(0, 0);
  const Scalar v0001 = _q0_xyzw(0, 0);
  const Scalar v0006 = v0004 * v0005;
  const Scalar v0003 = v0001 * v0002;
  const Scalar v0008 = _q1_xyzw(2, 0);
  const Scalar v0007 = _q0_xyzw(2, 0);
  const Scalar v0013 = v0003 + v0006;
  const Scalar v0009 = v0007 * v0008;
  const Scalar v0011 = _q1_xyzw(3, 0);
  const Scalar v0010 = _q0_xyzw(3, 0);
  const Scalar v0014 = v0009 + v0013;
  const Scalar v0012 = v0010 * v0011;
  const Scalar v0015 = v0012 + v0014;
  const bool v0017 = static_cast<Scalar>(0) <= v0015;
  std::int64_t v0020;
  if (v0017) {
    v0020 = 1;
  } else {
    v0020 = -1;
  }
  const Scalar v0022 = static_cast<Scalar>(v0020);
  const Scalar v0023 = v0015 * v0022;
  const bool v0025 = static_cast<Scalar>(1) < v0023;
  Scalar v0026;
  if (v0025) {
    v0026 = static_cast<Scalar>(1);
  } else {
    v0026 = v0023;
  }
  const Scalar v0027 = v0026 * v0026;
  const Scalar v0028 = -v0027;
  const Scalar v0029 = static_cast<Scalar>(1) + v0028;
  const Scalar v0033 = std::acos(v0026);
  const Scalar v0030 = std::sqrt(v0029);
  const Scalar v0036 = v0033 * static_cast<Scalar>(2);
  const bool v0031 = static_cast<Scalar>(1e-16) < v0030;
  Scalar v0038;
  if (v0031) {
    const Scalar v0034 = static_cast<Scalar>(1) / v0030;
    v0038 = v0034 * v0036;
  } else {
    v0038 = static_cast<Scalar>(2);
  }
  const Scalar v0063 = v0007 * v0011;
  const Scalar v0061 = v0001 * v0005;
  const Scalar v0052 = v0002 * v0007;
  const Scalar v0050 = v0004 * v0011;
  const Scalar v0041 = v0004 * v0008;
  const Scalar v0039 = v0001 * v0011;
  const Scalar v0084 = v0030 * v0030;
  const Scalar v0064 = -v0063;
  const Scalar v0062 = -v0061;
  const Scalar v0053 = -v0052;
  const Scalar v0051 = -v0050;
  const Scalar v0042 = -v0041;
  const Scalar v0040 = -v0039;
  const Scalar v0085 = v0030 * v0084;
  const Scalar v0067 = v0062 + v0064;
  const Scalar v0065 = v0002 * v0004;
  const Scalar v0056 = v0051 + v0053;
  const Scalar v0054 = v0001 * v0008;
  const Scalar v0045 = v0040 + v0042;
  const Scalar v0043 = v0005 * v0007;
  const Scalar v0086 = static_cast<Scalar>(1) / v0085;
  const Scalar v0068 = v0065 + v0067;
  const Scalar v0066 = v0008 * v0010;
  const Scalar v0057 = v0054 + v0056;
  const Scalar v0055 = v0005 * v0010;
  const Scalar v0046 = v0043 + v0045;
  const Scalar v0044 = v0002 * v0010;
  const Scalar v0088 = v0036 * v0086;
  const Scalar v0077 = static_cast<Scalar>(1) / v0029;
  const Scalar v0069 = v0066 + v0068;
  const Scalar v0058 = v0055 + v0057;
  const Scalar v0047 = v0044 + v0046;
  const Scalar v0089 = v0026 * v0088;
  const Scalar v0081 = v0077 * static_cast<Scalar>(-2);
  const Scalar v0048 = v0022 * v0038;
  const Scalar v0227 = v0022 * v0069;
  const Scalar v0177 = v0022 * v0058;
  const Scalar v0093 = v0022 * v0047;
  const Scalar v0073 = static_cast<Scalar>(-0.5);
  const Scalar v0115 = static_cast<Scalar>(0.5);
  if (static_cast<bool>(_d0)) {
    Scalar v0092;
    Scalar v0109;
    Scalar v0128;
    Scalar v0146;
    if (v0031) {
      Scalar v0079;
      Scalar v0101;
      Scalar v0120;
      Scalar v0138;
      if (v0025) {
        v0079 = static_cast<Scalar>(0);
        v0101 = static_cast<Scalar>(0);
        v0120 = static_cast<Scalar>(0);
        v0138 = static_cast<Scalar>(0);
      } else {
        v0079 = v0011 * v0022;
        v0101 = v0008 * v0022;
        v0120 = v0005 * v0022;
        v0138 = v0002 * v0022;
      }
      const Scalar v0090 = v0079 * v0089;
      const Scalar v0082 = v0079 * v0081;
      const Scalar v0107 = v0089 * v0101;
      const Scalar v0103 = v0081 * v0101;
      const Scalar v0126 = v0089 * v0120;
      const Scalar v0122 = v0081 * v0120;
      const Scalar v0144 = v0089 * v0138;
      const Scalar v0140 = v0081 * v0138;
      v0092 = v0082 + v0090;
      v0109 = v0103 + v0107;
      v0128 = v0122 + v0126;
      v0146 = v0140 + v0144;
    } else {
      v0092 = static_cast<Scalar>(0);
      v0109 = static_cast<Scalar>(0);
      v0128 = static_cast<Scalar>(0);
      v0146 = static_cast<Scalar>(0);
    }
    const Scalar v0099 = v0005 * v0048;
    const Scalar v0135 = v0011 * v0048;
    const Scalar v0075 = v0002 * v0048;
    const Scalar v0117 = v0008 * v0048;
    const Scalar v0228 = v0092 * v0227;
    const Scalar v0238 = v0128 * v0227;
    const Scalar v0246 = v0146 * v0227;
    const Scalar v0244 = -v0099;
    const Scalar v0233 = v0109 * v0227;
    const Scalar v0136 = -v0135;
    const Scalar v0178 = v0092 * v0177;
    const Scalar v0191 = v0128 * v0177;
    const Scalar v0198 = v0146 * v0177;
    const Scalar v0186 = v0109 * v0177;
    const Scalar v0184 = -v0075;
    const Scalar v0094 = v0092 * v0093;
    const Scalar v0130 = v0093 * v0128;
    const Scalar v0118 = -v0117;
    const Scalar v0148 = v0093 * v0146;
    const Scalar v0111 = v0093 * v0109;
    const Scalar v0229 = v0117 + v0228;
    const Scalar v0157 = v0007 * v0073;
    const Scalar v0239 = v0075 + v0238;
    const Scalar v0096 = v0001 * v0073;
    const Scalar v0247 = v0244 + v0246;
    const Scalar v0113 = v0004 * v0073;
    const Scalar v0234 = v0136 + v0233;
    const Scalar v0179 = v0099 + v0178;
    const Scalar v0192 = v0136 + v0191;
    const Scalar v0199 = v0117 + v0198;
    const Scalar v0187 = v0184 + v0186;
    const Scalar v0095 = v0075 + v0094;
    const Scalar v0131 = v0118 + v0130;
    const Scalar v0149 = v0136 + v0148;
    const Scalar v0112 = v0099 + v0111;
    const Scalar v0267 = v0157 * v0229;
    const Scalar v0265 = v0096 * v0239;
    const Scalar v0170 = v0004 * v0115;
    const Scalar v0256 = v0157 * v0247;
    const Scalar v0254 = v0113 * v0229;
    const Scalar v0159 = v0001 * v0115;
    const Scalar v0236 = v0113 * v0234;
    const Scalar v0231 = v0096 * v0229;
    const Scalar v0132 = v0007 * v0115;
    const Scalar v0219 = v0157 * v0179;
    const Scalar v0217 = v0096 * v0192;
    const Scalar v0208 = v0157 * v0199;
    const Scalar v0206 = v0113 * v0179;
    const Scalar v0189 = v0113 * v0187;
    const Scalar v0181 = v0096 * v0179;
    const Scalar v0169 = v0095 * v0157;
    const Scalar v0167 = v0096 * v0131;
    const Scalar v0158 = v0149 * v0157;
    const Scalar v0156 = v0095 * v0113;
    const Scalar v0114 = v0112 * v0113;
    const Scalar v0097 = v0095 * v0096;
    const Scalar v0272 = v0265 + v0267;
    const Scalar v0269 = v0170 * v0247;
    const Scalar v0150 = v0010 * v0115;
    const Scalar v0261 = v0254 + v0256;
    const Scalar v0258 = v0159 * v0234;
    const Scalar v0250 = v0231 + v0236;
    const Scalar v0241 = v0132 * v0239;
    const Scalar v0224 = v0217 + v0219;
    const Scalar v0221 = v0170 * v0199;
    const Scalar v0213 = v0206 + v0208;
    const Scalar v0210 = v0159 * v0187;
    const Scalar v0202 = v0181 + v0189;
    const Scalar v0194 = v0132 * v0192;
    const Scalar v0174 = v0167 + v0169;
    const Scalar v0171 = v0149 * v0170;
    const Scalar v0163 = v0156 + v0158;
    const Scalar v0160 = v0112 * v0159;
    const Scalar v0152 = v0097 + v0114;
    const Scalar v0133 = v0131 * v0132;
    const Scalar v0273 = v0269 + v0272;
    const Scalar v0271 = v0150 * v0234;
    const Scalar v0262 = v0258 + v0261;
    const Scalar v0260 = v0150 * v0239;
    const Scalar v0251 = v0241 + v0250;
    const Scalar v0249 = v0150 * v0247;
    const Scalar v0225 = v0221 + v0224;
    const Scalar v0223 = v0150 * v0187;
    const Scalar v0214 = v0210 + v0213;
    const Scalar v0212 = v0150 * v0192;
    const Scalar v0203 = v0194 + v0202;
    const Scalar v0201 = v0150 * v0199;
    const Scalar v0175 = v0171 + v0174;
    const Scalar v0173 = v0112 * v0150;
    const Scalar v0164 = v0160 + v0163;
    const Scalar v0162 = v0131 * v0150;
    const Scalar v0153 = v0133 + v0152;
    const Scalar v0151 = v0149 * v0150;
    const Scalar v0274 = v0271 + v0273;
    const Scalar v0263 = v0260 + v0262;
    const Scalar v0252 = v0249 + v0251;
    const Scalar v0226 = v0223 + v0225;
    const Scalar v0215 = v0212 + v0214;
    const Scalar v0204 = v0201 + v0203;
    const Scalar v0176 = v0173 + v0175;
    const Scalar v0165 = v0162 + v0164;
    const Scalar v0154 = v0151 + v0153;
    _d0(0, 0) = v0154;
    _d0(0, 1) = v0165;
    _d0(0, 2) = v0176;
    _d0(1, 0) = v0204;
    _d0(1, 1) = v0215;
    _d0(1, 2) = v0226;
    _d0(2, 0) = v0252;
    _d0(2, 1) = v0263;
    _d0(2, 2) = v0274;
  }
  if (static_cast<bool>(_d1)) {
    Scalar v0288;
    Scalar v0306;
    Scalar v0323;
    Scalar v0340;
    if (v0031) {
      Scalar v0280;
      Scalar v0298;
      Scalar v0315;
      Scalar v0332;
      if (v0025) {
        v0280 = static_cast<Scalar>(0);
        v0298 = static_cast<Scalar>(0);
        v0315 = static_cast<Scalar>(0);
        v0332 = static_cast<Scalar>(0);
      } else {
        v0280 = v0010 * v0022;
        v0298 = v0007 * v0022;
        v0315 = v0004 * v0022;
        v0332 = v0001 * v0022;
      }
      const Scalar v0286 = v0089 * v0280;
      const Scalar v0282 = v0081 * v0280;
      const Scalar v0304 = v0089 * v0298;
      const Scalar v0300 = v0081 * v0298;
      const Scalar v0321 = v0089 * v0315;
      const Scalar v0317 = v0081 * v0315;
      const Scalar v0338 = v0089 * v0332;
      const Scalar v0334 = v0081 * v0332;
      v0288 = v0282 + v0286;
      v0306 = v0300 + v0304;
      v0323 = v0317 + v0321;
      v0340 = v0334 + v0338;
    } else {
      v0288 = static_cast<Scalar>(0);
      v0306 = static_cast<Scalar>(0);
      v0323 = static_cast<Scalar>(0);
      v0340 = static_cast<Scalar>(0);
    }
    const Scalar v0313 = v0007 * v0048;
    const Scalar v0277 = v0001 * v0048;
    const Scalar v0295 = v0004 * v0048;
    const Scalar v0422 = v0227 * v0288;
    const Scalar v0390 = -v0313;
    const Scalar v0432 = v0227 * v0323;
    const Scalar v0278 = -v0277;
    const Scalar v0439 = v0227 * v0340;
    const Scalar v0427 = v0227 * v0306;
    const Scalar v0330 = v0010 * v0048;
    const Scalar v0372 = v0177 * v0288;
    const Scalar v0296 = -v0295;
    const Scalar v0384 = v0177 * v0323;
    const Scalar v0392 = v0177 * v0340;
    const Scalar v0379 = v0177 * v0306;
    const Scalar v0290 = v0093 * v0288;
    const Scalar v0325 = v0093 * v0323;
    const Scalar v0342 = v0093 * v0340;
    const Scalar v0308 = v0093 * v0306;
    const Scalar v0423 = v0390 + v0422;
    const Scalar v0351 = v0008 * v0073;
    const Scalar v0433 = v0278 + v0432;
    const Scalar v0292 = v0002 * v0073;
    const Scalar v0440 = v0295 + v0439;
    const Scalar v0310 = v0005 * v0073;
    const Scalar v0428 = v0330 + v0427;
    const Scalar v0373 = v0296 + v0372;
    const Scalar v0385 = v0330 + v0384;
    const Scalar v0393 = v0390 + v0392;
    const Scalar v0380 = v0277 + v0379;
    const Scalar v0291 = v0278 + v0290;
    const Scalar v0326 = v0313 + v0325;
    const Scalar v0343 = v0330 + v0342;
    const Scalar v0309 = v0296 + v0308;
    const Scalar v0460 = v0351 * v0423;
    const Scalar v0458 = v0292 * v0433;
    const Scalar v0364 = v0005 * v0115;
    const Scalar v0449 = v0351 * v0440;
    const Scalar v0447 = v0310 * v0423;
    const Scalar v0353 = v0002 * v0115;
    const Scalar v0430 = v0310 * v0428;
    const Scalar v0425 = v0292 * v0423;
    const Scalar v0327 = v0008 * v0115;
    const Scalar v0413 = v0351 * v0373;
    const Scalar v0411 = v0292 * v0385;
    const Scalar v0402 = v0351 * v0393;
    const Scalar v0400 = v0310 * v0373;
    const Scalar v0382 = v0310 * v0380;
    const Scalar v0375 = v0292 * v0373;
    const Scalar v0363 = v0291 * v0351;
    const Scalar v0361 = v0292 * v0326;
    const Scalar v0352 = v0343 * v0351;
    const Scalar v0350 = v0291 * v0310;
    const Scalar v0311 = v0309 * v0310;
    const Scalar v0293 = v0291 * v0292;
    const Scalar v0465 = v0458 + v0460;
    const Scalar v0462 = v0364 * v0440;
    const Scalar v0344 = v0011 * v0115;
    const Scalar v0454 = v0447 + v0449;
    const Scalar v0451 = v0353 * v0428;
    const Scalar v0443 = v0425 + v0430;
    const Scalar v0435 = v0327 * v0433;
    const Scalar v0418 = v0411 + v0413;
    const Scalar v0415 = v0364 * v0393;
    const Scalar v0407 = v0400 + v0402;
    const Scalar v0404 = v0353 * v0380;
    const Scalar v0396 = v0375 + v0382;
    const Scalar v0387 = v0327 * v0385;
    const Scalar v0368 = v0361 + v0363;
    const Scalar v0365 = v0343 * v0364;
    const Scalar v0357 = v0350 + v0352;
    const Scalar v0354 = v0309 * v0353;
    const Scalar v0346 = v0293 + v0311;
    const Scalar v0328 = v0326 * v0327;
    const Scalar v0466 = v0462 + v0465;
    const Scalar v0464 = v0344 * v0428;
    const Scalar v0455 = v0451 + v0454;
    const Scalar v0453 = v0344 * v0433;
    const Scalar v0444 = v0435 + v0443;
    const Scalar v0442 = v0344 * v0440;
    const Scalar v0419 = v0415 + v0418;
    const Scalar v0417 = v0344 * v0380;
    const Scalar v0408 = v0404 + v0407;
    const Scalar v0406 = v0344 * v0385;
    const Scalar v0397 = v0387 + v0396;
    const Scalar v0395 = v0344 * v0393;
    const Scalar v0369 = v0365 + v0368;
    const Scalar v0367 = v0309 * v0344;
    const Scalar v0358 = v0354 + v0357;
    const Scalar v0356 = v0326 * v0344;
    const Scalar v0347 = v0328 + v0346;
    const Scalar v0345 = v0343 * v0344;
    const Scalar v0467 = v0464 + v0466;
    const Scalar v0456 = v0453 + v0455;
    const Scalar v0445 = v0442 + v0444;
    const Scalar v0420 = v0417 + v0419;
    const Scalar v0409 = v0406 + v0408;
    const Scalar v0398 = v0395 + v0397;
    const Scalar v0370 = v0367 + v0369;
    const Scalar v0359 = v0356 + v0358;
    const Scalar v0348 = v0345 + v0347;
    _d1(0, 0) = v0348;
    _d1(0, 1) = v0359;
    _d1(0, 2) = v0370;
    _d1(1, 0) = v0398;
    _d1(1, 1) = v0409;
    _d1(1, 2) = v0420;
    _d1(2, 0) = v0445;
    _d1(2, 1) = v0456;
    _d1(2, 2) = v0467;
  }
  const Scalar v0071 = v0048 * v0069;
  const Scalar v0060 = v0048 * v0058;
  const Scalar v0049 = v0047 * v0048;
  _out(0, 0) = v0049;
  _out(1, 0) = v0060;
  _out(2, 0) = v0071;
}

} // namespace gen