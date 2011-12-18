# Copyright (c) 2011 Daniel Kirchner
#
# This file is part of glcp.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
#
include (UseDoxygen OPTIONAL)
find_package (GLM REQUIRED)
include_directories (include ${GLM_INCLUDE_DIR})

file (GLOB GLCP_SOURCES *.cpp gl3w/*.cpp)

add_library (glcp STATIC ${GLCP_SOURCES})

set_property (TARGET glcp PROPERTY COMPILE_FLAGS -std=c++0x)

set_target_properties (glcp PROPERTIES
		       	   PUBLIC_HEADER "include/glcp.h;include/buffer.h;include/framebuffer.h;include/renderbuffer.h;include/vertexarray.h;include/uniform.h;include/sampler.h;include/texture.h;include/common.h;include/config.h;include/programpipeline.h;include/program.h;include/shader.h;include/gl3w.h;include/gl3.h;include/gl3ext.h;include/exception.h")

install (TARGETS glcp ARCHIVE DESTINATION lib
		     RUNTIME DESTINATION bin
		     LIBRARY DESTINATION lib
		     PUBLIC_HEADER DESTINATION include/glcp)
