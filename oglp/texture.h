/*
 * Copyright 2015 Daniel Kirchner
 *
 * This file is part of midium.
 *
 * midium is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * midium is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with midium.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OGLP_TEXTURE_H
#define OGLP_TEXTURE_H

#include "common.h"
#include "buffer.h"
#include <iostream>

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
       * \param target texture target for the new texture
       */
    Texture (GLenum target)
    {
        CreateTextures (target, 1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL texture object to another Texture object.
       * \param texture Texture object to move.
       */
    Texture (Texture &&texture) noexcept
    {
        GLuint tmp = obj;
        obj = texture.obj;
        texture.obj = tmp;
    }

    /**
       * Deleted copy constructor.
       * A Texture object can't be copy constructed.
       */
    Texture (const Texture &) = delete;

    /**
       * A destructor.
       * Deletes a Texture object.
       */
    ~Texture (void)
    {
        DeleteTextures (1, &obj);
    }

    /**
       * Move assignment.
       * Passes the internal OpenGL texture object to another Texture object.
       * \param texture Texture object to move.
       * \return A reference to the Texture object.
       */
    Texture &operator= (Texture &&texture) noexcept
    {
        GLuint tmp = obj;
        obj = texture.obj;
        texture.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A Texture object can't be copy assigned.
       * \return
       */
    Texture &operator= (const Texture &) = delete;

    /**
       * Label the texture object.
       * Labels the internal OpenGL texture object.
       * \param name Label to be used for the texture object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_TEXTURE, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Bind the Texture object.
       * Binds the Texture object to the specified target and texture unit.
       * \param texunit Specifies the index of the texture unit to which to
       *                bind the sampler to.
       */
    void Bind (GLenum texunit) const
    {
        BindTextureUnit (texunit, obj);
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
                    GLint layer, GLenum access, GLenum format) const
    {
        BindImageTexture (unit, obj, level, layered, layer, access, format);
        CheckError ();
    }

    /** Specify one-dimensional texture storage.
       * Simultaneously specify storage for all levels of a
       * one-dimensional texture.
       * \param levels Specify the number of texture levels.
       * \param internalformat Specifies the sized internal format to
       *                       be used to store texture image data.
       * \param width Specifies the width of the texture, in texels.
       */
    void Storage1D (GLsizei levels, GLenum internalformat, GLsizei width)
    {
        TextureStorage1D (obj, levels, internalformat, width);
        CheckError ();
    }

    /**
       * Specify two-dimensional texture storage.
       * Simultaneously specify storage for all levels of a
       * two-dimensional or one-dimensional array texture.
       * \param levels Specify the number of texture levels.
       * \param internalformat Specifies the sized internal format to
       *                       be used to store texture image data.
       * \param width Specifies the width of the texture, in texels.
       * \param height Specifies the height of the texture, in texels.
       */
    void Storage2D (GLsizei levels,
                    GLenum internalformat,
                    GLsizei width, GLsizei height)
    {
        TextureStorage2D (obj, levels, internalformat, width, height);
        CheckError ();
    }

    /**
       * Specify two-dimensional multisample texture storage.
       * Simultaneously specify storage for a two-dimensional
       * multisample texture.
       * \param samples Specify the number of samples in the texture.
       * \param internalformat Specifies the sized internal format to
       *                       be used to store texture image data.
       * \param width Specifies the width of the texture, in texels.
       * \param height Specifies the height of the texture, in texels.
       * \param fixedsamplelocations Specifies whether the image will
       *                             use identical sample locations and
       *                             the same number of samples for all
       *                             texels in the image, and the sample
       *                             locations will not depend on the
       *                             internal format or size of the image.
       */
    void Storage2DMultisample (GLsizei samples,
                               GLenum internalformat,
                               GLsizei width, GLsizei height,
                               GLboolean fixedsamplelocations)
    {
        TextureStorage2DMultisample (obj, samples, internalformat, width, height, fixedsamplelocations);
        CheckError ();
    }

    /**
       * Specify three-dimensional multisample texture storage.
       * Simultaneously specify storage for a two-dimensional
       * multisample array texture.
       * \param samples Specify the number of samples in the texture.
       * \param internalformat Specifies the sized internal format to
       *                       be used to store texture image data.
       * \param width Specifies the width of the texture, in texels.
       * \param height Specifies the height of the texture, in texels.
       * \param depth Specifies the depth of the texture, in layers.
       * \param fixedsamplelocations Specifies whether the image will
       *                             use identical sample locations and
       *                             the same number of samples for all
       *                             texels in the image, and the sample
       *                             locations will not depend on the
       *                             internal format or size of the image.
       */
    void Storage3DMultisample (GLsizei samples, GLenum internalformat,
                               GLsizei width, GLsizei height, GLsizei depth,
                               GLboolean fixedsamplelocations)
    {
        TextureStorage3DMultisample (obj, samples, internalformat, width, height, depth, fixedsamplelocations);
        CheckError ();
    }

    /**
       * Specify three-dimensional texture storage.
       * Simultaneously specify storage for all levels of a
       * three-dimensional, two-dimensional array or cube-map array texture.
       * \param levels Specify the number of texture levels.
       * \param internalformat Specifies the sized internal format to
       *                       be used to store texture image data.
       * \param width Specifies the width of the texture, in texels.
       * \param height Specifies the height of the texture, in texels.
       * \param depth Specifies the depth of the texture, in texels.
       */
    void Storage3D (GLsizei levels, GLenum internalformat, GLsizei width,
                    GLsizei height, GLsizei depth)
    {
        TextureStorage3D (obj, levels, internalformat, width, height, depth);
        CheckError ();
    }

    /**
     * Specify a one-dimensional texture subimage.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param format Specifies the format of the pixel data. The following symbolic
     *               values are accepted: GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, and
     *               GL_BGRA.
     * \param type Specifies the data type of the pixel data. The following symbolic
     *             values are accepted: GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT,
     *             GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT,
     *             GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV,
     *             GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV,
     *             GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV,
     *             GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
     *             GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV,
     *             GL_UNSIGNED_INT_10_10_10_2, and GL_UNSIGNED_INT_2_10_10_10_REV.
     * \param data Specifies a pointer to the image data in memory.
     */
    void SubImage1D (GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *data)
    {
        TextureSubImage1D (obj, level, xoffset, width, format, type, data);
        CheckError ();
    }

    /**
     * Specify a one-dimensional texture subimage in a compressed format.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param format Specifies the format of the compressed image data.
     * \param imageSize Specifies the number of unsigned bytes of image data starting at
     *                  the address specified by data.
     * \param data Specifies a pointer to the image data in memory.
     */
    void CompressedSubImage1D (GLint level, GLint xoffset, GLsizei width, GLenum format,
                               GLsizei imageSize, const GLvoid *data)
    {
        CompressedTextureSubImage1D (obj, level, xoffset, width, format, imageSize, data);
        CheckError ();
    }

    /**
     * Specify a two-dimensional texture subimage.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param yoffset Specifies a texel offset in the y direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param height Specifies the height of the texture subimage.
     * \param format Specifies the format of the pixel data. The following symbolic
     *               values are accepted: GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, and
     *               GL_BGRA.
     * \param type Specifies the data type of the pixel data. The following symbolic
     *             values are accepted: GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT,
     *             GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT,
     *             GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV,
     *             GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV,
     *             GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV,
     *             GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
     *             GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV,
     *             GL_UNSIGNED_INT_10_10_10_2, and GL_UNSIGNED_INT_2_10_10_10_REV.
     * \param data Specifies a pointer to the image data in memory.
     */
    void SubImage2D (GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                     GLsizei height, GLenum format, GLenum type, const GLvoid *data)
    {
        TextureSubImage2D (obj, level, xoffset, yoffset, width, height, format, type, data);
        CheckError ();
    }

    /**
     * Specify a two-dimensional texture subimage in a compressed format.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param yoffset Specifies a texel offset in the y direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param height Specifies the height of the texture subimage.
     * \param format Specifies the format of the compressed image data.
     * \param imageSize Specifies the number of unsigned bytes of image data starting at
     *                  the address specified by data.
     * \param data Specifies a pointer to the image data in memory.
     */
    void CompressedSubImage2D (GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                               GLenum format, GLsizei imageSize, const GLvoid *data)
    {
        CompressedTextureSubImage2D (obj, level, xoffset, yoffset, width, height, format, imageSize, data);
        CheckError ();
    }

    /**
     * Specify a three-dimensional texture subimage.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param yoffset Specifies a texel offset in the y direction within the texture array.
     * \param zoffset Specifies a texel offset in the z direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param height Specifies the height of the texture subimage.
     * \param depth Specifies the depth of the texture subimage.
     * \param format Specifies the format of the pixel data. The following symbolic
     *               values are accepted: GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, and
     *               GL_BGRA.
     * \param type Specifies the data type of the pixel data. The following symbolic
     *             values are accepted: GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT,
     *             GL_SHORT, GL_UNSIGNED_INT, GL_INT, GL_FLOAT,
     *             GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV,
     *             GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV,
     *             GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV,
     *             GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV,
     *             GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV,
     *             GL_UNSIGNED_INT_10_10_10_2, and GL_UNSIGNED_INT_2_10_10_10_REV.
     * \param data Specifies a pointer to the image data in memory.
     */
    void SubImage3D (GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height,
                     GLsizei depth, GLenum format, GLenum type, const GLvoid *data)
    {
        TextureSubImage3D (obj, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
        CheckError ();
    }

    /**
     * Specify a three-dimensional texture subimage in a compressed format.
     * \param level Specifies the level-of-detail number. Level 0 is the base image
     *              level. Level n is the nth mipmap reduction image.
     * \param xoffset Specifies a texel offset in the x direction within the texture array.
     * \param yoffset Specifies a texel offset in the y direction within the texture array.
     * \param zoffset Specifies a texel offset in the z direction within the texture array.
     * \param width Specifies the width of the texture subimage.
     * \param height Specifies the height of the texture subimage.
     * \param depth Specifies the depth of the texture subimage.
     * \param format Specifies the format of the compressed image data.
     * \param imageSize Specifies the number of unsigned bytes of image data starting at
     *                  the address specified by data.
     * \param data Specifies a pointer to the image data in memory.
     */
    void CompressedSubImage3D (GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height,
                               GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
    {
        CompressedTextureSubImage3D (obj, level, xoffset, yoffset, zoffset, width, height, depth,
                                     format, imageSize, data);
        CheckError ();
    }

    /**
       * Attach a buffer object to the texture.
       * Attaches the storage for a buffer object to the buffer texture.
       * \param internalFormat Specifies the internal format of the data in the
       *                       store belonging to the buffer.
       * \param buffer Specifies the buffer object whose storage to attach to
       *               the active buffer texture.
       */
    void Buffer (GLenum internalFormat, const oglp::Buffer &buffer)
    {
        TextureBuffer (obj, internalFormat, buffer.get ());
        CheckError ();
    }

    /**
       * Attach a buffer object to the texture.
       * Attaches the storage for a buffer object to the buffer texture.
       * \param internalFormat Specifies the internal format of the data in the
       *                       store belonging to the buffer.
       * \param buffer Specifies the buffer object whose storage to attach to
       *               the active buffer texture.
       */
    void Buffer (GLenum internalFormat, GLuint buffer)
    {
        TextureBuffer (obj, internalFormat, buffer);
        CheckError ();
    }

    /**
     * Attach a buffer object to the texture.
     * Attaches the storage for a buffer object to the buffer texture.
     * \param internalFormat Specifies the internal format of the data in the
     *                       store belonging to the buffer.
     * \param buffer Specifies the buffer object whose storage to attach to
     *               the active buffer texture.
     * \param offset Specifies the offset of the start of the range of the buffer's data store to attach.
     * \param size Specifies the size of the range of the1 buffer's data store to attach.
     */
    void BufferRange (GLenum internalFormat, const oglp::Buffer &buffer, GLintptr offset, GLsizei size)
    {
        TextureBufferRange (obj, internalFormat, buffer.get (), offset, size);
        CheckError ();
    }

    /**
     * Attach a buffer object to the texture.
     * Attaches the storage for a buffer object to the buffer texture.
     * \param internalFormat Specifies the internal format of the data in the
     *                       store belonging to the buffer.
     * \param buffer Specifies the buffer object whose storage to attach to
     *               the active buffer texture.
     * \param offset Specifies the offset of the start of the range of the buffer's data store to attach.
     * \param size Specifies the size of the range of the buffer's data store to attach.
     */
    void BufferRange (GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizei size)
    {
        TextureBufferRange (obj, internalFormat, buffer, offset, size);
        CheckError ();
    }

    /**
       * Return a texture image.
       * Returns data from the internal texture object.
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
       * \param bufSize Specifies the size of the buffer pixels.
       * \param img Returns the texture image. Should be a pointer to an array
       *            of the type specified by type.
       */
    void GetTexImage (GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *img) const
    {
        GetTextureImage (obj, level, format, type, bufSize, img);
        CheckError ();
    }

    /**
       * Generate mipmaps.
       * Generates mipmaps for the internal texture object.
       */
    void GenerateMipmap (void) const
    {
        GenerateTextureMipmap (obj);
        CheckError ();
    }

    /**
       * Set texture parameters.
       * Set texture parameters.
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
    void Parameter (GLenum pname, GLint param)
    {
        TextureParameteri (obj, pname, param);
        CheckError ();
    }

    /**
       * Set texture parameters.
       * Set texture parameters.
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
    void Parameter (GLenum pname, const GLint *params)
    {
        TextureParameteriv (obj, pname, params);
        CheckError ();
    }

    /**
       * Set texture parameters.
       * Set texture parameters.
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
    void Parameter (GLenum pname, GLfloat param)
    {
        TextureParameterf (obj, pname, param);
        CheckError ();
    }

    /**
       * Set texture parameters.
       * Set texture parameters.
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
    void Parameter (GLenum pname, const GLfloat *params)
    {
        TextureParameterfv (obj, pname, params);
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
         * \param params Returns the texture parameters.
         */
    void GetParameter (GLenum pname, GLfloat *params) const
    {
        GetTextureParameterfv (obj, pname, params);
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
         * \param params Returns the texture parameters.
         */
    void GetParameter (GLenum pname, GLint *params) const
    {
        GetTextureParameteriv (obj, pname, params);
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
         * \param params Returns the texture parameters.
         */
    void GetParameterI (GLenum pname, GLint *params) const
    {
        GetTextureParameterIiv (obj, pname, params);
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
         * \param params Returns the texture parameters.
         */
    void GetParameterI (GLenum pname, GLuint *params) const
    {
        GetTextureParameterIuiv (obj, pname, params);
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
       * \param params Returns the requested data.
       */
    void GetLevelParameter (GLint level, GLenum pname, GLfloat *params) const
    {
        GetTextureLevelParameterfv (obj, level, pname, params);
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
       * \param params Returns the requested data.
       */
    void GetLevelParameter (GLint level, GLenum pname, GLint *params) const
    {
        GetTextureLevelParameteriv (obj, level, pname, params);
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
               GLuint numlayers)
    {
        TextureView (obj, target, origtexture.get (), internalFormat,
                     minlevel, numlevels, minlayer, numlayers);
        CheckError ();
    }

    /**
       * Return internal object.
       * Returns the internal OpenGL texture object. Use with caution.
       * \return The internal OpenGL texture object.
       */
    GLuint get (void) const
    {
        return obj;
    }
private:
    /** internal OpenGL texture object
       */
    GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_TEXTURE_H */
