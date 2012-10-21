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
#ifndef UNIFORMBLOCK_H
#define UNIFORMBLOCK_H

#include "common.h"

namespace oglp {

/** OpenGL shader uniform buffer object.
 * A wrapper class around the uniform buffer object within an
 * OpenGL shader program.
 */
class UniformBlock
{
public:
	 /**
		* Default constructor.
		* Creates a new UniformBlock object.
		*/
	 UniformBlock (void) {
		 program = 0;
		 idx = 0;
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal uniform block to
		* another UniformBlock object.
		* \param u The UniformBlock object to move.
		*/
	 UniformBlock (UniformBlock &&u) : program (u.program), idx (u.idx) {
		 u.program = 0;
		 u.idx = 0;
	 }
	 /**
		* A destructor.
		* Deletes a UniformBlock object.
		*/
	 ~UniformBlock (void) {
	 }
	 /**
		* Copy construction.
		* Creates a UniformBlock by cloning another UniformBlock.
		* \param u The UniformBlock object to clone.
		*/
	 UniformBlock (const UniformBlock &u) : program (u.program), idx (u.idx) {
	 }
	 /** Query information about an active uniform block.
		* Queries information about an active uniform block.
		* \param pname Specifies the name of the parameter to query.
		* \param params Specifies the address of a variable to receive
		*               the result of the query.
		*/
	 void GetActive (GLenum pname, GLint *params) const {
		 GetActiveUniformBlockiv (program, idx, pname, params);
		 CheckError ();
	 }
	 /** Query the last selected binding point.
		* Queries the index of the uniform buffer binding point last selected
		* by the uniform block specified. If no uniform block has been
		* previously specified, zero is returned.
		* \returns The binding point.
		*/
	 GLuint GetBinding (void) const {
		 GLint binding;
		 GetActive (GL_UNIFORM_BLOCK_BINDING, &binding);
		 return binding;
	 }
	 /** Query the minimum buffer object size.
		* Queries the implementation-dependent minimum total buffer object size,
		* in basic machine units, required to hold all active uniforms
		* in the uniform block.
		* \returns The minimum total buffer object size.
		*/
	 GLuint GetDataSize (void) const {
		 GLint datasize;
		 GetActive (GL_UNIFORM_BLOCK_DATA_SIZE, &datasize);
		 return datasize;
	 }
	 /** Get the name of the uniform block.
		* Obtains the name of the uniform block.
		* \returns The name of the uniform block.
		*/
	 std::string GetName (void) const {
		 std::vector<char> name;
		 GLint namelength;
		 GetActive (GL_UNIFORM_BLOCK_NAME_LENGTH, &namelength);
		 name.resize (namelength);
		 GetActiveUniformBlockName (program, idx, name.size (),
																&namelength, &name[0]);
		 CheckError ();
		 return std::string (&name[0], &name[namelength]);
	 }
	 /** Get active uniform indices.
		* Returns a vector of active uniform indices in the uniform block.
		* \returns The active uniform indices.
		*/
	 std::vector<GLuint> GetActiveUniformIndices (void) const {
		 std::vector<GLuint> indices;
		 GLint num_uniforms;
		 GetActive (GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &num_uniforms);
		 indices.resize (num_uniforms);
		 GetActive (GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES,
								reinterpret_cast<GLint*> (&indices[0]));
		 CheckError ();
		 return indices;
	 }
	 /**
		* Move assignment.
		* Passes the internal uniform block to another
		* UniformBlock object.
		* \param u The UniformBlock object to move.
		* \return A reference to the UniformBlock object.
		*/
	 UniformBlock &operator= (UniformBlock &&u) {
		 program = u.program;
		 idx = u.idx;
		 u.program = 0;
		 u.idx = 0;
		 return *this;
	 }
	 /**
		* Copy assignment.
		* Assign a UniformBlock object with the contents of another.
		* \param u The UniformBlock object to clone.
		* \return A reference to the UniformBlock object.
		*/
	 UniformBlock &operator= (const UniformBlock &u) {
		 program = u.program;
		 idx = u.idx;
		 return *this;
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
		* Return internal block index.
		* Returns the internal OpenGL block index. Use with caution.
		* \return The internal OpenGL block index.
		*/
	 GLuint getBlockIndex (void) const {
		 return idx;
	 }
   /**
		* Swap contents.
		* Swaps the contents of the UniformBlock object with another.
		* \param program Object with which to swap the contents
		*                of the UniformBlock.
		*/
	 void swap (UniformBlock &u) {
		 std::swap (program, u.program);
		 std::swap (idx, u.idx);
	 }
private:
   /**
		* Private constructor.
		* Private constructor for internal creation from a Program object.
		* \param _program Internal OpenGL shader program.
		* \param _idx Internal OpenGL uniform block index.
		*/
	 UniformBlock (GLuint _program, GLuint _idx)
		 : program (_program), idx (_idx) {
	 }
	 /**
		* internal OpenGL shader program
		*/
	 GLuint program;
	 /**
		* internal OpenGL uniform block index
		*/
	 GLuint idx;
	 friend class Program;
};

} /* namespace oglp */

#endif /* !defined UNIFORMBLOCK_H */
