
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