// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4>
void quat_local_coordinates_no_conditional(const T0& q0_xyzw, const T1& q1_xyzw, T2&& out, T3&& d0, T4&& d1)
{
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _out = wf::make_output_span<3, 1>(out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 115
  // branch: 6
  // call: 2
  // compare: 2
  // divide: 3
  // multiply: 197
  // negate: 7
  // total: 332
  
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
  const Scalar v0021 = static_cast<Scalar>(v0020);
  const Scalar v0022 = v0015 * v0021;
  const bool v0024 = static_cast<Scalar>(1) < v0022;
  Scalar v0025;
  if (v0024) {
    v0025 = static_cast<Scalar>(1);
  } else {
    v0025 = v0022;
  }
  const Scalar v0037 = v0025 * v0025;
  const Scalar v0038 = -v0037;
  const Scalar v0039 = static_cast<Scalar>(1) + v0038;
  const Scalar v0040 = std::sqrt(v0039);
  const Scalar v0062 = v0007 * v0011;
  const Scalar v0060 = v0001 * v0005;
  const Scalar v0049 = v0002 * v0007;
  const Scalar v0047 = v0004 * v0011;
  const Scalar v0030 = v0004 * v0008;
  const Scalar v0028 = v0001 * v0011;
  const Scalar v0089 = v0040 * v0040;
  const Scalar v0026 = std::acos(v0025);
  const Scalar v0063 = -v0062;
  const Scalar v0061 = -v0060;
  const Scalar v0050 = -v0049;
  const Scalar v0048 = -v0047;
  const Scalar v0031 = -v0030;
  const Scalar v0029 = -v0028;
  const Scalar v0090 = v0040 * v0089;
  const Scalar v0042 = v0021 * v0026;
  const Scalar v0066 = v0061 + v0063;
  const Scalar v0064 = v0002 * v0004;
  const Scalar v0053 = v0048 + v0050;
  const Scalar v0051 = v0001 * v0008;
  const Scalar v0034 = v0029 + v0031;
  const Scalar v0032 = v0005 * v0007;
  const Scalar v0091 = static_cast<Scalar>(1) / v0090;
  const Scalar v0044 = v0042 * static_cast<Scalar>(2);
  const Scalar v0084 = v0021 * static_cast<Scalar>(-2);
  const Scalar v0080 = static_cast<Scalar>(1) / v0039;
  const Scalar v0067 = v0064 + v0066;
  const Scalar v0065 = v0008 * v0010;
  const Scalar v0054 = v0051 + v0053;
  const Scalar v0052 = v0005 * v0010;
  const Scalar v0035 = v0032 + v0034;
  const Scalar v0033 = v0002 * v0010;
  const Scalar v0094 = v0044 * v0091;
  const Scalar v0085 = v0080 * v0084;
  const Scalar v0068 = v0065 + v0067;
  const Scalar v0041 = static_cast<Scalar>(1) / v0040;
  const Scalar v0124 = v0042 * static_cast<Scalar>(-2);
  const Scalar v0055 = v0052 + v0054;
  const Scalar v0036 = v0033 + v0035;
  const Scalar v0095 = v0025 * v0094;
  const Scalar v0279 = v0068 * v0085;
  const Scalar v0077 = v0041 * v0044;
  const Scalar v0125 = v0041 * v0124;
  const Scalar v0190 = v0055 * v0085;
  const Scalar v0086 = v0036 * v0085;
  const Scalar v0285 = v0068 * v0095;
  const Scalar v0196 = v0055 * v0095;
  const Scalar v0096 = v0036 * v0095;
  const Scalar v0074 = static_cast<Scalar>(-0.5);
  const Scalar v0122 = static_cast<Scalar>(0.5);
  if (static_cast<bool>(_d0)) {
    Scalar v0082;
    Scalar v0107;
    Scalar v0128;
    Scalar v0148;
    if (v0024) {
      v0082 = static_cast<Scalar>(0);
      v0107 = static_cast<Scalar>(0);
      v0128 = static_cast<Scalar>(0);
      v0148 = static_cast<Scalar>(0);
    } else {
      v0082 = v0011 * v0021;
      v0107 = v0008 * v0021;
      v0128 = v0005 * v0021;
      v0148 = v0002 * v0021;
    }
    const Scalar v0280 = v0082 * v0279;
    const Scalar v0237 = v0008 * v0077;
    const Scalar v0308 = v0128 * v0279;
    const Scalar v0078 = v0002 * v0077;
    const Scalar v0326 = v0148 * v0279;
    const Scalar v0322 = v0005 * v0125;
    const Scalar v0294 = v0107 * v0279;
    const Scalar v0146 = v0011 * v0125;
    const Scalar v0191 = v0082 * v0190;
    const Scalar v0105 = v0005 * v0077;
    const Scalar v0223 = v0128 * v0190;
    const Scalar v0241 = v0148 * v0190;
    const Scalar v0209 = v0107 * v0190;
    const Scalar v0205 = v0002 * v0125;
    const Scalar v0087 = v0082 * v0086;
    const Scalar v0132 = v0086 * v0128;
    const Scalar v0126 = v0008 * v0125;
    const Scalar v0152 = v0086 * v0148;
    const Scalar v0111 = v0086 * v0107;
    const Scalar v0287 = v0237 + v0280;
    const Scalar v0286 = v0082 * v0285;
    const Scalar v0315 = v0078 + v0308;
    const Scalar v0314 = v0128 * v0285;
    const Scalar v0333 = v0322 + v0326;
    const Scalar v0332 = v0148 * v0285;
    const Scalar v0301 = v0146 + v0294;
    const Scalar v0300 = v0107 * v0285;
    const Scalar v0198 = v0105 + v0191;
    const Scalar v0197 = v0082 * v0196;
    const Scalar v0230 = v0146 + v0223;
    const Scalar v0229 = v0128 * v0196;
    const Scalar v0248 = v0237 + v0241;
    const Scalar v0247 = v0148 * v0196;
    const Scalar v0216 = v0205 + v0209;
    const Scalar v0215 = v0107 * v0196;
    const Scalar v0098 = v0078 + v0087;
    const Scalar v0097 = v0082 * v0096;
    const Scalar v0139 = v0126 + v0132;
    const Scalar v0138 = v0096 * v0128;
    const Scalar v0159 = v0146 + v0152;
    const Scalar v0158 = v0096 * v0148;
    const Scalar v0118 = v0105 + v0111;
    const Scalar v0117 = v0096 * v0107;
    const Scalar v0288 = v0286 + v0287;
    const Scalar v0168 = v0007 * v0074;
    const Scalar v0316 = v0314 + v0315;
    const Scalar v0100 = v0001 * v0074;
    const Scalar v0334 = v0332 + v0333;
    const Scalar v0120 = v0004 * v0074;
    const Scalar v0302 = v0300 + v0301;
    const Scalar v0199 = v0197 + v0198;
    const Scalar v0231 = v0229 + v0230;
    const Scalar v0249 = v0247 + v0248;
    const Scalar v0217 = v0215 + v0216;
    const Scalar v0099 = v0097 + v0098;
    const Scalar v0140 = v0138 + v0139;
    const Scalar v0160 = v0158 + v0159;
    const Scalar v0119 = v0117 + v0118;
    const Scalar v0354 = v0168 * v0288;
    const Scalar v0352 = v0100 * v0316;
    const Scalar v0181 = v0004 * v0122;
    const Scalar v0343 = v0168 * v0334;
    const Scalar v0341 = v0120 * v0288;
    const Scalar v0170 = v0001 * v0122;
    const Scalar v0304 = v0120 * v0302;
    const Scalar v0290 = v0100 * v0288;
    const Scalar v0141 = v0007 * v0122;
    const Scalar v0269 = v0168 * v0199;
    const Scalar v0267 = v0100 * v0231;
    const Scalar v0258 = v0168 * v0249;
    const Scalar v0256 = v0120 * v0199;
    const Scalar v0219 = v0120 * v0217;
    const Scalar v0201 = v0100 * v0199;
    const Scalar v0180 = v0099 * v0168;
    const Scalar v0178 = v0100 * v0140;
    const Scalar v0169 = v0160 * v0168;
    const Scalar v0167 = v0099 * v0120;
    const Scalar v0121 = v0119 * v0120;
    const Scalar v0101 = v0099 * v0100;
    const Scalar v0359 = v0352 + v0354;
    const Scalar v0356 = v0181 * v0334;
    const Scalar v0161 = v0010 * v0122;
    const Scalar v0348 = v0341 + v0343;
    const Scalar v0345 = v0170 * v0302;
    const Scalar v0337 = v0290 + v0304;
    const Scalar v0318 = v0141 * v0316;
    const Scalar v0274 = v0267 + v0269;
    const Scalar v0271 = v0181 * v0249;
    const Scalar v0263 = v0256 + v0258;
    const Scalar v0260 = v0170 * v0217;
    const Scalar v0252 = v0201 + v0219;
    const Scalar v0233 = v0141 * v0231;
    const Scalar v0185 = v0178 + v0180;
    const Scalar v0182 = v0160 * v0181;
    const Scalar v0174 = v0167 + v0169;
    const Scalar v0171 = v0119 * v0170;
    const Scalar v0163 = v0101 + v0121;
    const Scalar v0142 = v0140 * v0141;
    const Scalar v0360 = v0356 + v0359;
    const Scalar v0358 = v0161 * v0302;
    const Scalar v0349 = v0345 + v0348;
    const Scalar v0347 = v0161 * v0316;
    const Scalar v0338 = v0318 + v0337;
    const Scalar v0336 = v0161 * v0334;
    const Scalar v0275 = v0271 + v0274;
    const Scalar v0273 = v0161 * v0217;
    const Scalar v0264 = v0260 + v0263;
    const Scalar v0262 = v0161 * v0231;
    const Scalar v0253 = v0233 + v0252;
    const Scalar v0251 = v0161 * v0249;
    const Scalar v0186 = v0182 + v0185;
    const Scalar v0184 = v0119 * v0161;
    const Scalar v0175 = v0171 + v0174;
    const Scalar v0173 = v0140 * v0161;
    const Scalar v0164 = v0142 + v0163;
    const Scalar v0162 = v0160 * v0161;
    const Scalar v0361 = v0358 + v0360;
    const Scalar v0350 = v0347 + v0349;
    const Scalar v0339 = v0336 + v0338;
    const Scalar v0276 = v0273 + v0275;
    const Scalar v0265 = v0262 + v0264;
    const Scalar v0254 = v0251 + v0253;
    const Scalar v0187 = v0184 + v0186;
    const Scalar v0176 = v0173 + v0175;
    const Scalar v0165 = v0162 + v0164;
    _d0(0, 0) = v0165;
    _d0(0, 1) = v0176;
    _d0(0, 2) = v0187;
    _d0(1, 0) = v0254;
    _d0(1, 1) = v0265;
    _d0(1, 2) = v0276;
    _d0(2, 0) = v0339;
    _d0(2, 1) = v0350;
    _d0(2, 2) = v0361;
  }
  if (static_cast<bool>(_d1)) {
    Scalar v0368;
    Scalar v0388;
    Scalar v0404;
    Scalar v0428;
    if (v0024) {
      v0368 = static_cast<Scalar>(0);
      v0388 = static_cast<Scalar>(0);
      v0404 = static_cast<Scalar>(0);
      v0428 = static_cast<Scalar>(0);
    } else {
      v0368 = v0010 * v0021;
      v0388 = v0007 * v0021;
      v0404 = v0004 * v0021;
      v0428 = v0001 * v0021;
    }
    const Scalar v0560 = v0279 * v0368;
    const Scalar v0517 = v0007 * v0125;
    const Scalar v0588 = v0279 * v0404;
    const Scalar v0366 = v0001 * v0125;
    const Scalar v0606 = v0004 * v0077;
    const Scalar v0602 = v0279 * v0428;
    const Scalar v0574 = v0279 * v0388;
    const Scalar v0426 = v0010 * v0077;
    const Scalar v0471 = v0190 * v0368;
    const Scalar v0386 = v0004 * v0125;
    const Scalar v0503 = v0190 * v0404;
    const Scalar v0521 = v0190 * v0428;
    const Scalar v0489 = v0001 * v0077;
    const Scalar v0485 = v0190 * v0388;
    const Scalar v0372 = v0086 * v0368;
    const Scalar v0412 = v0007 * v0077;
    const Scalar v0408 = v0086 * v0404;
    const Scalar v0432 = v0086 * v0428;
    const Scalar v0392 = v0086 * v0388;
    const Scalar v0567 = v0517 + v0560;
    const Scalar v0566 = v0285 * v0368;
    const Scalar v0595 = v0366 + v0588;
    const Scalar v0594 = v0285 * v0404;
    const Scalar v0613 = v0602 + v0606;
    const Scalar v0612 = v0285 * v0428;
    const Scalar v0581 = v0426 + v0574;
    const Scalar v0580 = v0285 * v0388;
    const Scalar v0478 = v0386 + v0471;
    const Scalar v0477 = v0196 * v0368;
    const Scalar v0510 = v0426 + v0503;
    const Scalar v0509 = v0196 * v0404;
    const Scalar v0528 = v0517 + v0521;
    const Scalar v0527 = v0196 * v0428;
    const Scalar v0496 = v0485 + v0489;
    const Scalar v0495 = v0196 * v0388;
    const Scalar v0379 = v0366 + v0372;
    const Scalar v0378 = v0096 * v0368;
    const Scalar v0419 = v0408 + v0412;
    const Scalar v0418 = v0096 * v0404;
    const Scalar v0439 = v0426 + v0432;
    const Scalar v0438 = v0096 * v0428;
    const Scalar v0399 = v0386 + v0392;
    const Scalar v0398 = v0096 * v0388;
    const Scalar v0568 = v0566 + v0567;
    const Scalar v0448 = v0008 * v0074;
    const Scalar v0596 = v0594 + v0595;
    const Scalar v0381 = v0002 * v0074;
    const Scalar v0614 = v0612 + v0613;
    const Scalar v0401 = v0005 * v0074;
    const Scalar v0582 = v0580 + v0581;
    const Scalar v0479 = v0477 + v0478;
    const Scalar v0511 = v0509 + v0510;
    const Scalar v0529 = v0527 + v0528;
    const Scalar v0497 = v0495 + v0496;
    const Scalar v0380 = v0378 + v0379;
    const Scalar v0420 = v0418 + v0419;
    const Scalar v0440 = v0438 + v0439;
    const Scalar v0400 = v0398 + v0399;
    const Scalar v0634 = v0448 * v0568;
    const Scalar v0632 = v0381 * v0596;
    const Scalar v0461 = v0005 * v0122;
    const Scalar v0623 = v0448 * v0614;
    const Scalar v0621 = v0401 * v0568;
    const Scalar v0450 = v0002 * v0122;
    const Scalar v0584 = v0401 * v0582;
    const Scalar v0570 = v0381 * v0568;
    const Scalar v0421 = v0008 * v0122;
    const Scalar v0549 = v0448 * v0479;
    const Scalar v0547 = v0381 * v0511;
    const Scalar v0538 = v0448 * v0529;
    const Scalar v0536 = v0401 * v0479;
    const Scalar v0499 = v0401 * v0497;
    const Scalar v0481 = v0381 * v0479;
    const Scalar v0460 = v0380 * v0448;
    const Scalar v0458 = v0381 * v0420;
    const Scalar v0449 = v0440 * v0448;
    const Scalar v0447 = v0380 * v0401;
    const Scalar v0402 = v0400 * v0401;
    const Scalar v0382 = v0380 * v0381;
    const Scalar v0639 = v0632 + v0634;
    const Scalar v0636 = v0461 * v0614;
    const Scalar v0441 = v0011 * v0122;
    const Scalar v0628 = v0621 + v0623;
    const Scalar v0625 = v0450 * v0582;
    const Scalar v0617 = v0570 + v0584;
    const Scalar v0598 = v0421 * v0596;
    const Scalar v0554 = v0547 + v0549;
    const Scalar v0551 = v0461 * v0529;
    const Scalar v0543 = v0536 + v0538;
    const Scalar v0540 = v0450 * v0497;
    const Scalar v0532 = v0481 + v0499;
    const Scalar v0513 = v0421 * v0511;
    const Scalar v0465 = v0458 + v0460;
    const Scalar v0462 = v0440 * v0461;
    const Scalar v0454 = v0447 + v0449;
    const Scalar v0451 = v0400 * v0450;
    const Scalar v0443 = v0382 + v0402;
    const Scalar v0422 = v0420 * v0421;
    const Scalar v0640 = v0636 + v0639;
    const Scalar v0638 = v0441 * v0582;
    const Scalar v0629 = v0625 + v0628;
    const Scalar v0627 = v0441 * v0596;
    const Scalar v0618 = v0598 + v0617;
    const Scalar v0616 = v0441 * v0614;
    const Scalar v0555 = v0551 + v0554;
    const Scalar v0553 = v0441 * v0497;
    const Scalar v0544 = v0540 + v0543;
    const Scalar v0542 = v0441 * v0511;
    const Scalar v0533 = v0513 + v0532;
    const Scalar v0531 = v0441 * v0529;
    const Scalar v0466 = v0462 + v0465;
    const Scalar v0464 = v0400 * v0441;
    const Scalar v0455 = v0451 + v0454;
    const Scalar v0453 = v0420 * v0441;
    const Scalar v0444 = v0422 + v0443;
    const Scalar v0442 = v0440 * v0441;
    const Scalar v0641 = v0638 + v0640;
    const Scalar v0630 = v0627 + v0629;
    const Scalar v0619 = v0616 + v0618;
    const Scalar v0556 = v0553 + v0555;
    const Scalar v0545 = v0542 + v0544;
    const Scalar v0534 = v0531 + v0533;
    const Scalar v0467 = v0464 + v0466;
    const Scalar v0456 = v0453 + v0455;
    const Scalar v0445 = v0442 + v0444;
    _d1(0, 0) = v0445;
    _d1(0, 1) = v0456;
    _d1(0, 2) = v0467;
    _d1(1, 0) = v0534;
    _d1(1, 1) = v0545;
    _d1(1, 2) = v0556;
    _d1(2, 0) = v0619;
    _d1(2, 1) = v0630;
    _d1(2, 2) = v0641;
  }
  const Scalar v0071 = v0044 * v0068;
  const Scalar v0058 = v0044 * v0055;
  const Scalar v0045 = v0036 * v0044;
  const Scalar v0072 = v0041 * v0071;
  const Scalar v0059 = v0041 * v0058;
  const Scalar v0046 = v0041 * v0045;
  _out(0, 0) = v0046;
  _out(1, 0) = v0059;
  _out(2, 0) = v0072;
}

} // namespace gen