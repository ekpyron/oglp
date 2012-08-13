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
#ifndef OGLP_FRAMEBUFFER_H
#define OGLP_FRAMEBUFFER_H

#include "common.h"
#include "texture.h"
#include "renderbuffer.h"
#include <vector>

namespace gl {

/** OpenGL framebuffer object.
 * A wrapper class around an OpenGL Framebuffer object.
 */
class Framebuffer
{
public:
	 /** Default constructor.
		* Creates a new Framebuffer object.
		*/
	 Framebuffer (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL Framebuffer object to
		* another framebuffer object.
		* \param framebuffer The Framebuffer object to move.
		*/
	 Framebuffer (Framebuffer &&framebuffer);
	 /**
		* Deleted copy constructor.
		* A Framebuffer object can't be copy constructed.
		*/
	 Framebuffer (const Framebuffer&) = delete;
	 /**
		* A destructor.
		* Deletes a Framebuffer object.
		*/
	 ~Framebuffer (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL framebuffer object to another
		* Framebuffer object.
		* \param framebuffer The Framebuffer object to move.
		* \return A reference to the Framebuffer object.
		*/
	 Framebuffer &operator= (Framebuffer &&framebuffer);
	 /**
		* Deleted copy assignment.
		* A Framebuffer object can't be copy assigned.
		* \return
		*/
	 Framebuffer &operator= (const Framebuffer&) = delete;
	 /**
		* Bind the Framebuffer object.
		* Binds the Framebuffer object to the specified target.
		* \param target Specifies which target to bind the Framebuffer object to.
		* \sa Unbind()
		*/
	 void Bind (GLenum target) const;
	 /**
		* Unbinds Framebuffers.
		* Unbinds any Framebuffer object potentially bound to the specified target.
		* \param target Specifies from which target Framebuffers should be unbound.
		* \sa Bind()
		*/
	 static void Unbind (GLenum target);
	 /**
		* Attach a texture object to the Framebuffer object.
		* Attach a level of a texture object as a logical buffer to the
		* Framebuffer object.
		* \param attachment Specifies the attachment point of the Framebuffer.
		*                   attachment must be one of the following:
		*                   - GL_COLOR_ATTACHMENTi
		*                   - GL_DEPTH_ATTACHMENT
		*                   - GL_STENCIL_ATTACHMENT
		*                   - GL_DEPTH_STENCIL_ATTACHMMENT
		* \param textarget Specifies what type of Texture is expected
		*                  in the texture parameter, or for cube map textures,
		*                  which face is to be attached.
		* \param texture Specifies the texture to be attached
		*                to the Framebuffer object.
		* \param level Specifies the mipmap level of texture to attach.
		* \sa Renderbuffer()
		*/
	 void Texture2D (GLenum attachment, GLenum textarget,
									 const Texture &texture, GLint level) const;
	 /**
		* Attach a layer of a texture array to the Framebuffer object.
		* Attach a layer of a texture array as a logical buffer to the
		* Framebuffer object.
		* \param attachment Specifies the attachment point of the Framebuffer.
		*                   attachment must be one of the following:
		*                   - GL_COLOR_ATTACHMENTi
		*                   - GL_DEPTH_ATTACHMENT
		*                   - GL_STENCIL_ATTACHMENT
		*                   - GL_DEPTH_STENCIL_ATTACHMMENT
		* \param texture Specifies the texture array to be attached
		*                to the Framebuffer object.
		* \param level Specifies the mipmap level of the texture layer to attach.
		* \param layer Specifies the layer of the texture array to attach.
		* \sa Renderbuffer() Texture2D()
		*/
	 void TextureLayer (GLenum attachment, const Texture &texture,
											GLint level, GLint layer) const;
	 /**
		* Attach a Renderbuffer to the Framebuffer object.
		* Attach a Renderbuffer as a logical buffer to the Framebuffer object.
		* \param attachment Specifies the attachment point of the Framebuffer.
		* \param renderbuffer Specifies the Renderbuffer object to attach.
		* \sa Texture2D()
		*/
	 void Renderbuffer (GLenum attachment,
											const Renderbuffer &renderbuffer) const;
	 /**
		* Specify buffers to draw to.
		* Specifies a list of color buffers to be drawn into.
		* \param bufs Points to an vector of symbolic constants
		*             specifying the buffers into which fragment
		*             colors or data values will be written.
		*/
	 void DrawBuffers (const std::vector<GLenum> &bufs) const;
	 /**
		* Set a named parameter.
		* Sets a named parameter of the internal OpenGL framebuffer
		* object.
		* \param pname A token indicating the parameter to be modified.
		* \param param The new value for the parameter named pname.
		*/
	 void Parameter (GLenum pname, GLint param) const;
	 /**
		* Return internal object.
		* Returns the internal OpenGL framebuffer object. Use with caution.
		* \return The internal OpenGL framebuffer object.
		*/
	 GLuint get (void) const;
	 /**
		* Swap internal object.
		* Swaps the internal OpenGL framebuffer object with another
		* gl::Framebuffer.
		* \param framebuffer Object with which to swap the internal object.
		*/
	 void swap (gl::Framebuffer &framebuffer);
private:
	 /**
		* internal OpenGL framebuffer object
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined OGLP_FRAMEBUFFER_H */
