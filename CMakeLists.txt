cmake_minimum_required(VERSION 3.20)
project(
  wrenfold-benchmarks
  VERSION 0.1
  DESCRIPTION "Benchmark wrenfold, symforce, and handwritten methods."
  LANGUAGES CXX)

add_subdirectory(dependencies)

if(MSVC)
  set(WARNING_FLAGS /W4 /WX /wd4244 /wd4702)
else()
  set(WARNING_FLAGS -Wall -Wextra -pedantic -Werror -Wno-sign-compare)
endif()

add_executable(
  run_benchmarks
  benchmarks/quat_interpolation.cc benchmarks/matrix_mul.cc
  benchmarks/imu_integration.cc benchmarks/rolling_shutter_camera.cc)
target_link_libraries(run_benchmarks benchmark::benchmark_main eigen symforce
                      wrenfold_runtime)
target_compile_options(run_benchmarks PRIVATE ${WARNING_FLAGS})
target_compile_features(run_benchmarks PRIVATE cxx_std_17)
target_include_directories(run_benchmarks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  message(STATUS "Adding release mode optimization flags.")
  if(NOT MSVC)
    target_compile_options(run_benchmarks PRIVATE -O3)
  else()
    target_compile_options(run_benchmarks PRIVATE /fp:fast)
  endif()
endif()

target_compile_definitions(
  run_benchmarks PRIVATE -DSKYMARSHAL_PRINTING_ENABLED -DWF_SPAN_EIGEN_SUPPORT
                         -DNDEBUG)
