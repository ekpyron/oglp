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
#include "buffer.h"
#include <stdexcept>
#include <algorithm>

namespace gl {

Buffer::Buffer (void)
{
	GenBuffers (1, &obj);
	CheckError ();
}

Buffer::Buffer (Buffer &&buffer)
	: obj (buffer.obj)
{
	GenBuffers (1, &buffer.obj);
	CheckError ();
}

Buffer::~Buffer (void)
{
	DeleteBuffers (1, &obj);
	CheckError ();
}

Buffer &Buffer::operator= (Buffer &&buffer)
{
	obj = buffer.obj;
	GenBuffers (1, &buffer.obj);
	CheckError ();
}

void Buffer::Bind (GLenum target) const
{
	BindBuffer (target, obj);
	CheckError ();
}

void Buffer::BindBase (GLenum target, GLuint index) const
{
	BindBufferBase (target, index, obj);
	CheckError ();
}

void Buffer::BindRange (GLenum target, GLuint index,
												GLintptr offset, GLsizeiptr size) const
{
	BindBufferRange (target, index, obj, offset, size);
	CheckError ();
}

void Buffer::Unbind (GLenum target)
{
	BindBuffer (target, 0);
	CheckError ();
}

void Buffer::Data (GLsizeiptr size, const GLvoid *data,
									 GLenum usage) const
{
	NamedBufferDataEXT (obj, size, data, usage);
	CheckError ();
}

void Buffer::SubData (GLintptr offset, GLsizeiptr size,
											const GLvoid *data) const
{
	NamedBufferSubDataEXT (obj, offset, size, data);
	CheckError ();
}

GLvoid *Buffer::Map (GLenum access) const
{
	GLvoid *ptr;
	ptr = MapNamedBufferEXT (obj, access);
	CheckError ();
	if (ptr == NULL)
	{
		throw std::runtime_error ("An OpenGL buffer object could not be "
															"mapped to memory.");
	}
	return ptr;
}

GLvoid *Buffer::MapRange (GLintptr offset, GLsizeiptr length,
													GLbitfield access) const
{
	GLvoid *ptr;
	ptr = MapNamedBufferRangeEXT (obj, offset, length, access);
	CheckError ();
	if (ptr == NULL)
	{
		throw std::runtime_error ("An OpenGL buffer object could not be "
															"mapped to memory");
	}
	return ptr;
}

void Buffer::Unmap (void) const
{
	UnmapNamedBufferEXT (obj);
	CheckError ();
}

void Buffer::CopySubData (Buffer &readbuffer,
													Buffer &writebuffer,
													GLintptr readOffset,
													GLintptr writeOffset,
													GLsizeiptr size)
{
	NamedCopyBufferSubDataEXT (readbuffer.obj, writebuffer.obj,
														 readOffset, writeOffset, size);
	CheckError ();
}

void Buffer::ClearData (GLenum internalformat, GLenum format,
												GLenum type, const void *data)
{
	ClearNamedBufferDataEXT (obj, internalformat, format, type, data);
	CheckError ();
}

void Buffer::ClearSubData (GLenum internalformat, GLenum format,
													 GLenum type, GLsizeiptr offset,
													 GLsizeiptr size,
													 const void *data)
{
	ClearNamedBufferSubDataEXT (obj, internalformat, offset, size,
															format, type, data);
	CheckError ();
}

void Buffer::GetParameter (GLenum value, GLint *data) const
{
	GetNamedBufferParameterivEXT (obj, value, data);
	CheckError ();
}


void Buffer::swap (Buffer &buffer)
{
	std::swap (obj, buffer.obj);
}

GLuint Buffer::get (void) const
{
	return obj;
}

} /* namespace gl */
