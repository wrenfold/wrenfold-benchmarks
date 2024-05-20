"""
Generate quaternion interpolation with derivatives using symforce.
"""
import symforce
symforce.set_symbolic_api("symengine")
symforce.set_epsilon_to_symbol()

from symforce import geo
from symforce import typing as T

from utils import get_output_dir
from symforce_utils import generate_symforce_function

from quat_expressions_sf import quat_interpolate, quat_local_coordinates



def quat_interpolate_chain(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
    return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="chain")


def quat_interpolate_first_order(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
    return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="first_order")


def quat_local_coordinates_first_order(q0_xyzw: geo.V4, q1_xyzw: geo.V4):
    return quat_local_coordinates(q0_xyzw, q1_xyzw, jacobian_method="first_order")


def quat_local_coordinates_chain(q0_xyzw: geo.V4, q1_xyzw: geo.V4):
    return quat_local_coordinates(q0_xyzw, q1_xyzw, jacobian_method="chain")


def main():
    output_dir = get_output_dir("quat_interpolation") / "sf"
    generate_symforce_function(quat_interpolate_chain, output_dir)
    generate_symforce_function(quat_interpolate_first_order, output_dir)
    generate_symforce_function(quat_local_coordinates_chain, output_dir)
    generate_symforce_function(quat_local_coordinates_first_order, output_dir)


if __name__ == "__main__":
    main()
