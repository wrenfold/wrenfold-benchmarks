// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T3, typename T4, typename T5>
void quat_interpolation_sffo(const T0& q0_xyzw, const T1& q1_xyzw, const Scalar alpha, T3&& q_out,
                             T4&& d0, T5&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _q_out = wf::make_output_span<4, 1>(q_out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 291
  // branch: 6
  // call: 7
  // compare: 4
  // divide: 7
  // multiply: 476
  // negate: 24
  // total: 815

  const Scalar v00014 = _q1_xyzw(3, 0);
  const Scalar v00013 = _q0_xyzw(3, 0);
  const Scalar v00011 = _q1_xyzw(2, 0);
  const Scalar v00001 = _q0_xyzw(2, 0);
  const Scalar v00009 = _q1_xyzw(1, 0);
  const Scalar v00008 = _q0_xyzw(1, 0);
  const Scalar v00006 = _q1_xyzw(0, 0);
  const Scalar v00005 = _q0_xyzw(0, 0);
  const Scalar v00016 = v00005 * v00006 + v00008 * v00009 + v00001 * v00011 + v00013 * v00014;
  const std::int64_t v00017 = (static_cast<Scalar>(0) < v00016) - (v00016 < static_cast<Scalar>(0));
  std::int64_t v00020;
  if (v00017 < 0) {
    v00020 = v00017;
  } else {
    v00020 = 0;
  }
  const Scalar v00030 = std::abs(v00016);
  Scalar v00033;
  if (v00030 < static_cast<Scalar>(0.9999999999999999)) {
    v00033 = v00030;
  } else {
    v00033 = static_cast<Scalar>(0.9999999999999999);
  }
  const Scalar v00099 = static_cast<Scalar>(0.9999999999999999) + -v00030;
  const Scalar v00090 = static_cast<Scalar>(0.5);
  Scalar v00104;
  if (static_cast<Scalar>(0) < v00099) {
    v00104 = static_cast<Scalar>(1);
  } else {
    if (v00099 < static_cast<Scalar>(0)) {
      v00104 = static_cast<Scalar>(-1);
    } else {
      v00104 = v00090;
    }
  }
  const Scalar v08740 = v00008 * v00014 + v00001 * v00006;
  const Scalar v08742 = v00005 * v00014 + v00008 * v00011;
  const Scalar v08741 = v00005 * v00009 + v00001 * v00014;
  const Scalar v00002 = alpha;
  const Scalar v08737 = v00005 * v00011 + v00009 * v00013;
  const Scalar v08739 = v00001 * v00009 + v00006 * v00013;
  const Scalar v08738 = v00006 * v00008 + v00011 * v00013;
  const Scalar v02646 = v00002 * static_cast<Scalar>(1 + 2 * v00020);
  const Scalar v00044 = std::acos(v00033);
  const Scalar v00036 = v00033 * -v00033 + static_cast<Scalar>(1);
  const Scalar v00804 = v08737 + -v08740;
  const Scalar v00814 = v08739 + -v08742;
  const Scalar v00809 = v08738 + -v08741;
  const Scalar v02650 = v00044 * v02646;
  const Scalar v00037 = static_cast<Scalar>(1) / v00036;
  const Scalar v03251 = v00037 * v02650;
  const Scalar v01777 = v00809 * v00809 + v00814 * v00814 + v00804 * v00804;
  const Scalar v00056 = std::sqrt(v00036);
  const Scalar v00820 = static_cast<Scalar>(2.4999999999999998e-33) + v01777 * v02650 * v03251;
  const Scalar v00829 = v00013 * v00804;
  const Scalar v00828 = v00001 * v00814;
  const Scalar v07857 = v00005 * v00804;
  const Scalar v00835 = v00013 * v00809;
  const Scalar v00823 = v00013 * v00814;
  const Scalar v00822 = v00008 * v00809;
  const Scalar v00054 = std::sqrt(v00820);
  const Scalar v00123 = static_cast<Scalar>(1) / (v00036 * v00036);
  const Scalar v00087 = static_cast<Scalar>(-0.5);
  const Scalar v08735 = v00828 + v00829;
  const Scalar v08759 = -v00005;
  const Scalar v00097 = static_cast<Scalar>(1) / (v00056 * v00056 * v00056);
  const Scalar v08760 = -v00008;
  const Scalar v08736 = v00835 + v07857;
  const Scalar v08758 = -v00001;
  const Scalar v08734 = v00822 + v00823;
  const Scalar v00058 = std::sin(v00054);
  const Scalar v00055 = static_cast<Scalar>(1) / v00054;
  const Scalar v00841 = v00001 * v00809;
  const Scalar v00840 = v00008 * v00804;
  const Scalar v00839 = v00005 * v00814;
  const Scalar v04317 = v00033 * v00044;
  const Scalar v08756 = -v00044;
  const Scalar v07858 = v00005 * v00809;
  const Scalar v07884 = v00008 * v00814;
  const Scalar v07822 = v00001 * v00804;
  const Scalar v02837 = (static_cast<Scalar>(1) / v00056) * v02650;
  const Scalar v02702 = v00055 * v00058;
  const Scalar v00842 = v00839 + v00840 + v00841;
  const Scalar v02742 = v02646 * (v00104 * static_cast<Scalar>(v00017));
  const Scalar v01263 = v00087 * v08739 + v00090 * v08742;
  const Scalar v01063 = v00087 * v08740 + v00090 * v08737;
  const Scalar v00060 = std::cos(v00054);
  const Scalar v00911 = v00087 * v08741 + v00090 * v08738;
  const Scalar v00920 = v00087 * v08737 + v00090 * v08740;
  const Scalar v00859 = v00087 * v08742 + v00090 * v08739;
  const Scalar v01109 = v00087 * v08738 + v00090 * v08741;
  const Scalar v01906 = v07858 + -v08735;
  const Scalar v07521 = v00097 * v04317;
  const Scalar v00830 = v00809 * v08759 + v08735;
  const Scalar v00836 = v00814 * v08760 + v08736;
  const Scalar v02131 = v07884 + -v08736;
  const Scalar v00824 = v00804 * v08758 + v08734;
  const Scalar v01840 = v07822 + -v08734;
  const Scalar v03960 = v02702 * v02837;
  const Scalar v08774 = -v00842;
  const Scalar v03364 = v01777 * v02742;
  const Scalar v00143 = static_cast<Scalar>(1) / (v00054 * v00054 * v00054);
  const Scalar v08757 = -v02650;
  const Scalar v06001 = v00008 * v00060;
  const Scalar v05970 = v00005 * v00060;
  const Scalar v05940 = v00001 * v00060;
  const Scalar v02442 = v00804 * (v00814 + (v08742 + -v08739));
  const Scalar v02405 = v00814 * (v00809 + (v08741 + -v08738));
  const Scalar v02340 = v00809 * (v00804 + (v08740 + -v08737));
  const Scalar v05012 = (v00123 * v04317 + -v00097) * v03364;
  const Scalar v04503 = v00090 * v03251;
  const Scalar v05597 = (v00097 + (v00033 * v00123) * v08756) * v03364;
  const Scalar v05366 = v00087 * v03251;
  const Scalar v08751 = v00005 * v01063 + v00008 * v01263;
  const Scalar v03585 = v02650 * (v00060 * (static_cast<Scalar>(1) / v00820));
  const Scalar v05396 = v00143 * (v00058 * v02650);
  const Scalar v08748 = v00920 * v08759 + v00013 * v00911;
  const Scalar v01322 = v00001 * v01063;
  const Scalar v08750 = v01263 * v08758 + v00013 * v01063;
  const Scalar v08749 = v01109 * v08760 + v00013 * v00859;
  const Scalar v01114 = v00008 * v00859;
  const Scalar v01040 = v00005 * v00911;
  const Scalar v01890 = v00830 * v07521 + v00037 * v01906;
  const Scalar v04227 = v00008 * v08757;
  const Scalar v04557 = v00842 * (v00037 + (v00033 * v00097) * v08756);
  const Scalar v04310 = v00013 * v08757;
  const Scalar v01921 = v00037 * v02131 + v00836 * v07521;
  const Scalar v05199 = v00001 * v08757;
  const Scalar v01813 = v00037 * v01840 + v00824 * v07521;
  const Scalar v04150 = v00005 * v08757;
  const Scalar v01843 = v00060 * v08759 + v01840 * v03960;
  const Scalar v02134 = v00060 * v08758 + v02131 * v03960;
  const Scalar v00844 = v03960 * v08774 + v00013 * v00060;
  const Scalar v00832 = v00830 * v03960 + v06001;
  const Scalar v00826 = v00824 * v03960 + v05970;
  const Scalar v01909 = v00060 * v08760 + v01906 * v03960;
  const Scalar v00838 = v00836 * v03960 + v05940;
  if (static_cast<bool>(_d0)) {
    const Scalar v08761 = -v00016;
    const Scalar v02443 = v00809 * v08761 + v02442;
    const Scalar v02406 = v00804 * v08761 + v02405;
    const Scalar v02341 = v00814 * v08761 + v02340;
    const Scalar v01981 = v00090 * v00814;
    const Scalar v07941 = v00016 * v08759;
    const Scalar v01004 = v00087 * (v00001 * v00016);
    const Scalar v07909 = v00013 * v00016;
    const Scalar v08094 = v00090 * v00804;
    const Scalar v01815 = v00090 * v00809;
    const Scalar v07942 = v00016 * v08760;
    const Scalar v02446 = v02443 * v04503 + v00911 * v05012;
    const Scalar v02092 = v01263 + v01981;
    const Scalar v02409 = v02406 * v04503 + v01063 * v05012;
    const Scalar v01982 = v01981 + -v00859;
    const Scalar v01962 = v01109 + v01815;
    const Scalar v02348 = v02341 * v04503 + v00859 * v05012;
    const Scalar v01816 = v01815 + -v00911;
    const Scalar v01823 = v00920 + v08094;
    const Scalar v02454 = (v02443 * v05366 + v00911 * v05597) * v05396 + v02446 * v03585;
    const Scalar v04683 = v00911 * v02742;
    const Scalar v02417 = (v02406 * v05366 + v01063 * v05597) * v05396 + v02409 * v03585;
    const Scalar v04745 = v01063 * v02742;
    const Scalar v02364 = (v02341 * v05366 + v00859 * v05597) * v05396 + v02348 * v03585;
    const Scalar v04647 = v00859 * v02742;
    const Scalar v00198 = v00087 * v05970;
    const Scalar v00299 = v00087 * v05940;
    const Scalar v00158 = v00013 * (v00060 * v00090);
    const Scalar v00247 = v00087 * v06001;
    const Scalar v02104 =
        v00198 + (v02446 * v04227 + v01890 * v04683) * v02702 +
        ((v01322 + v00087 * (v07941 + (v00822 + v07822)) + v00013 * v02092) * v02702 +
         v00830 * v02454) *
            v02837;
    const Scalar v02085 =
        v00299 + (v02446 * v04310 + v04557 * v04683) * v02702 +
        ((v00804 * (v00005 * v00090) + v00087 * (v00835 + v07884) + -(v01004 + v08751)) * v02702 +
         v02454 * v08774) *
            v02837;
    const Scalar v02126 =
        v00158 + (v02446 * v05199 + v01921 * v04683) * v02702 +
        ((v00008 * (v08094 + -v01063) + v00087 * (v00841 + v07909) + v00005 * v02092) * v02702 +
         v00836 * v02454) *
            v02837;
    const Scalar v02065 =
        v00090 * v06001 + (v02446 * v04150 + v01813 * v04683) * v02702 +
        ((v00087 * (v00008 * v00016 + v07858 + v08735) + v08750) * v02702 + v00824 * v02454) *
            v02837;
    const Scalar v02016 =
        v00158 + (v02409 * v04227 + v01890 * v04745) * v02702 +
        ((v00001 * v01962 + v00087 * (v00840 + v07909) + v00005 * v01982) * v02702 +
         v00830 * v02417) *
            v02837;
    const Scalar v01994 =
        v00247 + (v02409 * v04310 + v04557 * v04745) * v02702 +
        ((v01109 * v08759 + v00087 * (v07942 + (v00829 + v07858)) + v00001 * v01982) * v02702 +
         v02417 * v08774) *
            v02837;
    const Scalar v02033 =
        v00090 * v05970 + (v02409 * v05199 + v01921 * v04745) * v02702 +
        ((v00087 * (v00005 * v00016 + v07822 + v08734) + v08749) * v02702 + v00836 * v02417) *
            v02837;
    const Scalar v01974 =
        v00299 + (v02409 * v04150 + v01813 * v04745) * v02702 +
        ((v01114 + v00087 * (v00016 * v08758 + (v07857 + v07884)) + v00013 * v01962) * v02702 +
         v00824 * v02417) *
            v02837;
    const Scalar v01901 =
        v00090 * v05940 + (v02348 * v04227 + v01890 * v04647) * v02702 +
        (v00830 * v02364 + ((v01004 + v08748) + v00087 * (v07884 + v08736)) * v02702) * v02837;
    const Scalar v01875 =
        v00198 + (v02348 * v04310 + v04557 * v04647) * v02702 +
        ((v00920 * v08758 + v00087 * (v07941 + (v00823 + v07822)) + v00008 * v01816) * v02702 +
         v02364 * v08774) *
            v02837;
    const Scalar v01940 =
        v00247 + (v02348 * v05199 + v01921 * v04647) * v02702 +
        ((v01040 + v00087 * (v07942 + (v00828 + v07858)) + v00013 * v01823) * v02702 +
         v00836 * v02364) *
            v02837;
    const Scalar v01835 =
        v00158 + (v02348 * v04150 + v01813 * v04647) * v02702 +
        ((v00001 * v01816 + v00087 * (v00839 + v07909) + v00008 * v01823) * v02702 +
         v00824 * v02364) *
            v02837;
    _d0(0, 0) = static_cast<Scalar>(2) *
                (v00844 * v01835 + v01843 * v01875 + v00838 * v01901 + v01909 * v01940);
    _d0(0, 1) = static_cast<Scalar>(2) *
                (v00844 * v01974 + v01843 * v01994 + v00838 * v02016 + v01909 * v02033);
    _d0(0, 2) = static_cast<Scalar>(2) *
                (v00844 * v02065 + v01843 * v02085 + v00838 * v02104 + v01909 * v02126);
    _d0(1, 0) = static_cast<Scalar>(2) *
                (v00844 * v01901 + v01835 * v02134 + v01875 * v01909 + v00826 * v01940);
    _d0(1, 1) = static_cast<Scalar>(2) *
                (v00844 * v02016 + v01974 * v02134 + v01909 * v01994 + v00826 * v02033);
    _d0(1, 2) = static_cast<Scalar>(2) *
                (v00844 * v02104 + v02065 * v02134 + v01909 * v02085 + v00826 * v02126);
    _d0(2, 0) = static_cast<Scalar>(2) *
                (v00832 * v01835 + v00844 * v01940 + v01875 * v02134 + v01843 * v01901);
    _d0(2, 1) = static_cast<Scalar>(2) *
                (v00832 * v01974 + v00844 * v02033 + v01994 * v02134 + v01843 * v02016);
    _d0(2, 2) = static_cast<Scalar>(2) *
                (v00832 * v02065 + v00844 * v02126 + v02085 * v02134 + v01843 * v02104);
  }
  if (static_cast<bool>(_d1)) {
    const Scalar v02604 = v02442 + v00016 * v00809;
    const Scalar v03587 = v00016 * v00090;
    const Scalar v02560 = v02405 + v00016 * v00804;
    const Scalar v02516 = v02340 + v00016 * v00814;
    const Scalar v01476 = v00001 * v03587;
    const Scalar v01682 = v00008 * v03587;
    const Scalar v01626 = v00005 * v03587;
    const Scalar v02607 = v02604 * v04503 + v01109 * v05012;
    const Scalar v02611 = v02604 * v05366 + v01109 * v05597;
    const Scalar v08194 = v00842 * (v00143 * v02650);
    const Scalar v02563 = v02560 * v04503 + v00920 * v05012;
    const Scalar v02567 = v02560 * v05366 + v00920 * v05597;
    const Scalar v02519 = v02516 * v04503 + v01263 * v05012;
    const Scalar v02523 = v02516 * v05366 + v01263 * v05597;
    const Scalar v01430 = v00013 * v03587;
    const Scalar v02615 = v02611 * v05396 + v02607 * v03585;
    const Scalar v04751 = v01109 * v02742;
    const Scalar v07623 = v00842 * v03585;
    const Scalar v02571 = v02567 * v05396 + v02563 * v03585;
    const Scalar v04699 = v00920 * v02742;
    const Scalar v02527 = v02523 * v05396 + v02519 * v03585;
    const Scalar v04777 = v01263 * v02742;
    const Scalar v08763 = -v02837;
    const Scalar v02328 =
        (v02607 * v04227 + v01890 * v04751) * v02702 +
        ((v01322 + v00013 * v01263 + v03587 * v08759) * v02702 + v00830 * v02615) * v02837;
    const Scalar v02318 =
        (v02607 * v04310 + v04557 * v04751) * v02702 +
        (v00058 * (v00055 * (v01476 + v08751) + v02611 * v08194) + v02607 * v07623) * v08763;
    const Scalar v02338 =
        (v02607 * v05199 + v01921 * v04751) * v02702 +
        ((v01063 * v08760 + v00005 * v01263 + v01430) * v02702 + v00836 * v02615) * v02837;
    const Scalar v02298 = (v02607 * v04150 + v01813 * v04751) * v02702 +
                          ((v01682 + v08750) * v02702 + v00824 * v02615) * v02837;
    const Scalar v02263 =
        (v02563 * v04227 + v01890 * v04699) * v02702 +
        ((v00859 * v08759 + v00001 * v01109 + v01430) * v02702 + v00830 * v02571) * v02837;
    const Scalar v02253 =
        (v02563 * v04310 + v04557 * v04699) * v02702 +
        (v00058 * (v00055 * (v01682 + v00001 * v00859 + v00005 * v01109) + v02567 * v08194) +
         v02563 * v07623) *
            v08763;
    const Scalar v02273 = (v02563 * v05199 + v01921 * v04699) * v02702 +
                          ((v01626 + v08749) * v02702 + v00836 * v02571) * v02837;
    const Scalar v02233 =
        (v02563 * v04150 + v01813 * v04699) * v02702 +
        ((v01114 + v00013 * v01109 + v03587 * v08758) * v02702 + v00824 * v02571) * v02837;
    const Scalar v02198 = (v02519 * v04227 + v01890 * v04777) * v02702 +
                          ((v01476 + v08748) * v02702 + v00830 * v02527) * v02837;
    const Scalar v02188 =
        (v02519 * v04310 + v04557 * v04777) * v02702 +
        (v00058 * (v00055 * (v01626 + v00008 * v00911 + v00001 * v00920) + v02523 * v08194) +
         v02519 * v07623) *
            v08763;
    const Scalar v02208 =
        (v02519 * v05199 + v01921 * v04777) * v02702 +
        ((v01040 + v00013 * v00920 + v03587 * v08760) * v02702 + v00836 * v02527) * v02837;
    const Scalar v02168 =
        (v02519 * v04150 + v01813 * v04777) * v02702 +
        ((v00911 * v08758 + v00008 * v00920 + v01430) * v02702 + v00824 * v02527) * v02837;
    _d1(0, 0) = static_cast<Scalar>(2) *
                (v00844 * v02168 + v01843 * v02188 + v00838 * v02198 + v01909 * v02208);
    _d1(0, 1) = static_cast<Scalar>(2) *
                (v00844 * v02233 + v01843 * v02253 + v00838 * v02263 + v01909 * v02273);
    _d1(0, 2) = static_cast<Scalar>(2) *
                (v00844 * v02298 + v01843 * v02318 + v00838 * v02328 + v01909 * v02338);
    _d1(1, 0) = static_cast<Scalar>(2) *
                (v00844 * v02198 + v02134 * v02168 + v01909 * v02188 + v00826 * v02208);
    _d1(1, 1) = static_cast<Scalar>(2) *
                (v00844 * v02263 + v02134 * v02233 + v01909 * v02253 + v00826 * v02273);
    _d1(1, 2) = static_cast<Scalar>(2) *
                (v00844 * v02328 + v02134 * v02298 + v01909 * v02318 + v00826 * v02338);
    _d1(2, 0) = static_cast<Scalar>(2) *
                (v00832 * v02168 + v00844 * v02208 + v02134 * v02188 + v01843 * v02198);
    _d1(2, 1) = static_cast<Scalar>(2) *
                (v00832 * v02233 + v00844 * v02273 + v02134 * v02253 + v01843 * v02263);
    _d1(2, 2) = static_cast<Scalar>(2) *
                (v00832 * v02298 + v00844 * v02338 + v02134 * v02318 + v01843 * v02328);
  }
  _q_out(0, 0) = v00826;
  _q_out(1, 0) = v00832;
  _q_out(2, 0) = v00838;
  _q_out(3, 0) = v00844;
}

}  // namespace gen
