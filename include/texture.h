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
#ifndef TEXTURE_H
#define TEXTURE_H

#include "common.h"
#include "buffer.h"

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
		* \param texture Texture object to move.
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
		* \param texture Texture object to move.
		* \return A reference to the Texture object.
		*/
	 Texture &operator= (Texture &&texture);
	 /**
		* Deleted copy assignment.
		* A Texture object can't be copy assigned.
		* \return
		*/
	 Texture &operator= (const Texture&) = delete;
	 /**
		* Bind the Texture object.
		* Binds the Texture object to the specified target and texture unit.
		* \param texunit Specifies the index of the texture unit to which to
		*                bind the sampler to.
		* \param target Specifies the target to which the texture is bound.
    *               Must be one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_RECTANGLE
		*               - GL_TEXTURE_CUBE_MAP
		*               - GL_TEXTURE_2D_MULTISAMPLE
		*               - GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		*/
	 void Bind (GLenum texunit, GLenum target) const;
	 /* Bind to an image unit.
		* Binds a level of a texture to an image unit
		* \param unit    Specifies the index of the image unit to which
		*                to bind the texture                
		* \param level   Specifies the level of the texture that is to be bound.
		* \param layered Specifies whether a layered texture binding is
		*                to be established.
		* \param layer   If layered is GL_FALSE, specifies the layer of texture
		*                to be bound to the image unit. Ignored otherwise.
		* \param access  Specifies a token indicating the type of access
		*                that will be performed on the image.
		* \param format  Specifies the format that the elements of the image
		*                will be treated as for the purposes of formatted stores.
		*/
	 void BindImage (GLuint unit, GLint level, GLboolean layered,
									 GLint layer, GLenum access, GLenum format) const;
	 /**
		* Specified a one-dimensional texture Image.
		* Loads a one-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_PROXY_TEXTURE_1D
		* \param level Specifies the level-of-detail number.
		*               - Level 0 is the base image level.
		*               - Level n is the nth mipmap reduction image.
		* \param internalFormat Specifies the number of color components
		*                       in the texture. The following values are
		*                       accepted:
		*                       - base internal formats
		*                         - GL_DEPTH_COMPONENT
		*                         - GL_DEPTH_STENCIL
		*                         - GL_RED
		*                         - GL_RG
		*                         - GL_RGB
		*                         - GL_RGB
		*                         - GL_RGBA
		*                       - sized internal formats
		*                         - GL_R8
		*                         - GL_R8_SNORM
		*                         - GL_R16
		*                         - GL_R16_SNORM
		*                         - GL_RG8
		*                         - GL_RG8_SNORM
		*                         - GL_RG16
		*                         - GL_RG16_SNORM
		*                         - GL_R3_G3_B2
		*                         - GL_RGB4
		*                         - GL_RGB5
		*                         - GL_RGB8
		*                         - GL_RGB8_SNORM
		*                         - GL_RGB10
		*                         - GL_RGB12
		*                         - GL_RGB16_SNORM
		*                         - GL_RGBA2
		*                         - GL_RGBA4
		*                         - GL_RGB5_A1
		*                         - GL_RGBA8
		*                         - GL_RGBA8_SNORM
		*                         - GL_RGB10_A2
		*                         - GL_RGB10_A2UI
		*                         - GL_RGBA12
		*                         - GL_RGBA16
		*                         - GL_SRGB8
		*                         - GL_SRGB8_ALPHA8
		*                         - GL_R16F
		*                         - GL_RG16F
		*                         - GL_RGB16F
		*                         - GL_RGBA16F
		*                         - GL_R32F
		*                         - GL_RG32F
		*                         - GL_RGB32F
		*                         - GL_RGBA32F
		*                         - GL_R11F_G11F_B10F
		*                         - GL_RGB9_E5
		*                         - GL_R8I
		*                         - GL_R8UI
		*                         - GL_R16I
		*                         - GL_R16UI
		*                         - GL_R32I
		*                         - GL_R32UI
		*                         - GL_RG8I
		*                         - GL_RG8UI
		*                         - GL_RG16I
		*                         - GL_RG16UI
		*                         - GL_RG32I
		*                         - GL_RG32UI
		*                         - GL_RGB8I
		*                         - GL_RGB8UI
		*                         - GL_RGB16I
		*                         - GL_RGB16UI
		*                         - GL_RGB32I
		*                         - GL_RGB32UI
		*                         - GL_RGBA8I
		*                         - GL_RGBA8UI
		*                         - GL_RGBA16I
		*                         - GL_RGBA16UI
		*                         - GL_RGBA32I
		*                         - GL_RGBA32UI
		*                       - compressed internal formats
		*                         - GL_COMPRESSED_RED
		*                         - GL_COMPRESSED_RG
		*                         - GL_COMPRESSED_RGB
		*                         - GL_COMPRESSED_RGBA
		*                         - GL_COMPRESSED_SRGB
		*                         - GL_COMPRESSED_SRGB_ALPHA
		*                         - GL_COMPRESSED_RED_RGTC1
		*                         - GL_COMPRESSED_SIGNED_RED_RGTC1
		*                         - GL_COMPRESSED_RG_RGTC2
		*                         - GL_COMPRESSED_SIGNED_RG_RGTC2
		*                         - GL_COMPRESSED_RGBA_BPTC_UNORM
		*                         - GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
		*                         - GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
		*                         - GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
		* \param width Specifies the width of the texture image including the
		*              border if any. If the GL version does not support
		*              non-power-of-two sizes, this value must be 2^n+2(border)
		*              for some integer n. All implementations support texture
		*              images that are at least 64 texels wide.
		* \param border This value must be 0.
		* \param format Specifies the format of the pixel data.
		*               The following symbolic values are accepted:
		*               - GL_RED
		*               - GL_RG
		*               - GL_RGB
		*               - GL_BGR
		*               - GL_RGBA
		*               - GL_BGRA
		* \param type Specifies the data type of the pixel data.
		*             The following symbolic values are accepted:
		*             - GL_UNSIGNED_BYTE
		*             - GL_BYTE
		*             - GL_UNSIGNED_SHORT
		*             - GL_SHORT
		*             - GL_UNSIGNED_INT
		*             - GL_INT
		*             - GL_FLOAT
		*             - GL_UNSIGNED_BYTE_3_3_2
		*             - GL_UNSIGNED_BYTE_2_3_3_REV
		*             - GL_UNSIGNED_SHORT_5_6_5
		*             - GL_UNSIGNED_SHORT_5_6_5_REV
		*             - GL_UNSIGNED_SHORT_4_4_4_4
		*             - GL_UNSIGNED_SHORT_4_4_4_4_REV
		*             - GL_UNSIGNED_SHORT_5_5_5_1
		*             - GL_UNSIGNED_SHORT_1_5_5_5_REV
		*             - GL_UNSIGNED_INT_8_8_8_8
		*             - GL_UNSIGNED_INT_8_8_8_8_REV
		*             - GL_UNSIGNED_INT_10_10_10_2
		*             - GL_UNSIGNED_INT_2_10_10_10_REV
		* \param data Specifies a pointer to the image data in memory.
		* \sa Image2D ()
		*/
	 void Image1D (GLenum target, GLint level, GLint internalFormat,
								 GLsizei width, GLint border, GLenum format, GLenum type,
								 const GLvoid *data);
	 /**
		* Specified a one-dimensional texture Image.
		* Loads a one-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_PROXY_TEXTURE_1D
		* \param level Specifies the level-of-detail number.
		*               - Level 0 is the base image level.
		*               - Level n is the nth mipmap reduction image.
		* \param internfalformat Specifies the format of the compressed
		*                        image data stored at address data.
		* \param width Specifies the width of the texture image.
		*              All implementations support texture images
		*              that are at least 64 texels wide.
		*              The height of the 1D texture image is 1.
		* \param border This value must be 0.
		* \param imageSize Specifies the number of unsigned bytes of image
		*                  data starting at the address specified by data.
		* \param data Specifies a pointer to the compressed image data in memory.
		* \sa Image1D ()
		*/
	 void CompressedImage1D (GLenum target, GLint level, GLenum internalFormat,
													 GLsizei width, GLint border, GLsizei imageSize,
													 const GLvoid *data);
	 /**
		* Specified a two-dimensional texture Image.
		* Loads a two-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_2D
		*               - GL_PROXY_TEXTURE_2D
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_X
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_X
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_Y
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_Z
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		*               - GL_PROXY_TEXTURE_CUBE_MAP
		* \param level Specifies the level-of-detail number.
		*              - Level 0 is the base image level.
		*              - Level n is the nth mipmap reduction image.
		* \param internalFormat Specifies the number of color components
		*                       in the texture. The following values are
		*                       accepted:
		*                       - base internal formats
		*                         - GL_DEPTH_COMPONENT
		*                         - GL_DEPTH_STENCIL
		*                         - GL_RED
		*                         - GL_RG
		*                         - GL_RGB
		*                         - GL_RGB
		*                         - GL_RGBA
		*                       - sized internal formats
		*                         - GL_R8
		*                         - GL_R8_SNORM
		*                         - GL_R16
		*                         - GL_R16_SNORM
		*                         - GL_RG8
		*                         - GL_RG8_SNORM
		*                         - GL_RG16
		*                         - GL_RG16_SNORM
		*                         - GL_R3_G3_B2
		*                         - GL_RGB4
		*                         - GL_RGB5
		*                         - GL_RGB8
		*                         - GL_RGB8_SNORM
		*                         - GL_RGB10
		*                         - GL_RGB12
		*                         - GL_RGB16_SNORM
		*                         - GL_RGBA2
		*                         - GL_RGBA4
		*                         - GL_RGB5_A1
		*                         - GL_RGBA8
		*                         - GL_RGBA8_SNORM
		*                         - GL_RGB10_A2
		*                         - GL_RGB10_A2UI
		*                         - GL_RGBA12
		*                         - GL_RGBA16
		*                         - GL_SRGB8
		*                         - GL_SRGB8_ALPHA8
		*                         - GL_R16F
		*                         - GL_RG16F
		*                         - GL_RGB16F
		*                         - GL_RGBA16F
		*                         - GL_R32F
		*                         - GL_RG32F
		*                         - GL_RGB32F
		*                         - GL_RGBA32F
		*                         - GL_R11F_G11F_B10F
		*                         - GL_RGB9_E5
		*                         - GL_R8I
		*                         - GL_R8UI
		*                         - GL_R16I
		*                         - GL_R16UI
		*                         - GL_R32I
		*                         - GL_R32UI
		*                         - GL_RG8I
		*                         - GL_RG8UI
		*                         - GL_RG16I
		*                         - GL_RG16UI
		*                         - GL_RG32I
		*                         - GL_RG32UI
		*                         - GL_RGB8I
		*                         - GL_RGB8UI
		*                         - GL_RGB16I
		*                         - GL_RGB16UI
		*                         - GL_RGB32I
		*                         - GL_RGB32UI
		*                         - GL_RGBA8I
		*                         - GL_RGBA8UI
		*                         - GL_RGBA16I
		*                         - GL_RGBA16UI
		*                         - GL_RGBA32I
		*                         - GL_RGBA32UI
		*                       - compressed internal formats
		*                         - GL_COMPRESSED_RED
		*                         - GL_COMPRESSED_RG
		*                         - GL_COMPRESSED_RGB
		*                         - GL_COMPRESSED_RGBA
		*                         - GL_COMPRESSED_SRGB
		*                         - GL_COMPRESSED_SRGB_ALPHA
		*                         - GL_COMPRESSED_RED_RGTC1
		*                         - GL_COMPRESSED_SIGNED_RED_RGTC1
		*                         - GL_COMPRESSED_RG_RGTC2
		*                         - GL_COMPRESSED_SIGNED_RG_RGTC2
		*                         - GL_COMPRESSED_RGBA_BPTC_UNORM
		*                         - GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
		*                         - GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
		*                         - GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
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
		*               - GL_RED
		*               - GL_RG
		*               - GL_RGB
		*               - GL_BGR
		*               - GL_RGBA
		*               - GL_BGRA
		* \param type Specifies the data type of the pixel data.
		*             The following symbolic values are accepted:
		*             - GL_UNSIGNED_BYTE
		*             - GL_BYTE
		*             - GL_UNSIGNED_SHORT
		*             - GL_SHORT
		*             - GL_UNSIGNED_INT
		*             - GL_INT
		*             - GL_FLOAT
		*             - GL_UNSIGNED_BYTE_3_3_2
		*             - GL_UNSIGNED_BYTE_2_3_3_REV
		*             - GL_UNSIGNED_SHORT_5_6_5
		*             - GL_UNSIGNED_SHORT_5_6_5_REV
		*             - GL_UNSIGNED_SHORT_4_4_4_4
		*             - GL_UNSIGNED_SHORT_4_4_4_4_REV
		*             - GL_UNSIGNED_SHORT_5_5_5_1
		*             - GL_UNSIGNED_SHORT_1_5_5_5_REV
		*             - GL_UNSIGNED_INT_8_8_8_8
		*             - GL_UNSIGNED_INT_8_8_8_8_REV
		*             - GL_UNSIGNED_INT_10_10_10_2
		*             - GL_UNSIGNED_INT_2_10_10_10_REV
		* \param data Specifies a pointer to the image data in memory.
		* \sa Image2D ()
		*/
	 void Image2D (GLenum target, GLint level, GLint internalFormat,
								 GLsizei width, GLsizei height, GLint border,
								 GLenum format, GLenum type, const GLvoid *data);
	 /**
		* Specified a two-dimensional texture Image.
		* Loads a two-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_2D
		*               - GL_PROXY_TEXTURE_2D
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_X
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_X
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_Y
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
		*               - GL_TEXTURE_CUBE_MAP_POSITIVE_Z
		*               - GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		*               - GL_PROXY_TEXTURE_CUBE_MAP
		* \param level Specifies the level-of-detail number.
		*               - Level 0 is the base image level.
		*               - Level n is the nth mipmap reduction image.
		* \param internfalformat Specifies the format of the compressed
		*                        image data stored at address data.
		* \param width Specifies the width of the texture image.
		*              All implementations support 2D texture images
		*              that are at least 64 texels wide and cube-mapped
		*              texture images that are at least 16 texels wide.
		* \param height Specifies the height of the texture image.
		*               All implementations support 2D texture images
		*               that are at least 64 texels high and cube-mapped
		*               texture images that are at least 16 texels high.
		* \param border This value must be 0.
		* \param imageSize Specifies the number of unsigned bytes of image
		*                  data starting at the address specified by data.
		* \param data Specifies a pointer to the compressed image data in memory.
		* \sa Image2D ()
		*/
	 void CompressedImage2D (GLenum target, GLint level, GLenum internalFormat,
													 GLsizei width, GLsizei height, GLint border,
													 GLsizei imageSize, const GLvoid *data);
	 /**
		* Specified a three-dimensional texture Image.
		* Loads a three-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_3D
		*               - GL_PROXY_TEXTURE_3D
		*               - GL_TEXTURE_2D_ARRAY
		* \param level Specifies the level-of-detail number.
		*              - Level 0 is the base image level.
		*              - Level n is the nth mipmap reduction image.
		* \param internalFormat Specifies the number of color components
		*                       in the texture. The following values are
		*                       accepted:
		*                       - base internal formats
		*                         - GL_DEPTH_COMPONENT
		*                         - GL_DEPTH_STENCIL
		*                         - GL_RED
		*                         - GL_RG
		*                         - GL_RGB
		*                         - GL_RGB
		*                         - GL_RGBA
		*                       - sized internal formats
		*                         - GL_R8
		*                         - GL_R8_SNORM
		*                         - GL_R16
		*                         - GL_R16_SNORM
		*                         - GL_RG8
		*                         - GL_RG8_SNORM
		*                         - GL_RG16
		*                         - GL_RG16_SNORM
		*                         - GL_R3_G3_B2
		*                         - GL_RGB4
		*                         - GL_RGB5
		*                         - GL_RGB8
		*                         - GL_RGB8_SNORM
		*                         - GL_RGB10
		*                         - GL_RGB12
		*                         - GL_RGB16_SNORM
		*                         - GL_RGBA2
		*                         - GL_RGBA4
		*                         - GL_RGB5_A1
		*                         - GL_RGBA8
		*                         - GL_RGBA8_SNORM
		*                         - GL_RGB10_A2
		*                         - GL_RGB10_A2UI
		*                         - GL_RGBA12
		*                         - GL_RGBA16
		*                         - GL_SRGB8
		*                         - GL_SRGB8_ALPHA8
		*                         - GL_R16F
		*                         - GL_RG16F
		*                         - GL_RGB16F
		*                         - GL_RGBA16F
		*                         - GL_R32F
		*                         - GL_RG32F
		*                         - GL_RGB32F
		*                         - GL_RGBA32F
		*                         - GL_R11F_G11F_B10F
		*                         - GL_RGB9_E5
		*                         - GL_R8I
		*                         - GL_R8UI
		*                         - GL_R16I
		*                         - GL_R16UI
		*                         - GL_R32I
		*                         - GL_R32UI
		*                         - GL_RG8I
		*                         - GL_RG8UI
		*                         - GL_RG16I
		*                         - GL_RG16UI
		*                         - GL_RG32I
		*                         - GL_RG32UI
		*                         - GL_RGB8I
		*                         - GL_RGB8UI
		*                         - GL_RGB16I
		*                         - GL_RGB16UI
		*                         - GL_RGB32I
		*                         - GL_RGB32UI
		*                         - GL_RGBA8I
		*                         - GL_RGBA8UI
		*                         - GL_RGBA16I
		*                         - GL_RGBA16UI
		*                         - GL_RGBA32I
		*                         - GL_RGBA32UI
		*                       - compressed internal formats
		*                         - GL_COMPRESSED_RED
		*                         - GL_COMPRESSED_RG
		*                         - GL_COMPRESSED_RGB
		*                         - GL_COMPRESSED_RGBA
		*                         - GL_COMPRESSED_SRGB
		*                         - GL_COMPRESSED_SRGB_ALPHA
		*                         - GL_COMPRESSED_RED_RGTC1
		*                         - GL_COMPRESSED_SIGNED_RED_RGTC1
		*                         - GL_COMPRESSED_RG_RGTC2
		*                         - GL_COMPRESSED_SIGNED_RG_RGTC2
		*                         - GL_COMPRESSED_RGBA_BPTC_UNORM
		*                         - GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
		*                         - GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
		*                         - GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
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
		* \param depth Specifies the depth of the texture image including the 
		*              border if any. If the GL version does not support
		*              non-power-of-two sizes, this value must be 2^k + 2(border)
		*              for some integer k. All implementations support 3D texture
		*              images that are at least 16 texels deep.
		* \param border Specifies the width of the border. Must be either 0 or 1.
		* \param format Specifies the format of the pixel data.
		*               The following symbolic values are accepted:
		*               - GL_RED
		*               - GL_RG
		*               - GL_RGB
		*               - GL_BGR
		*               - GL_RGBA
		*               - GL_BGRA
		* \param type Specifies the data type of the pixel data.
		*             The following symbolic values are accepted:
		*             - GL_UNSIGNED_BYTE
		*             - GL_BYTE
		*             - GL_UNSIGNED_SHORT
		*             - GL_SHORT
		*             - GL_UNSIGNED_INT
		*             - GL_INT
		*             - GL_FLOAT
		*             - GL_UNSIGNED_BYTE_3_3_2
		*             - GL_UNSIGNED_BYTE_2_3_3_REV
		*             - GL_UNSIGNED_SHORT_5_6_5
		*             - GL_UNSIGNED_SHORT_5_6_5_REV
		*             - GL_UNSIGNED_SHORT_4_4_4_4
		*             - GL_UNSIGNED_SHORT_4_4_4_4_REV
		*             - GL_UNSIGNED_SHORT_5_5_5_1
		*             - GL_UNSIGNED_SHORT_1_5_5_5_REV
		*             - GL_UNSIGNED_INT_8_8_8_8
		*             - GL_UNSIGNED_INT_8_8_8_8_REV
		*             - GL_UNSIGNED_INT_10_10_10_2
		*             - GL_UNSIGNED_INT_2_10_10_10_REV
		* \param data Specifies a pointer to the image data in memory.
		* \sa Image2D ()
		*/
	 void Image3D (GLenum target, GLint level, GLint internalFormat,
								 GLsizei width, GLsizei height, GLsizei depth, GLint border,
								 GLenum format, GLenum type, const GLvoid *data);
	 /**
		* Specified a three-dimensional texture Image.
		* Loads a three-dimensional texture image from memory to the
		* internal OpenGL texture object.
		* \param target Specifies the target texture.
		*               Must be one of the following:
		*               - GL_TEXTURE_3D
		*               - GL_PROXY_TEXTURE_3D
		*               - GL_TEXTURE_2D_ARRAY
		* \param level Specifies the level-of-detail number.
		*               - Level 0 is the base image level.
		*               - Level n is the nth mipmap reduction image.
		* \param internfalformat Specifies the format of the compressed
		*                        image data stored at address data.
		* \param width Specifies the width of the texture image.
		*              All implementations support 3D texture images
		*              that are at least 16 texels wide.
		* \param height Specifies the height of the texture image.
		*               All implementations support 3D texture images
		*               that are at least 16 texels high.
		* \param depth Specifies the depth of the texture image.
		*              All implementations support 3D texture images
		*              that are at least 16 texels deep.
		* \param border This value must be 0.
		* \param imageSize Specifies the number of unsigned bytes of image
		*                  data starting at the address specified by data.
		* \param data Specifies a pointer to the compressed image data in memory.
		* \sa Image3D ()
		*/
	 void CompressedImage3D (GLenum target, GLint level, GLenum internalFormat,
													 GLsizei width, GLsizei height, GLsizei depth,
													 GLint border, GLsizei imageSize,
													 const GLvoid *data);
	 /**
		* Specified a two-dimensional multisample texture image.
		* Establish the data storage, format, dimensions, and number
		* of samples of a multisample texture's image.
		* \param target Specifies the target of the operation.
		*               target must be GL_TEXTURE_2D_MULTISAMPLE.
		* \param samples The number of samples in the multisample
		*                texture's image.
		* \param width The width of the multisample texture's image, in texels.
		* \param height The height of the multisample texture's image, in texels.
		* \param fixedsamplelocations Specifies whether the image will use
		*                             identical sample locations and the same
		*                             number of samples for all texels in the
		*                             image, and the sample locations will not
		*                             depend on the internal format or size of
		*                             the image.
		*/
	 void Image2DMultisample (GLenum target, GLsizei samples,
														GLint internalFormat, GLsizei width,
														GLsizei height, GLboolean fixedsamplelocation);
	 /**
		* Specified a two-dimensional multisample texture image.
		* Establish the data storage, format, dimensions, and number
		* of samples of a multisample texture's image.
		* \param target Specifies the target of the operation.
		*               target must be GL_TEXTURE_2D_MULTISAMPLE_ARRAY.
		* \param samples The number of samples in the multisample
		*                texture's image.
		* \param width The width of the multisample texture's image, in texels.
		* \param height The height of the multisample texture's image, in texels.
		* \param depth Specifies the number of layers in the multisample texture
		*              array.
		* \param fixedsamplelocations Specifies whether the image will use
		*                             identical sample locations and the same
		*                             number of samples for all texels in the
		*                             image, and the sample locations will not
		*                             depend on the internal format or size of
		*                             the image.
		*/
	 void Image3DMultisample (GLenum target, GLsizei samples,
														GLint internalFormat, GLsizei width,
														GLsizei height, GLsizei depth,
														GLboolean fixedsamplelocation);
	 /**
		* Attach a buffer object to the texture.
		* Attaches the storage for a buffer object to the buffer texture.
		* \param internalFormat Specifies the internal format of the data in the
		*                       store belonging to the buffer.
		* \param buffer Specifies the buffer object whose storage to attach to
		*               the active buffer texture.
		*/
	 void Buffer (GLenum internalFormat, const gl::Buffer &buffer);
	 /**
		* Return a texture image.
		* Returns data from the internal texture object.
		* \param target Specifies the texture target from which to obtain
		*               the data. target must be one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_CUBE_MAP
		* \param level Specifies the level-of-detail number.
		*               - Level 0 is the base image level.
		*               - Level n is the nth mipmap reduction image.
		* \param format Specifies the pixel format for the returned data.
		*               The following symbolic values are accepted:
		*               - GL_STENCIL_INDEX
		*               - GL_DEPTH_COMPONENT
		*               - GL_DEPTH_STENCIL
		*               - GL_RED
		*               - GL_GREEN
		*               - GL_BLUE
		*               - GL_RG
		*               - GL_RGB
		*               - GL_BGR
		*               - GL_RGBA
		*               - GL_BGRA
		*               - GL_RED_INTEGER
		*               - GL_GREEN_INTEGER
		*               - GL_BLUE_INTEGER
		*               - GL_RG_INTEGER
		*               - GL_RGB_INTEGER
		*               - GL_BGR_INTEGER
		*               - GL_RGBA_INTEGER
		*               - GL_BGRA_INTEGER
		* \param img Returns the texture image. Should be a pointer to an array
		*            of the type specified by type.
		*/
	 void GetTexImage (GLenum target, GLint level, GLenum format, GLenum type,
										 GLvoid *img);
	 /**
		* Generate mipmaps.
		* Generates mipmaps for the internal texture object
		* and the specified texture target.
		* \param target Specifies the target to which the texture whose
		*               mimaps to generate is bound. target must be one
		*               of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_CUBE_MAP
		*/
	 void GenerateMipmap (GLenum target) const;
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must
		*               be one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_RECTANGLE
		*               - GL_TEXTURE_CUBE_MAP
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_BASE_LEVEL
		*              - GL_TEXTURE_COMPARE_FUNC
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_MAX_LEVEL
		*              - GL_TEXTURE_SWIZZLE_R
		*              - GL_TEXTURE_SWIZZLE_G
		*              - GL_TEXTURE_SWIZZLE_B
		*              - GL_TEXTURE_SWIZZLE_A
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_Ry
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, GLint param);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be
		*               one of the following.
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_RECTANGLE
		*               - GL_TEXTURE_CUBE_MAP
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_BASE_LEVEL
		*              - GL_TEXTURE_BORDER_COLOR
		*              - GL_TEXTURE_COMPARE_FUNC
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_MAX_LEVEL
		*              - GL_TEXTURE_SWIZZLE_R
		*              - GL_TEXTURE_SWIZZLE_G
		*              - GL_TEXTURE_SWIZZLE_B
		*              - GL_TEXTURE_SWIZZLE_A
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - or GL_TEXTURE_WRAP_R
		* \param params Specifies the values of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, const GLint *params);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be
		*               one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_RECTANGLE
		*               - GL_TEXTURE_CUBE_MAP
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_BASE_LEVEL
		*              - GL_TEXTURE_COMPARE_FUNC
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_MAX_LEVEL
		*              - GL_TEXTURE_SWIZZLE_R
		*              - GL_TEXTURE_SWIZZLE_G
		*              - GL_TEXTURE_SWIZZLE_B
		*              - GL_TEXTURE_SWIZZLE_A
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, GLfloat param);
	 /**
		* Set texture parameters.
		* Set texture parameters.
		* \param target Specifies the target texture, which must be
		*               one of the following:
		*               - GL_TEXTURE_1D
		*               - GL_TEXTURE_2D
		*               - GL_TEXTURE_3D
		*               - GL_TEXTURE_1D_ARRAY
		*               - GL_TEXTURE_2D_ARRAY
		*               - GL_TEXTURE_RECTANGLE
		*               - GL_TEXTURE_CUBE_MAP
		* \param pname Specifies the symbolic name of a single-valued texture
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_BASE_LEVEL
		*              - GL_TEXTURE_BORDER_COLOR
		*              - GL_TEXTURE_COMPARE_FUNC
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_MAX_LEVEL
		*              - GL_TEXTURE_SWIZZLE_R
		*              - GL_TEXTURE_SWIZZLE_G
		*              - GL_TEXTURE_SWIZZLE_B
		*              - GL_TEXTURE_SWIZZLE_A
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		* \param params Specifies the values of pname.
		*/
	 void Parameter (GLenum target, GLenum pname, const GLfloat *params);
	 /**
		* Return internal object.
		* Returns the internal OpenGL texture object. Use with caution.
		* \return The internal OpenGL texture object.
		*/
	 GLuint get (void) const;
   /**
		* Swap internal object.
		* Swaps the internal OpenGL texture object with another gl::Texture.
		* \param sampler Object with which to swap the internal texture object.
		*/
	 void swap (Texture &texture);
private:
	 /** internal OpenGL texture object
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined TEXTURE_H */
