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
#ifdef _WIN32
#include <windows.h>
#endif
#include <glm/glm.hpp>
#include "glcorew.h"
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

#ifdef OGLP_ERROR_CALLBACK
/** Error callback.
 * Callback that receives error codes and messages.
 * \param err OpenGL error code. If the error was not an OpenGL error
 *            this is set to GL_NO_ERROR.
 * \param msg A human readable error message.
 * \param userdata The user pointer as specified with SetErrorCallback.
 */
typedef void (*ErrorCallback) (GLenum err, const char *msg, void *userdata);
namespace internal {
extern ErrorCallback errorcallback;
extern void *errorcallback_userdata;
} /* namespace internal */

/** Set error callback.
 * Specifies an error callback that is called, if an OpenGL error is
 * detected.
 * \param cb The error callback to use.
 * \param userdata A user pointer that is passed on to the error callback.
 */
inline void SetErrorCallback (ErrorCallback cb, void *userdata) {
	internal::errorcallback = cb;
	internal::errorcallback_userdata = userdata;
}
#endif

/**
 * Check for an OpenGL error.
 * Checks for an OpenGL error and calls the error callback or
 * throws an Exception if one occurred, depending on whether
 * OGLP_ERROR_CALLBACK is defined and a callback was set with
 * SetErrorCallback or OGLP_THROW_EXCEPTIONS is defined.
 */
inline void CheckError (void) {
	GLenum err;
	err = GetError ();
#ifdef OGLP_ERROR_CALLBACK
	if (err != GL_NO_ERROR && internal::errorcallback)
		 internal::errorcallback (err, ErrorToString (err),
															internal::errorcallback_userdata);
#endif
#ifdef OGLP_THROW_EXCEPTIONS
	if (err != GL_NO_ERROR)
		throw Exception (err);
#endif
}

} /* namespace oglp */

#endif /* !defined OGLP_COMMON_H */
