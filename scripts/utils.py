"""Shared utilities."""
import pathlib
import timeit
import typing as T


def get_output_dir(name: str) -> pathlib.Path:
    return pathlib.Path(__file__).parent.parent.absolute() / "generated" / name


def time_operation(func: T.Callable, runs: int):
    time = timeit.timeit("func()", number=runs, globals=dict(func=func))
    print(f"Time for {func.__name__}: {time / runs} seconds/run")
