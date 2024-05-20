import timeit
import typing as T
from pathlib import Path


def generate_symforce_function(func: T.Callable, output_dir: T.Optional[Path] = None):
    """
    Generate a function using symforce.
    """
    # Local imports to workaround symforce global init.
    from symforce.codegen import Codegen, CppConfig
    from symforce.type_helpers import symbolic_inputs

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


def coerce_sympy_matrix(mat):
    """
    Symforce operands don't like mixing sympy matrices and symforce matrices. Covnert a sympy
    matrix to a symforce matrix.
    """
    from symforce.geo import Matrix
    if isinstance(mat, Matrix):
        return mat
    return Matrix(mat.tolist())


# Hack we need to deal with the global epsilon.
INITIALIZED_SYMFORCE = False


def configure_symforce():
    global INITIALIZED_SYMFORCE
    if not INITIALIZED_SYMFORCE:
        import symforce
        symforce.set_symbolic_api("sympy")
        symforce.set_epsilon_to_symbol()
        INITIALIZED_SYMFORCE = True
