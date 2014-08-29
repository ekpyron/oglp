/*
 * This is NOT an official header by The Khronos Group Inc.
 *
 * This header is a subset of glext.h that ONLY exposes the
 * definitions and entry points for GL_NV_vertex_buffer_unified_memory.
 *
 */
/*
** Copyright (c) 2013-2014 The Khronos Group Inc.
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

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV       0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV        0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV        0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV         0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV         0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV     0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV     0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV       0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV  0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV         0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV         0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV          0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV          0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV  0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV      0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV      0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV        0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV       0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV       0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV        0x8F42
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC) (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC) (GLsizei stride);
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC) (GLenum value, GLuint index, GLuint64EXT *result);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC) (GLenum cap);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glBufferAddressRangeNV (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
GLAPI void APIENTRY glVertexFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glNormalFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glColorFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glIndexFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glTexCoordFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glEdgeFlagFormatNV (GLsizei stride);
GLAPI void APIENTRY glSecondaryColorFormatNV (GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glFogCoordFormatNV (GLenum type, GLsizei stride);
GLAPI void APIENTRY glVertexAttribFormatNV (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
GLAPI void APIENTRY glVertexAttribIFormatNV (GLuint index, GLint size, GLenum type, GLsizei stride);
GLAPI void APIENTRY glGetIntegerui64i_vNV (GLenum value, GLuint index, GLuint64EXT *result);
GLAPI void APIENTRY glEnableClientState (GLenum cap);
#endif
#endif /* GL_NV_vertex_buffer_unified_memory */
