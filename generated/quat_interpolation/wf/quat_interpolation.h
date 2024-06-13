// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T3, typename T4, typename T5>
void quat_interpolation(const T0& q0_xyzw, const T1& q1_xyzw, const Scalar alpha, T3&& q_out,
                        T4&& d0, T5&& d1) {
  auto _q0_xyzw = wf::make_input_span<4, 1>(q0_xyzw);
  auto _q1_xyzw = wf::make_input_span<4, 1>(q1_xyzw);
  auto _q_out = wf::make_output_span<4, 1>(q_out);
  auto _d0 = wf::make_optional_output_span<3, 3>(d0);
  auto _d1 = wf::make_optional_output_span<3, 3>(d1);

  // Operation counts:
  // add: 338
  // branch: 12
  // call: 6
  // compare: 4
  // divide: 8
  // multiply: 607
  // negate: 28
  // total: 1003

  const Scalar v00013 = _q0_xyzw(3, 0);
  const Scalar v00008 = _q1_xyzw(3, 0);
  const Scalar v00014 = _q1_xyzw(2, 0);
  const Scalar v00001 = _q0_xyzw(2, 0);
  const Scalar v00010 = _q0_xyzw(1, 0);
  const Scalar v00005 = _q1_xyzw(1, 0);
  const Scalar v00011 = _q1_xyzw(0, 0);
  const Scalar v00004 = _q0_xyzw(0, 0);
  const Scalar v00022 = v00004 * v00011 + v00005 * v00010 + v00001 * v00014 + v00008 * v00013;
  std::int64_t v00026;
  if (v00022 < static_cast<Scalar>(0)) {
    v00026 = -1;
  } else {
    v00026 = 1;
  }
  const Scalar v00027 = static_cast<Scalar>(v00026);
  const Scalar v00028 = v00022 * v00027;
  const bool v00030 = static_cast<Scalar>(1) < v00028;
  Scalar v00031;
  if (v00030) {
    v00031 = static_cast<Scalar>(1);
  } else {
    v00031 = v00028;
  }
  const Scalar v00033 = static_cast<Scalar>(1) + -(v00031 * v00031);
  const Scalar v00034 = std::sqrt(v00033);
  const Scalar v00038 = std::acos(v00031);
  const bool v00035 = static_cast<Scalar>(1e-16) < v00034;
  Scalar v00041;
  if (v00035) {
    v00041 = (static_cast<Scalar>(1) / v00034) * v00038 * static_cast<Scalar>(2);
  } else {
    v00041 = static_cast<Scalar>(2);
  }
  const Scalar v00003 = alpha;
  const Scalar v02392 = v00003 * v00027;
  const Scalar v00961 = v00004 * v00014 + v00005 * v00013 + -(v00008 * v00010 + v00001 * v00011);
  const Scalar v00956 = v00001 * v00005 + v00011 * v00013 + -(v00004 * v00008 + v00010 * v00014);
  const Scalar v00951 = v00010 * v00011 + v00013 * v00014 + -(v00004 * v00005 + v00001 * v00008);
  const Scalar v02396 = v00041 * v02392;
  const Scalar v02500 = v02396 * v02396;
  const Scalar v01736 = v00951 * v00951 + v00956 * v00956 + v00961 * v00961;
  const Scalar v05701 = v01736 * v02500;
  const Scalar v00064 = static_cast<Scalar>(0.25);
  const Scalar v00059 = static_cast<Scalar>(0.5);
  const Scalar v00056 = std::sqrt(v05701);
  const Scalar v00069 = std::sqrt(static_cast<Scalar>(1) + v00064 * v05701);
  const Scalar v00061 = v00056 * v00059;
  const Scalar v00070 = static_cast<Scalar>(1) / v00069;
  const Scalar v00062 = std::sin(v00061);
  const Scalar v02587 = v00059 * v00070;
  const Scalar v02479 = (static_cast<Scalar>(1) / v00056) * v00062;
  const Scalar v00074 = std::cos(v00061);
  const bool v00057 = static_cast<Scalar>(1e-16) < v00056;
  Scalar v00072;
  Scalar v00075;
  Scalar v00079;
  Scalar v00083;
  if (v00057) {
    const Scalar v03130 = v02396 * v02479;
    v00072 = v00961 * v03130;
    v00075 = v00074;
    v00079 = v00951 * v03130;
    v00083 = v00956 * v03130;
  } else {
    v00072 = v02587 * (v00961 * v02396);
    v00075 = v00070;
    v00079 = v02587 * (v00951 * v02396);
    v00083 = v02587 * (v00956 * v02396);
  }
  const Scalar v00102 = static_cast<Scalar>(-0.5);
  const Scalar v00162 = static_cast<Scalar>(1) / (v00069 * v00069 * v00069);
  const Scalar v00151 = static_cast<Scalar>(-0.25);
  const Scalar v06407 = v00013 * v00083 + (v00004 * v00075 + v00010 * v00079);
  const Scalar v06415 = v00013 * v00079 + (v00004 * v00072 + v00001 * v00075);
  const Scalar v06429 = -v00004;
  const Scalar v06428 = -v00001;
  const Scalar v06411 = v00013 * v00072 + (v00010 * v00075 + v00001 * v00083);
  const Scalar v06430 = -v00010;
  const Scalar v02674 = v02500 * (v00151 * v00162);
  const Scalar v03253 = static_cast<Scalar>(2) *
                        (v00031 * v00038 * (static_cast<Scalar>(1) / (v00034 * v00034 * v00034)) +
                         -(static_cast<Scalar>(1) / v00033));
  const Scalar v03312 = v00059 * v01736;
  const Scalar v02559 = static_cast<Scalar>(2) * v00041;
  const Scalar v04074 = v00961 * v02674;
  const Scalar v03979 = v00951 * v02674;
  const Scalar v04036 = v00956 * v02674;
  const Scalar v03672 = v00070 * (v00041 * v00102);
  const Scalar v03639 = (v00162 * v02392) * (v00102 * v02396);
  const Scalar v03637 =
      v02500 * (static_cast<Scalar>(2) *
                (v00062 * v00102 * (static_cast<Scalar>(1) / (v00056 * v00056 * v00056)) +
                 v00064 * v00074 * (static_cast<Scalar>(1) / v05701)));
  const Scalar v02827 = v00041 * v02479;
  const Scalar v03640 = (static_cast<Scalar>(2) * v02396) * (v02479 * (v00151 * v02392));
  const Scalar v01805 = v00001 * v00072 + -v06407;
  const Scalar v01954 = v00010 * v00083 + -v06415;
  const Scalar v00978 = v00013 * v00075 + -(v00004 * v00083 + v00010 * v00072 + v00001 * v00079);
  const Scalar v00090 = v00079 * v06429 + v06411;
  const Scalar v00085 = v00072 * v06428 + v06407;
  const Scalar v01809 = v00004 * v00079 + -v06411;
  const Scalar v00095 = v00083 * v06430 + v06415;
  if (static_cast<bool>(_d0)) {
    Scalar v00118;
    Scalar v00240;
    Scalar v00318;
    Scalar v00394;
    if (v00035) {
      Scalar v00110;
      Scalar v00236;
      Scalar v00314;
      Scalar v00390;
      if (v00030) {
        v00110 = static_cast<Scalar>(0);
        v00236 = static_cast<Scalar>(0);
        v00314 = static_cast<Scalar>(0);
        v00390 = static_cast<Scalar>(0);
      } else {
        v00110 = v00008 * v00027;
        v00236 = v00014 * v00027;
        v00314 = v00005 * v00027;
        v00390 = v00011 * v00027;
      }
      v00118 = v00110 * v03253;
      v00240 = v00236 * v03253;
      v00318 = v00314 * v03253;
      v00394 = v00390 * v03253;
    } else {
      v00118 = static_cast<Scalar>(0);
      v00240 = static_cast<Scalar>(0);
      v00318 = static_cast<Scalar>(0);
      v00394 = static_cast<Scalar>(0);
    }
    const Scalar v02155 = v00011 * v00961 + v00008 * v00951;
    const Scalar v05107 = v00005 * v00956;
    const Scalar v02179 = v00014 * v00956 + v00008 * v00961;
    const Scalar v05137 = v00011 * v00951;
    const Scalar v02203 = v00005 * v00951 + v00008 * v00956;
    const Scalar v05164 = v00014 * v00961;
    const Scalar v01760 = v00011 * v00956 + v00005 * v00961 + v00014 * v00951;
    Scalar v00167;
    Scalar v00171;
    Scalar v00182;
    Scalar v00193;
    Scalar v00261;
    Scalar v00266;
    Scalar v00277;
    Scalar v00286;
    Scalar v00338;
    Scalar v00342;
    Scalar v00351;
    Scalar v00362;
    Scalar v00414;
    Scalar v00418;
    Scalar v00429;
    Scalar v00438;
    if (v00057) {
      const Scalar v02141 = v00041 * v01760 + v00118 * v01736;
      const Scalar v02160 = v00041 * (v05107 + -v02155) + v00240 * v01736;
      const Scalar v02184 = v00041 * (v05137 + -v02179) + v00318 * v01736;
      const Scalar v02208 = v00041 * (v05164 + -v02203) + v00394 * v01736;
      const Scalar v01774 = v00118 * v02479 + v02141 * v03637;
      const Scalar v01823 = v00240 * v02479 + v02160 * v03637;
      const Scalar v06433 = -v02827;
      const Scalar v01870 = v00318 * v02479 + v02184 * v03637;
      const Scalar v01917 = v00394 * v02479 + v02208 * v03637;
      const Scalar v05124 = v00005 * v02827;
      const Scalar v05183 = v00014 * v02827;
      const Scalar v05160 = v00011 * v02827;
      const Scalar v01841 = v00008 * v06433;
      v00167 = (v00961 * v01774 + v05124) * v02392;
      v00171 = v02141 * v03640;
      v00182 = (v00951 * v01774 + v05183) * v02392;
      v00193 = (v00956 * v01774 + v05160) * v02392;
      v00261 = (v00011 * v06433 + v00961 * v01823) * v02392;
      v00266 = v02160 * v03640;
      v00277 = (v01841 + v00951 * v01823) * v02392;
      v00286 = (v00956 * v01823 + v05124) * v02392;
      v00338 = (v01841 + v00961 * v01870) * v02392;
      v00342 = v02184 * v03640;
      v00351 = (v00951 * v01870 + v05160) * v02392;
      v00362 = (v00014 * v06433 + v00956 * v01870) * v02392;
      v00414 = (v00961 * v01917 + v05183) * v02392;
      v00418 = v02208 * v03640;
      v00429 = (v00005 * v06433 + v00951 * v01917) * v02392;
      v00438 = (v01841 + v00956 * v01917) * v02392;
    } else {
      const Scalar v02169 = (v00064 * v05107 + v00151 * v02155) * v02559 + v00240 * v03312;
      const Scalar v02193 = (v00064 * v05137 + v00151 * v02179) * v02559 + v00318 * v03312;
      const Scalar v02217 = (v00064 * v05164 + v00151 * v02203) * v02559 + v00394 * v03312;
      const Scalar v03881 = v00005 * v00041;
      const Scalar v03886 = v00014 * v00041;
      const Scalar v03885 = v00011 * v00041;
      const Scalar v02145 = v00064 * v01760 * v02559 + v00118 * v03312;
      const Scalar v01838 = v00240 * v02587 + v02169 * v02674;
      const Scalar v01885 = v00318 * v02587 + v02193 * v02674;
      const Scalar v01940 = v00394 * v02587 + v02217 * v02674;
      const Scalar v01129 = v00008 * v03672;
      v00167 = (v02145 * v04074 + (v00118 * v00961 + v03881) * v02587) * v02392;
      v00171 = v02145 * v03639;
      v00182 = (v02145 * v03979 + (v00118 * v00951 + v03886) * v02587) * v02392;
      v00193 = (v02145 * v04036 + (v00118 * v00956 + v03885) * v02587) * v02392;
      v00261 = (v00011 * v03672 + v00961 * v01838) * v02392;
      v00266 = v02169 * v03639;
      v00277 = (v01129 + v00951 * v01838) * v02392;
      v00286 = (v02169 * v04036 + (v00240 * v00956 + v03881) * v02587) * v02392;
      v00338 = (v01129 + v00961 * v01885) * v02392;
      v00342 = v02193 * v03639;
      v00351 = (v02193 * v03979 + (v00318 * v00951 + v03885) * v02587) * v02392;
      v00362 = (v00014 * v03672 + v00956 * v01885) * v02392;
      v00414 = (v02217 * v04074 + (v00394 * v00961 + v03886) * v02587) * v02392;
      v00418 = v02217 * v03639;
      v00429 = (v00005 * v03672 + v00951 * v01940) * v02392;
      v00438 = (v01129 + v00956 * v01940) * v02392;
    }
    const Scalar v00301 =
        v00083 + v00277 * v06429 + v00010 * v00266 + v00001 * v00286 + v00013 * v00261;
    const Scalar v01154 =
        v00013 * v00266 + -(v00079 + v00004 * v00286 + v00010 * v00261 + v00001 * v00277);
    const Scalar v00307 =
        v00075 + v00286 * v06430 + v00004 * v00261 + v00001 * v00266 + v00013 * v00277;
    const Scalar v01148 =
        v00004 * v00266 + v00010 * v00277 + v00013 * v00286 + -(v00072 + v00001 * v00261);
    const Scalar v01292 =
        v00010 * v00418 + v00001 * v00438 + v00013 * v00414 + -(v00079 + v00004 * v00429);
    const Scalar v01288 =
        v00013 * v00418 + -(v00083 + v00004 * v00438 + v00010 * v00414 + v00001 * v00429);
    const Scalar v00458 =
        v00072 + v00438 * v06430 + v00004 * v00414 + v00001 * v00418 + v00013 * v00429;
    const Scalar v00440 =
        v00075 + v00414 * v06428 + v00004 * v00418 + v00010 * v00429 + v00013 * v00438;
    const Scalar v00217 =
        v00072 + v00182 * v06429 + v00010 * v00171 + v00001 * v00193 + v00013 * v00167;
    const Scalar v01073 =
        v00075 + v00013 * v00171 + -(v00004 * v00193 + v00010 * v00167 + v00001 * v00182);
    const Scalar v00228 =
        v00079 + v00193 * v06430 + v00004 * v00167 + v00001 * v00171 + v00013 * v00182;
    const Scalar v00195 =
        v00083 + v00167 * v06428 + v00004 * v00171 + v00010 * v00182 + v00013 * v00193;
    const Scalar v00376 =
        v00075 + v00351 * v06429 + v00010 * v00342 + v00001 * v00362 + v00013 * v00338;
    const Scalar v01219 =
        v00013 * v00342 + -(v00072 + v00004 * v00362 + v00010 * v00338 + v00001 * v00351);
    const Scalar v01223 =
        v00004 * v00338 + v00001 * v00342 + v00013 * v00351 + -(v00083 + v00010 * v00362);
    const Scalar v00364 =
        v00079 + v00338 * v06428 + v00004 * v00342 + v00010 * v00351 + v00013 * v00362;
    const Scalar v03202 = v00013 * static_cast<Scalar>(2);
    const Scalar v02259 = v00090 * v01148 + v00307 * v00978 + v01154 * v01954 + v00301 * v01805;
    const Scalar v03200 = v00010 * static_cast<Scalar>(2);
    const Scalar v02271 = v00090 * v00440 + v00458 * v00978 + v01288 * v01954 + v01292 * v01805;
    const Scalar v03196 = v00001 * static_cast<Scalar>(2);
    const Scalar v02253 = v00090 * v00195 + v00228 * v00978 + v01073 * v01954 + v00217 * v01805;
    const Scalar v03197 = v00004 * static_cast<Scalar>(2);
    const Scalar v02265 = v00090 * v00364 + v00978 * v01223 + v01219 * v01954 + v00376 * v01805;
    const Scalar v02235 = v00301 * v00978 + v01148 * v01954 + v01154 * v01809 + v00085 * v00307;
    const Scalar v02247 = v00978 * v01292 + v00440 * v01954 + v01288 * v01809 + v00085 * v00458;
    const Scalar v02229 = v00217 * v00978 + v00195 * v01954 + v01073 * v01809 + v00085 * v00228;
    const Scalar v02241 = v00376 * v00978 + v00364 * v01954 + v01219 * v01809 + v00085 * v01223;
    const Scalar v02175 = v00978 * v01148 + v01154 * v01805 + v00095 * v00301 + v00307 * v01809;
    const Scalar v02223 = v00440 * v00978 + v01288 * v01805 + v00095 * v01292 + v00458 * v01809;
    const Scalar v02151 = v00195 * v00978 + v01073 * v01805 + v00095 * v00217 + v00228 * v01809;
    const Scalar v02199 = v00364 * v00978 + v01219 * v01805 + v00095 * v00376 + v01223 * v01809;
    _d0(0, 0) =
        v00102 * (v02151 * v03197 + v02175 * v03200) + v00059 * (v02199 * v03196 + v02223 * v03202);
    _d0(0, 1) =
        v00102 * (v02151 * v03200 + v02223 * v03196) + v00059 * (v02175 * v03197 + v02199 * v03202);
    _d0(0, 2) =
        v00102 * (v02199 * v03197 + v02151 * v03196) + v00059 * (v02223 * v03200 + v02175 * v03202);
    _d0(1, 0) =
        v00102 * (v02229 * v03197 + v02235 * v03200) + v00059 * (v02241 * v03196 + v02247 * v03202);
    _d0(1, 1) =
        v00102 * (v02229 * v03200 + v02247 * v03196) + v00059 * (v02235 * v03197 + v02241 * v03202);
    _d0(1, 2) =
        v00102 * (v02241 * v03197 + v02229 * v03196) + v00059 * (v02247 * v03200 + v02235 * v03202);
    _d0(2, 0) =
        v00102 * (v02253 * v03197 + v02259 * v03200) + v00059 * (v02265 * v03196 + v02271 * v03202);
    _d0(2, 1) =
        v00102 * (v02253 * v03200 + v02271 * v03196) + v00059 * (v02259 * v03197 + v02265 * v03202);
    _d0(2, 2) =
        v00102 * (v02265 * v03197 + v02253 * v03196) + v00059 * (v02271 * v03200 + v02259 * v03202);
  }
  if (static_cast<bool>(_d1)) {
    Scalar v00568;
    Scalar v00644;
    Scalar v00721;
    Scalar v00796;
    if (v00035) {
      Scalar v00564;
      Scalar v00640;
      Scalar v00717;
      Scalar v00792;
      if (v00030) {
        v00564 = static_cast<Scalar>(0);
        v00640 = static_cast<Scalar>(0);
        v00717 = static_cast<Scalar>(0);
        v00792 = static_cast<Scalar>(0);
      } else {
        v00564 = v00013 * v00027;
        v00640 = v00001 * v00027;
        v00717 = v00010 * v00027;
        v00792 = v00004 * v00027;
      }
      v00568 = v00564 * v03253;
      v00644 = v00640 * v03253;
      v00721 = v00717 * v03253;
      v00796 = v00792 * v03253;
    } else {
      v00568 = static_cast<Scalar>(0);
      v00644 = static_cast<Scalar>(0);
      v00721 = static_cast<Scalar>(0);
      v00796 = static_cast<Scalar>(0);
    }
    const Scalar v06416 = v00004 * v00961 + v00013 * v00951;
    const Scalar v06417 = v00001 * v00956 + v00013 * v00961;
    const Scalar v06418 = v00010 * v00951 + v00013 * v00956;
    const Scalar v01959 = v00004 * v00956 + v00010 * v00961 + v00001 * v00951;
    Scalar v00588;
    Scalar v00592;
    Scalar v00603;
    Scalar v00614;
    Scalar v00667;
    Scalar v00671;
    Scalar v00682;
    Scalar v00691;
    Scalar v00742;
    Scalar v00746;
    Scalar v00755;
    Scalar v00766;
    Scalar v00817;
    Scalar v00821;
    Scalar v00832;
    Scalar v00841;
    if (v00057) {
      const Scalar v02275 = v01959 * -v00041 + v00568 * v01736;
      const Scalar v02301 = v00041 * (v00956 * v06430 + v06416) + v00644 * v01736;
      const Scalar v02332 = v00041 * (v00951 * v06429 + v06417) + v00721 * v01736;
      const Scalar v02363 = v00041 * (v00961 * v06428 + v06418) + v00796 * v01736;
      const Scalar v01969 = v00568 * v02479 + v02275 * v03637;
      const Scalar v02013 = v00644 * v02479 + v02301 * v03637;
      const Scalar v02059 = v00721 * v02479 + v02332 * v03637;
      const Scalar v02105 = v00796 * v02479 + v02363 * v03637;
      const Scalar v01970 = v02827 * v06430;
      const Scalar v01983 = v02827 * v06428;
      const Scalar v01992 = v02827 * v06429;
      const Scalar v02030 = v00013 * v02827;
      v00588 = (v01970 + v00961 * v01969) * v02392;
      v00592 = v02275 * v03640;
      v00603 = (v01983 + v00951 * v01969) * v02392;
      v00614 = (v01992 + v00956 * v01969) * v02392;
      v00667 = (v00961 * v02013 + v00004 * v02827) * v02392;
      v00671 = v02301 * v03640;
      v00682 = (v02030 + v00951 * v02013) * v02392;
      v00691 = (v01970 + v00956 * v02013) * v02392;
      v00742 = (v02030 + v00961 * v02059) * v02392;
      v00746 = v02332 * v03640;
      v00755 = (v01992 + v00951 * v02059) * v02392;
      v00766 = (v00956 * v02059 + v00001 * v02827) * v02392;
      v00817 = (v01983 + v00961 * v02105) * v02392;
      v00821 = v02363 * v03640;
      v00832 = (v00951 * v02105 + v00010 * v02827) * v02392;
      v00841 = (v02030 + v00956 * v02105) * v02392;
    } else {
      const Scalar v02279 = static_cast<Scalar>(2) * v01959 * (v00041 * v00151) + v00568 * v03312;
      const Scalar v02310 =
          (v00010 * (v00151 * v00956) + v00064 * v06416) * v02559 + v00644 * v03312;
      const Scalar v02341 =
          (v00004 * (v00151 * v00951) + v00064 * v06417) * v02559 + v00721 * v03312;
      const Scalar v02372 =
          (v00001 * (v00151 * v00961) + v00064 * v06418) * v02559 + v00796 * v03312;
      const Scalar v05161 = v00013 * v00041;
      const Scalar v01980 = v02279 * v02674 + v00568 * v02587;
      const Scalar v01424 = v00010 * v03672;
      const Scalar v01435 = v00001 * v03672;
      const Scalar v01446 = v00004 * v03672;
      v00588 = (v01424 + v00961 * v01980) * v02392;
      v00592 = v02279 * v03639;
      v00603 = (v01435 + v00951 * v01980) * v02392;
      v00614 = (v01446 + v00956 * v01980) * v02392;
      v00667 = (v02310 * v04074 + (v00644 * v00961 + v00004 * v00041) * v02587) * v02392;
      v00671 = v02310 * v03639;
      v00682 = (v02310 * v03979 + (v00644 * v00951 + v05161) * v02587) * v02392;
      v00691 = (v01424 + v00956 * (v00644 * v02587 + v02310 * v02674)) * v02392;
      v00742 = (v02341 * v04074 + (v00721 * v00961 + v05161) * v02587) * v02392;
      v00746 = v02341 * v03639;
      v00755 = (v01446 + v00951 * (v00721 * v02587 + v02341 * v02674)) * v02392;
      v00766 = (v02341 * v04036 + (v00721 * v00956 + v00001 * v00041) * v02587) * v02392;
      v00817 = (v01435 + v00961 * (v00796 * v02587 + v02372 * v02674)) * v02392;
      v00821 = v02372 * v03639;
      v00832 = (v02372 * v03979 + (v00796 * v00951 + v00010 * v00041) * v02587) * v02392;
      v00841 = (v02372 * v04036 + (v00796 * v00956 + v05161) * v02587) * v02392;
    }
    const Scalar v00705 = v00682 * v06429 + v00010 * v00671 + v00001 * v00691 + v00013 * v00667;
    const Scalar v01521 = v00013 * v00671 + -(v00004 * v00691 + v00010 * v00667 + v00001 * v00682);
    const Scalar v00711 = v00691 * v06430 + v00004 * v00667 + v00001 * v00671 + v00013 * v00682;
    const Scalar v00693 = v00667 * v06428 + v00004 * v00671 + v00010 * v00682 + v00013 * v00691;
    const Scalar v00855 = v00832 * v06429 + v00010 * v00821 + v00001 * v00841 + v00013 * v00817;
    const Scalar v01651 = v00013 * v00821 + -(v00004 * v00841 + v00010 * v00817 + v00001 * v00832);
    const Scalar v00861 = v00841 * v06430 + v00004 * v00817 + v00001 * v00821 + v00013 * v00832;
    const Scalar v00843 = v00817 * v06428 + v00004 * v00821 + v00010 * v00832 + v00013 * v00841;
    const Scalar v00628 = v00603 * v06429 + v00010 * v00592 + v00001 * v00614 + v00013 * v00588;
    const Scalar v01456 = v00013 * v00592 + -(v00004 * v00614 + v00010 * v00588 + v00001 * v00603);
    const Scalar v00634 = v00614 * v06430 + v00004 * v00588 + v00001 * v00592 + v00013 * v00603;
    const Scalar v00616 = v00588 * v06428 + v00004 * v00592 + v00010 * v00603 + v00013 * v00614;
    const Scalar v00780 = v00755 * v06429 + v00010 * v00746 + v00001 * v00766 + v00013 * v00742;
    const Scalar v01586 = v00013 * v00746 + -(v00004 * v00766 + v00010 * v00742 + v00001 * v00755);
    const Scalar v00786 = v00766 * v06430 + v00004 * v00742 + v00001 * v00746 + v00013 * v00755;
    const Scalar v00768 = v00742 * v06428 + v00004 * v00746 + v00010 * v00755 + v00013 * v00766;
    const Scalar v03199 = v00008 * static_cast<Scalar>(2);
    const Scalar v02328 = v00090 * v00693 + v00711 * v00978 + v01521 * v01954 + v00705 * v01805;
    const Scalar v03198 = v00005 * static_cast<Scalar>(2);
    const Scalar v02390 = v00090 * v00843 + v00861 * v00978 + v01651 * v01954 + v00855 * v01805;
    const Scalar v03203 = v00014 * static_cast<Scalar>(2);
    const Scalar v02297 = v00090 * v00616 + v00634 * v00978 + v01456 * v01954 + v00628 * v01805;
    const Scalar v03201 = v00011 * static_cast<Scalar>(2);
    const Scalar v02359 = v00090 * v00768 + v00786 * v00978 + v01586 * v01954 + v00780 * v01805;
    const Scalar v02322 = v00705 * v00978 + v00693 * v01954 + v01521 * v01809 + v00085 * v00711;
    const Scalar v02384 = v00855 * v00978 + v00843 * v01954 + v01651 * v01809 + v00085 * v00861;
    const Scalar v02291 = v00628 * v00978 + v00616 * v01954 + v01456 * v01809 + v00085 * v00634;
    const Scalar v02353 = v00780 * v00978 + v00768 * v01954 + v01586 * v01809 + v00085 * v00786;
    const Scalar v02316 = v00693 * v00978 + v01521 * v01805 + v00095 * v00705 + v00711 * v01809;
    const Scalar v02378 = v00843 * v00978 + v01651 * v01805 + v00095 * v00855 + v00861 * v01809;
    const Scalar v02285 = v00616 * v00978 + v01456 * v01805 + v00095 * v00628 + v00634 * v01809;
    const Scalar v02347 = v00768 * v00978 + v01586 * v01805 + v00095 * v00780 + v00786 * v01809;
    _d1(0, 0) =
        v00102 * (v02285 * v03201 + v02316 * v03198) + v00059 * (v02347 * v03203 + v02378 * v03199);
    _d1(0, 1) =
        v00102 * (v02285 * v03198 + v02378 * v03203) + v00059 * (v02316 * v03201 + v02347 * v03199);
    _d1(0, 2) =
        v00102 * (v02347 * v03201 + v02285 * v03203) + v00059 * (v02378 * v03198 + v02316 * v03199);
    _d1(1, 0) =
        v00102 * (v02291 * v03201 + v02322 * v03198) + v00059 * (v02353 * v03203 + v02384 * v03199);
    _d1(1, 1) =
        v00102 * (v02291 * v03198 + v02384 * v03203) + v00059 * (v02322 * v03201 + v02353 * v03199);
    _d1(1, 2) =
        v00102 * (v02353 * v03201 + v02291 * v03203) + v00059 * (v02384 * v03198 + v02322 * v03199);
    _d1(2, 0) =
        v00102 * (v02297 * v03201 + v02328 * v03198) + v00059 * (v02359 * v03203 + v02390 * v03199);
    _d1(2, 1) =
        v00102 * (v02297 * v03198 + v02390 * v03203) + v00059 * (v02328 * v03201 + v02359 * v03199);
    _d1(2, 2) =
        v00102 * (v02359 * v03201 + v02297 * v03203) + v00059 * (v02390 * v03198 + v02328 * v03199);
  }
  _q_out(0, 0) = v00085;
  _q_out(1, 0) = v00090;
  _q_out(2, 0) = v00095;
  _q_out(3, 0) = v00978;
}

}  // namespace gen
