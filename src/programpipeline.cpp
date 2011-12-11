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
#include "programpipeline.h"

namespace gl {

ProgramPipeline::ProgramPipeline (void)
{
	GenProgramPipelines (1, &pipeline);
	GLP_CHECK_ERROR;
}

ProgramPipeline::ProgramPipeline (ProgramPipeline &&p)
	: pipeline (p.pipeline)
{
	GenProgramPipelines (1, &p.pipeline);
	GLP_CHECK_ERROR;
}

ProgramPipeline::~ProgramPipeline (void)
{
	DeleteProgramPipelines (1, &pipeline);	
	GLP_CHECK_ERROR;
}

ProgramPipeline &ProgramPipeline::operator= (ProgramPipeline &&p)
{
	pipeline = p.pipeline;
	GenProgramPipelines (1, &p.pipeline);
	GLP_CHECK_ERROR;
}

void ProgramPipeline::Bind (void) const
{
	BindProgramPipeline (pipeline);
	GLP_CHECK_ERROR;
}

void ProgramPipeline::UseProgramStages (GLbitfield stages,
																			 const Program &program)
{
	gl::UseProgramStages (pipeline, stages, program.program);
	GLP_CHECK_ERROR;
}

bool ProgramPipeline::Validate (void) const
{
	GLint status;
	ValidateProgramPipeline (pipeline);
	GetProgramPipelineiv (pipeline, GL_VALIDATE_STATUS, &status);
	GLP_CHECK_ERROR;
	return status;
}

std::string ProgramPipeline::GetInfoLog (void) const
{
	GLint length;
	std::vector<GLchar> log;
	GetProgramPipelineiv (pipeline, GL_INFO_LOG_LENGTH, &length);
	log.resize (length);
	GetProgramPipelineInfoLog (pipeline, length, &length, &log[0]);
	GLP_CHECK_ERROR;
	return std::string (&log[0], length);
}

} /* namespace gl */
