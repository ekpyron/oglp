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
		*             Must be one of the following:
		*             - GL_VERTEX_SHADER
		*             - GL_FRAGMENT_SHADER
		*/
	 Shader (GLenum type);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader object to
		* another Shader object.
		* \param s Shader object to move.
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
		* \param s Shader object to move.
		* \return A reference to the Shader object.
		*/
	 Shader &operator= (Shader &&s);
	 /**
		* Deleted copy assignment.
		* A Shader object can't be copy assigned.
		* \return
		*/
	 Shader &operator= (const Shader&) = delete;
	 /**
		* Create a Shader.
		* Creates the internal OpenGL shader object.
		* \param type Specifies the type of shader to be created.
		*             Must be one of the following:
		*             - GL_VERTEX_SHADER
		*             - GL_FRAGMENT_SHADER
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
		* \return Whether the shader object was compiled successfully.
		*/
	 bool Compile (void) const;
	 /**
		* Get the info log.
		* Obtain the info log of the internal OpenGL shader object.
		* \return The info log of the internal OpenGL shader object.
		*/
	 std::string GetInfoLog (void) const;
	 /**
		* Return internal object.
		* Returns the internal OpenGL shader object. Use with caution.
		* \return The internal OpenGL shader object.
		*/
	 GLuint get (void) const;
   /**
		* Swap internal object.
		* Swaps the internal OpenGL shader object with another gl::Shader.
		* \param sampler Object with which to swap the internal shader object.
		*/
	 void swap (Shader &shader);
private:
	 /**
		* internal OpenGL shader object
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined SHADER_H */
