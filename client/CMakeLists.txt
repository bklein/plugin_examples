add_executable(ls_compile_time_pickups
  ls_compile_time_pickups.cc)
target_link_libraries(ls_compile_time_pickups
  PRIVATE
    compile_time_pickup_base
)

get_property(AVAILABLE_PICKUPS GLOBAL PROPERTY AVAILABLE_PICKUPS)
message(STATUS "Found pickups:")
foreach(PICKUP ${AVAILABLE_PICKUPS})
  message(STATUS "  ${PICKUP}")
  target_link_libraries(ls_compile_time_pickups
    PRIVATE
      ${PICKUP}
  )
endforeach()

install(TARGETS ls_compile_time_pickups
  RUNTIME DESTINATION bin)
