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
#ifndef GLP_RENDERBUFFER_H
#define GLP_RENDERBUFFER_H

#include "common.h"

namespace gl {

/** An OpenGL renderbuffer object.
 * A wrapper class around an OpenGL renderbuffer object.
 */
class Renderbuffer
{
public:
	 /** Default constructor.
		* Creates a new Renderbuffer object.
		*/
	 Renderbuffer (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL renderbuffer object to another
		* Renderbuffer object.
		*/
	 Renderbuffer (Renderbuffer &&renderbuffer);
	 /**
		* Deleted copy constructor.
		* A Renderbuffer object can't be copy constructed.
		*/
	 Renderbuffer (const Renderbuffer&) = delete;
	 /**
		* A destructor.
		* Deletes a Renderbuffer object.
		*/
	 ~Renderbuffer (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL renderbuffer object to another
		* Renderbuffer object.
		*/
	 Renderbuffer &operator= (Renderbuffer &&renderbuffer);
	 /**
		* Deleted copy assignment.
		* A Renderbuffer object can't be copy assigned.
		*/
	 Renderbuffer &operator= (const Renderbuffer&) = delete;
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
								 GLsizei height) const;
private:
	 /**
		* internal OpenGL renderbuffer object
		*/
	 GLuint obj;
	 friend class Framebuffer;
};

} /* namespace gl */

#endif /* !defined GLP_RENDERBUFFER_H */
