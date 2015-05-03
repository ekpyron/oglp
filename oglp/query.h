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
#ifndef OGLP_QUERY_H
#define OGLP_QUERY_H

#include "common.h"

namespace oglp {

/** OpenGL Query object.
 * A wrapper class around an OpenGL Query object.
 */
class Query
{
public:
    /**
     * Default contructor.
     * Creates a new Query object.
     */
    Query (void)
    {
        GenQueries (1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL Query object to another Query object.
       * \param query The Query object to move.
       */
    Query (Query &&query) noexcept
    {
        GLuint tmp = obj;
        obj = query.obj;
        query.obj = tmp;
    }

    /**
       * Deleted copy constructor.
       * A Query object can't be copy constructed.
       */
    Query (const Query &) = delete;

    /**
       * A destructor.
       * Deletes a Query object.
       */
    ~Query (void)
    {
        DeleteQueries (1, &obj);
    }

    /**
       * Move assignment.
       * Passes the internal OpenGL Query object to another Query object.
       * \param query The Query object to move.
       * \return A reference to the Query object.
       */
    Query &operator= (Query &&query) noexcept
    {
        GLuint tmp = obj;
        obj = query.obj;
        query.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A Query object can't be copy assigned.
       * \return
       */
    Query &operator= (const Query &) = delete;

    /**
       * Return internal object.
       * Returns the internal OpenGL Query object. Use with caution.
       * \return The internal OpenGL Query object.
       */
    GLuint get (void) const
    {
        return obj;
    }

    /**
       * Label the query object.
       * Labels the internal OpenGL query object.
       * \param name Label to be used for the query object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_QUERY, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Delimits the boundaries of a query object.
       * Delimits the boundaries of the internal OpenGL query object.
       * \param target Specifies the target type of query object established
       *               between glBeginQuery and the subsequent glEndQuery.
       *               The symbolic constant must be one of GL_SAMPLES_PASSED,
       *               GL_ANY_SAMPLES_PASSED, GL_PRIMITIVES_GENERATED,
       *               GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, or
       *               GL_TIME_ELAPSED.
       */
    void Begin (GLenum target) const
    {
        BeginQuery (target, obj);
        CheckError ();
    }

    /**
       * Delimits the boundaries of a query object.
       * Delimits the boundaries of the internal OpenGL query object.
       * \param target Specifies the target type of query object established
       *               between glBeginQuery and the subsequent glEndQuery.
       *               The symbolic constant must be one of GL_SAMPLES_PASSED,
       *               GL_ANY_SAMPLES_PASSED, GL_PRIMITIVES_GENERATED,
       *               GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, or
       *               GL_TIME_ELAPSED.
       * \param index Specifies the index of the query target upon which
       *              to begin the query.
       */
    void BeginIndexed (GLenum target, GLuint index) const
    {
        BeginQueryIndexed (target, index, obj);
        CheckError ();
    }

    /**
       * Delimits the boundaries of a query object.
       * Delimits the boundaries of the internal OpenGL query object.
       * \param target Specifies the target type of query object to be concluded.
       *               The symbolic constant must be one of GL_SAMPLES_PASSED,
       *               GL_ANY_SAMPLES_PASSED, GL_PRIMITIVES_GENERATED,
       *               GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, or
       *               GL_TIME_ELAPSED.
       */
    static void End (GLenum target)
    {
        EndQuery (target);
        CheckError ();
    }

    /**
       * Delimits the boundaries of a query object.
       * Delimits the boundaries of the internal OpenGL query object.
       * \param target Specifies the target type of query object to be concluded.
       *               The symbolic constant must be one of GL_SAMPLES_PASSED,
       *               GL_ANY_SAMPLES_PASSED, GL_PRIMITIVES_GENERATED,
       *               GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, or
       *               GL_TIME_ELAPSED.
       * \param index Specifies the index of the query target upon which
       *              to end the query.
       */
    static void EndIndexed (GLenum target, GLuint index)
    {
        EndQueryIndexed (target, index);
        CheckError ();
    }

    /**
       * Return parameters of a query object.
       * Returns parameters of the internal OpenGL query object.
       * \param pname Specifies the symbolic name of a query object parameter.
       *              Accepted values are GL_QUERY_RESULT or
       *              GL_QUERY_RESULT_AVAILABLE.
       * \param params Returns the requested data.
       */
    void Get (GLenum pname, GLint *params) const
    {
        GetQueryObjectiv (obj, pname, params);
        CheckError ();
    }

    /**
       * Return parameters of a query object.
       * Returns parameters of the internal OpenGL query object.
       * \param pname Specifies the symbolic name of a query object parameter.
       *              Accepted values are GL_QUERY_RESULT or
       *              GL_QUERY_RESULT_AVAILABLE.
       * \param params Returns the requested data.
       */
    void Get (GLenum pname, GLuint *params) const
    {
        GetQueryObjectuiv (obj, pname, params);
        CheckError ();
    }

    /**
       * Return parameters of a query object.
       * Returns parameters of the internal OpenGL query object.
       * \param pname Specifies the symbolic name of a query object parameter.
       *              Accepted values are GL_QUERY_RESULT or
       *              GL_QUERY_RESULT_AVAILABLE.
       * \param params Returns the requested data.
       */
    void Get (GLenum pname, GLint64 *params) const
    {
        GetQueryObjecti64v (obj, pname, params);
        CheckError ();
    }

    /**
       * Return parameters of a query object.
       * Returns parameters of the internal OpenGL query object.
       * \param pname Specifies the symbolic name of a query object parameter.
       *              Accepted values are GL_QUERY_RESULT or
       *              GL_QUERY_RESULT_AVAILABLE.
       * \param params Returns the requested data.
       */
    void Get (GLenum pname, GLuint64 *params) const
    {
        GetQueryObjectui64v (obj, pname, params);
        CheckError ();
    }

    /**
       * Checks validity.
       * Returns whether the internal OpenGL query object is valid.
       * \return whether the internal OpenGL query object is valid.
       */
    bool IsQuery (void) const
    {
        bool result;
        result = oglp::IsQuery (obj);
        CheckError ();
        return result;
    }

    /**
       * Start conditional rendering.
       * Starts conditional rendering.
       * \param mode Specifies how glBeginConditionalRender interprets
       *             the results of the occlusion query.
       */
    void BeginConditionalRender (GLenum mode) const
    {
        oglp::BeginConditionalRender (obj, mode);
        CheckError ();
    }

    /**
       * End conditional rendering.
       * Ends conditional rendering.
       */
    static void EndConditionalRender (void)
    {
        oglp::EndConditionalRender ();
        CheckError ();
    }

private:
    /**
       * internal OpenGL query object name
       */
    GLuint obj;
};

} /* namespace oglp */

#endif /* !defined OGLP_QUERY_H */
