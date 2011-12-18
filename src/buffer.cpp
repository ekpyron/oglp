/*
 * This file is part of glcp.
 *
 * glcp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glcp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glcp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "buffer.h"
#include <stdexcept>

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

void Buffer::Unmap (void) const
{
	UnmapNamedBufferEXT (obj);
	CheckError ();
}

GLuint Buffer::get (void) const
{
	return obj;
}

} /* namespace gl */
