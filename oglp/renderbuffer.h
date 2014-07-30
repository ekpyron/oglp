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
#ifndef OGLP_RENDERBUFFER_H
#define OGLP_RENDERBUFFER_H

#include "common.h"

namespace oglp {

/** OpenGL renderbuffer object.
 * A wrapper class around an OpenGL renderbuffer object.
 */
class Renderbuffer
{
public:
	 /** Default constructor.
		* Creates a new Renderbuffer object.
		*/
	 Renderbuffer (void) {
		 GenRenderbuffers (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move constuctor.
		* Passes the internal OpenGL renderbuffer object to another
		* Renderbuffer object.
		* \param renderbuffer The Renderbuffer object to move.
		*/
	 Renderbuffer (Renderbuffer &&renderbuffer) : obj (renderbuffer.obj) {
		 GenRenderbuffers (1, &renderbuffer.obj);
		 CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A Renderbuffer object can't be copy constructed.
		*/
	 Renderbuffer (const Renderbuffer&) = delete;
	 /**
		* A destructor.
		* Deletes a Renderbuffer object.
		*/
	 ~Renderbuffer (void) {
		 DeleteRenderbuffers (1, &obj);
		 CheckError ();
	 }
	 /**
		* Move assignment.
		* Passes the internal OpenGL renderbuffer object to another
		* Renderbuffer object.
		* \param renderbuffer The Renderbuffer object to move.
		* \return A reference to the Renderbuffer object.
		*/
	 Renderbuffer &operator= (Renderbuffer &&renderbuffer) {
	     DeleteRenderbuffers (1, &obj);
		 obj = renderbuffer.obj;
		 GenRenderbuffers (1, &renderbuffer.obj);
		 CheckError ();
		 return *this;
	 }
	 /**
		* Deleted copy assignment.
		* A Renderbuffer object can't be copy assigned.
		* \return
		*/
	 Renderbuffer &operator= (const Renderbuffer&) = delete;
	 /**
		* Label the renderbuffer object.
		* Labels the internal OpenGL renderbuffer object.
		* \param name Label to be used for the renderbuffer object.
		*/
	 void Label (const std::string &name) {
		ObjectLabel (GL_RENDERBUFFER, obj, name.length (), name.data ());
		CheckError ();
	 }
	 /**
		* Setup the internal storage of a Renderbuffer object.
		* Establishes the data storage, format and dimensions of the internal
		* OpenGL renderbuffer object's image.
		* \param internalformat Specifies the internal format to use for
		*                       the renderbuffer object's image.
		* \param width Specifies the width of the Renderbuffer, in pixels.
		* \param height Specifies the height of the Renderbuffer, in pixels.
		*/
	 void Storage (GLenum internalformat, GLsizei width,
								 GLsizei height) const {
		 NamedRenderbufferStorageEXT (obj, internalformat, width, height);
		 CheckError ();
	 }
	 /**
		* Setup the internal storage of a Renderbuffer object.
		* Establishes the data storage, format and dimensions of the internal
		* OpenGL renderbuffer object's image.
		* \param samples Specifies the number of samples to be used
		*                for the renderbuffer object's storage.
		* \param internalformat Specifies the internal format to use for
		*                       the renderbuffer object's image.
		* \param width Specifies the width of the Renderbuffer, in pixels.
		* \param height Specifies the height of the Renderbuffer, in pixels.
		*/
	 void StorageMultisample (GLsizei samples, GLenum internalformat,
														GLsizei width, GLsizei height) const {
		 NamedRenderbufferStorageMultisampleEXT (obj, samples, internalformat,
																						 width, height);
		 CheckError ();
	 }
	 /**
		* Return internal object.
		* Returns the internal renderbuffer object. Use with caution.
		* \return The internal OpenGL renderbuffer object.
		*/
	 GLuint get (void) const {
		 return obj;
	 }
   /**
		* Swap internal object.
		* Swaps the internal OpenGL renderbuffer object with another
		* Renderbuffer.
		*/
	 void swap (Renderbuffer &renderbuffer) {
		 std::swap (obj, renderbuffer.obj);
	 }
private:
	 /**
		* internal OpenGL renderbuffer object
		*/
	 GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_RENDERBUFFER_H */
