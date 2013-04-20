/*
 * This file is part of oglp.
 *
 * oglp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * oglp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with oglp.  If not, see <http://www.gnu.org/licenses/>.
 */
/** @file */
#ifndef OGLP_H
#define OGLP_H

#include "common.h"
#include "buffer.h"
#include "framebuffer.h"
#include "renderbuffer.h"
#include "vertexarray.h"
#include "programpipeline.h"
#include "program.h"
#include "programresource.h"
#include "uniform.h"
#include "uniformblock.h"
#include "smartuniform.h"
#include "shader.h"
#include "sampler.h"
#include "texture.h"
#include "query.h"
#include "conditionalrender.h"
#include "transformfeedback.h"

namespace oglp {

/** \mainpage
 * \section intro_sec Introduction
 * \subsection About
 * OGLP is a free, open source and platform independent library, which
 * provides a C++ wrapper for OpenGL.
 * \subsection Goal
 * OGLP is NOT designed to be backward compatible, but to use modern
 * technologies. Thus there will be no wrappers for deprecated functions.
 * That means that OGLP is designed to be used with the OpenGL core
 * profile introduced with OpenGL 3.2.
 * Furthermore OGLP aimes to be as close to the underlying OpenGL API
 * as possible and to produce the least possible overhead.
 * \subsection Requirements
 * As OGLP is not designed to be backward compatible, but it depends on the
 * presence of modern technologies. Thus OpenGL 3.0+ is an requirement.
 * Some of the functionality of OGLP (e.g. the gl::Sampler class) also depends
 * on common OpenGL extensions  as for example GL_ARB_sampler_objects.
 * Any attempt to use such functionality, if respective extension is not supported
 * will result in a call of oglp::Unsupported which currently throws an exception.
 * Furthermore OGLP makes intensive use of the extension GL_EXT_direct_state_access.
 * If GL_EXT_direct_state_access is not available, oglp can fall back to wrapper
 * functions that provide the same functionality. This may or may not have negative
 * impacts on the performance.
 * Further dependencies include GLM, a C++ compiler (at least partially) 
 * supporting C++11 and a decent implementation of the C++ STL.
 * \subsection Installation
 * oglp does not need to be compiled. The library is mostly header-only,
 * so you just include the headers and use it. As some parts can't be
 * implemented only in header files, there is also a special header to
 * be included in one of your source files. See the Usage section for
 * more details.
 * \subsection Usage
 * Use \#include <oglp/oglp.h> in all source files in which you want to
 * use oglp.
 * Additionally in one source file of your project you must also use
 * \#include <oglp/oglp.cxx> to include the non-header parts of the code.
 * \subsection License
 * OGLP is licensed under the GPL.
 */

/**
 * Check for an extension.
 * Checks whether the specified OpenGL extension is supported.
 * \param name Specifies the name of the extension to check.
 * \return Whether the extension is supported.
 */
bool IsExtensionSupported (const std::string &name);

/** Initialize oglp.
 * Initializes oglp.
 * \param callback Callback to obtain OpenGL entry points.
 * \returns Whether oglp was initialized successfully.
 */
bool Init (GetProcAddressCallback callback);

} /* namespace oglp */

#ifndef OGLP_NO_NAMESPACE_ALIAS
namespace gl = oglp;
#endif

#endif /* !defined OGLP_H */
