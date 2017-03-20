add_executable(use_pickups
  main.cc)
target_link_libraries(use_pickups
  PRIVATE
    pickup_base
    more_pickups
)
