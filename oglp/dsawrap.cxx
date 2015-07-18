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

#ifndef OGLP_DSAWRAP_CXX
#define OGLP_DSAWRAP_CXX

/* This file provides workaround wrappers for the entry points of EXT_direct_state_access that
 * correspond to core profile functions. Entry points that correspond to legacy functions just
 * call Unsuppported().
 */

namespace oglp {
namespace dsawrap {

GLAPI void APIENTRY
ClientAttribDefaultEXT (GLbitfield
mask) {
Unsupported ();
}

GLAPI void APIENTRY
PushClientAttribDefaultEXT (GLbitfield
mask) {
Unsupported ();
}

GLAPI void APIENTRY
MatrixLoadfEXT (GLenum
mode,
const GLfloat *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixLoaddEXT (GLenum
mode,
const GLdouble *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixMultfEXT (GLenum
mode,
const GLfloat *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixMultdEXT (GLenum
mode,
const GLdouble *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixLoadIdentityEXT (GLenum
mode)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixRotatefEXT (GLenum
mode,
GLfloat angle, GLfloat
x,
GLfloat y, GLfloat
z)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixRotatedEXT (GLenum
mode,
GLdouble angle, GLdouble
x,
GLdouble y, GLdouble
z)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixScalefEXT (GLenum
mode,
GLfloat x, GLfloat
y,
GLfloat z
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixScaledEXT (GLenum
mode,
GLdouble x, GLdouble
y,
GLdouble z
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixTranslatefEXT (GLenum
mode,
GLfloat x, GLfloat
y,
GLfloat z
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixTranslatedEXT (GLenum
mode,
GLdouble x, GLdouble
y,
GLdouble z
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixFrustumEXT (GLenum
mode,
GLdouble left, GLdouble
right,
GLdouble bottom, GLdouble
top,
GLdouble zNear, GLdouble
zFar)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixOrthoEXT (GLenum
mode,
GLdouble left, GLdouble
right,
GLdouble bottom, GLdouble
top,
GLdouble zNear, GLdouble
zFar)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixPopEXT (GLenum
mode)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixPushEXT (GLenum
mode)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixLoadTransposefEXT (GLenum
mode,
const GLfloat *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixLoadTransposedEXT (GLenum
mode,
const GLdouble *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixMultTransposefEXT (GLenum
mode,
const GLfloat *m
)
{
Unsupported ();

}

GLAPI void APIENTRY
MatrixMultTransposedEXT (GLenum
mode,
const GLdouble *m
)
{
Unsupported ();

}

namespace detail {

inline void BindTexture (GLenum target, GLuint texture)
{
    switch (target) {
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
            oglp::BindTexture (GL_TEXTURE_CUBE_MAP, texture);
            break;
        default:
            oglp::BindTexture (target, texture);
            break;
    }
}

inline GLenum TextureTargetToBinding (GLenum target)
{
    switch (target) {
        case GL_TEXTURE_1D:
            return GL_TEXTURE_BINDING_1D;
        case GL_TEXTURE_1D_ARRAY:
            return GL_TEXTURE_BINDING_1D_ARRAY;
        case GL_TEXTURE_2D:
            return GL_TEXTURE_BINDING_2D;
        case GL_TEXTURE_2D_ARRAY:
            return GL_TEXTURE_BINDING_2D_ARRAY;
        case GL_TEXTURE_2D_MULTISAMPLE:
            return GL_TEXTURE_BINDING_2D_MULTISAMPLE;
        case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
            return GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;
        case GL_TEXTURE_3D:
            return GL_TEXTURE_BINDING_3D;
        case GL_TEXTURE_BUFFER:
            return GL_TEXTURE_BINDING_BUFFER;
        case GL_TEXTURE_RECTANGLE:
            return GL_TEXTURE_BINDING_RECTANGLE;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
        case GL_TEXTURE_CUBE_MAP:
            return GL_TEXTURE_BINDING_CUBE_MAP;
        default:
            return (GLenum) - 1;
    }
}

}
/* namespace detail */

GLAPI void APIENTRY
TextureParameterfEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLfloat param
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameterf (target, pname, param
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureParameterfvEXT (GLuint
texture,
GLenum target, GLenum
pname,
const GLfloat *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameterfv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureParameteriEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLint param
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameteri (target, pname, param
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureParameterivEXT (GLuint
texture,
GLenum target, GLenum
pname,
const GLint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameteriv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat, GLsizei
width,
GLint border, GLenum
format,
GLenum type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexImage1D (target, level, internalformat, width, border, format, type, pixels
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat, GLsizei
width,
GLsizei height, GLint
border,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
TexImage2D (target, level, internalformat, width, height, border, format, type, pixels
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureSubImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLsizei
width,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexSubImage1D (target, level, xoffset, width, format, type, pixels
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureSubImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLsizei width, GLsizei
height,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
TexSubImage2D (target, level, xoffset, yoffset, width, height, format, type, pixels
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
CopyTextureImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat, GLint
x,
GLint y, GLsizei
width,
GLint border
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CopyTexImage1D (target, level, internalformat, x, y, width, border
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CopyTextureImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat, GLint
x,
GLint y, GLsizei
width,
GLsizei height, GLint
border)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
CopyTexImage2D (target, level, internalformat, x, y, width, height, border
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
CopyTextureSubImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLint
x,
GLint y, GLsizei
width)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CopyTexSubImage1D (target, level, xoffset, x, y, width
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CopyTextureSubImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint x, GLint
y,
GLsizei width, GLsizei
height)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
CopyTexSubImage2D (target, level, xoffset, yoffset, x, y, width, height
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureImageEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum format, GLenum
type,
GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
GetTexImage (target, level, format, type, pixels
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureParameterfvEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLfloat *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
GetTexParameterfv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureParameterivEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
GetTexParameteriv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureLevelParameterfvEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum pname,
        GLfloat
*params)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
GetTexLevelParameterfv (target, level, pname, params
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureLevelParameterivEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum pname,
        GLint
*params)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
GetTexLevelParameteriv (target, level, pname, params
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureImage3DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat, GLsizei
width,
GLsizei height, GLsizei
depth,
GLint border, GLenum
format,
GLenum type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexImage3D (target, level, internalformat, width, height, depth, border, format, type, pixels
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureSubImage3DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint zoffset, GLsizei
width,
GLsizei height, GLsizei
depth,
GLenum format,
        GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CopyTextureSubImage3DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint zoffset, GLint
x,
GLint y, GLsizei
width,
GLsizei height
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CopyTexSubImage3D (target, level, xoffset, yoffset, zoffset, x, y, width, height
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
MultiTexParameterfEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLfloat param
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameterf (target, pname, param
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexParameterfvEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLfloat *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameterfv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexParameteriEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLint param
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameteri (target, pname, param
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexParameterivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameteriv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLint border, GLenum
format,
GLenum type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexImage1D (target, level, internalformat, width, border, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLint
border,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexImage2D (target, level, internalformat, width, height, border, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexSubImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLsizei
width,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexSubImage1D (target, level, xoffset, width, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexSubImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLsizei width, GLsizei
height,
GLenum format, GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexSubImage2D (target, level, xoffset, yoffset, width, height, format, type, pixels
);
ActiveTexture (saved);
}


GLAPI void APIENTRY
CopyMultiTexImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat, GLint
x,
GLint y, GLsizei
width,
GLint border
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CopyTexImage1D (target, level, internalformat, x, y, width, border
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CopyMultiTexImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat, GLint
x,
GLint y, GLsizei
width,
GLsizei height, GLint
border)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CopyTexImage2D (target, level, internalformat, x, y, width, height, border
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CopyMultiTexSubImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLint
x,
GLint y, GLsizei
width)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CopyTexSubImage1D (target, level, xoffset, x, y, width
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CopyMultiTexSubImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint x, GLint
y,
GLsizei width, GLsizei
height)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CopyTexSubImage2D (target, level, xoffset, yoffset, x, y, width, height
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexImageEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum format, GLenum
type,
GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexImage (target, level, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexParameterfvEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLfloat *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexParameterfv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexParameterivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexParameteriv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexLevelParameterfvEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum pname,
        GLfloat
*params)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexLevelParameterfv (target, level, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexLevelParameterivEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum pname,
        GLint
*params)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexLevelParameteriv (target, level, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexImage3DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLsizei
depth,
GLint border, GLenum
format,
GLenum type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexImage3D (target, level, internalformat, width, height, depth, border, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexSubImage3DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint zoffset, GLsizei
width,
GLsizei height, GLsizei
depth,
GLenum format,
        GLenum
type,
const GLvoid *pixels
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CopyMultiTexSubImage3DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset, GLint
yoffset,
GLint zoffset, GLint
x,
GLint y, GLsizei
width,
GLsizei height
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CopyTexSubImage3D (target, level, xoffset, yoffset, zoffset, x, y, width, height
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
BindMultiTextureEXT (GLenum
texunit,
GLenum target, GLuint
texture)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
BindTexture (target, texture
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
EnableClientStateIndexedEXT (GLenum
array,
GLuint index
)
{
Unsupported ();

}

GLAPI void APIENTRY
DisableClientStateIndexedEXT (GLenum
array,
GLuint index
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexCoordPointerEXT (GLenum
texunit,
GLint size, GLenum
type,
GLsizei stride,
const GLvoid *pointer
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexEnvfEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLfloat param
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexEnvfvEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexEnviEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLint param
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexEnvivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGendEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLdouble param
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGendvEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
const GLdouble *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGenfEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLfloat param
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGenfvEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
const GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGeniEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLint param
)
{
Unsupported ();

}

GLAPI void APIENTRY
MultiTexGenivEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
const GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetMultiTexEnvfvEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetMultiTexEnvivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetMultiTexGendvEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLdouble *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetMultiTexGenfvEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetMultiTexGenivEXT (GLenum
texunit,
GLenum coord, GLenum
pname,
GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetFloatIndexedvEXT (GLenum
target,
GLuint index, GLfloat
*data)
{
switch (target) {
case
GL_TEXTURE_BINDING_1D:
case
GL_TEXTURE_BINDING_1D_ARRAY:
case
GL_TEXTURE_BINDING_2D:
case
GL_TEXTURE_BINDING_2D_ARRAY:
case
GL_TEXTURE_BINDING_3D:
case
GL_TEXTURE_BINDING_BUFFER:
case
GL_TEXTURE_BINDING_CUBE_MAP:
case
GL_TEXTURE_BINDING_CUBE_MAP_ARRAY:
case
GL_TEXTURE_BINDING_RECTANGLE:
case
GL_TEXTURE_BINDING_RENDERBUFFER_NV:
case
GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV:
case
GL_TEXTURE_BUFFER_DATA_STORE_BINDING:
//	case GL_TEXTURE_BUFFER_FORMAT:
//	case GL_TEXTURE_GEN_Q:
//	case GL_TEXTURE_GEN_R:
//	case GL_TEXTURE_GEN_S:
//	case GL_TEXTURE_GEN_T:
//	case GL_TEXTURE_MATRIX:
//	case GL_TEXTURE_STACK_DEPTH:
//	case GL_TRANSPOSE_TEXTURE_MATRIX:
case
GL_TEXTURE_1D:
case
GL_TEXTURE_2D:
case
GL_TEXTURE_3D:
case
GL_TEXTURE_CUBE_MAP:
case
GL_TEXTURE_RECTANGLE:
int saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (GL_TEXTURE0
+ index);
GetFloatv (target, data
);
ActiveTexture (saved);
return;
default:

Unsupported ();

return;
}
}

GLAPI void APIENTRY
GetDoubleIndexedvEXT (GLenum
target,
GLuint index, GLdouble
*data)
{
switch (target) {
case
GL_TEXTURE_BINDING_1D:
case
GL_TEXTURE_BINDING_1D_ARRAY:
case
GL_TEXTURE_BINDING_2D:
case
GL_TEXTURE_BINDING_2D_ARRAY:
case
GL_TEXTURE_BINDING_3D:
case
GL_TEXTURE_BINDING_BUFFER:
case
GL_TEXTURE_BINDING_CUBE_MAP:
case
GL_TEXTURE_BINDING_CUBE_MAP_ARRAY:
case
GL_TEXTURE_BINDING_RECTANGLE:
case
GL_TEXTURE_BINDING_RENDERBUFFER_NV:
case
GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV:
case
GL_TEXTURE_BUFFER_DATA_STORE_BINDING:
//	case GL_TEXTURE_BUFFER_FORMAT:
//	case GL_TEXTURE_GEN_Q:
//	case GL_TEXTURE_GEN_R:
//	case GL_TEXTURE_GEN_S:
//	case GL_TEXTURE_GEN_T:
//	case GL_TEXTURE_MATRIX:
//	case GL_TEXTURE_STACK_DEPTH:
//	case GL_TRANSPOSE_TEXTURE_MATRIX:
case
GL_TEXTURE_1D:
case
GL_TEXTURE_2D:
case
GL_TEXTURE_3D:
case
GL_TEXTURE_CUBE_MAP:
case
GL_TEXTURE_RECTANGLE:
int saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (GL_TEXTURE0
+ index);
GetDoublev (target, data
);
ActiveTexture (saved);
return;
default:

Unsupported ();

return;
}
}

GLAPI void APIENTRY
GetPointerIndexedvEXT (GLenum
target,
GLuint index, GLvoid
**data)
{
Unsupported ();

}

GLAPI void APIENTRY
CompressedTextureImage3DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLsizei
depth,
GLint border,
        GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CompressedTexImage3D (target, level, internalformat, width, height, depth, border, imageSize, bits
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedTextureImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLint
border,
GLsizei imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
CompressedTexImage2D (target, level, internalformat, width, height, border, imageSize, bits
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedTextureImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLint border, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CompressedTexImage1D (target, level, internalformat, width, border, imageSize, bits
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedTextureSubImage3DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset,
        GLint
yoffset,
GLint zoffset, GLsizei
width,
GLsizei height,
        GLsizei
depth,
GLenum format, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CompressedTexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedTextureSubImage2DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset,
        GLint
yoffset,
GLsizei width, GLsizei
height,
GLenum format,
        GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
CompressedTexSubImage2D (target, level, xoffset, yoffset, width, height, format, imageSize, bits
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedTextureSubImage1DEXT (GLuint
texture,
GLenum target, GLint
level,
GLint xoffset,
        GLsizei
width,
GLenum format, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
CompressedTexSubImage1D (target, level, xoffset, width, format, imageSize, bits
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetCompressedTextureImageEXT (GLuint
texture,
GLenum target, GLint
lod,
GLvoid *img
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
GetCompressedTexImage (target, lod, img
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
CompressedMultiTexImage3DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLsizei
depth,
GLint border,
        GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexImage3D (target, level, internalformat, width, height, depth, border, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CompressedMultiTexImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLint
border,
GLsizei imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexImage2D (target, level, internalformat, width, height, border, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CompressedMultiTexImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLenum internalformat,
        GLsizei
width,
GLint border, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexImage1D (target, level, internalformat, width, border, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CompressedMultiTexSubImage3DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset,
        GLint
yoffset,
GLint zoffset, GLsizei
width,
GLsizei height,
        GLsizei
depth,
GLenum format, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexSubImage3D (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CompressedMultiTexSubImage2DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset,
        GLint
yoffset,
GLsizei width, GLsizei
height,
GLenum format,
        GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexSubImage2D (target, level, xoffset, yoffset, width, height, format, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
CompressedMultiTexSubImage1DEXT (GLenum
texunit,
GLenum target, GLint
level,
GLint xoffset,
        GLsizei
width,
GLenum format, GLsizei
imageSize,
const GLvoid *bits
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
CompressedTexSubImage1D (target, level, xoffset, width, format, imageSize, bits
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetCompressedMultiTexImageEXT (GLenum
texunit,
GLenum target, GLint
lod,
GLvoid *img
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetCompressedTexImage (target, lod, img
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
NamedProgramStringEXT (GLuint
program,
GLenum target, GLenum
format,
GLsizei len,
const GLvoid *string
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameter4dEXT (GLuint
program,
GLenum target, GLuint
index,
GLdouble x,
        GLdouble
y,
GLdouble z, GLdouble
w)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameter4dvEXT (GLuint
program,
GLenum target, GLuint
index,
const GLdouble *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameter4fEXT (GLuint
program,
GLenum target, GLuint
index,
GLfloat x, GLfloat
y,
GLfloat z, GLfloat
w)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameter4fvEXT (GLuint
program,
GLenum target, GLuint
index,
const GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramLocalParameterdvEXT (GLuint
program,
GLenum target, GLuint
index,
GLdouble *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramLocalParameterfvEXT (GLuint
program,
GLenum target, GLuint
index,
GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramivEXT (GLuint
program,
GLenum target, GLenum
pname,
GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramStringEXT (GLuint
program,
GLenum target, GLenum
pname,
GLvoid *string
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameters4fvEXT (GLuint
program,
GLenum target, GLuint
index,
GLsizei count,
const GLfloat *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameterI4iEXT (GLuint
program,
GLenum target, GLuint
index,
GLint x, GLint
y,
GLint z, GLint
w)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameterI4ivEXT (GLuint
program,
GLenum target, GLuint
index,
const GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParametersI4ivEXT (GLuint
program,
GLenum target, GLuint
index,
GLsizei count,
const GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameterI4uiEXT (GLuint
program,
GLenum target, GLuint
index,
GLuint x, GLuint
y,
GLuint z, GLuint
w)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParameterI4uivEXT (GLuint
program,
GLenum target, GLuint
index,
const GLuint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedProgramLocalParametersI4uivEXT (GLuint
program,
GLenum target, GLuint
index,
GLsizei count,
const GLuint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramLocalParameterIivEXT (GLuint
program,
GLenum target, GLuint
index,
GLint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetNamedProgramLocalParameterIuivEXT (GLuint
program,
GLenum target, GLuint
index,
GLuint *params
)
{
Unsupported ();

}

GLAPI void APIENTRY
TextureParameterIivEXT (GLuint
texture,
GLenum target, GLenum
pname,
const GLint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameterIiv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureParameterIuivEXT (GLuint
texture,
GLenum target, GLenum
pname,
const GLuint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexParameterIuiv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureParameterIivEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
GetTexParameterIiv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GetTextureParameterIuivEXT (GLuint
texture,
GLenum target, GLenum
pname,
GLuint *params
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
GetTexParameterIuiv (target, pname, params
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
MultiTexParameterIivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameterIiv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
MultiTexParameterIuivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
const GLuint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexParameterIuiv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexParameterIivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexParameterIiv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
GetMultiTexParameterIuivEXT (GLenum
texunit,
GLenum target, GLenum
pname,
GLuint *params
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GetTexParameterIuiv (target, pname, params
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
ProgramUniform1fEXT (GLuint
program,
GLint location, GLfloat
v0)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1f (location, v0
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2fEXT (GLuint
program,
GLint location, GLfloat
v0,
GLfloat v1
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2f (location, v0, v1
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3fEXT (GLuint
program,
GLint location, GLfloat
v0,
GLfloat v1, GLfloat
v2)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3f (location, v0, v1, v2
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4fEXT (GLuint
program,
GLint location, GLfloat
v0,
GLfloat v1, GLfloat
v2,
GLfloat v3
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4f (location, v0, v1, v2, v3
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1iEXT (GLuint
program,
GLint location, GLint
v0)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1i (location, v0
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2iEXT (GLuint
program,
GLint location, GLint
v0,
GLint v1
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2i (location, v0, v1
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3iEXT (GLuint
program,
GLint location, GLint
v0,
GLint v1, GLint
v2)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3i (location, v0, v1, v2
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4iEXT (GLuint
program,
GLint location, GLint
v0,
GLint v1, GLint
v2,
GLint v3
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4i (location, v0, v1, v2, v3
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1fvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1fv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2fvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2fv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3fvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3fv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4fvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4fv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1ivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1iv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2ivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2iv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3ivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3iv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4ivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4iv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2x3fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2x3fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3x2fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3x2fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2x4fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2x4fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4x2fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4x2fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3x4fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3x4fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4x3fvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLfloat *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4x3fv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1uiEXT (GLuint
program,
GLint location, GLuint
v0)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1ui (location, v0
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2uiEXT (GLuint
program,
GLint location, GLuint
v0,
GLuint v1
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2ui (location, v0, v1
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3uiEXT (GLuint
program,
GLint location, GLuint
v0,
GLuint v1, GLuint
v2)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3ui (location, v0, v1, v2
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4uiEXT (GLuint
program,
GLint location, GLuint
v0,
GLuint v1, GLuint
v2,
GLuint v3
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4ui (location, v0, v1, v2, v3
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1uivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLuint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1uiv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2uivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLuint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2uiv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3uivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLuint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3uiv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4uivEXT (GLuint
program,
GLint location, GLsizei
count,
const GLuint *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4uiv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
NamedBufferDataEXT (GLuint
buffer,
GLsizeiptr size,
const GLvoid *data, GLenum
usage)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
BufferData (GL_ARRAY_BUFFER, size, data, usage
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
NamedBufferSubDataEXT (GLuint
buffer,
GLintptr offset, GLsizeiptr
size,
const GLvoid *data
)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
BufferSubData (GL_ARRAY_BUFFER, offset, size, data
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI GLvoid
*

APIENTRY MapNamedBufferEXT (GLuint buffer, GLenum access)
{
    GLint saved;
    void *ptr;
    GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved);
    BindBuffer (GL_ARRAY_BUFFER, buffer);
    ptr = MapBuffer (GL_ARRAY_BUFFER, access);
    BindBuffer (GL_ARRAY_BUFFER, saved);
    return ptr;
}

GLAPI GLboolean

APIENTRY UnmapNamedBufferEXT (GLuint buffer)
{
    GLint saved;
    GLboolean result;
    GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved);
    BindBuffer (GL_ARRAY_BUFFER, buffer);
    result = UnmapBuffer (GL_ARRAY_BUFFER);
    BindBuffer (GL_ARRAY_BUFFER, saved);
    return result;
}

GLAPI GLvoid
*

APIENTRY MapNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    GLint saved;
    void *ptr;
    GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved);
    BindBuffer (GL_ARRAY_BUFFER, buffer);
    ptr = MapBufferRange (GL_ARRAY_BUFFER, offset, length, access);
    BindBuffer (GL_ARRAY_BUFFER, saved);
    return ptr;
}

GLAPI void APIENTRY
FlushMappedNamedBufferRangeEXT (GLuint
buffer,
GLintptr offset, GLsizeiptr
length)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
FlushMappedBufferRange (GL_ARRAY_BUFFER, offset, length
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
NamedCopyBufferSubDataEXT (GLuint
readBuffer,
GLuint writeBuffer, GLintptr
readOffset,
GLintptr writeOffset, GLsizeiptr
size)
{
GLint saved_read, saved_write;
GetIntegerv (GL_COPY_READ_BUFFER, &saved_read
);
GetIntegerv (GL_COPY_WRITE_BUFFER, &saved_write
);
BindBuffer (GL_COPY_READ_BUFFER, readBuffer
);
BindBuffer (GL_COPY_WRITE_BUFFER, writeBuffer
);
CopyBufferSubData (GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, readOffset, writeOffset, size
);
BindBuffer (GL_COPY_READ_BUFFER, saved_read
);
BindBuffer (GL_COPY_WRITE_BUFFER, saved_write
);
}

GLAPI void APIENTRY
GetNamedBufferParameterivEXT (GLuint
buffer,
GLenum pname, GLint
*params)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
GetBufferParameteriv (GL_ARRAY_BUFFER, pname, params
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
GetNamedBufferPointervEXT (GLuint
buffer,
GLenum pname, GLvoid
**params)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
GetBufferPointerv (GL_ARRAY_BUFFER, pname, params
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
GetNamedBufferSubDataEXT (GLuint
buffer,
GLintptr offset, GLsizeiptr
size,
GLvoid *data
)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
GetBufferSubData (GL_ARRAY_BUFFER, offset, size, data
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
TextureBufferEXT (GLuint
texture,
GLenum target, GLenum
internalformat,
GLuint buffer
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexBuffer (target, internalformat, buffer
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
MultiTexBufferEXT (GLenum
texunit,
GLenum target, GLenum
internalformat,
GLuint buffer
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexBuffer (target, internalformat, buffer
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
NamedRenderbufferStorageEXT (GLuint
renderbuffer,
GLenum internalformat, GLsizei
width,
GLsizei height
)
{
GLint saved;
GetIntegerv (GL_RENDERBUFFER_BINDING, &saved
);
BindRenderbuffer (GL_RENDERBUFFER, renderbuffer
);
RenderbufferStorage (GL_RENDERBUFFER, internalformat, width, height
);
BindRenderbuffer (GL_RENDERBUFFER, saved
);
}

GLAPI void APIENTRY
GetNamedRenderbufferParameterivEXT (GLuint
renderbuffer,
GLenum pname, GLint
*params)
{
GLint saved;
GetIntegerv (GL_RENDERBUFFER_BINDING, &saved
);
BindRenderbuffer (GL_RENDERBUFFER, renderbuffer
);
GetRenderbufferParameteriv (GL_RENDERBUFFER, pname, params
);
BindRenderbuffer (GL_RENDERBUFFER, saved
);
}

GLAPI GLenum

APIENTRY CheckNamedFramebufferStatusEXT (GLuint framebuffer, GLenum target)
{
    GLint saved_read, saved_draw;
    GLenum result;
    GetIntegerv (GL_READ_FRAMEBUFFER_BINDING, &saved_read);
    GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved_draw);
    BindFramebuffer (target, framebuffer);
    result = CheckFramebufferStatus (target);
    BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved_draw);
    BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved_read);
    return result;
}

GLAPI void APIENTRY
NamedFramebufferTexture1DEXT (GLuint
framebuffer,
GLenum attachment, GLenum
textarget,
GLuint texture, GLint
level)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferTexture1D (GL_DRAW_FRAMEBUFFER, attachment, textarget, texture, level
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedFramebufferTexture2DEXT (GLuint
framebuffer,
GLenum attachment, GLenum
textarget,
GLuint texture, GLint
level)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferTexture2D (GL_DRAW_FRAMEBUFFER, attachment, textarget, texture, level
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedFramebufferTexture3DEXT (GLuint
framebuffer,
GLenum attachment, GLenum
textarget,
GLuint texture, GLint
level,
GLint zoffset
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferTexture3D (GL_DRAW_FRAMEBUFFER, attachment, textarget, texture, level, zoffset
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedFramebufferRenderbufferEXT (GLuint
framebuffer,
GLenum attachment, GLenum
renderbuffertarget,
GLuint renderbuffer
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferRenderbuffer (GL_DRAW_FRAMEBUFFER, attachment, renderbuffertarget, renderbuffer
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
GetNamedFramebufferAttachmentParameterivEXT (GLuint
framebuffer,
GLenum attachment, GLenum
pname,
GLint *params
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
GetFramebufferAttachmentParameteriv (GL_DRAW_FRAMEBUFFER, attachment, pname, params
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
GenerateTextureMipmapEXT (GLuint
texture,
GLenum target
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
GenerateMipmap (target);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
GenerateMultiTexMipmapEXT (GLenum
texunit,
GLenum target
)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
GenerateMipmap (target);
ActiveTexture (saved);
}

GLAPI void APIENTRY
FramebufferDrawBufferEXT (GLuint
framebuffer,
GLenum mode
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
DrawBuffer (mode);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
FramebufferDrawBuffersEXT (GLuint
framebuffer,
GLsizei n,
const GLenum *bufs
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
DrawBuffers (n, bufs
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
FramebufferReadBufferEXT (GLuint
framebuffer,
GLenum mode
)
{
GLint saved;
GetIntegerv (GL_READ_FRAMEBUFFER, &saved
);
BindFramebuffer (GL_READ_FRAMEBUFFER, framebuffer
);
ReadBuffer (mode);
BindFramebuffer (GL_READ_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
GetFramebufferParameterivEXT (GLuint
framebuffer,
GLenum pname, GLint
*params)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
GetFramebufferParameteriv (GL_DRAW_FRAMEBUFFER, pname, params
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedRenderbufferStorageMultisampleEXT (GLuint
renderbuffer,
GLsizei samples, GLenum
internalformat,
GLsizei width, GLsizei
height)
{
GLint saved;
GetIntegerv (GL_RENDERBUFFER_BINDING, &saved
);
BindRenderbuffer (GL_RENDERBUFFER, renderbuffer
);
RenderbufferStorageMultisample (GL_RENDERBUFFER, samples, internalformat, width, height
);
BindRenderbuffer (GL_RENDERBUFFER, saved
);
}

GLAPI void APIENTRY
NamedRenderbufferStorageMultisampleCoverageEXT (GLuint
renderbuffer,
GLsizei coverageSamples,
        GLsizei
colorSamples,
GLenum internalformat,
        GLsizei
width,
GLsizei height
)
{
// TODO
Unsupported ();

}

GLAPI void APIENTRY
NamedFramebufferTextureEXT (GLuint
framebuffer,
GLenum attachment, GLuint
texture,
GLint level
)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferTexture (GL_DRAW_FRAMEBUFFER, attachment, texture, level
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedFramebufferTextureLayerEXT (GLuint
framebuffer,
GLenum attachment, GLuint
texture,
GLint level,
        GLint
layer)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferTextureLayer (GL_DRAW_FRAMEBUFFER, attachment, texture, level, layer
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
NamedFramebufferTextureFaceEXT (GLuint
framebuffer,
GLenum attachment, GLuint
texture,
GLint level,
        GLenum
face)
{
Unsupported ();

}

GLAPI void APIENTRY
TextureRenderbufferEXT (GLuint
texture,
GLenum target, GLuint
renderbuffer)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
TexRenderbufferNV (target, renderbuffer
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
MultiTexRenderbufferEXT (GLenum
texunit,
GLenum target, GLuint
renderbuffer)
{
GLint saved;
GetIntegerv (GL_ACTIVE_TEXTURE, &saved
);
ActiveTexture (texunit);
TexRenderbufferNV (target, renderbuffer
);
ActiveTexture (saved);
}

GLAPI void APIENTRY
ProgramUniform1dEXT (GLuint
program,
GLint location, GLdouble
x)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1d (location, x
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2dEXT (GLuint
program,
GLint location, GLdouble
x,
GLdouble y
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2d (location, x, y
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3dEXT (GLuint
program,
GLint location, GLdouble
x,
GLdouble y, GLdouble
z)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3d (location, x, y, z
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4dEXT (GLuint
program,
GLint location, GLdouble
x,
GLdouble y, GLdouble
z,
GLdouble w
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4d (location, x, y, z, w
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform1dvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform1dv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform2dvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform2dv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform3dvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform3dv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniform4dvEXT (GLuint
program,
GLint location, GLsizei
count,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
Uniform4dv (location, count, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2x3dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2x3dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix2x4dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix2x4dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3x2dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3x2dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix3x4dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix3x4dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4x2dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4x2dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
ProgramUniformMatrix4x3dvEXT (GLuint
program,
GLint location, GLsizei
count,
GLboolean transpose,
const GLdouble *value
)
{
GLint saved;
GetIntegerv (GL_CURRENT_PROGRAM, &saved
);
UseProgram (program);
UniformMatrix4x3dv (location, count, transpose, value
);
UseProgram (saved);
}

GLAPI void APIENTRY
VertexArrayVertexAttribOffsetEXT (GLuint
vaobj,
GLuint buffer, GLuint
index,
GLint size,
        GLenum
type,
GLboolean normalized, GLsizei
stride,
GLintptr offset
)
{
GLint saved_vao, saved_ab;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved_vao
);
BindVertexArray (vaobj);
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved_ab
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
VertexAttribPointer (index, size, type, normalized, stride, (
const GLvoid *) offset);
BindBuffer (GL_ARRAY_BUFFER, saved_ab
);
BindVertexArray (saved_vao);
}

GLAPI void APIENTRY
EnableVertexArrayAttribEXT (GLuint
vaobj,
GLenum array
)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
EnableVertexAttribArray (array);
BindVertexArray (saved);
}

GLAPI void APIENTRY
DisableVertexArrayAttribEXT (GLuint
vaobj,
GLenum array
)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
DisableVertexAttribArray (array);
BindVertexArray (saved);
}

GLAPI void APIENTRY
TextureStorage1DEXT (GLuint
texture,
GLenum target, GLsizei
levels,
GLenum internalformat,
        GLsizei
width)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexStorage1D (target, levels, internalformat, width
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureStorage2DEXT (GLuint
texture,
GLenum target, GLsizei
levels,
GLenum internalformat,
        GLsizei
width,
GLsizei height
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
detail::BindTexture (target, texture
);
TexStorage2D (target, levels, internalformat, width, height
);
detail::BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureStorage3DEXT (GLuint
texture,
GLenum target, GLsizei
levels,
GLenum internalformat,
        GLsizei
width,
GLsizei height, GLsizei
depth)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexStorage3D (target, levels, internalformat, width, height, depth
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
ClearNamedBufferDataEXT (GLuint
buffer,
GLenum internalformat, GLenum
format,
GLenum type,
const void *data
)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
ClearBufferData (GL_ARRAY_BUFFER, internalformat, format, type, data
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
ClearNamedBufferSubDataEXT (GLuint
buffer,
GLenum internalformat, GLenum
format,
GLenum type,
        GLsizeiptr
offset,
GLsizeiptr size,
const void *data
)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
ClearBufferSubData (GL_ARRAY_BUFFER, internalformat, format, type, offset, size, data
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
VertexArrayBindVertexBufferEXT (GLuint
vaobj,
GLuint bindingindex, GLuint
buffer,
GLintptr offset,
        GLsizei
stride)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
BindVertexBuffer (bindingindex, buffer, offset, stride
);
BindVertexArray (saved);
}

GLAPI void APIENTRY
VertexArrayVertexAttribFormatEXT (GLuint
vaobj,
GLuint attribindex, GLint
size,
GLenum type,
        GLboolean
normalized,
GLuint relativeoffset
)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
VertexAttribFormat (attribindex, size, type, normalized, relativeoffset
);
BindVertexArray (saved);
}

GLAPI void APIENTRY
VertexArrayVertexAttribIFormatEXT (GLuint
vaobj,
GLuint attribindex, GLint
size,
GLenum type,
        GLuint
relativeoffset)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
VertexAttribIFormat (attribindex, size, type, relativeoffset
);
BindVertexArray (saved);
}

GLAPI void APIENTRY
VertexArrayVertexAttribLFormatEXT (GLuint
vaobj,
GLuint attribindex, GLint
size,
GLenum type,
        GLuint
relativeoffset)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
VertexAttribLFormat (attribindex, size, type, relativeoffset
);
BindVertexArray (saved);
}

GLAPI void APIENTRY
VertexArrayVertexAttribBindingEXT (GLuint
vaobj,
GLuint attribindex, GLuint
bindingindex)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
VertexAttribBinding (attribindex, bindingindex
);
BindVertexArray (saved);
}

GLAPI void APIENTRY
VertexArrayVertexBindingDivisorEXT (GLuint
vaobj,
GLuint bindingindex, GLuint
divisor)
{
GLint saved;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved
);
BindVertexArray (vaobj);
VertexBindingDivisor (bindingindex, divisor
);
BindVertexArray (saved);

}

GLAPI void APIENTRY
NamedFramebufferParameteriEXT (GLuint
framebuffer,
GLenum pname, GLint
param)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
FramebufferParameteri (GL_DRAW_FRAMEBUFFER, pname, param
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
GetNamedFramebufferParameterivEXT (GLuint
framebuffer,
GLenum pname, GLint
*params)
{
GLint saved;
GetIntegerv (GL_DRAW_FRAMEBUFFER_BINDING, &saved
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, framebuffer
);
GetFramebufferParameteriv (GL_DRAW_FRAMEBUFFER, pname, params
);
BindFramebuffer (GL_DRAW_FRAMEBUFFER, saved
);
}

GLAPI void APIENTRY
TextureBufferRangeEXT (GLuint
texture,
GLenum target, GLenum
internalformat,
GLuint buffer,
        GLintptr
offset,
GLsizeiptr size
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexBufferRange (target, internalformat, buffer, offset, size
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureStorage2DMultisampleEXT (GLuint
texture,
GLenum target, GLsizei
samples,
GLenum internalformat, GLsizei
width,
GLsizei height,
        GLboolean
fixedsamplelocations)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexStorage2DMultisample (target, samples, internalformat, width, height, fixedsamplelocations
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
TextureStorage3DMultisampleEXT (GLuint
texture,
GLenum target, GLsizei
samples,
GLenum internalformat, GLsizei
width,
GLsizei height, GLsizei
depth,
GLboolean fixedsamplelocations
)
{
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (target), &saved
);
BindTexture (target, texture
);
TexStorage3DMultisample (target, samples, internalformat, width, height, depth, fixedsamplelocations
);
BindTexture (target, saved
);
}

GLAPI void APIENTRY
EnableIndexedEXT (GLenum
cap,
GLuint index
)
{
GLint savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
Enable (cap);
ActiveTexture (savedActiveTexture);
}

GLAPI void APIENTRY
DisableIndexedEXT (GLenum
cap,
GLuint index
)
{
GLint savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
Disable (cap);
ActiveTexture (savedActiveTexture);
}

GLAPI GLboolean

APIENTRY IsEnabledIndexedEXT (GLenum target, GLuint index)
{
    int savedActiveTexture;
    GLboolean rv;
    GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture);
    ActiveTexture (GL_TEXTURE0 + index);
    rv = IsEnabled (target);
    ActiveTexture (savedActiveTexture);
    return rv;
}

GLAPI void APIENTRY
GetIntegerIndexedvEXT (GLenum
target,
GLuint index, GLint
*data)
{
int savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
GetIntegerv (target, data
);
ActiveTexture (savedActiveTexture);
}

GLAPI void APIENTRY
GetBooleanIndexedvEXT (GLenum
target,
GLuint index, GLboolean
*data)
{
int savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
GetBooleanv (target, data
);
ActiveTexture (savedActiveTexture);
}

GLAPI void APIENTRY
EnableClientStateiEXT (GLenum
array,
GLuint index
)
{
Unsupported ();

}

GLAPI void APIENTRY
DisableClientStateiEXT (GLenum
array,
GLuint index
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetFloati_vEXT (GLenum
pname,
GLuint index, GLfloat
*params)
{
int savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
GetFloatv (pname, params
);
ActiveTexture (savedActiveTexture);

}

GLAPI void APIENTRY
GetDoublei_vEXT (GLenum
pname,
GLuint index, GLdouble
*params)
{
int savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
GetDoublev (pname, params
);
ActiveTexture (savedActiveTexture);

}

GLAPI void APIENTRY
GetPointeri_vEXT (GLenum
pname,
GLuint index, GLvoid
**params)
{
int savedActiveTexture;
GetIntegerv (GL_ACTIVE_TEXTURE, &savedActiveTexture
);
ActiveTexture (GL_TEXTURE0
+ index);
GetPointerv (pname, params
);
ActiveTexture (savedActiveTexture);
}

GLAPI void APIENTRY
VertexArrayVertexOffsetEXT (GLuint
vaobj,
GLuint buffer, GLint
size,
GLenum type, GLsizei
stride,
GLintptr offset
)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayColorOffsetEXT (GLuint
vaobj,
GLuint buffer, GLint
size,
GLenum type, GLsizei
stride,
GLintptr offset
)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayEdgeFlagOffsetEXT (GLuint
vaobj,
GLuint buffer, GLsizei
stride,
GLintptr offset
)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayIndexOffsetEXT (GLuint
vaobj,
GLuint buffer, GLenum
type,
GLsizei stride,
        GLintptr
offset)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayNormalOffsetEXT (GLuint
vaobj,
GLuint buffer, GLenum
type,
GLsizei stride,
        GLintptr
offset)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayTexCoordOffsetEXT (GLuint
vaobj,
GLuint buffer, GLint
size,
GLenum type, GLsizei
stride,
GLintptr offset
)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayMultiTexCoordOffsetEXT (GLuint
vaobj,
GLuint buffer, GLenum
texunit,
GLint size,
        GLenum
type,
GLsizei stride, GLintptr
offset)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayFogCoordOffsetEXT (GLuint
vaobj,
GLuint buffer, GLenum
type,
GLsizei stride,
        GLintptr
offset)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArraySecondaryColorOffsetEXT (GLuint
vaobj,
GLuint buffer, GLint
size,
GLenum type,
        GLsizei
stride,
GLintptr offset
)
{
Unsupported ();

}

GLAPI void APIENTRY
VertexArrayVertexAttribIOffsetEXT (GLuint
vaobj,
GLuint buffer, GLuint
index,
GLint size,
        GLenum
type,
GLsizei stride, GLintptr
offset)
{
GLint saved_vao, saved_ab;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved_vao
);
BindVertexArray (vaobj);
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved_ab
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
VertexAttribIPointer (index, size, type, stride, (
const GLvoid *) offset);
BindBuffer (GL_ARRAY_BUFFER, saved_ab
);
BindVertexArray (saved_vao);
}

GLAPI void APIENTRY
EnableVertexArrayEXT (GLuint
vaobj,
GLenum array
)
{
Unsupported ();

}

GLAPI void APIENTRY
DisableVertexArrayEXT (GLuint
vaobj,
GLenum array
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetVertexArrayIntegervEXT (GLuint
vaobj,
GLenum pname, GLint
*param)
{
Unsupported ();

}

GLAPI void APIENTRY
GetVertexArrayPointervEXT (GLuint
vaobj,
GLenum pname, GLvoid
**param)
{
Unsupported ();

}

GLAPI void APIENTRY
GetVertexArrayIntegeri_vEXT (GLuint
vaobj,
GLuint index, GLenum
pname,
GLint *param
)
{
Unsupported ();

}

GLAPI void APIENTRY
GetVertexArrayPointeri_vEXT (GLuint
vaobj,
GLuint index, GLenum
pname,
GLvoid **param
)
{
Unsupported ();

}

GLAPI void APIENTRY
NamedBufferStorageEXT (GLuint
buffer,
GLsizeiptr size,
const void *data, GLbitfield
flags)
{
GLint saved;
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
BufferStorage (GL_ARRAY_BUFFER, size, data, flags
);
BindBuffer (GL_ARRAY_BUFFER, saved
);
}

GLAPI void APIENTRY
VertexArrayVertexAttribLOffsetEXT (GLuint
vaobj,
GLuint buffer, GLuint
index,
GLint size,
        GLenum
type,
GLsizei stride, GLintptr
offset)
{
GLint saved_vao, saved_ab;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved_vao
);
BindVertexArray (vaobj);
GetIntegerv (GL_ARRAY_BUFFER_BINDING, &saved_ab
);
BindBuffer (GL_ARRAY_BUFFER, buffer
);
VertexAttribLPointer (index, size, type, stride, (
const GLvoid *) offset);
BindBuffer (GL_ARRAY_BUFFER, saved_ab
);
BindVertexArray (saved_vao);
}

GLAPI void APIENTRY
VertexArrayVertexAttribDivisorEXT (GLuint
vaobj,
GLuint index, GLuint
divisor)
{
GLint saved_vao;
GetIntegerv (GL_VERTEX_ARRAY_BINDING, &saved_vao
);
BindVertexArray (vaobj);
VertexAttribDivisor (index, divisor
);
BindVertexArray (saved_vao);
}

GLAPI void APIENTRY
TexturePageCommitmentEXT (GLuint
texture,
GLint level, GLint
xoffset,
GLint yoffset, GLint
zoffset,
GLsizei width, GLsizei
height,
GLsizei depth, GLboolean
resident)
{
GLuint targets[] = {
        GL_TEXTURE_1D,
        GL_TEXTURE_2D,
        GL_TEXTURE_3D,
        GL_TEXTURE_1D_ARRAY,
        GL_TEXTURE_2D_ARRAY,
        GL_TEXTURE_RECTANGLE,
        GL_TEXTURE_CUBE_MAP,
        GL_TEXTURE_CUBE_MAP_ARRAY,
        GL_TEXTURE_BUFFER,
        GL_TEXTURE_2D_MULTISAMPLE,
        GL_TEXTURE_2D_MULTISAMPLE_ARRAY
};

// Can't reasonably implement this, as there is no target parameter
CheckError ();

int i;
for (
i = 0;
i < sizeof (targets) / sizeof (targets[0]); i++) {
GLint saved;
GetIntegerv (detail::TextureTargetToBinding (targets[i]), &saved
);

BindTexture (targets[i], texture
);
if (

GetError ()

== GL_INVALID_OPERATION) {
BindTexture (targets[i], saved
);
continue;
}

TexPageCommitmentARB (targets[i], level, xoffset, yoffset, zoffset, width, height, depth, resident
);
BindTexture (targets[i], saved
);
return;
}

// generate error
TexPageCommitmentARB (0, level, xoffset, yoffset, zoffset, width, height, depth, resident);
}


} /* namespace dsawrap */
} /* namespace oglp */

#endif /* ! defined OGLP_DSAWRAP_CXX */
