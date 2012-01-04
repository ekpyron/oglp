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
#ifndef OGLP_COMMON_H
#define OGLP_COMMON_H

#include "config.h"
#include <glm/glm.hpp>
#include "gl3w.h"
#include "exception.h"

namespace gl {

/**
 * Check for an OpenGL error.
 * Checks for an OpenGL error and throws an Exception if one occurred.
 */
void CheckError (void);

} /* namespace gl */

#endif /* !defined OGLP_COMMON_H */
