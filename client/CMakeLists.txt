add_executable(ls_compile_time_pickups
  ls_compile_time_pickups.cc)
target_link_libraries(ls_compile_time_pickups
  PRIVATE
    compile_time_pickup_base
)

get_property(AVAILABLE_PLUGINS GLOBAL PROPERTY AVAILABLE_PLUGINS)
message(STATUS "Found pickups:")
foreach(PLUGIN ${AVAILABLE_PLUGINS})
  message(STATUS "  ${PLUGIN}")
  target_link_libraries(ls_compile_time_pickups
    PRIVATE
      ${PLUGIN}
  )
endforeach()

install(TARGETS ls_compile_time_pickups
  RUNTIME DESTINATION bin)
