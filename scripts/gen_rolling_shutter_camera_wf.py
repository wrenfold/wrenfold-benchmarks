"""
Generate projection equations for a rolling shutter camera.
"""

import dataclasses
import typing as T

from wrenfold import sym
from wrenfold.code_generation import OutputArg, OptimizationParams, CppGenerator, cse_function_description, create_function_description
from wrenfold.geometry import Quaternion
from wrenfold.type_annotations import Vector4, Vector3, FloatScalar
from wrenfold.sympy_conversion import to_sympy, from_sympy
from wrenfold.type_info import CustomType

from utils import get_output_dir, generate_wrenfold_function
from symforce_utils import configure_symforce


@dataclasses.dataclass
class CameraParams:
    """
    Represent the parameters of an OpenCV camera with 3 radial distortion coefficients.
    """

    # Camera matrix.
    fx: FloatScalar
    fy: FloatScalar
    cx: FloatScalar
    cy: FloatScalar
    # Radial coeffs.
    k1: FloatScalar
    k2: FloatScalar
    k3: FloatScalar
    # Tangential coeffs.
    p1: FloatScalar
    p2: FloatScalar


def opencv_project(p_cam: Vector3, camera: CameraParams) -> sym.MatrixExpr:
    """
    Project a point in camera frame using the OpenCV camera model.
    """
    p_image_plane = sym.matrix(p_cam[0:2]) / p_cam[2]
    r2 = p_image_plane.squared_norm()
    x, y = p_image_plane

    radial_coeff = (1 + camera.k1 * r2 + camera.k2 * sym.pow(r2, 2) + camera.k3 * sym.pow(r2, 3))

    # Compute distorted location:
    x_d = radial_coeff * x + 2 * camera.p1 * x * y + camera.p2 * (r2 + 2 * x * x)
    y_d = radial_coeff * y + 2 * camera.p1 * (r2 + 2 * y * y) + camera.p2 * x * y
    x_pixels = x_d * camera.fx + camera.cx
    y_pixels = y_d * camera.fy + camera.cy
    return sym.vector(x_pixels, y_pixels)


def integrate_and_project(
    world_R_imu_xyzw: Vector4,
    world_t_imu: Vector3,
    imu_R_cam_xyzw: Vector4,
    imu_t_cam: Vector3,
    angular_velocity_imu: Vector3,
    world_v_imu: Vector3,
    p_world: Vector3,
    row_time: FloatScalar,
    camera: CameraParams,
):
    """
    A simple first-order integration model of a rolling shutter camera.

    Integrate a pose at the start of readout (world_R_imu, world_t_imu) to a specific row of
    the image using a constant velocity model specified by (angular_velocity_imu, world_v_imu).

    Then apply extrinsic transform (imu_R_cam, imu_t_cam) and project using an OpenCV camera model.
    """
    world_R_imu = Quaternion.from_xyzw(world_R_imu_xyzw)
    imu_R_cam = Quaternion.from_xyzw(imu_R_cam_xyzw)

    # Transform IMU to the specific row time:
    world_R_imu_at_row = world_R_imu * Quaternion.from_rotation_vector(
        angular_velocity_imu * row_time, epsilon=1.0e-16)
    world_t_imu_at_row = world_t_imu + world_v_imu * row_time

    # Apply extrinsic transform:
    world_R_cam = world_R_imu_at_row * imu_R_cam
    world_t_cam = (world_t_imu_at_row + world_R_imu_at_row.to_rotation_matrix() * imu_t_cam)

    # Transform the point to camera frame:
    p_cam = world_R_cam.conjugate().to_rotation_matrix() * (p_world - world_t_cam)

    # Project it:
    p_image = opencv_project(p_cam, camera=camera)

    # Output derivatives wrt to:
    # Pose in world: world_T_imu
    # Extrinsic pose: imu_T_cam
    # Angular velocity in IMU: angular_velocity_imu
    # Linear velocity in world: world_v_imu
    # The point: p_world
    return (
        OutputArg(p_image, "p_image"),
        OutputArg(
            sym.jacobian(p_image, world_R_imu.to_vector_wxyz()) *
            world_R_imu.right_retract_derivative(),
            "D_world_R_imu",
            True,
        ),
        OutputArg(sym.jacobian(p_image, world_t_imu), "D_world_t_imu", True),
        OutputArg(
            sym.jacobian(p_image, imu_R_cam.to_vector_wxyz()) *
            imu_R_cam.right_retract_derivative(),
            "D_imu_R_cam",
            True,
        ),
        OutputArg(sym.jacobian(p_image, imu_t_cam), "D_imu_t_cam", True),
        OutputArg(sym.jacobian(p_image, angular_velocity_imu), "D_angular_velocity_imu", True),
        OutputArg(sym.jacobian(p_image, world_v_imu), "D_world_v_imu", True),
        OutputArg(sym.jacobian(p_image, p_world), "D_p_world", True),
    )


class CustomGenerator(CppGenerator):

    def format_custom_type(self, element: CustomType) -> str:
        if element.python_type == CameraParams:
            return "camera_params_t"
        else:
            return self.super_format(element)


def main():
    output_dir = get_output_dir("rolling_shutter_camera") / "wf"
    params = OptimizationParams()
    params.factorization_passes = 5
    generate_wrenfold_function(
        integrate_and_project,
        output_dir=output_dir,
        params=params,
        generator=CustomGenerator(),
    )


if __name__ == "__main__":
    main()
