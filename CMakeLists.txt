cmake_minimum_required (VERSION 3.0)

project (oglp)

configure_file (oglp-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/oglp-config.cmake)

install (DIRECTORY oglp DESTINATION include)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/oglp-config.cmake DESTINATION lib/cmake/oglp)
 