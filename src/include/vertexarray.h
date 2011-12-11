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
#ifndef GLP_VERTEXARRAY_H
#define GLP_VERTEXARRAY_H

#include "common.h"

namespace gl {

/** An OpenGL vertex array object.
 * A wrapper class around an OpenGL vertex array object.
 */
class VertexArray
{
public:
	/**
	 * Default contructor.
	 * Creates a new VertexArray object.
	 */
	 VertexArray (void);
	 /**
		* Move constuctor.
		* Passes the internal OpenGL vertex array object to
		* another VertexArray object.
		*/
	 VertexArray (VertexArray &&va);
	 /**
		* Deleted copy constructor.
		* A VertexArray object can't be copy constructed.
		*/
	 VertexArray (const VertexArray&) = delete;
	 /**
		* A destructor.
		* Deletes a VertexArray object.
		*/
	 ~VertexArray (void);
	 /**
		* Move assignment.
		* Passes the internal OpenGL vertex array object to
		* another VertexArray object.
		*/
	 VertexArray &operator= (VertexArray &&va);
	 /**
		* Deleted copy assignment.
		* A VertexArray object can't be copy assigned.
		*/
	 VertexArray &operator= (const VertexArray&) = delete;
	 /**
		* Bind the VertexArray object.
		* Binds the internal OpenGL vertex array object.
		*/
	 void Bind (void) const;
private:
	 /**
		* internal OpenGL vertex array object
		*/
	 GLuint obj;
};

} /* namespace gl */

#endif /* !defined GLP_VERTEXARRAY_H */
