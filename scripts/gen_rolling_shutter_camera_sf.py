"""
Generate first-order rolling shutter camera model using symforce.
"""
import symforce
symforce.set_symbolic_api("symengine")
symforce.set_epsilon_to_symbol()

from symforce import geo
from symforce import typing as T
from symforce.values import Values
from symforce.jacobian_helpers import (
    tangent_jacobians_chain_rule,
    tangent_jacobians_first_order,
)

from utils import get_output_dir
from symforce_utils import generate_symforce_function


def diff(a, b, jacobian_method: str) -> geo.Matrix:
    if jacobian_method == "chain":
        J, = tangent_jacobians_chain_rule(expr=a, args=[b])
    elif jacobian_method == "first_order":
        J, = tangent_jacobians_first_order(expr=a, args=[b])
    else:
        raise RuntimeError(f"Invalid arg: {jacobian_method}")
    return J


def opencv_project(p_cam: geo.V3, camera: geo.V9) -> geo.M21:
    """
    Project a point in camera frame using the OpenCV camera model.
    """
    p_image_plane = p_cam[0:2] / p_cam[2]
    r2 = p_image_plane.squared_norm()
    x, y = p_image_plane

    fx, fy, cx, cy, k1, k2, k3, p1, p2 = camera
    radial_coeff = (
        1 + k1 * r2 + k2 * (r2 * r2) + k3 * (r2 * r2 * r2)
    )

    # Compute distorted location:
    x_d = radial_coeff * x + 2 * p1 * x * y + p2 * (r2 + 2 * x * x)
    y_d = radial_coeff * y + 2 * p1 * (r2 + 2 * y * y) + p2 * x * y
    return geo.V2([x_d * fx + cx, y_d * fy + cy])


def integrate_and_project(
    world_R_imu_xyzw: geo.V4,
    world_t_imu: geo.V3,
    imu_R_cam_xyzw: geo.V4,
    imu_t_cam: geo.V3,
    angular_velocity_imu: geo.V3,
    world_v_imu: geo.V3,
    p_world: geo.V3,
    row_time: T.Scalar,
    camera: geo.V9,
    jacobian_method: str,
):
    """
    SymForce equivalent of `integrate_and_project` from gen_rolling_shutter_camera_wf.py
    """
    world_R_imu = geo.Rot3.from_storage(world_R_imu_xyzw)
    imu_R_cam = geo.Rot3.from_storage(imu_R_cam_xyzw)

    # Transform IMU to the specific row time:
    world_R_imu_at_row = world_R_imu * geo.Rot3.from_tangent(
        angular_velocity_imu * row_time, epsilon=1.0e-16
    )
    world_t_imu_at_row = world_t_imu + world_v_imu * row_time

    # Apply extrinsic transform:
    world_R_cam = world_R_imu_at_row * imu_R_cam
    world_t_cam = (
        world_t_imu_at_row + world_R_imu_at_row.to_rotation_matrix() * imu_t_cam
    )

    # Transform the point to camera frame:
    p_cam = world_R_cam.inverse().to_rotation_matrix() * (p_world - world_t_cam)

    # Project it:
    p_image = opencv_project(p_cam, camera=camera)

    return Values(
        p_image=p_image,
        D_world_R_imu=diff(p_image, world_R_imu, jacobian_method),
        D_world_t_imu=diff(p_image, world_t_imu, jacobian_method),
        D_imu_R_cam=diff(p_image, imu_R_cam, jacobian_method),
        D_imu_t_cam=diff(p_image, imu_t_cam, jacobian_method),
        D_angular_velocity_imu=diff(p_image, angular_velocity_imu, jacobian_method),
        D_world_v_imu=diff(p_image, world_v_imu, jacobian_method),
        D_p_world=diff(p_image, p_world, jacobian_method)
    )


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
        jacobian_method="chain"
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
        jacobian_method="first_order"
    )


def main():
    output_dir = get_output_dir("rolling_shutter_camera") / "sf"
    generate_symforce_function(integrate_and_project_chain, output_dir)
    generate_symforce_function(integrate_and_project_first_order, output_dir)


if __name__ == '__main__':
    main()
