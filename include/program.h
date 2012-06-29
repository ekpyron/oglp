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
#ifndef PROGRAM_H
#define PROGRAM_H

#include "common.h"
#include "uniform.h"
#include "shader.h"
#include <string>
#include <vector>

namespace gl {

/** OpenGL shader program object.
 * A wrapper class around an OpenGL shader program.
 */
class Program
{
public:
	 /**
		* Default constructor.
		* Creates a new Program object.
		*/
	 Program (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader program object to
		* another Program object.
		* \param p The Program object to move.
		*/
	 Program (Program &&p);
	 /**
		* A destructor.
		* Deletes a Program object.
		*/
	 ~Program (void);
	 /**
		* Deleted copy assignment.
		* A Program object can't be copy assigned.
		*/
	 Program (const Program&) = delete;
	 /**
		* Move assignment.
		* Passes the internal OpenGL shader program object to another
		* Program object.
		* \param p The Program object to move.
		* \return A reference to the program object.
		*/
	 Program &operator= (Program &&p);
	 /**
		* Deleted copy assignment.
		* A Program object can't be copy assigned.
		* \return
		*/
	 Program &operator= (const Program&) = delete;
	 /**
		* Create a Program from source.
		* Creates a stand-alone Program from a source string.
		* \param type Specifies the type of shader to create.
		* \param source Specifies the source to compile the program from.
		* \return Whether the Program was successfully created.
		*/
	 bool Create (GLenum type, const std::string &source);
	 /**
		* Specify a parameter.
		* Specify a parameter for the internal OpenGL program object
		* \param pname Specifies the name of the parameter to modify.
		* \param value Specifies the new value of the parameter
		*              specified by pname.
		*/
	 void Parameter (GLenum pname, GLint value) const;
	 /**
		* Attaches a Shader.
		* Attaches the OpenGL shader object of a Shader to the internal
		* program object.
		* \param shader Specifies the Shader to attach.
		* \return Whether the program was successfully created.
		*/
	 void Attach (const Shader &shader) const;
	 /**
		* Links a Program.
		* Links the internal OpenGL program object.
		* \return Whether the program was successfully linked.
		*/
	 bool Link (void) const;
	 /**
		* Load a Program binary.
		* Loads the internal OpenGL program object with a program binary.
		* \param binaryFormat Specifies the format of the binary data in binary.
		* \param binary Specifies the address an array containing the binary
		*               to be loaded into program.
		* \param length Specifies the number of bytes contained in binary.
		* \returns whether the program was successfully loaded
		*/
	 bool Binary (GLenum binaryFormat, const void *binary,
								GLsizei length) const;
	 /**
		* Obtain program binary.
		* Return a binary representation of a program object's compiled and
		* linked executable source.
		* \param bufSize Specifies the size of the buffer whose address is
		*                given by binary.
		* \param length Specifies the address of a variable to receive the
		*               number of bytes written into binary.
		* \param binaryFormat Specifies the address of a variable to receive
		*                     a token indicating the format of the binary data
		*                     returned by the GL.
		* \param binary Specifies the address an array into which the GL will
		*               return program's binary representation.
		*/
	 void GetBinary (GLsizei bufsize, GLsizei *length,
									 GLenum *binaryFormat, void *binary) const;
	 /**
		* Return a parameter.
		* Returns a parameter from the internal OpenGL program object.
		* \param pname Specifies the object parameter. Accepted
		*              symbolic names are
		*              GL_DELETE_STATUS, GL_LINK_STATUS,
		*              GL_VALIDATE_STATUS, GL_INFO_LOG_LENGTH,
		*              GL_ATTACHED_SHADERS, GL_ACTIVE_ATTRIBUTES,
		*              GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, GL_ACTIVE_UNIFORMS,
		*              GL_ACTIVE_UNIFORM_BLOCKS,
		*              GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
		*              GL_ACTIVE_UNIFORM_MAX_LENGTH, GL_PROGRAM_BINARY_LENGTH,
		*              GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
		*              GL_TRANSFORM_FEEDBACK_VARYINGS,
		*              GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
		*              GL_GEOMETRY_VERTICES_OUT, GL_GEOMETRY_INPUT_TYPE, and
		*              GL_GEOMETRY_OUTPUT_TYPE.
		* \param params Returns the requested object parameter.
		*/
	 void Get (GLenum pname, GLint *params) const;
	 /**
		* Use a Program.
		* Installs the internal OpenGL program object
		* as part of current rendering state.
		*/
	 void Use (void) const;
	 /**
		* Disable all Programs
		* Uninstalls the current OpenGL program object, so that shader pipelines
		* can be used.
		*/
	 static void UseNone (void);
	 /**
		* Get the info log.
		* Obtain the info log of the internal OpenGL program object.
		* \return The info log of the program.
		*/
	 std::string GetInfoLog (void) const;
	 /**
		* Get subroutine uniform location.
		* Retrieve the location of a subroutine uniform of
		* a given shader stage within a program.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param name Specifies the name of the subroutine uniform
		*             whose index to query.
		* \returns The subroutine uniform location.
		*/
	 GLint GetSubroutineUniformLocation (GLenum shadertype,
																			 const std::string &name) const;
   /**
		* Get the index of a subroutine unifom.
		* Retrieve the index of a subroutine uniform of a given shader stage
		* within a program.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param name Specifies the name of the subroutine uniform
		*             whose index to query.
		* \retuns The subroutine index.
		*/
	 GLuint GetSubroutineIndex (GLenum shadertype,
															const std::string &name) const;
   /**
		* Get an active subroutine uniform property.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param index Specifies the index of the shader subroutine uniform.
		* \param pname Specifies the parameter of the shader subroutine uniform
		*              to query. pname must be GL_NUM_COMPATIBLE_SUBROUTINES,
		*              GL_COMPATIBLE_SUBROUTINES, GL_UNIFORM_SIZE or
		*              GL_UNIFORM_NAME_LENGTH.
		* \param values Specifies the address of a into which the queried value
		*               or values will be placed.
		*/
	 void GetActiveSubroutineUniform (GLenum shadertype, GLuint index,
																		GLenum pname, GLint *values) const;
	 /**
		* Get a subroutine uniform name.
		* Query the name of an active shader subroutine uniform.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param index Specifies the index of the shader subroutine uniform.
		* \returns The name of the specified shader subroutine unifom.
		*/
	 std::string GetActiveSubroutineUniformName (GLenum shadertype,
																							 GLuint index) const;
	 /**
		* Get a subroutine name.
		* Query the name of an active shader subroutine.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param index Specifies the index of the shader subroutine uniform.
		* \returns The subroutine name.
		*/
	 std::string GetActiveSubroutineName (GLenum shadertype,
																				GLuint index) const;
	 /**
		* Get shader stage properties.
		* Retrieve properties of a program object corresponding to
		* a specified shader stage.
		* \param shadertype Specifies the shader stage from which to query
		*                   for subroutine uniform index. shadertype must be
		*                   one of GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER,
		*                   GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER or
		*                   GL_FRAGMENT_SHADER.
		* \param pname Specifies the parameter of the shader to query. pname
		*              must be GL_ACTIVE_SUBROUTINE_UNIFORMS,
		*              GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS,
		*              GL_ACTIVE_SUBROUTINES,
		*              GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH,
		*              or GL_ACTIVE_SUBROUTINE_MAX_LENGTH.
		* \param values Specifies the address of a variable into which
		*               the queried value or values will be placed.
		*/
	 void GetProgramStage (GLenum shadertype, GLenum pname, GLint *values) const;
	 /** 
		* Obtain a Uniform location.
		* Obtains the Uniform location of a uniform variable
		* within the shader program.
		* \param name Name of the uniform variable.
		* \return An Uniform object representing the specified uniform variable.
		*/
	 Uniform operator[] (const std::string &name) const;
	 /**
		* Return internal object.
		* Returns the internal OpenGL shader program object. Use with caution.
		* \return The internal OpenGL shader program object.
		*/
	 GLuint get (void) const;
   /**
		* Swap internal object.
		* Swaps the internal OpenGL shader program object with another gl::Program.
		* \param program Object with which to swap the internal OpenGL
		*                shader program object.
		*/
	 void swap (Program &program);
private:
	 /**
		* internal OpenGL shader program
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined PROGRAM_H */
