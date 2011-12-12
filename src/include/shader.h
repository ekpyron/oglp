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
#ifndef SHADER_H
#define SHADER_H

#include "common.h"
#include <string>

namespace gl {

/** OpenGL shader object.
 * A wrapper class around an OpenGL shader object.
 */
class Shader
{
public:
	 /**
		* Default constructor.
		* Creates a new Shader object.
		*/
	 Shader (void);
	 /**
		* Constructor.
		* Creates a new Shader object and an internal OpenGL shader object.
		* \param type Specifies the type of shader to be created.
		*             Must be either GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
		*/
	 Shader (GLenum type);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader object to
		* another Shader object.
		*/
	 Shader (Shader &&s);
	 /**
		* A destructor.
		* Deletes a Shader object.
		*/
	 ~Shader (void);
	 /**
		* Deleted copy assignment.
		* A Shader object can't be copy assigned.
		*/
	 Shader (const Shader&) = delete;
	 /**
		* Move assignment.
		* Passes the internal OpenGL shader object to another
		* Shader object.
		*/
	 Shader &operator= (Shader&&);
	 /**
		* Deleted copy assignment.
		* A Shader object can't be copy assigned.
		*/
	 Shader &operator= (const Shader&) = delete;
	 /**
		* Create a Shader.
		* Creates the internal OpenGL shader object.
		* \param type Specifies the type of shader to be created.
		*             Must be either GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
		*/
	 void Create (GLenum type);
	 /**
		* Specify source.
		* Replaces the source code in the internal OpenGL shader object.
		* \param source Specifies the source.
		*/
	 void Source (const std::string &source) const;
	 /**
		* Compile the shader object.
		* Compiles the internal OpenGL shader object.
		*/
	 bool Compile (void) const;
	 /**
		* Get the info log.
		* Obtain the info log of the internal OpenGL shader object.
		*/
	 std::string GetInfoLog (void) const;
private:
	 /**
		* internal OpenGL shader object
		*/
	 GLuint obj;
	 friend class Program;
};

} /* namespace gl */

#endif /* !defined SHADER_H */
