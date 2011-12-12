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
#ifndef TEXTURE_H
#define TEXTURE_H

#include "common.h"

namespace gl {

/**
 * OpenGL texture object.
 * A wrapper class around an OpenGL Texture object.
 */
class Texture
{
public:
	 /**
		* Default constructor.
		* Creates a new Texture object.
		*/
	 Texture (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL texture object to another Texture object.
		*/
	 Texture (Texture &&texture);
	 /**
		* Deleted copy constructor.
		* A Texture object can't be copy constructed.
		*/
	 Texture (const Texture&) = delete;
	 /**
		* A destructor.
		* Deletes a Texture object.
		*/
	 ~Texture (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL texture object to another Texture object.
		*/
	 Texture &operator= (Texture &&texture);
	 /**
		* Deleted copy assignment.
		* A Texture object can't be copy assigned.
		*/
	 Texture &operator= (const Texture&) = delete;
	 /**
		* Bind the Texture object.
		* Binds the Texture object to the specified target and texture unit.
		* \param texunit Specifies the index of the texture unit to which to
		*                bind the sampler to.
		* \param target Specifies the target to which the texture is bound.
    *               Must be either
    *               GL_TEXTURE_1D,
    *               GL_TEXTURE_2D,
    *               GL_TEXTURE_3D, or
    *               GL_TEXTURE_1D_ARRAY,
    *               GL_TEXTURE_2D_ARRAY,
    *               GL_TEXTURE_RECTANGLE,
    *               GL_TEXTURE_CUBE_MAP,
    *               GL_TEXTURE_2D_MULTISAMPLE or
    *               GL_TEXTURE_2D_MULTISAMPLE_ARRAY.
		*/
	 void Bind (GLenum texunit, GLenum target) const;
	 /**
		* Specified a two-dimensional texture Image.
		* Loads a two-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D,
		*               GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		*               GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		*               GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
		*               GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		*               GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
		*               GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, or
		*               GL_PROXY_TEXTURE_CUBE_MAP.
		* \param level Specifies the level-of-detail number.
		*              Level 0 is the base image level.
		*              Level n is the nth mipmap reduction image.
		* \param internalFormat Specifies the number of color components
		*                       in the texture. Must be 1, 2, 3, or 4, or
		*                       one of the following symbolic constants:
		*                       GL_ALPHA, GL_ALPHA4, GL_ALPHA8, GL_ALPHA12,
		*                       GL_ALPHA16, GL_COMPRESSED_ALPHA,
		*                       GL_COMPRESSED_LUMINANCE,
		*                       GL_COMPRESSED_LUMINANCE_ALPHA,
		*                       GL_COMPRESSED_INTENSITY,
		*                       GL_COMPRESSED_RGB, GL_COMPRESSED_RGBA,
		*                       GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16,
		*                       GL_DEPTH_COMPONENT24, GL_DEPTH_COMPONENT32,
		*                       GL_LUMINANCE, GL_LUMINANCE4, GL_LUMINANCE8,
		*                       GL_LUMINANCE12, GL_LUMINANCE16, GL_LUMINANCE_ALPHA,
		*                       GL_LUMINANCE4_ALPHA4, GL_LUMINANCE6_ALPHA2,
		*                       GL_LUMINANCE8_ALPHA8, GL_LUMINANCE12_ALPHA4,
		*                       GL_LUMINANCE12_ALPHA12, GL_LUMINANCE16_ALPHA16,
		*                       GL_INTENSITY, GL_INTENSITY4, GL_INTENSITY8,
		*                       GL_INTENSITY12, GL_INTENSITY16, GL_R3_G3_B2,
		*                       GL_RGB, GL_RGB4, GL_RGB5, GL_RGB8, GL_RGB10,
		*                       GL_RGB12, GL_RGB16, GL_RGBA, GL_RGBA2, GL_RGBA4,
		*                       GL_RGB5_A1, GL_RGBA8, GL_RGB10_A2, GL_RGBA12,
		*                       GL_RGBA16, GL_SLUMINANCE, GL_SLUMINANCE8,
		*                       GL_SLUMINANCE_ALPHA, GL_SLUMINANCE8_ALPHA8,
		*                       GL_SRGB, GL_SRGB8, GL_SRGB_ALPHA,
		*                       or GL_SRGB8_ALPHA8.
		* \param width Specifies the width of the texture image including the
		*              border if any. If the GL version does not support
		*              non-power-of-two sizes, this value must be 2^n+2(border)
		*              for some integer n. All implementations support texture
		*              images that are at least 64 texels wide.
		* \param height Specifies the height of the texture image including the
		*               border if any. If the GL version does not support
		*               non-power-of-two sizes, this value must be 2^m+2(border)
		*               for some integer m. All implementations support texture
		*               images that are at least 64 texels high.
		* \param border Specifies the width of the border. Must be either 0 or 1.
		* \param format Specifies the format of the pixel data.
		*               The following symbolic values are accepted:
		*               GL_COLOR_INDEX, GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA,
		*               GL_RGB, GL_BGR, GL_RGBA,GL_BGRA, GL_LUMINANCE, and
		*               GL_LUMINANCE_ALPHA.
		* \param type Specifies the data type of the pixel data.
		*             The following symbolic values are accepted:
		*             GL_UNSIGNED_BYTE, GL_BYTE, GL_BITMAP, GL_UNSIGNED_SHORT,
		*             GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT,
		*             GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV,
		*             GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV,
		*             GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV,
		*             GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
		*             GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV,
		*             GL_UNSIGNED_INT_10_10_10_2,
		*             and GL_UNSIGNED_INT_2_10_10_10_REV.
		* \param data Specifies a pointer to the image data in memory.
		* \sa Image2D ()
		*/
	 void Image2D (GLenum target, GLint level, GLint internalFormat,
								 GLsizei width, GLsizei height, GLint border,
								 GLenum format, GLenum type, const GLvoid *data);
	 /**
		* Generate mipmaps.
		* Generates mipmaps for the internal texture object
		* and the specified texture target.
		* \param target Specifies the target to which the texture whose
		*               mimaps to generate is bound. target must be
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY or
		*               GL_TEXTURE_CUBE_MAP.
		*/
	 void GenerateMipmap (GLenum target);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be either
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, or GL_TEXTURE_CUBE_MAP.
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_BASE_LEVEL, GL_TEXTURE_COMPARE_FUNC,
		*              GL_TEXTURE_COMPARE_MODE, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_MAX_LOD,
		*              GL_TEXTURE_MAX_LEVEL, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_WRAP_S,
		*              GL_TEXTURE_WRAP_T, or GL_TEXTURE_WRAP_R.
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, GLint param);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be either
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, or GL_TEXTURE_CUBE_MAP.
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_BASE_LEVEL, GL_TEXTURE_BORDER_COLOR,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_LOD_BIAS, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_LOD,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_SWIZZLE_R, GL_TEXTURE_SWIZZLE_G,
		*              GL_TEXTURE_SWIZZLE_B, GL_TEXTURE_SWIZZLE_A,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T,
		*              or GL_TEXTURE_WRAP_R.
		* \param params Specifies the values of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, const GLint *params);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be either
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, or GL_TEXTURE_CUBE_MAP.
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_BASE_LEVEL, GL_TEXTURE_COMPARE_FUNC,
		*              GL_TEXTURE_COMPARE_MODE, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_MAX_LOD,
		*              GL_TEXTURE_MAX_LEVEL, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_WRAP_S,
		*              GL_TEXTURE_WRAP_T, or GL_TEXTURE_WRAP_R.
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, GLfloat param);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be either
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, or GL_TEXTURE_CUBE_MAP.
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_BASE_LEVEL, GL_TEXTURE_BORDER_COLOR,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_LOD_BIAS, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_LOD,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_SWIZZLE_R, GL_TEXTURE_SWIZZLE_G,
		*              GL_TEXTURE_SWIZZLE_B, GL_TEXTURE_SWIZZLE_A,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T,
		*              or GL_TEXTURE_WRAP_R.
		* \param params Specifies the values of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, const GLfloat *params);
private:
	 /** internal OpenGL texture object
		*/
	 GLuint obj;
	 friend class Framebuffer;
};

} /* namespace gl */

#endif /* !defined TEXTURE_H */
