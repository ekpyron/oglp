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
#include <vector>
#include <array>

namespace oglp {

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
	 Shader (void) : obj (0) {
	 }
	 /**
		* Constructor.
		* Creates a new Shader object and an internal OpenGL shader object.
		* \param type Specifies the type of shader to be created.
		*             Must be one of the following:
		*             - GL_VERTEX_SHADER
		*             - GL_FRAGMENT_SHADER
		*/
	 Shader (GLenum type) {
		 obj = CreateShader (type);
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader object to
		* another Shader object.
		* \param s Shader object to move.
		*/
	 Shader (Shader &&s) : obj (s.obj) {
		 s.obj = 0;
	 }
	 /**
		* A destructor.
		* Deletes a Shader object.
		*/
	 ~Shader (void) {
		 if (obj)
		 {
			 DeleteShader (obj);
			 CheckError ();
			 obj = 0;
		 }
	 }
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
	 Shader &operator= (Shader &&s) {
		 obj = s.obj;
		 s.obj = 0;
	 }
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
	 void Create (GLenum type) {
		 if (obj)
		 {
			 DeleteShader (obj);
		 }
		 obj = CreateShader (type);
		 CheckError ();
	 }
	 /**
		* Specify source.
		* Replaces the source code in the internal OpenGL shader object.
		* \param source Specifies the source.
		*/
	 void Source (const std::string &source) {
		 const GLchar *src = source.c_str ();
		 ShaderSource (obj, 1, &src, NULL);
		 CheckError ();
	 }
	 /**
		* Specify sources.
		* Replaces the source code in the internal OpenGL shader object.
		* \param sources Specifies the sources.
		*/
	 template<size_t N>
	 inline void Source (const std::array<std::string,N> &sources) {
		 Source (sources.data (), N);
	 }
	 /**
		* Specify sources.
		* Replaces the source code in the internal OpenGL shader object.
		* \param sources Specifies the sources.
		*/
	 inline void Source (const std::vector<std::string> &sources) {
		 Source (&sources[0], sources.size ());
	 }
	 /**
		* Compile the shader object.
		* Compiles the internal OpenGL shader object.
		* \return Whether the shader object was compiled successfully.
		*/
	 bool Compile (void) {
		 GLint status;
		 CompileShader (obj);
		 
		 GetShaderiv (obj, GL_COMPILE_STATUS, &status);
		 CheckError ();
		 return status;
	 }
	 /**
		* Get the info log.
		* Obtain the info log of the internal OpenGL shader object.
		* \return The info log of the internal OpenGL shader object.
		*/
	 std::string GetInfoLog (void) const {
		 GLint length;
		 std::vector<GLchar> log;
		 GetShaderiv (obj, GL_INFO_LOG_LENGTH, &length);
		 log.resize (length);
		 GetShaderInfoLog (obj, length, NULL, &log[0]);
		 return std::string (&log[0], length);
	 }
	 /**
		* Return internal object.
		* Returns the internal OpenGL shader object. Use with caution.
		* \return The internal OpenGL shader object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL shader object with another Shader.
		* \param sampler Object with which to swap the internal shader object.
		*/
	 void swap (Shader &shader) {
		 std::swap (obj, shader.obj);
	 }
private:
	 void Source (const std::string *sources, size_t N) const {
		 std::vector<const GLchar*> sourcelist;
		 std::vector<GLint> lengths;
		 sourcelist.reserve (N);
		 lengths.reserve (N);
		 for (size_t i = 0; i < N; i++)
		 {
			 sourcelist.push_back (sources[i].data ());
			 lengths.push_back (sources[i].length ());
		 }
		 ShaderSource (obj, N, &sourcelist[0], &lengths[0]);
		 CheckError ();
	 }
	 /**
		* internal OpenGL shader object
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined SHADER_H */
