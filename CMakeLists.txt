cmake_minimum_required (VERSION 3.0)

project (oglp)

configure_file (oglp-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/oglp-config.cmake @ONLY)

add_library (oglp STATIC src/glcorew.cpp src/oglp.cpp)
target_include_directories (oglp PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)

set_property (TARGET oglp PROPERTY COMPILE_FLAGS -std=c++14)

install (TARGETS oglp EXPORT oglp ARCHIVE DESTINATION lib)
install (DIRECTORY oglp DESTINATION include)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/oglp-config.cmake DESTINATION lib/cmake/oglp)
