# Google benchmark
function(add_google_benchmark)
  set(BENCHMARK_ENABLE_TESTING
      OFF
      CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_INSTALL
      OFF
      CACHE BOOL "" FORCE)
  if(MSVC)
    # Turn off warning about failure to specify /EHs
    add_compile_options(/wd4530)
  endif()
  add_subdirectory(benchmark)
endfunction()
add_google_benchmark()

# Create a target for eigen.
function(add_eigen)
  set(EIGEN_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/eigen")
  if(NOT TARGET eigen)
    add_library(eigen INTERFACE IMPORTED GLOBAL)
    set_target_properties(eigen PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                           "${EIGEN_INCLUDE_DIRS}")
  endif()
endfunction()
add_eigen()

# Create an interface library so we can import a couple of symforce types.
function(add_symforce_lib)
  add_library(symforce INTERFACE)
  target_include_directories(
    symforce
    INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/symforce/third_party/skymarshal/include>
      $<INSTALL_INTERFACE:include>)
  target_include_directories(
    symforce
    INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/symforce/third_party/eigen_lcm/lcmtypes/eigen_lcm_lcm/cpp>
      $<INSTALL_INTERFACE:include>)
endfunction()
add_symforce_lib()

# Create an interface library for the wrenfold runtime headers
function(add_wrenfold_headers)
  add_library(wrenfold_runtime INTERFACE)
  target_include_directories(
    wrenfold_runtime INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/wrenfold>
                               $<INSTALL_INTERFACE:include>)
endfunction()
add_wrenfold_headers()
