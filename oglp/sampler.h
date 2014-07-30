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
#ifndef OGLP_SAMPLER_H
#define OGLP_SAMPLER_H

#include "common.h"

namespace oglp {

/** OpenGL sampler object.
 * A wrapper class around an OpenGL Sampler object.
 */
class Sampler
{
public:
	 /** Default constructor.
		* Creates a new Sampler object.
		*/
	 Sampler (void) {
		 GenSamplers (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL sampler object to another Sampler object.
		* \param sampler Sampler object to move.
		*/
	 Sampler (Sampler &&sampler) : obj (sampler.obj) {
		 GenSamplers (1, &sampler.obj);
		 CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A Sampler object can't be copy constructed.
		*/
	 Sampler (const Sampler&) = delete;
	 /**
		* A destructor.
		* Deletes a Sampler object.
		*/
	 ~Sampler (void) {
		 DeleteSamplers (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move assignment.
		* Passes the internal OpenGL sampler object to another Sampler object.
		* \param sampler Sampler object to move.
		* \return A reference to the Sampler object.
		*/
	 Sampler &operator= (Sampler &&sampler) {
	     DeleteSamplers (1, &obj);
		 obj = sampler.obj;
		 GenSamplers (1, &sampler.obj);
		 CheckError ();
	 }
	 /**
		* Deleted copy assignment.
		* A Sampler object can't be copy assigned.
		* \return
		*/
	 Sampler &operator= (const Sampler&) = delete;
	 /**
		* Label the sampler object.
		* Labels the internal OpenGL sampler object.
		* \param name Label to be used for the sampler object.
		*/
	 void Label (const std::string &name) {
		ObjectLabel (GL_SAMPLER, obj, name.length (), name.data ());
		CheckError ();
	 }
	 /**
		* Bind the Sampler object.
		* Binds the Sampler object to the specified target.
		* \param unit Specifies the index of the texture unit to which to
		*             bind the sampler to.
		*/
	 void Bind (GLuint unit) const {
		 BindSampler (unit, obj);
		 CheckError ();
	 }
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_COMPARE_FUNC.
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum pname, GLfloat param) {
		 SamplerParameterf (obj, pname, param);
		 CheckError ();
	 }
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_COMPARE_FUNC
		* \param param Specifies the value of pname.
		*/
	 void Parameter (GLenum pname, GLint param) {
		 SamplerParameteri (obj, pname, param);
		 CheckError ();
	 }
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_COMPARE_FUNC.
		* \param params Specifies the values for pname.
		*/
	 void Parameter (GLenum pname, const GLfloat *params) {
		 SamplerParameterfv (obj, pname, params);
		 CheckError ();
	 }
	 /** Set Sampler parameters.
		* Sets the parameters of the internal sampler object.
		* \param pname Specifies the symbolic name of a single-valued sampler
		*              parameter. pname can be one of the following:
		*              - GL_TEXTURE_WRAP_S
		*              - GL_TEXTURE_WRAP_T
		*              - GL_TEXTURE_WRAP_R
		*              - GL_TEXTURE_MIN_FILTER
		*              - GL_TEXTURE_MAG_FILTER
		*              - GL_TEXTURE_BORDER_COLOR
		*              - GL_TEXTURE_MIN_LOD
		*              - GL_TEXTURE_MAX_LOD
		*              - GL_TEXTURE_LOD_BIAS
		*              - GL_TEXTURE_COMPARE_MODE
		*              - GL_TEXTURE_COMPARE_FUNC
		* \param params Specifies a pointer to an array where the value or values
		*               of pname are stored.
		*/
	 void Parameter (GLenum pname, const GLint *params) {
		 SamplerParameteriv (obj, pname, params);
		 CheckError ();
	 }
	 /**
		* Return internal object.
		* Returns the internal OpenGL sampler object. Use with caution.
		* \return The internal OpenGL sampler object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL sampler object with another Sampler.
		* \param sampler Object with which to swap the internal sampler object.
		*/
	 void swap (Sampler &sampler) {
		 std::swap (obj, sampler.obj);
	 }
private:
	 /**
		* internal OpenGL sampler object
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_SAMPLER_H */
