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
#include "sampler.h"

namespace gl {

Sampler::Sampler (void)
{
	GenSamplers (1, &obj);
	CheckError ();
}

Sampler::Sampler (Sampler &&sampler) : obj (sampler.obj)
{
	GenSamplers (1, &sampler.obj);
	CheckError ();
}

Sampler::~Sampler (void)
{
	DeleteSamplers (1, &obj);
	CheckError ();
}

Sampler &Sampler::operator= (Sampler &&sampler)
{
	obj = sampler.obj;
	GenSamplers (1, &sampler.obj);
	CheckError ();
}

void Sampler::Bind (GLuint unit) const
{
	BindSampler (unit, obj);
	CheckError ();
}

void Sampler::Parameter (GLenum pname, GLfloat param)
{
	SamplerParameterf (obj, pname, param);
	CheckError ();
}

void Sampler::Parameter (GLenum pname, GLint param)
{
	SamplerParameteri (obj, pname, param);
	CheckError ();
}

void Sampler::Parameter (GLenum pname, const GLfloat *params)
{
	SamplerParameterfv (obj, pname, params);
	CheckError ();
}

void Sampler::Parameter (GLenum pname, const GLint *params)
{
	SamplerParameteriv (obj, pname, params);
	CheckError ();
}

GLuint Sampler::get (void) const
{
	return obj;
}

} /* namespace gl */
