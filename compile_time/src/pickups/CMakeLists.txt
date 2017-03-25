macro(ADD_PICKUP _PICKUP_NAME)
  add_library(compile_time_pickup_${_PICKUP_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/${_PICKUP_NAME}.cc)
  target_link_libraries(compile_time_pickup_${_PICKUP_NAME}
    PUBLIC
      compile_time_pickup_base)
  install(
    TARGETS
      compile_time_pickup_${_PICKUP_NAME}
    LIBRARY DESTINATION lib
  )
  get_property(AVAILABLE_PLUGINS GLOBAL PROPERTY _AVAILABLE_PLUGINS)
  set(_AVAILABLE_PLUGINS ${_AVAILABLE_PLUGINS} compile_time_pickup_${_PICKUP_NAME})
  set_property(GLOBAL PROPERTY AVAILABLE_PLUGINS ${_AVAILABLE_PLUGINS})
endmacro()

ADD_PICKUP(health)
ADD_PICKUP(lightning)
ADD_PICKUP(oil)
