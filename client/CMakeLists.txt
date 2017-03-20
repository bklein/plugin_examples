add_executable(ls_compile_time_pickups
  ls_compile_time_pickups.cc)
target_link_libraries(ls_compile_time_pickups
  PRIVATE
    compile_time_pickup_base
    compile_time_pickups
)

install(TARGETS ls_compile_time_pickups
  RUNTIME DESTINATION bin)
