// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

namespace sym {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     q0_xyzw: Matrix41
 *     q1_xyzw: Matrix41
 *     alpha: Scalar
 *
 * Outputs:
 *     q_out: Matrix41
 *     D0: Matrix33
 *     D1: Matrix33
 */
template <typename Scalar>
void QuatInterpolateFirstOrder(const Eigen::Matrix<Scalar, 4, 1>& q0_xyzw,
                               const Eigen::Matrix<Scalar, 4, 1>& q1_xyzw, const Scalar alpha,
                               Eigen::Matrix<Scalar, 4, 1>* const q_out = nullptr,
                               Eigen::Matrix<Scalar, 3, 3>* const D0 = nullptr,
                               Eigen::Matrix<Scalar, 3, 3>* const D1 = nullptr) {
  // Total ops: 1324

  // Input arrays

  // Intermediate terms (310)
  const Scalar _tmp0 = q0_xyzw(0, 0) * q1_xyzw(1, 0);
  const Scalar _tmp1 = q0_xyzw(1, 0) * q1_xyzw(0, 0);
  const Scalar _tmp2 = q0_xyzw(2, 0) * q1_xyzw(3, 0);
  const Scalar _tmp3 = q0_xyzw(3, 0) * q1_xyzw(2, 0);
  const Scalar _tmp4 = -_tmp0 + _tmp1 - _tmp2 + _tmp3;
  const Scalar _tmp5 = q0_xyzw(1, 0) * q1_xyzw(1, 0);
  const Scalar _tmp6 = q0_xyzw(0, 0) * q1_xyzw(0, 0);
  const Scalar _tmp7 = q0_xyzw(2, 0) * q1_xyzw(2, 0);
  const Scalar _tmp8 = -_tmp5 - _tmp6 - _tmp7;
  const Scalar _tmp9 = q0_xyzw(3, 0) * q1_xyzw(3, 0);
  const Scalar _tmp10 =
      2 * std::min<Scalar>(0, (((-_tmp8 + _tmp9) > 0) - ((-_tmp8 + _tmp9) < 0))) + 1;
  const Scalar _tmp11 = _tmp10 * alpha;
  const Scalar _tmp12 = _tmp11 * _tmp4;
  const Scalar _tmp13 = std::min<Scalar>(Scalar(1.0), std::fabs(_tmp8 - _tmp9));
  const Scalar _tmp14 = std::acos(_tmp13);
  const Scalar _tmp15 = q0_xyzw(2, 0) * q1_xyzw(1, 0);
  const Scalar _tmp16 = q0_xyzw(3, 0) * q1_xyzw(0, 0);
  const Scalar _tmp17 = q0_xyzw(0, 0) * q1_xyzw(3, 0);
  const Scalar _tmp18 = q0_xyzw(1, 0) * q1_xyzw(2, 0);
  const Scalar _tmp19 = _tmp15 + _tmp16 - _tmp17 - _tmp18;
  const Scalar _tmp20 = std::pow(_tmp19, Scalar(2));
  const Scalar _tmp21 = std::pow(alpha, Scalar(2));
  const Scalar _tmp22 = std::pow(_tmp10, Scalar(2));
  const Scalar _tmp23 = 4 * _tmp21 * _tmp22;
  const Scalar _tmp24 = 1 - std::pow(_tmp13, Scalar(2));
  const Scalar _tmp25 = std::pow(_tmp14, Scalar(2)) / _tmp24;
  const Scalar _tmp26 = _tmp23 * _tmp25;
  const Scalar _tmp27 = q0_xyzw(3, 0) * q1_xyzw(1, 0);
  const Scalar _tmp28 = q0_xyzw(2, 0) * q1_xyzw(0, 0);
  const Scalar _tmp29 = q0_xyzw(1, 0) * q1_xyzw(3, 0);
  const Scalar _tmp30 = q0_xyzw(0, 0) * q1_xyzw(2, 0);
  const Scalar _tmp31 = _tmp27 - _tmp28 - _tmp29 + _tmp30;
  const Scalar _tmp32 = std::pow(_tmp31, Scalar(2));
  const Scalar _tmp33 = _tmp23 * std::pow(_tmp4, Scalar(2));
  const Scalar _tmp34 = std::sqrt(
      Scalar(_tmp20 * _tmp26 + _tmp25 * _tmp33 + _tmp26 * _tmp32 + Scalar(1.0000000000000001e-32)));
  const Scalar _tmp35 = (Scalar(1) / Scalar(2)) * _tmp34;
  const Scalar _tmp36 = 2 * _tmp14 * std::sin(_tmp35) / (std::sqrt(_tmp24) * _tmp34);
  const Scalar _tmp37 = _tmp12 * _tmp36;
  const Scalar _tmp38 = _tmp11 * _tmp31;
  const Scalar _tmp39 = _tmp38 * q0_xyzw(2, 0);
  const Scalar _tmp40 = std::cos(_tmp35);
  const Scalar _tmp41 = _tmp11 * _tmp19;
  const Scalar _tmp42 = _tmp41 * q0_xyzw(3, 0);
  const Scalar _tmp43 = _tmp38 * q0_xyzw(3, 0);
  const Scalar _tmp44 = _tmp41 * q0_xyzw(2, 0);
  const Scalar _tmp45 = _tmp36 * _tmp38;
  const Scalar _tmp46 = _tmp41 * q0_xyzw(1, 0);
  const Scalar _tmp47 = _tmp12 * q0_xyzw(2, 0);
  const Scalar _tmp48 = _tmp41 * q0_xyzw(0, 0);
  const Scalar _tmp49 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp50 = (Scalar(1) / Scalar(2)) * _tmp16;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp18;
  const Scalar _tmp53 = _tmp49 + _tmp50 - _tmp51 - _tmp52;
  const Scalar _tmp54 = _tmp5 + _tmp6 + _tmp7 + _tmp9;
  const Scalar _tmp55 = std::fabs(_tmp54);
  const Scalar _tmp56 = std::min<Scalar>(Scalar(1.0), _tmp55);
  const Scalar _tmp57 = std::acos(_tmp56);
  const Scalar _tmp58 = 1 - std::pow(_tmp56, Scalar(2));
  const Scalar _tmp59 = _tmp57 / (_tmp58 * std::sqrt(_tmp58));
  const Scalar _tmp60 = _tmp53 * _tmp59;
  const Scalar _tmp61 = Scalar(1.0) / (_tmp58);
  const Scalar _tmp62 = std::pow(_tmp57, Scalar(2));
  const Scalar _tmp63 = _tmp61 * _tmp62;
  const Scalar _tmp64 = _tmp23 * _tmp63;
  const Scalar _tmp65 =
      _tmp20 * _tmp64 + _tmp32 * _tmp64 + _tmp33 * _tmp63 + Scalar(1.0000000000000001e-32);
  const Scalar _tmp66 = std::sqrt(_tmp65);
  const Scalar _tmp67 = (Scalar(1) / Scalar(2)) * _tmp66;
  const Scalar _tmp68 = std::sin(_tmp67);
  const Scalar _tmp69 = _tmp68 / _tmp66;
  const Scalar _tmp70 = ((((Scalar(1.0) - _tmp55) > 0) - ((Scalar(1.0) - _tmp55) < 0)) + 1) *
                        (((_tmp54) > 0) - ((_tmp54) < 0));
  const Scalar _tmp71 = _tmp69 * _tmp70;
  const Scalar _tmp72 = _tmp56 * _tmp71;
  const Scalar _tmp73 = _tmp44 * _tmp72;
  const Scalar _tmp74 = _tmp61 * _tmp71;
  const Scalar _tmp75 = _tmp53 * _tmp74;
  const Scalar _tmp76 = _tmp23 * _tmp70;
  const Scalar _tmp77 = _tmp20 * _tmp76;
  const Scalar _tmp78 = _tmp56 * _tmp62 / std::pow(_tmp58, Scalar(2));
  const Scalar _tmp79 = _tmp77 * _tmp78;
  const Scalar _tmp80 = _tmp33 * _tmp70;
  const Scalar _tmp81 = _tmp78 * _tmp80;
  const Scalar _tmp82 = (Scalar(1) / Scalar(2)) * _tmp5;
  const Scalar _tmp83 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp84 = (Scalar(1) / Scalar(2)) * _tmp9;
  const Scalar _tmp85 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp86 = -_tmp82 - _tmp83 - _tmp84 - _tmp85;
  const Scalar _tmp87 = 8 * _tmp21 * _tmp22 * _tmp63;
  const Scalar _tmp88 = _tmp19 * _tmp87;
  const Scalar _tmp89 = _tmp59 * _tmp77;
  const Scalar _tmp90 = _tmp32 * _tmp76;
  const Scalar _tmp91 = _tmp78 * _tmp90;
  const Scalar _tmp92 = (Scalar(1) / Scalar(2)) * _tmp27;
  const Scalar _tmp93 = (Scalar(1) / Scalar(2)) * _tmp28;
  const Scalar _tmp94 = (Scalar(1) / Scalar(2)) * _tmp29;
  const Scalar _tmp95 = (Scalar(1) / Scalar(2)) * _tmp30;
  const Scalar _tmp96 = -_tmp92 + _tmp93 + _tmp94 - _tmp95;
  const Scalar _tmp97 = _tmp4 * _tmp96;
  const Scalar _tmp98 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp99 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp100 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp101 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp102 = -_tmp100 + _tmp101 - _tmp98 + _tmp99;
  const Scalar _tmp103 = _tmp31 * _tmp87;
  const Scalar _tmp104 = _tmp102 * _tmp103 + _tmp87 * _tmp97;
  const Scalar _tmp105 = _tmp104 + _tmp53 * _tmp79 + _tmp53 * _tmp81 - _tmp53 * _tmp89 +
                         _tmp53 * _tmp91 - _tmp60 * _tmp80 - _tmp60 * _tmp90 + _tmp86 * _tmp88;
  const Scalar _tmp106 = _tmp57 / std::sqrt(_tmp58);
  const Scalar _tmp107 = _tmp68 / (_tmp65 * std::sqrt(_tmp65));
  const Scalar _tmp108 = _tmp106 * _tmp107;
  const Scalar _tmp109 = _tmp105 * _tmp108;
  const Scalar _tmp110 = _tmp106 * _tmp69;
  const Scalar _tmp111 = _tmp11 * _tmp110;
  const Scalar _tmp112 = 2 * _tmp111;
  const Scalar _tmp113 = _tmp112 * q0_xyzw(2, 0);
  const Scalar _tmp114 = _tmp113 * _tmp86;
  const Scalar _tmp115 = std::cos(_tmp67);
  const Scalar _tmp116 = _tmp115 * q0_xyzw(3, 0);
  const Scalar _tmp117 = (Scalar(1) / Scalar(2)) * _tmp116;
  const Scalar _tmp118 = _tmp117 * _tmp38;
  const Scalar _tmp119 = Scalar(1.0) / (_tmp65);
  const Scalar _tmp120 = _tmp106 * _tmp119;
  const Scalar _tmp121 = _tmp105 * _tmp120;
  const Scalar _tmp122 = _tmp60 * _tmp72;
  const Scalar _tmp123 = _tmp12 * _tmp122;
  const Scalar _tmp124 = _tmp105 * q0_xyzw(0, 0);
  const Scalar _tmp125 = _tmp108 * _tmp124;
  const Scalar _tmp126 = _tmp115 * q0_xyzw(0, 0);
  const Scalar _tmp127 = (Scalar(1) / Scalar(2)) * _tmp126;
  const Scalar _tmp128 = _tmp12 * _tmp120;
  const Scalar _tmp129 = _tmp105 * _tmp128;
  const Scalar _tmp130 = _tmp111 * _tmp4;
  const Scalar _tmp131 = _tmp130 * q0_xyzw(3, 0);
  const Scalar _tmp132 = -_tmp131;
  const Scalar _tmp133 = _tmp115 * q0_xyzw(2, 0);
  const Scalar _tmp134 = (Scalar(1) / Scalar(2)) * _tmp133;
  const Scalar _tmp135 = (Scalar(1) / Scalar(4)) * _tmp69;
  const Scalar _tmp136 = _tmp105 * _tmp135;
  const Scalar _tmp137 = _tmp12 * _tmp74;
  const Scalar _tmp138 = _tmp137 * _tmp53;
  const Scalar _tmp139 = _tmp120 * _tmp41;
  const Scalar _tmp140 = _tmp105 * _tmp139;
  const Scalar _tmp141 = _tmp112 * q0_xyzw(0, 0);
  const Scalar _tmp142 = _tmp112 * q0_xyzw(3, 0);
  const Scalar _tmp143 = _tmp102 * _tmp142 - _tmp141 * _tmp96;
  const Scalar _tmp144 = _tmp111 * _tmp31;
  const Scalar _tmp145 = _tmp144 * q0_xyzw(0, 0);
  const Scalar _tmp146 = _tmp110 * _tmp41;
  const Scalar _tmp147 = _tmp146 * q0_xyzw(1, 0);
  const Scalar _tmp148 = -_tmp147;
  const Scalar _tmp149 = -_tmp145 + _tmp148;
  const Scalar _tmp150 = -_tmp109 * _tmp43 - _tmp109 * _tmp44 + _tmp114 + _tmp118 * _tmp121 +
                         _tmp12 * _tmp125 + _tmp122 * _tmp43 - _tmp123 * q0_xyzw(0, 0) -
                         _tmp127 * _tmp129 + _tmp132 + _tmp134 * _tmp140 + _tmp134 -
                         _tmp136 * q0_xyzw(1, 0) + _tmp138 * q0_xyzw(0, 0) + _tmp143 + _tmp149 -
                         _tmp43 * _tmp75 - _tmp44 * _tmp75 + _tmp60 * _tmp73;
  const Scalar _tmp151 = 4 * _tmp131 + 2 * _tmp133 + 4 * _tmp145 - 4 * _tmp147;
  const Scalar _tmp152 = _tmp38 * q0_xyzw(1, 0);
  const Scalar _tmp153 = _tmp115 * q0_xyzw(1, 0);
  const Scalar _tmp154 = (Scalar(1) / Scalar(2)) * _tmp153;
  const Scalar _tmp155 = _tmp121 * _tmp38;
  const Scalar _tmp156 = _tmp130 * q0_xyzw(1, 0);
  const Scalar _tmp157 = _tmp112 * q0_xyzw(1, 0);
  const Scalar _tmp158 = -_tmp102 * _tmp157 - _tmp113 * _tmp96;
  const Scalar _tmp159 = _tmp144 * q0_xyzw(2, 0);
  const Scalar _tmp160 = -_tmp159;
  const Scalar _tmp161 = _tmp146 * q0_xyzw(3, 0);
  const Scalar _tmp162 = _tmp160 - _tmp161;
  const Scalar _tmp163 = _tmp141 * _tmp86;
  const Scalar _tmp164 = -_tmp127 - _tmp163;
  const Scalar _tmp165 = _tmp109 * _tmp152 + _tmp109 * _tmp47 - _tmp122 * _tmp152 -
                         _tmp122 * _tmp47 - _tmp122 * _tmp48 + _tmp125 * _tmp41 -
                         _tmp127 * _tmp140 - _tmp129 * _tmp134 - _tmp136 * q0_xyzw(3, 0) +
                         _tmp152 * _tmp75 - _tmp154 * _tmp155 + _tmp156 + _tmp158 + _tmp162 +
                         _tmp164 + _tmp47 * _tmp75 + _tmp48 * _tmp75;
  const Scalar _tmp166 = 2 * _tmp126 + 4 * _tmp156 - 4 * _tmp159 + 4 * _tmp161;
  const Scalar _tmp167 = _tmp38 * q0_xyzw(0, 0);
  const Scalar _tmp168 = _tmp144 * q0_xyzw(3, 0);
  const Scalar _tmp169 = _tmp127 * _tmp38;
  const Scalar _tmp170 = _tmp12 * q0_xyzw(3, 0);
  const Scalar _tmp171 = _tmp109 * _tmp12;
  const Scalar _tmp172 = _tmp102 * _tmp141 + _tmp142 * _tmp96;
  const Scalar _tmp173 = _tmp130 * q0_xyzw(0, 0);
  const Scalar _tmp174 = -_tmp173;
  const Scalar _tmp175 = _tmp146 * q0_xyzw(2, 0);
  const Scalar _tmp176 = _tmp174 - _tmp175;
  const Scalar _tmp177 = _tmp157 * _tmp86;
  const Scalar _tmp178 = -_tmp154 - _tmp177;
  const Scalar _tmp179 = _tmp109 * _tmp46 + _tmp117 * _tmp129 + _tmp121 * _tmp169 +
                         _tmp122 * _tmp167 + _tmp122 * _tmp170 - _tmp122 * _tmp46 -
                         _tmp125 * _tmp38 - _tmp136 * q0_xyzw(2, 0) - _tmp138 * q0_xyzw(3, 0) -
                         _tmp140 * _tmp154 - _tmp167 * _tmp75 + _tmp168 - _tmp171 * q0_xyzw(3, 0) +
                         _tmp172 + _tmp176 + _tmp178 + _tmp46 * _tmp75;
  const Scalar _tmp180 = 2 * _tmp153 + 4 * _tmp168 - 4 * _tmp173 + 4 * _tmp175;
  const Scalar _tmp181 = _tmp144 * q0_xyzw(1, 0);
  const Scalar _tmp182 = _tmp137 * q0_xyzw(1, 0);
  const Scalar _tmp183 = _tmp110 * _tmp48;
  const Scalar _tmp184 = -_tmp102 * _tmp113 + _tmp157 * _tmp96;
  const Scalar _tmp185 = _tmp142 * _tmp86;
  const Scalar _tmp186 = _tmp130 * q0_xyzw(2, 0);
  const Scalar _tmp187 = _tmp117 + _tmp185 + _tmp186;
  const Scalar _tmp188 = _tmp109 * _tmp39 - _tmp109 * _tmp42 + _tmp117 * _tmp140 -
                         _tmp122 * _tmp39 + _tmp122 * _tmp42 + _tmp123 * q0_xyzw(1, 0) -
                         _tmp124 * _tmp135 + _tmp129 * _tmp154 - _tmp134 * _tmp155 -
                         _tmp171 * q0_xyzw(1, 0) + _tmp181 - _tmp182 * _tmp53 - _tmp183 + _tmp184 +
                         _tmp187 + _tmp39 * _tmp75 - _tmp42 * _tmp75;
  const Scalar _tmp189 = 2 * _tmp116 - 4 * _tmp181 - 4 * _tmp183 - 4 * _tmp186;
  const Scalar _tmp190 = -_tmp156;
  const Scalar _tmp191 = _tmp92 - _tmp93 - _tmp94 + _tmp95;
  const Scalar _tmp192 = _tmp59 * _tmp90;
  const Scalar _tmp193 = _tmp59 * _tmp80;
  const Scalar _tmp194 = _tmp100 - _tmp101 + _tmp98 - _tmp99;
  const Scalar _tmp195 = _tmp4 * _tmp87;
  const Scalar _tmp196 = _tmp194 * _tmp88 + _tmp195 * _tmp53;
  const Scalar _tmp197 = _tmp103 * _tmp86 - _tmp191 * _tmp192 - _tmp191 * _tmp193 +
                         _tmp191 * _tmp79 + _tmp191 * _tmp81 - _tmp191 * _tmp89 + _tmp191 * _tmp91 +
                         _tmp196;
  const Scalar _tmp198 = _tmp108 * _tmp197;
  const Scalar _tmp199 = _tmp12 * _tmp198;
  const Scalar _tmp200 = _tmp137 * _tmp191;
  const Scalar _tmp201 = _tmp191 * _tmp74;
  const Scalar _tmp202 = _tmp59 * _tmp72;
  const Scalar _tmp203 = _tmp191 * _tmp202;
  const Scalar _tmp204 = _tmp135 * q0_xyzw(2, 0);
  const Scalar _tmp205 = _tmp120 * _tmp197;
  const Scalar _tmp206 = _tmp139 * _tmp197;
  const Scalar _tmp207 = _tmp12 * _tmp205;
  const Scalar _tmp208 = _tmp112 * _tmp53;
  const Scalar _tmp209 = -_tmp157 * _tmp194 + _tmp208 * q0_xyzw(3, 0);
  const Scalar _tmp210 = _tmp117 * _tmp207 + _tmp127 - _tmp154 * _tmp206 + _tmp162 + _tmp163 -
                         _tmp167 * _tmp198 - _tmp167 * _tmp201 + _tmp167 * _tmp203 +
                         _tmp169 * _tmp205 + _tmp170 * _tmp203 + _tmp190 - _tmp197 * _tmp204 +
                         _tmp198 * _tmp46 - _tmp199 * q0_xyzw(3, 0) - _tmp200 * q0_xyzw(3, 0) +
                         _tmp201 * _tmp46 - _tmp203 * _tmp46 + _tmp209;
  const Scalar _tmp211 = -_tmp168;
  const Scalar _tmp212 = _tmp135 * q0_xyzw(3, 0);
  const Scalar _tmp213 = _tmp205 * _tmp38;
  const Scalar _tmp214 = -_tmp141 * _tmp194 - _tmp208 * q0_xyzw(2, 0);
  const Scalar _tmp215 = -_tmp127 * _tmp206 - _tmp134 * _tmp207 + _tmp152 * _tmp198 +
                         _tmp152 * _tmp201 - _tmp152 * _tmp203 - _tmp154 * _tmp213 + _tmp174 +
                         _tmp175 + _tmp178 - _tmp197 * _tmp212 + _tmp198 * _tmp47 +
                         _tmp198 * _tmp48 + _tmp201 * _tmp47 + _tmp201 * _tmp48 - _tmp203 * _tmp47 -
                         _tmp203 * _tmp48 + _tmp211 + _tmp214;
  const Scalar _tmp216 = _tmp59 * _tmp73;
  const Scalar _tmp217 = _tmp12 * q0_xyzw(0, 0);
  const Scalar _tmp218 = _tmp135 * q0_xyzw(1, 0);
  const Scalar _tmp219 = _tmp113 * _tmp194 - _tmp141 * _tmp53;
  const Scalar _tmp220 = _tmp118 * _tmp205 - _tmp127 * _tmp207 + _tmp134 * _tmp206 - _tmp181 +
                         _tmp183 + _tmp187 + _tmp191 * _tmp216 - _tmp197 * _tmp218 -
                         _tmp198 * _tmp43 - _tmp198 * _tmp44 + _tmp199 * q0_xyzw(0, 0) +
                         _tmp200 * q0_xyzw(0, 0) - _tmp201 * _tmp43 - _tmp201 * _tmp44 -
                         _tmp203 * _tmp217 + _tmp203 * _tmp43 + _tmp219;
  const Scalar _tmp221 = _tmp12 * q0_xyzw(1, 0);
  const Scalar _tmp222 = _tmp135 * q0_xyzw(0, 0);
  const Scalar _tmp223 = _tmp142 * _tmp194 + _tmp208 * q0_xyzw(1, 0);
  const Scalar _tmp224 = -_tmp114 - _tmp134;
  const Scalar _tmp225 = _tmp117 * _tmp206 + _tmp131 - _tmp134 * _tmp213 + _tmp149 +
                         _tmp154 * _tmp207 - _tmp182 * _tmp191 - _tmp197 * _tmp222 +
                         _tmp198 * _tmp39 - _tmp198 * _tmp42 - _tmp199 * q0_xyzw(1, 0) +
                         _tmp201 * _tmp39 - _tmp201 * _tmp42 + _tmp203 * _tmp221 -
                         _tmp203 * _tmp39 + _tmp203 * _tmp42 + _tmp223 + _tmp224;
  const Scalar _tmp226 = _tmp102 * _tmp202;
  const Scalar _tmp227 = -_tmp49 - _tmp50 + _tmp51 + _tmp52;
  const Scalar _tmp228 = _tmp103 * _tmp227 + _tmp191 * _tmp88;
  const Scalar _tmp229 = -_tmp102 * _tmp192 - _tmp102 * _tmp193 + _tmp102 * _tmp79 +
                         _tmp102 * _tmp81 - _tmp102 * _tmp89 + _tmp102 * _tmp91 + _tmp195 * _tmp86 +
                         _tmp228;
  const Scalar _tmp230 = _tmp106 * _tmp229;
  const Scalar _tmp231 = _tmp107 * _tmp230;
  const Scalar _tmp232 = _tmp12 * _tmp231;
  const Scalar _tmp233 = _tmp119 * _tmp230;
  const Scalar _tmp234 = _tmp12 * _tmp233;
  const Scalar _tmp235 = _tmp102 * _tmp74;
  const Scalar _tmp236 = _tmp233 * _tmp38;
  const Scalar _tmp237 = _tmp135 * _tmp229;
  const Scalar _tmp238 = _tmp233 * _tmp41;
  const Scalar _tmp239 = _tmp112 * _tmp191;
  const Scalar _tmp240 = -_tmp113 * _tmp227 + _tmp239 * q0_xyzw(3, 0);
  const Scalar _tmp241 = -_tmp102 * _tmp182 + _tmp117 * _tmp238 - _tmp134 * _tmp236 +
                         _tmp154 * _tmp234 + _tmp154 + _tmp176 + _tmp177 + _tmp211 +
                         _tmp221 * _tmp226 - _tmp226 * _tmp39 + _tmp226 * _tmp42 +
                         _tmp231 * _tmp39 - _tmp231 * _tmp42 - _tmp232 * q0_xyzw(1, 0) +
                         _tmp235 * _tmp39 - _tmp235 * _tmp42 - _tmp237 * q0_xyzw(0, 0) + _tmp240;
  const Scalar _tmp242 = _tmp231 * _tmp38;
  const Scalar _tmp243 = -_tmp141 * _tmp191 - _tmp157 * _tmp227;
  const Scalar _tmp244 = -_tmp127 * _tmp238 + _tmp132 - _tmp134 * _tmp234 + _tmp145 + _tmp148 -
                         _tmp152 * _tmp226 + _tmp152 * _tmp235 - _tmp154 * _tmp236 -
                         _tmp212 * _tmp229 + _tmp224 - _tmp226 * _tmp47 - _tmp226 * _tmp48 +
                         _tmp231 * _tmp47 + _tmp231 * _tmp48 + _tmp235 * _tmp47 + _tmp235 * _tmp48 +
                         _tmp242 * q0_xyzw(1, 0) + _tmp243;
  const Scalar _tmp245 = _tmp137 * q0_xyzw(3, 0);
  const Scalar _tmp246 = _tmp141 * _tmp227 - _tmp239 * q0_xyzw(1, 0);
  const Scalar _tmp247 =
      -_tmp102 * _tmp245 + _tmp117 * _tmp234 + _tmp117 - _tmp154 * _tmp238 + _tmp167 * _tmp226 -
      _tmp167 * _tmp235 + _tmp169 * _tmp233 + _tmp170 * _tmp226 + _tmp181 + _tmp183 + _tmp185 -
      _tmp186 - _tmp226 * _tmp46 + _tmp231 * _tmp46 - _tmp232 * q0_xyzw(3, 0) + _tmp235 * _tmp46 -
      _tmp237 * q0_xyzw(2, 0) - _tmp242 * q0_xyzw(0, 0) + _tmp246;
  const Scalar _tmp248 = _tmp137 * q0_xyzw(0, 0);
  const Scalar _tmp249 = _tmp142 * _tmp227 + _tmp239 * q0_xyzw(2, 0);
  const Scalar _tmp250 = _tmp102 * _tmp216 + _tmp102 * _tmp248 + _tmp118 * _tmp233 -
                         _tmp127 * _tmp234 + _tmp134 * _tmp238 + _tmp160 + _tmp161 + _tmp164 +
                         _tmp190 - _tmp217 * _tmp226 + _tmp226 * _tmp43 - _tmp231 * _tmp43 -
                         _tmp231 * _tmp44 + _tmp232 * q0_xyzw(0, 0) - _tmp235 * _tmp43 -
                         _tmp235 * _tmp44 - _tmp237 * q0_xyzw(1, 0) + _tmp249;
  const Scalar _tmp251 = _tmp227 * _tmp59;
  const Scalar _tmp252 = _tmp251 * _tmp72;
  const Scalar _tmp253 = _tmp227 * _tmp74;
  const Scalar _tmp254 = _tmp82 + _tmp83 + _tmp84 + _tmp85;
  const Scalar _tmp255 = _tmp112 * _tmp254;
  const Scalar _tmp256 = _tmp255 * q0_xyzw(1, 0);
  const Scalar _tmp257 = -_tmp256;
  const Scalar _tmp258 = _tmp137 * _tmp227;
  const Scalar _tmp259 = _tmp104 + _tmp227 * _tmp79 + _tmp227 * _tmp81 + _tmp227 * _tmp91 -
                         _tmp251 * _tmp77 - _tmp251 * _tmp80 - _tmp251 * _tmp90 + _tmp254 * _tmp88;
  const Scalar _tmp260 = _tmp120 * _tmp259;
  const Scalar _tmp261 = _tmp139 * _tmp259;
  const Scalar _tmp262 = _tmp128 * _tmp259;
  const Scalar _tmp263 = _tmp108 * _tmp259;
  const Scalar _tmp264 = _tmp12 * _tmp263;
  const Scalar _tmp265 = _tmp263 * _tmp38;
  const Scalar _tmp266 = _tmp117 * _tmp262 - _tmp154 * _tmp261 + _tmp167 * _tmp252 -
                         _tmp167 * _tmp253 + _tmp169 * _tmp260 + _tmp170 * _tmp252 + _tmp172 -
                         _tmp204 * _tmp259 - _tmp252 * _tmp46 + _tmp253 * _tmp46 + _tmp257 -
                         _tmp258 * q0_xyzw(3, 0) + _tmp263 * _tmp46 - _tmp264 * q0_xyzw(3, 0) -
                         _tmp265 * q0_xyzw(0, 0);
  const Scalar _tmp267 = _tmp12 * _tmp252;
  const Scalar _tmp268 = _tmp255 * q0_xyzw(2, 0);
  const Scalar _tmp269 = _tmp118 * _tmp260 - _tmp127 * _tmp262 + _tmp134 * _tmp261 + _tmp143 -
                         _tmp218 * _tmp259 + _tmp251 * _tmp73 + _tmp252 * _tmp43 -
                         _tmp253 * _tmp43 - _tmp253 * _tmp44 + _tmp258 * q0_xyzw(0, 0) -
                         _tmp263 * _tmp44 + _tmp264 * q0_xyzw(0, 0) - _tmp265 * q0_xyzw(3, 0) -
                         _tmp267 * q0_xyzw(0, 0) + _tmp268;
  const Scalar _tmp270 = _tmp255 * q0_xyzw(3, 0);
  const Scalar _tmp271 = _tmp260 * _tmp38;
  const Scalar _tmp272 = _tmp117 * _tmp261 - _tmp134 * _tmp271 + _tmp154 * _tmp262 -
                         _tmp182 * _tmp227 + _tmp184 - _tmp222 * _tmp259 - _tmp252 * _tmp39 +
                         _tmp252 * _tmp42 + _tmp253 * _tmp39 - _tmp253 * _tmp42 + _tmp263 * _tmp39 -
                         _tmp263 * _tmp42 - _tmp264 * q0_xyzw(1, 0) + _tmp267 * q0_xyzw(1, 0) +
                         _tmp270;
  const Scalar _tmp273 = _tmp141 * _tmp254;
  const Scalar _tmp274 = -_tmp273;
  const Scalar _tmp275 = -_tmp127 * _tmp261 - _tmp134 * _tmp262 - _tmp152 * _tmp252 +
                         _tmp152 * _tmp253 - _tmp154 * _tmp271 + _tmp158 - _tmp212 * _tmp259 -
                         _tmp252 * _tmp47 - _tmp252 * _tmp48 + _tmp253 * _tmp47 + _tmp253 * _tmp48 +
                         _tmp263 * _tmp47 + _tmp263 * _tmp48 + _tmp265 * q0_xyzw(1, 0) + _tmp274;
  const Scalar _tmp276 = _tmp59 * _tmp96;
  const Scalar _tmp277 = _tmp103 * _tmp254 + _tmp196 - _tmp276 * _tmp77 - _tmp276 * _tmp80 -
                         _tmp276 * _tmp90 + _tmp79 * _tmp96 + _tmp81 * _tmp96 + _tmp91 * _tmp96;
  const Scalar _tmp278 = _tmp108 * _tmp277;
  const Scalar _tmp279 = _tmp12 * _tmp278;
  const Scalar _tmp280 = _tmp11 * _tmp97;
  const Scalar _tmp281 = _tmp202 * _tmp280;
  const Scalar _tmp282 = _tmp135 * _tmp277;
  const Scalar _tmp283 = _tmp280 * _tmp74;
  const Scalar _tmp284 = _tmp276 * _tmp72;
  const Scalar _tmp285 = _tmp278 * _tmp38;
  const Scalar _tmp286 = _tmp120 * _tmp277;
  const Scalar _tmp287 = _tmp74 * _tmp96;
  const Scalar _tmp288 = _tmp12 * _tmp286;
  const Scalar _tmp289 = _tmp139 * _tmp277;
  const Scalar _tmp290 = _tmp117 * _tmp288 - _tmp154 * _tmp289 + _tmp167 * _tmp284 -
                         _tmp167 * _tmp287 + _tmp169 * _tmp286 + _tmp209 + _tmp273 +
                         _tmp278 * _tmp46 - _tmp279 * q0_xyzw(3, 0) + _tmp281 * q0_xyzw(3, 0) -
                         _tmp282 * q0_xyzw(2, 0) - _tmp283 * q0_xyzw(3, 0) - _tmp284 * _tmp46 -
                         _tmp285 * q0_xyzw(0, 0) + _tmp287 * _tmp46;
  const Scalar _tmp291 = _tmp118 * _tmp286 - _tmp127 * _tmp288 + _tmp134 * _tmp289 + _tmp219 +
                         _tmp270 + _tmp276 * _tmp73 - _tmp278 * _tmp43 - _tmp278 * _tmp44 +
                         _tmp279 * q0_xyzw(0, 0) - _tmp281 * q0_xyzw(0, 0) -
                         _tmp282 * q0_xyzw(1, 0) + _tmp283 * q0_xyzw(0, 0) + _tmp284 * _tmp43 -
                         _tmp287 * _tmp43 - _tmp287 * _tmp44;
  const Scalar _tmp292 = _tmp286 * _tmp38;
  const Scalar _tmp293 = -_tmp127 * _tmp289 - _tmp134 * _tmp288 - _tmp152 * _tmp284 +
                         _tmp152 * _tmp287 - _tmp154 * _tmp292 - _tmp212 * _tmp277 + _tmp214 +
                         _tmp257 + _tmp278 * _tmp47 + _tmp278 * _tmp48 - _tmp281 * q0_xyzw(2, 0) +
                         _tmp283 * q0_xyzw(2, 0) - _tmp284 * _tmp48 + _tmp285 * q0_xyzw(1, 0) +
                         _tmp287 * _tmp48;
  const Scalar _tmp294 = -_tmp268;
  const Scalar _tmp295 = _tmp117 * _tmp289 - _tmp134 * _tmp292 + _tmp154 * _tmp288 + _tmp223 +
                         _tmp278 * _tmp39 - _tmp278 * _tmp42 - _tmp279 * q0_xyzw(1, 0) +
                         _tmp281 * q0_xyzw(1, 0) - _tmp282 * q0_xyzw(0, 0) -
                         _tmp283 * q0_xyzw(1, 0) - _tmp284 * _tmp39 + _tmp284 * _tmp42 +
                         _tmp287 * _tmp39 - _tmp287 * _tmp42 + _tmp294;
  const Scalar _tmp296 = -_tmp192 * _tmp194 - _tmp193 * _tmp194 + _tmp194 * _tmp79 +
                         _tmp194 * _tmp81 - _tmp194 * _tmp89 + _tmp194 * _tmp91 +
                         _tmp195 * _tmp254 + _tmp228;
  const Scalar _tmp297 = _tmp139 * _tmp296;
  const Scalar _tmp298 = _tmp194 * _tmp202;
  const Scalar _tmp299 = _tmp120 * _tmp296;
  const Scalar _tmp300 = _tmp299 * _tmp38;
  const Scalar _tmp301 = _tmp108 * _tmp296;
  const Scalar _tmp302 = _tmp194 * _tmp74;
  const Scalar _tmp303 = _tmp301 * _tmp38;
  const Scalar _tmp304 = _tmp12 * _tmp299;
  const Scalar _tmp305 = -_tmp127 * _tmp297 - _tmp134 * _tmp304 - _tmp152 * _tmp298 +
                         _tmp152 * _tmp302 - _tmp154 * _tmp300 - _tmp212 * _tmp296 + _tmp243 +
                         _tmp294 - _tmp298 * _tmp47 - _tmp298 * _tmp48 + _tmp301 * _tmp47 +
                         _tmp301 * _tmp48 + _tmp302 * _tmp47 + _tmp302 * _tmp48 +
                         _tmp303 * q0_xyzw(1, 0);
  const Scalar _tmp306 = _tmp12 * _tmp301;
  const Scalar _tmp307 = _tmp117 * _tmp304 - _tmp154 * _tmp297 + _tmp167 * _tmp298 -
                         _tmp167 * _tmp302 + _tmp169 * _tmp299 + _tmp170 * _tmp298 -
                         _tmp194 * _tmp245 - _tmp204 * _tmp296 + _tmp246 + _tmp270 -
                         _tmp298 * _tmp46 + _tmp301 * _tmp46 + _tmp302 * _tmp46 -
                         _tmp303 * q0_xyzw(0, 0) - _tmp306 * q0_xyzw(3, 0);
  const Scalar _tmp308 = _tmp117 * _tmp300 - _tmp127 * _tmp304 + _tmp134 * _tmp297 +
                         _tmp194 * _tmp216 + _tmp194 * _tmp248 - _tmp217 * _tmp298 -
                         _tmp218 * _tmp296 + _tmp249 + _tmp274 + _tmp298 * _tmp43 -
                         _tmp301 * _tmp43 - _tmp301 * _tmp44 - _tmp302 * _tmp43 - _tmp302 * _tmp44 +
                         _tmp306 * q0_xyzw(0, 0);
  const Scalar _tmp309 = _tmp117 * _tmp297 - _tmp134 * _tmp300 + _tmp154 * _tmp304 -
                         _tmp182 * _tmp194 + _tmp221 * _tmp298 - _tmp222 * _tmp296 + _tmp240 +
                         _tmp256 - _tmp298 * _tmp39 + _tmp298 * _tmp42 + _tmp301 * _tmp39 -
                         _tmp301 * _tmp42 + _tmp302 * _tmp39 - _tmp302 * _tmp42 -
                         _tmp306 * q0_xyzw(1, 0);

  // Output terms (3)
  if (q_out != nullptr) {
    Eigen::Matrix<Scalar, 4, 1>& _q_out = (*q_out);

    _q_out(0, 0) =
        -_tmp36 * _tmp39 + _tmp36 * _tmp42 + _tmp37 * q0_xyzw(1, 0) + _tmp40 * q0_xyzw(0, 0);
    _q_out(1, 0) =
        _tmp36 * _tmp43 + _tmp36 * _tmp44 - _tmp37 * q0_xyzw(0, 0) + _tmp40 * q0_xyzw(1, 0);
    _q_out(2, 0) =
        -_tmp36 * _tmp46 + _tmp37 * q0_xyzw(3, 0) + _tmp40 * q0_xyzw(2, 0) + _tmp45 * q0_xyzw(0, 0);
    _q_out(3, 0) =
        -_tmp36 * _tmp47 - _tmp36 * _tmp48 + _tmp40 * q0_xyzw(3, 0) - _tmp45 * q0_xyzw(1, 0);
  }

  if (D0 != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _D0 = (*D0);

    _D0(0, 0) = _tmp150 * _tmp151 - _tmp165 * _tmp166 - _tmp179 * _tmp180 + _tmp188 * _tmp189;
    _D0(1, 0) = _tmp150 * _tmp189 - _tmp151 * _tmp188 - _tmp165 * _tmp180 + _tmp166 * _tmp179;
    _D0(2, 0) = -_tmp150 * _tmp166 - _tmp151 * _tmp165 + _tmp179 * _tmp189 + _tmp180 * _tmp188;
    _D0(0, 1) = _tmp151 * _tmp220 - _tmp166 * _tmp215 - _tmp180 * _tmp210 + _tmp189 * _tmp225;
    _D0(1, 1) = -_tmp151 * _tmp225 + _tmp166 * _tmp210 - _tmp180 * _tmp215 + _tmp189 * _tmp220;
    _D0(2, 1) = -_tmp151 * _tmp215 - _tmp166 * _tmp220 + _tmp180 * _tmp225 + _tmp189 * _tmp210;
    _D0(0, 2) = _tmp151 * _tmp250 - _tmp166 * _tmp244 - _tmp180 * _tmp247 + _tmp189 * _tmp241;
    _D0(1, 2) = -_tmp151 * _tmp241 + _tmp166 * _tmp247 - _tmp180 * _tmp244 + _tmp189 * _tmp250;
    _D0(2, 2) = -_tmp151 * _tmp244 - _tmp166 * _tmp250 + _tmp180 * _tmp241 + _tmp189 * _tmp247;
  }

  if (D1 != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _D1 = (*D1);

    _D1(0, 0) = _tmp151 * _tmp269 - _tmp166 * _tmp275 - _tmp180 * _tmp266 + _tmp189 * _tmp272;
    _D1(1, 0) = -_tmp151 * _tmp272 + _tmp166 * _tmp266 - _tmp180 * _tmp275 + _tmp189 * _tmp269;
    _D1(2, 0) = -_tmp151 * _tmp275 - _tmp166 * _tmp269 + _tmp180 * _tmp272 + _tmp189 * _tmp266;
    _D1(0, 1) = _tmp151 * _tmp291 - _tmp166 * _tmp293 - _tmp180 * _tmp290 + _tmp189 * _tmp295;
    _D1(1, 1) = -_tmp151 * _tmp295 + _tmp166 * _tmp290 - _tmp180 * _tmp293 + _tmp189 * _tmp291;
    _D1(2, 1) = -_tmp151 * _tmp293 - _tmp166 * _tmp291 + _tmp180 * _tmp295 + _tmp189 * _tmp290;
    _D1(0, 2) = _tmp151 * _tmp308 - _tmp166 * _tmp305 - _tmp180 * _tmp307 + _tmp189 * _tmp309;
    _D1(1, 2) = -_tmp151 * _tmp309 + _tmp166 * _tmp307 - _tmp180 * _tmp305 + _tmp189 * _tmp308;
    _D1(2, 2) = -_tmp151 * _tmp305 - _tmp166 * _tmp308 + _tmp180 * _tmp309 + _tmp189 * _tmp307;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
