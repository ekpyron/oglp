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
#ifndef OGLP_CONDITIONALRENDER_H
#define OGLP_CONDITIONALRENDER_H

#include "common.h"
#include "query.h"

namespace oglp {

/**
 * Conditional render class.
 * Wrapper class for conditional rendering.
 * When an ConditionalRender object is created,
 * conditional rendering is started and when
 * it is destructed, conditional rendering is
 * automatically ended.
 */
class ConditionalRender
{
public:
	/**
	 * Constructor.
	 * Creates a new ConditionalRender object and begins
	 * conditional rendering.
	 * \param query Query as a condition for rendering.
	 * \param mode Specifies how glBeginConditionalRender interprets
	 *             the results of the occlusion query.
	 */
	 ConditionalRender (const Query &query, GLenum mode) {
		 query.BeginConditionalRender (mode);
		 CheckError ();
	 }
	 /**
		* Deleted copy constructor.
		* A ConditionalRender object can't be copy constructed.
		*/
	 ConditionalRender (const ConditionalRender&) = delete;
	 /**
		* A destructor.
		* Deletes the ConditionalRender object and
		* automatically ends the conditional rendering.
		*/
	 ~ConditionalRender (void) {
		 Query::EndConditionalRender ();
		 CheckError ();
	 }
	 /**
		* Deleted copy assignment.
		* A Query object can't be copy assigned.
		* \return
		*/
	 ConditionalRender &operator= (const ConditionalRender&) = delete;
};

} /* namespace oglp */

#endif /* !defined OGLP_QUERY_H */
