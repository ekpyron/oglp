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
#ifndef GLP_UNIFORM_H
#define GLP_UNIFORM_H

#include "common.h"
#include <glm/glm.hpp>

namespace gl {

/**
 * An OpenGL uniform location object.
 * A wrapper class around an OpenGL uniform location.
 */
class Uniform
{
public:
	 /**
		* Default constructor.
		* Creates a new Uniform object.
		*/
	 Uniform (void);
	 /**
		* Copy constuctor.
		* Copies the internal uniform location to another Uniform object.
		*/
	 Uniform (const Uniform &obj);
	 /**
		* A destructor.
		* Deletes a Uniform object.
		*/
	 ~Uniform (void);
	 /**
		* Copy assignment.
		* Copies the internal uniform location to another Uniform object.
		*/
	 Uniform &operator= (const Uniform &obj);
	 /**
		* Assign a value.
		* Assigns a float value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 GLfloat operator= (GLfloat v);
	 /**
		* Assign a value.
		* Assigns a glm::vec2 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::vec2 &operator= (const glm::vec2 &v);
	 /**
		* Assign a value.
		* Assigns a glm::vec3 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::vec3 &operator= (const glm::vec3 &v);
	 /**
		* Assign a value.
		* Assigns a glm::vec4 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::vec4 &operator= (const glm::vec4 &v);
	 /**
		* Assign a value.
		* Assigns an int value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 GLint operator= (GLint v);
	 /**
		* Assign a value.
		* Assigns a glm::ivec2 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::ivec2 &operator= (const glm::ivec2 &v);
	 /**
		* Assign a value.
		* Assigns a glm::ivec3 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::ivec3 &operator= (const glm::ivec3 &v);
	 /**
		* Assign a value.
		* Assigns a glm::ivec4 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::ivec4 &operator= (const glm::ivec4 &v);
	 /**
		* Assign a value.
		* Assigns an unsigned int value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 GLuint operator= (GLuint v);
	 /**
		* Assign a value.
		* Assigns a glm::uvec2 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::uvec2 &operator= (const glm::uvec2 &v);
	 /**
		* Assign a value.
		* Assigns a glm::uvec3 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::uvec3 &operator= (const glm::uvec3 &v);
	 /**
		* Assign a value.
		* Assigns a glm::uvec4 value to the uniform location.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const glm::uvec4 &operator= (const glm::uvec4 &v);
	 /**
		* Assign a value.
		* Assigns a glm::mat2 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat2 &operator= (const glm::mat2 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat3 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat3 &operator= (const glm::mat3 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat4 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat4 &operator= (const glm::mat4 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat2x3 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat2x3 &operator= (const glm::mat2x3 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat3x2 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat3x2 &operator= (const glm::mat3x2 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat2x4 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat2x4 &operator= (const glm::mat2x4 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat4x2 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat4x2 &operator= (const glm::mat4x2 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat3x4 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat3x4 &operator= (const glm::mat3x4 &m);
	 /**
		* Assign a value.
		* Assigns a glm::mat4x3 value to the uniform location.
		* \param m value to assign
		* \return a reference to the assigned value
		*/
	 const glm::mat4x3 &operator= (const glm::mat4x3 &m);
	 /**
		* Checks whether the uniform is valid.
		* \return Whether the uniform is valid.
		*/
	 operator bool (void);
private:
	 /**
		* Private constructor.
		* Creates a Uniform object using the specified internal parameters.
		* \param program the internal OpenGL shader program to use
		* \param location the internal OpenGL uniform location to use
		*/
	 Uniform (GLuint program, GLuint location);
	 /**
		* The internal OpenGL program name containing the Uniform.
		*/
	 GLuint program;
	 /**
		* The internal OpenGL uniform location of the uniform variable.
		*/
	 GLuint location;
	 friend class Program;
};

} /* namespace gl */

#endif /* !defined GLP_UNIFORM_H */
