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
#ifndef GLCP_SAMPLER_H
#define GLCP_SAMPLER_H

#include "common.h"

namespace gl {

/** OpenGL sampler object.
 * A wrapper class around an OpenGL Sampler object.
 */
class Sampler
{
public:
	 /** Default constructor.
		* Creates a new Sampler object.
		*/
	 Sampler (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL sampler object to another Sampler object.
		*/
	 Sampler (Sampler &&sampler);
	 /**
		* Deleted copy constructor.
		* A Sampler object can't be copy constructed.
		*/
	 Sampler (const Sampler&) = delete;
	 /**
		* A destructor.
		* Deletes a Sampler object.
		*/
	 ~Sampler (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL sampler object to another Sampler object.
		*/
	 Sampler &operator= (Sampler &&sampler);
	 /**
		* Deleted copy assignment.
		* A Sampler object can't be copy assigned.
		*/
	 Sampler &operator= (const Sampler&) = delete;
	 /**
		* Bind the Sampler object.
		* Binds the Sampler object to the specified target.
		* \param unit Specifies the index of the texture unit to which to
		*             bind the sampler to.
		*/
	 void Bind (GLuint unit) const;
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_R,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_MAX_LOD, GL_TEXTURE_LOD_BIAS
		*              GL_TEXTURE_COMPARE_MODE, or GL_TEXTURE_COMPARE_FUNC.
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum pname, GLfloat param);
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_R,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_MAX_LOD, GL_TEXTURE_LOD_BIAS
		*              GL_TEXTURE_COMPARE_MODE, or GL_TEXTURE_COMPARE_FUNC.
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum pname, GLint param);
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_R,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_MIN_LOD, GL_TEXTURE_MAX_LOD, GL_TEXTURE_LOD_BIAS
		*              GL_TEXTURE_COMPARE_MODE, or GL_TEXTURE_COMPARE_FUNC.
		* \param params Specifies the values for pname.
		*/
	 void Parameter (GLenum pname, const GLfloat *params);
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_R,
		*              GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER,
		*              GL_TEXTURE_BORDER_COLOR, GL_TEXTURE_MIN_LOD,
		*              GL_TEXTURE_MAX_LOD, GL_TEXTURE_LOD_BIAS
		*              GL_TEXTURE_COMPARE_MODE, or GL_TEXTURE_COMPARE_FUNC.
		* \param params Specifies a pointer to an array where the value or values
		*               of pname are stored.
		*/
	 void Parameter (GLenum pname, const GLint *params);
	 /**
		* Return internal object.
		* Returns the internal OpenGL sampler object. Use with caution.
		* \return The internal OpenGL sampler object.
		*/
	 GLuint get (void) const;
private:
	 /**
		* internal OpenGL sampler object
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined GLCP_SAMPLER_H */
