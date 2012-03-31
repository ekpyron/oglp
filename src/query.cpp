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
#include "query.h"
#include <algorithm>

namespace gl {

Query::Query (void)
{
	GenQueries (1, &obj);
	CheckError ();
}

Query::Query (Query &&query)
	: obj (query.obj)
{
	GenQueries (1, &query.obj);
	CheckError ();
}

Query::~Query (void)
{
	DeleteQueries (1, &obj);
	CheckError ();
}

Query &Query::operator= (Query &&query)
{
	obj = query.obj;
	GenQueries (1, &query.obj);
	CheckError ();
}

void Query::swap (Query &query)
{
	std::swap (obj, query.obj);
}

GLuint Query::get (void) const
{
	return obj;
}

void Query::Begin (GLenum target)
{
	BeginQuery (target, obj);
	CheckError ();
}

void Query::End (GLenum target)
{
	EndQuery (target);
	CheckError ();
}

void Query::Get (GLenum pname, GLint *params)
{
	GetQueryObjectiv (obj, pname, params);
	CheckError ();
}

void Query::Get (GLenum pname, GLuint *params)
{
	GetQueryObjectuiv (obj, pname, params);
	CheckError ();
}

void Query::Get (GLenum pname, GLint64 *params)
{
	GetQueryObjecti64v (obj, pname, params);
	CheckError ();
}

void Query::Get (GLenum pname, GLuint64 *params)
{
	GetQueryObjectui64v (obj, pname, params);
	CheckError ();
} 

} /* namespace gl */
