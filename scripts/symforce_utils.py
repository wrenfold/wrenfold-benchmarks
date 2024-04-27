import timeit

from symforce import typing as T
from symforce.codegen import Codegen, CppConfig
from symforce.type_helpers import symbolic_inputs


def generate_symforce_function(func: T.Callable, output_dir: T.Optional[T.Openable] = None):
    """
    Generate a function using symforce.
    """
    def gen():
        inputs = symbolic_inputs(func)
        cg = Codegen(
            inputs,
            outputs=func(**inputs),
            config=CppConfig(),
            name=func.__name__,
            return_key=None,
        )
        cg.generate_function(
            output_dir=output_dir,
            skip_directory_nesting=True,
        )

    duration = timeit.timeit("gen()", number=1, globals=dict(gen=gen))
    print(f"SymForce generation time for {func.__name__}: {duration}s")
