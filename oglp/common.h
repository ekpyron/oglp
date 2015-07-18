/*
 * Copyright 2015 Daniel Kirchner
 *
 * This file is part of midium.
 *
 * midium is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * midium is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with midium.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OGLP_COMMON_H
#define OGLP_COMMON_H

#include "config.h"

#ifdef _WIN32
#include <windows.h>
#endif
#ifdef OGLP_USE_CXX11
#include <functional>
#endif

#include "glcorew.h"
#include <glm/glm.hpp>
#include <sstream>

#ifdef OGLP_THROW_EXCEPTIONS
#include <stdexcept>
#include "exception.h"
#endif

/** oglp namespace.
 * This namespace contains all oglp functions and data.
 * Unless OGLP_NO_NAMESPACE_ALIAS is specified the
 * namespace gl will be defined as an alias of oglp.
 */
namespace oglp {

/** Convert error code to string.
 * Converts an OpenGL error code to a human readable string.
 * If error is no valid error code, "unknown" is returned.
 * \param error The OpenGL error code to convert.
 * \returns The human readable error string.
 */
const char *ErrorToString (GLenum error);

/**
 * Check for an OpenGL error.
 * If OGLP_THROW_EXCEPTIONS is defined, this checks for an
 * OpenGL error and throws an Exception if one occurred,
 * otherwise it does nothing.
 */
inline void CheckError (void)
{
#ifdef OGLP_THROW_EXCEPTIONS
	GLenum err;
	err = GetError ();
	if (err != GL_NO_ERROR)
		throw Exception (err);
#endif
}

} /* namespace oglp */

#endif /* !defined OGLP_COMMON_H */
