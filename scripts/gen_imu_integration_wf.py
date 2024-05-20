"""
Generate quaternion interpolation with derivatives using wrenfold.
"""

import typing as T

from wrenfold import sym
from wrenfold.code_generation import (
    OutputArg,
)
from wrenfold.geometry import Quaternion
from wrenfold.type_annotations import Vector4, Vector3, RealScalar
from wrenfold.sympy_conversion import to_sympy, from_sympy

from utils import get_output_dir, generate_wrenfold_function
from symforce_utils import configure_symforce


def blockwise_jacobians(
    output_states: T.Iterable[T.Union[sym.MatrixExpr, Quaternion]],
    input_states: T.Iterable[T.Union[sym.MatrixExpr, Quaternion]],
) -> sym.MatrixExpr:
    jacobians = []
    for out_state in output_states:
        jacobians_row = []
        for in_state in input_states:
            out_expressions = (
                out_state.to_vector_wxyz()
                if isinstance(out_state, Quaternion)
                else out_state
            )
            in_expressions = (
                in_state.to_vector_wxyz()
                if isinstance(in_state, Quaternion)
                else in_state
            )

            out_D_in = sym.jacobian(out_expressions, in_expressions)
            if isinstance(out_state, Quaternion):
                out_D_in = out_state.right_local_coordinates_derivative() * out_D_in
            if isinstance(in_state, Quaternion):
                out_D_in = out_D_in * in_state.right_retract_derivative()
            jacobians_row.append(out_D_in)

        jacobians.append(sym.hstack(jacobians_row))

    return sym.vstack(jacobians)


def integrate_imu(
    i_R_j_xyzw: Vector4,
    i_p_j: Vector3,
    i_v_j: Vector3,
    gyro_bias: Vector3,
    accelerometer_bias: Vector3,
    angular_velocity: Vector3,
    linear_acceleration: Vector3,
    dt: RealScalar,
):
    """
    We take an incremental navigation state represented by the 9DOF product of:
    - Rotation from frame i to j: i_R_j_xyzw (a scalar last quaternion)
    - Translation from frame i to j: i_p_j
    - Velocity delta from frame i to j: i_v_j

    Given a gyro and accelerometer measurement (plus their respective biases), we integrate
    the state forward.

    The updated state is returned, as well as the 9x9 Jacobian of the new state with respect
    to the previous one. In addition, we compute 9x6 jacobians of the new state with respect
    to the input measurements and sensor biases. These would typically be used to propagate
    forward your filter uncertainty.
    """

    # This operation does not produce a math operation - it can be thought of as a cast
    # from vector storage to a Quaternion.
    i_R_j: Quaternion = Quaternion.from_xyzw(i_R_j_xyzw)

    # Subtract biases from the input measurements:
    angular_velocity_unbiased = angular_velocity - gyro_bias
    linear_acceleration_unbiased = linear_acceleration - accelerometer_bias

    # Rotation from frame `j` (start of integration) to frame `k` (end of integration)
    angular_vel_times_dt = angular_velocity_unbiased * dt
    j_R_k: Quaternion = Quaternion.from_rotation_vector(
        angular_vel_times_dt, epsilon=1.0e-16
    )

    # Rotate the acceleration back into frame `i`:
    accel_in_i = i_R_j.to_rotation_matrix() * linear_acceleration_unbiased

    # Integrate position and velocity:
    i_p_k = i_p_j + i_v_j * dt + accel_in_i * (sym.abs(dt) * dt / 2)
    i_v_k = i_v_j + accel_in_i * dt

    # Integrate rotation:
    i_R_k = i_R_j * j_R_k

    # Determine jacobians:
    k_D_j = blockwise_jacobians(
        output_states=(i_R_k, i_p_k, i_v_k), input_states=(i_R_j, i_p_j, i_v_j)
    )

    k_D_measurements = blockwise_jacobians(
        output_states=(i_R_k, i_p_k, i_v_k),
        input_states=(angular_velocity, linear_acceleration),
    )

    # Debatable whether you want to do this here, or just do it numerically after invoking the
    # generated code. I'll put it here for the sake of completeness in this example.
    k_D_bias = -k_D_measurements

    return [
        OutputArg(i_R_k.normalized().to_vector_xyzw(), name="i_R_k"),
        OutputArg(i_p_k, name="i_p_k"),
        OutputArg(i_v_k, name="i_v_k"),
        OutputArg(k_D_j, name="k_D_j", is_optional=True),
        OutputArg(k_D_measurements, name="k_D_measurements", is_optional=True),
        OutputArg(k_D_bias, name="k_D_bias", is_optional=True),
    ]


def integrate_imu_sffo(
    i_R_j_xyzw: Vector4,
    i_p_j: Vector3,
    i_v_j: Vector3,
    gyro_bias: Vector3,
    accelerometer_bias: Vector3,
    angular_velocity: Vector3,
    linear_acceleration: Vector3,
    dt: RealScalar,
):
    """Convert symforce first-order to wrenfold so we can generate it."""
    configure_symforce()

    from imu_integration_expressions_sf import integrate_imu_first_order

    values = integrate_imu_first_order(
        i_R_j_xyzw=to_sympy(i_R_j_xyzw),
        i_p_j=to_sympy(i_p_j),
        i_v_j=to_sympy(i_v_j),
        gyro_bias=to_sympy(gyro_bias),
        accelerometer_bias=to_sympy(accelerometer_bias),
        angular_velocity=to_sympy(angular_velocity),
        linear_acceleration=to_sympy(linear_acceleration),
        dt=to_sympy(dt),
    )
    return (
        OutputArg(from_sympy(values["i_R_k"].mat), name="i_R_k"),
        OutputArg(from_sympy(values["i_p_k"].mat), name="i_p_k"),
        OutputArg(from_sympy(values["i_v_k"].mat), name="i_v_k"),
        OutputArg(from_sympy(values["k_D_j"].mat), name="k_D_j", is_optional=True),
        OutputArg(
            from_sympy(values["k_D_measurements"].mat),
            name="k_D_measurements",
            is_optional=True,
        ),
        OutputArg(
            from_sympy(values["k_D_bias"].mat), name="k_D_bias", is_optional=True
        ),
    )


def main():
    output_dir = get_output_dir("imu_integration") / "wf"
    generate_wrenfold_function(integrate_imu, output_dir=output_dir)
    generate_wrenfold_function(integrate_imu_sffo, output_dir=output_dir)


if __name__ == "__main__":
    main()
