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
#include "program.h"
#include <iostream>
#include <algorithm>

namespace gl {

Program::Program (void) : obj (0)
{
	obj = CreateProgram ();
	CheckError ();
}

Program::Program (Program &&p) : obj (p.obj)
{
	p.obj = CreateProgram ();
	CheckError ();
}

Program::~Program (void)
{
	if (obj)
	{
		DeleteProgram (obj);
		CheckError ();
		obj = 0;
	}
}

Program &Program::operator= (Program &&p)
{
	obj = p.obj;
	p.obj = CreateProgram ();
	CheckError ();
}

bool Program::Create (GLenum type, const std::string &source)
{
	const GLchar *src = source.c_str ();
	GLint status;
	DeleteProgram (obj);
	obj = CreateShaderProgramv (type, 1, &src);
	if (!obj)
	{
		obj = CreateProgram ();
		return false;
	}

	GetProgramiv (obj, GL_LINK_STATUS, &status);
	CheckError ();
	return status;
}

std::string Program::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetProgramiv (obj, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetProgramInfoLog (obj, length, NULL, &log[0]);
	CheckError ();
	return std::string (&log[0], length);
}

Uniform Program::operator[] (const std::string &name) const
{
	GLint location;
	location = GetUniformLocation (obj, name.c_str ());
	CheckError ();
	return Uniform (obj, location);
}

void Program::Parameter (GLenum pname, GLint value) const
{
	ProgramParameteri (obj, pname, value);
	CheckError ();
}

void Program::Attach (const Shader &shader) const
{
	AttachShader (obj, shader.get ());
	CheckError ();
}

bool Program::Link (void) const
{
	GLint status;
	LinkProgram (obj);
	Get (GL_LINK_STATUS, &status);
	return status;
}

bool Program::Binary (GLenum binaryFormat, const void *binary,
											GLsizei length) const
{
	GLint status;
	ProgramBinary (obj, binaryFormat, binary, length);
	GLenum err = GetError ();
	if (err == GL_INVALID_ENUM)
		 return false;
	if (err != GL_NO_ERROR)
		 throw Exception (err);
	Get (GL_LINK_STATUS, &status);
	return status;
}

void Program::GetBinary (GLsizei bufsize, GLsizei *length,
												 GLenum *binaryFormat, void *binary) const
{
	GetProgramBinary (obj, bufsize, length, binaryFormat, binary);
	CheckError ();
}

void Program::Get (GLenum pname, GLint *params) const
{
	GetProgramiv (obj, pname, params);
	CheckError ();
}

void Program::Use (void) const
{
	UseProgram (obj);
	CheckError ();
}

void Program::UseNone (void)
{
	UseProgram (0);
	CheckError ();
}

GLint Program::GetSubroutineUniformLocation (GLenum shadertype,
																						 const std::string &name) const
{
	GLint location;
	location = gl::GetSubroutineUniformLocation (obj, shadertype, name.c_str ());
	CheckError ();
	return location;
}

GLuint Program::GetSubroutineIndex (GLenum shadertype,
																		const std::string &name) const
{
	GLuint index;
	index = gl::GetSubroutineIndex (obj, shadertype, name.c_str ());
	CheckError ();
	return index;
}

void Program::GetActiveSubroutineUniform (GLenum shadertype,
																					GLuint index,
																					GLenum pname,
																					GLint *values) const
{
	GetActiveSubroutineUniformiv (obj, shadertype, index, pname, values);
	CheckError ();
}

std::string Program::GetActiveSubroutineUniformName (GLenum shadertype,
																										 GLuint index) const
{
	GLint len = 0;
	std::vector<char> buf;
	GetActiveSubroutineUniform (shadertype, index, GL_UNIFORM_NAME_LENGTH, &len);
	buf.resize (len);
	gl::GetActiveSubroutineUniformName (obj, shadertype, index, len,
																			NULL, &buf[0]);
	CheckError ();
	return std::string (&buf[0]);
}

std::string Program::GetActiveSubroutineName (GLenum shadertype,
																							GLuint index) const
{
	GLint len = 0;
	std::vector<char> buf;
	GetProgramStage (shadertype, GL_ACTIVE_SUBROUTINE_MAX_LENGTH, &len);
	buf.resize (len);
	gl::GetActiveSubroutineName (obj, shadertype, index, len, NULL, &buf[0]);
	CheckError ();
	return std::string (&buf[0]);
}

void Program::GetProgramStage (GLenum shadertype, GLenum pname,
															 GLint *values) const
{
	GetProgramStageiv (obj, shadertype, pname, values);
	CheckError ();
}

void Program::swap (Program &program)
{
	std::swap (obj, program.obj);
}

GLuint Program::get (void) const
{
	return obj;
}

} /* namespace gl */
