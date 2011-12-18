/*
 * This file is part of glcp.
 *
 * glcp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glcp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glcp.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLCP_H
#define GLCP_H

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

namespace gl {

/**
 * Initialize glcp.
 * Initializes glcp.
 * \param callback Callback to obtain OpenGL entry points.
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

#endif /* !defined GLCP_H */
