cmake_minimum_required(VERSION 3.20)
project(
  symforce-benchmarks
  VERSION 0.1
  DESCRIPTION "Benchmark symforce and wrenfold"
  LANGUAGES CXX)

add_subdirectory(dependencies)

include(functions.cmake)

add_benchmark(quat_interpolation.cc)
add_benchmark(imu_integration.cc)