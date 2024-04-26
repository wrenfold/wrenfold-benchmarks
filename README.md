# wrenfold-benchmarks

This repository contains runtime benchmarks for wrenfold-generated functions. We compare to [SymForce](https://symforce.org) and some handwritten implementations. When considering these benchmarks, it is important to remember that **all** of the following factors can materially impact the results:
- Choice of compiler and compiler version.
- Selected CPU features (ie. AVX, SSE). For example, enabling `-march=native` can improve _or_ pessimize a given implementation.
- CPU architecture (ARM vs Intel).

As with all performance assessment, **your mileage may vary** and there is no perfect substitute for profiling in the context of your deployment environment.

## Notes

- The original python symbolic implementations can be found in the [scripts](/scripts) directory.
- SymForce outputs were last updated using version `0.9.0`.

## Building

Make sure you have cloned the requisite submodules:
```bash
git submodule update --init --recursive
```

To configure and run the benchmark suite:
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -Wno-deprecated
cmake --build .
./run_benchmarks
```

## Updating the generated functions

TODO: Fill out this section.
