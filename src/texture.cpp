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
#include "texture.h"
#include <algorithm>

namespace gl {

Texture::Texture (void)
{
	GenTextures (1, &obj);
	CheckError ();
}

Texture::Texture (Texture &&texture) : obj (texture.obj)
{
	GenTextures (1, &texture.obj);
	CheckError ();
}

Texture::~Texture (void)
{
	DeleteTextures (1, &obj);
	CheckError ();
}

Texture &Texture::operator= (Texture &&texture)
{
	obj = texture.obj;
	GenTextures (1, &texture.obj);
	CheckError ();
}

void Texture::Bind (GLenum texunit, GLenum target) const
{
	BindMultiTextureEXT (texunit, target, obj);
	CheckError ();
}

void Texture::Image2D (GLenum target, GLint level, GLint internalFormat,
											 GLsizei width, GLsizei height, GLint border,
											 GLenum format, GLenum type, const GLvoid *data)
{
	TextureImage2DEXT (obj, target, level, internalFormat, width, height,
										 border, format, type, data);
	CheckError ();
}

void Texture::Image3D (GLenum target, GLint level, GLint internalFormat,
											 GLsizei width, GLsizei height, GLsizei depth,
											 GLint border, GLenum format, GLenum type,
											 const GLvoid *data)
{
	TextureImage3DEXT (obj, target, level, internalFormat, width, height,
										 depth, border, format, type, data);
	CheckError ();
}

void Texture::Image2DMultisample (GLenum target, GLsizei samples,
																	GLint internalFormat, GLsizei width,
																	GLsizei height,
																	GLboolean fixedsamplelocation)
{
	GLint previous;
	if (target == GL_TEXTURE_2D_MULTISAMPLE)
		GetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE, &previous);
	else
		 throw Exception (GL_INVALID_VALUE);

	BindTexture (target, obj);
	TexImage2DMultisample (target, samples, internalFormat, width, height,
												 fixedsamplelocation);
	BindTexture (target, previous);
}

void Texture::Image3DMultisample (GLenum target, GLsizei samples,
																	GLint internalFormat, GLsizei width,
																	GLsizei height, GLsizei depth,
																	GLboolean fixedsamplelocation)
{
	GLint previous;
	if (target == GL_TEXTURE_2D_MULTISAMPLE_ARRAY)
		GetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &previous);
	else
		 throw Exception (GL_INVALID_VALUE);

	BindTexture (target, obj);
	TexImage3DMultisample (target, samples, internalFormat, width, height,
												 depth, fixedsamplelocation);
	BindTexture (target, previous);
}


void Texture::Buffer (GLenum internalFormat, const gl::Buffer &buffer)
{
	TextureBufferEXT (obj, GL_TEXTURE_BUFFER, internalFormat, buffer.get ());
	CheckError ();
}

void Texture::GetTexImage (GLenum target, GLint level, GLenum format,
													 GLenum type, GLvoid *img)
{
	GetTextureImageEXT (obj, target, level, format, type, img);
	CheckError ();
}

void Texture::GenerateMipmap (GLenum target)
{
	GenerateTextureMipmapEXT (obj, target);
	CheckError ();
}

void Texture::Parameter (GLenum target, GLenum pname, GLfloat param)
{
	TextureParameterfEXT (obj, target, pname, param);
	CheckError ();
}

void Texture::Parameter (GLenum target, GLenum pname, GLint param)
{
	TextureParameteriEXT (obj, target, pname, param);
	CheckError ();
}

void Texture::Parameter (GLenum target, GLenum pname, const GLfloat *params)
{
	TextureParameterfvEXT (obj, target, pname, params);
	CheckError ();
}

void Texture::Parameter (GLenum target, GLenum pname, const GLint *params)
{
	TextureParameterivEXT (obj, target, pname, params);
	CheckError ();
}

void Texture::swap (gl::Texture &texture)
{
	std::swap (obj, texture.obj);
}

GLuint Texture::get (void) const
{
	return obj;
}

} /* namespace gl */
