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
#ifndef GLP_BUFFER_H
#define GLP_BUFFER_H

#include "common.h"

namespace gl {

/** OpenGL buffer object.
 * A wrapper class around an OpenGL Buffer object.
 */
class Buffer
{
public:
	/**
	 * Default contructor.
	 * Creates a new Buffer object.
	 */
	 Buffer (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL buffer object to another Buffer object.
		*/
	 Buffer (Buffer &&buffer);
	 /**
		* Deleted copy constructor.
		* A Buffer object can't be copy constructed.
		*/
	 Buffer (const Buffer&) = delete;
	 /**
		* A destructor.
		* Deletes a Buffer object.
		*/
	 ~Buffer (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL buffer object to another Buffer object.
		*/
	 Buffer &operator= (Buffer &&buffer);
	 /**
		* Deleted copy assignment.
		* A Buffer object can't be copy assigned.
		*/
	 Buffer &operator= (const Buffer&) = delete;
	 /**
		* Bind the Buffer object.
		* Binds the Buffer object to the specified target.
		* \param target Specifies which target to bind the Buffer to.
		* \sa Unbind()
		*/
	 void Bind (GLenum target) const;
	 /**
		* Unbinds Buffers.
		* Unbinds any Buffer object potentially bound to the specified target.
		* \param target Specifies from which target Buffers should be unbound.
		* \sa Bind()
		*/
	 static void Unbind (GLenum target);
	 /**
		* Create and initialize the data store.
		* Creates and initializes the data store of the internal
		* OpenGL buffer object.
		* \param size Specifies the size in bytes of the Buffer object's
		*             new data store.
		* \param data Specifies a pointer to data that will be copied
		*             into the data store for initialization, or NULL
		*             if no data is to be copied.
		* \param usage Specifies the expected usage pattern of the data store.
		*              The symbolic constant must be GL_STREAM_DRAW,
		*              GL_STREAM_READ, GL_STREAM_COPY, GL_STATIC_DRAW,
		*              GL_STATIC_READ, GL_STATIC_COPY, GL_DYNAMIC_DRAW,
		*              GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.
		* \sa SubData()
		*/
	 void Data (GLsizeiptr size, const GLvoid *data, GLenum usage) const;
	 /**
		* Updates a subset of a Buffer object's data store.
		* Updates a subset of the data store of the internal OpenGL buffer object.
		* \param offset Specifies the offset into the Buffer object's data store
		*               where data replacement will begin, measured in bytes.
		* \param size Specifies the size in bytes of the data store region
		*             being replaced.
		* \param data Specifies a pointer to the new data that will be copied
		*             into the data store.
		* \sa Data()
		*/
	 void SubData (GLintptr offset, GLsizeiptr size, const GLvoid *data) const;
   /**
		* Map a Buffer object's data store.
		* Maps the data store of the internal OpenGL buffer object.
		* \param access Specifies the access policy, indicating whether it
		*               will be possible to read from, write to, or both read
		*               from and write to the Buffer object's mapped data store.
		*               The symbolic constant must be GL_READ_ONLY, GL_WRITE_ONLY,
		*               or GL_READ_WRITE.
		* \sa Unmap()
		*/
	 GLvoid *Map (GLenum access) const;
	 /**
		* Unmap a Buffer object's data store.
		* Unmaps the data store of the internal OpenGL buffer object.
		* \sa Map
		*/
	 void Unmap (void) const;
	 /**
		* Return internal object.
		* Returns the internal OpenGL buffer object. Use with caution.
		* \return The internal OpenGL buffer object.
		*/
	 GLuint get (void) const;
private:
	 /**
		* internal OpenGL buffer object name
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined GLP_BUFFER_H */
