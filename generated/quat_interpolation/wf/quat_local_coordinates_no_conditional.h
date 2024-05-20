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
  // add: 92
  // branch: 6
  // call: 2
  // compare: 2
  // divide: 3
  // multiply: 212
  // negate: 3
  // total: 320
  
  const Scalar v0008 = _q0_xyzw(1, 0);
  const Scalar v0005 = _q1_xyzw(1, 0);
  const Scalar v0012 = _q0_xyzw(0, 0);
  const Scalar v0002 = _q1_xyzw(0, 0);
  const Scalar v0018 = v0005 * v0008;
  const Scalar v0017 = v0002 * v0012;
  const Scalar v0009 = _q1_xyzw(2, 0);
  const Scalar v0004 = _q0_xyzw(2, 0);
  const Scalar v0657 = v0017 + v0018;
  const Scalar v0019 = v0004 * v0009;
  const Scalar v0013 = _q1_xyzw(3, 0);
  const Scalar v0001 = _q0_xyzw(3, 0);
  const Scalar v0658 = v0019 + v0657;
  const Scalar v0020 = v0001 * v0013;
  const Scalar v0659 = v0020 + v0658;
  const bool v0024 = static_cast<Scalar>(0) <= v0659;
  std::int64_t v0025;
  if (v0024) {
    v0025 = 1;
  } else {
    v0025 = -1;
  }
  const Scalar v0026 = static_cast<Scalar>(v0025);
  const Scalar v0027 = v0026 * v0659;
  const bool v0029 = static_cast<Scalar>(1) < v0027;
  Scalar v0030;
  if (v0029) {
    v0030 = static_cast<Scalar>(1);
  } else {
    v0030 = v0027;
  }
  const Scalar v0031 = v0030 * v0030;
  const Scalar v0666 = -v0031;
  const Scalar v0033 = static_cast<Scalar>(1) + v0666;
  const Scalar v0034 = std::sqrt(v0033);
  const Scalar v0267 = v0004 * v0013;
  const Scalar v0266 = v0005 * v0012;
  const Scalar v0261 = v0008 * v0013;
  const Scalar v0260 = v0002 * v0004;
  const Scalar v0255 = v0012 * v0013;
  const Scalar v0254 = v0008 * v0009;
  const Scalar v0058 = v0034 * v0034;
  const Scalar v0047 = v0001 * v0009;
  const Scalar v0045 = v0002 * v0008;
  const Scalar v0268 = v0266 + v0267;
  const Scalar v0041 = v0009 * v0012;
  const Scalar v0040 = v0001 * v0005;
  const Scalar v0262 = v0260 + v0261;
  const Scalar v0006 = v0004 * v0005;
  const Scalar v0003 = v0001 * v0002;
  const Scalar v0256 = v0254 + v0255;
  const Scalar v0036 = std::acos(v0030);
  const Scalar v0059 = v0034 * v0058;
  const Scalar v0035 = static_cast<Scalar>(1) / v0034;
  const Scalar v0664 = v0045 + v0047;
  const Scalar v0269 = static_cast<Scalar>(-1) * v0268;
  const Scalar v0662 = v0040 + v0041;
  const Scalar v0263 = static_cast<Scalar>(-1) * v0262;
  const Scalar v0660 = v0003 + v0006;
  const Scalar v0257 = static_cast<Scalar>(-1) * v0256;
  const Scalar v0053 = static_cast<Scalar>(1) / v0033;
  const Scalar v0655 = v0030 * v0036;
  const Scalar v0060 = static_cast<Scalar>(1) / v0059;
  const Scalar v0614 = v0035 * v0036;
  const Scalar v0613 = v0026 * static_cast<Scalar>(2);
  const Scalar v0665 = v0269 + v0664;
  const Scalar v0663 = v0263 + v0662;
  const Scalar v0661 = v0257 + v0660;
  const Scalar v0667 = -v0053;
  const Scalar v0656 = v0060 * v0655;
  const Scalar v0615 = v0613 * v0614;
  const Scalar v0072 = static_cast<Scalar>(-0.5);
  const Scalar v0052 = static_cast<Scalar>(0.5);
  const Scalar v0618 = v0613 * v0665;
  const Scalar v0617 = v0613 * v0663;
  const Scalar v0616 = v0613 * v0661;
  const Scalar v0274 = v0656 + v0667;
  const Scalar v0668 = -v0615;
  if (static_cast<bool>(_d0)) {
    Scalar v0055;
    Scalar v0066;
    Scalar v0074;
    Scalar v0081;
    if (v0029) {
      v0055 = static_cast<Scalar>(0);
      v0066 = static_cast<Scalar>(0);
      v0074 = static_cast<Scalar>(0);
      v0081 = static_cast<Scalar>(0);
    } else {
      v0055 = v0002 * v0026;
      v0066 = v0005 * v0026;
      v0074 = v0009 * v0026;
      v0081 = v0013 * v0026;
    }
    const Scalar v0639 = v0081 * v0618;
    const Scalar v0633 = v0066 * v0618;
    const Scalar v0636 = v0074 * v0618;
    const Scalar v0630 = v0055 * v0618;
    const Scalar v0638 = v0081 * v0617;
    const Scalar v0632 = v0066 * v0617;
    const Scalar v0635 = v0074 * v0617;
    const Scalar v0629 = v0055 * v0617;
    const Scalar v0637 = v0081 * v0616;
    const Scalar v0631 = v0066 * v0616;
    const Scalar v0634 = v0074 * v0616;
    const Scalar v0628 = v0055 * v0616;
    const Scalar v0401 = v0274 * v0639;
    const Scalar v0100 = v0009 * v0615;
    const Scalar v0389 = v0274 * v0633;
    const Scalar v0084 = v0002 * v0615;
    const Scalar v0627 = v0013 * v0668;
    const Scalar v0407 = v0274 * v0636;
    const Scalar v0623 = v0005 * v0668;
    const Scalar v0395 = v0274 * v0630;
    const Scalar v0350 = v0274 * v0638;
    const Scalar v0077 = v0005 * v0615;
    const Scalar v0338 = v0274 * v0632;
    const Scalar v0621 = v0002 * v0668;
    const Scalar v0344 = v0274 * v0635;
    const Scalar v0332 = v0274 * v0629;
    const Scalar v0293 = v0274 * v0637;
    const Scalar v0625 = v0009 * v0668;
    const Scalar v0281 = v0274 * v0631;
    const Scalar v0287 = v0274 * v0634;
    const Scalar v0275 = v0274 * v0628;
    const Scalar v0402 = v0100 + v0401;
    const Scalar v0390 = v0084 + v0389;
    const Scalar v0408 = v0407 + v0627;
    const Scalar v0396 = v0395 + v0623;
    const Scalar v0351 = v0077 + v0350;
    const Scalar v0339 = v0338 + v0627;
    const Scalar v0345 = v0344 + v0621;
    const Scalar v0333 = v0100 + v0332;
    const Scalar v0294 = v0084 + v0293;
    const Scalar v0282 = v0281 + v0625;
    const Scalar v0288 = v0077 + v0287;
    const Scalar v0276 = v0275 + v0627;
    const Scalar v0438 = v0004 * v0402;
    const Scalar v0437 = v0012 * v0390;
    const Scalar v0433 = v0001 * v0408;
    const Scalar v0432 = v0008 * v0396;
    const Scalar v0427 = v0004 * v0396;
    const Scalar v0426 = v0008 * v0402;
    const Scalar v0422 = v0001 * v0390;
    const Scalar v0421 = v0012 * v0408;
    const Scalar v0416 = v0008 * v0408;
    const Scalar v0415 = v0012 * v0402;
    const Scalar v0411 = v0001 * v0396;
    const Scalar v0410 = v0004 * v0390;
    const Scalar v0381 = v0004 * v0351;
    const Scalar v0380 = v0012 * v0339;
    const Scalar v0376 = v0001 * v0345;
    const Scalar v0375 = v0008 * v0333;
    const Scalar v0370 = v0012 * v0345;
    const Scalar v0369 = v0001 * v0339;
    const Scalar v0365 = v0008 * v0351;
    const Scalar v0364 = v0004 * v0333;
    const Scalar v0359 = v0012 * v0351;
    const Scalar v0358 = v0008 * v0345;
    const Scalar v0354 = v0004 * v0339;
    const Scalar v0353 = v0001 * v0333;
    const Scalar v0324 = v0004 * v0294;
    const Scalar v0323 = v0012 * v0282;
    const Scalar v0319 = v0001 * v0288;
    const Scalar v0318 = v0008 * v0276;
    const Scalar v0313 = v0008 * v0294;
    const Scalar v0312 = v0004 * v0276;
    const Scalar v0308 = v0012 * v0288;
    const Scalar v0307 = v0001 * v0282;
    const Scalar v0302 = v0012 * v0294;
    const Scalar v0301 = v0008 * v0288;
    const Scalar v0297 = v0004 * v0282;
    const Scalar v0296 = v0001 * v0276;
    const Scalar v0439 = v0437 + v0438;
    const Scalar v0434 = v0432 + v0433;
    const Scalar v0428 = v0426 + v0427;
    const Scalar v0423 = v0421 + v0422;
    const Scalar v0417 = v0415 + v0416;
    const Scalar v0412 = v0410 + v0411;
    const Scalar v0382 = v0380 + v0381;
    const Scalar v0377 = v0375 + v0376;
    const Scalar v0371 = v0369 + v0370;
    const Scalar v0366 = v0364 + v0365;
    const Scalar v0360 = v0358 + v0359;
    const Scalar v0355 = v0353 + v0354;
    const Scalar v0325 = v0323 + v0324;
    const Scalar v0320 = v0318 + v0319;
    const Scalar v0314 = v0312 + v0313;
    const Scalar v0309 = v0307 + v0308;
    const Scalar v0303 = v0301 + v0302;
    const Scalar v0298 = v0296 + v0297;
    const Scalar v0440 = v0072 * v0439;
    const Scalar v0435 = v0052 * v0434;
    const Scalar v0429 = v0072 * v0428;
    const Scalar v0424 = v0052 * v0423;
    const Scalar v0418 = v0072 * v0417;
    const Scalar v0413 = v0052 * v0412;
    const Scalar v0383 = v0072 * v0382;
    const Scalar v0378 = v0052 * v0377;
    const Scalar v0372 = v0052 * v0371;
    const Scalar v0367 = v0072 * v0366;
    const Scalar v0361 = v0072 * v0360;
    const Scalar v0356 = v0052 * v0355;
    const Scalar v0326 = v0072 * v0325;
    const Scalar v0321 = v0052 * v0320;
    const Scalar v0315 = v0072 * v0314;
    const Scalar v0310 = v0052 * v0309;
    const Scalar v0304 = v0072 * v0303;
    const Scalar v0299 = v0052 * v0298;
    const Scalar v0441 = v0435 + v0440;
    const Scalar v0430 = v0424 + v0429;
    const Scalar v0419 = v0413 + v0418;
    const Scalar v0384 = v0378 + v0383;
    const Scalar v0373 = v0367 + v0372;
    const Scalar v0362 = v0356 + v0361;
    const Scalar v0327 = v0321 + v0326;
    const Scalar v0316 = v0310 + v0315;
    const Scalar v0305 = v0299 + v0304;
    _d0(0, 0) = v0305;
    _d0(0, 1) = v0316;
    _d0(0, 2) = v0327;
    _d0(1, 0) = v0362;
    _d0(1, 1) = v0373;
    _d0(1, 2) = v0384;
    _d0(2, 0) = v0419;
    _d0(2, 1) = v0430;
    _d0(2, 2) = v0441;
  }
  if (static_cast<bool>(_d1)) {
    Scalar v0157;
    Scalar v0164;
    Scalar v0171;
    Scalar v0178;
    if (v0029) {
      v0157 = static_cast<Scalar>(0);
      v0164 = static_cast<Scalar>(0);
      v0171 = static_cast<Scalar>(0);
      v0178 = static_cast<Scalar>(0);
    } else {
      v0157 = v0012 * v0026;
      v0164 = v0008 * v0026;
      v0171 = v0004 * v0026;
      v0178 = v0001 * v0026;
    }
    const Scalar v0651 = v0178 * v0618;
    const Scalar v0645 = v0164 * v0618;
    const Scalar v0648 = v0171 * v0618;
    const Scalar v0642 = v0157 * v0618;
    const Scalar v0650 = v0178 * v0617;
    const Scalar v0644 = v0164 * v0617;
    const Scalar v0647 = v0171 * v0617;
    const Scalar v0641 = v0157 * v0617;
    const Scalar v0649 = v0178 * v0616;
    const Scalar v0643 = v0164 * v0616;
    const Scalar v0646 = v0171 * v0616;
    const Scalar v0640 = v0157 * v0616;
    const Scalar v0622 = v0004 * v0668;
    const Scalar v0572 = v0274 * v0651;
    const Scalar v0626 = v0012 * v0668;
    const Scalar v0560 = v0274 * v0645;
    const Scalar v0620 = v0001 * v0615;
    const Scalar v0578 = v0274 * v0648;
    const Scalar v0566 = v0274 * v0642;
    const Scalar v0230 = v0008 * v0615;
    const Scalar v0624 = v0008 * v0668;
    const Scalar v0521 = v0274 * v0650;
    const Scalar v0509 = v0274 * v0644;
    const Scalar v0515 = v0274 * v0647;
    const Scalar v0206 = v0012 * v0615;
    const Scalar v0503 = v0274 * v0641;
    const Scalar v0464 = v0274 * v0649;
    const Scalar v0452 = v0274 * v0643;
    const Scalar v0167 = v0004 * v0615;
    const Scalar v0458 = v0274 * v0646;
    const Scalar v0446 = v0274 * v0640;
    const Scalar v0573 = v0572 + v0622;
    const Scalar v0561 = v0560 + v0626;
    const Scalar v0579 = v0578 + v0620;
    const Scalar v0567 = v0230 + v0566;
    const Scalar v0522 = v0521 + v0624;
    const Scalar v0510 = v0509 + v0620;
    const Scalar v0516 = v0206 + v0515;
    const Scalar v0504 = v0503 + v0622;
    const Scalar v0465 = v0464 + v0626;
    const Scalar v0453 = v0167 + v0452;
    const Scalar v0459 = v0458 + v0624;
    const Scalar v0447 = v0446 + v0620;
    const Scalar v0609 = v0009 * v0573;
    const Scalar v0608 = v0002 * v0561;
    const Scalar v0604 = v0013 * v0579;
    const Scalar v0603 = v0005 * v0567;
    const Scalar v0598 = v0009 * v0567;
    const Scalar v0597 = v0005 * v0573;
    const Scalar v0593 = v0013 * v0561;
    const Scalar v0592 = v0002 * v0579;
    const Scalar v0587 = v0005 * v0579;
    const Scalar v0586 = v0002 * v0573;
    const Scalar v0582 = v0013 * v0567;
    const Scalar v0581 = v0009 * v0561;
    const Scalar v0552 = v0009 * v0522;
    const Scalar v0551 = v0002 * v0510;
    const Scalar v0547 = v0013 * v0516;
    const Scalar v0546 = v0005 * v0504;
    const Scalar v0541 = v0002 * v0516;
    const Scalar v0540 = v0013 * v0510;
    const Scalar v0536 = v0005 * v0522;
    const Scalar v0535 = v0009 * v0504;
    const Scalar v0530 = v0002 * v0522;
    const Scalar v0529 = v0005 * v0516;
    const Scalar v0525 = v0009 * v0510;
    const Scalar v0524 = v0013 * v0504;
    const Scalar v0495 = v0009 * v0465;
    const Scalar v0494 = v0002 * v0453;
    const Scalar v0490 = v0013 * v0459;
    const Scalar v0489 = v0005 * v0447;
    const Scalar v0484 = v0005 * v0465;
    const Scalar v0483 = v0009 * v0447;
    const Scalar v0479 = v0002 * v0459;
    const Scalar v0478 = v0013 * v0453;
    const Scalar v0473 = v0002 * v0465;
    const Scalar v0472 = v0005 * v0459;
    const Scalar v0468 = v0009 * v0453;
    const Scalar v0467 = v0013 * v0447;
    const Scalar v0610 = v0608 + v0609;
    const Scalar v0605 = v0603 + v0604;
    const Scalar v0599 = v0597 + v0598;
    const Scalar v0594 = v0592 + v0593;
    const Scalar v0588 = v0586 + v0587;
    const Scalar v0583 = v0581 + v0582;
    const Scalar v0553 = v0551 + v0552;
    const Scalar v0548 = v0546 + v0547;
    const Scalar v0542 = v0540 + v0541;
    const Scalar v0537 = v0535 + v0536;
    const Scalar v0531 = v0529 + v0530;
    const Scalar v0526 = v0524 + v0525;
    const Scalar v0496 = v0494 + v0495;
    const Scalar v0491 = v0489 + v0490;
    const Scalar v0485 = v0483 + v0484;
    const Scalar v0480 = v0478 + v0479;
    const Scalar v0474 = v0472 + v0473;
    const Scalar v0469 = v0467 + v0468;
    const Scalar v0611 = v0072 * v0610;
    const Scalar v0606 = v0052 * v0605;
    const Scalar v0600 = v0072 * v0599;
    const Scalar v0595 = v0052 * v0594;
    const Scalar v0589 = v0072 * v0588;
    const Scalar v0584 = v0052 * v0583;
    const Scalar v0554 = v0072 * v0553;
    const Scalar v0549 = v0052 * v0548;
    const Scalar v0543 = v0052 * v0542;
    const Scalar v0538 = v0072 * v0537;
    const Scalar v0532 = v0072 * v0531;
    const Scalar v0527 = v0052 * v0526;
    const Scalar v0497 = v0072 * v0496;
    const Scalar v0492 = v0052 * v0491;
    const Scalar v0486 = v0072 * v0485;
    const Scalar v0481 = v0052 * v0480;
    const Scalar v0475 = v0072 * v0474;
    const Scalar v0470 = v0052 * v0469;
    const Scalar v0612 = v0606 + v0611;
    const Scalar v0601 = v0595 + v0600;
    const Scalar v0590 = v0584 + v0589;
    const Scalar v0555 = v0549 + v0554;
    const Scalar v0544 = v0538 + v0543;
    const Scalar v0533 = v0527 + v0532;
    const Scalar v0498 = v0492 + v0497;
    const Scalar v0487 = v0481 + v0486;
    const Scalar v0476 = v0470 + v0475;
    _d1(0, 0) = v0476;
    _d1(0, 1) = v0487;
    _d1(0, 2) = v0498;
    _d1(1, 0) = v0533;
    _d1(1, 1) = v0544;
    _d1(1, 2) = v0555;
    _d1(2, 0) = v0590;
    _d1(2, 1) = v0601;
    _d1(2, 2) = v0612;
  }
  const Scalar v0654 = v0615 * v0665;
  const Scalar v0653 = v0615 * v0663;
  const Scalar v0652 = v0615 * v0661;
  _out(0, 0) = v0652;
  _out(1, 0) = v0653;
  _out(2, 0) = v0654;
}

} // namespace gen