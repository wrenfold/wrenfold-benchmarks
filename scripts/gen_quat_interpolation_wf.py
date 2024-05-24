"""
Generate quaternion interpolation with derivatives using wrenfold.
"""

from wrenfold import sym
from wrenfold.code_generation import (
    OutputArg,
    OptimizationParams,
)
from wrenfold.geometry import Quaternion
from wrenfold.type_annotations import Vector4, FloatScalar
from wrenfold.sympy_conversion import to_sympy, from_sympy

from utils import get_output_dir, generate_wrenfold_function
from symforce_utils import configure_symforce


def quat_local_coordinates_impl(q0_xyzw: Vector4, q1_xyzw: Vector4, use_conditional: bool):
    """
    Tangent-space difference between two scalar-last quaternions, w/ derivatives.
    """
    q0: Quaternion = Quaternion.from_xyzw(q0_xyzw)
    q1: Quaternion = Quaternion.from_xyzw(q1_xyzw)

    # We are comparing to symforce, so take the acos() code-path.
    out = (q0.conjugate() * q1).to_rotation_vector(
        epsilon=1.0e-16 if use_conditional else None, use_atan2=False)
    D0 = out.jacobian(q0.to_vector_wxyz()) * q0.right_retract_derivative()
    D1 = out.jacobian(q1.to_vector_wxyz()) * q1.right_retract_derivative()

    return (
        OutputArg(out, name="out"),
        OutputArg(D0, name="d0", is_optional=True),
        OutputArg(D1, name="d1", is_optional=True),
    )


def quat_local_coordinates(q0_xyzw: Vector4, q1_xyzw: Vector4):
    return quat_local_coordinates_impl(q0_xyzw, q1_xyzw, use_conditional=True)


def quat_local_coordinates_no_conditional(q0_xyzw: Vector4, q1_xyzw: Vector4):
    return quat_local_coordinates_impl(q0_xyzw, q1_xyzw, use_conditional=False)


def quat_local_coordinates_sffo(q0_xyzw: Vector4, q1_xyzw: Vector4):
    """
    Compute the "first order" local coordinates using symforce, then convert it back
    to wrenfold for code generation.
    """
    configure_symforce()

    from quat_expressions_sf import quat_local_coordinates as quat_local_coordinates_sf

    values = quat_local_coordinates_sf(
        to_sympy(q0_xyzw), to_sympy(q1_xyzw), jacobian_method="first_order")
    return (
        OutputArg(from_sympy(values["out"].mat), name="out"),
        OutputArg(from_sympy(values["D0"].mat), name="d0", is_optional=True),
        OutputArg(from_sympy(values["D1"].mat), name="d1", is_optional=True),
    )


def quat_interpolation_impl(q0_xyzw: Vector4,
                            q1_xyzw: Vector4,
                            alpha: FloatScalar,
                            use_conditional: bool = True):
    """
    Quaternion interpolation.
    """
    q0: Quaternion = Quaternion.from_xyzw(q0_xyzw)
    q1: Quaternion = Quaternion.from_xyzw(q1_xyzw)

    # We are comparing to symforce, so take the acos() code-path.
    w01 = (q0.conjugate() * q1).to_rotation_vector(
        epsilon=1.0e-16 if use_conditional else None, use_atan2=False)

    q_out = q0 * Quaternion.from_rotation_vector(
        w01 * alpha, epsilon=1.0e-16 if use_conditional else None)
    D0 = (
        q_out.right_local_coordinates_derivative() *
        sym.jacobian(q_out.to_vector_wxyz(), q0.to_vector_wxyz()) * q0.right_retract_derivative())
    D1 = (
        q_out.right_local_coordinates_derivative() *
        sym.jacobian(q_out.to_vector_wxyz(), q1.to_vector_wxyz()) * q1.right_retract_derivative())

    return (
        OutputArg(q_out.to_vector_xyzw(), name="q_out"),
        OutputArg(D0, name="d0", is_optional=True),
        OutputArg(D1, name="d1", is_optional=True),
    )


def quat_interpolation(q0_xyzw: Vector4, q1_xyzw: Vector4, alpha: FloatScalar):
    return quat_interpolation_impl(q0_xyzw, q1_xyzw, alpha, use_conditional=True)


def quat_interpolation_no_conditional(q0_xyzw: Vector4, q1_xyzw: Vector4, alpha: FloatScalar):
    return quat_interpolation_impl(q0_xyzw, q1_xyzw, alpha, use_conditional=False)


def quat_interpolation_sffo(q0_xyzw: Vector4, q1_xyzw: Vector4, alpha: FloatScalar):
    """
    Compute the "first order" quat interpolation using symforce, then convert it back
    to wrenfold for code generation.
    """
    configure_symforce()

    from quat_expressions_sf import quat_interpolate as quat_interpolate_sf

    values = quat_interpolate_sf(
        to_sympy(q0_xyzw), to_sympy(q1_xyzw), alpha=to_sympy(alpha), jacobian_method="first_order")
    return (
        OutputArg(from_sympy(values["q_out"].mat), name="q_out"),
        OutputArg(from_sympy(values["D0"].mat), name="d0", is_optional=True),
        OutputArg(from_sympy(values["D1"].mat), name="d1", is_optional=True),
    )


def main():
    output_dir = get_output_dir("quat_interpolation") / "wf"

    params = OptimizationParams()
    params.factorization_passes = 3
    generate_wrenfold_function(quat_local_coordinates, output_dir=output_dir, params=params)
    generate_wrenfold_function(
        quat_local_coordinates_no_conditional, output_dir=output_dir, params=params)
    generate_wrenfold_function(quat_local_coordinates_sffo, output_dir=output_dir, params=params)

    generate_wrenfold_function(quat_interpolation, output_dir=output_dir, params=params)
    generate_wrenfold_function(
        quat_interpolation_no_conditional, output_dir=output_dir, params=params)
    generate_wrenfold_function(quat_interpolation_sffo, output_dir=output_dir, params=params)


if __name__ == "__main__":
    main()
