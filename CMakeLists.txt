cmake_minimum_required(VERSION 3.0)

project(plugin_examples CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weverything")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-exit-time-destructors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-global-constructors")

option(BUILD_SHARED_LIBS "Shared libs" ON)

add_library(pickup_base
  pickup_base.cc)

add_library(more_pickups
  more_pickups.cc)
target_link_libraries(more_pickups
  PUBLIC
    pickup_base)

add_executable(use_pickups
  main.cc)
target_link_libraries(use_pickups
  PRIVATE
    pickup_base
    more_pickups
)
