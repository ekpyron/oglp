/*
 * This is NOT an official header by The Khronos Group Inc.
 *
 * This header is a subset of glext.h that ONLY exposes the
 * definitions and entry points for GL_NV_explicit_multisample.
 *
 */
/*
** Copyright (c) 2007-2011 The Khronos Group Inc.
** 
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
** 
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
** 
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/
#include "../glcorearb.h"

#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
#define GL_SAMPLE_POSITION_NV             0x8E50
#define GL_SAMPLE_MASK_NV                 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV           0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_MAX_SAMPLE_MASK_WORDS_NV       0x8E59
#define GL_TEXTURE_RENDERBUFFER_NV        0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV        0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV    0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glGetMultisamplefvNV (GLenum, GLuint, GLfloat *);
GLAPI void APIENTRY glSampleMaskIndexedNV (GLuint, GLbitfield);
GLAPI void APIENTRY glTexRenderbufferNV (GLenum, GLuint);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVNVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKINDEXEDNVPROC) (GLuint index, GLbitfield mask);
typedef void (APIENTRYP PFNGLTEXRENDERBUFFERNVPROC) (GLenum target, GLuint renderbuffer);
#endif
