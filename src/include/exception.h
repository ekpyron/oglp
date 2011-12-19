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
#ifndef OGLP_EXCEPTION_H
#define OGLP_EXCEPTION_H

#include "common.h"
#include <exception>

namespace gl {

/**
 * Exception class.
 * Wrapper for OpenGL errors.
 */
class Exception : public std::exception
{
public:
	 /**
		* Constructor.
		* \param err Specifies the OpenGL error code
		*/
	 Exception (GLenum err);
	 /**
		* Format the reason for the exception.
		* \return A string describing the exception.
		*/
	 virtual const char *what (void) const throw ();
private:
	 /**
		* stores the OpenGL error code
		*/
	 GLenum error;
};

} /* namespace gl */

#endif /* !defined OGLP_EXCEPTION_H */
