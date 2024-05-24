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
  // multiply: 209
  // negate: 6
  // total: 324
  
  const Scalar v0009 = _q1_xyzw(1, 0);
  const Scalar v0005 = _q0_xyzw(1, 0);
  const Scalar v0012 = _q1_xyzw(0, 0);
  const Scalar v0001 = _q0_xyzw(0, 0);
  const Scalar v0018 = v0005 * v0009;
  const Scalar v0017 = v0001 * v0012;
  const Scalar v0008 = _q0_xyzw(2, 0);
  const Scalar v0006 = _q1_xyzw(2, 0);
  const Scalar v0802 = v0017 + v0018;
  const Scalar v0019 = v0006 * v0008;
  const Scalar v0011 = _q0_xyzw(3, 0);
  const Scalar v0002 = _q1_xyzw(3, 0);
  const Scalar v0803 = v0019 + v0802;
  const Scalar v0020 = v0002 * v0011;
  const Scalar v0804 = v0020 + v0803;
  const bool v0024 = static_cast<Scalar>(0) <= v0804;
  std::int64_t v0025;
  if (v0024) {
    v0025 = 1;
  } else {
    v0025 = -1;
  }
  const Scalar v0026 = static_cast<Scalar>(v0025);
  const Scalar v0027 = v0026 * v0804;
  const bool v0029 = static_cast<Scalar>(1) < v0027;
  Scalar v0030;
  if (v0029) {
    v0030 = static_cast<Scalar>(1);
  } else {
    v0030 = v0027;
  }
  const Scalar v0814 = -v0030;
  const Scalar v0795 = v0030 * v0814;
  const Scalar v0032 = static_cast<Scalar>(1) + v0795;
  const Scalar v0033 = std::sqrt(v0032);
  const Scalar v0037 = std::acos(v0030);
  const bool v0034 = static_cast<Scalar>(1e-16) < v0033;
  Scalar v0040;
  if (v0034) {
    const Scalar v0036 = static_cast<Scalar>(1) / v0033;
    const Scalar v0796 = v0036 * v0037;
    v0040 = static_cast<Scalar>(2) * v0796;
  } else {
    v0040 = static_cast<Scalar>(2);
  }
  const Scalar v0798 = v0033 * v0033;
  const Scalar v0799 = v0033 * v0798;
  const Scalar v0057 = static_cast<Scalar>(1) / v0032;
  const Scalar v0800 = v0030 * v0037;
  const Scalar v0064 = static_cast<Scalar>(1) / v0799;
  const Scalar v0275 = v0002 * v0008;
  const Scalar v0274 = v0001 * v0009;
  const Scalar v0270 = v0008 * v0012;
  const Scalar v0269 = v0002 * v0005;
  const Scalar v0265 = v0005 * v0006;
  const Scalar v0264 = v0001 * v0002;
  const Scalar v0815 = -v0057;
  const Scalar v0801 = v0064 * v0800;
  const Scalar v0276 = v0274 + v0275;
  const Scalar v0051 = v0006 * v0011;
  const Scalar v0050 = v0005 * v0012;
  const Scalar v0271 = v0269 + v0270;
  const Scalar v0045 = v0009 * v0011;
  const Scalar v0044 = v0001 * v0006;
  const Scalar v0266 = v0264 + v0265;
  const Scalar v0013 = v0011 * v0012;
  const Scalar v0010 = v0008 * v0009;
  const Scalar v0281 = v0801 + v0815;
  const Scalar v0813 = -v0276;
  const Scalar v0809 = v0050 + v0051;
  const Scalar v0812 = -v0271;
  const Scalar v0807 = v0044 + v0045;
  const Scalar v0811 = -v0266;
  const Scalar v0805 = v0010 + v0013;
  const Scalar v0785 = static_cast<Scalar>(2) * v0281;
  const Scalar v0810 = v0809 + v0813;
  const Scalar v0816 = -v0040;
  const Scalar v0808 = v0807 + v0812;
  const Scalar v0806 = v0805 + v0811;
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
    const Scalar v0386 = v0077 * v0810;
    const Scalar v0307 = v0002 * v0816;
    const Scalar v0394 = v0098 * v0810;
    const Scalar v0393 = v0009 * v0816;
    const Scalar v0790 = v0006 * v0040;
    const Scalar v0382 = v0067 * v0810;
    const Scalar v0793 = v0012 * v0040;
    const Scalar v0390 = v0088 * v0810;
    const Scalar v0343 = v0077 * v0808;
    const Scalar v0342 = v0012 * v0816;
    const Scalar v0351 = v0098 * v0808;
    const Scalar v0792 = v0009 * v0040;
    const Scalar v0339 = v0067 * v0808;
    const Scalar v0347 = v0088 * v0808;
    const Scalar v0292 = v0077 * v0806;
    const Scalar v0308 = v0098 * v0806;
    const Scalar v0284 = v0067 * v0806;
    const Scalar v0300 = v0088 * v0806;
    const Scalar v0299 = v0006 * v0816;
    const Scalar v0387 = v0307 + v0386;
    const Scalar v0395 = v0393 + v0394;
    const Scalar v0383 = v0382 + v0790;
    const Scalar v0391 = v0390 + v0793;
    const Scalar v0344 = v0342 + v0343;
    const Scalar v0352 = v0351 + v0790;
    const Scalar v0340 = v0339 + v0792;
    const Scalar v0348 = v0307 + v0347;
    const Scalar v0293 = v0292 + v0792;
    const Scalar v0309 = v0307 + v0308;
    const Scalar v0285 = v0284 + v0793;
    const Scalar v0301 = v0299 + v0300;
    const Scalar v0638 = v0011 * v0387;
    const Scalar v0637 = v0005 * v0395;
    const Scalar v0634 = v0008 * v0383;
    const Scalar v0633 = v0001 * v0391;
    const Scalar v0630 = v0011 * v0391;
    const Scalar v0629 = v0001 * v0387;
    const Scalar v0626 = v0008 * v0395;
    const Scalar v0625 = v0005 * v0383;
    const Scalar v0622 = v0011 * v0395;
    const Scalar v0621 = v0008 * v0391;
    const Scalar v0618 = v0005 * v0387;
    const Scalar v0617 = v0001 * v0383;
    const Scalar v0614 = v0011 * v0344;
    const Scalar v0613 = v0005 * v0352;
    const Scalar v0610 = v0008 * v0340;
    const Scalar v0609 = v0001 * v0348;
    const Scalar v0606 = v0011 * v0348;
    const Scalar v0605 = v0001 * v0344;
    const Scalar v0602 = v0008 * v0352;
    const Scalar v0601 = v0005 * v0340;
    const Scalar v0598 = v0011 * v0352;
    const Scalar v0597 = v0008 * v0348;
    const Scalar v0594 = v0005 * v0344;
    const Scalar v0593 = v0001 * v0340;
    const Scalar v0590 = v0011 * v0293;
    const Scalar v0589 = v0005 * v0309;
    const Scalar v0586 = v0008 * v0285;
    const Scalar v0585 = v0001 * v0301;
    const Scalar v0582 = v0011 * v0301;
    const Scalar v0581 = v0001 * v0293;
    const Scalar v0578 = v0008 * v0309;
    const Scalar v0577 = v0005 * v0285;
    const Scalar v0574 = v0011 * v0309;
    const Scalar v0573 = v0008 * v0301;
    const Scalar v0570 = v0005 * v0293;
    const Scalar v0569 = v0001 * v0285;
    const Scalar v0639 = v0637 + v0638;
    const Scalar v0635 = v0633 + v0634;
    const Scalar v0631 = v0629 + v0630;
    const Scalar v0627 = v0625 + v0626;
    const Scalar v0623 = v0621 + v0622;
    const Scalar v0619 = v0617 + v0618;
    const Scalar v0615 = v0613 + v0614;
    const Scalar v0611 = v0609 + v0610;
    const Scalar v0607 = v0605 + v0606;
    const Scalar v0603 = v0601 + v0602;
    const Scalar v0599 = v0597 + v0598;
    const Scalar v0595 = v0593 + v0594;
    const Scalar v0591 = v0589 + v0590;
    const Scalar v0587 = v0585 + v0586;
    const Scalar v0583 = v0581 + v0582;
    const Scalar v0579 = v0577 + v0578;
    const Scalar v0575 = v0573 + v0574;
    const Scalar v0571 = v0569 + v0570;
    const Scalar v0746 = v0081 * v0639;
    const Scalar v0745 = v0055 * v0635;
    const Scalar v0742 = v0081 * v0631;
    const Scalar v0741 = v0055 * v0627;
    const Scalar v0738 = v0081 * v0623;
    const Scalar v0737 = v0055 * v0619;
    const Scalar v0734 = v0081 * v0615;
    const Scalar v0733 = v0055 * v0611;
    const Scalar v0730 = v0081 * v0607;
    const Scalar v0729 = v0055 * v0603;
    const Scalar v0726 = v0081 * v0599;
    const Scalar v0725 = v0055 * v0595;
    const Scalar v0722 = v0081 * v0591;
    const Scalar v0721 = v0055 * v0587;
    const Scalar v0718 = v0081 * v0583;
    const Scalar v0717 = v0055 * v0579;
    const Scalar v0714 = v0081 * v0575;
    const Scalar v0713 = v0055 * v0571;
    const Scalar v0747 = v0745 + v0746;
    const Scalar v0743 = v0741 + v0742;
    const Scalar v0739 = v0737 + v0738;
    const Scalar v0735 = v0733 + v0734;
    const Scalar v0731 = v0729 + v0730;
    const Scalar v0727 = v0725 + v0726;
    const Scalar v0723 = v0721 + v0722;
    const Scalar v0719 = v0717 + v0718;
    const Scalar v0715 = v0713 + v0714;
    const Scalar v0748 = v0026 * v0747;
    const Scalar v0744 = v0026 * v0743;
    const Scalar v0740 = v0026 * v0739;
    const Scalar v0736 = v0026 * v0735;
    const Scalar v0732 = v0026 * v0731;
    const Scalar v0728 = v0026 * v0727;
    const Scalar v0724 = v0026 * v0723;
    const Scalar v0720 = v0026 * v0719;
    const Scalar v0716 = v0026 * v0715;
    _d0(0, 0) = v0716;
    _d0(0, 1) = v0720;
    _d0(0, 2) = v0724;
    _d0(1, 0) = v0728;
    _d0(1, 1) = v0732;
    _d0(1, 2) = v0736;
    _d0(2, 0) = v0740;
    _d0(2, 1) = v0744;
    _d0(2, 2) = v0748;
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
    const Scalar v0531 = v0179 * v0810;
    const Scalar v0452 = v0011 * v0040;
    const Scalar v0789 = v0005 * v0040;
    const Scalar v0539 = v0199 * v0810;
    const Scalar v0527 = v0169 * v0810;
    const Scalar v0495 = v0008 * v0816;
    const Scalar v0535 = v0189 * v0810;
    const Scalar v0428 = v0001 * v0816;
    const Scalar v0788 = v0001 * v0040;
    const Scalar v0488 = v0179 * v0808;
    const Scalar v0496 = v0199 * v0808;
    const Scalar v0484 = v0169 * v0808;
    const Scalar v0436 = v0005 * v0816;
    const Scalar v0492 = v0189 * v0808;
    const Scalar v0437 = v0179 * v0806;
    const Scalar v0453 = v0199 * v0806;
    const Scalar v0429 = v0169 * v0806;
    const Scalar v0791 = v0008 * v0040;
    const Scalar v0445 = v0189 * v0806;
    const Scalar v0532 = v0452 + v0531;
    const Scalar v0540 = v0539 + v0789;
    const Scalar v0528 = v0495 + v0527;
    const Scalar v0536 = v0428 + v0535;
    const Scalar v0489 = v0488 + v0788;
    const Scalar v0497 = v0495 + v0496;
    const Scalar v0485 = v0436 + v0484;
    const Scalar v0493 = v0452 + v0492;
    const Scalar v0438 = v0436 + v0437;
    const Scalar v0454 = v0452 + v0453;
    const Scalar v0430 = v0428 + v0429;
    const Scalar v0446 = v0445 + v0791;
    const Scalar v0710 = v0002 * v0532;
    const Scalar v0709 = v0009 * v0540;
    const Scalar v0706 = v0006 * v0528;
    const Scalar v0705 = v0012 * v0536;
    const Scalar v0702 = v0002 * v0536;
    const Scalar v0701 = v0012 * v0532;
    const Scalar v0698 = v0006 * v0540;
    const Scalar v0697 = v0009 * v0528;
    const Scalar v0694 = v0002 * v0540;
    const Scalar v0693 = v0006 * v0536;
    const Scalar v0690 = v0009 * v0532;
    const Scalar v0689 = v0012 * v0528;
    const Scalar v0686 = v0002 * v0489;
    const Scalar v0685 = v0009 * v0497;
    const Scalar v0682 = v0006 * v0485;
    const Scalar v0681 = v0012 * v0493;
    const Scalar v0678 = v0002 * v0493;
    const Scalar v0677 = v0012 * v0489;
    const Scalar v0674 = v0006 * v0497;
    const Scalar v0673 = v0009 * v0485;
    const Scalar v0670 = v0002 * v0497;
    const Scalar v0669 = v0006 * v0493;
    const Scalar v0666 = v0009 * v0489;
    const Scalar v0665 = v0012 * v0485;
    const Scalar v0662 = v0002 * v0438;
    const Scalar v0661 = v0009 * v0454;
    const Scalar v0658 = v0006 * v0430;
    const Scalar v0657 = v0012 * v0446;
    const Scalar v0654 = v0002 * v0446;
    const Scalar v0653 = v0012 * v0438;
    const Scalar v0650 = v0006 * v0454;
    const Scalar v0649 = v0009 * v0430;
    const Scalar v0646 = v0002 * v0454;
    const Scalar v0645 = v0006 * v0446;
    const Scalar v0642 = v0009 * v0438;
    const Scalar v0641 = v0012 * v0430;
    const Scalar v0711 = v0709 + v0710;
    const Scalar v0707 = v0705 + v0706;
    const Scalar v0703 = v0701 + v0702;
    const Scalar v0699 = v0697 + v0698;
    const Scalar v0695 = v0693 + v0694;
    const Scalar v0691 = v0689 + v0690;
    const Scalar v0687 = v0685 + v0686;
    const Scalar v0683 = v0681 + v0682;
    const Scalar v0679 = v0677 + v0678;
    const Scalar v0675 = v0673 + v0674;
    const Scalar v0671 = v0669 + v0670;
    const Scalar v0667 = v0665 + v0666;
    const Scalar v0663 = v0661 + v0662;
    const Scalar v0659 = v0657 + v0658;
    const Scalar v0655 = v0653 + v0654;
    const Scalar v0651 = v0649 + v0650;
    const Scalar v0647 = v0645 + v0646;
    const Scalar v0643 = v0641 + v0642;
    const Scalar v0782 = v0081 * v0711;
    const Scalar v0781 = v0055 * v0707;
    const Scalar v0778 = v0081 * v0703;
    const Scalar v0777 = v0055 * v0699;
    const Scalar v0774 = v0081 * v0695;
    const Scalar v0773 = v0055 * v0691;
    const Scalar v0770 = v0081 * v0687;
    const Scalar v0769 = v0055 * v0683;
    const Scalar v0766 = v0081 * v0679;
    const Scalar v0765 = v0055 * v0675;
    const Scalar v0762 = v0081 * v0671;
    const Scalar v0761 = v0055 * v0667;
    const Scalar v0758 = v0081 * v0663;
    const Scalar v0757 = v0055 * v0659;
    const Scalar v0754 = v0081 * v0655;
    const Scalar v0753 = v0055 * v0651;
    const Scalar v0750 = v0081 * v0647;
    const Scalar v0749 = v0055 * v0643;
    const Scalar v0783 = v0781 + v0782;
    const Scalar v0779 = v0777 + v0778;
    const Scalar v0775 = v0773 + v0774;
    const Scalar v0771 = v0769 + v0770;
    const Scalar v0767 = v0765 + v0766;
    const Scalar v0763 = v0761 + v0762;
    const Scalar v0759 = v0757 + v0758;
    const Scalar v0755 = v0753 + v0754;
    const Scalar v0751 = v0749 + v0750;
    const Scalar v0784 = v0026 * v0783;
    const Scalar v0780 = v0026 * v0779;
    const Scalar v0776 = v0026 * v0775;
    const Scalar v0772 = v0026 * v0771;
    const Scalar v0768 = v0026 * v0767;
    const Scalar v0764 = v0026 * v0763;
    const Scalar v0760 = v0026 * v0759;
    const Scalar v0756 = v0026 * v0755;
    const Scalar v0752 = v0026 * v0751;
    _d1(0, 0) = v0752;
    _d1(0, 1) = v0756;
    _d1(0, 2) = v0760;
    _d1(1, 0) = v0764;
    _d1(1, 1) = v0768;
    _d1(1, 2) = v0772;
    _d1(2, 0) = v0776;
    _d1(2, 1) = v0780;
    _d1(2, 2) = v0784;
  }
  const Scalar v0787 = v0026 * v0040;
  const Scalar v0053 = v0787 * v0810;
  const Scalar v0047 = v0787 * v0808;
  const Scalar v0041 = v0787 * v0806;
  _out(0, 0) = v0041;
  _out(1, 0) = v0047;
  _out(2, 0) = v0053;
}

} // namespace gen