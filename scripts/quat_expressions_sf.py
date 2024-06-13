"""Quaternion interpolation expressions in symforce."""
from symforce import geo
from symforce import typing as T
from symforce.jacobian_helpers import (
    tangent_jacobians_chain_rule,
    tangent_jacobians_first_order,
)
from symforce.values import Values


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
        D0, = tangent_jacobians_chain_rule(expr=out, args=[q0])
        D1, = tangent_jacobians_chain_rule(expr=out, args=[q1])
    elif jacobian_method == "first_order":
        D0, = tangent_jacobians_first_order(expr=out, args=[q0])
        D1, = tangent_jacobians_first_order(expr=out, args=[q1])
    else:
        raise RuntimeError(f"Invalid arg: {jacobian_method}")

    return Values(q_out=geo.V4.from_storage(out.to_storage()), D0=geo.M33(D0), D1=geo.M33(D1))


def quat_local_coordinates(q0_xyzw: geo.V4, q1_xyzw: geo.V4, jacobian_method: str):
    """
    Compute local_coordinates between two quaternions.
    """
    q0 = geo.Rot3.from_storage(q0_xyzw)
    q1 = geo.Rot3.from_storage(q1_xyzw)
    out = geo.V3(q0.local_coordinates(q1, epsilon=1.0e-16))

    if jacobian_method == "chain":
        D0, = tangent_jacobians_chain_rule(expr=out, args=[q0])
        D1, = tangent_jacobians_chain_rule(expr=out, args=[q1])
    elif jacobian_method == "first_order":
        D0, = tangent_jacobians_first_order(expr=out, args=[q0])
        D1, = tangent_jacobians_first_order(expr=out, args=[q1])
    else:
        raise RuntimeError(f"Invalid arg: {jacobian_method}")

    return Values(out=out, D0=geo.M33(D0), D1=geo.M33(D1))
