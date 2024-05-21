"""Shared utilities."""

import pathlib
import timeit
import typing as T

from wrenfold import code_generation


def get_output_dir(name: str) -> pathlib.Path:
    return pathlib.Path(__file__).parent.parent.absolute() / "generated" / name


def generate_wrenfold_function(
    func: T.Callable,
    output_dir: T.Optional[pathlib.Path] = None,
    params: T.Optional[code_generation.OptimizationParams] = None,
    generator: T.Optional[code_generation.CppGenerator] = None,
):
    """
    Generate a function using wrenfold.
    """
    if generator is None:
        generator = code_generation.CppGenerator()

    def gen():
        code = code_generation.generate_function(
            func=func, generator=generator, optimization_params=params
        )
        code = code_generation.CppGenerator.apply_preamble(code, namespace="gen")
        if output_dir is not None:
            code_generation.mkdir_and_write_file(
                code=code, path=output_dir / f"{func.__name__}.h"
            )

    duration = timeit.timeit("gen()", number=1, globals=dict(gen=gen))
    print(f"wrenfold generation time for {func.__name__}: {duration}s")
