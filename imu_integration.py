from pathlib import Path
import time

import symforce

symforce.set_epsilon_to_symbol()
symforce.set_symbolic_api("symengine")

from symforce import geo
from symforce import symbolic as sm
from symforce import typing as T
from symforce.codegen import Codegen, CodegenConfig, CppConfig
from symforce.values import Values
from symforce.jacobian_helpers import tangent_jacobians_chain_rule


THIS_DIR = Path(__file__).parent.absolute()


def blockwise_jacobians(output_states, input_states) -> geo.Matrix:
    jacobians_stacked = None
    for out_state in output_states:
        jacobian_row = None
        for in_state in input_states:
            out_D_in, = tangent_jacobians_chain_rule(expr=out_state,
                                                     args=[in_state])
            if jacobian_row is None:
                jacobian_row = out_D_in
            else:
                jacobian_row = jacobian_row.row_join(out_D_in)

        if jacobians_stacked is None:
            jacobians_stacked = jacobian_row
        else:
            jacobians_stacked = jacobians_stacked.col_join(jacobian_row)

    return jacobians_stacked


def integrate_imu(
    i_R_j: geo.Rot3,
    i_p_j: geo.V3,
    i_v_j: geo.V3,
    gyro_bias: geo.V3,
    accelerometer_bias: geo.V3,
    angular_velocity: geo.V3,
    linear_acceleration: geo.V3,
    dt: T.Scalar,
) -> Values:
    
    # Subtract biases from the input measurements:
    angular_velocity_unbiased = angular_velocity - gyro_bias
    linear_acceleration_unbiased = linear_acceleration - accelerometer_bias

    # Rotation from frame `j` (start of integration) to frame `k` (end of integration)
    angular_vel_times_dt = angular_velocity_unbiased * dt
    j_R_k = geo.Rot3.from_tangent(angular_vel_times_dt, epsilon=1.0e-16)

    # Rotate the acceleration back into frame `i`:
    accel_in_i = i_R_j.to_rotation_matrix() * linear_acceleration_unbiased

    # Integrate position and velocity:
    i_p_k = i_p_j + i_v_j * dt + accel_in_i * (sm.Abs(dt) * dt / 2)
    i_v_k = i_v_j + accel_in_i * dt

    # Integrate rotation:
    i_R_k = i_R_j * j_R_k

    # Determine jacobians:
    k_D_j = blockwise_jacobians(
        output_states=(i_R_k, i_p_k, i_v_k), input_states=(i_R_j, i_p_j, i_v_j))

    k_D_measurements = blockwise_jacobians(
        output_states=(i_R_k, i_p_k, i_v_k), input_states=(angular_velocity, linear_acceleration))

    k_D_bias = -k_D_measurements

    return Values(
        i_R_k=i_R_k,
        i_p_k=i_p_k,
        i_v_k=i_v_k,
        k_D_j=k_D_j,
        k_D_measurements=k_D_measurements,
        k_D_bias=k_D_bias,
    )



def main():
    config = CppConfig()
    start = time.time()
    cg = Codegen.function(func=integrate_imu, config=config)
    cg.generate_function(output_dir=THIS_DIR / "output" / "integrate_imu", skip_directory_nesting=True)
    end = time.time()
    print(f'Elapsed time: {end - start}')


if __name__ == '__main__':
    main()
