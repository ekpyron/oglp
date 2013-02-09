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
#ifndef PROGRAM_RESOURCE_H
#define PROGRAM_RESOURCE_H

#include "common.h"
#include <string>
#include <vector>

namespace oglp {

/** OpenGL program resource object.
 * A wrapper class around a program resource within an
 * OpenGL shader program.
 */
class ProgramResource
{
public:
	 /**
		* Default constructor.
		* Creates a new ProgramResource object.
		*/
	 ProgramResource (void) {
		 program = 0;
		 rsrcinterface = 0;
		 idx = 0;
	 }
	 /**
		* Move constuctor.
		* Passes the internal program resource to
		* another ProgramResource object.
		* \param r The ProgramResource object to move.
		*/
	 ProgramResource (ProgramResource &&r)
		 : program (r.program), rsrcinterface (r.rsrcinterface), idx (r.idx) {
		 r.program = 0;
		 r.rsrcinterface = 0;
		 r.idx = 0;
	 }
	 /**
		* A destructor.
		* Deletes a ProgramResource object.
		*/
	 ~ProgramResource (void) {
	 }
	 /**
		* Copy construction.
		* Creates a ProgramResource by cloning another ProgramResource.
		* \param r The ProgramResource object to clone.
		*/
	 ProgramResource (const ProgramResource &r)
		 : program (r.program), rsrcinterface (r.rsrcinterface), idx (r.idx) {
	 }
	 /**
		* Move assignment.
		* Passes the internal program resource to another
		* ProgramResource object.
		* \param r The ProgramResource object to move.
		* \return A reference to the ProgramResource object.
		*/
	 ProgramResource &operator= (ProgramResource &&r) {
		 program = r.program;
		 rsrcinterface = r.rsrcinterface;
		 idx = r.idx;
		 r.program = 0;
		 r.rsrcinterface = 0;
		 r.idx = 0;
		 return *this;
	 }
	 /**
		* Copy assignment.
		* Assign a ProgramResource object with the contents of another.
		* \param u The ProgramResource object to clone.
		* \return A reference to the ProgramResource object.
		*/
	 ProgramResource &operator= (const ProgramResource &r) {
		 program = r.program;
		 rsrcinterface = r.rsrcinterface;
		 idx = r.idx;
		 return *this;
	 }
	 /**
		* Get values for properties.
		* Retrieve values for multiple properties of a
		* single active resource within a program object.
		* \param propCount number of properties to be returned
		* \param props which properties are to be returned
		* \param bufSize size of the array supplied at params
		* \param length if not NULL, returns the number of returned props
		* \param params buffer to store the properties to be returned
		*/
	 void Get (GLsizei propCount, const GLenum *props, GLsizei bufSize,
						 GLsizei *length, GLint *params) const {
		 GetProgramResourceiv (program, rsrcinterface, idx, propCount, props,
													 bufSize, length, params);
		 CheckError ();
	 }
	 /**
		* Get property.
		* Queries the value of a property.
		* \param prop Property to be returned.
		*/
	 GLint GetProperty (GLenum prop) const {
		 GLint value;
		 GetProgramResourceiv (program, rsrcinterface, idx, 1, &prop,
													 1, NULL, &value);
		 CheckError ();
		 return value;
	 }
	 /**
		* Get resource name.
		* Queries the name of the indexed resource within the program.
		* \returns The name of the program resource.
		*/
	 std::string GetName (void) const {
		 std::vector<GLchar> name;
		 name.resize (GetProperty (GL_NAME_LENGTH));
		 GetProgramResourceName (program, rsrcinterface, idx, name.size (),
														 NULL, name.data ());
		 CheckError ();
		 return std::string (name.begin (), name.end ());
	 }
	 /**
		* Return internal program object.
		* Returns the internal OpenGL shader program object. Use with caution.
		* \return The internal OpenGL shader program object.
		*/
	 GLuint getProgram (void) const {
		 return program;
	 }
	 /**
		* Return internal program interface.
		* Returns the internal OpenGL program interface.
		* \returns The internal OpenGL program interface.
		*/
	 GLenum getInterface (void) const  {
		 return rsrcinterface;
	 }
	 /**
		* Return internal block index.
		* Returns the internal OpenGL program resource index. Use with caution.
		* \return The internal OpenGL program resource index.
		*/
	 GLuint getBlockIndex (void) const {
		 return idx;
	 }
   /**
		* Swap contents.
		* Swaps the contents of the ProgramResource object with another.
		* \param r Object with which to swap the contents
		*          of the ProgramResource.
		*/
	 void swap (ProgramResource &r) {
		 std::swap (program, r.program);
		 std::swap (rsrcinterface, r.rsrcinterface);
		 std::swap (idx, r.idx);
	 }
private:
   /**
		* Private constructor.
		* Private constructor for internal creation from a Program object.
		* \param _program Internal OpenGL shader program.
		* \param _rsrcinterface Internal OpenGL program interface.
		* \param _idx Internal OpenGL program resource index.
		*/
	 ProgramResource (GLuint _program, GLuint _rsrcinterface, GLuint _idx)
		 : program (_program), rsrcinterface (_rsrcinterface), idx (_idx) {
	 }
	 /**
		* internal OpenGL shader program
		*/
	 GLuint program;
	 /**
		* internal OpenGL program interface
		*/
	 GLenum rsrcinterface;
	 /**
		* internal OpenGL program resource index
		*/
	 GLuint idx;
	 friend class Program;
};

} /* namespace oglp */

#endif /* !defined PROGRAM_RESOURCE_H */
