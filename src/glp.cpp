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
#include "glp.h"
#include <stdexcept>
#include <sstream>

namespace gl {

bool IsExtensionSupported (const std::string &name)
{
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

void Init (GetProcAddressCallback callback)
{
	std::vector<std::string> needed_extensions = {
		"GL_ARB_separate_shader_objects",
		"GL_ARB_sampler_objects",
		"GL_EXT_direct_state_access"
	};
	std::stringstream version;
	int major, minor;
	InitPrototypes (callback);
	if (!GetString)
		 throw std::runtime_error ("No entry point for glGetString found.");

	version << GetString (GL_VERSION);
	GLP_CHECK_ERROR;
	version >> major;
	version.ignore (1);
	version >> minor;

	if (major < 3 || (major == 3 && minor < 3))
		 throw std::runtime_error ("OpenGL version 3.3 or higher is required.");
	for (std::string &extension : needed_extensions)
	{
		if (!IsExtensionSupported (extension))
		{
			throw std::runtime_error (extension + " is required.");
		}
	}
}

} /* namespace gl */
