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
		*/
	 Program &operator= (Program&&);
	 /**
		* Deleted copy assignment.
		* A Program object can't be copy assigned.
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
		* Obtain a Uniform location.
		* Obtains the Uniform location of a uniform variable
		* within the shader program.
		* \param name Name of the uniform variable.
		* \return An Uniform object representing the specified uniform variable.
		*/
	 Uniform operator[] (const std::string &name) const;
private:
	 /**
		* internal OpenGL shader program
		*/
	 GLuint program;
	 friend class ProgramPipeline;
};

} /* namespace gl */

#endif /* !defined PROGRAM_H */
