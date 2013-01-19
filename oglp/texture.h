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

namespace oglp {

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
	 Texture (void) {
		 GenTextures (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL texture object to another Texture object.
		* \param texture Texture object to move.
		*/
	 Texture (Texture &&texture) : obj (texture.obj) {
		 GenTextures (1, &texture.obj);
		 CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A Texture object can't be copy constructed.
		*/
	 Texture (const Texture&) = delete;
	 /**
		* A destructor.
		* Deletes a Texture object.
		*/
	 ~Texture (void) {
		 DeleteTextures (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move assignment.
		* Passes the internal OpenGL texture object to another Texture object.
		* \param texture Texture object to move.
		* \return A reference to the Texture object.
		*/
	 Texture &operator= (Texture &&texture) {
		 obj = texture.obj;
		 GenTextures (1, &texture.obj);
		 CheckError ();
	 }
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
	 void Bind (GLenum texunit, GLenum target) const {
		 BindMultiTextureEXT (texunit, target, obj);
		 CheckError ();
	 }
	 /** Bind to an image unit.
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
									 GLint layer, GLenum access, GLenum format) const {
		 BindImageTexture (unit, obj, level, layered, layer, access, format);
		 CheckError ();
	 }
	 /** Specify one-dimensional texture storage.
		* Simultaneously specify storage for all levels of a
		* one-dimensional texture.
		* \param target Specify the target of the operation.
		*               target must be either
		*               GL_TEXTURE_1D or GL_PROXY_TEXTURE_1D.
		* \param levels Specify the number of texture levels.
		* \param internalformat Specifies the sized internal format to
		*                       be used to store texture image data.
		* \param width Specifies the width of the texture, in texels.
		*/
	 void Storage1D (GLenum target, GLsizei levels,
									 GLenum internalformat, GLsizei width)
	 {
		 TextureStorage1DEXT (obj, target, levels, internalformat, width);
		 CheckError ();
	 }
	 /**
		* Specify two-dimensional texture storage.
		* Simultaneously specify storage for all levels of a
		* two-dimensional or one-dimensional array texture.
		* \param target Specify the target of the operation.
		*               target must be one of
		*               GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_PROXY_TEXTURE_1D_ARRAY, GL_TEXTURE_RECTANGLE,
		*               GL_PROXY_TEXTURE_RECTANGLE, or GL_PROXY_TEXTURE_CUBE_MAP.
		* \param levels Specify the number of texture levels.
		* \param internalformat Specifies the sized internal format to
		*                       be used to store texture image data.
		* \param width Specifies the width of the texture, in texels.
		* \param height Specifies the height of the texture, in texels.
		*/
	 void Storage2D (GLenum target, GLsizei levels,
									 GLenum internalformat,
									 GLsizei width, GLsizei height)
	 {
		 TextureStorage2DEXT (obj, target, levels, internalformat, width, height);
		 CheckError ();
	 }
	 /**
		* Specify three-dimensional texture storage.
		* Simultaneously specify storage for all levels of a
		* three-dimensional, two-dimensional array or cube-map array texture.
		* \param target Specify the target of the operation.
		*               target must be one of
		*               GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_PROXY_TEXTURE_1D_ARRAY, GL_TEXTURE_RECTANGLE,
		*               GL_PROXY_TEXTURE_RECTANGLE, or GL_PROXY_TEXTURE_CUBE_MAP.
		* \param levels Specify the number of texture levels.
		* \param internalformat Specifies the sized internal format to
		*                       be used to store texture image data.
		* \param width Specifies the width of the texture, in texels.
		* \param height Specifies the height of the texture, in texels.
		* \param depth Specifies the depth of the texture, in texels.
		*/
	 void Storage3D (GLenum target, GLsizei levels,
									 GLenum internalformat, GLsizei width,
									 GLsizei height, GLsizei depth)
	 {
		 TextureStorage3DEXT (obj, target, levels, internalformat,
													width, height, depth);
		 CheckError ();
	 }
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
								 const GLvoid *data) {
		 TextureImage1DEXT (obj, target, level, internalFormat, width,
												border, format, type, data);
		 CheckError ();
	 }
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
		* \param internalFormat Specifies the format of the compressed
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
													 const GLvoid *data) {
		 CompressedTextureImage1DEXT (obj, target, level, internalFormat, width,
																	border, imageSize, data);
		 CheckError ();
	 }
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
								 GLenum format, GLenum type, const GLvoid *data) {
		 TextureImage2DEXT (obj, target, level, internalFormat, width, height,
												border, format, type, data);
		 CheckError ();
	 }
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
		* \param internalFormat Specifies the format of the compressed
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
													 GLsizei imageSize, const GLvoid *data) {
		 CompressedTextureImage2DEXT (obj, target, level, internalFormat, width,
																	height, border, imageSize, data);
		 CheckError ();
	 }
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
								 GLenum format, GLenum type, const GLvoid *data) {
		 TextureImage3DEXT (obj, target, level, internalFormat, width, height,
												depth, border, format, type, data);
		 CheckError ();
	 }
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
		* \param internalFormat Specifies the format of the compressed
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
													 const GLvoid *data) {
		 CompressedTextureImage3DEXT (obj, target, level, internalFormat, width,
																	height, depth, border, imageSize, data);
		 CheckError ();
	 }
	 /**
		* Specified a two-dimensional multisample texture image.
		* Establish the data storage, format, dimensions, and number
		* of samples of a multisample texture's image.
		* \param target Specifies the target of the operation.
		*               target must be GL_TEXTURE_2D_MULTISAMPLE.
		* \param samples The number of samples in the multisample
		*                texture's image.
		* \param internalFormat The internal format to be used to store
		*                       the multisample texture's image.
		*                       internalformat must specify a color-renderable,
		*                       depth-renderable, or stencil-renderable format.
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
														GLsizei height, GLboolean fixedsamplelocations) {
		 GLint previous;
		 if (target == GL_TEXTURE_2D_MULTISAMPLE)
				GetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE, &previous);
		 else
		 {
#ifdef OGLP_ERROR_CALLBACK
			 if (internal::errorcallback)
					internal::errorcallback (GL_INVALID_VALUE, "invalid value",
																	 internal::errorcallback_userdata);
#endif
#ifdef OGLP_THROW_EXCEPTIONS
				throw Exception (GL_INVALID_VALUE);
#else
				return;
#endif
		 }

		 BindTexture (target, obj);
		 TexImage2DMultisample (target, samples, internalFormat, width, height,
														fixedsamplelocations);
		 BindTexture (target, previous);
	 }
	 /**
		* Specified a two-dimensional multisample texture image.
		* Establish the data storage, format, dimensions, and number
		* of samples of a multisample texture's image.
		* \param target Specifies the target of the operation.
		*               target must be GL_TEXTURE_2D_MULTISAMPLE_ARRAY.
		* \param samples The number of samples in the multisample
		*                texture's image.
		* \param internalFormat  The internal format to be used to store
		*                        the multisample texture's image.
		*                        internalformat must specify a color-renderable,
		*                        depth-renderable, or stencil-renderable format.
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
														GLboolean fixedsamplelocations) {
		 GLint previous;
		 if (target == GL_TEXTURE_2D_MULTISAMPLE_ARRAY)
				GetIntegerv (GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, &previous);
		 else
		 {
#ifdef OGLP_ERROR_CALLBACK
			 if (internal::errorcallback)
					internal::errorcallback (GL_INVALID_VALUE, "invalid value",
																	 internal::errorcallback_userdata);
#endif
#ifdef OGLP_THROW_EXCEPTIONS
				throw Exception (GL_INVALID_VALUE);
#else
				return;
#endif
		 }
		 
		 BindTexture (target, obj);
		 TexImage3DMultisample (target, samples, internalFormat, width, height,
														depth, fixedsamplelocations);
		 BindTexture (target, previous);
	 }
	 /**
		* Attach a buffer object to the texture.
		* Attaches the storage for a buffer object to the buffer texture.
		* \param internalFormat Specifies the internal format of the data in the
		*                       store belonging to the buffer.
		* \param buffer Specifies the buffer object whose storage to attach to
		*               the active buffer texture.
		*/
	 void Buffer (GLenum internalFormat, const Buffer &buffer) {
		 TextureBufferEXT (obj, GL_TEXTURE_BUFFER, internalFormat,
											 buffer.get ());
		 CheckError ();
	 }
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
		* \param type Specifies a pixel type for the returned data.
		*             The supported types are GL_UNSIGNED_BYTE, GL_BYTE,
		*             GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT, GL_INT,
		*             GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2,
		*             GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5,
		*             GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4,
		*             GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1,
		*             GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8,
		*             GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2,
		*             GL_UNSIGNED_INT_2_10_10_10_REV, GL_UNSIGNED_INT_24_8,
		*             GL_UNSIGNED_INT_10F_11F_11F_REV, GL_UNSIGNED_INT_5_9_9_9_REV,
		*             and GL_FLOAT_32_UNSIGNED_INT_24_8_REV.
		* \param img Returns the texture image. Should be a pointer to an array
		*            of the type specified by type.
		*/
	 void GetTexImage (GLenum target, GLint level, GLenum format, GLenum type,
										 GLvoid *img) const {
		 GetTextureImageEXT (obj, target, level, format, type, img);
		 CheckError ();
	 }
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
	 void GenerateMipmap (GLenum target) const {
		 GenerateTextureMipmapEXT (obj, target);
		 CheckError ();
	 }
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
	 void Parameter (GLenum target, GLenum pname, GLint param) {
		 TextureParameteriEXT (obj, target, pname, param);
		 CheckError ();
	 }
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
	 void Parameter (GLenum target, GLenum pname, const GLint *params) {
		 TextureParameterivEXT (obj, target, pname, params);
		 CheckError ();
	 }
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
	 void Parameter (GLenum target, GLenum pname, GLfloat param) {
		 TextureParameterfEXT (obj, target, pname, param);
		 CheckError ();
	 }
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
	 void Parameter (GLenum target, GLenum pname, const GLfloat *params) {
		 TextureParameterfvEXT (obj, target, pname, params);
		 CheckError ();
	 }
   /** Get texture parameter.
		* Returns texture parameter values.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_DEPTH_STENCIL_TEXTURE_MODE, GL_TEXTURE_BASE_LEVEL,
		*              GL_TEXTURE_BORDER_COLOR, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_IMMUTABLE_FORMAT,
		*              GL_TEXTURE_IMMUTABLE_LEVELS, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_SWIZZLE_RGBA,
		*              GL_TEXTURE_VIEW_MIN_LAYER, GL_TEXTURE_VIEW_MIN_LEVEL,
		*              GL_TEXTURE_VIEW_NUM_LAYERS, GL_TEXTURE_VIEW_NUM_LEVELS,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, and
		*              GL_TEXTURE_WRAP_R are accepted.
		* \param target Specifies the symbolic name of the target texture.
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_TEXTURE_2D_ARRAY, GL_TEXTURE_3D,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP,
		*               and GL_TEXTURE_CUBE_MAP_ARRAY are accepted.
		* \param params Returns the texture parameters.
		*/
	 void GetParameter (GLenum target, GLenum pname,
											GLfloat *params) const {
		 GetTextureParameterfvEXT (obj, target, pname, params);
		 CheckError ();
	 }
   /** Get texture parameter.
		* Returns texture parameter values.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_DEPTH_STENCIL_TEXTURE_MODE, GL_TEXTURE_BASE_LEVEL,
		*              GL_TEXTURE_BORDER_COLOR, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_IMMUTABLE_FORMAT,
		*              GL_TEXTURE_IMMUTABLE_LEVELS, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_SWIZZLE_RGBA,
		*              GL_TEXTURE_VIEW_MIN_LAYER, GL_TEXTURE_VIEW_MIN_LEVEL,
		*              GL_TEXTURE_VIEW_NUM_LAYERS, GL_TEXTURE_VIEW_NUM_LEVELS,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, and
		*              GL_TEXTURE_WRAP_R are accepted.
		* \param target Specifies the symbolic name of the target texture.
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_TEXTURE_2D_ARRAY, GL_TEXTURE_3D,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP,
		*               and GL_TEXTURE_CUBE_MAP_ARRAY are accepted.
		* \param params Returns the texture parameters.
		*/
	 void GetParameter (GLenum target, GLenum pname, GLint *params) const {
		 GetTextureParameterivEXT (obj, target, pname, params);
		 CheckError ();
	 }
   /** Get texture parameter.
		* Returns texture parameter values.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_DEPTH_STENCIL_TEXTURE_MODE, GL_TEXTURE_BASE_LEVEL,
		*              GL_TEXTURE_BORDER_COLOR, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_IMMUTABLE_FORMAT,
		*              GL_TEXTURE_IMMUTABLE_LEVELS, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_SWIZZLE_RGBA,
		*              GL_TEXTURE_VIEW_MIN_LAYER, GL_TEXTURE_VIEW_MIN_LEVEL,
		*              GL_TEXTURE_VIEW_NUM_LAYERS, GL_TEXTURE_VIEW_NUM_LEVELS,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, and
		*              GL_TEXTURE_WRAP_R are accepted.
		* \param target Specifies the symbolic name of the target texture.
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_TEXTURE_2D_ARRAY, GL_TEXTURE_3D,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP,
		*               and GL_TEXTURE_CUBE_MAP_ARRAY are accepted.
		* \param params Returns the texture parameters.
		*/
	 void GetParameterI (GLenum target, GLenum pname, GLint *params) const {
		 GetTextureParameterIivEXT (obj, target, pname, params);
		 CheckError ();
	 }
   /** Get texture parameter.
		* Returns texture parameter values.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_DEPTH_STENCIL_TEXTURE_MODE, GL_TEXTURE_BASE_LEVEL,
		*              GL_TEXTURE_BORDER_COLOR, GL_TEXTURE_COMPARE_MODE,
		*              GL_TEXTURE_COMPARE_FUNC, GL_TEXTURE_IMMUTABLE_FORMAT,
		*              GL_TEXTURE_IMMUTABLE_LEVELS, GL_TEXTURE_LOD_BIAS,
		*              GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MAX_LEVEL,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_MIN_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_SWIZZLE_R,
		*              GL_TEXTURE_SWIZZLE_G, GL_TEXTURE_SWIZZLE_B,
		*              GL_TEXTURE_SWIZZLE_A, GL_TEXTURE_SWIZZLE_RGBA,
		*              GL_TEXTURE_VIEW_MIN_LAYER, GL_TEXTURE_VIEW_MIN_LEVEL,
		*              GL_TEXTURE_VIEW_NUM_LAYERS, GL_TEXTURE_VIEW_NUM_LEVELS,
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, and
		*              GL_TEXTURE_WRAP_R are accepted.
		* \param target Specifies the symbolic name of the target texture.
		*               GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_1D_ARRAY,
		*               GL_TEXTURE_2D_ARRAY, GL_TEXTURE_3D,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP,
		*               and GL_TEXTURE_CUBE_MAP_ARRAY are accepted.
		* \param params Returns the texture parameters.
		*/
	 void GetParameterI (GLenum target, GLenum pname, GLuint *params) const {
		 GetTextureParameterIuivEXT (obj, target, pname, params);
		 CheckError ();
	 }
	 /** Get texture level parameter.
		* Return texture parameter values for a specific level of detail.
		* \param level Specifies the level-of-detail number of the desired image.
		*              Level 0 is the base image level. Level n is the 
		*              nth mipmap reduction image.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_TEXTURE_WIDTH, GL_TEXTURE_HEIGHT,
		*              GL_TEXTURE_DEPTH, GL_TEXTURE_INTERNAL_FORMAT,
		*              GL_TEXTURE_BORDER, GL_TEXTURE_RED_SIZE,
		*              GL_TEXTURE_GREEN_SIZE, GL_TEXTURE_BLUE_SIZE,
		*              GL_TEXTURE_ALPHA_SIZE, GL_TEXTURE_DEPTH_SIZE,
		*              GL_TEXTURE_COMPRESSED, GL_TEXTURE_COMPRESSED_IMAGE_SIZE,
		*              and GL_TEXTURE_BUFFER_OFFSET are accepted.
		* \param target Specifies the symbolic name of the target texture,
		*               one of GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_2D_MULTISAMPLE,
		*               GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
		*               GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		*               GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    *               GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    *               GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    *               GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    *               GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
    *               GL_PROXY_TEXTURE_1D,
    *               GL_PROXY_TEXTURE_2D,
    *               GL_PROXY_TEXTURE_3D,
    *               GL_PROXY_TEXTURE_1D_ARRAY,
    *               GL_PROXY_TEXTURE_2D_ARRAY,
    *               GL_PROXY_TEXTURE_RECTANGLE,
    *               GL_PROXY_TEXTURE_2D_MULTISAMPLE,
    *               GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY,
		*               GL_PROXY_TEXTURE_CUBE_MAP, or
		*                GL_TEXTURE_BUFFER.           
		* \param params Returns the requested data.
		*/
	 void GetLevelParameter (GLenum target, GLint level,
													 GLenum pname, GLfloat *params) const {
		 GetTextureLevelParameterfvEXT (obj, target, level, pname, params);
		 CheckError ();
	 }
	 /** Get texture level parameter.
		* Return texture parameter values for a specific level of detail.
		* \param level Specifies the level-of-detail number of the desired image.
		*              Level 0 is the base image level. Level n is the 
		*              nth mipmap reduction image.
		* \param pname Specifies the symbolic name of a texture parameter.
		*              GL_TEXTURE_WIDTH, GL_TEXTURE_HEIGHT,
		*              GL_TEXTURE_DEPTH, GL_TEXTURE_INTERNAL_FORMAT,
		*              GL_TEXTURE_BORDER, GL_TEXTURE_RED_SIZE,
		*              GL_TEXTURE_GREEN_SIZE, GL_TEXTURE_BLUE_SIZE,
		*              GL_TEXTURE_ALPHA_SIZE, GL_TEXTURE_DEPTH_SIZE,
		*              GL_TEXTURE_COMPRESSED, GL_TEXTURE_COMPRESSED_IMAGE_SIZE,
		*              and GL_TEXTURE_BUFFER_OFFSET are accepted.    
		* \param target Specifies the symbolic name of the target texture,
		*               one of GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
		*               GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY,
		*               GL_TEXTURE_RECTANGLE, GL_TEXTURE_2D_MULTISAMPLE,
		*               GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
		*               GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		*               GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
    *               GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
    *               GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
    *               GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
    *               GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
    *               GL_PROXY_TEXTURE_1D,
    *               GL_PROXY_TEXTURE_2D,
    *               GL_PROXY_TEXTURE_3D,
    *               GL_PROXY_TEXTURE_1D_ARRAY,
    *               GL_PROXY_TEXTURE_2D_ARRAY,
    *               GL_PROXY_TEXTURE_RECTANGLE,
    *               GL_PROXY_TEXTURE_2D_MULTISAMPLE,
    *               GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY,
		*               GL_PROXY_TEXTURE_CUBE_MAP, or
		*                GL_TEXTURE_BUFFER.           
		* \param params Returns the requested data.
		*/
	 void GetLevelParameter (GLenum target, GLint level, GLenum pname,
													 GLint *params) const {
		 GetTextureLevelParameterivEXT (obj, target, level, pname, params);
		 CheckError ();
	 }
	 /**
		* Initialize a texture view.
		* Initialize the internal OpenGL texture object as a data
		* alias of another texture's data store.
		* \param target Specifies the target to be used
		*               for the newly initialized texture.
		* \param origtexture Specifies the name of a texture object
		*                    of which to make a view.
		* \param internalFormat Specifies the internal format
		*                       for the newly created view.
		* \param minlevel Specifies lowest level of detail of the view.
		* \param numlevels Specifies the number of levels of detail
		*                  to include in the view.
		* \param minlayer Specifies the index of the first layer 
		*                 to include in the view.
		* \param numlayers Specifies the number of layers
		*                  to include in the view.
		*/
	 void View (GLenum target, const Texture &origtexture,
							GLenum internalFormat, GLuint minlevel,
							GLuint numlevels, GLuint minlayer,
							GLuint numlayers) {
		 TextureView (obj, target, origtexture.get (), internalFormat,
									minlevel, numlevels, minlayer, numlayers);
		 CheckError ();
	 }
	 /**
		* Return internal object.
		* Returns the internal OpenGL texture object. Use with caution.
		* \return The internal OpenGL texture object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL texture object with another Texture.
		* \param texture Object with which to swap the internal texture object.
		*/
	 void swap (Texture &texture) {
		 std::swap (obj, texture.obj);
	 }
private:
	 /** internal OpenGL texture object
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined TEXTURE_H */
