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
#ifndef OGLP_PROGRAMPIPELINE_H
#define OGLP_PROGRAMPIPELINE_H

#include "common.h"
#include "program.h"
#include <string>

namespace gl {

/** OpenGL shader pipeline object.
 * A wrapper class around an OpenGL shader program pipeline.
 */
class ProgramPipeline
{
public:
	 /** Default constructor.
		* Creates a new ProgramPipeline object.
		*/
	 ProgramPipeline (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL shader pipeline object to
		* another ProgramPipeline object.
		*/
	 ProgramPipeline (ProgramPipeline&&);
	 /**
		* Deleted copy constructor.
		* A ProgramPipeline object can't be copy constructed.
		*/
	 ProgramPipeline (const ProgramPipeline&) = delete;
	 /**
		* A destructor.
		* Deletes a ProgramPipeline object.
		*/
	 ~ProgramPipeline (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL shader pipeline object to another
		* ProgramPipeline object.
		*/
	 ProgramPipeline &operator= (ProgramPipeline&&);
	 /**
		* Deleted copy assignment.
		* A ProgramPipeline object can't be copy assigned.
		*/
	 ProgramPipeline &operator= (const ProgramPipeline&) = delete;
	 /**
		* Bind the ProgramPipeline object.
		* Binds the internal OpenGL shader pipeline object.
		*/
	 void Bind (void) const;
	 /**
		* Bind stages of a ShaderProgram to a ProgramPipeline.
		* Binds stages of a OpenGL program object contained in a ShaderProgram
		* pbject to the internal OpenGL program pipeline.
		* \param stages Specifies a set of program stages to bind
		                to the program pipeline object.
    * \param program Specifies the ShaderProgram object containing the
		*                shader executables to use in the ProgramPipeline.
		*/
	 void UseProgramStages (GLbitfield stages, const Program &program);
	 /**
		* Validates the ProgramPipeline against the current OpenGL state.
		* \return Returns the validation status.
		*/
	 bool Validate (void) const;
	 /**
		* Get the info log.
		* Obtains the info log of the internal OpenGL program pipeline object
		* \return A string containing the info log.
		*/
	 std::string GetInfoLog (void) const;
	 /**
		* Return internal object.
		* Returns the internal OpenGL program pipeline object. Use with caution.
		* \return The internal OpenGL program pipeline object.
		*/
	 GLuint get (void) const;
private:
	 /**
		* internal OpenGL program pipeline object
		*/
	 GLuint pipeline;
};

} /* namespace gl */

#endif /* !defined PROGRAMPIPELINE_H */
