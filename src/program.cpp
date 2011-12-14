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
#include "program.h"
#include <iostream>

namespace gl {

Program::Program (void) : program (0)
{
	program = CreateProgram ();
	CheckError ();
}

Program::Program (Program &&p) : program (p.program)
{
	p.program = CreateProgram ();
	CheckError ();
}

Program::~Program (void)
{
	if (program)
	{
		DeleteProgram (program);
		CheckError ();
		program = 0;
	}
}

Program &Program::operator= (Program &&p)
{
	program = p.program;
	p.program = CreateProgram ();
	CheckError ();
}

bool Program::Create (GLenum type, const std::string &source)
{
	const GLchar *src = source.c_str ();
	GLint status;
	DeleteProgram (program);
	program = CreateShaderProgramv (type, 1, &src);
	if (!program)
	{
		program = CreateProgram ();
		return false;
	}

	GetProgramiv (program, GL_LINK_STATUS, &status);
	CheckError ();
	return status;
}

std::string Program::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetProgramiv (program, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetProgramInfoLog (program, length, NULL, &log[0]);
	CheckError ();
	return std::string (&log[0], length);
}

Uniform Program::operator[] (const std::string &name) const
{
	GLint location;
	location = GetUniformLocation (program, name.c_str ());
	CheckError ();
	return Uniform (program, location);
}

void Program::Parameter (GLenum pname, GLint value) const
{
	ProgramParameteri (program, pname, value);
	CheckError ();
}

void Program::Attach (const Shader &shader) const
{
	AttachShader (program, shader.get ());
	CheckError ();
}

bool Program::Link (void) const
{
	GLint status;
	LinkProgram (program);
	GetProgramiv (program, GL_LINK_STATUS, &status);
	CheckError ();
	return status;
}

void Program::Use (void) const
{
	UseProgram (program);
	CheckError ();
}

void Program::UseNone (void)
{
	UseProgram (0);
	CheckError ();
}

GLuint Program::get (void) const
{
	return program;
}

} /* namespace gl */
