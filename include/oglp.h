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
#include "uniform.h"
#include "shader.h"
#include "sampler.h"
#include "texture.h"
#include "query.h"

namespace gl {

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
 * As OGLP is not designed to be backward compatible, it depends on the
 * presence of modern technologies. Thus OpenGL 3.3+ is an requirement, 
 * as well as some common extensions namely GL_EXT_direct_state_access,
 * GL_ARB_separable_shader_objects and GL_ARB_sampler_objects.
 * The former is well supported by established graphics card manufactors
 * and the latter is in core OpenGL 4.
 * Build dependencies include GLM, cmake and a C++ compiler supporting C++11.
 * \subsection License
 * OGLP is licensed under the GPL.
 */

/**
 * @brief Initialize oglp.
 * @param callback Callback to obtain OpenGL entry points.
 *
 * Initializes oglp.
 */
void Init (GetProcAddressCallback callback);

/**
 * Check for an extension.
 * Checks whether the specified OpenGL extension is supported.
 * \param name Specifies the name of the extension to check.
 * \return Whether the extension is supported.
 */
bool IsExtensionSupported (const std::string &name);

} /* namespace gl */

#endif /* !defined OGLP_H */
