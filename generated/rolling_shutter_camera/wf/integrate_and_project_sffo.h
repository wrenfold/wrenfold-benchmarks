// Machine generated code.
#pragma once
#include <cmath>
#include <cstdint>

#include <wrenfold/span.h>

namespace gen {

template <typename Scalar, typename T0, typename T1, typename T2, typename T3, typename T4,
          typename T5, typename T6, typename T9, typename T10, typename T11, typename T12,
          typename T13, typename T14, typename T15, typename T16>
void integrate_and_project_sffo(const T0& world_R_imu_xyzw, const T1& world_t_imu,
                                const T2& imu_R_cam_xyzw, const T3& imu_t_cam,
                                const T4& angular_velocity_imu, const T5& world_v_imu,
                                const T6& p_world, const Scalar row_time,
                                const camera_params_t& camera, T9&& p_image, T10&& D_world_R_imu,
                                T11&& D_world_t_imu, T12&& D_imu_R_cam, T13&& D_imu_t_cam,
                                T14&& D_angular_velocity_imu, T15&& D_world_v_imu,
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
  // add: 1134
  // branch: 7
  // call: 3
  // divide: 6
  // multiply: 1805
  // negate: 100
  // total: 3055

  const Scalar v000011 = _angular_velocity_imu(2, 0);
  const Scalar v000009 = _angular_velocity_imu(1, 0);
  const Scalar v000005 = _angular_velocity_imu(0, 0);
  const Scalar v000006 = row_time;
  const Scalar v002499 =
      static_cast<Scalar>(9.999999999999999e-33) +
      (v000005 * v000005 + v000009 * v000009 + v000011 * v000011) * (v000006 * v000006);
  const Scalar v000017 = static_cast<Scalar>(0.5);
  const Scalar v000014 = std::sqrt(v002499);
  const Scalar v000019 = v000014 * v000017;
  const Scalar v000020 = std::sin(v000019);
  const Scalar v000016 = static_cast<Scalar>(1) / v000014;
  const Scalar v000023 = _world_R_imu_xyzw(1, 0);
  const Scalar v000004 = _world_R_imu_xyzw(0, 0);
  const Scalar v000027 = _world_R_imu_xyzw(3, 0);
  const Scalar v000025 = _world_R_imu_xyzw(2, 0);
  const Scalar v007684 = v000016 * v000020;
  const Scalar v008641 = v000009 * v000023;
  const Scalar v008633 = v000004 * v000005;
  const Scalar v009113 = v000005 * v000027;
  const Scalar v008819 = v000011 * v000023;
  const Scalar v012629 = -v000025;
  const Scalar v009164 = v000011 * v000027;
  const Scalar v008793 = v000004 * v000009;
  const Scalar v012628 = -v000023;
  const Scalar v009162 = v000009 * v000027;
  const Scalar v008796 = v000005 * v000025;
  const Scalar v012627 = -v000004;
  const Scalar v007702 = v000006 * v007684;
  const Scalar v012560 = v008633 + v008641;
  const Scalar v008644 = v000011 * v000025;
  const Scalar v012565 = v008819 + v009113;
  const Scalar v012563 = v008793 + v009164;
  const Scalar v012564 = v008796 + v009162;
  const Scalar v000028 = std::cos(v000019);
  const Scalar v012630 = -v007702;
  const Scalar v002503 = v008644 + v012560;
  const Scalar v002515 = v000009 * v012629 + v012565;
  const Scalar v002521 = v000005 * v012628 + v012563;
  const Scalar v002509 = v000011 * v012627 + v012564;
  const Scalar v010650 = v000027 * v000028;
  const Scalar v008794 = v000004 * v000028;
  const Scalar v008849 = v000025 * v000028;
  const Scalar v008848 = v000023 * v000028;
  const Scalar v002505 = v002503 * v012630 + v010650;
  const Scalar v000032 = _imu_R_cam_xyzw(2, 0);
  const Scalar v002517 = v002515 * v007702 + v008794;
  const Scalar v000046 = _imu_R_cam_xyzw(1, 0);
  const Scalar v002523 = v002521 * v007702 + v008849;
  const Scalar v000003 = _imu_R_cam_xyzw(0, 0);
  const Scalar v002511 = v002509 * v007702 + v008848;
  const Scalar v000039 = _imu_R_cam_xyzw(3, 0);
  const Scalar v002572 = v002511 * v002511;
  const Scalar v002554 = v002517 * v002517;
  const Scalar v002553 = v002523 * v002523;
  const Scalar v012624 = -static_cast<Scalar>(2);
  const Scalar v002609 = v002554 + v002572;
  const Scalar v012632 = -v002505;
  const Scalar v012577 = v000039 * v002523 + (v000046 * v002517 + v000032 * v002505);
  const Scalar v002555 = v002553 + v002554;
  const Scalar v012573 = v000039 * v002511 + (v000003 * v002523 + v000046 * v002505);
  const Scalar v002573 = v002553 + v002572;
  const Scalar v012581 = v000039 * v002517 + (v000003 * v002505 + v000032 * v002511);
  const Scalar v012569 = v000032 * v002523 + (v000003 * v002517 + v000046 * v002511);
  const Scalar v000081 = _imu_t_cam(1, 0);
  const Scalar v010986 = v002511 * v002523;
  const Scalar v010967 = v002505 * v002517;
  const Scalar v000066 = _imu_t_cam(0, 0);
  const Scalar v011010 = v002517 * v002523;
  const Scalar v009112 = v000003 * v002511;
  const Scalar v000086 = _imu_t_cam(2, 0);
  const Scalar v010985 = v002511 * v002517;
  const Scalar v010968 = v002505 * v002523;
  const Scalar v008852 = v000032 * v002517;
  const Scalar v010966 = v002505 * v002511;
  const Scalar v008853 = v000046 * v002523;
  const Scalar v009207 = v000039 * v002505;
  const Scalar v000151 = _world_v_imu(2, 0);
  const Scalar v008174 = static_cast<Scalar>(2) * v000081;
  const Scalar v006760 = v010967 + v010986;
  const Scalar v008173 = static_cast<Scalar>(2) * v000066;
  const Scalar v002535 = v009112 + -v012577;
  const Scalar v000096 = _world_v_imu(1, 0);
  const Scalar v008175 = static_cast<Scalar>(2) * v000086;
  const Scalar v006736 = v010968 + v010985;
  const Scalar v002594 = v008852 + -v012573;
  const Scalar v000113 = _world_v_imu(0, 0);
  const Scalar v006752 = v010966 + v011010;
  const Scalar v002529 = v008853 + -v012581;
  const Scalar v002606 = v009207 + -v012569;
  const Scalar v000141 = _world_t_imu(2, 0);
  const Scalar v000064 = _world_t_imu(1, 0);
  const Scalar v001227 = v002594 * v002594;
  const Scalar v001019 = v002535 * v002535;
  const Scalar v000101 = _world_t_imu(0, 0);
  const Scalar v012674 = -v002529;
  const Scalar v002536 = v002529 * v002529;
  const Scalar v012664 = -v002594;
  const Scalar v011070 = v002594 * v002606;
  const Scalar v011048 = v002529 * v002535;
  const Scalar v011049 = v002529 * v002594;
  const Scalar v002627 = v001019 + v001227;
  const Scalar v011055 = v002535 * v002594;
  const Scalar v011056 = v002535 * v002606;
  const Scalar v002538 = v001019 + v002536;
  const Scalar v011050 = v002529 * v002606;
  const Scalar v002632 = v001227 + v002536;
  const Scalar v006802 = v011048 + v011070;
  const Scalar v000140 = _p_world(2, 0);
  const Scalar v006776 = v002606 * -v002535 + v011049;
  const Scalar v000063 = _p_world(1, 0);
  const Scalar v000100 = _p_world(0, 0);
  const Scalar v006798 = v002606 * v012674 + v011055;
  const Scalar v006772 = v011049 + v011056;
  const Scalar v006810 = v011050 + v011055;
  const Scalar v006806 = v002606 * v012664 + v011048;
  const Scalar v007719 = static_cast<Scalar>(2) * v006802;
  const Scalar v002618 =
      v000140 + -(v000141 + (v002511 * v012632 + v011010) * v008173 + v006760 * v008174 +
                  v000086 * (static_cast<Scalar>(1) + v002609 * v012624) + v000006 * v000151);
  const Scalar v007732 = static_cast<Scalar>(2) * v006776;
  const Scalar v002570 = v000063 + -(v000064 + v006736 * v008173 +
                                     v000081 * (static_cast<Scalar>(1) + v002555 * v012624) +
                                     (v002517 * v012632 + v010986) * v008175 + v000006 * v000096);
  const Scalar v002629 = static_cast<Scalar>(1) + v002627 * v012624;
  const Scalar v002582 =
      v000100 + -(v000101 + v000066 * (static_cast<Scalar>(1) + v002573 * v012624) +
                  (v002523 * v012632 + v010985) * v008174 + v006752 * v008175 + v000006 * v000113);
  const Scalar v007743 = static_cast<Scalar>(2) * v006798;
  const Scalar v007718 = static_cast<Scalar>(2) * v006772;
  const Scalar v002540 = static_cast<Scalar>(1) + v002538 * v012624;
  const Scalar v007694 = static_cast<Scalar>(2) * v006810;
  const Scalar v007722 = static_cast<Scalar>(2) * v006806;
  const Scalar v002634 = static_cast<Scalar>(1) + v002632 * v012624;
  const Scalar v000174 = v002582 * v002629 + v002570 * v007732 + v002618 * v007719;
  const Scalar v000163 = v002540 * v002570 + v002582 * v007718 + v002618 * v007743;
  const Scalar v000183 = v002618 * v002634 + v002582 * v007722 + v002570 * v007694;
  const Scalar v009346 = v000174 * v000174;
  const Scalar v009332 = v000163 * v000163;
  const Scalar v010793 = v000183 * v000183;
  const Scalar v002637 = v009332 + v009346;
  const Scalar v000185 = static_cast<Scalar>(1) / v010793;
  const Scalar v007697 = v000185 * v002637;
  const Scalar v009389 = camera.k3 * v007697;
  const Scalar v000194 = camera.k2;
  const Scalar v000192 = camera.k1;
  const Scalar v007745 = v000163 * static_cast<Scalar>(3);
  const Scalar v007751 = v000174 * static_cast<Scalar>(3);
  const Scalar v000337 = static_cast<Scalar>(1) / (v000183 * v010793);
  const Scalar v006935 = static_cast<Scalar>(2) * v000194 + static_cast<Scalar>(3) * v009389;
  const Scalar v000187 = camera.p1;
  const Scalar v000223 = static_cast<Scalar>(-0.5);
  const Scalar v007678 = static_cast<Scalar>(2) * static_cast<Scalar>(2);
  const Scalar v012685 = -v000337;
  const Scalar v007685 = static_cast<Scalar>(2) * v000185;
  const Scalar v007689 = v000337 * v012624;
  const Scalar v002643 =
      static_cast<Scalar>(1) + (v000192 + (v000194 + v009389) * v007697) * v007697;
  const Scalar v002655 = v000163 * v007745 + v009346;
  const Scalar v002646 = v000174 * v007751 + v009332;
  const Scalar v000205 = camera.p2;
  const Scalar v007680 = static_cast<Scalar>(2) * v000187;
  const Scalar v008634 = v000004 * v000011;
  const Scalar v008649 = v000025 * v000223;
  const Scalar v008635 = v000004 * v000223;
  const Scalar v008648 = v000023 * v000223;
  const Scalar v008349 = v000081 * v012624;
  const Scalar v008371 = v000086 * v012624;
  const Scalar v008326 = v000066 * v012624;
  const Scalar v008471 = v002582 * v007678;
  const Scalar v008727 = v002570 * v007678;
  const Scalar v007785 = static_cast<Scalar>(2) * v002618;
  const Scalar v007784 = static_cast<Scalar>(2) * v002582;
  const Scalar v008473 = v002618 * v007678;
  const Scalar v007783 = static_cast<Scalar>(2) * v002570;
  const Scalar v007963 = v002637 * v012685;
  const Scalar v008036 = v007685 * (v002637 * v006935);
  const Scalar v007802 = static_cast<Scalar>(2) * v000192;
  const Scalar v007932 = v000163 * v007689;
  const Scalar v012687 = -v002643;
  const Scalar v008034 = v002655 * v012685;
  const Scalar v007949 = v000174 * v007689;
  const Scalar v007975 = v002646 * v012685;
  const Scalar v007734 = v000174 * v000205;
  const Scalar v000199 = static_cast<Scalar>(1) / v000183;
  const Scalar v007744 = v000163 * v000185;
  const Scalar v007816 = v000187 * v007678;
  const Scalar v007750 = v000174 * v000185;
  const Scalar v007747 = v000163 * v007680;
  const Scalar v007782 = static_cast<Scalar>(2) * v000205;
  const Scalar v000218 = camera.fy;
  const Scalar v000208 = camera.fx;
  if (static_cast<bool>(_D_world_R_imu)) {
    const Scalar v008636 = v000005 * v000023;
    const Scalar v008642 = v000009 * v000025;
    const Scalar v012622 = v008642 + v008819;
    const Scalar v008820 = v000017 * v000027;
    const Scalar v012620 = v008636 + v008793;
    const Scalar v012561 = v008633 + v008644;
    const Scalar v012618 = v008634 + v008796;
    const Scalar v012562 = v008641 + v008644;
    const Scalar v003149 = v008634 + v012564;
    const Scalar v009425 = v000223 * v007702;
    const Scalar v008821 = v000017 * v000028;
    const Scalar v002910 = v008642 + v012565;
    const Scalar v002671 = v008636 + v012563;
    const Scalar v000457 = v000028 * v008649;
    const Scalar v000224 = v000028 * v008635;
    const Scalar v000261 = v000028 * v008820;
    const Scalar v000235 = v000028 * v008648;
    const Scalar v003151 = v003149 * v012630 + v008848;
    const Scalar v007763 = static_cast<Scalar>(2) * v002517;
    const Scalar v003133 = v000457 + (v000017 * v008793 + v000223 * (v008636 + v009164)) * v007702;
    const Scalar v003177 = v000224 + (v000005 * v008820 + v000223 * v012622) * v007702;
    const Scalar v003145 = v000261 + (v000223 * v008644 + v000017 * v012560) * v007702;
    const Scalar v003139 = v000028 * v012627 + (v009113 + -v012622) * v007702;
    const Scalar v007924 = static_cast<Scalar>(2) * v002511;
    const Scalar v003171 = v000023 * v008821 + v003149 * v009425;
    const Scalar v003216 = (v000011 * v012629 + v012560) * v007702 + v010650;
    const Scalar v008318 = static_cast<Scalar>(2) * v002523;
    const Scalar v002918 = v000028 * v012629 + (v009164 + -v012620) * v007702;
    const Scalar v002900 = v000235 + (v000017 * v008796 + v000223 * (v008634 + v009162)) * v007702;
    const Scalar v002944 = v000261 + (v000223 * v008641 + v000017 * v012561) * v007702;
    const Scalar v002912 = v000017 * v008794 + v002910 * v009425;
    const Scalar v002906 = (v000009 * v012628 + v012561) * v007702 + v010650;
    const Scalar v002938 = v000457 + (v000011 * v008820 + v000223 * v012620) * v007702;
    const Scalar v002983 = v002910 * v012630 + v008794;
    const Scalar v002685 = (v000005 * v012627 + v012562) * v007702 + v010650;
    const Scalar v002667 = v000224 + (v000017 * v008819 + v000223 * (v008642 + v009113)) * v007702;
    const Scalar v002711 = v000025 * v008821 + v002671 * v009425;
    const Scalar v002679 = v000235 + (v000009 * v008820 + v000223 * v012618) * v007702;
    const Scalar v002673 = v002671 * v012630 + v008849;
    const Scalar v002705 = v000261 + (v000223 * v008633 + v000017 * v012562) * v007702;
    const Scalar v002750 = v000028 * v012628 + (v009162 + -v012618) * v007702;
    const Scalar v000637 = v002505 * v003151;
    const Scalar v000698 = v002505 * v003139;
    const Scalar v000704 = v002505 * v003216;
    const Scalar v000447 = v002505 * v002918;
    const Scalar v000512 = v002505 * v002906;
    const Scalar v000518 = v002505 * v002983;
    const Scalar v000248 = v002505 * v002685;
    const Scalar v000317 = v002505 * v002673;
    const Scalar v000323 = v002505 * v002750;
    const Scalar v000638 = v002523 * v003139;
    const Scalar v003218 = v002523 * v003216;
    const Scalar v003157 = v002517 * v003151;
    const Scalar v000694 = v002511 * v003151;
    const Scalar v003158 = v002511 * v003139;
    const Scalar v000632 = v002523 * v003151;
    const Scalar v000448 = v002523 * v002906;
    const Scalar v002985 = v002523 * v002983;
    const Scalar v002924 = v002517 * v002918;
    const Scalar v000508 = v002511 * v002918;
    const Scalar v002925 = v002511 * v002906;
    const Scalar v000442 = v002523 * v002918;
    const Scalar v000249 = v002523 * v002673;
    const Scalar v002752 = v002523 * v002750;
    const Scalar v002691 = v002517 * v002685;
    const Scalar v000313 = v002511 * v002685;
    const Scalar v002692 = v002511 * v002673;
    const Scalar v000243 = v002523 * v002685;
    const Scalar v003195 =
        v000003 * v003177 + -(v000046 * v003171 + v000032 * v003133 + v000039 * v003145);
    const Scalar v003268 =
        v000032 * v003171 + -(v000003 * v003145 + v000046 * v003133 + v000039 * v003177);
    const Scalar v006068 =
        v000046 * v003145 + -(v000003 * v003133 + v000032 * v003177 + v000039 * v003171);
    const Scalar v003183 =
        v000039 * v003133 + -(v000003 * v003171 + v000046 * v003177 + v000032 * v003145);
    const Scalar v002962 =
        v000003 * v002944 + -(v000046 * v002938 + v000032 * v002900 + v000039 * v002912);
    const Scalar v003035 =
        v000032 * v002938 + -(v000003 * v002912 + v000046 * v002900 + v000039 * v002944);
    const Scalar v005999 =
        v000046 * v002912 + -(v000003 * v002900 + v000032 * v002944 + v000039 * v002938);
    const Scalar v002950 =
        v000039 * v002900 + -(v000003 * v002938 + v000046 * v002944 + v000032 * v002912);
    const Scalar v002729 =
        v000003 * v002711 + -(v000046 * v002705 + v000032 * v002667 + v000039 * v002679);
    const Scalar v002802 =
        v000032 * v002705 + -(v000003 * v002679 + v000046 * v002667 + v000039 * v002711);
    const Scalar v005925 =
        v000046 * v002679 + -(v000003 * v002667 + v000032 * v002711 + v000039 * v002705);
    const Scalar v002717 =
        v000039 * v002667 + -(v000003 * v002705 + v000046 * v002711 + v000032 * v002679);
    const Scalar v007077 = v002535 * v003195;
    const Scalar v007058 = v002594 * v003268;
    const Scalar v007057 = v002529 * v006068;
    const Scalar v006993 = v002535 * v002962;
    const Scalar v006974 = v002594 * v003035;
    const Scalar v006973 = v002529 * v005999;
    const Scalar v006909 = v002535 * v002729;
    const Scalar v006884 = v002594 * v002802;
    const Scalar v006885 = v002529 * v005925;
    const Scalar v003243 =
        v000066 *
            (v000694 + v000704 + static_cast<Scalar>(2) * (v002517 * v003177 + v002523 * v003133)) +
        (v003157 + v003218) * v008349 +
        v000086 * (v003145 * v007924 + v000638 + -(v003133 * v007763 + v000637));
    const Scalar v003164 =
        v000066 * (v003145 * v007763 + v000632 + -(v003133 * v007924 + v000698)) +
        v000081 *
            (v000637 + v000638 + static_cast<Scalar>(2) * (v002511 * v003145 + v002517 * v003133)) +
        (v003157 + v003158) * v008371;
    const Scalar v003229 =
        (v003158 + v003218) * v008326 +
        v000081 * (v003177 * v007763 + v000694 + -(v003133 * v008318 + v000704)) +
        v000086 *
            (v000632 + v000698 + static_cast<Scalar>(2) * (v002511 * v003133 + v002517 * v003145));
    const Scalar v012598 = v002529 * v003268 + v002594 * v006068;
    const Scalar v012599 = v002535 * v003183 + v002606 * v003195;
    const Scalar v012596 = v002594 * v003195 + v002535 * v003268;
    const Scalar v012595 = v002529 * v003183 + v002606 * v006068;
    const Scalar v003010 =
        v000066 *
            (v000508 + v000518 + static_cast<Scalar>(2) * (v002517 * v002944 + v002523 * v002900)) +
        (v002924 + v002985) * v008349 +
        v000086 * (v002912 * v007924 + v000448 + -(v002900 * v007763 + v000447));
    const Scalar v002931 =
        v000066 * (v002912 * v007763 + v000442 + -(v002900 * v007924 + v000512)) +
        v000081 *
            (v000447 + v000448 + static_cast<Scalar>(2) * (v002511 * v002912 + v002517 * v002900)) +
        (v002924 + v002925) * v008371;
    const Scalar v002996 =
        (v002925 + v002985) * v008326 +
        v000081 * (v002944 * v007763 + v000508 + -(v002900 * v008318 + v000518)) +
        v000086 *
            (v000442 + v000512 + static_cast<Scalar>(2) * (v002511 * v002900 + v002517 * v002912));
    const Scalar v012592 = v002529 * v003035 + v002594 * v005999;
    const Scalar v012593 = v002535 * v002950 + v002606 * v002962;
    const Scalar v012590 = v002594 * v002962 + v002535 * v003035;
    const Scalar v012589 = v002529 * v002950 + v002606 * v005999;
    const Scalar v002777 =
        v000066 *
            (v000313 + v000323 + static_cast<Scalar>(2) * (v002517 * v002711 + v002523 * v002667)) +
        (v002691 + v002752) * v008349 +
        v000086 * (v002679 * v007924 + v000249 + -(v002667 * v007763 + v000248));
    const Scalar v002698 =
        v000066 * (v002679 * v007763 + v000243 + -(v002667 * v007924 + v000317)) +
        v000081 *
            (v000248 + v000249 + static_cast<Scalar>(2) * (v002511 * v002679 + v002517 * v002667)) +
        (v002691 + v002692) * v008371;
    const Scalar v002763 =
        (v002692 + v002752) * v008326 +
        v000081 * (v002711 * v007763 + v000313 + -(v002667 * v008318 + v000323)) +
        v000086 *
            (v000243 + v000317 + static_cast<Scalar>(2) * (v002511 * v002667 + v002517 * v002679));
    const Scalar v012586 = v002529 * v002802 + v002594 * v005925;
    const Scalar v012587 = v002535 * v002717 + v002606 * v002729;
    const Scalar v012584 = v002594 * v002729 + v002535 * v002802;
    const Scalar v012583 = v002529 * v002717 + v002606 * v005925;
    const Scalar v012597 = v002529 * v003195 + v002535 * v006068;
    const Scalar v012594 = v002594 * v003183 + v002606 * v003268;
    const Scalar v012591 = v002529 * v002962 + v002535 * v005999;
    const Scalar v012588 = v002594 * v002950 + v002606 * v003035;
    const Scalar v012585 = v002529 * v002729 + v002535 * v005925;
    const Scalar v012582 = v002594 * v002717 + v002606 * v002802;
    const Scalar v006087 = v002570 * (v012599 * v012624 + static_cast<Scalar>(2) * v012598) +
                           (v012594 + v012597) * v007785 +
                           -(v002629 * v003229 + (v007058 + v007077) * v008471 + v003164 * v007719 +
                             v003243 * v007732);
    const Scalar v006094 = (v012598 + v012599) * v007784 +
                           v002618 * (v012595 * v012624 + static_cast<Scalar>(2) * v012596) +
                           -(v002540 * v003243 + (v007057 + v007077) * v008727 + v003229 * v007718 +
                             v003164 * v007743);
    const Scalar v006018 = v002570 * (v012593 * v012624 + static_cast<Scalar>(2) * v012592) +
                           (v012588 + v012591) * v007785 +
                           -(v002629 * v002996 + (v006974 + v006993) * v008471 + v002931 * v007719 +
                             v003010 * v007732);
    const Scalar v006025 = (v012592 + v012593) * v007784 +
                           v002618 * (v012589 * v012624 + static_cast<Scalar>(2) * v012590) +
                           -(v002540 * v003010 + (v006973 + v006993) * v008727 + v002996 * v007718 +
                             v002931 * v007743);
    const Scalar v005949 = v002570 * (v012587 * v012624 + static_cast<Scalar>(2) * v012586) +
                           (v012582 + v012585) * v007785 +
                           -(v002629 * v002763 + (v006884 + v006909) * v008471 + v002698 * v007719 +
                             v002777 * v007732);
    const Scalar v005956 = (v012586 + v012587) * v007784 +
                           v002618 * (v012583 * v012624 + static_cast<Scalar>(2) * v012584) +
                           -(v002540 * v002777 + (v006885 + v006909) * v008727 + v002763 * v007718 +
                             v002698 * v007743);
    const Scalar v010777 = v000174 * v006087;
    const Scalar v010752 = v000163 * v006094;
    const Scalar v010776 = v000174 * v006018;
    const Scalar v010751 = v000163 * v006025;
    const Scalar v010775 = v000174 * v005949;
    const Scalar v010750 = v000163 * v005956;
    const Scalar v006076 = v002582 * (v012594 * v012624 + static_cast<Scalar>(2) * v012597) +
                           (v012595 + v012596) * v007783 +
                           -(v002634 * v003164 + (v007057 + v007058) * v008473 + v003229 * v007722 +
                             v003243 * v007694);
    const Scalar v006007 = v002582 * (v012588 * v012624 + static_cast<Scalar>(2) * v012591) +
                           (v012589 + v012590) * v007783 +
                           -(v002634 * v002931 + (v006973 + v006974) * v008473 + v002996 * v007722 +
                             v003010 * v007694);
    const Scalar v005938 = v002582 * (v012582 * v012624 + static_cast<Scalar>(2) * v012585) +
                           (v012583 + v012584) * v007783 +
                           -(v002634 * v002698 + (v006884 + v006885) * v008473 + v002763 * v007722 +
                             v002777 * v007694);
    const Scalar v007099 = v006076 * v007963 + v000185 * (v010752 + v010777);
    const Scalar v007015 = v006007 * v007963 + v000185 * (v010751 + v010776);
    const Scalar v006931 = v005938 * v007963 + v000185 * (v010750 + v010775);
    const Scalar v003347 = v007099 * v007802 + v007099 * v008036;
    const Scalar v003114 = v007015 * v007802 + v007015 * v008036;
    const Scalar v002881 = v006931 * v007802 + v006931 * v008036;
    const Scalar v003353 = v006076 * v012687;
    const Scalar v003120 = v006007 * v012687;
    const Scalar v002887 = v005938 * v012687;
    _D_world_R_imu(0, 0) =
        v000208 * ((v005938 * v007975 + v000185 * (v005949 * v007751 + v010750)) * v007782 +
                   (v005938 * v007949 + v000185 * v005949) * v007747 +
                   (v005956 * v007680 + v002887) * v007750 +
                   v000199 * (v002643 * v005949 + v000174 * v002881));
    _D_world_R_imu(0, 1) =
        v000208 * ((v006007 * v007975 + v000185 * (v006018 * v007751 + v010751)) * v007782 +
                   (v006007 * v007949 + v000185 * v006018) * v007747 +
                   (v006025 * v007680 + v003120) * v007750 +
                   v000199 * (v002643 * v006018 + v000174 * v003114));
    _D_world_R_imu(0, 2) =
        v000208 * ((v006076 * v007975 + v000185 * (v006087 * v007751 + v010752)) * v007782 +
                   (v006076 * v007949 + v000185 * v006087) * v007747 +
                   (v006094 * v007680 + v003353) * v007750 +
                   v000199 * (v002643 * v006087 + v000174 * v003347));
    _D_world_R_imu(1, 0) =
        v000218 * ((v005938 * v008034 + v000185 * (v005956 * v007745 + v010775)) * v007816 +
                   (v002887 + v000205 * v005949) * v007744 +
                   v000199 * (v002643 * v005956 + v000163 * v002881) +
                   (v005938 * v007932 + v000185 * v005956) * v007734);
    _D_world_R_imu(1, 1) =
        v000218 * ((v006007 * v008034 + v000185 * (v006025 * v007745 + v010776)) * v007816 +
                   (v003120 + v000205 * v006018) * v007744 +
                   v000199 * (v002643 * v006025 + v000163 * v003114) +
                   (v006007 * v007932 + v000185 * v006025) * v007734);
    _D_world_R_imu(1, 2) =
        v000218 * ((v006076 * v008034 + v000185 * (v006094 * v007745 + v010777)) * v007816 +
                   (v003353 + v000205 * v006087) * v007744 +
                   v000199 * (v002643 * v006094 + v000163 * v003347) +
                   (v006076 * v007932 + v000185 * v006094) * v007734);
  }
  const Scalar v007681 = static_cast<Scalar>(2) * v000163;
  const Scalar v008430 = v000185 * v012624;
  const Scalar v007812 = v000174 * v012624;
  const Scalar v012631 = -static_cast<Scalar>(4);
  const Scalar v008235 = v000174 * v007678;
  const Scalar v007729 = v000337 * v002637;
  const Scalar v008587 = v006810 * v007678;
  const Scalar v008554 = v006806 * v007678;
  const Scalar v008620 = v006935 * v007697;
  const Scalar v010904 = static_cast<Scalar>(3) * v007681;
  const Scalar v008273 = v006802 * v012624;
  const Scalar v007723 = v000163 * v000337;
  const Scalar v007791 = static_cast<Scalar>(2) * v002643;
  const Scalar v007768 = v000337 * v002655;
  const Scalar v007724 = v000174 * v000337;
  const Scalar v007767 = v000337 * v002646;
  const Scalar v003664 = v006772 * v008430;
  const Scalar v003634 = v006802 * v008430;
  if (static_cast<bool>(_D_world_t_imu)) {
    const Scalar v006814 = v002535 * v012664 + v011050;
    const Scalar v003520 = static_cast<Scalar>(-2) + static_cast<Scalar>(4) * v002538;
    const Scalar v006780 = v002529 * v012664 + v011056;
    const Scalar v008494 = v006772 * v012624;
    const Scalar v003444 = static_cast<Scalar>(-2) + static_cast<Scalar>(4) * v002627;
    const Scalar v012388 = v006814 * v007681;
    const Scalar v006144 = v006802 * v007812;
    const Scalar v010748 = v000163 * v003520;
    const Scalar v003531 = v006780 * v008235;
    const Scalar v012545 = v007681 * v008494;
    const Scalar v010773 = v000174 * v003444;
    const Scalar v003579 = static_cast<Scalar>(2) + v002632 * v012631;
    const Scalar v003627 = v003579 * v007729 + (v006144 + v012388) * v007685;
    const Scalar v003556 = v000185 * (v003531 + v010748) + v007729 * v008587;
    const Scalar v003484 = v000185 * (v010773 + v012545) + v007729 * v008554;
    const Scalar v003632 = v000192 * v003627 + v003627 * v008620;
    const Scalar v003507 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002538;
    const Scalar v003561 = v000192 * v003556 + v003556 * v008620;
    const Scalar v003489 = v000192 * v003484 + v003484 * v008620;
    const Scalar v003431 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002627;
    const Scalar v003638 = v002634 * v002643;
    const Scalar v003563 = v002643 * v007694;
    const Scalar v003495 = v002643 * v007722;
    _D_world_t_imu(0, 0) =
        v000208 * (v000205 * (v000185 * (v003444 * v007751 + v012545) + v007767 * v008554) +
                   (v000185 * v003431 + v007724 * v008554) * v007747 +
                   (v007680 * v008494 + v003495) * v007750 +
                   v000199 * (v002643 * v003431 + v000174 * v003489));
    _D_world_t_imu(0, 1) =
        v000208 *
        (v000205 * (v000185 * (v007751 * (v006780 * v007678) + v010748) + v007767 * v008587) +
         (v003507 * v007680 + v003563) * v007750 +
         (v006780 * v007685 + v007724 * v008587) * v007747 +
         v000199 * (v006780 * v007791 + v000174 * v003561));
    _D_world_t_imu(0, 2) =
        v000208 *
        (v000205 * (v003579 * v007767 + (v007751 * v008273 + v012388) * v007685) +
         (v003579 * v007724 + v003634) * v007747 + (v006814 * v007816 + v003638) * v007750 +
         v000199 * (v000174 * v003632 + v002643 * v008273));
    _D_world_t_imu(1, 0) =
        v000218 * ((v000185 * (v008494 * v010904 + v010773) + v007768 * v008554) * v007680 +
                   (v003495 + v000205 * v003431) * v007744 +
                   v000199 * (v002643 * v008494 + v000163 * v003489) +
                   (v007723 * v008554 + v003664) * v007734);
    _D_world_t_imu(1, 1) =
        v000218 * ((v000185 * (v003531 + v003520 * v007745) + v007768 * v008587) * v007680 +
                   v000199 * (v002643 * v003507 + v000163 * v003561) +
                   (v000185 * v003507 + v007723 * v008587) * v007734 +
                   (v003563 + v006780 * v007782) * v007744);
    _D_world_t_imu(1, 2) =
        v000218 * ((v003579 * v007768 + (v006144 + v006814 * v010904) * v007685) * v007680 +
                   (v003638 + v000205 * v008273) * v007744 +
                   v000199 * (v006814 * v007791 + v000163 * v003632) +
                   (v003579 * v007723 + v006814 * v007685) * v007734);
  }
  const Scalar v012640 = -v002511;
  const Scalar v012650 = -v002517;
  if (static_cast<bool>(_D_imu_R_cam)) {
    const Scalar v003744 = v000017 * v009112 + v000223 * v012577;
    const Scalar v008854 = static_cast<Scalar>(2) * v002535;
    const Scalar v001012 = v000039 * v012632 + v012569;
    const Scalar v008319 = static_cast<Scalar>(2) * v002529;
    const Scalar v003963 = v000223 * v008853 + v000017 * v012581;
    const Scalar v003836 = v000017 * v008852 + v000223 * v012573;
    const Scalar v003717 = v000017 * v008853 + v000223 * v012581;
    const Scalar v001113 = v000003 * v012640 + v012577;
    const Scalar v003860 = v000223 * v009207 + v000017 * v012569;
    const Scalar v003723 = v000223 * v008852 + v000017 * v012573;
    const Scalar v001032 = v000032 * v012650 + v012573;
    const Scalar v001018 = v001012 * v002606;
    const Scalar v001043 = v003744 * v008319;
    const Scalar v011051 = v002529 * v003717;
    const Scalar v001146 = v003836 * v008854;
    const Scalar v001118 = v001113 * v002606;
    const Scalar v009707 = v002594 * v003717;
    const Scalar v006844 = v002529 * v003723;
    const Scalar v001054 = v001032 * v002606;
    const Scalar v001016 = v003717 * v008319;
    const Scalar v001201 = v000046 * -v002523 + v012581;
    const Scalar v008320 = static_cast<Scalar>(2) * v002594;
    const Scalar v006788 = v002606 + static_cast<Scalar>(2) * v003860;
    const Scalar v001231 = v001201 * v002606;
    const Scalar v001137 = v003860 * v008319;
    const Scalar v001013 = v001012 * v002535;
    const Scalar v001208 = v001201 * v002535;
    const Scalar v001114 = v001113 * v002535;
    const Scalar v001138 = v001113 * v002594;
    const Scalar v001044 = v001012 * v002594;
    const Scalar v003728 = v001012 * v002529;
    const Scalar v009602 = v002582 * v012624;
    const Scalar v009497 = v002570 * v012624;
    const Scalar v001234 =
        (v001013 + v001201 * v002594) * v009602 +
        v002570 * (v003963 * v008319 + v001227 + -(v001018 + v003744 * v008854)) +
        v002618 * (v001137 + v001231 + v002594 * (v002535 + static_cast<Scalar>(2) * v003744));
    const Scalar v001245 =
        v002582 *
            (v001018 + v001227 + static_cast<Scalar>(2) * (v002529 * v003963 + v002535 * v003744)) +
        (v001013 + v011049) * v009497 +
        v002618 * (v003860 * v008320 + v001208 + -(v001043 + v011070));
    const Scalar v009709 = v002618 * v012624;
    const Scalar v001144 =
        (v001044 + v011048) * v009602 + v002570 * (v001137 + v001138 + -(v001146 + v011050)) +
        v002618 * (v001018 + v001114 + static_cast<Scalar>(2) * (v011051 + v002594 * v003836));
    const Scalar v001156 = v002582 * (v001138 + v001146 + v002529 * v006788) +
                           v002529 * (v001113 + v002535) * v009497 +
                           v002618 * (v001013 + v003717 * v008320 + -(v003836 * v008319 + v001118));
    const Scalar v001051 =
        v002535 * (v001032 + v002594) * v009602 +
        v002570 * (v001043 + v001044 + -(v003717 * v008854 + v001054)) +
        v002618 * (v002535 * (v001012 + v002606) + static_cast<Scalar>(2) * (v006844 + v009707));
    const Scalar v001063 =
        v002582 *
            (v001044 + v001054 + static_cast<Scalar>(2) * (v002529 * v003744 + v002535 * v003717)) +
        (v003728 + v001032 * v002535) * v009497 +
        v002618 * (v003723 * v008320 + v001019 + -(v001016 + v001018));
    const Scalar v010767 = v000174 * v001234;
    const Scalar v010742 = v000163 * v001245;
    const Scalar v010766 = v000174 * v001144;
    const Scalar v010741 = v000163 * v001156;
    const Scalar v010765 = v000174 * v001051;
    const Scalar v010740 = v000163 * v001063;
    const Scalar v003952 = v002582 * (v001137 + v011055 + -(v003744 * v008320 + v001231)) +
                           v002570 * (v001043 + v001208 + v002594 * v006788) +
                           v002594 * (v001201 + v002529) * v009709;
    const Scalar v003849 =
        v002582 * (v001016 + v001114 + -(v001018 + v003836 * v008320)) +
        v002570 * (v001013 + v001118 + static_cast<Scalar>(2) * (v009707 + v002529 * v003836)) +
        (v001044 + v001113 * v002529) * v009709;
    const Scalar v003735 =
        v002582 * (v002535 * (v001012 + -v002606) +
                   static_cast<Scalar>(2) * (v003717 * v012664 + v006844)) +
        v002570 * (v001018 + v001019 + static_cast<Scalar>(2) * (v011051 + v002594 * v003723)) +
        (v003728 + v011055) * v009709;
    const Scalar v007159 = v003952 * v007963 + v000185 * (v010742 + v010767);
    const Scalar v007147 = v003849 * v007963 + v000185 * (v010741 + v010766);
    const Scalar v007135 = v003735 * v007963 + v000185 * (v010740 + v010765);
    const Scalar v004033 = v007159 * v007802 + v007159 * v008036;
    const Scalar v003928 = v007147 * v007802 + v007147 * v008036;
    const Scalar v003817 = v007135 * v007802 + v007135 * v008036;
    const Scalar v004039 = v003952 * v012687;
    const Scalar v003934 = v003849 * v012687;
    const Scalar v003823 = v003735 * v012687;
    _D_imu_R_cam(0, 0) =
        v000208 * ((v003735 * v007975 + v000185 * (v001051 * v007751 + v010740)) * v007782 +
                   (v003735 * v007949 + v000185 * v001051) * v007747 +
                   (v001063 * v007680 + v003823) * v007750 +
                   v000199 * (v001051 * v002643 + v000174 * v003817));
    _D_imu_R_cam(0, 1) =
        v000208 * ((v003849 * v007975 + v000185 * (v001144 * v007751 + v010741)) * v007782 +
                   (v003849 * v007949 + v000185 * v001144) * v007747 +
                   (v001156 * v007680 + v003934) * v007750 +
                   v000199 * (v001144 * v002643 + v000174 * v003928));
    _D_imu_R_cam(0, 2) =
        v000208 * ((v003952 * v007975 + v000185 * (v001234 * v007751 + v010742)) * v007782 +
                   (v003952 * v007949 + v000185 * v001234) * v007747 +
                   (v001245 * v007680 + v004039) * v007750 +
                   v000199 * (v001234 * v002643 + v000174 * v004033));
    _D_imu_R_cam(1, 0) =
        v000218 * ((v003735 * v008034 + v000185 * (v001063 * v007745 + v010765)) * v007816 +
                   (v003823 + v000205 * v001051) * v007744 +
                   v000199 * (v001063 * v002643 + v000163 * v003817) +
                   (v003735 * v007932 + v000185 * v001063) * v007734);
    _D_imu_R_cam(1, 1) =
        v000218 * ((v003849 * v008034 + v000185 * (v001156 * v007745 + v010766)) * v007816 +
                   (v003934 + v000205 * v001144) * v007744 +
                   v000199 * (v001156 * v002643 + v000163 * v003928) +
                   (v003849 * v007932 + v000185 * v001156) * v007734);
    _D_imu_R_cam(1, 2) =
        v000218 * ((v003952 * v008034 + v000185 * (v001245 * v007745 + v010767)) * v007816 +
                   (v004039 + v000205 * v001234) * v007744 +
                   v000199 * (v001245 * v002643 + v000163 * v004033) +
                   (v003952 * v007932 + v000185 * v001245) * v007734);
  }
  const Scalar v010229 = v006776 * v007678;
  const Scalar v009033 = v006772 * v007678;
  if (static_cast<bool>(_D_imu_t_cam)) {
    const Scalar v006744 = v002517 * v012640 + v010968;
    const Scalar v006764 = v002523 * v012650 + v010966;
    const Scalar v006768 = v002523 * v012640 + v010967;
    const Scalar v010105 = v006752 * v012624;
    const Scalar v004283 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002609;
    const Scalar v010149 = v006760 * v012624;
    const Scalar v004200 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002555;
    const Scalar v010057 = v006736 * v012624;
    const Scalar v004117 = static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002573;
    const Scalar v001450 = v004283 * v007719 + v002629 * v010105 + v006768 * v010229;
    const Scalar v001445 =
        v004283 * v007743 + v006768 * (static_cast<Scalar>(2) * v002540) + v007718 * v010105;
    const Scalar v001394 =
        v004200 * v007732 + v002629 * (static_cast<Scalar>(2) * v006744) + v007719 * v010149;
    const Scalar v001389 = v002540 * v004200 + v007743 * v010149 + v006744 * v009033;
    const Scalar v001331 = v002629 * v004117 + v007732 * v010057 + v006802 * (v006764 * v007678);
    const Scalar v001336 = v004117 * v007718 + v002540 * v010057 + v006764 * (v006798 * v007678);
    const Scalar v010770 = v000174 * v001450;
    const Scalar v010745 = v000163 * v001445;
    const Scalar v010769 = v000174 * v001394;
    const Scalar v010744 = v000163 * v001389;
    const Scalar v010768 = v000174 * v001331;
    const Scalar v010743 = v000163 * v001336;
    const Scalar v004291 = v002634 * v004283 + v007722 * v010105 + v006768 * v008587;
    const Scalar v004208 = v004200 * v007694 + v002634 * v010149 + v006744 * v008554;
    const Scalar v004125 =
        v004117 * v007722 + v002634 * (static_cast<Scalar>(2) * v006764) + v007694 * v010057;
    const Scalar v007207 = v004291 * v007963 + v000185 * (v010745 + v010770);
    const Scalar v007195 = v004208 * v007963 + v000185 * (v010744 + v010769);
    const Scalar v007183 = v004125 * v007963 + v000185 * (v010743 + v010768);
    const Scalar v004348 = v007207 * v007802 + v007207 * v008036;
    const Scalar v004265 = v007195 * v007802 + v007195 * v008036;
    const Scalar v004182 = v007183 * v007802 + v007183 * v008036;
    const Scalar v004354 = v004291 * v012687;
    const Scalar v004271 = v004208 * v012687;
    const Scalar v004188 = v004125 * v012687;
    _D_imu_t_cam(0, 0) =
        v000208 * ((v004125 * v007975 + v000185 * (v001331 * v007751 + v010743)) * v007782 +
                   (v004125 * v007949 + v000185 * v001331) * v007747 +
                   (v001336 * v007680 + v004188) * v007750 +
                   v000199 * (v001331 * v002643 + v000174 * v004182));
    _D_imu_t_cam(0, 1) =
        v000208 * ((v004208 * v007975 + v000185 * (v001394 * v007751 + v010744)) * v007782 +
                   (v004208 * v007949 + v000185 * v001394) * v007747 +
                   (v001389 * v007680 + v004271) * v007750 +
                   v000199 * (v001394 * v002643 + v000174 * v004265));
    _D_imu_t_cam(0, 2) =
        v000208 * ((v004291 * v007975 + v000185 * (v001450 * v007751 + v010745)) * v007782 +
                   (v004291 * v007949 + v000185 * v001450) * v007747 +
                   (v001445 * v007680 + v004354) * v007750 +
                   v000199 * (v001450 * v002643 + v000174 * v004348));
    _D_imu_t_cam(1, 0) =
        v000218 * ((v004125 * v008034 + v000185 * (v001336 * v007745 + v010768)) * v007816 +
                   (v004188 + v000205 * v001331) * v007744 +
                   v000199 * (v001336 * v002643 + v000163 * v004182) +
                   (v004125 * v007932 + v000185 * v001336) * v007734);
    _D_imu_t_cam(1, 1) =
        v000218 * ((v004208 * v008034 + v000185 * (v001389 * v007745 + v010769)) * v007816 +
                   (v004271 + v000205 * v001394) * v007744 +
                   v000199 * (v001389 * v002643 + v000163 * v004265) +
                   (v004208 * v007932 + v000185 * v001389) * v007734);
    _D_imu_t_cam(1, 2) =
        v000218 * ((v004291 * v008034 + v000185 * (v001445 * v007745 + v010770)) * v007816 +
                   (v004354 + v000205 * v001450) * v007744 +
                   v000199 * (v001445 * v002643 + v000163 * v004348) +
                   (v004291 * v007932 + v000185 * v001445) * v007734);
  }
  const Scalar v007686 = v000006 * static_cast<Scalar>(2);
  if (static_cast<bool>(_D_angular_velocity_imu)) {
    const Scalar v007777 = v000006 * v000009;
    const Scalar v012625 = -v000006;
    const Scalar v007795 = v000006 * v000011;
    const Scalar v007726 = v000005 * v000006;
    const Scalar v001530 = static_cast<Scalar>(1) / (v000014 * v000014 * v000014);
    const Scalar v009130 = v000006 * v000017;
    const Scalar v007762 = v000028 * (static_cast<Scalar>(1) / v002499);
    const Scalar v004568 = v000023 * static_cast<Scalar>(2);
    const Scalar v008198 = v001530 * v007686;
    const Scalar v007257 = v012565 * v012625 + v000025 * v007777;
    const Scalar v005114 = v007795 * v008635;
    const Scalar v007240 = v012564 * v012625 + v000004 * v007795;
    const Scalar v004512 = v007726 * v008648;
    const Scalar v007274 = v012563 * v012625 + v000023 * v007726;
    const Scalar v004868 = v000004 * static_cast<Scalar>(2);
    const Scalar v004454 = v000025 * static_cast<Scalar>(2);
    const Scalar v004777 = v007777 * v008649;
    const Scalar v004464 = v000027 * static_cast<Scalar>(2);
    const Scalar v010347 = v007257 * v008198;
    const Scalar v007888 = v000006 * v007762;
    const Scalar v007296 = v005114 + v009130 * v012564;
    const Scalar v008721 = v001530 * v007240;
    const Scalar v007687 = v000006 * v000020;
    const Scalar v007278 = v004512 + v009130 * v012563;
    const Scalar v008450 = v001530 * v007274;
    const Scalar v012626 = -v000016;
    const Scalar v010342 = v007240 * v008198;
    const Scalar v010350 = v007274 * v008198;
    const Scalar v008449 = v001530 * v007257;
    const Scalar v009129 = v000005 * v008198;
    const Scalar v007304 = v004777 + v009130 * v012565;
    const Scalar v011937 = (v000223 * v007762 + v000020 * v001530) * (v000006 * v002503);
    const Scalar v009471 = v002515 * v007888;
    const Scalar v006435 = v007687 * v008721 + v007296 * v007888;
    const Scalar v009464 = v002509 * v007888;
    const Scalar v010427 = v007762 * v007777;
    const Scalar v009482 = v002521 * v007888;
    const Scalar v008626 = v007726 * v007762;
    const Scalar v008134 = v002517 * v007686;
    const Scalar v007507 = (v000027 * (v000223 * v007795) + v012629) * v007684 + v007795 * v011937;
    const Scalar v008070 = v000006 * v002505;
    const Scalar v007515 =
        v007795 * v009471 + v000020 * (v000011 * v010347 + v000016 * (v004568 + v008634 * v012625));
    const Scalar v007797 = v000006 * v002523;
    const Scalar v007727 = v000006 * v002517;
    const Scalar v007533 = (v007795 * v008648 + v012627) * v007684 + v000011 * v006435;
    const Scalar v007759 = v000006 * v002511;
    const Scalar v007519 =
        (v000027 + v007795 * v008649) * v007684 + v000011 * (v007687 * v008450 + v007278 * v007888);
    const Scalar v007511 =
        v007795 * v009464 + v000020 * (v000011 * v010342 + (v004868 + v000023 * v007795) * v012626);
    const Scalar v008453 = v002511 * v007686;
    const Scalar v007920 = v000006 * v000039;
    const Scalar v007919 = v000006 * v000032;
    const Scalar v007921 = v000006 * v000046;
    const Scalar v007537 =
        v007795 * (v007304 * v007762) +
        v000020 * ((v000006 * v001530) * (v000011 * v007257) + v000016 * (v000023 + v005114));
    const Scalar v007918 = v000003 * v000006;
    const Scalar v009484 = v002523 * v007686;
    const Scalar v007575 = (v004464 + v008644 * v012625) * v007684 +
                           v000011 * (v000020 * v010350 + v007888 * (v000006 * v002521));
    const Scalar v007395 = (v000027 * (v000223 * v007777) + v012628) * v007684 + v007777 * v011937;
    const Scalar v007403 =
        v007777 * v009471 + v000020 * (v000009 * v010347 + (v004454 + v000004 * v007777) * v012626);
    const Scalar v007421 = (v000027 + v007777 * v008648) * v007684 + v000009 * v006435;
    const Scalar v007407 =
        v007278 * v010427 + v000020 * (v007777 * v008450 + v000016 * (v000004 + v004777));
    const Scalar v007399 = (v004464 + v007777 * v012628) * v007684 +
                           v000009 * (v000020 * v010342 + v007888 * (v000006 * v002509));
    const Scalar v007425 =
        v007304 * v010427 + v000020 * (v007777 * v008449 + v000016 * (v007777 * v008635 + v012629));
    const Scalar v007463 =
        v007777 * v009482 + v000020 * (v000009 * v010350 + v000016 * (v007777 * v012629 + v004868));
    const Scalar v007232 = (v000027 * (v000223 * v007726) + v012627) * v007684 + v007726 * v011937;
    const Scalar v007266 =
        v007726 * v009471 + v000020 * (v007257 * v009129 + v000016 * (v007726 * v012627 + v004464));
    const Scalar v007300 =
        v007296 * v008626 + v000020 * (v007726 * v008721 + v000016 * (v000025 + v004512));
    const Scalar v007282 =
        v007278 * v008626 + v000020 * (v007726 * v008450 + v000016 * (v007726 * v008649 + v012628));
    const Scalar v007249 =
        v007726 * v009464 + v000020 * (v007240 * v009129 + v000016 * (v007726 * v012628 + v004454));
    const Scalar v007308 =
        v007304 * v008626 + v000020 * (v007726 * v008449 + v000016 * (v000027 + v007726 * v008635));
    const Scalar v007351 =
        v007726 * v009482 + v000020 * (v007274 * v009129 + (v004568 + v000025 * v007726) * v012626);
    const Scalar v002025 = v007515 * v008070;
    const Scalar v002100 = v007511 * v008070;
    const Scalar v002105 = v007575 * v008070;
    const Scalar v001799 = v007403 * v008070;
    const Scalar v001880 = v007399 * v008070;
    const Scalar v001885 = v007463 * v008070;
    const Scalar v001569 = v007266 * v008070;
    const Scalar v001653 = v007249 * v008070;
    const Scalar v001658 = v007351 * v008070;
    const Scalar v002024 = v007511 * v007797;
    const Scalar v005167 = v007575 * v007797;
    const Scalar v005081 = v007515 * v007727;
    const Scalar v002095 = v007515 * v007759;
    const Scalar v005080 = v007511 * v007759;
    const Scalar v002011 = v007515 * v007797;
    const Scalar v001800 = v007399 * v007797;
    const Scalar v004873 = v007463 * v007797;
    const Scalar v004786 = v007403 * v007727;
    const Scalar v001875 = v007403 * v007759;
    const Scalar v004787 = v007399 * v007759;
    const Scalar v001787 = v007403 * v007797;
    const Scalar v001571 = v007249 * v007797;
    const Scalar v004579 = v007351 * v007797;
    const Scalar v004493 = v007266 * v007727;
    const Scalar v001648 = v007266 * v007759;
    const Scalar v004494 = v007249 * v007759;
    const Scalar v001555 = v007266 * v007797;
    const Scalar v005135 =
        v007533 * v007918 + -(v007537 * v007921 + v007507 * v007919 + v007519 * v007920);
    const Scalar v005217 =
        v007537 * v007919 + -(v007519 * v007918 + v007507 * v007921 + v007533 * v007920);
    const Scalar v006533 =
        v007519 * v007921 + -(v007507 * v007918 + v007533 * v007919 + v007537 * v007920);
    const Scalar v005129 =
        v007507 * v007920 + -(v007537 * v007918 + v007533 * v007921 + v007519 * v007919);
    const Scalar v004841 =
        v007421 * v007918 + -(v007425 * v007921 + v007395 * v007919 + v007407 * v007920);
    const Scalar v004923 =
        v007425 * v007919 + -(v007407 * v007918 + v007395 * v007921 + v007421 * v007920);
    const Scalar v006449 =
        v007407 * v007921 + -(v007395 * v007918 + v007421 * v007919 + v007425 * v007920);
    const Scalar v004835 =
        v007395 * v007920 + -(v007425 * v007918 + v007421 * v007921 + v007407 * v007919);
    const Scalar v004547 =
        v007300 * v007918 + -(v007308 * v007921 + v007232 * v007919 + v007282 * v007920);
    const Scalar v004629 =
        v007308 * v007919 + -(v007282 * v007918 + v007232 * v007921 + v007300 * v007920);
    const Scalar v006360 =
        v007282 * v007921 + -(v007232 * v007918 + v007300 * v007919 + v007308 * v007920);
    const Scalar v004541 =
        v007232 * v007920 + -(v007308 * v007918 + v007300 * v007921 + v007282 * v007919);
    const Scalar v007589 = v002535 * v005135;
    const Scalar v007560 = v002594 * v005217;
    const Scalar v007561 = v002529 * v006533;
    const Scalar v007477 = v002535 * v004841;
    const Scalar v007448 = v002594 * v004923;
    const Scalar v007449 = v002529 * v006449;
    const Scalar v007365 = v002535 * v004547;
    const Scalar v007331 = v002594 * v004629;
    const Scalar v007332 = v002529 * v006360;
    const Scalar v005192 =
        v000066 *
            (v002095 + v002105 + static_cast<Scalar>(2) * (v007533 * v007727 + v007507 * v007797)) +
        (v005081 + v005167) * v008349 +
        v000086 * (v007519 * v008453 + v002024 + -(v002025 + v007507 * v008134));
    const Scalar v005087 =
        v000066 * (v002011 + v007519 * v008134 + -(v007507 * v008453 + v002100)) +
        v000081 *
            (v002024 + v002025 + static_cast<Scalar>(2) * (v007519 * v007759 + v007507 * v007727)) +
        (v005080 + v005081) * v008371;
    const Scalar v005178 =
        (v005080 + v005167) * v008326 +
        v000081 * (v002095 + v007533 * v008134 + -(v002105 + v007507 * v009484)) +
        v000086 *
            (v002011 + v002100 + static_cast<Scalar>(2) * (v007519 * v007727 + v007507 * v007759));
    const Scalar v012616 = v002529 * v005217 + v002594 * v006533;
    const Scalar v012617 = v002606 * v005135 + v002535 * v005129;
    const Scalar v012614 = v002535 * v005217 + v002594 * v005135;
    const Scalar v012613 = v002529 * v005129 + v002606 * v006533;
    const Scalar v004898 =
        v000066 *
            (v001875 + v001885 + static_cast<Scalar>(2) * (v007421 * v007727 + v007395 * v007797)) +
        (v004786 + v004873) * v008349 +
        v000086 * (v007407 * v008453 + v001800 + -(v001799 + v007395 * v008134));
    const Scalar v004793 =
        v000066 * (v001787 + v007407 * v008134 + -(v007395 * v008453 + v001880)) +
        v000081 *
            (v001799 + v001800 + static_cast<Scalar>(2) * (v007407 * v007759 + v007395 * v007727)) +
        (v004786 + v004787) * v008371;
    const Scalar v004884 =
        (v004787 + v004873) * v008326 +
        v000081 * (v001875 + v007421 * v008134 + -(v001885 + v007395 * v009484)) +
        v000086 *
            (v001787 + v001880 + static_cast<Scalar>(2) * (v007407 * v007727 + v007395 * v007759));
    const Scalar v012610 = v002529 * v004923 + v002594 * v006449;
    const Scalar v012611 = v002606 * v004841 + v002535 * v004835;
    const Scalar v012608 = v002535 * v004923 + v002594 * v004841;
    const Scalar v012607 = v002529 * v004835 + v002606 * v006449;
    const Scalar v004604 =
        v000066 *
            (v001648 + v001658 + static_cast<Scalar>(2) * (v007300 * v007727 + v007232 * v007797)) +
        (v004493 + v004579) * v008349 +
        v000086 * (v007282 * v008453 + v001571 + -(v001569 + v007232 * v008134));
    const Scalar v004500 =
        v000066 * (v001555 + v007282 * v008134 + -(v007232 * v008453 + v001653)) +
        v000081 *
            (v001569 + v001571 + static_cast<Scalar>(2) * (v007282 * v007759 + v007232 * v007727)) +
        (v004493 + v004494) * v008371;
    const Scalar v004590 =
        (v004494 + v004579) * v008326 +
        v000081 * (v001648 + v007300 * v008134 + -(v001658 + v007232 * v009484)) +
        v000086 *
            (v001555 + v001653 + static_cast<Scalar>(2) * (v007282 * v007727 + v007232 * v007759));
    const Scalar v012604 = v002529 * v004629 + v002594 * v006360;
    const Scalar v012605 = v002606 * v004547 + v002535 * v004541;
    const Scalar v012601 = v002535 * v004629 + v002594 * v004547;
    const Scalar v012602 = v002529 * v004541 + v002606 * v006360;
    const Scalar v012615 = v002529 * v005135 + v002535 * v006533;
    const Scalar v012612 = v002606 * v005217 + v002594 * v005129;
    const Scalar v012609 = v002529 * v004841 + v002535 * v006449;
    const Scalar v012606 = v002606 * v004923 + v002594 * v004835;
    const Scalar v012603 = v002529 * v004547 + v002535 * v006360;
    const Scalar v012600 = v002606 * v004629 + v002594 * v004541;
    const Scalar v006557 = v002570 * (v012617 * v012624 + static_cast<Scalar>(2) * v012616) +
                           (v012612 + v012615) * v007785 +
                           -(v002629 * v005178 + (v007560 + v007589) * v008471 + v005087 * v007719 +
                             v005192 * v007732);
    const Scalar v006564 = (v012616 + v012617) * v007784 +
                           v002618 * (v012613 * v012624 + static_cast<Scalar>(2) * v012614) +
                           -(v002540 * v005192 + (v007561 + v007589) * v008727 + v005178 * v007718 +
                             v005087 * v007743);
    const Scalar v006473 = v002570 * (v012611 * v012624 + static_cast<Scalar>(2) * v012610) +
                           (v012606 + v012609) * v007785 +
                           -(v002629 * v004884 + (v007448 + v007477) * v008471 + v004793 * v007719 +
                             v004898 * v007732);
    const Scalar v006480 = (v012610 + v012611) * v007784 +
                           v002618 * (v012607 * v012624 + static_cast<Scalar>(2) * v012608) +
                           -(v002540 * v004898 + (v007449 + v007477) * v008727 + v004884 * v007718 +
                             v004793 * v007743);
    const Scalar v006389 = v002570 * (v012605 * v012624 + static_cast<Scalar>(2) * v012604) +
                           (v012600 + v012603) * v007785 +
                           -(v002629 * v004590 + (v007331 + v007365) * v008471 + v004500 * v007719 +
                             v004604 * v007732);
    const Scalar v006396 = (v012604 + v012605) * v007784 +
                           v002618 * (v012602 * v012624 + static_cast<Scalar>(2) * v012601) +
                           -(v002540 * v004604 + (v007332 + v007365) * v008727 + v004590 * v007718 +
                             v004500 * v007743);
    const Scalar v010780 = v000174 * v006557;
    const Scalar v010755 = v000163 * v006564;
    const Scalar v010779 = v000174 * v006473;
    const Scalar v010754 = v000163 * v006480;
    const Scalar v010778 = v000174 * v006389;
    const Scalar v010753 = v000163 * v006396;
    const Scalar v006546 = v002582 * (v012612 * v012624 + static_cast<Scalar>(2) * v012615) +
                           (v012613 + v012614) * v007783 +
                           -(v002634 * v005087 + (v007560 + v007561) * v008473 + v005178 * v007722 +
                             v005192 * v007694);
    const Scalar v006462 = v002582 * (v012606 * v012624 + static_cast<Scalar>(2) * v012609) +
                           (v012607 + v012608) * v007783 +
                           -(v002634 * v004793 + (v007448 + v007449) * v008473 + v004884 * v007722 +
                             v004898 * v007694);
    const Scalar v006378 = v002582 * (v012600 * v012624 + static_cast<Scalar>(2) * v012603) +
                           (v012601 + v012602) * v007783 +
                           -(v002634 * v004500 + (v007331 + v007332) * v008473 + v004590 * v007722 +
                             v004604 * v007694);
    const Scalar v007611 = v006546 * v007963 + v000185 * (v010755 + v010780);
    const Scalar v007499 = v006462 * v007963 + v000185 * (v010754 + v010779);
    const Scalar v007387 = v006378 * v007963 + v000185 * (v010753 + v010778);
    const Scalar v005296 = v007611 * v007802 + v007611 * v008036;
    const Scalar v005002 = v007499 * v007802 + v007499 * v008036;
    const Scalar v004708 = v007387 * v007802 + v007387 * v008036;
    const Scalar v005302 = v006546 * v012687;
    const Scalar v005008 = v006462 * v012687;
    const Scalar v004714 = v006378 * v012687;
    _D_angular_velocity_imu(0, 0) =
        v000208 * ((v006378 * v007975 + v000185 * (v006389 * v007751 + v010753)) * v007782 +
                   (v006378 * v007949 + v000185 * v006389) * v007747 +
                   (v006396 * v007680 + v004714) * v007750 +
                   v000199 * (v002643 * v006389 + v000174 * v004708));
    _D_angular_velocity_imu(0, 1) =
        v000208 * ((v006462 * v007975 + v000185 * (v006473 * v007751 + v010754)) * v007782 +
                   (v006462 * v007949 + v000185 * v006473) * v007747 +
                   (v006480 * v007680 + v005008) * v007750 +
                   v000199 * (v002643 * v006473 + v000174 * v005002));
    _D_angular_velocity_imu(0, 2) =
        v000208 * ((v006546 * v007975 + v000185 * (v006557 * v007751 + v010755)) * v007782 +
                   (v006546 * v007949 + v000185 * v006557) * v007747 +
                   (v006564 * v007680 + v005302) * v007750 +
                   v000199 * (v002643 * v006557 + v000174 * v005296));
    _D_angular_velocity_imu(1, 0) =
        v000218 * ((v006378 * v008034 + v000185 * (v006396 * v007745 + v010778)) * v007816 +
                   (v004714 + v000205 * v006389) * v007744 +
                   v000199 * (v002643 * v006396 + v000163 * v004708) +
                   (v006378 * v007932 + v000185 * v006396) * v007734);
    _D_angular_velocity_imu(1, 1) =
        v000218 * ((v006462 * v008034 + v000185 * (v006480 * v007745 + v010779)) * v007816 +
                   (v005008 + v000205 * v006473) * v007744 +
                   v000199 * (v002643 * v006480 + v000163 * v005002) +
                   (v006462 * v007932 + v000185 * v006480) * v007734);
    _D_angular_velocity_imu(1, 2) =
        v000218 * ((v006546 * v008034 + v000185 * (v006564 * v007745 + v010780)) * v007816 +
                   (v005302 + v000205 * v006557) * v007744 +
                   v000199 * (v002643 * v006564 + v000163 * v005296) +
                   (v006546 * v007932 + v000185 * v006564) * v007734);
  }
  const Scalar v007683 = static_cast<Scalar>(2) * v000174;
  const Scalar v007682 = static_cast<Scalar>(2) * v000337;
  const Scalar v012366 = v006798 * v007681;
  const Scalar v010277 = v006802 * v007683;
  const Scalar v008397 = v000163 * v007678;
  const Scalar v008617 = v006810 * v007682;
  const Scalar v005495 = v010277 + v012366;
  const Scalar v011094 = v002637 * v007682;
  const Scalar v008700 = v000185 * v000205;
  const Scalar v008970 = v000199 * v002643;
  const Scalar v005377 = v006772 * v008397;
  const Scalar v010294 = v006810 * v007681;
  if (static_cast<bool>(_D_world_v_imu)) {
    const Scalar v012686 = -v000185;
    const Scalar v008933 = v000174 * static_cast<Scalar>(6);
    const Scalar v005527 = v006798 * v007683 + v006802 * v007681;
    const Scalar v005426 = v000185 * v002643;
    const Scalar v005473 = v000174 * v002540 + v006776 * v007681;
    const Scalar v005419 = v000163 * v002629 + v006772 * v007683;
    const Scalar v009334 = v000163 * static_cast<Scalar>(6);
    const Scalar v005554 = v005426 + v007682 * v007734;
    const Scalar v005382 = v000163 * v007681 + v000174 * v008933;
    const Scalar v005427 = v000187 * static_cast<Scalar>(4) * v007723 + v005426;
    const Scalar v012549 =
        v007697 * (v000006 * (static_cast<Scalar>(6) * v009389 + v000194 * static_cast<Scalar>(4)));
    const Scalar v006641 = v005495 * v012686 + v002634 * v007729;
    const Scalar v009379 = v000192 * v007686;
    const Scalar v006620 = (v000163 * v002540 + v006776 * v007683) * v012686 + v002637 * v008617;
    const Scalar v006599 = (v006772 * v007681 + v000174 * v002629) * v012686 + v006806 * v011094;
    const Scalar v009377 = v000187 * v008430;
    const Scalar v011652 = v005427 * v007683;
    const Scalar v005524 = v006641 * v009379 + v006641 * v012549;
    const Scalar v005470 = v006620 * v009379 + v006620 * v012549;
    const Scalar v005416 = v006599 * v009379 + v006599 * v012549;
    const Scalar v009333 = v000163 * v000199;
    _D_world_v_imu(0, 0) =
        v000208 * (v000199 * (v000006 * v002629 * v012687 + v000174 * v005416) +
                   v000006 * ((v005419 * v009377 + v006806 * v011652) +
                              v000205 * ((v002629 * v008933 + v005377) * v012686 +
                                         v005382 * (v006806 * v007682))));
    _D_world_v_imu(0, 1) =
        v000208 *
        (v000199 * (v000006 * v006776 * (v002643 * v012624) + v000174 * v005470) +
         v000006 * ((v005473 * v009377 + v006810 * v011652) +
                    v000205 * ((v006776 * (static_cast<Scalar>(6) * v007683) + v002540 * v007681) *
                                   v012686 +
                               v005382 * v008617)));
    _D_world_v_imu(0, 2) =
        v000208 *
        (v000199 * (v008273 * (v000006 * v002643) + v000174 * v005524) +
         v000006 * ((v005527 * v009377 + v002634 * (v000174 * v005427)) +
                    v000205 * ((static_cast<Scalar>(6) * v010277 + v006798 * v008397) * v012686 +
                               v005382 * (v000337 * v002634))));
    _D_world_v_imu(1, 0) =
        v000218 *
        (v005416 * v009333 +
         v000006 * ((v006806 * (v005554 * v007681) + -(v007718 * v008970 + v005419 * v008700)) +
                    ((v003664 + v007681 * (v000337 * v006806)) * v009334 +
                     (v002629 * v012686 + v006806 * (v000174 * v007682)) * v007683) *
                        v007680));
    _D_world_v_imu(1, 1) =
        v000218 * (v005470 * v009333 +
                   v000006 * ((v005554 * v010294 + -(v002540 * v008970 + v005473 * v008700)) +
                              ((v002540 * v012686 + v007681 * (v000337 * v006810)) * v009334 +
                               (v006776 * v008430 + v000174 * v008617) * v007683) *
                                  v007680));
    _D_world_v_imu(1, 2) =
        v000218 *
        (v005524 * v009333 +
         v000006 * ((v002634 * (v000163 * v005554) + -(v007743 * v008970 + v005527 * v008700)) +
                    ((v006798 * v008430 + v002634 * v007723) * v009334 +
                     (v003634 + v002634 * v007724) * v007683) *
                        v007680));
  }
  if (static_cast<bool>(_D_p_world)) {
    const Scalar v005678 = static_cast<Scalar>(2) + v002538 * v012631;
    const Scalar v005603 = static_cast<Scalar>(2) + v002627 * v012631;
    const Scalar v010749 = v000163 * v005678;
    const Scalar v005689 = v006776 * v008235;
    const Scalar v010774 = v000174 * v005603;
    const Scalar v006841 = v002535 * v012674 + v011070;
    const Scalar v005737 = static_cast<Scalar>(-2) + static_cast<Scalar>(4) * v002632;
    const Scalar v008277 = v006810 * v012624;
    const Scalar v008771 = v006841 * v007678;
    const Scalar v005786 = v005737 * v007729 + v005495 * v007685;
    const Scalar v005714 = v000185 * (v005689 + v010749) + v008277 * v011094;
    const Scalar v005643 = v007729 * v008771 + v000185 * (v005377 + v010774);
    const Scalar v005791 = v000192 * v005786 + v005786 * v008620;
    const Scalar v005719 = v000192 * v005714 + v005714 * v008620;
    const Scalar v010417 = v007682 * v008277;
    const Scalar v005648 = v000192 * v005643 + v005643 * v008620;
    const Scalar v005797 = v002643 * (static_cast<Scalar>(-1) + static_cast<Scalar>(2) * v002632);
    const Scalar v005721 = v002643 * v008277;
    const Scalar v005654 = v006841 * v007791;
    _D_p_world(0, 0) =
        v000208 * (v000205 * (v000185 * (v005377 + v005603 * v007751) + v007767 * v008771) +
                   (v007724 * v008771 + v000185 * v002629) * v007747 +
                   (v006772 * v007816 + v005654) * v007750 +
                   v000199 * (v000174 * v005648 + v002629 * v002643));
    _D_p_world(0, 1) =
        v000208 * (v000205 * (v002646 * v010417 + v000185 * (v007751 * v010229 + v010749)) +
                   (v002540 * v007680 + v005721) * v007750 +
                   (v007812 * v008617 + v006776 * v007685) * v007747 +
                   v000199 * (v002643 * v007732 + v000174 * v005719));
    _D_p_world(0, 2) =
        v000208 *
        (v000205 * (v005737 * v007767 + (static_cast<Scalar>(3) * v010277 + v012366) * v007685) +
         (v005737 * v007724 + v006802 * v007685) * v007747 +
         (v006798 * v007816 + v005797) * v007750 +
         v000199 * (v002643 * v007719 + v000174 * v005791));
    _D_p_world(1, 0) =
        v000218 * ((v007768 * v008771 + v000185 * (v007745 * v009033 + v010774)) * v007680 +
                   (v005654 + v000205 * v002629) * v007744 +
                   v000199 * (v000163 * v005648 + v002643 * v007718) +
                   (v007723 * v008771 + v006772 * v007685) * v007734);
    _D_p_world(1, 1) =
        v000218 * ((v000185 * (v005689 + v005678 * v007745) + v002655 * v010417) * v007680 +
                   v000199 * (v000163 * v005719 + v002540 * v002643) +
                   (v007689 * v010294 + v000185 * v002540) * v007734 +
                   (v005721 + v000205 * v007732) * v007744);
    _D_p_world(1, 2) =
        v000218 * ((v005737 * v007768 + (v006798 * v010904 + v010277) * v007685) * v007680 +
                   (v005737 * v007723 + v006798 * v007685) * v007734 +
                   (v005797 + v000205 * v007719) * v007744 +
                   v000199 * (v000163 * v005791 + v002643 * v007743));
  }
  _p_image(0, 0) =
      v000208 * (v002646 * v008700 + v000174 * (v007680 * v007744 + v008970)) + camera.cx;
  _p_image(1, 0) =
      v000218 * (v002655 * (v000185 * v007680) + v000163 * (v000185 * v007734 + v008970)) +
      camera.cy;
}

}  // namespace gen
