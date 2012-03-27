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
#include "renderbuffer.h"
#include <algorithm>

namespace gl {

Renderbuffer::Renderbuffer (void)
{
	GenRenderbuffers (1, &obj);
	CheckError ();
}

Renderbuffer::Renderbuffer (Renderbuffer &&renderbuffer)
	: obj (renderbuffer.obj)
{
	GenRenderbuffers (1, &renderbuffer.obj);
	CheckError ();
}

Renderbuffer::~Renderbuffer (void)
{
	DeleteRenderbuffers (1, &obj);
	CheckError ();
}

Renderbuffer &Renderbuffer::operator= (Renderbuffer &&renderbuffer)
{
	obj = renderbuffer.obj;
	GenRenderbuffers (1, &renderbuffer.obj);
	CheckError ();
}

void Renderbuffer::Storage (GLenum internalformat, GLsizei width,
														GLsizei height) const
{
	NamedRenderbufferStorageEXT (obj, internalformat, width, height);
	CheckError ();
}

void Renderbuffer::swap (Renderbuffer &renderbuffer)
{
	std::swap (obj, renderbuffer.obj);
}

GLuint Renderbuffer::get (void) const
{
	return obj;
}

} /* namespace gl */
