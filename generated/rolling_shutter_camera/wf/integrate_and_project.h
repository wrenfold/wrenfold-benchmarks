// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4,
          typename T5, typename T6, typename T9, typename T10, typename T11, typename T12,
          typename T13, typename T14, typename T15, typename T16>
void integrate_and_project(const T0& world_R_imu_xyzw, const T1& world_t_imu,
                           const T2& imu_R_cam_xyzw, const T3& imu_t_cam,
                           const T4& angular_velocity_imu, const T5& world_v_imu, const T6& p_world,
                           const Scalar row_time, const camera_params_t& camera, T9&& p_image,
                           T10&& D_world_R_imu, T11&& D_world_t_imu, T12&& D_imu_R_cam,
                           T13&& D_imu_t_cam, T14&& D_angular_velocity_imu, T15&& D_world_v_imu,
                           T16&& D_p_world) {
  auto _world_R_imu_xyzw = wf::make_input_span<4, 1>(world_R_imu_xyzw);
  auto _world_t_imu = wf::make_input_span<3, 1>(world_t_imu);
  auto _imu_R_cam_xyzw = wf::make_input_span<4, 1>(imu_R_cam_xyzw);
  auto _imu_t_cam = wf::make_input_span<3, 1>(imu_t_cam);
  auto _angular_velocity_imu = wf::make_input_span<3, 1>(angular_velocity_imu);
  auto _world_v_imu = wf::make_input_span<3, 1>(world_v_imu);
  auto _p_world = wf::make_input_span<3, 1>(p_world);
  auto _p_image = wf::make_output_span<2, 1>(p_image);
  auto _D_world_R_imu = wf::make_optional_output_span<2, 3>(D_world_R_imu);
  auto _D_world_t_imu = wf::make_optional_output_span<2, 3>(D_world_t_imu);
  auto _D_imu_R_cam = wf::make_optional_output_span<2, 3>(D_imu_R_cam);
  auto _D_imu_t_cam = wf::make_optional_output_span<2, 3>(D_imu_t_cam);
  auto _D_angular_velocity_imu = wf::make_optional_output_span<2, 3>(D_angular_velocity_imu);
  auto _D_world_v_imu = wf::make_optional_output_span<2, 3>(D_world_v_imu);
  auto _D_p_world = wf::make_optional_output_span<2, 3>(D_p_world);

  // Operation counts:
  // add: 1044
  // branch: 9
  // call: 4
  // compare: 1
  // divide: 7
  // multiply: 1528
  // negate: 99
  // total: 2692

  const Scalar v000011 = _angular_velocity_imu(2, 0);
  const Scalar v000009 = _angular_velocity_imu(1, 0);
  const Scalar v000006 = _angular_velocity_imu(0, 0);
  const Scalar v000007 = row_time;
  const Scalar v008728 = v000011 * v000011;
  const Scalar v008721 = v000009 * v000009;
  const Scalar v007433 = v000007 * v000007;
  const Scalar v010294 = (v000006 * v000006 + v008721 + v008728) * v007433;
  const Scalar v000018 = static_cast<Scalar>(0.5);
  const Scalar v000014 = std::sqrt(v010294);
  const Scalar v000028 = std::sqrt(static_cast<Scalar>(1) + static_cast<Scalar>(0.25) * v010294);
  const Scalar v000020 = v000014 * v000018;
  const Scalar v000029 = static_cast<Scalar>(1) / v000028;
  const Scalar v000021 = std::sin(v000020);
  const Scalar v000017 = static_cast<Scalar>(1) / v000014;
  const Scalar v008271 = v000018 * v000029;
  const Scalar v007586 = v000006 * v000007;
  const Scalar v007627 = v000007 * v000009;
  const Scalar v007628 = v000007 * v000011;
  const Scalar v007833 = v000017 * v000021;
  const Scalar v000045 = std::cos(v000020);
  const bool v000015 = static_cast<Scalar>(1e-16) < v000014;
  Scalar v000031;
  Scalar v000037;
  Scalar v000042;
  Scalar v000046;
  if (v000015) {
    v000031 = v007586 * v007833;
    v000037 = v007627 * v007833;
    v000042 = v007628 * v007833;
    v000046 = v000045;
  } else {
    v000031 = v007586 * v008271;
    v000037 = v007627 * v008271;
    v000042 = v007628 * v008271;
    v000046 = v000029;
  }
  const Scalar v000034 = _world_R_imu_xyzw(1, 0);
  const Scalar v000004 = _world_R_imu_xyzw(0, 0);
  const Scalar v000039 = _world_R_imu_xyzw(2, 0);
  const Scalar v000044 = _world_R_imu_xyzw(3, 0);
  const Scalar v011385 = v000039 * v000042 + (v000004 * v000031 + v000034 * v000037);
  const Scalar v011463 = -v000037;
  const Scalar v011462 = -v000031;
  const Scalar v011464 = -v000042;
  const Scalar v011361 = v000031 * v000044 + (v000004 * v000046 + v000034 * v000042);
  const Scalar v011365 = v000042 * v000044 + (v000004 * v000037 + v000039 * v000046);
  const Scalar v011357 = v000037 * v000044 + (v000034 * v000046 + v000031 * v000039);
  const Scalar v002295 = v000044 * v000046 + -v011385;
  const Scalar v000063 = v000039 * v011463 + v011361;
  const Scalar v000070 = v000034 * v011462 + v011365;
  const Scalar v000056 = v000004 * v011464 + v011357;
  const Scalar v011498 = -v002295;
  const Scalar v000058 = _imu_R_cam_xyzw(3, 0);
  const Scalar v000051 = _imu_R_cam_xyzw(2, 0);
  const Scalar v000065 = _imu_R_cam_xyzw(1, 0);
  const Scalar v000003 = _imu_R_cam_xyzw(0, 0);
  const Scalar v009424 = v000063 * v002295;
  const Scalar v009421 = v000056 * v000070;
  const Scalar v009423 = v000063 * v000070;
  const Scalar v005050 = v000063 * v000063;
  const Scalar v005028 = v000056 * v000056;
  const Scalar v009425 = v000070 * v002295;
  const Scalar v009420 = v000056 * v000063;
  const Scalar v005029 = v000070 * v000070;
  const Scalar v009422 = v000056 * v002295;
  const Scalar v005047 = v009421 + v009424;
  const Scalar v000109 = _imu_t_cam(1, 0);
  const Scalar v000094 = _imu_t_cam(0, 0);
  const Scalar v011457 = -static_cast<Scalar>(2);
  const Scalar v005056 = v005028 + v005050;
  const Scalar v000119 = _imu_t_cam(2, 0);
  const Scalar v005014 = v009420 + v009425;
  const Scalar v005051 = v005029 + v005050;
  const Scalar v005022 = v009422 + v009423;
  const Scalar v005030 = v005028 + v005029;
  const Scalar v000169 = _world_v_imu(2, 0);
  const Scalar v002319 =
      v000003 * v000056 + -(v000063 * v000065 + v000051 * v002295 + v000058 * v000070);
  const Scalar v000124 = _world_v_imu(1, 0);
  const Scalar v002396 =
      v000051 * v000063 + -(v000003 * v000070 + v000065 * v002295 + v000056 * v000058);
  const Scalar v000141 = _world_v_imu(0, 0);
  const Scalar v002307 =
      v000065 * v000070 + -(v000003 * v002295 + v000051 * v000056 + v000058 * v000063);
  const Scalar v002378 =
      v000058 * v002295 + -(v000003 * v000063 + v000056 * v000065 + v000051 * v000070);
  const Scalar v000159 = _world_t_imu(2, 0);
  const Scalar v011501 = -v002319;
  const Scalar v000092 = _world_t_imu(1, 0);
  const Scalar v006301 = v002396 * v002396;
  const Scalar v006232 = v002319 * v002319;
  const Scalar v000129 = _world_t_imu(0, 0);
  const Scalar v011500 = -v002307;
  const Scalar v006233 = v002307 * v002307;
  const Scalar v009924 = v002378 * v002396;
  const Scalar v009901 = v002307 * v002319;
  const Scalar v009903 = v002307 * v002396;
  const Scalar v006303 = v006232 + v006301;
  const Scalar v009914 = v002319 * v002396;
  const Scalar v009913 = v002319 * v002378;
  const Scalar v006234 = v006232 + v006233;
  const Scalar v009902 = v002307 * v002378;
  const Scalar v006312 = v006233 + v006301;
  const Scalar v006291 = v009901 + v009924;
  const Scalar v000158 = _p_world(2, 0);
  const Scalar v006287 = v002378 * v011501 + v009903;
  const Scalar v000091 = _p_world(1, 0);
  const Scalar v000128 = _p_world(0, 0);
  const Scalar v006226 = v002378 * v011500 + v009914;
  const Scalar v006283 = v009903 + v009913;
  const Scalar v006230 = v009902 + v009914;
  const Scalar v006295 = v002396 * -v002378 + v009901;
  const Scalar v007458 = static_cast<Scalar>(2) * v006291;
  const Scalar v002390 =
      v000158 +
      -(v000159 + v000119 * (static_cast<Scalar>(1) + v005056 * v011457) + v000007 * v000169 +
        static_cast<Scalar>(2) * (v000094 * (v000056 * v011498 + v009423) + v000109 * v005047));
  const Scalar v007524 = static_cast<Scalar>(2) * v006287;
  const Scalar v002354 =
      v000091 +
      -(v000092 + v000109 * (static_cast<Scalar>(1) + v005051 * v011457) + v000007 * v000124 +
        static_cast<Scalar>(2) * (v000094 * v005014 + v000119 * (v000063 * v011498 + v009421)));
  const Scalar v002401 = static_cast<Scalar>(1) + v006303 * v011457;
  const Scalar v002366 =
      v000128 +
      -(v000129 + v000094 * (static_cast<Scalar>(1) + v005030 * v011457) + v000007 * v000141 +
        static_cast<Scalar>(2) * (v000109 * (v000070 * v011498 + v009420) + v000119 * v005022));
  const Scalar v007523 = static_cast<Scalar>(2) * v006226;
  const Scalar v007446 = static_cast<Scalar>(2) * v006283;
  const Scalar v002324 = static_cast<Scalar>(1) + v006234 * v011457;
  const Scalar v007410 = static_cast<Scalar>(2) * v006230;
  const Scalar v007434 = static_cast<Scalar>(2) * v006295;
  const Scalar v002406 = static_cast<Scalar>(1) + v006312 * v011457;
  const Scalar v000192 = v002366 * v002401 + v002354 * v007524 + v002390 * v007458;
  const Scalar v000181 = v002324 * v002354 + v002366 * v007446 + v002390 * v007523;
  const Scalar v000201 = v002390 * v002406 + v002366 * v007434 + v002354 * v007410;
  const Scalar v008374 = v000192 * v000192;
  const Scalar v008366 = v000181 * v000181;
  const Scalar v009692 = v000201 * v000201;
  const Scalar v002409 = v008366 + v008374;
  const Scalar v000203 = static_cast<Scalar>(1) / v009692;
  const Scalar v008182 = v000203 * v002409;
  const Scalar v009729 = camera.k3 * v008182;
  const Scalar v000212 = camera.k2;
  const Scalar v000210 = camera.k1;
  const Scalar v000205 = camera.p1;
  const Scalar v007409 = static_cast<Scalar>(2) * v000192;
  const Scalar v007408 = static_cast<Scalar>(2) * v000181;
  const Scalar v000342 = static_cast<Scalar>(1) / (v000201 * v009692);
  const Scalar v000223 = camera.p2;
  const Scalar v002415 =
      static_cast<Scalar>(1) + (v000210 + (v000212 + v009729) * v008182) * v008182;
  const Scalar v005095 = static_cast<Scalar>(1) + static_cast<Scalar>(1);
  const Scalar v002612 = v000203 * v002415;
  const Scalar v007405 = static_cast<Scalar>(2) * v005095;
  const Scalar v007552 = v005095 * v011457;
  const Scalar v011516 = -v000342;
  const Scalar v007407 =
      static_cast<Scalar>(2) *
      (v000210 + (static_cast<Scalar>(3) * v009729 + static_cast<Scalar>(2) * v000212) * v008182);
  const Scalar v003081 = v000192 * v007409 + static_cast<Scalar>(6) * v008366;
  const Scalar v002587 = static_cast<Scalar>(6) * v008374 + v000181 * v007408;
  const Scalar v003090 = v002612 + v000223 * v000342 * v007409;
  const Scalar v007403 = static_cast<Scalar>(2) * v000203;
  const Scalar v002613 = v000342 * static_cast<Scalar>(4) * (v000181 * v000205) + v002612;
  const Scalar v011485 = -v000063;
  const Scalar v011461 = -v000046;
  const Scalar v011482 = -v000056;
  const Scalar v007471 = static_cast<Scalar>(2) * v000119;
  const Scalar v007470 = static_cast<Scalar>(2) * v000094;
  const Scalar v007668 = v002396 * v007405;
  const Scalar v007665 = v002319 * v007405;
  const Scalar v007522 = static_cast<Scalar>(2) * v000109;
  const Scalar v008093 = v000094 * v007552;
  const Scalar v007683 = v002307 * v007405;
  const Scalar v008130 = v000109 * v007552;
  const Scalar v008172 = v000119 * v007552;
  const Scalar v007605 = static_cast<Scalar>(2) * v002390;
  const Scalar v007604 = static_cast<Scalar>(2) * v002366;
  const Scalar v007603 = static_cast<Scalar>(2) * v002354;
  const Scalar v007532 = v002409 * v011516;
  const Scalar v007435 = v000181 * static_cast<Scalar>(3);
  const Scalar v007437 = v000192 * static_cast<Scalar>(3);
  const Scalar v007426 = v000181 * v007407;
  const Scalar v007504 = v003081 * v011516;
  const Scalar v007420 = v000192 * v007407;
  const Scalar v007484 = v002587 * v011516;
  const Scalar v000217 = static_cast<Scalar>(1) / v000201;
  const Scalar v007428 = v000203 * v000223;
  const Scalar v007540 = v003090 * -v000181;
  const Scalar v007406 = static_cast<Scalar>(2) * v000205;
  const Scalar v007430 = v000205 * v007403;
  const Scalar v007537 = v002613 * -v000192;
  const Scalar v000241 = static_cast<Scalar>(-0.5);
  const Scalar v000236 = camera.fy;
  const Scalar v000226 = camera.fx;
  if (static_cast<bool>(_D_world_R_imu)) {
    const Scalar v011488 = -v000070;
    const Scalar v009335 = v000042 * v000063;
    const Scalar v009332 = v000037 * v002295;
    const Scalar v009338 = v000042 * v002295;
    const Scalar v009309 = v000031 * v000056;
    const Scalar v005084 = v000031 * v000070;
    const Scalar v009341 = v000046 * v000056;
    const Scalar v002434 = v000037 * v011498;
    const Scalar v002440 = v000042 * v000056;
    const Scalar v009343 = v000046 * v000063;
    const Scalar v002511 = v000037 * v000063;
    const Scalar v002517 = v009332 + v009335;
    const Scalar v009331 = v000037 * v000070;
    const Scalar v009311 = v000031 * v002295;
    const Scalar v009337 = v000042 * v000070;
    const Scalar v009345 = v000046 * v002295;
    const Scalar v009330 = v000037 * v000056;
    const Scalar v011389 = v005084 + v000042 * v011485;
    const Scalar v011386 = v002440 + v000037 * v011488;
    const Scalar v009310 = v000031 * v000063;
    const Scalar v009344 = v000046 * v000070;
    const Scalar v005367 = v000031 * v011482;
    const Scalar v002512 = v000042 * v011498 + v002511;
    const Scalar v011391 = v005084 + v009341;
    const Scalar v011456 = v009331 + v009343;
    const Scalar v011388 = v000056 * v011461 + v005084;
    const Scalar v005129 = v000070 * v011461;
    const Scalar v011392 = v000037 * v011482 + v009337;
    const Scalar v011387 = v002440 + v009331;
    const Scalar v002683 = v009311 + v009343;
    const Scalar v011455 = v009330 + v009337;
    const Scalar v011377 = v000031 * v000058 + (v000003 * v000046 + v000037 * v000051);
    const Scalar v002676 = v000046 * v011498;
    const Scalar v011381 = v000042 * v000058 + (v000031 * v000065 + v000046 * v000051);
    const Scalar v005352 = v009310 + v009337;
    const Scalar v011390 = v005084 + v009335;
    const Scalar v011369 = v000037 * v000058 + (v000003 * v000042 + v000046 * v000065);
    const Scalar v011373 = v000042 * v000051 + (v000003 * v000031 + v000037 * v000065);
    const Scalar v002701 = v009310 + v009345;
    const Scalar v002713 = v009332 + v009341;
    const Scalar v006624 = v000094 * ((v000031 * v011498 + v009343) + v011386);
    const Scalar v011454 = v009309 + v009344;
    const Scalar v009533 = v000109 * v007405;
    const Scalar v009605 = v000119 * v007405;
    const Scalar v002473 = v000042 * v000065 + -v011377;
    const Scalar v000493 = v000058 * v011461 + v011373;
    const Scalar v000436 = v000051 * v011462 + v011369;
    const Scalar v002552 = v000003 * v000037 + -v011381;
    const Scalar v002496 = v000031 * v000051 + -v011369;
    const Scalar v000663 = v000003 * v011463 + v011381;
    const Scalar v009464 = v000094 * v007405;
    const Scalar v002461 = v000046 * v000058 + -v011373;
    const Scalar v000595 = v000065 * v011464 + v011377;
    const Scalar v006644 = v002473 * v007668;
    const Scalar v005234 = v000493 * v007665;
    const Scalar v009904 = v002307 * v002473;
    const Scalar v006533 = v000436 * v002396;
    const Scalar v009916 = v002319 * v002552;
    const Scalar v005283 = v000493 * v002378;
    const Scalar v005203 = v000436 * v007683;
    const Scalar v009773 = v000493 * v002396;
    const Scalar v006249 = v002319 * v002473;
    const Scalar v009905 = v002307 * v002552;
    const Scalar v005196 = v000436 * v002378;
    const Scalar v002542 = ((v002511 + v009338) + v011454) * v007470;
    const Scalar v006742 = v002496 * v007665;
    const Scalar v005359 = v000663 * v007668;
    const Scalar v006439 = v002378 * v002496;
    const Scalar v005356 = v000493 * v007683;
    const Scalar v009926 = v002396 * v002496;
    const Scalar v006501 = v002496 * v007668;
    const Scalar v006495 = v002552 * v007665;
    const Scalar v009925 = v002396 * v002473;
    const Scalar v006433 = v002307 * v002496;
    const Scalar v006475 = v002378 * v002552;
    const Scalar v006474 = v002319 * v002461;
    const Scalar v006550 = v002473 * v007683;
    const Scalar v009915 = v002319 * v002496;
    const Scalar v006378 = v002396 * v002552;
    const Scalar v006522 = v002378 * v002473;
    const Scalar v006521 = v002307 * v002461;
    const Scalar v005322 = v000595 * v007665;
    const Scalar v005295 = v000493 * v007668;
    const Scalar v009771 = v000493 * v002307;
    const Scalar v005289 = v000595 * v002378;
    const Scalar v006699 = v002552 * v007683;
    const Scalar v009772 = v000493 * v002319;
    const Scalar v002719 = (v002701 + -v011455) * v007470 + (v002511 + v005129) * v009533 +
                           (v002713 + v011390) * v007471;
    const Scalar v006628 =
        (v002511 + v005367) * v009605 +
        static_cast<Scalar>(2) * (v006624 + v000109 * ((v002434 + v009341) + v011389));
    const Scalar v002693 = v008093 * v011454 + ((v002676 + v009310) + v011392) * v007522 +
                           (v002683 + -v011387) * v007471;
    const Scalar v002932 = v002542 + ((v009330 + v009345) + -v005352) * v007522 +
                           (v002440 + v000063 * v011461) * v009605;
    const Scalar v002993 = (v002713 + -v011390) * v007470 + v008130 * v011456 +
                           ((v002676 + v009330) + v000042 * v011488 + v009310) * v007471;
    const Scalar v006729 =
        v009464 * v011386 + static_cast<Scalar>(2) * (v000109 * (v011391 + -v002517) +
                                                      v000119 * (v002512 + v005367 + v009344));
    const Scalar v011423 = v000663 * v002307 + v009773;
    const Scalar v011339 = v006249 + v006439;
    const Scalar v011421 = v000663 * v002319 + v009926;
    const Scalar v011338 = v005283 + v009904;
    const Scalar v002545 = v002542 + v005352 * v008130 + (v011387 + -v002683) * v007471;
    const Scalar v006425 = (v009310 + v009330) * v008172 +
                           static_cast<Scalar>(2) * (v000094 * ((v002434 + v009335) + v011388) +
                                                     v000109 * ((v002440 + v009311) + v011456));
    const Scalar v006612 =
        v008093 * v011455 + static_cast<Scalar>(2) * (v000109 * (v002512 + v005129 + v009309) +
                                                      v000119 * (v002517 + v011391));
    const Scalar v011342 = v006378 + v009915;
    const Scalar v002798 = (v011455 + -v002701) * v007470 +
                           ((v009338 + v009344) + -(v002511 + v009309)) * v007522 +
                           (v009335 + v009341) * v008172;
    const Scalar v006705 =
        v009533 * v011389 +
        static_cast<Scalar>(2) * (v006624 + v000119 * (v002511 + v009344 + -(v009309 + v009338)));
    const Scalar v006710 =
        v009464 * v011388 +
        static_cast<Scalar>(2) *
            (v000109 * (v002683 + v011387) + v000119 * ((v000031 * v011485 + v009345) + v011392));
    const Scalar v005284 = v000595 * v002307;
    const Scalar v011425 = v000595 * v002396 + v009772;
    const Scalar v011345 = v006433 + v006475;
    const Scalar v011427 = v000436 * v002319 + v009771;
    const Scalar v011341 = v006378 + v006522;
    const Scalar v011419 = v000663 * v002378 + v009925;
    const Scalar v011346 = v006433 + v009772;
    const Scalar v006444 = v002396 * v002461;
    const Scalar v011340 = v006249 + v009905;
    const Scalar v005242 =
        v002354 * ((v005283 + v009916) * v011457 + static_cast<Scalar>(2) * (v006533 + v009904)) +
        (v011341 + v011427) * v007605 +
        -(v002401 * v002693 + v002366 * (v005234 + v006644) + v006628 * v007458 +
          v002719 * v007524);
    const Scalar v005256 =
        (v006533 + v009916 + v011338) * v007604 +
        v002390 * ((v005196 + v009905) * v011457 + static_cast<Scalar>(2) * (v006249 + v009773)) +
        -(v002324 * v002719 + v002354 * (v005203 + v005234) + v006628 * v007523 +
          v002693 * v007446);
    const Scalar v005404 = v002354 * (v011339 * v011457 + static_cast<Scalar>(2) * v011423) +
                           (v011346 + v011419) * v007605 +
                           -(v002401 * v006729 + v002366 * (v005359 + v006742) + v002993 * v007524 +
                             v002932 * v007458);
    const Scalar v005415 = (v011339 + v011423) * v007604 +
                           v002390 * (v011338 * v011457 + static_cast<Scalar>(2) * v011421) +
                           -(v002324 * v002993 + v002354 * (v005356 + v006742) + v006729 * v007446 +
                             v002932 * v007523);
    const Scalar v005167 =
        v002354 * ((v006474 + v006475) * v011457 + static_cast<Scalar>(2) * (v006433 + v009925)) +
        (v006444 + v009905 + v011339) * v007605 +
        -(v002401 * v006612 + v002366 * (v006495 + v006501) + v006425 * v007458 +
          v002545 * v007524);
    const Scalar v005174 =
        (v006474 + v009925 + v011345) * v007604 +
        v002390 * ((v006521 + v006522) * v011457 + static_cast<Scalar>(2) * v011342) +
        -(v002324 * v002545 + v002354 * (v006495 + v006550) + v006425 * v007523 +
          v006612 * v007446);
    const Scalar v005330 =
        v002354 * ((v005289 + v009915) * v011457 + static_cast<Scalar>(2) * (v006378 + v009771)) +
        ((v005283 + v005284) + v009916 + v009926) * v007605 +
        -(v002401 * v006710 + v002366 * (v005295 + v005322) + v006705 * v007524 +
          v002798 * v007458);
    const Scalar v005341 = ((v005289 + v009771) + v011342) * v007604 +
                           v002390 * (v011345 * v011457 + static_cast<Scalar>(2) * v011425) +
                           -(v002324 * v006705 + v002354 * (v005322 + v006699) + v002798 * v007523 +
                             v006710 * v007446);
    const Scalar v009675 = v000192 * v005242;
    const Scalar v009649 = v000181 * v005256;
    const Scalar v009677 = v000192 * v005404;
    const Scalar v009651 = v000181 * v005415;
    const Scalar v009674 = v000192 * v005167;
    const Scalar v009648 = v000181 * v005174;
    const Scalar v009676 = v000192 * v005330;
    const Scalar v009650 = v000181 * v005341;
    const Scalar v005231 = v002366 * (v011341 * v011457 + static_cast<Scalar>(2) * v011427) +
                           ((v005196 + v009773) + v011340) * v007603 +
                           -(v002406 * v006628 + v002390 * (v005203 + v006644) + v002693 * v007434 +
                             v002719 * v007410);
    const Scalar v005393 = v002366 * (v011419 * v011457 + static_cast<Scalar>(2) * v011346) +
                           (v011338 + v011421) * v007603 +
                           -(v002406 * v002932 + v002390 * (v005356 + v005359) + v006729 * v007434 +
                             v002993 * v007410);
    const Scalar v005160 =
        v002366 * ((v006439 + v006444) * v011457 + static_cast<Scalar>(2) * v011340) +
        (v006521 + v009915 + v011341) * v007603 +
        -(v002406 * v006425 + v002390 * (v006501 + v006550) + v006612 * v007434 +
          v002545 * v007410);
    const Scalar v005316 =
        v002366 * ((v005283 + v009926) * v011457 + static_cast<Scalar>(2) * (v005284 + v009916)) +
        (v011345 + v011425) * v007603 +
        -(v002406 * v002798 + v002390 * (v005295 + v006699) + v006705 * v007410 +
          v006710 * v007434);
    const Scalar v006671 = v005231 * v007532 + v000203 * (v009649 + v009675);
    const Scalar v006753 = v005393 * v007532 + v000203 * (v009651 + v009677);
    const Scalar v006622 = v005160 * v007532 + v000203 * (v009648 + v009674);
    const Scalar v006720 = v005316 * v007532 + v000203 * (v009650 + v009676);
    const Scalar v002771 = v000181 * v005242 + v000192 * v005256;
    const Scalar v003045 = v000181 * v005404 + v000192 * v005415;
    const Scalar v002617 = v000181 * v005167 + v000192 * v005174;
    const Scalar v002906 = v000181 * v005330 + v000192 * v005341;
    const Scalar v003122 = (v005231 * v007504 + (v005256 * v007435 + v009675) * v007403) * v007406 +
                           v005231 * v007540 + v002771 * v007428 +
                           v000217 * (v002415 * v005256 + v006671 * v007426);
    const Scalar v003166 = (v005393 * v007504 + (v005415 * v007435 + v009677) * v007403) * v007406 +
                           v005393 * v007540 + v003045 * v007428 +
                           v000217 * (v002415 * v005415 + v006753 * v007426);
    const Scalar v003100 = (v005160 * v007504 + (v005174 * v007435 + v009674) * v007403) * v007406 +
                           v005160 * v007540 + v002617 * v007428 +
                           v000217 * (v002415 * v005174 + v006622 * v007426);
    const Scalar v003144 = (v005316 * v007504 + (v005341 * v007435 + v009676) * v007403) * v007406 +
                           v005316 * v007540 + v002906 * v007428 +
                           v000217 * (v002415 * v005341 + v006720 * v007426);
    const Scalar v002777 = v000223 * (v005231 * v007484 + (v005242 * v007437 + v009649) * v007403) +
                           v005231 * v007537 + v002771 * v007430 +
                           v000217 * (v002415 * v005242 + v006671 * v007420);
    const Scalar v003051 = v000223 * (v005393 * v007484 + (v005404 * v007437 + v009651) * v007403) +
                           v005393 * v007537 + v003045 * v007430 +
                           v000217 * (v002415 * v005404 + v006753 * v007420);
    const Scalar v002623 = v000223 * (v005160 * v007484 + (v005167 * v007437 + v009648) * v007403) +
                           v005160 * v007537 + v002617 * v007430 +
                           v000217 * (v002415 * v005167 + v006622 * v007420);
    const Scalar v002912 = v000223 * (v005316 * v007484 + (v005330 * v007437 + v009650) * v007403) +
                           v005316 * v007537 + v002906 * v007430 +
                           v000217 * (v002415 * v005330 + v006720 * v007420);
    _D_world_R_imu(0, 0) = v000226 * (v000241 * (v000004 * v002623 + v000034 * v002777) +
                                      v000018 * (v000039 * v002912 + v000044 * v003051));
    _D_world_R_imu(0, 1) = v000226 * (v000241 * (v000034 * v002623 + v000039 * v003051) +
                                      v000018 * (v000004 * v002777 + v000044 * v002912));
    _D_world_R_imu(0, 2) = v000226 * (v000241 * (v000004 * v002912 + v000039 * v002623) +
                                      v000018 * (v000034 * v003051 + v000044 * v002777));
    _D_world_R_imu(1, 0) = v000236 * (v000241 * (v000004 * v003100 + v000034 * v003122) +
                                      v000018 * (v000039 * v003144 + v000044 * v003166));
    _D_world_R_imu(1, 1) = v000236 * (v000241 * (v000034 * v003100 + v000039 * v003166) +
                                      v000018 * (v000004 * v003122 + v000044 * v003144));
    _D_world_R_imu(1, 2) = v000236 * (v000241 * (v000004 * v003144 + v000039 * v003100) +
                                      v000018 * (v000034 * v003166 + v000044 * v003122));
  }
  const Scalar v008225 = v006291 * v011457;
  const Scalar v009756 = static_cast<Scalar>(3) * v007408;
  const Scalar v007677 = v006230 * v011457;
  const Scalar v007423 = v000342 * v002409;
  const Scalar v008215 = v006283 * v011457;
  const Scalar v008914 = static_cast<Scalar>(3) * v007409;
  const Scalar v007425 = v000342 * v003081;
  const Scalar v007424 = v000342 * v002587;
  const Scalar v003306 = v002415 * v008225;
  const Scalar v007414 = v000181 * v003090;
  const Scalar v007417 = v000192 * v002613;
  if (static_cast<bool>(_D_world_t_imu)) {
    const Scalar v006239 = v002396 * v011501 + v009902;
    const Scalar v007865 = v000192 * v011457;
    const Scalar v006308 = v002396 * v011500 + v009913;
    const Scalar v006236 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v006234;
    const Scalar v006305 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v006303;
    const Scalar v007839 = v000181 * v011457;
    const Scalar v010562 = v006239 * v007408;
    const Scalar v005485 = v006291 * v007865;
    const Scalar v010684 = v006308 * v007409;
    const Scalar v009656 = v000181 * v006236;
    const Scalar v009684 = v000192 * v006305;
    const Scalar v005465 = v006283 * v007839;
    const Scalar v006314 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v006312;
    const Scalar v008236 = (v002319 * v011500 + v009924) * v011457;
    const Scalar v006765 = v006314 * v007532 + v000203 * (v005485 + v010562);
    const Scalar v007648 = static_cast<Scalar>(2) * v002415;
    const Scalar v006761 = v007532 * v007677 + v000203 * (v009656 + v010684);
    const Scalar v006757 = v007423 * v008236 + v000203 * (v005465 + v009684);
    const Scalar v003304 = v006291 * v007839 + v006239 * v007409;
    const Scalar v003265 = v000192 * v006236 + v006308 * v007408;
    const Scalar v003226 = v000181 * v006305 + v006283 * v007865;
    _D_world_t_imu(0, 0) =
        v000226 *
        (v000223 * (v007424 * v008236 + (v006305 * v007437 + v005465) * v007403) +
         v007417 * v008236 + v003226 * v007430 + v000217 * (v002415 * v006305 + v006757 * v007420));
    _D_world_t_imu(0, 1) =
        v000226 *
        (v000223 * (v007484 * v007677 + (v006308 * v008914 + v009656) * v007403) +
         v007537 * v007677 + v003265 * v007430 + v000217 * (v006308 * v007648 + v006761 * v007420));
    _D_world_t_imu(0, 2) =
        v000226 * (v000223 * (v006314 * v007484 + (v007437 * v008225 + v010562) * v007403) +
                   v006314 * v007537 + v003304 * v007430 + v000217 * (v003306 + v006765 * v007420));
    _D_world_t_imu(1, 0) =
        v000236 *
        ((v007425 * v008236 + (v007435 * v008215 + v009684) * v007403) * v007406 +
         v007414 * v008236 + v003226 * v007428 + v000217 * (v002415 * v008215 + v006757 * v007426));
    _D_world_t_imu(1, 1) =
        v000236 *
        ((v007504 * v007677 + (v006236 * v007435 + v010684) * v007403) * v007406 +
         v007540 * v007677 + v003265 * v007428 + v000217 * (v002415 * v006236 + v006761 * v007426));
    _D_world_t_imu(1, 2) =
        v000236 *
        ((v006314 * v007504 + (v005485 + v006239 * v009756) * v007403) * v007406 +
         v006314 * v007540 + v003304 * v007428 + v000217 * (v006239 * v007648 + v006765 * v007426));
  }
  if (static_cast<bool>(_D_imu_R_cam)) {
    const Scalar v003411 = v000004 * v000042 + -v011357;
    const Scalar v003423 = v000031 * v000034 + -v011365;
    const Scalar v001050 = v000044 * v011461 + v011385;
    const Scalar v003394 = v000037 * v000039 + -v011361;
    const Scalar v009927 = v002396 * v003411;
    const Scalar v005525 = v000063 * v002307;
    const Scalar v009918 = v002319 * v003423;
    const Scalar v005526 = v001050 * v002378;
    const Scalar v009826 = v001050 * v002396;
    const Scalar v006769 = v002307 * v003423;
    const Scalar v006767 = v002378 * v003411;
    const Scalar v009917 = v002319 * v003394;
    const Scalar v005531 = v000056 * v002396;
    const Scalar v009906 = v002307 * v003394;
    const Scalar v009907 = v002307 * v003411;
    const Scalar v006792 = v002396 * v003394;
    const Scalar v006794 = v002295 * v002319;
    const Scalar v006793 = v002378 * v003423;
    const Scalar v009928 = v002396 * v003423;
    const Scalar v006390 = v002319 * v003411;
    const Scalar v006852 = v002295 * v002307;
    const Scalar v006851 = v002378 * v003394;
    const Scalar v009824 = v001050 * v002307;
    const Scalar v009825 = v001050 * v002319;
    const Scalar v005521 = v000063 * v002378;
    const Scalar v011430 = v000063 * v002319 + v009826;
    const Scalar v011348 = v006767 + v006769;
    const Scalar v011349 = v006769 + v009826;
    const Scalar v011417 = v000056 * v002378 + v009917;
    const Scalar v011395 = v005526 + v009906;
    const Scalar v011344 = v006390 + v009928;
    const Scalar v011435 = v000070 * v002396 + v009824;
    const Scalar v011343 = v006390 + v006851;
    const Scalar v011352 = v006792 + v009825;
    const Scalar v011415 = v000070 * v002378 + v009907;
    const Scalar v005541 = v001050 * v007665;
    const Scalar v005537 = v000063 * v007668;
    const Scalar v006950 = v003411 * v007683;
    const Scalar v011432 = v000056 * v002307 + v009825;
    const Scalar v011351 = v006792 + v006793;
    const Scalar v006986 = v003423 * v007668;
    const Scalar v005587 = v000056 * v007665;
    const Scalar v005583 = v001050 * v007683;
    const Scalar v006774 = v002295 * v002396;
    const Scalar v006826 = v003423 * v007665;
    const Scalar v006820 = v003411 * v007668;
    const Scalar v006886 = v003394 * v007683;
    const Scalar v006865 = v000070 * v002319;
    const Scalar v006968 = v003394 * v007665;
    const Scalar v005560 = v001050 * v007668;
    const Scalar v005563 = v000070 * v007683;
    const Scalar v011508 = -v002366;
    const Scalar v011513 = -v002354;
    const Scalar v001063 =
        (v005537 + v005541) * v011508 +
        v002354 * ((v005526 + v009918) * v011457 + static_cast<Scalar>(2) * (v005525 + v009927)) +
        ((v005521 + v009824) + v011344) * v007605;
    const Scalar v001074 = ((v005525 + v005526) + v009918 + v009927) * v007604 +
                           (v005541 + v006950) * v011513 +
                           v002390 * (v011348 * v011457 + static_cast<Scalar>(2) * v011430);
    const Scalar v011511 = -v002390;
    const Scalar v001176 = (v005587 + v006986) * v011508 +
                           v002354 * (v011417 * v011457 + static_cast<Scalar>(2) * v011349) +
                           (v011351 + v011432) * v007605;
    const Scalar v001185 =
        (v011349 + v011417) * v007604 + (v005583 + v005587) * v011513 +
        v002390 * (v011395 * v011457 + static_cast<Scalar>(2) * (v005531 + v009918));
    const Scalar v000990 =
        (v006820 + v006826) * v011508 +
        v002354 * ((v006793 + v006794) * v011457 + static_cast<Scalar>(2) * (v006792 + v009907)) +
        (v006774 + v009917 + v011348) * v007605;
    const Scalar v001002 =
        (v006794 + v009907 + v011351) * v007604 + (v006826 + v006886) * v011513 +
        v002390 * ((v006851 + v006852) * v011457 + static_cast<Scalar>(2) * v011344);
    const Scalar v001122 = (v005560 + v006968) * v011508 +
                           v002354 * (v011343 * v011457 + static_cast<Scalar>(2) * v011435) +
                           (v006865 + v009927 + v011395) * v007605;
    const Scalar v001131 = (v011343 + v011435) * v007604 + (v005563 + v006968) * v011513 +
                           v002390 * (v011415 * v011457 + static_cast<Scalar>(2) * v011352);
    const Scalar v009669 = v000192 * v001063;
    const Scalar v009643 = v000181 * v001074;
    const Scalar v009671 = v000192 * v001176;
    const Scalar v009645 = v000181 * v001185;
    const Scalar v009668 = v000192 * v000990;
    const Scalar v009642 = v000181 * v001002;
    const Scalar v009670 = v000192 * v001122;
    const Scalar v009644 = v000181 * v001131;
    const Scalar v001042 =
        v002366 * ((v005521 + v009928) * v011457 + static_cast<Scalar>(2) * (v006390 + v009824)) +
        (v011348 + v011430) * v007603 + (v005537 + v006950) * v011511;
    const Scalar v001163 = v002366 * (v011351 * v011457 + static_cast<Scalar>(2) * v011432) +
                           ((v005526 + v005531) + v009906 + v009918) * v007603 +
                           (v005583 + v006986) * v011511;
    const Scalar v000968 =
        v002366 * ((v006767 + v006774) * v011457 + static_cast<Scalar>(2) * (v006769 + v009917)) +
        (v006852 + v009928 + v011343) * v007603 + (v006820 + v006886) * v011511;
    const Scalar v001109 =
        v002366 * ((v005526 + v009927) * v011457 + static_cast<Scalar>(2) * (v006865 + v009906)) +
        (v011352 + v011415) * v007603 + (v005560 + v005563) * v011511;
    const Scalar v006961 = v001042 * v007532 + v000203 * (v009643 + v009669);
    const Scalar v006997 = v001163 * v007532 + v000203 * (v009645 + v009671);
    const Scalar v006931 = v000968 * v007532 + v000203 * (v009642 + v009668);
    const Scalar v006979 = v001109 * v007532 + v000203 * (v009644 + v009670);
    const Scalar v003548 = v000181 * v001063 + v000192 * v001074;
    const Scalar v003684 = v000181 * v001176 + v000192 * v001185;
    const Scalar v003474 = v000181 * v000990 + v000192 * v001002;
    const Scalar v003616 = v000181 * v001122 + v000192 * v001131;
    const Scalar v003761 = (v001042 * v007504 + (v001074 * v007435 + v009669) * v007403) * v007406 +
                           v001042 * v007540 + v003548 * v007428 +
                           v000217 * (v001074 * v002415 + v006961 * v007426);
    const Scalar v003805 = (v001163 * v007504 + (v001185 * v007435 + v009671) * v007403) * v007406 +
                           v001163 * v007540 + v003684 * v007428 +
                           v000217 * (v001185 * v002415 + v006997 * v007426);
    const Scalar v003739 = (v000968 * v007504 + (v001002 * v007435 + v009668) * v007403) * v007406 +
                           v000968 * v007540 + v003474 * v007428 +
                           v000217 * (v001002 * v002415 + v006931 * v007426);
    const Scalar v003783 = (v001109 * v007504 + (v001131 * v007435 + v009670) * v007403) * v007406 +
                           v001109 * v007540 + v003616 * v007428 +
                           v000217 * (v001131 * v002415 + v006979 * v007426);
    const Scalar v003554 = v000223 * (v001042 * v007484 + (v001063 * v007437 + v009643) * v007403) +
                           v001042 * v007537 + v003548 * v007430 +
                           v000217 * (v001063 * v002415 + v006961 * v007420);
    const Scalar v003690 = v000223 * (v001163 * v007484 + (v001176 * v007437 + v009645) * v007403) +
                           v001163 * v007537 + v003684 * v007430 +
                           v000217 * (v001176 * v002415 + v006997 * v007420);
    const Scalar v003480 = v000223 * (v000968 * v007484 + (v000990 * v007437 + v009642) * v007403) +
                           v000968 * v007537 + v003474 * v007430 +
                           v000217 * (v000990 * v002415 + v006931 * v007420);
    const Scalar v003622 = v000223 * (v001109 * v007484 + (v001122 * v007437 + v009644) * v007403) +
                           v001109 * v007537 + v003616 * v007430 +
                           v000217 * (v001122 * v002415 + v006979 * v007420);
    _D_imu_R_cam(0, 0) = v000226 * (v000241 * (v000003 * v003480 + v000065 * v003554) +
                                    v000018 * (v000051 * v003622 + v000058 * v003690));
    _D_imu_R_cam(0, 1) = v000226 * (v000241 * (v000065 * v003480 + v000051 * v003690) +
                                    v000018 * (v000003 * v003554 + v000058 * v003622));
    _D_imu_R_cam(0, 2) = v000226 * (v000241 * (v000003 * v003622 + v000051 * v003480) +
                                    v000018 * (v000065 * v003690 + v000058 * v003554));
    _D_imu_R_cam(1, 0) = v000236 * (v000241 * (v000003 * v003739 + v000065 * v003761) +
                                    v000018 * (v000051 * v003783 + v000058 * v003805));
    _D_imu_R_cam(1, 1) = v000236 * (v000241 * (v000065 * v003739 + v000051 * v003805) +
                                    v000018 * (v000003 * v003761 + v000058 * v003783));
    _D_imu_R_cam(1, 2) = v000236 * (v000241 * (v000003 * v003783 + v000051 * v003739) +
                                    v000018 * (v000065 * v003805 + v000058 * v003761));
  }
  const Scalar v008014 = v006295 * v011457;
  if (static_cast<bool>(_D_imu_t_cam)) {
    const Scalar v005061 = v000070 * v011482 + v009424;
    const Scalar v005039 = v000063 * v011482 + v009425;
    const Scalar v005035 = v000070 * v011485 + v009422;
    const Scalar v005058 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v005056;
    const Scalar v005053 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v005051;
    const Scalar v005032 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v005030;
    const Scalar v006348 =
        v005058 * v007458 + static_cast<Scalar>(2) * (v002401 * -v005022 + v005061 * v007524);
    const Scalar v006329 =
        v005058 * v007523 + static_cast<Scalar>(2) * (v002324 * v005061 + v005022 * v008215);
    const Scalar v006343 =
        v005053 * v007524 + static_cast<Scalar>(2) * (v002401 * v005039 + v005047 * v008225);
    const Scalar v006324 =
        v002324 * v005053 +
        static_cast<Scalar>(2) * (v005039 * v007446 + v006226 * (v005047 * v011457));
    const Scalar v006338 =
        v002401 * v005032 +
        static_cast<Scalar>(2) * (v006287 * (v005014 * v011457) + v005035 * v007458);
    const Scalar v006319 =
        v005032 * v007446 + static_cast<Scalar>(2) * (v002324 * -v005014 + v005035 * v007523);
    const Scalar v009688 = v000192 * v006348;
    const Scalar v009662 = v000181 * v006329;
    const Scalar v009687 = v000192 * v006343;
    const Scalar v009661 = v000181 * v006324;
    const Scalar v009686 = v000192 * v006338;
    const Scalar v009660 = v000181 * v006319;
    const Scalar v006367 =
        v002406 * v005058 + static_cast<Scalar>(2) * (v005022 * v008014 + v005061 * v007410);
    const Scalar v006362 =
        v005053 * v007410 + static_cast<Scalar>(2) * (v005047 * -v002406 + v005039 * v007434);
    const Scalar v006357 =
        v005032 * v007434 + static_cast<Scalar>(2) * (v002406 * v005035 + v005014 * v007677);
    const Scalar v007009 = v006367 * v007532 + v000203 * (v009662 + v009688);
    const Scalar v007005 = v006362 * v007532 + v000203 * (v009661 + v009687);
    const Scalar v007001 = v006357 * v007532 + v000203 * (v009660 + v009686);
    const Scalar v003943 = v000192 * v006329 + v000181 * v006348;
    const Scalar v003904 = v000192 * v006324 + v000181 * v006343;
    const Scalar v003865 = v000181 * v006338 + v000192 * v006319;
    _D_imu_t_cam(0, 0) =
        v000226 *
        (v000223 * (v006357 * v007484 + (v006338 * v007437 + v009660) * v007403) +
         v006357 * v007537 + v003865 * v007430 + v000217 * (v002415 * v006338 + v007001 * v007420));
    _D_imu_t_cam(0, 1) =
        v000226 *
        (v000223 * (v006362 * v007484 + (v006343 * v007437 + v009661) * v007403) +
         v006362 * v007537 + v003904 * v007430 + v000217 * (v002415 * v006343 + v007005 * v007420));
    _D_imu_t_cam(0, 2) =
        v000226 *
        (v000223 * (v006367 * v007484 + (v006348 * v007437 + v009662) * v007403) +
         v006367 * v007537 + v003943 * v007430 + v000217 * (v002415 * v006348 + v007009 * v007420));
    _D_imu_t_cam(1, 0) =
        v000236 *
        ((v006357 * v007504 + (v006319 * v007435 + v009686) * v007403) * v007406 +
         v006357 * v007540 + v003865 * v007428 + v000217 * (v002415 * v006319 + v007001 * v007426));
    _D_imu_t_cam(1, 1) =
        v000236 *
        ((v006362 * v007504 + (v006324 * v007435 + v009687) * v007403) * v007406 +
         v006362 * v007540 + v003904 * v007428 + v000217 * (v002415 * v006324 + v007005 * v007426));
    _D_imu_t_cam(1, 2) =
        v000236 *
        ((v006367 * v007504 + (v006329 * v007435 + v009688) * v007403) * v007406 +
         v006367 * v007540 + v003943 * v007428 + v000217 * (v002415 * v006329 + v007009 * v007426));
  }
  if (static_cast<bool>(_D_angular_velocity_imu)) {
    const Scalar v007709 = v000006 * v007433;
    const Scalar v008706 = v000006 * v007709;
    Scalar v001443;
    Scalar v001449;
    Scalar v001455;
    Scalar v001460;
    Scalar v001654;
    Scalar v001660;
    Scalar v001664;
    Scalar v001855;
    Scalar v001859;
    if (v000015) {
      const Scalar v011465 = -(static_cast<Scalar>(1) / (v000014 * v000014 * v000014));
      const Scalar v009877 = (static_cast<Scalar>(1) / v010294) * (v000018 * v000045);
      const Scalar v007013 = v000021 * v011465 + v009877;
      const Scalar v007762 = v000009 * v007433;
      const Scalar v007830 = v000011 * v007433;
      const Scalar v009231 = v007013 * v007830;
      const Scalar v008930 = v000241 * v007833;
      v001443 = v000007 * (v008706 * v009877 + v000021 * (v000017 + v008706 * v011465));
      v001449 = v007762 * (v007013 * v007586);
      v001455 = v007586 * v009231;
      v001460 = v007709 * v008930;
      v001654 = v000007 * (v007762 * (v000009 * v007013) + v007833);
      v001660 = v007627 * v009231;
      v001664 = v007762 * v008930;
      v001855 = v000007 * (v007830 * (v000011 * v007013) + v007833);
      v001859 = v007830 * v008930;
    } else {
      const Scalar v001439 = static_cast<Scalar>(1) / (v000028 * v000028 * v000028);
      const Scalar v001435 = static_cast<Scalar>(-0.125);
      const Scalar v007734 = v001439 * v007433;
      const Scalar v008191 = v001435 * v007734;
      const Scalar v001458 = static_cast<Scalar>(-0.25);
      const Scalar v009298 = v000011 * v008191;
      v001443 = v000007 * ((v001435 * v001439) * v008706 + v008271);
      v001449 = v008191 * (v000009 * v007586);
      v001455 = v007586 * v009298;
      v001460 = v007709 * (v001439 * v001458);
      v001654 = v000007 * (v008191 * v008721 + v008271);
      v001660 = v007627 * v009298;
      v001664 = v001458 * (v000009 * v007734);
      v001855 = v000007 * (v008191 * v008728 + v008271);
      v001859 = v001458 * (v000011 * v007734);
    }
    const Scalar v001676 = v000034 * v001660;
    const Scalar v001511 = v000004 * v001449;
    const Scalar v001882 = v000039 * v001455;
    const Scalar v011460 = -v000039;
    const Scalar v011458 = -v000004;
    const Scalar v011459 = -v000034;
    const Scalar v001513 = v000044 * v001455;
    const Scalar v001714 = v000044 * v001660;
    const Scalar v001487 = v000044 * v001449;
    const Scalar v001870 = v001513 + v001660 * v011460 + v000004 * v001859 + v000034 * v001855;
    const Scalar v004423 = v000044 * v001859 + -(v001676 + v000039 * v001855 + v000004 * v001455);
    const Scalar v001883 = v001714 + v001855 * v011458 + v000034 * v001859 + v001882;
    const Scalar v001908 =
        v001455 * v011459 + v000039 * v001859 + v000044 * v001855 + v000004 * v001660;
    const Scalar v001677 = v001487 + v001654 * v011460 + v000004 * v001664 + v001676;
    const Scalar v004232 = v000044 * v001664 + -(v001511 + v000034 * v001654 + v000039 * v001660);
    const Scalar v001691 =
        v001660 * v011458 + v000034 * v001664 + v000044 * v001654 + v000039 * v001449;
    const Scalar v001715 = v001449 * v011459 + v000004 * v001654 + v000039 * v001664 + v001714;
    const Scalar v001474 =
        v001449 * v011460 + v000004 * v001460 + v000044 * v001443 + v000034 * v001455;
    const Scalar v004037 = v000044 * v001460 + -(v001882 + v000004 * v001443 + v000034 * v001449);
    const Scalar v001488 = v001455 * v011458 + v000034 * v001460 + v000039 * v001443 + v001487;
    const Scalar v001514 = v001443 * v011459 + v001511 + v000039 * v001460 + v001513;
    const Scalar v011414 = v000063 * v004423 + v001870 * v002295;
    const Scalar v011410 = v000056 * v004423 + v001883 * v002295;
    const Scalar v011412 = v000070 * v004423 + v001908 * v002295;
    const Scalar v011408 = v000063 * v004232 + v001677 * v002295;
    const Scalar v011404 = v000056 * v004232 + v001691 * v002295;
    const Scalar v011406 = v000070 * v004232 + v001715 * v002295;
    const Scalar v011402 = v000063 * v004037 + v001474 * v002295;
    const Scalar v011398 = v000056 * v004037 + v001488 * v002295;
    const Scalar v011400 = v000070 * v004037 + v001514 * v002295;
    const Scalar v011413 = v000070 * v001883 + v000056 * v001908;
    const Scalar v007325 = v000070 * v001908;
    const Scalar v007237 = v000063 * v001870;
    const Scalar v011411 = v000056 * v001870 + v000063 * v001883;
    const Scalar v007236 = v000056 * v001883;
    const Scalar v011409 = v000070 * v001870 + v000063 * v001908;
    const Scalar v011407 = v000070 * v001691 + v000056 * v001715;
    const Scalar v007216 = v000070 * v001715;
    const Scalar v007128 = v000063 * v001677;
    const Scalar v011405 = v000056 * v001677 + v000063 * v001691;
    const Scalar v007127 = v000056 * v001691;
    const Scalar v011403 = v000070 * v001677 + v000063 * v001715;
    const Scalar v011401 = v000070 * v001488 + v000056 * v001514;
    const Scalar v007107 = v000070 * v001514;
    const Scalar v007019 = v000063 * v001474;
    const Scalar v011399 = v000056 * v001474 + v000063 * v001488;
    const Scalar v007018 = v000056 * v001488;
    const Scalar v011397 = v000070 * v001474 + v000063 * v001514;
    const Scalar v004542 =
        v000003 * v001883 + -(v000065 * v001870 + v000051 * v004423 + v000058 * v001908);
    const Scalar v004498 =
        v000051 * v001870 + -(v000003 * v001908 + v000065 * v004423 + v000058 * v001883);
    const Scalar v004475 =
        v000065 * v001908 + -(v000003 * v004423 + v000051 * v001883 + v000058 * v001870);
    const Scalar v004463 =
        v000058 * v004423 + -(v000003 * v001870 + v000065 * v001883 + v000051 * v001908);
    const Scalar v004351 =
        v000003 * v001691 + -(v000065 * v001677 + v000051 * v004232 + v000058 * v001715);
    const Scalar v004307 =
        v000051 * v001677 + -(v000003 * v001715 + v000065 * v004232 + v000058 * v001691);
    const Scalar v004284 =
        v000065 * v001715 + -(v000003 * v004232 + v000051 * v001691 + v000058 * v001677);
    const Scalar v004272 =
        v000058 * v004232 + -(v000003 * v001677 + v000065 * v001691 + v000051 * v001715);
    const Scalar v004156 =
        v000003 * v001488 + -(v000065 * v001474 + v000051 * v004037 + v000058 * v001514);
    const Scalar v004112 =
        v000051 * v001474 + -(v000003 * v001514 + v000065 * v004037 + v000058 * v001488);
    const Scalar v004089 =
        v000065 * v001514 + -(v000003 * v004037 + v000051 * v001488 + v000058 * v001474);
    const Scalar v004077 =
        v000058 * v004037 + -(v000003 * v001474 + v000065 * v001488 + v000051 * v001514);
    const Scalar v007272 = v004542 * v007665;
    const Scalar v007266 = v004498 * v007668;
    const Scalar v007294 = v004475 * v007683;
    const Scalar v007163 = v004351 * v007665;
    const Scalar v007157 = v004307 * v007668;
    const Scalar v007185 = v004284 * v007683;
    const Scalar v007054 = v004156 * v007665;
    const Scalar v007048 = v004112 * v007668;
    const Scalar v007076 = v004089 * v007683;
    const Scalar v004535 = (v011411 + v011412) * v007470 + (v007237 + v007325) * v008130 +
                           (v011413 + -v011414) * v007471;
    const Scalar v004456 = (v011409 + -v011410) * v007470 + (v011413 + v011414) * v007522 +
                           (v007236 + v007237) * v008172;
    const Scalar v004519 = (v007236 + v007325) * v008093 + (v011411 + -v011412) * v007522 +
                           (v011409 + v011410) * v007471;
    const Scalar v011450 = v002396 * v004475 + v002307 * v004498;
    const Scalar v011451 = v002319 * v004463 + v002378 * v004542;
    const Scalar v011453 = v002319 * v004498 + v002396 * v004542;
    const Scalar v011452 = v002307 * v004463 + v002378 * v004475;
    const Scalar v004344 = (v011405 + v011406) * v007470 + (v007128 + v007216) * v008130 +
                           (v011407 + -v011408) * v007471;
    const Scalar v004265 = (v011403 + -v011404) * v007470 + (v011407 + v011408) * v007522 +
                           (v007127 + v007128) * v008172;
    const Scalar v004328 = (v007127 + v007216) * v008093 + (v011405 + -v011406) * v007522 +
                           (v011403 + v011404) * v007471;
    const Scalar v011444 = v002396 * v004284 + v002307 * v004307;
    const Scalar v011445 = v002319 * v004272 + v002378 * v004351;
    const Scalar v011447 = v002319 * v004307 + v002396 * v004351;
    const Scalar v011446 = v002307 * v004272 + v002378 * v004284;
    const Scalar v004149 = (v011399 + v011400) * v007470 + (v007019 + v007107) * v008130 +
                           (v011401 + -v011402) * v007471;
    const Scalar v004070 = (v011397 + -v011398) * v007470 + (v011401 + v011402) * v007522 +
                           (v007018 + v007019) * v008172;
    const Scalar v004133 = (v007018 + v007107) * v008093 + (v011399 + -v011400) * v007522 +
                           (v011397 + v011398) * v007471;
    const Scalar v011438 = v002396 * v004089 + v002307 * v004112;
    const Scalar v011439 = v002319 * v004077 + v002378 * v004156;
    const Scalar v011441 = v002319 * v004112 + v002396 * v004156;
    const Scalar v011440 = v002307 * v004077 + v002378 * v004089;
    const Scalar v011449 = v002319 * v004475 + v002307 * v004542;
    const Scalar v011448 = v002396 * v004463 + v002378 * v004498;
    const Scalar v011443 = v002319 * v004284 + v002307 * v004351;
    const Scalar v011442 = v002396 * v004272 + v002378 * v004307;
    const Scalar v011437 = v002319 * v004089 + v002307 * v004156;
    const Scalar v011436 = v002396 * v004077 + v002378 * v004112;
    const Scalar v006063 = v002354 * (v011451 * v011457 + static_cast<Scalar>(2) * v011450) +
                           (v011448 + v011449) * v007605 +
                           -(v002401 * v004519 + v002366 * (v007266 + v007272) + v004456 * v007458 +
                             v004535 * v007524);
    const Scalar v006070 = (v011450 + v011451) * v007604 +
                           v002390 * (v011452 * v011457 + static_cast<Scalar>(2) * v011453) +
                           -(v002324 * v004535 + v002354 * (v007272 + v007294) + v004456 * v007523 +
                             v004519 * v007446);
    const Scalar v005930 = v002354 * (v011445 * v011457 + static_cast<Scalar>(2) * v011444) +
                           (v011442 + v011443) * v007605 +
                           -(v002401 * v004328 + v002366 * (v007157 + v007163) + v004265 * v007458 +
                             v004344 * v007524);
    const Scalar v005937 = (v011444 + v011445) * v007604 +
                           v002390 * (v011446 * v011457 + static_cast<Scalar>(2) * v011447) +
                           -(v002324 * v004344 + v002354 * (v007163 + v007185) + v004265 * v007523 +
                             v004328 * v007446);
    const Scalar v005797 = v002354 * (v011439 * v011457 + static_cast<Scalar>(2) * v011438) +
                           (v011436 + v011437) * v007605 +
                           -(v002401 * v004133 + v002366 * (v007048 + v007054) + v004070 * v007458 +
                             v004149 * v007524);
    const Scalar v005804 = (v011438 + v011439) * v007604 +
                           v002390 * (v011440 * v011457 + static_cast<Scalar>(2) * v011441) +
                           -(v002324 * v004149 + v002354 * (v007054 + v007076) + v004133 * v007446 +
                             v004070 * v007523);
    const Scalar v009680 = v000192 * v006063;
    const Scalar v009654 = v000181 * v006070;
    const Scalar v009679 = v000192 * v005930;
    const Scalar v009653 = v000181 * v005937;
    const Scalar v009678 = v000192 * v005797;
    const Scalar v009652 = v000181 * v005804;
    const Scalar v006056 = v002366 * (v011448 * v011457 + static_cast<Scalar>(2) * v011449) +
                           (v011452 + v011453) * v007603 +
                           -(v002406 * v004456 + v002390 * (v007266 + v007294) + v004519 * v007434 +
                             v004535 * v007410);
    const Scalar v005923 = v002366 * (v011442 * v011457 + static_cast<Scalar>(2) * v011443) +
                           (v011446 + v011447) * v007603 +
                           -(v002406 * v004265 + v002390 * (v007157 + v007185) + v004328 * v007434 +
                             v004344 * v007410);
    const Scalar v005790 = v002366 * (v011436 * v011457 + static_cast<Scalar>(2) * v011437) +
                           (v011440 + v011441) * v007603 +
                           -(v002406 * v004070 + v002390 * (v007048 + v007076) + v004133 * v007434 +
                             v004149 * v007410);
    const Scalar v007340 = v006056 * v007532 + v000203 * (v009654 + v009680);
    const Scalar v007231 = v005923 * v007532 + v000203 * (v009653 + v009679);
    const Scalar v007122 = v005790 * v007532 + v000203 * (v009652 + v009678);
    const Scalar v004593 = v000181 * v006063 + v000192 * v006070;
    const Scalar v004402 = v000181 * v005930 + v000192 * v005937;
    const Scalar v004207 = v000181 * v005797 + v000192 * v005804;
    _D_angular_velocity_imu(0, 0) =
        v000226 *
        (v000223 * (v005790 * v007484 + (v005797 * v007437 + v009652) * v007403) +
         v005790 * v007537 + v004207 * v007430 + v000217 * (v002415 * v005797 + v007122 * v007420));
    _D_angular_velocity_imu(0, 1) =
        v000226 *
        (v000223 * (v005923 * v007484 + (v005930 * v007437 + v009653) * v007403) +
         v005923 * v007537 + v004402 * v007430 + v000217 * (v002415 * v005930 + v007231 * v007420));
    _D_angular_velocity_imu(0, 2) =
        v000226 *
        (v000223 * (v006056 * v007484 + (v006063 * v007437 + v009654) * v007403) +
         v006056 * v007537 + v004593 * v007430 + v000217 * (v002415 * v006063 + v007340 * v007420));
    _D_angular_velocity_imu(1, 0) =
        v000236 *
        ((v005790 * v007504 + (v005804 * v007435 + v009678) * v007403) * v007406 +
         v005790 * v007540 + v004207 * v007428 + v000217 * (v002415 * v005804 + v007122 * v007426));
    _D_angular_velocity_imu(1, 1) =
        v000236 *
        ((v005923 * v007504 + (v005937 * v007435 + v009679) * v007403) * v007406 +
         v005923 * v007540 + v004402 * v007428 + v000217 * (v002415 * v005937 + v007231 * v007426));
    _D_angular_velocity_imu(1, 2) =
        v000236 *
        ((v006056 * v007504 + (v006070 * v007435 + v009680) * v007403) * v007406 +
         v006056 * v007540 + v004593 * v007428 + v000217 * (v002415 * v006070 + v007340 * v007426));
  }
  const Scalar v010527 = v006226 * v007408;
  const Scalar v010664 = v006291 * v007409;
  const Scalar v009646 = v000181 * v002324;
  const Scalar v010615 = v006287 * v007409;
  const Scalar v010610 = v006283 * v007408;
  const Scalar v009672 = v000192 * v002401;
  const Scalar v004760 = v006226 * v007409 + v006291 * v007408;
  const Scalar v004725 = v000192 * v002324 + v006287 * v007408;
  const Scalar v004690 = v000181 * v002401 + v006283 * v007409;
  const Scalar v006135 = v006291 * v008914 + v010527;
  const Scalar v006143 = v010527 + v010664;
  const Scalar v006114 = v006287 * v008914 + v009646;
  const Scalar v006122 = v009646 + v010615;
  const Scalar v006093 = v002401 * v007437 + v010610;
  const Scalar v006101 = v009672 + v010610;
  const Scalar v008386 = v000217 * v002415;
  const Scalar v006192 = v006226 * v009756 + v010664;
  const Scalar v004993 = v004760 * v007428;
  const Scalar v006174 = v002324 * v007435 + v010615;
  const Scalar v004971 = v004725 * v007428;
  const Scalar v006156 = v006283 * v009756 + v009672;
  const Scalar v004949 = v004690 * v007428;
  if (static_cast<bool>(_D_world_v_imu)) {
    const Scalar v007715 = v000203 * v011457;
    const Scalar v011517 = -v000203;
    const Scalar v011318 = (v000203 * v000205) * v011457;
    const Scalar v007380 = v006143 * v011517 + v002406 * v007423;
    const Scalar v007364 = v006122 * v011517 + v007410 * v007423;
    const Scalar v007348 = v006101 * v011517 + v007423 * v007434;
    const Scalar v008911 = v000217 * v007426;
    const Scalar v008708 = v000007 * v000217;
    const Scalar v008709 = v000007 * v000236;
    _D_world_v_imu(0, 0) =
        v000226 * ((v002401 * -v002415 + v007348 * v007420) * v008708 +
                   v000007 * ((v004690 * v011318 + v007409 * (v002613 * v006295)) +
                              v000223 * (v006093 * v007715 + v007424 * v007434)));
    _D_world_v_imu(0, 1) =
        v000226 * ((v006287 * (v002415 * v011457) + v007364 * v007420) * v008708 +
                   v000007 * ((v004725 * v011318 + v007409 * (v002613 * v006230)) +
                              v000223 * (v006114 * v007715 + v007410 * v007424)));
    _D_world_v_imu(0, 2) =
        v000226 * ((v003306 + v007380 * v007420) * v008708 +
                   v000007 * ((v004760 * v011318 + v002406 * v007417) +
                              v000223 * (v006135 * v007715 + v002406 * v007424)));
    _D_world_v_imu(1, 0) = ((v007408 * (v003090 * v006295) + -(v007446 * v008386 + v004949)) +
                            (v006156 * v007715 + v007425 * v007434) * v007406 + v007348 * v008911) *
                           v008709;
    _D_world_v_imu(1, 1) = ((v007408 * (v003090 * v006230) + -(v002324 * v008386 + v004971)) +
                            (v006174 * v007715 + v007410 * v007425) * v007406 + v007364 * v008911) *
                           v008709;
    _D_world_v_imu(1, 2) = ((v002406 * v007414 + -(v007523 * v008386 + v004993)) +
                            (v006192 * v007715 + v002406 * v007425) * v007406 + v007380 * v008911) *
                           v008709;
  }
  if (static_cast<bool>(_D_p_world)) {
    const Scalar v007376 = v002406 * v007532 + v000203 * v006143;
    const Scalar v007360 = v007423 * v007677 + v000203 * v006122;
    const Scalar v007344 = v007423 * v008014 + v000203 * v006101;
    _D_p_world(0, 0) =
        v000226 * (v000223 * (v007424 * v008014 + v006093 * v007403) + v007417 * v008014 +
                   v004690 * v007430 + v000217 * (v007344 * v007420 + v002401 * v002415));
    _D_p_world(0, 1) =
        v000226 * (v000223 * (v007424 * v007677 + v006114 * v007403) + v007417 * v007677 +
                   v004725 * v007430 + v000217 * (v002415 * v007524 + v007360 * v007420));
    _D_p_world(0, 2) =
        v000226 * (v000223 * (v002406 * v007484 + v006135 * v007403) + v002406 * v007537 +
                   v004760 * v007430 + v000217 * (v002415 * v007458 + v007376 * v007420));
    _D_p_world(1, 0) =
        v000236 * ((v007425 * v008014 + v006156 * v007403) * v007406 + v007414 * v008014 + v004949 +
                   v000217 * (v007344 * v007426 + v002415 * v007446));
    _D_p_world(1, 1) =
        v000236 * ((v007425 * v007677 + v006174 * v007403) * v007406 + v007414 * v007677 + v004971 +
                   v000217 * (v007360 * v007426 + v002324 * v002415));
    _D_p_world(1, 2) =
        v000236 * ((v002406 * v007504 + v006192 * v007403) * v007406 + v002406 * v007540 + v004993 +
                   v000217 * (v007376 * v007426 + v002415 * v007523));
  }
  _p_image(0, 0) = v000226 * ((v000192 * v007437 + v008366) * v007428 +
                              v000192 * (v000181 * v007430 + v008386)) +
                   camera.cx;
  _p_image(1, 0) = v000236 * ((v000181 * v007435 + v008374) * v007430 +
                              v000181 * (v000192 * v007428 + v008386)) +
                   camera.cy;
}

}  // namespace gen
