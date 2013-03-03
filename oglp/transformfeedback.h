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
#ifndef OGLP_TRANSFORMFEEDBACK_H
#define OGLP_TRANSFORMFEEDBACK_H

#include "common.h"
#include "query.h"

namespace oglp {

/**
 * TransformFeedback class.
 * Wrapper class for transform feedback operations.
 * When an TransformFeedback object is created,
 * a transform feedback operation is startet and when
 * it is destructed, the operation is automatically ended.
 */
class TransformFeedback
{
public:
	/**
	 * Constructor.
	 * Creates a new TransformFeedback object and starts
	 * a transform feedback operation
	 * \param primitiveMode Specify the output type of the primitives
	 *                      that will be recorded into the buffer objects
	 *                      that are bound for transform feedback.
	 */
	 TransformFeedback (GLenum primitiveMode) {
		 BeginTransformFeedback (primitiveMode);
		 CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A TransformFeedback object can't be copy constructed.
		*/
	 TransformFeedback (const TransformFeedback&) = delete;
	 /**
		* A destructor.
		* Deletes the TransformFeedback object and
		* automatically ends the transform feedback operation.
		*/
	 ~TransformFeedback (void) {
		 EndTransformFeedback ();
		 CheckError ();
	 }
	 /**
		* Deleted copy assignment.
		* A TransformFeedback object can't be copy assigned.
		* \return
		*/
	 TransformFeedback &operator= (const TransformFeedback&) = delete;
};

} /* namespace oglp */

#endif /* !defined OGLP_TRANSFORMFEEDBACK_H */
