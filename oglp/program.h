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
#include "uniformblock.h"
#include "programresource.h"
#include "shader.h"
#include <string>
#include <vector>

namespace oglp {

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
	 Program (void) {
		 obj = CreateProgram ();
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader program object to
		* another Program object.
		* \param p The Program object to move.
		*/
	 Program (Program &&p) : obj (p.obj) {
		 p.obj = CreateProgram ();
		 CheckError ();
	 }
	 /**
		* A destructor.
		* Deletes a Program object.
		*/
	 ~Program (void) {
		 if (obj) {
			 DeleteProgram (obj);
			 CheckError ();
			 obj = 0;
		 }
	 }
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
	 Program &operator= (Program &&p) {
		 obj = p.obj;
		 p.obj = CreateProgram ();
		 CheckError ();
	 }
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
	 bool Create (GLenum type, const std::string &source) {
		 const GLchar *src = source.c_str ();
		 GLint status;
		 DeleteProgram (obj);
		 obj = CreateShaderProgramv (type, 1, &src);
		 if (!obj)
		 {
			 obj = CreateProgram ();
			 CheckError ();
			 return false;
		 }
		 
		 GetProgramiv (obj, GL_LINK_STATUS, &status);
		 CheckError ();
		 return status;
	 }
	 /**
		* Specify a parameter.
		* Specify a parameter for the internal OpenGL program object
		* \param pname Specifies the name of the parameter to modify.
		* \param value Specifies the new value of the parameter
		*              specified by pname.
		*/
	 void Parameter (GLenum pname, GLint value) {
		 ProgramParameteri (obj, pname, value);
		 CheckError ();
	 }
	 /**
		* Attaches a Shader.
		* Attaches the OpenGL shader object of a Shader to the internal
		* program object.
		* \param shader Specifies the Shader to attach.
		* \return Whether the program was successfully created.
		*/
	 void Attach (const Shader &shader) {
		 AttachShader (obj, shader.get ());
		 CheckError ();
	 }
	 /**
		* Links a Program.
		* Links the internal OpenGL program object.
		* \return Whether the program was successfully linked.
		*/
	 bool Link (void) {
		 GLint status;
		 LinkProgram (obj);
		 Get (GL_LINK_STATUS, &status);
		 return status;
	 }
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
								GLsizei length) {
		 GLint status;
		 ProgramBinary (obj, binaryFormat, binary, length);
		 GLenum err = GetError ();
		 if (err == GL_INVALID_ENUM)
				return false;
		 if (err != GL_NO_ERROR)
		 {
#ifdef OGLP_ERROR_CALLBACK
			 if (internal::errorcallback)
					internal::errorcallback (err, ErrorToString (err),
																	 internal::errorcallback_userdata);
#endif
#ifdef OGLP_THROW_EXCEPTION
				throw Exception (err);
#else
				return false;
#endif
		 }
		 Get (GL_LINK_STATUS, &status);
		 return status;
	 }
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
	 void GetBinary (GLsizei bufSize, GLsizei *length,
									 GLenum *binaryFormat, void *binary) const {
		 GetProgramBinary (obj, bufSize, length, binaryFormat, binary);
		 CheckError ();
	 }
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
	 void Get (GLenum pname, GLint *params) const {
		 GetProgramiv (obj, pname, params);
		 CheckError ();
	 }
	 /**
		* Use a Program.
		* Installs the internal OpenGL program object
		* as part of current rendering state.
		*/
	 void Use (void) const {
		 UseProgram (obj);
		 CheckError ();
	 }
	 /**
		* Disable all Programs
		* Uninstalls the current OpenGL program object, so that shader pipelines
		* can be used.
		*/
	 static void UseNone (void) {
		 UseProgram (0);
		 CheckError ();
	 }
	 /**
		* Get the info log.
		* Obtain the info log of the internal OpenGL program object.
		* \return The info log of the program.
		*/
	 std::string GetInfoLog (void) const {
		 GLint length;
		 std::vector<GLchar> log;
		 GetProgramiv (obj, GL_INFO_LOG_LENGTH, &length);
		 log.resize (length);
		 GetProgramInfoLog (obj, length, NULL, &log[0]);
		 CheckError ();
		 return std::string (&log[0], length);
	 }
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
																			 const std::string &name) const {
		 GLint location;
		 location = oglp::GetSubroutineUniformLocation (obj, shadertype,
																									name.c_str ());
		 CheckError ();
		 return location;
	 }
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
		* \returns The subroutine index.
		*/
	 GLuint GetSubroutineIndex (GLenum shadertype,
															const std::string &name) const {
		 GLuint index;
		 index = oglp::GetSubroutineIndex (obj, shadertype, name.c_str ());
		 CheckError ();
		 return index;
	 }
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
																		GLenum pname, GLint *values) const {
		 GetActiveSubroutineUniformiv (obj, shadertype, index, pname, values);
		 CheckError ();
	 }
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
																							 GLuint index) const {
		 GLint len = 0;
		 std::vector<char> buf;
		 GetActiveSubroutineUniform (shadertype, index,
																 GL_UNIFORM_NAME_LENGTH, &len);
		 buf.resize (len);
		 oglp::GetActiveSubroutineUniformName (obj, shadertype, index, len,
																				 NULL, &buf[0]);
		 CheckError ();
		 return std::string (&buf[0]);
	 }
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
																				GLuint index) const {
		 GLint len = 0;
		 std::vector<char> buf;
		 GetProgramStage (shadertype, GL_ACTIVE_SUBROUTINE_MAX_LENGTH, &len);
		 buf.resize (len);
		 oglp::GetActiveSubroutineName (obj, shadertype, index, len, NULL, &buf[0]);
		 CheckError ();
		 return std::string (&buf[0]);
	 }
	 /** Get program resource.
		* Retrieves a ProgramResource wrapper of a program resource.
		* \param interface A token identifying the interface within
		*                  program containing the resource named name.
		* \param name The name of the resource to query the index of.
		* \returns The ProgramResource wrapper for the program resource.
		*/
	 ProgramResource GetResource (GLenum interface,
																const std::string &name) const {
		 return ProgramResource (obj, interface,
														 GetProgramResourceIndex (obj, interface,
																											name.c_str ()));
	 }
   /** Get uniform block index.
		* Retrieve the index of a named uniform block.
		* \param uniformBlockName Specifies the name of the uniform block
		*                         whose index to retrieve.
		* \returns The index of the uniform block.
		*/
	 GLuint GetUniformBlockIndex (const std::string &uniformBlockName) const {
		 GLuint idx = oglp::GetUniformBlockIndex (obj, uniformBlockName.c_str ());
		 CheckError ();
		 return idx;
	 }
	 /** Get uniform block.
		* Retrieves a UniformBlock wrapper of a named uniform block.
		* \param uniformBlockName Specifies the name of the uniform block
		*                         for which to receive a wrapper.
		* \returns The UniformBlock wrapper.
		*/
	 UniformBlock GetUniformBlock (const std::string &uniformBlockName) const {
		 return UniformBlock (obj, GetUniformBlockIndex (uniformBlockName));
	 }
	 /** Query information about an active uniform block.
		* Queries information about an active uniform block.
		* \param uniformBlockIndex Specifies the index of the uniform block
		*                          within program.
		* \param pname Specifies the name of the parameter to query.
		* \param params Specifies the address of a variable to receive
		*               the result of the query.
		*/
	 void GetActiveUniformBlock (GLuint uniformBlockIndex, GLenum pname,
															 GLint *params) const
	 {
		 GetActiveUniformBlockiv (obj, uniformBlockIndex, pname, params);
		 CheckError ();
	 }
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
	 void GetProgramStage (GLenum shadertype, GLenum pname,
												 GLint *values) const {
		 GetProgramStageiv (obj, shadertype, pname, values);
		 CheckError ();
	 }
	 /** Get uniform indices.
		* Retrieves indices from a named uniform block.
		* \param uniformCount Specifies the number of uniforms
		*                     whose indices to query.
		* \param uniformNames Specifies the address of an array of pointers to
		*                     buffers containing the names of
		*                     the queried uniforms.
		* \param uniformIndices Specifies the address of an array that will
		*                       receive the indices of the uniforms.
		*/
	 void GetUniformIndices (GLsizei uniformCount, const char **uniformNames,
													 GLuint *uniformIndices) const
	 {
		 oglp::GetUniformIndices (obj, uniformCount, uniformNames, uniformIndices);
		 CheckError ();
	 }
	 /** Get information about active uniform variables.
		* Returns information about several active uniform variables
		* for the specified program object.
		* \param uniformCount Specifies both the number of elements in
		*                     the array of indices uniformIndices and
		*                     the number of parameters written to params upon
		*                     successful return.
		* \param uniformIndices Specifies the address of an array of uniformCount
		*                       integers containing the indices of uniforms within
		*                       program whose parameter pname pname.
		* \param pname Specifies the property of the each uniform in
		*              uniformIndices that should be written into the
		*              corresponding element of params.
		* \param params Specifies the address of an array of uniformCount integers
		*               which are to receive the value of pname for each uniform
		*               in uniformIndices.
		*/
	 void GetActiveUniforms (GLsizei uniformCount, const GLuint *uniformIndices,
													 GLenum pname, GLint *params) const
	 {
		 GetActiveUniformsiv (obj, uniformCount, uniformIndices, pname, params);
		 CheckError ();
	 }
	 /** 
		* Obtain a Uniform location.
		* Obtains the Uniform location of a uniform variable
		* within the shader program.
		* \param name Name of the uniform variable.
		* \return An Uniform object representing the specified uniform variable.
		*/
	 Uniform operator[] (const std::string &name) const {
		 GLint location;
		 location = GetUniformLocation (obj, name.c_str ());
		 CheckError ();
		 return Uniform (obj, location);
	 }
	 /**
		* Return internal object.
		* Returns the internal OpenGL shader program object. Use with caution.
		* \return The internal OpenGL shader program object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL shader program object with another Program.
		* \param program Object with which to swap the internal OpenGL
		*                shader program object.
		*/
	 void swap (Program &program) {
		 std::swap (obj, program.obj);
	 }
private:
	 /**
		* internal OpenGL shader program
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined PROGRAM_H */
