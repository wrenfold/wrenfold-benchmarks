"""
Generate quaternion interpolation with derivatives using symforce.
"""
import argparse

import symforce

symforce.set_epsilon_to_symbol()
symforce.set_symbolic_api("symengine")

from symforce import geo
from symforce import typing as T
from symforce.codegen import Codegen, CppConfig
from symforce.jacobian_helpers import (
    tangent_jacobians_chain_rule,
    tangent_jacobians_first_order,
)
from symforce.values import Values
from symforce.type_helpers import symbolic_inputs

from utils import get_output_dir, time_operation


def quat_interpolate(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar,
                     jacobian_method: str) -> Values:
    """
    Interpolate between two quaternions in the tangent space.
    
    Generate derivatives as well wrt both quaternions.
    """
    q0 = geo.Rot3.from_storage(q0_xyzw)
    q1 = geo.Rot3.from_storage(q1_xyzw)
    w01 = geo.V3(q0.local_coordinates(q1, epsilon=1.0e-16))
    out = q0.retract(w01 * alpha, epsilon=1.0e-16)
    if jacobian_method == "chain":
        D0 = tangent_jacobians_chain_rule(expr=out, args=[q0])[0]
        D1 = tangent_jacobians_chain_rule(expr=out, args=[q1])[0]
    elif jacobian_method == "first_order":
        D0 = tangent_jacobians_first_order(expr=out, args=[q0])[0]
        D1 = tangent_jacobians_first_order(expr=out, args=[q1])[0]
    else:
        raise RuntimeError(f"Invalid arg: {jacobian_method}")
    result = Values(q_out=geo.V4.from_storage(out.to_storage()), D0=geo.M33(D0), D1=geo.M33(D1))
    return result


def generate_quat_interpolate_chain(output_dir: T.Optional[T.Openable] = None):
    def quat_interpolate_chain(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
        return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="chain")
    
    inputs = symbolic_inputs(quat_interpolate_chain)
    cg = Codegen(
        inputs,
        outputs=quat_interpolate_chain(**inputs),
        config=CppConfig(),
        name="quat_interpolate_chain",
        return_key=None,
    )
    cg.generate_function(
        output_dir=output_dir,
        skip_directory_nesting=True,
    )


def generate_quat_interpolate_first_order(output_dir: T.Optional[T.Openable] = None):
    def quat_interpolate_first_order(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
        return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="first_order")
    
    inputs = symbolic_inputs(quat_interpolate_first_order)
    cg = Codegen(
        inputs,
        outputs=quat_interpolate_first_order(**inputs),
        config=CppConfig(),
        name="quat_interpolate_first_order",
        return_key=None,
    )
    cg.generate_function(
        output_dir=output_dir,
        skip_directory_nesting=True,
    )


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument('--profile', type=int, default=None)
    args = parser.parse_args()

    if args.profile is None:
        output_dir = get_output_dir("quat_interpolation")
        generate_quat_interpolate_chain(output_dir)
        generate_quat_interpolate_first_order(output_dir)
    else:
        time_operation(func=generate_quat_interpolate_chain, runs=args.profile)
        time_operation(func=generate_quat_interpolate_first_order, runs=args.profile)


if __name__ == "__main__":
    main()
