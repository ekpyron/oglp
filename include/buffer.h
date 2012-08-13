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
#ifndef OGLP_BUFFER_H
#define OGLP_BUFFER_H

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
		* \param buffer The Buffer object to move.
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
		* \param buffer The Buffer object to move.
		* \return A reference to the buffer object.
		*/
	 Buffer &operator= (Buffer &&buffer);
	 /**
		* Deleted copy assignment.
		* A Buffer object can't be copy assigned.
		* \return
		*/
	 Buffer &operator= (const Buffer&) = delete;
	 /**
		* Bind the Buffer object.
		* Binds the Buffer object to the specified target.
		* \param target Specifies the target to which the buffer object is bound.
		*               The following symbolic constants are accepted:
		*               - GL_ARRAY_BUFFER
		*               - GL_ATOMIC_COUNTER_BUFFER
		*               - GL_COPY_READ_BUFFER
		*               - GL_COPY_WRITE_BUFFER
		*               - GL_DRAW_INDIRECT_BUFFER
		*               - GL_ELEMENT_ARRAY_BUFFER
		*               - GL_PIXEL_PACK_BUFFER
		*               - GL_PIXEL_UNPACK_BUFFER
		*               - GL_TEXTURE_BUFFER
		*               - GL_TRANSFORM_FEEDBACK_BUFFER
		*               - GL_UNIFORM_BUFFER
		* \sa Unbind()
		*/
	 void Bind (GLenum target) const;
	 /**
		* Bind the buffer object.
		* Binds the Buffer object to an indexed buffer target.
		* \param target Specify the target of the bind operation. target must be
		*               one of GL_ATOMIC_COUNTER_BUFFER,
		*               GL_TRANSFORM_FEEDBACK_BUFFER or GL_UNIFORM_BUFFER.
		* \param index  Specify the index of the binding point within the
		*               array specified by target.
		*/
	 void BindBase (GLenum target, GLuint index) const;
	 /**
		* Bind a range of the buffer object.
		* Binds a range of the Buffer object to an indexed buffer target.
		* \param target Specify the target of the bind operation. target must be
		*               one of GL_ATOMIC_COUNTER_BUFFER,
		*               GL_TRANSFORM_FEEDBACK_BUFFER or GL_UNIFORM_BUFFER.
		* \param index  Specify the index of the binding point within the
		*               array specified by target.
		* \param offset The starting offset in basic machine units into
		*               the buffer object buffer.
		* \param size   The amount of data in machine units that can be read
		*               from the buffet object while used as an indexed target.
		*/
	 void BindRange (GLenum target, GLuint index, GLintptr offset,
									 GLsizeiptr size) const;
	 /**
		* Unbinds Buffers.
		* Unbinds any Buffer object potentially bound to the specified target.
		* \param target Specifies from which target all buffers should be unbound.
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
		*              The following symbolic constants are accepted:
		*              - GL_STREAM_DRAW
		*              - GL_STREAM_READ
		*              - GL_STREAM_COPY
		*              - GL_STATIC_DRAW
		*              - GL_STATIC_READ
		*              - GL_STATIC_COPY
		*              - GL_DYNAMIC_DRAW
		*              - GL_DYNAMIC_READ
		*              - GL_DYNAMIC_COPY
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
		*               The following symbolic constants are accepted:
		*               - GL_READ_ONLY
		*               - GL_WRITE_ONLY
		*               - GL_READ_WRITE
		* \return A pointer to the memory region the data store was mapped to.
		* \sa Unmap()
		*/
	 GLvoid *Map (GLenum access) const;
	 /**
		* Map a section of a buffer object's data store.
		* Maps a section of the internal OpenGL buffer object's data store.
		* \param offset Specifies a the starting offset within the buffer
		*               of the range to be mapped.
		* \param length Specifies a length of the range to be mapped.
		* \param access Specifies a combination of access flags indicating
		*               the desired access to the range.
		* \return A pointer to the memory region the data store was mapped to.
		* \sa Map()
		*/
	 GLvoid *MapRange (GLintptr offset, GLsizeiptr length,
										 GLbitfield access) const;
	 /**
		* Unmap a Buffer object's data store.
		* Unmaps the data store of the internal OpenGL buffer object.
		* \sa Map
		*/
	 void Unmap (void) const;
	 /**
		* Fill a buffer object.
		* Fill the data store of the internal OpenGL buffer object
		* with a fixed value
		* \param internalformat The internal format with which the data
		*                       will be stored in the buffer object.
		* \param format The format of the data in memory addressed by data.
		* \param type The type of the data in memory addressed by data.
		* \param data The address of a memory location storing the data
		*             to be replicated into the buffer's data store.
		*/
	 void ClearData (GLenum internalformat, GLenum format,
									 GLenum type, const void *data);
	 /**
		* Fill a buffer object.
		* Fill all or part of the data store of the internal OpenGL
		* buffer object with a fixed value
		* \param internalformat The internal format with which the data
		*                       will be stored in the buffer object.
		* \param offset The offset, in basic machine units into the buffer
		*               object's data store at which to start filling.
		* \param size he size, in basic machine units of the range
		*             of the data store to fill.
		* \param format The format of the data in memory addressed by data.
		* \param type The type of the data in memory addressed by data.
		* \param data The address of a memory location storing the data
		*             to be replicated into the buffer's data store.
		*/
	 void ClearSubData (GLenum internalformat, GLenum format,
											GLenum type, GLsizeiptr offset,
											GLsizeiptr size,
											const void *data);
	 /**
		* Return internal object.
		* Returns the internal OpenGL buffer object. Use with caution.
		* \return The internal OpenGL buffer object.
		*/
	 GLuint get (void) const;
	 /**
		* Swaps internal object.
		* Swaps the internal OpenGL buffer object with another gl::Buffer.
		* \param buffer Object with which to swap the internal object.
		*/
	 void swap (Buffer &buffer);
	 /** Copy buffer data.
		* Copies data between buffer objects.
		* \param readBuffer  Buffer object to read from.
		* \param writeBuffer Buffer object to write fom.
		* \param readOffset  offset to start reading
		* \param writeOffset offset to start writing
		* \param size        number of bytes to copy
		*/
	 static void CopySubData (Buffer &readBuffer,
														Buffer &writeBuffer,
														GLintptr readOffset,
														GLintptr writeOffset,
														GLsizeiptr size);
private:
	 /**
		* internal OpenGL buffer object name
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined OGLP_BUFFER_H */
