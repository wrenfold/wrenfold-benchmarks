from pathlib import Path
import time

import symforce

symforce.set_epsilon_to_symbol()
symforce.set_symbolic_api("symengine")

from symforce import geo
from symforce import symbolic as sm
from symforce import typing as T
from symforce.codegen import Codegen, CodegenConfig, CppConfig


THIS_DIR = Path(__file__).parent.absolute()


def quat_interpolate(q0: geo.Rot3, q1: geo.Rot3, alpha: T.Scalar) -> geo.Rot3:
    w01 = geo.V3(q0.local_coordinates(q1, epsilon=1.0e-16))
    return q0.retract(w01 * alpha, epsilon=1.0e-16)


def main():
    config = CppConfig()
    start = time.time()
    cg = Codegen.function(func=quat_interpolate, config=config).with_jacobians(which_args=["q0", "q1"])
    cg.generate_function(output_dir=THIS_DIR, skip_directory_nesting=True)
    end = time.time()
    print(f'elapsed time: {end - start}')


if __name__ == '__main__':
    main()
