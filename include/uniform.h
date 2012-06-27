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
#ifndef OGLP_UNIFORM_H
#define OGLP_UNIFORM_H

#include "common.h"
#include <vector>
#include <array>

namespace gl {

/**
 * OpenGL uniform location object.
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
		* \param obj Uniform object to copy.
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
		* \param obj Uniform object to copy.
		* \return A reference to the Uniform object.
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
		* Assign an array of values.
		* Assigns an array of float values to the uniform location.
		* \param v array of values to assign
		* \return a reference to the assigned array of values
		*/
	 template<size_t N>
	 const std::array<GLfloat, N> &operator= (const std::array<GLfloat, N> &v) {
		 Set (v.data (), N);
		 return v;
	 }
	 /**
		* Assign an array of values.
		* Assigns an array of float values to the uniform location.
		* \param v array of values to assign
		* \param N number of values in the array
		*/
	 void Set (GLfloat *v, size_t N);
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
	 /**
		* Get a value.
		* Returns the value of the uniform variable.
		* \param params Returns the value of the uniform variable.
		*/
	 void Get (GLfloat *params);
	 /**
		* Get a value.
		* Returns the value of the uniform variable.
		* \param params Returns the value of the uniform variable.
		*/
	 void Get (GLint *params);
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

#endif /* !defined OGLP_UNIFORM_H */
