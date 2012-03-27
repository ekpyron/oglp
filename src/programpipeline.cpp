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
#include "programpipeline.h"
#include <algorithm>

namespace gl {

ProgramPipeline::ProgramPipeline (void)
{
	GenProgramPipelines (1, &obj);
	CheckError ();
}

ProgramPipeline::ProgramPipeline (ProgramPipeline &&p)
	: obj (p.obj)
{
	GenProgramPipelines (1, &p.obj);
	CheckError ();
}

ProgramPipeline::~ProgramPipeline (void)
{
	DeleteProgramPipelines (1, &obj);
	CheckError ();
}

ProgramPipeline &ProgramPipeline::operator= (ProgramPipeline &&p)
{
	obj = p.obj;
	GenProgramPipelines (1, &p.obj);
	CheckError ();
}

void ProgramPipeline::Bind (void) const
{
	BindProgramPipeline (obj);
	CheckError ();
}

void ProgramPipeline::UseProgramStages (GLbitfield stages,
																			 const Program &program)
{
	gl::UseProgramStages (obj, stages, program.get ());
	CheckError ();
}

bool ProgramPipeline::Validate (void) const
{
	GLint status;
	ValidateProgramPipeline (obj);
	GetProgramPipelineiv (obj, GL_VALIDATE_STATUS, &status);
	CheckError ();
	return status;
}

std::string ProgramPipeline::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetProgramPipelineiv (obj, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetProgramPipelineInfoLog (obj, length, &length, &log[0]);
	CheckError ();
	return std::string (&log[0], length);
}

void ProgramPipeline::ActiveShaderProgram (const Program &program) const
{
	gl::ActiveShaderProgram (obj, program.get ());
	CheckError ();
}

void ProgramPipeline::swap (ProgramPipeline &pipeline)
{
	std::swap (obj, pipeline.obj);
}

GLuint ProgramPipeline::get (void) const
{
	return obj;
}

} /* namespace gl */
