/*
 * This file is part of glp.
 *
 * glp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glp.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GLP_H
#define GLP_H

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
 * Initialize glp.
 * Initializes glp.
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

#endif /* !defined GLP_H */
