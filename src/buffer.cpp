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
#include "buffer.h"
#include <stdexcept>

namespace gl {

Buffer::Buffer (void)
{
	GenBuffers (1, &obj);
	GLP_CHECK_ERROR;
}

Buffer::Buffer (Buffer &&buffer)
	: obj (buffer.obj)
{
	GenBuffers (1, &buffer.obj);
	GLP_CHECK_ERROR;
}

Buffer::~Buffer (void)
{
	DeleteBuffers (1, &obj);
	GLP_CHECK_ERROR;
}

Buffer &Buffer::operator= (Buffer &&buffer)
{
	obj = buffer.obj;
	GenBuffers (1, &buffer.obj);
	GLP_CHECK_ERROR;
}

void Buffer::Bind (GLenum target) const
{
	BindBuffer (target, obj);
	GLP_CHECK_ERROR;
}

void Buffer::Unbind (GLenum target)
{
	BindBuffer (target, 0);
	GLP_CHECK_ERROR;
}

void Buffer::Data (GLsizeiptr size, const GLvoid *data,
									 GLenum usage) const
{
	NamedBufferDataEXT (obj, size, data, usage);
	GLP_CHECK_ERROR;
}

void Buffer::SubData (GLintptr offset, GLsizeiptr size,
											const GLvoid *data) const
{
	NamedBufferSubDataEXT (obj, offset, size, data);
	GLP_CHECK_ERROR;
}

GLvoid *Buffer::Map (GLenum access) const
{
	GLvoid *ptr;
	ptr = MapNamedBufferEXT (obj, access);
	GLP_CHECK_ERROR;
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
	GLP_CHECK_ERROR;
}

} /* namespace gl */
