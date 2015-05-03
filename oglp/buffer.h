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

namespace oglp {

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
    Buffer (void)
    {
        GenBuffers (1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL buffer object to another Buffer object.
       * \param buffer The Buffer object to move.
       */
    Buffer (Buffer &&buffer) noexcept
    {
        GLuint tmp = obj;
        obj = buffer.obj;
        buffer.obj = tmp;
    }

    /**
       * Deleted copy constructor.
       * A Buffer object can't be copy constructed.
       */
    Buffer (const Buffer &) = delete;

    /**
       * A destructor.
       * Deletes a Buffer object.
       */
    ~Buffer (void)
    {
        DeleteBuffers (1, &obj);
    }

    /**
       * Move assignment.
       * Passes the internal OpenGL buffer object to another Buffer object.
       * \param buffer The Buffer object to move.
       * \return A reference to the buffer object.
       */
    Buffer &operator= (Buffer &&buffer) noexcept
    {
        GLuint tmp = obj;
        obj = buffer.obj;
        buffer.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A Buffer object can't be copy assigned.
       * \return
       */
    Buffer &operator= (const Buffer &) = delete;

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
    void Bind (GLenum target) const
    {
        BindBuffer (target, obj);
        CheckError ();
    }

    /**
       * Label the buffer object.
       * Labels the internal OpenGL buffer object.
       * \param name Label to be used for the buffer object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_BUFFER, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Bind the buffer object.
       * Binds the Buffer object to an indexed buffer target.
       * \param target Specify the target of the bind operation. target must be
       *               one of GL_ATOMIC_COUNTER_BUFFER,
       *               GL_TRANSFORM_FEEDBACK_BUFFER or GL_UNIFORM_BUFFER.
       * \param index  Specify the index of the binding point within the
       *               array specified by target.
       */
    void BindBase (GLenum target, GLuint index) const
    {
        BindBufferBase (target, index, obj);
        CheckError ();
    }

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
                    GLsizeiptr size) const
    {
        BindBufferRange (target, index, obj, offset, size);
        CheckError ();
    }

    /**
       * Unbinds Buffers.
       * Unbinds any Buffer object potentially bound to the specified target.
       * \param target Specifies from which target all buffers should be unbound.
       * \sa Bind()
       */
    static void Unbind (GLenum target)
    {
        BindBuffer (target, 0);
        CheckError ();
    }

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
    void Data (GLsizeiptr size, const GLvoid *data, GLenum usage)
    {
        NamedBufferDataEXT (obj, size, data, usage);
        CheckError ();
    }

    /**
       * Creates and initializes an immutable data store.
       * Creates and initializes an immutable data store for the internal
       * OpenGL buffer object.
       * \param size Specifies the size in bytes of the Buffer object's
       *             new data store.
       * \param data Specifies a pointer to data that will be copied
       *             into the data store for initialization, or NULL
       *             if no data is to be copied.
       * \param flags Specifies the intended usage of the buffer's data store.
       *              Must be a bitwise combination of the following flags:
       *              - GL_DYNAMIC_STORAGE_BIT
       *              - GL_MAP_READ_BIT
       *              - GL_MAP_WRITE_BIT
       *              - GL_MAP_PERSISTENT_BIT
       *              - GL_MAP_COHERENT_BIT
       *              - GL_CLIENT_STORAGE_BIT.
       */
    void Storage (GLsizeiptr size, const void *data, GLbitfield flags)
    {
        NamedBufferStorageEXT (obj, size, data, flags);
        CheckError ();
    }

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
    void SubData (GLintptr offset, GLsizeiptr size, const GLvoid *data)
    {
        NamedBufferSubDataEXT (obj, offset, size, data);
        CheckError ();
    }

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
    GLvoid *Map (GLenum access) const
    {
        GLvoid *ptr;
        ptr = MapNamedBufferEXT (obj, access);
        CheckError ();
#ifdef OGLP_THROW_EXCEPTIONS
		 if (ptr == NULL) throw std::runtime_error ("An OpenGL buffer object could not be mapped to memory.");
#endif
        return ptr;
    }

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
                      GLbitfield access) const
    {
        GLvoid *ptr;
        ptr = MapNamedBufferRangeEXT (obj, offset, length, access);
        CheckError ();
#ifdef OGLP_THROW_EXCEPTIONS
		 if (ptr == NULL) throw std::runtime_error ("An OpenGL buffer object could not be mapped to memory");
#endif
        return ptr;
    }

    /**
       * Unmap a Buffer object's data store.
       * Unmaps the data store of the internal OpenGL buffer object.
       * \sa Map
       */
    void Unmap (void) const
    {
        UnmapNamedBufferEXT (obj);
        CheckError ();
    }

    /**
       * Flush mapped buffer range.
       * Indicates modifications to a range of a mapped buffer.
       * \param offset Specifies the start of the buffer subrange,
       *               in basic machine units.
       * \param length Specifies the length of the buffer subrange,
       *               in basic machine units.
       */
    void FlushMappedRange (GLintptr offset, GLsizeiptr length) const
    {
        FlushMappedNamedBufferRangeEXT (obj, offset, length);
        CheckError ();
    }

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
                    GLenum type, const void *data)
    {
        ClearNamedBufferDataEXT (obj, internalformat, format, type, data);
        CheckError ();
    }

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
                       const void *data)
    {
        ClearNamedBufferSubDataEXT (obj, internalformat, offset, size,
                                    format, type, data);
        CheckError ();
    }

    /** Get parameter.
       * Returns parameters of the internal OpenGL buffer object.
       * \param value Specifies the symbolic name of a buffer object parameter.
       *              Accepted values are GL_BUFFER_ACCESS, GL_BUFFER_MAPPED,
       *              GL_BUFFER_SIZE, or GL_BUFFER_USAGE.
       * \param data Returns the requested parameter.
       */
    void GetParameter (GLenum value, GLint *data) const
    {
        GetNamedBufferParameterivEXT (obj, value, data);
        CheckError ();
    }

    /** Invalidate buffer.
       * Invalidates the content of the internal
       * OpenGL buffer object's data store.
       */
    void InvalidateData (void)
    {
        InvalidateBufferData (obj);
        CheckError ();
    }

    /** Invalidate a buffer region.
       * Invalidates a region of the internal
       * OpenGL buffer object's data store.
       * \param offset The offset within the buffer's data store
       *               of the start of the range to be invalidated.
       * \param length The length of the range within the buffer's
       *               data store to be invalidated.
       */
    void InvalidateSubData (GLintptr offset, GLsizeiptr length)
    {
        InvalidateBufferSubData (obj, offset, length);
        CheckError ();
    }

    /**
       * Return internal object.
       * Returns the internal OpenGL buffer object. Use with caution.
       * \return The internal OpenGL buffer object.
       */
    GLuint get (void) const
    {
        return obj;
    }

    /** Copy buffer data.
       * Copies data between buffer objects.
       * \param readBuffer  Buffer object to read from.
       * \param writeBuffer Buffer object to write fom.
       * \param readOffset  offset to start reading
       * \param writeOffset offset to start writing
       * \param size        number of bytes to copy
       */
    static void CopySubData (const Buffer &readBuffer,
                             Buffer &writeBuffer,
                             GLintptr readOffset,
                             GLintptr writeOffset,
                             GLsizeiptr size)
    {
        NamedCopyBufferSubDataEXT (readBuffer.obj, writeBuffer.obj,
                                   readOffset, writeOffset, size);
        CheckError ();
    }

private:
    /**
       * internal OpenGL buffer object name
       */
    GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_BUFFER_H */
