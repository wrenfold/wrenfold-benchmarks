"""
Generate first-order rolling shutter camera model using symforce.
"""

import symforce

symforce.set_symbolic_api("symengine")
symforce.set_epsilon_to_symbol()

from symforce import geo
from symforce import typing as T

from utils import get_output_dir
from symforce_utils import generate_symforce_function
from rolling_shutter_camera_expressions_sf import integrate_and_project


def integrate_and_project_chain(
    world_R_imu_xyzw: geo.V4,
    world_t_imu: geo.V3,
    imu_R_cam_xyzw: geo.V4,
    imu_t_cam: geo.V3,
    angular_velocity_imu: geo.V3,
    world_v_imu: geo.V3,
    p_world: geo.V3,
    row_time: T.Scalar,
    camera: geo.V9,
):
    return integrate_and_project(
        world_R_imu_xyzw,
        world_t_imu,
        imu_R_cam_xyzw,
        imu_t_cam,
        angular_velocity_imu,
        world_v_imu,
        p_world,
        row_time,
        camera,
        jacobian_method="chain",
    )


def integrate_and_project_first_order(
    world_R_imu_xyzw: geo.V4,
    world_t_imu: geo.V3,
    imu_R_cam_xyzw: geo.V4,
    imu_t_cam: geo.V3,
    angular_velocity_imu: geo.V3,
    world_v_imu: geo.V3,
    p_world: geo.V3,
    row_time: T.Scalar,
    camera: geo.V9,
):
    return integrate_and_project(
        world_R_imu_xyzw,
        world_t_imu,
        imu_R_cam_xyzw,
        imu_t_cam,
        angular_velocity_imu,
        world_v_imu,
        p_world,
        row_time,
        camera,
        jacobian_method="first_order",
    )


def main():
    output_dir = get_output_dir("rolling_shutter_camera") / "sf"
    generate_symforce_function(integrate_and_project_chain, output_dir)
    generate_symforce_function(integrate_and_project_first_order, output_dir)


if __name__ == "__main__":
    main()
