if(MSVC)
  set(WARNING_FLAGS /W4 /WX /wd4244 /wd4702)
else()
  set(WARNING_FLAGS -Wall -Wextra -pedantic -Werror -Wno-sign-compare)
endif()

function(add_compilation_options TARGET_NAME)
  target_link_libraries(${TARGET_NAME} benchmark::benchmark eigen symforce wf_runtime)
  target_compile_options(${TARGET_NAME} PRIVATE ${WARNING_FLAGS} -O3)
  target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
  target_compile_definitions(${TARGET_NAME} PRIVATE -DSKYMARSHAL_PRINTING_ENABLED -DMATH_SPAN_EIGEN_SUPPORT -DNDEBUG)
  target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/output")
endfunction()

function(add_benchmark SOURCE_FILE)
  # get just the filename w/o extension
  get_filename_component(BENCH_NAME ${SOURCE_FILE} NAME_WE)

  # add test executable for every file
  message(STATUS "Adding benchmark: ${BENCH_NAME}")
  add_executable(${BENCH_NAME} ${SOURCE_FILE})
  add_compilation_options(${BENCH_NAME})

  add_executable(${BENCH_NAME}_native ${SOURCE_FILE})
  add_compilation_options(${BENCH_NAME}_native)
  target_compile_options(${BENCH_NAME}_native PRIVATE "-march=native")
endfunction()
