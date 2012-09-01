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
#ifndef OGLP_VERTEXARRAY_H
#define OGLP_VERTEXARRAY_H

#include "common.h"
#include "buffer.h"

namespace oglp {

/** OpenGL vertex array object.
 * A wrapper class around an OpenGL vertex array object.
 */
class VertexArray
{
public:
	/**
	 * Default contructor.
	 * Creates a new VertexArray object.
	 */
	 VertexArray (void) {
		 GenVertexArrays (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL vertex array object to
		* another VertexArray object.
		* \param va VertexArray object to move.
		*/
	 VertexArray (VertexArray &&va) : obj (va.obj) {
		 	GenVertexArrays (1, &va.obj);
			CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A VertexArray object can't be copy constructed.
		*/
	 VertexArray (const VertexArray&) = delete;
	 /**
		* A destructor.
		* Deletes a VertexArray object.
		*/
	 ~VertexArray (void) {
		 DeleteVertexArrays (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move assignment.
		* Passes the internal OpenGL vertex array object to
		* another VertexArray object.
		* \param va The VertexArray object to move.
		* \return A reference to the VertexArray object.
		*/
	 VertexArray &operator= (VertexArray &&va) {
		 obj = va.obj;
		 GenVertexArrays (1, &va.obj);
		 CheckError ();
	 }
	 /**
		* Deleted copy assignment.
		* A VertexArray object can't be copy assigned.
		* \return
		*/
	 VertexArray &operator= (const VertexArray&) = delete;
	 /**
		* Bind the VertexArray object.
		* Binds the internal OpenGL vertex array object.
		*/
	 void Bind (void) const {
		 BindVertexArray (obj);
		 CheckError ();
	 }
	 /**
		* Specify an vertex attrib.
		* Defines an array of generic vertex attribute data in the vertex array.
		* \param buffer Buffer object in which the data is stored.
		* \param index Specifies the index of the generic vertex
		*              attribute to be modified.
		* \param type Specifies the data type of each component.
		*             Must be one of the following symbolic constants:
		*             - GL_BYTE
		*             - GL_UNSIGNED_BYTE
		*             - GL_SHORT
		*             - GL_UNSIGNED_SHORT
		*             - GL_INT
		*             - GL_UNSIGNED_INT
		*             - GL_FLOAT
		*             - GL_DOUBLE
		* \param size Specifies the number of components per generic
		*             vertex attribute. Must be 1, 2, 3, or 4.
		* \param normalized Specifies whether fixed-point data values
		*                   should be normalized (GL_TRUE) or converted
		*                   directly as fixed-point values (GL_FALSE) when
		*                   they are accessed.
		* \param stride Specifies the byte offset between consecutive
		*               generic vertex attributes. If stride is 0, the
		*               generic vertex attributes are understood to be
		*               tightly packed.
		* \param offset Specifies the offset of the first component of
		*               the first generic vertex attribute in the buffer.
		*/
	 void VertexAttribOffset (const Buffer &buffer, GLuint index, GLint size,
														GLenum type, GLboolean normalized, GLsizei stride,
														GLintptr offset) {
		 VertexArrayVertexAttribOffsetEXT (obj, buffer.get (), index, size,
																			 type, normalized, stride, offset);
		 CheckError ();
	 }
	 /**
		* Enable a vertex attrib.
		* Enables a generic vertex attribute.
		* \param index Specifies the index of the generic vertex
		*              attribute to be enabled.
		*/
	 void EnableVertexAttrib (GLuint index) {
		 EnableVertexArrayAttribEXT (obj, index);
		 CheckError ();
	 }
	 /**
		* Disable a vertex attrib.
		* Disables a generic vertex attribute.
		* \param index Specifies the index of the generic vertex
		*              attribute to be disabled.
		*/
	 void DisableVertexAttrib (GLuint index) {
		 DisableVertexArrayAttribEXT (obj, index);
		 CheckError ();
	 }
	 /**
		* Return internal object.
		* Returns the internal OpenGL vertex array object. Use with caution.
		* \return The internal OpenGL vertex array object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL vertex array object with another
		* VertexArray.
		* \param vertexarray Object with which to swap the internal
		*                vertex array object.
		*/
	 void swap (VertexArray &vertexarray) {
		 std::swap (obj, vertexarray.obj);
	 }
private:
	 /**
		* internal OpenGL vertex array object
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_VERTEXARRAY_H */
