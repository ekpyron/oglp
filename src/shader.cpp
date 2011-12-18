/*
 * This file is part of glcp.
 *
 * glcp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glcp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glcp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "shader.h"
#include <vector>

namespace gl {

Shader::Shader (void) : obj (0)
{
}

Shader::Shader (GLenum type)
{
	obj = CreateShader (type);
	CheckError ();
}

Shader::Shader (Shader &&s) : obj (s.obj)
{
	s.obj = 0;
}

Shader::~Shader (void)
{
	if (obj)
	{
		DeleteShader (obj);
		CheckError ();
		obj = 0;
	}
}

Shader &Shader::operator= (Shader &&s)
{
	obj = s.obj;
	s.obj = 0;
}

void Shader::Create (GLenum type)
{
	if (obj)
	{
		 DeleteShader (obj);
	}
	obj = CreateShader (type);
	CheckError ();
}

void Shader::Source (const std::string &source) const
{
	const GLchar *src = source.c_str ();
	ShaderSource (obj, 1, &src, NULL);

	CheckError ();
}

bool Shader::Compile (void) const
{
	GLint status;
	CompileShader (obj);
	
	GetShaderiv (obj, GL_COMPILE_STATUS, &status);
	CheckError ();
	return status;
}

std::string Shader::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetShaderiv (obj, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetShaderInfoLog (obj, length, NULL, &log[0]);
	return std::string (&log[0], length);
}

GLuint Shader::get (void) const
{
	return obj;
}

} /* namespace gl */
