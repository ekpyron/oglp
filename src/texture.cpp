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

GLuint Texture::get (void) const
{
	return obj;
}

} /* namespace gl */
