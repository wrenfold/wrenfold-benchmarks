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
  // multiply: 187
  // negate: 6
  // total: 298
  
  const Scalar v00010 = _q1_xyzw(1, 0);
  const Scalar v00006 = _q0_xyzw(1, 0);
  const Scalar v00013 = _q1_xyzw(0, 0);
  const Scalar v00002 = _q0_xyzw(0, 0);
  const Scalar v00018 = v00006 * v00010;
  const Scalar v00017 = v00002 * v00013;
  const Scalar v00009 = _q0_xyzw(2, 0);
  const Scalar v00007 = _q1_xyzw(2, 0);
  const Scalar v01033 = v00017 + v00018;
  const Scalar v00019 = v00007 * v00009;
  const Scalar v00012 = _q0_xyzw(3, 0);
  const Scalar v00003 = _q1_xyzw(3, 0);
  const Scalar v01034 = v00019 + v01033;
  const Scalar v00020 = v00003 * v00012;
  const Scalar v01035 = v00020 + v01034;
  const bool v00024 = static_cast<Scalar>(0) <= v01035;
  std::int64_t v00025;
  if (v00024) {
    v00025 = 1;
  } else {
    v00025 = -1;
  }
  const Scalar v00026 = static_cast<Scalar>(v00025);
  const Scalar v00027 = v00026 * v01035;
  const bool v00029 = static_cast<Scalar>(1) < v00027;
  Scalar v00030;
  if (v00029) {
    v00030 = static_cast<Scalar>(1);
  } else {
    v00030 = v00027;
  }
  const Scalar v01045 = -v00030;
  const Scalar v01028 = v00030 * v01045;
  const Scalar v00032 = static_cast<Scalar>(1) + v01028;
  const Scalar v00033 = std::sqrt(v00032);
  const Scalar v01029 = v00033 * v00033;
  const Scalar v00263 = v00003 * v00009;
  const Scalar v00262 = v00002 * v00010;
  const Scalar v00035 = std::acos(v00030);
  const Scalar v01030 = v00033 * v01029;
  const Scalar v00258 = v00009 * v00013;
  const Scalar v00257 = v00003 * v00006;
  const Scalar v00253 = v00006 * v00007;
  const Scalar v00252 = v00002 * v00003;
  const Scalar v00264 = v00262 + v00263;
  const Scalar v00047 = v00007 * v00012;
  const Scalar v00046 = v00006 * v00013;
  const Scalar v00052 = static_cast<Scalar>(1) / v00032;
  const Scalar v01031 = v00030 * v00035;
  const Scalar v00060 = static_cast<Scalar>(1) / v01030;
  const Scalar v00259 = v00257 + v00258;
  const Scalar v00041 = v00010 * v00012;
  const Scalar v00040 = v00002 * v00007;
  const Scalar v00254 = v00252 + v00253;
  const Scalar v00014 = v00012 * v00013;
  const Scalar v00011 = v00009 * v00010;
  const Scalar v01044 = -v00264;
  const Scalar v01040 = v00046 + v00047;
  const Scalar v01046 = -v00052;
  const Scalar v01032 = v00060 * v01031;
  const Scalar v00034 = static_cast<Scalar>(1) / v00033;
  const Scalar v01043 = -v00259;
  const Scalar v01038 = v00040 + v00041;
  const Scalar v01042 = -v00254;
  const Scalar v01036 = v00011 + v00014;
  const Scalar v01041 = v01040 + v01044;
  const Scalar v00269 = v01032 + v01046;
  const Scalar v00797 = v00034 * v00035;
  const Scalar v01039 = v01038 + v01043;
  const Scalar v01037 = v01036 + v01042;
  const Scalar v00789 = v00026 * static_cast<Scalar>(2);
  const Scalar v00071 = static_cast<Scalar>(0.5);
  const Scalar v00051 = static_cast<Scalar>(-0.5);
  const Scalar v00840 = v00269 * v01041;
  const Scalar v01047 = -v00797;
  const Scalar v00839 = v00269 * v01039;
  const Scalar v00838 = v00269 * v01037;
  const Scalar v00796 = v00071 * v00789;
  const Scalar v00794 = v00051 * v00789;
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
    const Scalar v00586 = v00065 * v00840;
    const Scalar v00561 = v00003 * v01047;
    const Scalar v00594 = v00081 * v00840;
    const Scalar v00593 = v00010 * v01047;
    const Scalar v00985 = v00007 * v00797;
    const Scalar v00582 = v00054 * v00840;
    const Scalar v01010 = v00013 * v00797;
    const Scalar v00590 = v00074 * v00840;
    const Scalar v00570 = v00065 * v00839;
    const Scalar v00569 = v00013 * v01047;
    const Scalar v00578 = v00081 * v00839;
    const Scalar v01000 = v00010 * v00797;
    const Scalar v00566 = v00054 * v00839;
    const Scalar v00574 = v00074 * v00839;
    const Scalar v00554 = v00065 * v00838;
    const Scalar v00562 = v00081 * v00838;
    const Scalar v00550 = v00054 * v00838;
    const Scalar v00558 = v00074 * v00838;
    const Scalar v00557 = v00007 * v01047;
    const Scalar v00587 = v00561 + v00586;
    const Scalar v00595 = v00593 + v00594;
    const Scalar v00583 = v00582 + v00985;
    const Scalar v00591 = v00590 + v01010;
    const Scalar v00571 = v00569 + v00570;
    const Scalar v00579 = v00578 + v00985;
    const Scalar v00567 = v00566 + v01000;
    const Scalar v00575 = v00561 + v00574;
    const Scalar v00555 = v00554 + v01000;
    const Scalar v00563 = v00561 + v00562;
    const Scalar v00551 = v00550 + v01010;
    const Scalar v00559 = v00557 + v00558;
    const Scalar v00714 = v00012 * v00587;
    const Scalar v00713 = v00006 * v00595;
    const Scalar v00702 = v00009 * v00583;
    const Scalar v00701 = v00002 * v00591;
    const Scalar v00698 = v00012 * v00591;
    const Scalar v00697 = v00002 * v00587;
    const Scalar v00710 = v00009 * v00595;
    const Scalar v00709 = v00006 * v00583;
    const Scalar v00706 = v00012 * v00595;
    const Scalar v00705 = v00009 * v00591;
    const Scalar v00694 = v00006 * v00587;
    const Scalar v00693 = v00002 * v00583;
    const Scalar v00690 = v00012 * v00571;
    const Scalar v00689 = v00006 * v00579;
    const Scalar v00678 = v00009 * v00567;
    const Scalar v00677 = v00002 * v00575;
    const Scalar v00674 = v00012 * v00575;
    const Scalar v00673 = v00002 * v00571;
    const Scalar v00686 = v00009 * v00579;
    const Scalar v00685 = v00006 * v00567;
    const Scalar v00682 = v00012 * v00579;
    const Scalar v00681 = v00009 * v00575;
    const Scalar v00670 = v00006 * v00571;
    const Scalar v00669 = v00002 * v00567;
    const Scalar v00666 = v00012 * v00555;
    const Scalar v00665 = v00006 * v00563;
    const Scalar v00654 = v00009 * v00551;
    const Scalar v00653 = v00002 * v00559;
    const Scalar v00650 = v00012 * v00559;
    const Scalar v00649 = v00002 * v00555;
    const Scalar v00662 = v00009 * v00563;
    const Scalar v00661 = v00006 * v00551;
    const Scalar v00658 = v00012 * v00563;
    const Scalar v00657 = v00009 * v00559;
    const Scalar v00646 = v00006 * v00555;
    const Scalar v00645 = v00002 * v00551;
    const Scalar v00715 = v00713 + v00714;
    const Scalar v00703 = v00701 + v00702;
    const Scalar v00699 = v00697 + v00698;
    const Scalar v00711 = v00709 + v00710;
    const Scalar v00707 = v00705 + v00706;
    const Scalar v00695 = v00693 + v00694;
    const Scalar v00691 = v00689 + v00690;
    const Scalar v00679 = v00677 + v00678;
    const Scalar v00675 = v00673 + v00674;
    const Scalar v00687 = v00685 + v00686;
    const Scalar v00683 = v00681 + v00682;
    const Scalar v00671 = v00669 + v00670;
    const Scalar v00667 = v00665 + v00666;
    const Scalar v00655 = v00653 + v00654;
    const Scalar v00651 = v00649 + v00650;
    const Scalar v00663 = v00661 + v00662;
    const Scalar v00659 = v00657 + v00658;
    const Scalar v00647 = v00645 + v00646;
    const Scalar v00406 = v00715 * v00796;
    const Scalar v00402 = v00703 * v00794;
    const Scalar v00397 = v00699 * v00796;
    const Scalar v00393 = v00711 * v00794;
    const Scalar v00388 = v00707 * v00796;
    const Scalar v00384 = v00695 * v00794;
    const Scalar v00359 = v00691 * v00796;
    const Scalar v00355 = v00679 * v00794;
    const Scalar v00350 = v00675 * v00796;
    const Scalar v00346 = v00687 * v00794;
    const Scalar v00341 = v00683 * v00796;
    const Scalar v00337 = v00671 * v00794;
    const Scalar v00312 = v00667 * v00796;
    const Scalar v00308 = v00655 * v00794;
    const Scalar v00303 = v00651 * v00796;
    const Scalar v00299 = v00663 * v00794;
    const Scalar v00294 = v00659 * v00796;
    const Scalar v00290 = v00647 * v00794;
    const Scalar v00407 = v00402 + v00406;
    const Scalar v00398 = v00393 + v00397;
    const Scalar v00389 = v00384 + v00388;
    const Scalar v00360 = v00355 + v00359;
    const Scalar v00351 = v00346 + v00350;
    const Scalar v00342 = v00337 + v00341;
    const Scalar v00313 = v00308 + v00312;
    const Scalar v00304 = v00299 + v00303;
    const Scalar v00295 = v00290 + v00294;
    _d0(0, 0) = v00295;
    _d0(0, 1) = v00304;
    _d0(0, 2) = v00313;
    _d0(1, 0) = v00342;
    _d0(1, 1) = v00351;
    _d0(1, 2) = v00360;
    _d0(2, 0) = v00389;
    _d0(2, 1) = v00398;
    _d0(2, 2) = v00407;
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
    const Scalar v00634 = v00164 * v00840;
    const Scalar v00609 = v00012 * v00797;
    const Scalar v00982 = v00006 * v00797;
    const Scalar v00642 = v00177 * v00840;
    const Scalar v00630 = v00157 * v00840;
    const Scalar v00625 = v00009 * v01047;
    const Scalar v00638 = v00170 * v00840;
    const Scalar v00597 = v00002 * v01047;
    const Scalar v00976 = v00002 * v00797;
    const Scalar v00618 = v00164 * v00839;
    const Scalar v00626 = v00177 * v00839;
    const Scalar v00614 = v00157 * v00839;
    const Scalar v00601 = v00006 * v01047;
    const Scalar v00622 = v00170 * v00839;
    const Scalar v00602 = v00164 * v00838;
    const Scalar v00610 = v00177 * v00838;
    const Scalar v00598 = v00157 * v00838;
    const Scalar v00996 = v00009 * v00797;
    const Scalar v00606 = v00170 * v00838;
    const Scalar v00635 = v00609 + v00634;
    const Scalar v00643 = v00642 + v00982;
    const Scalar v00631 = v00625 + v00630;
    const Scalar v00639 = v00597 + v00638;
    const Scalar v00619 = v00618 + v00976;
    const Scalar v00627 = v00625 + v00626;
    const Scalar v00615 = v00601 + v00614;
    const Scalar v00623 = v00609 + v00622;
    const Scalar v00603 = v00601 + v00602;
    const Scalar v00611 = v00609 + v00610;
    const Scalar v00599 = v00597 + v00598;
    const Scalar v00607 = v00606 + v00996;
    const Scalar v00786 = v00003 * v00635;
    const Scalar v00785 = v00010 * v00643;
    const Scalar v00774 = v00007 * v00631;
    const Scalar v00773 = v00013 * v00639;
    const Scalar v00770 = v00003 * v00639;
    const Scalar v00769 = v00013 * v00635;
    const Scalar v00782 = v00007 * v00643;
    const Scalar v00781 = v00010 * v00631;
    const Scalar v00778 = v00003 * v00643;
    const Scalar v00777 = v00007 * v00639;
    const Scalar v00766 = v00010 * v00635;
    const Scalar v00765 = v00013 * v00631;
    const Scalar v00762 = v00003 * v00619;
    const Scalar v00761 = v00010 * v00627;
    const Scalar v00750 = v00007 * v00615;
    const Scalar v00749 = v00013 * v00623;
    const Scalar v00746 = v00003 * v00623;
    const Scalar v00745 = v00013 * v00619;
    const Scalar v00758 = v00007 * v00627;
    const Scalar v00757 = v00010 * v00615;
    const Scalar v00754 = v00003 * v00627;
    const Scalar v00753 = v00007 * v00623;
    const Scalar v00742 = v00010 * v00619;
    const Scalar v00741 = v00013 * v00615;
    const Scalar v00738 = v00003 * v00603;
    const Scalar v00737 = v00010 * v00611;
    const Scalar v00726 = v00007 * v00599;
    const Scalar v00725 = v00013 * v00607;
    const Scalar v00722 = v00003 * v00607;
    const Scalar v00721 = v00013 * v00603;
    const Scalar v00734 = v00007 * v00611;
    const Scalar v00733 = v00010 * v00599;
    const Scalar v00730 = v00003 * v00611;
    const Scalar v00729 = v00007 * v00607;
    const Scalar v00718 = v00010 * v00603;
    const Scalar v00717 = v00013 * v00599;
    const Scalar v00787 = v00785 + v00786;
    const Scalar v00775 = v00773 + v00774;
    const Scalar v00771 = v00769 + v00770;
    const Scalar v00783 = v00781 + v00782;
    const Scalar v00779 = v00777 + v00778;
    const Scalar v00767 = v00765 + v00766;
    const Scalar v00763 = v00761 + v00762;
    const Scalar v00751 = v00749 + v00750;
    const Scalar v00747 = v00745 + v00746;
    const Scalar v00759 = v00757 + v00758;
    const Scalar v00755 = v00753 + v00754;
    const Scalar v00743 = v00741 + v00742;
    const Scalar v00739 = v00737 + v00738;
    const Scalar v00727 = v00725 + v00726;
    const Scalar v00723 = v00721 + v00722;
    const Scalar v00735 = v00733 + v00734;
    const Scalar v00731 = v00729 + v00730;
    const Scalar v00719 = v00717 + v00718;
    const Scalar v00547 = v00787 * v00796;
    const Scalar v00543 = v00775 * v00794;
    const Scalar v00538 = v00771 * v00796;
    const Scalar v00534 = v00783 * v00794;
    const Scalar v00529 = v00779 * v00796;
    const Scalar v00525 = v00767 * v00794;
    const Scalar v00500 = v00763 * v00796;
    const Scalar v00496 = v00751 * v00794;
    const Scalar v00491 = v00747 * v00796;
    const Scalar v00487 = v00759 * v00794;
    const Scalar v00482 = v00755 * v00796;
    const Scalar v00478 = v00743 * v00794;
    const Scalar v00453 = v00739 * v00796;
    const Scalar v00449 = v00727 * v00794;
    const Scalar v00444 = v00723 * v00796;
    const Scalar v00440 = v00735 * v00794;
    const Scalar v00435 = v00731 * v00796;
    const Scalar v00431 = v00719 * v00794;
    const Scalar v00548 = v00543 + v00547;
    const Scalar v00539 = v00534 + v00538;
    const Scalar v00530 = v00525 + v00529;
    const Scalar v00501 = v00496 + v00500;
    const Scalar v00492 = v00487 + v00491;
    const Scalar v00483 = v00478 + v00482;
    const Scalar v00454 = v00449 + v00453;
    const Scalar v00445 = v00440 + v00444;
    const Scalar v00436 = v00431 + v00435;
    _d1(0, 0) = v00436;
    _d1(0, 1) = v00445;
    _d1(0, 2) = v00454;
    _d1(1, 0) = v00483;
    _d1(1, 1) = v00492;
    _d1(1, 2) = v00501;
    _d1(2, 0) = v00530;
    _d1(2, 1) = v00539;
    _d1(2, 2) = v00548;
  }
  const Scalar v00959 = v00789 * v00797;
  const Scalar v00049 = v00959 * v01041;
  const Scalar v00043 = v00959 * v01039;
  const Scalar v00037 = v00959 * v01037;
  _out(0, 0) = v00037;
  _out(1, 0) = v00043;
  _out(2, 0) = v00049;
}

} // namespace gen