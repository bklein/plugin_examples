add_library(compile_time_pickup_base
  src/pickup_base.cc)
target_include_directories(compile_time_pickup_base
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_library(compile_time_pickups
  src/pickups.cc)
target_link_libraries(compile_time_pickups
  PUBLIC
    compile_time_pickup_base)

install(
  TARGETS
    compile_time_pickup_base
    compile_time_pickups
  LIBRARY DESTINATION lib
)
