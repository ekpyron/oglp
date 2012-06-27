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
#include "uniform.h"

namespace gl {

Uniform::Uniform (void) : location (-1), program (0)
{
}

Uniform::Uniform (const Uniform &u)
	: location (u.location), program (u.program)
{
}

Uniform::Uniform (GLuint prog, GLuint loc)
	: program (prog), location (loc)
{
}

Uniform::~Uniform (void)
{
}

Uniform &Uniform::operator= (const Uniform &u)
{
	location = u.location;
	program = u.program;
	return *this;
}

GLfloat Uniform::operator= (GLfloat v)
{
	if (location != -1)
	{
		ProgramUniform1f (program, location, v);
		CheckError ();
	}
	return v;
}

void Uniform::Set (const GLfloat *v, size_t N)
{
	if (location != -1)
	{
		ProgramUniform1fv (program, location, N, v);
		CheckError ();
	}
}

const glm::vec2 &Uniform::operator= (const glm::vec2 &v)
{
	if (location != -1)
	{
		ProgramUniform2fv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::vec3 &Uniform::operator= (const glm::vec3 &v)
{
	if (location != -1)
	{
		ProgramUniform3fv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::vec4 &Uniform::operator= (const glm::vec4 &v)
{
	if (location != -1)
	{
		ProgramUniform4fv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

GLint Uniform::operator= (GLint v)
{
	if (location != -1)
	{
		ProgramUniform1i (program, location, v);
		CheckError ();
	}
	return v;
}

const glm::ivec2 &Uniform::operator= (const glm::ivec2 &v)
{
	if (location != -1)
	{
		ProgramUniform2iv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::ivec3 &Uniform::operator= (const glm::ivec3 &v)
{
	if (location != -1)
	{
		ProgramUniform3iv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::ivec4 &Uniform::operator= (const glm::ivec4 &v)
{
	if (location != -1)
	{
		ProgramUniform4iv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

GLuint Uniform::operator= (GLuint v)
{
	if (location != -1)
	{
		ProgramUniform1ui (program, location, v);
		CheckError ();
	}
	return v;
}

const glm::uvec2 &Uniform::operator= (const glm::uvec2 &v)
{
	if (location != -1)
	{
		ProgramUniform2uiv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::uvec3 &Uniform::operator= (const glm::uvec3 &v)
{
	if (location != -1)
	{
		ProgramUniform3uiv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::uvec4 &Uniform::operator= (const glm::uvec4 &v)
{
	if (location != -1)
	{
		ProgramUniform4uiv (program, location, 1, &v[0]);
		CheckError ();
	}
	return v;
}

const glm::mat2 &Uniform::operator= (const glm::mat2 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix2fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat3 &Uniform::operator= (const glm::mat3 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix3fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat4 &Uniform::operator= (const glm::mat4 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix4fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat2x3 &Uniform::operator= (const glm::mat2x3 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix2x3fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat3x2 &Uniform::operator= (const glm::mat3x2 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix3x2fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat2x4 &Uniform::operator= (const glm::mat2x4 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix2x4fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat4x2 &Uniform::operator= (const glm::mat4x2 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix4x2fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat3x4 &Uniform::operator= (const glm::mat3x4 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix3x4fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

const glm::mat4x3 &Uniform::operator= (const glm::mat4x3 &m)
{
	if (location != -1)
	{
		ProgramUniformMatrix4x3fv (program, location, 1, GL_FALSE, &m[0][0]);
		CheckError ();
	}
	return m;
}

Uniform::operator bool (void)
{
	return location != -1;
}

void Uniform::Get (GLfloat *params)
{
	GetUniformfv (program, location, params);
	CheckError ();
}

void Uniform::Get (GLint *params)
{
	GetUniformiv (program, location, params);
	CheckError ();
}

} /* namespace gl */
