"""
Generate projection equations for a constant-velocity rolling shutter camera.
"""
import argparse
import dataclasses
import typing as T

from wrenfold import sym
from wrenfold.code_generation import OutputArg, CppGenerator
from wrenfold.geometry import Quaternion
from wrenfold.type_annotations import Vector4, Vector3, FloatScalar
from wrenfold.sympy_conversion import to_sympy, from_sympy
from wrenfold.type_info import CustomType

from utils import get_output_dir, generate_wrenfold_function


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

    def to_vector(self) -> sym.MatrixExpr:
        return sym.vector(
            self.fx,
            self.fy,
            self.cx,
            self.cy,
            self.k1,
            self.k2,
            self.k3,
            self.p1,
            self.p2,
        )

    @staticmethod
    def from_vector(vec: sym.MatrixExpr) -> "CameraParams":
        fx, fy, cx, cy, k1, k2, k3, p1, p2 = vec
        return CameraParams(fx, fy, cx, cy, k1, k2, k3, p1, p2)


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


def integrate_and_project_(
    world_R_imu: Quaternion,
    world_t_imu: Vector3,
    imu_R_cam: Quaternion,
    imu_t_cam: Vector3,
    angular_velocity_imu: Vector3,
    world_v_imu: Vector3,
    p_world: Vector3,
    row_time: FloatScalar,
    camera: CameraParams,
) -> sym.MatrixExpr:
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
    return opencv_project(p_cam, camera=camera)


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
    p_image = integrate_and_project_(
        world_R_imu=world_R_imu,
        world_t_imu=world_t_imu,
        imu_R_cam=imu_R_cam,
        imu_t_cam=imu_t_cam,
        angular_velocity_imu=angular_velocity_imu,
        world_v_imu=world_v_imu,
        p_world=p_world,
        row_time=row_time,
        camera=camera,
    )

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


def integrate_and_project_sffo(
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
    """Integrate and project using the SymForce first-order expressions."""
    from symforce_utils import configure_symforce

    configure_symforce()

    from rolling_shutter_camera_expressions_sf import integrate_and_project as \
        integrate_and_project_sf

    # We can't pass elements of `CameraParams` into SymForce, so instead generate substitute
    # variables and pass those.
    camera_sub_vars = sym.symbols('fx, fy, cx, cy, k1, k2, k3, p1, p2', real=True)

    values = integrate_and_project_sf(
        world_R_imu_xyzw=to_sympy(world_R_imu_xyzw),
        world_t_imu=to_sympy(world_t_imu),
        imu_R_cam_xyzw=to_sympy(imu_R_cam_xyzw),
        imu_t_cam=to_sympy(imu_t_cam),
        angular_velocity_imu=to_sympy(angular_velocity_imu),
        world_v_imu=to_sympy(world_v_imu),
        p_world=to_sympy(p_world),
        row_time=to_sympy(row_time),
        camera=to_sympy(sym.vector(*camera_sub_vars)),
        jacobian_method="first_order")

    def fs(thing) -> T.Union[sym.Expr, sym.MatrixExpr]:
        # We need the output expressions to reference the input arguments passed in
        # `camera`, so substitute those back in.
        camera_params = camera.to_vector()
        substitutions = list(zip(camera_sub_vars, camera_params))
        return from_sympy(thing).subs(substitutions)

    return (
        OutputArg(fs(values["p_image"].mat), name="p_image"),
        OutputArg(fs(values["D_world_R_imu"].mat), name="D_world_R_imu", is_optional=True),
        OutputArg(fs(values["D_world_t_imu"].mat), name="D_world_t_imu", is_optional=True),
        OutputArg(fs(values["D_imu_R_cam"].mat), name="D_imu_R_cam", is_optional=True),
        OutputArg(fs(values["D_imu_t_cam"].mat), name="D_imu_t_cam", is_optional=True),
        OutputArg(
            fs(values["D_angular_velocity_imu"].mat),
            name="D_angular_velocity_imu",
            is_optional=True),
        OutputArg(fs(values["D_world_v_imu"].mat), name="D_world_v_imu", is_optional=True),
        OutputArg(fs(values["D_p_world"].mat), name="D_p_world", is_optional=True),
    )


class CustomGenerator(CppGenerator):

    def format_custom_type(self, element: CustomType) -> str:
        if element.python_type == CameraParams:
            return "camera_params_t"
        else:
            return self.super_format(element)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        '--symforce',
        action='store_true',
        help='Include the SymForce first-order implementation (pretty slow)')
    args = parser.parse_args()

    output_dir = get_output_dir("rolling_shutter_camera") / "wf"
    generate_wrenfold_function(
        integrate_and_project,
        output_dir=output_dir,
        generator=CustomGenerator(),
    )

    if args.symforce:
        # Because of slow SymPy evaluation, we have to wait a while here.
        print('Generating integrate_and_project_sffo, this takes several minutes...')
        generate_wrenfold_function(
            integrate_and_project_sffo, output_dir=output_dir, generator=CustomGenerator())


if __name__ == "__main__":
    main()
