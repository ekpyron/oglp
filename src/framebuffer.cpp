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
#include "framebuffer.h"

namespace gl {

Framebuffer::Framebuffer (void)
{
	GenFramebuffers (1, &obj);
	CheckError ();
}

Framebuffer::Framebuffer (Framebuffer &&framebuffer)
	: obj (framebuffer.obj)
{
	GenFramebuffers (1, &framebuffer.obj);
	CheckError ();
}

Framebuffer::~Framebuffer (void)
{
	DeleteFramebuffers (1, &obj);
	CheckError ();
}

Framebuffer &Framebuffer::operator= (Framebuffer &&framebuffer)
{
	obj = framebuffer.obj;
	GenFramebuffers (1, &framebuffer.obj);
	CheckError ();
}

void Framebuffer::Bind (GLenum target) const
{
	BindFramebuffer (target, obj);
	CheckError ();
}

void Framebuffer::Unbind (GLenum target)
{
	BindFramebuffer (target, 0);
	CheckError ();
}

void Framebuffer::Texture2D (GLenum attachment, GLenum textarget,
														 const Texture &texture, GLint level) const
{
	NamedFramebufferTexture2DEXT (obj, attachment, textarget,
																texture.get (), level);
	CheckError ();
}

void Framebuffer::Renderbuffer (GLenum attachment,
																const gl::Renderbuffer &renderbuffer) const
{
	NamedFramebufferRenderbufferEXT (obj, attachment, GL_RENDERBUFFER,
																	 renderbuffer.get ());
	CheckError ();
}

void Framebuffer::DrawBuffers (const std::vector<GLenum> &bufs) const
{
	FramebufferDrawBuffersEXT (obj, bufs.size (), &bufs[0]);
	CheckError ();
}

GLuint Framebuffer::get (void) const
{
	return obj;
}

} /* namespace gl */
