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
/** @file */
#ifndef OGLP_CXX
#define OGLP_CXX

#include "oglp.h"
#include "glcorew.cxx"

namespace oglp {

#ifdef _WIN32
namespace internal {
/* This workaround falls back to loading symbols
 * directly from OpenGL32.dll, as wglGetProcAddress
 * may return NULL for legacy opengl entry points. */
static HMODULE _opengl32dllhandle = NULL;
static GetProcAddressCallback _usergetprocaddress = NULL;
inline void *_getprocaddress (const char *name)
{
	void *ptr = NULL;
	if (_usergetprocaddress)
		 ptr = _usergetprocaddress (name);
	if (!ptr && _opengl32dllhandle)
		 ptr = (void*) GetProcAddress (_opengl32dllhandle, name);
	return ptr;
}
} /* namespace internal */
#endif

bool IsExtensionSupported (const std::string &name) {
	int num, i;
	GetIntegerv (GL_NUM_EXTENSIONS, &num);
	for (i = 0; i < num; i++)
	{
		const GLubyte *ext = GetStringi (GL_EXTENSIONS, i);
		if (!name.compare (reinterpret_cast<const char*> (ext)))
			 return true;
	}
	return false;
}

void Init (GetProcAddressCallback callback) {
	std::vector<std::string> needed_extensions = {
		"GL_ARB_separate_shader_objects",
		"GL_ARB_sampler_objects",
		"GL_EXT_direct_state_access"
	};
	std::stringstream version;
	int major, minor;

#ifdef _WIN32
	internal::_opengl32dllhandle = LoadLibrary ("OPENGL32.DLL");
	internal::_usergetprocaddress = callback;
	InitPrototypes (internal::_getprocaddress);
#else
	InitPrototypes (callback);
#endif
	if (!GetString || GetString == (PFNGLGETSTRINGPROC) oglp::Unsupported)
		 throw std::runtime_error ("No entry point for glGetString found.");

	version << GetString (GL_VERSION);
	CheckError ();
	version >> major;
	version.ignore (1);
	version >> minor;

	if (major < 3)
		 throw std::runtime_error ("OpenGL version 3.0 or higher is required.");
	for (std::string &extension : needed_extensions)
	{
		if (!IsExtensionSupported (extension))
		{
			throw std::runtime_error (extension + " is required.");
		}
	}
}

} /* namespace oglp */

#endif /* !defined OGLP_CXX */
