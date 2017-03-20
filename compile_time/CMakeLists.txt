add_library(pickup_base
  src/pickup_base.cc)
target_include_directories(pickup_base
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_library(more_pickups
  src/more_pickups.cc)
target_link_libraries(more_pickups
  PUBLIC
    pickup_base)
