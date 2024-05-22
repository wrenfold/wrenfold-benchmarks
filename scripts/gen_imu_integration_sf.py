"""
Generate IMU integration logic using symforce.
"""
import symforce

symforce.set_epsilon_to_symbol()
symforce.set_symbolic_api("symengine")

from symforce import typing as T
from symforce.codegen import Codegen, CppConfig
from symforce.type_helpers import symbolic_inputs

from utils import get_output_dir

from imu_integration_expressions_sf import integrate_imu_chain, integrate_imu_first_order


def generate_integrate_imu(output_dir: T.Optional[T.Openable] = None):
    inputs = symbolic_inputs(integrate_imu_chain)
    cg = Codegen(
        inputs,
        outputs=integrate_imu_chain(**inputs),
        config=CppConfig(),
        name="integrate_imu_chain",
        return_key=None,
    )
    cg.generate_function(output_dir=output_dir, skip_directory_nesting=True)


def generate_integrate_imu_first_order(output_dir: T.Optional[T.Openable] = None):
    inputs = symbolic_inputs(integrate_imu_first_order)
    cg = Codegen(
        inputs,
        outputs=integrate_imu_first_order(**inputs),
        config=CppConfig(),
        name="integrate_imu_first_order",
        return_key=None,
    )
    cg.generate_function(output_dir=output_dir, skip_directory_nesting=True)


def main():
    output_dir = get_output_dir("imu_integration") / "sf"
    generate_integrate_imu(output_dir)
    generate_integrate_imu_first_order(output_dir)


if __name__ == "__main__":
    main()
