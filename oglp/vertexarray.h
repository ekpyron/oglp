/*
 * Copyright 2015 Daniel Kirchner
 *
 * This file is part of midium.
 *
 * midium is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * midium is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with midium.  If not, see <http://www.gnu.org/licenses/>.
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
    VertexArray (void)
    {
        CreateVertexArrays (1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL vertex array object to
       * another VertexArray object.
       * \param va VertexArray object to move.
       */
    VertexArray (VertexArray &&va) noexcept
    {
        GLuint tmp = obj;
        obj = va.obj;
        va.obj = tmp;
    }

    /**
       * Deleted copy constructor.
       * A VertexArray object can't be copy constructed.
       */
    VertexArray (const VertexArray &) = delete;

    /**
       * A destructor.
       * Deletes a VertexArray object.
       */
    ~VertexArray (void)
    {
        DeleteVertexArrays (1, &obj);
    }

    /**
       * Move assignment.
       * Passes the internal OpenGL vertex array object to
       * another VertexArray object.
       * \param va The VertexArray object to move.
       * \return A reference to the VertexArray object.
       */
    VertexArray &operator= (VertexArray &&va) noexcept
    {
        GLuint tmp = obj;
        obj = va.obj;
        va.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A VertexArray object can't be copy assigned.
       * \return
       */
    VertexArray &operator= (const VertexArray &) = delete;

    /**
       * Label the vertex array object.
       * Labels the internal OpenGL vertex array object.
       * \param name Label to be used for the vertex array object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_VERTEX_ARRAY, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Bind the VertexArray object.
       * Binds the internal OpenGL vertex array object.
       */
    void Bind (void) const
    {
        BindVertexArray (obj);
        CheckError ();
    }

    /**
  * Enable a vertex attrib.
  * Enables a generic vertex attribute.
  * \param index Specifies the index of the generic vertex
  *              attribute to be enabled.
  */
    void EnableAttrib (GLuint index)
    {
        EnableVertexArrayAttrib (obj, index);
        CheckError ();
    }

    /**
       * Disable a vertex attrib.
       * Disables a generic vertex attribute.
       * \param index Specifies the index of the generic vertex
       *              attribute to be disabled.
       */
    void DisableAttrib (GLuint index)
    {
        DisableVertexArrayAttrib (obj, index);
        CheckError ();
    }

    /**
     * Specify element buffer.
     * Configures element array buffer binding of a vertex array object.
     * \param buffer Specifies the name of the buffer object to use for the element array buffer binding.
     */
    void ElementBuffer (GLuint buffer) {
        VertexArrayElementBuffer (obj, buffer);
        CheckError ();
    }

    /** Bind vertex buffers.
     * Attach multiple buffer objects to a vertex array object.
     * \param first Specifies the first vertex buffer binding point to which a buffer object is to be bound.
     * \param count Specifies the number of buffers to bind.
     * \param buffers Specifies the address of an array of names of existing buffer objects.
     * \param offsets Specifies the address of an array of offsets to associate with the binding points.
     * \param strides Specifies the address of an array of strides to associate with the binding points.
     */
    void VertexBuffers (GLuint first, GLuint count, const GLuint *buffers,
                        const GLintptr *offsets, const GLsizei *strides) {
        VertexArrayVertexBuffers (obj, first, count, buffers, offsets, strides);
        CheckError ();
    }

    /** Bind vertex buffers.
     * Attach multiple buffer objects to a vertex array object.
     * \param first Specifies the first vertex buffer binding point to which a buffer object is to be bound.
     * \param count Specifies the number of buffers to bind.
     * \param buffers Specifies the address of an array of names of existing buffer objects.
     * \param offsets Specifies the address of an array of offsets to associate with the binding points.
     * \param strides Specifies the address of an array of strides to associate with the binding points.
     */
    void VertexBuffers (GLuint first, GLuint count, const Buffer *buffers,
                        const GLintptr *offsets, const GLsizei *strides) {
        VertexArrayVertexBuffers (obj, first, count, reinterpret_cast<const GLuint*> (buffers), offsets, strides);
        CheckError ();
    }

    /** Bind a vertex buffer.
         * Binds a buffer to a vertex buffer bind point.
         * \param bindingindex The index of the vertex buffer binding point
         *                     to which to bind the buffer.
         * \param buffer The name of an existing buffer to bind
         *               to the vertex buffer binding point.
         * \param offset The offset of the first element of the buffer.
         * \param stride The distance between elements within the buffer.
         */
    void VertexBuffer (GLuint bindingindex, const Buffer &buffer, GLintptr offset, GLsizei stride)
    {
        VertexArrayVertexBuffer (obj, bindingindex, buffer.get (), offset, stride);
        CheckError ();
    }

    /** Bind a vertex buffer.
         * Binds a buffer to a vertex buffer bind point.
         * \param bindingindex The index of the vertex buffer binding point
         *                     to which to bind the buffer.
         * \param buffer The name of an existing buffer to bind
         *               to the vertex buffer binding point.
         * \param offset The offset of the first element of the buffer.
         * \param stride The distance between elements within the buffer.
         */
    void VertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
    {
        VertexArrayVertexBuffer (obj, bindingindex, buffer, offset, stride);
        CheckError ();
    }

    /** Specify vertex format.
       * Specifies the organization of the vertex array.
       * \param attribindex The generic vertex attribute array being described.
       * \param size The number of values per vertex that are stored in the array.
       * \param type The type of the data stored in the array.
       * \param normalized The distance between elements within the buffer.
       * \param relativeoffset The distance between elements within the buffer.
       */
    void AttribFormat (GLuint attribindex, GLint size, GLenum type,
                             GLboolean normalized, GLuint relativeoffset)
    {
        VertexArrayAttribFormat (obj, attribindex, size, type, normalized, relativeoffset);
        CheckError ();
    }

    /** Specify vertex format.
       * Specifies the organization of the vertex array.
       * \param attribindex The generic vertex attribute array being described.
       * \param size The number of values per vertex that are stored in the array.
       * \param type The type of the data stored in the array.
       * \param relativeoffset The distance between elements within the buffer.
       */
    void AttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        VertexArrayAttribIFormat (obj, attribindex, size, type, relativeoffset);
        CheckError ();
    }

    /** Specify vertex format.
       * Specifies the organization of the vertex array.
       * \param attribindex The generic vertex attribute array being described.
       * \param size The number of values per vertex that are stored in the array.
       * \param type The type of the data stored in the array.
       * \param relativeoffset The distance between elements within the buffer.
       */
    void AttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
    {
        VertexArrayAttribLFormat (obj, attribindex, size, type, relativeoffset);
        CheckError ();
    }

    /** Set vertex attrib binding.
       * Associates a vertex attribute and a vertex buffer binding.
       * \param attribindex The index of the attribute to associate
       *                    with a vertex buffer binding.
       * \param bindingindex The index of the vertex buffer binding
       *                     with which to associate the
       *                     generic vertex attribute.
       */
    void AttribBinding (GLuint attribindex, GLuint bindingindex)
    {
        VertexArrayAttribBinding (obj, attribindex, bindingindex);
        CheckError ();
    }

    /** Set vertex attrib advance rate.
       * Modifies the rate at which generic vertex attributes advance.
       * \param bindingindex The index of the binding whose divisor to modify.
       * \param divisor The new value for the instance step rate to apply.
       */
    void BindingDivisor (GLuint bindingindex, GLuint divisor)
    {
        VertexArrayBindingDivisor (obj, bindingindex, divisor);
        CheckError ();
    }

    /**
       * Return internal object.
       * Returns the internal OpenGL vertex array object. Use with caution.
       * \return The internal OpenGL vertex array object.
       */
    GLuint get (void) const
    {
        return obj;
    }
private:
    /**
       * internal OpenGL vertex array object
       */
    GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_VERTEXARRAY_H */
