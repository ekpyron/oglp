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

namespace gl {

ProgramPipeline::ProgramPipeline (void)
{
	GenProgramPipelines (1, &pipeline);
	CheckError ();
}

ProgramPipeline::ProgramPipeline (ProgramPipeline &&p)
	: pipeline (p.pipeline)
{
	GenProgramPipelines (1, &p.pipeline);
	CheckError ();
}

ProgramPipeline::~ProgramPipeline (void)
{
	DeleteProgramPipelines (1, &pipeline);	
	CheckError ();
}

ProgramPipeline &ProgramPipeline::operator= (ProgramPipeline &&p)
{
	pipeline = p.pipeline;
	GenProgramPipelines (1, &p.pipeline);
	CheckError ();
}

void ProgramPipeline::Bind (void) const
{
	BindProgramPipeline (pipeline);
	CheckError ();
}

void ProgramPipeline::UseProgramStages (GLbitfield stages,
																			 const Program &program)
{
	gl::UseProgramStages (pipeline, stages, program.get ());
	CheckError ();
}

bool ProgramPipeline::Validate (void) const
{
	GLint status;
	ValidateProgramPipeline (pipeline);
	GetProgramPipelineiv (pipeline, GL_VALIDATE_STATUS, &status);
	CheckError ();
	return status;
}

std::string ProgramPipeline::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetProgramPipelineiv (pipeline, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetProgramPipelineInfoLog (pipeline, length, &length, &log[0]);
	CheckError ();
	return std::string (&log[0], length);
}

void ProgramPipeline::ActiveShaderProgram (const Program &program) const
{
	gl::ActiveShaderProgram (pipeline, program.get ());
	CheckError ();
}

GLuint ProgramPipeline::get (void) const
{
	return pipeline;
}

} /* namespace gl */
