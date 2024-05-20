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
  // add: 92
  // branch: 9
  // call: 2
  // compare: 3
  // divide: 3
  // multiply: 225
  // negate: 3
  // total: 337
  
  const Scalar v0007 = _q0_xyzw(1, 0);
  const Scalar v0004 = _q1_xyzw(1, 0);
  const Scalar v0011 = _q0_xyzw(0, 0);
  const Scalar v0001 = _q1_xyzw(0, 0);
  const Scalar v0018 = v0004 * v0007;
  const Scalar v0017 = v0001 * v0011;
  const Scalar v0008 = _q1_xyzw(2, 0);
  const Scalar v0003 = _q0_xyzw(2, 0);
  const Scalar v0657 = v0017 + v0018;
  const Scalar v0019 = v0003 * v0008;
  const Scalar v0012 = _q1_xyzw(3, 0);
  const Scalar v0000 = _q0_xyzw(3, 0);
  const Scalar v0658 = v0019 + v0657;
  const Scalar v0020 = v0000 * v0012;
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
  const Scalar v0038 = std::acos(v0030);
  const bool v0035 = static_cast<Scalar>(1e-16) < v0034;
  Scalar v0041;
  if (v0035) {
    const Scalar v0037 = static_cast<Scalar>(1) / v0034;
    const Scalar v0653 = v0037 * v0038;
    v0041 = static_cast<Scalar>(2) * v0653;
  } else {
    v0041 = static_cast<Scalar>(2);
  }
  const Scalar v0063 = v0034 * v0034;
  const Scalar v0064 = v0034 * v0063;
  const Scalar v0279 = v0003 * v0012;
  const Scalar v0278 = v0004 * v0011;
  const Scalar v0273 = v0007 * v0012;
  const Scalar v0272 = v0001 * v0003;
  const Scalar v0267 = v0011 * v0012;
  const Scalar v0266 = v0007 * v0008;
  const Scalar v0058 = static_cast<Scalar>(1) / v0033;
  const Scalar v0655 = v0030 * v0038;
  const Scalar v0065 = static_cast<Scalar>(1) / v0064;
  const Scalar v0051 = v0000 * v0008;
  const Scalar v0049 = v0001 * v0007;
  const Scalar v0280 = v0278 + v0279;
  const Scalar v0045 = v0008 * v0011;
  const Scalar v0044 = v0000 * v0004;
  const Scalar v0274 = v0272 + v0273;
  const Scalar v0005 = v0003 * v0004;
  const Scalar v0002 = v0000 * v0001;
  const Scalar v0268 = v0266 + v0267;
  const Scalar v0667 = -v0058;
  const Scalar v0656 = v0065 * v0655;
  const Scalar v0664 = v0049 + v0051;
  const Scalar v0281 = static_cast<Scalar>(-1) * v0280;
  const Scalar v0662 = v0044 + v0045;
  const Scalar v0275 = static_cast<Scalar>(-1) * v0274;
  const Scalar v0660 = v0002 + v0005;
  const Scalar v0269 = static_cast<Scalar>(-1) * v0268;
  const Scalar v0082 = static_cast<Scalar>(-0.5);
  const Scalar v0056 = static_cast<Scalar>(0.5);
  const Scalar v0286 = v0656 + v0667;
  const Scalar v0665 = v0281 + v0664;
  const Scalar v0668 = -v0041;
  const Scalar v0663 = v0275 + v0662;
  const Scalar v0661 = v0269 + v0660;
  const Scalar v0288 = v0026;
  if (static_cast<bool>(_d0)) {
    Scalar v0068;
    Scalar v0078;
    Scalar v0089;
    Scalar v0099;
    if (v0035) {
      Scalar v0060;
      Scalar v0074;
      Scalar v0085;
      Scalar v0095;
      if (v0029) {
        v0060 = static_cast<Scalar>(0);
        v0074 = static_cast<Scalar>(0);
        v0085 = static_cast<Scalar>(0);
        v0095 = static_cast<Scalar>(0);
      } else {
        v0060 = v0004 * v0026;
        v0074 = v0001 * v0026;
        v0085 = v0012 * v0026;
        v0095 = v0008 * v0026;
      }
      const Scalar v0283 = static_cast<Scalar>(2) * v0060;
      const Scalar v0293 = static_cast<Scalar>(2) * v0074;
      const Scalar v0303 = static_cast<Scalar>(2) * v0085;
      const Scalar v0313 = static_cast<Scalar>(2) * v0095;
      v0068 = v0283 * v0286;
      v0078 = v0286 * v0293;
      v0089 = v0286 * v0303;
      v0099 = v0286 * v0313;
    } else {
      v0068 = static_cast<Scalar>(0);
      v0078 = static_cast<Scalar>(0);
      v0089 = static_cast<Scalar>(0);
      v0099 = static_cast<Scalar>(0);
    }
    const Scalar v0421 = v0089 * v0665;
    const Scalar v0357 = v0008 * v0041;
    const Scalar v0411 = v0068 * v0665;
    const Scalar v0309 = v0001 * v0041;
    const Scalar v0649 = v0012 * v0668;
    const Scalar v0426 = v0099 * v0665;
    const Scalar v0645 = v0004 * v0668;
    const Scalar v0416 = v0078 * v0665;
    const Scalar v0363 = v0068 * v0663;
    const Scalar v0373 = v0089 * v0663;
    const Scalar v0319 = v0004 * v0041;
    const Scalar v0358 = v0078 * v0663;
    const Scalar v0643 = v0001 * v0668;
    const Scalar v0368 = v0099 * v0663;
    const Scalar v0647 = v0008 * v0668;
    const Scalar v0290 = v0068 * v0661;
    const Scalar v0310 = v0089 * v0661;
    const Scalar v0300 = v0078 * v0661;
    const Scalar v0320 = v0099 * v0661;
    const Scalar v0422 = v0357 + v0421;
    const Scalar v0412 = v0309 + v0411;
    const Scalar v0427 = v0426 + v0649;
    const Scalar v0417 = v0416 + v0645;
    const Scalar v0364 = v0363 + v0649;
    const Scalar v0374 = v0319 + v0373;
    const Scalar v0359 = v0357 + v0358;
    const Scalar v0369 = v0368 + v0643;
    const Scalar v0291 = v0290 + v0647;
    const Scalar v0311 = v0309 + v0310;
    const Scalar v0301 = v0300 + v0649;
    const Scalar v0321 = v0319 + v0320;
    const Scalar v0423 = v0288 * v0422;
    const Scalar v0413 = v0288 * v0412;
    const Scalar v0428 = v0288 * v0427;
    const Scalar v0418 = v0288 * v0417;
    const Scalar v0365 = v0288 * v0364;
    const Scalar v0375 = v0288 * v0374;
    const Scalar v0360 = v0288 * v0359;
    const Scalar v0370 = v0288 * v0369;
    const Scalar v0292 = v0288 * v0291;
    const Scalar v0312 = v0288 * v0311;
    const Scalar v0302 = v0288 * v0301;
    const Scalar v0322 = v0288 * v0321;
    const Scalar v0458 = v0003 * v0423;
    const Scalar v0457 = v0011 * v0413;
    const Scalar v0453 = v0000 * v0428;
    const Scalar v0452 = v0007 * v0418;
    const Scalar v0447 = v0007 * v0423;
    const Scalar v0446 = v0003 * v0418;
    const Scalar v0442 = v0011 * v0428;
    const Scalar v0441 = v0000 * v0413;
    const Scalar v0436 = v0007 * v0428;
    const Scalar v0435 = v0011 * v0423;
    const Scalar v0431 = v0000 * v0418;
    const Scalar v0430 = v0003 * v0413;
    const Scalar v0405 = v0011 * v0365;
    const Scalar v0404 = v0003 * v0375;
    const Scalar v0400 = v0007 * v0360;
    const Scalar v0399 = v0000 * v0370;
    const Scalar v0394 = v0003 * v0360;
    const Scalar v0393 = v0007 * v0375;
    const Scalar v0389 = v0000 * v0365;
    const Scalar v0388 = v0011 * v0370;
    const Scalar v0383 = v0011 * v0375;
    const Scalar v0382 = v0007 * v0370;
    const Scalar v0378 = v0003 * v0365;
    const Scalar v0377 = v0000 * v0360;
    const Scalar v0352 = v0011 * v0292;
    const Scalar v0351 = v0003 * v0312;
    const Scalar v0347 = v0007 * v0302;
    const Scalar v0346 = v0000 * v0322;
    const Scalar v0341 = v0003 * v0302;
    const Scalar v0340 = v0007 * v0312;
    const Scalar v0336 = v0000 * v0292;
    const Scalar v0335 = v0011 * v0322;
    const Scalar v0330 = v0007 * v0322;
    const Scalar v0329 = v0011 * v0312;
    const Scalar v0325 = v0000 * v0302;
    const Scalar v0324 = v0003 * v0292;
    const Scalar v0459 = v0457 + v0458;
    const Scalar v0454 = v0452 + v0453;
    const Scalar v0448 = v0446 + v0447;
    const Scalar v0443 = v0441 + v0442;
    const Scalar v0437 = v0435 + v0436;
    const Scalar v0432 = v0430 + v0431;
    const Scalar v0406 = v0404 + v0405;
    const Scalar v0401 = v0399 + v0400;
    const Scalar v0395 = v0393 + v0394;
    const Scalar v0390 = v0388 + v0389;
    const Scalar v0384 = v0382 + v0383;
    const Scalar v0379 = v0377 + v0378;
    const Scalar v0353 = v0351 + v0352;
    const Scalar v0348 = v0346 + v0347;
    const Scalar v0342 = v0340 + v0341;
    const Scalar v0337 = v0335 + v0336;
    const Scalar v0331 = v0329 + v0330;
    const Scalar v0326 = v0324 + v0325;
    const Scalar v0460 = v0082 * v0459;
    const Scalar v0455 = v0056 * v0454;
    const Scalar v0449 = v0082 * v0448;
    const Scalar v0444 = v0056 * v0443;
    const Scalar v0438 = v0082 * v0437;
    const Scalar v0433 = v0056 * v0432;
    const Scalar v0407 = v0082 * v0406;
    const Scalar v0402 = v0056 * v0401;
    const Scalar v0396 = v0082 * v0395;
    const Scalar v0391 = v0056 * v0390;
    const Scalar v0385 = v0082 * v0384;
    const Scalar v0380 = v0056 * v0379;
    const Scalar v0354 = v0082 * v0353;
    const Scalar v0349 = v0056 * v0348;
    const Scalar v0343 = v0082 * v0342;
    const Scalar v0338 = v0056 * v0337;
    const Scalar v0332 = v0082 * v0331;
    const Scalar v0327 = v0056 * v0326;
    const Scalar v0461 = v0455 + v0460;
    const Scalar v0450 = v0444 + v0449;
    const Scalar v0439 = v0433 + v0438;
    const Scalar v0408 = v0402 + v0407;
    const Scalar v0397 = v0391 + v0396;
    const Scalar v0386 = v0380 + v0385;
    const Scalar v0355 = v0349 + v0354;
    const Scalar v0344 = v0338 + v0343;
    const Scalar v0333 = v0327 + v0332;
    _d0(0, 0) = v0333;
    _d0(0, 1) = v0344;
    _d0(0, 2) = v0355;
    _d0(1, 0) = v0386;
    _d0(1, 1) = v0397;
    _d0(1, 2) = v0408;
    _d0(2, 0) = v0439;
    _d0(2, 1) = v0450;
    _d0(2, 2) = v0461;
  }
  if (static_cast<bool>(_d1)) {
    Scalar v0170;
    Scalar v0180;
    Scalar v0190;
    Scalar v0200;
    if (v0035) {
      Scalar v0166;
      Scalar v0176;
      Scalar v0186;
      Scalar v0196;
      if (v0029) {
        v0166 = static_cast<Scalar>(0);
        v0176 = static_cast<Scalar>(0);
        v0186 = static_cast<Scalar>(0);
        v0196 = static_cast<Scalar>(0);
      } else {
        v0166 = v0007 * v0026;
        v0176 = v0011 * v0026;
        v0186 = v0000 * v0026;
        v0196 = v0003 * v0026;
      }
      const Scalar v0462 = static_cast<Scalar>(2) * v0166;
      const Scalar v0472 = static_cast<Scalar>(2) * v0176;
      const Scalar v0482 = static_cast<Scalar>(2) * v0186;
      const Scalar v0492 = static_cast<Scalar>(2) * v0196;
      v0170 = v0286 * v0462;
      v0180 = v0286 * v0472;
      v0190 = v0286 * v0482;
      v0200 = v0286 * v0492;
    } else {
      v0170 = static_cast<Scalar>(0);
      v0180 = static_cast<Scalar>(0);
      v0190 = static_cast<Scalar>(0);
      v0200 = static_cast<Scalar>(0);
    }
    const Scalar v0644 = v0003 * v0668;
    const Scalar v0600 = v0190 * v0665;
    const Scalar v0648 = v0011 * v0668;
    const Scalar v0590 = v0170 * v0665;
    const Scalar v0605 = v0200 * v0665;
    const Scalar v0478 = v0000 * v0041;
    const Scalar v0595 = v0180 * v0665;
    const Scalar v0594 = v0007 * v0041;
    const Scalar v0542 = v0170 * v0663;
    const Scalar v0646 = v0007 * v0668;
    const Scalar v0552 = v0190 * v0663;
    const Scalar v0537 = v0180 * v0663;
    const Scalar v0547 = v0200 * v0663;
    const Scalar v0546 = v0011 * v0041;
    const Scalar v0469 = v0170 * v0661;
    const Scalar v0468 = v0003 * v0041;
    const Scalar v0489 = v0190 * v0661;
    const Scalar v0479 = v0180 * v0661;
    const Scalar v0499 = v0200 * v0661;
    const Scalar v0601 = v0600 + v0644;
    const Scalar v0591 = v0590 + v0648;
    const Scalar v0606 = v0478 + v0605;
    const Scalar v0596 = v0594 + v0595;
    const Scalar v0543 = v0478 + v0542;
    const Scalar v0553 = v0552 + v0646;
    const Scalar v0538 = v0537 + v0644;
    const Scalar v0548 = v0546 + v0547;
    const Scalar v0470 = v0468 + v0469;
    const Scalar v0490 = v0489 + v0648;
    const Scalar v0480 = v0478 + v0479;
    const Scalar v0500 = v0499 + v0646;
    const Scalar v0602 = v0288 * v0601;
    const Scalar v0592 = v0288 * v0591;
    const Scalar v0607 = v0288 * v0606;
    const Scalar v0597 = v0288 * v0596;
    const Scalar v0544 = v0288 * v0543;
    const Scalar v0554 = v0288 * v0553;
    const Scalar v0539 = v0288 * v0538;
    const Scalar v0549 = v0288 * v0548;
    const Scalar v0471 = v0288 * v0470;
    const Scalar v0491 = v0288 * v0490;
    const Scalar v0481 = v0288 * v0480;
    const Scalar v0501 = v0288 * v0500;
    const Scalar v0637 = v0008 * v0602;
    const Scalar v0636 = v0001 * v0592;
    const Scalar v0632 = v0012 * v0607;
    const Scalar v0631 = v0004 * v0597;
    const Scalar v0626 = v0004 * v0602;
    const Scalar v0625 = v0008 * v0597;
    const Scalar v0621 = v0001 * v0607;
    const Scalar v0620 = v0012 * v0592;
    const Scalar v0615 = v0004 * v0607;
    const Scalar v0614 = v0001 * v0602;
    const Scalar v0610 = v0012 * v0597;
    const Scalar v0609 = v0008 * v0592;
    const Scalar v0584 = v0001 * v0544;
    const Scalar v0583 = v0008 * v0554;
    const Scalar v0579 = v0004 * v0539;
    const Scalar v0578 = v0012 * v0549;
    const Scalar v0573 = v0008 * v0539;
    const Scalar v0572 = v0004 * v0554;
    const Scalar v0568 = v0012 * v0544;
    const Scalar v0567 = v0001 * v0549;
    const Scalar v0562 = v0001 * v0554;
    const Scalar v0561 = v0004 * v0549;
    const Scalar v0557 = v0008 * v0544;
    const Scalar v0556 = v0012 * v0539;
    const Scalar v0531 = v0001 * v0471;
    const Scalar v0530 = v0008 * v0491;
    const Scalar v0526 = v0004 * v0481;
    const Scalar v0525 = v0012 * v0501;
    const Scalar v0520 = v0008 * v0481;
    const Scalar v0519 = v0004 * v0491;
    const Scalar v0515 = v0012 * v0471;
    const Scalar v0514 = v0001 * v0501;
    const Scalar v0509 = v0004 * v0501;
    const Scalar v0508 = v0001 * v0491;
    const Scalar v0504 = v0012 * v0481;
    const Scalar v0503 = v0008 * v0471;
    const Scalar v0638 = v0636 + v0637;
    const Scalar v0633 = v0631 + v0632;
    const Scalar v0627 = v0625 + v0626;
    const Scalar v0622 = v0620 + v0621;
    const Scalar v0616 = v0614 + v0615;
    const Scalar v0611 = v0609 + v0610;
    const Scalar v0585 = v0583 + v0584;
    const Scalar v0580 = v0578 + v0579;
    const Scalar v0574 = v0572 + v0573;
    const Scalar v0569 = v0567 + v0568;
    const Scalar v0563 = v0561 + v0562;
    const Scalar v0558 = v0556 + v0557;
    const Scalar v0532 = v0530 + v0531;
    const Scalar v0527 = v0525 + v0526;
    const Scalar v0521 = v0519 + v0520;
    const Scalar v0516 = v0514 + v0515;
    const Scalar v0510 = v0508 + v0509;
    const Scalar v0505 = v0503 + v0504;
    const Scalar v0639 = v0082 * v0638;
    const Scalar v0634 = v0056 * v0633;
    const Scalar v0628 = v0082 * v0627;
    const Scalar v0623 = v0056 * v0622;
    const Scalar v0617 = v0082 * v0616;
    const Scalar v0612 = v0056 * v0611;
    const Scalar v0586 = v0082 * v0585;
    const Scalar v0581 = v0056 * v0580;
    const Scalar v0575 = v0082 * v0574;
    const Scalar v0570 = v0056 * v0569;
    const Scalar v0564 = v0082 * v0563;
    const Scalar v0559 = v0056 * v0558;
    const Scalar v0533 = v0082 * v0532;
    const Scalar v0528 = v0056 * v0527;
    const Scalar v0522 = v0082 * v0521;
    const Scalar v0517 = v0056 * v0516;
    const Scalar v0511 = v0082 * v0510;
    const Scalar v0506 = v0056 * v0505;
    const Scalar v0640 = v0634 + v0639;
    const Scalar v0629 = v0623 + v0628;
    const Scalar v0618 = v0612 + v0617;
    const Scalar v0587 = v0581 + v0586;
    const Scalar v0576 = v0570 + v0575;
    const Scalar v0565 = v0559 + v0564;
    const Scalar v0534 = v0528 + v0533;
    const Scalar v0523 = v0517 + v0522;
    const Scalar v0512 = v0506 + v0511;
    _d1(0, 0) = v0512;
    _d1(0, 1) = v0523;
    _d1(0, 2) = v0534;
    _d1(1, 0) = v0565;
    _d1(1, 1) = v0576;
    _d1(1, 2) = v0587;
    _d1(2, 0) = v0618;
    _d1(2, 1) = v0629;
    _d1(2, 2) = v0640;
  }
  const Scalar v0642 = v0026 * v0041;
  const Scalar v0652 = v0642 * v0665;
  const Scalar v0651 = v0642 * v0663;
  const Scalar v0650 = v0642 * v0661;
  _out(0, 0) = v0650;
  _out(1, 0) = v0651;
  _out(2, 0) = v0652;
}

} // namespace gen