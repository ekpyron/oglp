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
#include "vertexarray.h"

namespace gl {

VertexArray::VertexArray (void)
{
	GenVertexArrays (1, &obj);
	CheckError ();
}

VertexArray::VertexArray (VertexArray &&va) : obj (va.obj)
{
	GenVertexArrays (1, &va.obj);
	CheckError ();
}

VertexArray::~VertexArray (void)
{
	DeleteVertexArrays (1, &obj);
	CheckError ();
}

VertexArray &VertexArray::operator= (VertexArray &&va)
{
	obj = va.obj;
	GenVertexArrays (1, &va.obj);
	CheckError ();
}

void VertexArray::Bind (void) const
{
	BindVertexArray (obj);
	CheckError ();
}

void VertexArray::VertexAttribOffset (const Buffer &buffer, GLuint index,
																			GLint size, GLenum type,
																			GLboolean normalized,
																			GLsizei stride, GLintptr offset)
{
	VertexArrayVertexAttribOffsetEXT (obj, buffer.get (), index, size,
																		type, normalized, stride, offset);
	CheckError ();
}

void VertexArray::EnableVertexAttrib (GLuint index)
{
	EnableVertexArrayAttribEXT (obj, index);
	CheckError ();
}

void VertexArray::DisableVertexAttrib (GLuint index)
{
	DisableVertexArrayAttribEXT (obj, index);
	CheckError ();
}

GLuint VertexArray::get (void) const
{
	return obj;
}

} /* namespace gl */
