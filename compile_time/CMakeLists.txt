add_library(compile_time_pickup_base
  src/pickup_base.cc)
target_include_directories(compile_time_pickup_base
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(
  TARGETS
    compile_time_pickup_base
  LIBRARY DESTINATION lib
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/pickups)
