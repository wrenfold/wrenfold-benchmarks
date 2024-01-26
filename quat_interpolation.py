from pathlib import Path
import time

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


THIS_DIR = Path(__file__).parent.absolute()


def quat_interpolate(
    q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar, jacobian_method: str
) -> Values:
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
    result = Values(
        q_out=geo.V4.from_storage(out.to_storage()), D0=geo.M33(D0), D1=geo.M33(D1)
    )
    return result


def quat_interpolate_chain(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
    return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="chain")


def quat_interpolate_first_order(q0_xyzw: geo.V4, q1_xyzw: geo.V4, alpha: T.Scalar):
    return quat_interpolate(q0_xyzw, q1_xyzw, alpha, jacobian_method="first_order")


def main():
    start = time.time()
    config = CppConfig()

    inputs = symbolic_inputs(quat_interpolate_chain)
    cg = Codegen(
        inputs,
        outputs=quat_interpolate_chain(**inputs),
        config=config,
        name="quat_interpolate_chain",
        return_key=None,
    )
    cg.generate_function(
        output_dir=THIS_DIR / "output" / "quat_interpolation",
        skip_directory_nesting=True,
    )

    inputs = symbolic_inputs(quat_interpolate_first_order)
    cg = Codegen(
        inputs,
        outputs=quat_interpolate(**inputs, jacobian_method="first_order"),
        config=config,
        name="quat_interpolate_first_order",
        return_key=None,
    )
    cg.generate_function(
        output_dir=THIS_DIR / "output" / "quat_interpolation",
        skip_directory_nesting=True,
    )

    end = time.time()
    print(f"Elapsed time: {end - start}")


if __name__ == "__main__":
    main()
