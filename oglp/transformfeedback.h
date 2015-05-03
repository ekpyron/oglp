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
 * OpenGL TransformFeedback object.
 * A wrapper class around an OpenGL transform feedback object.
 */
class TransformFeedback
{
public:
    /**
       * Default constructor.
       * Creates a new TransformFeedback object.
       */
    TransformFeedback (void)
    {
        GenTransformFeedbacks (1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL transform feedback object to
       * another TransformFeedback object.
       * \param t The TransformFeedback object to move.
       */
    TransformFeedback (TransformFeedback &&t) noexcept
    {
        GLuint tmp = obj;
        obj = t.obj;
        t.obj = tmp;
    }

    /**
       * A destructor.
       * Deletes a TransformFeedback object.
       */
    ~TransformFeedback (void)
    {
        DeleteTransformFeedbacks (1, &obj);
    }

    /**
       * Deleted copy assignment.
       * A TransformFeedback object can't be copy assigned.
       */
    TransformFeedback (const TransformFeedback &) = delete;

    /**
       * Move assignment.
       * Passes the internal OpenGL transform feedback object to another
       * TransformFeedback object.
       * \param t The TransformFeedback object to move.
       * \return A reference to the transform feedback object.
       */
    TransformFeedback &operator= (TransformFeedback &&t) noexcept
    {
        GLuint tmp = obj;
        obj = t.obj;
        t.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A TransformFeedback object can't be copy assigned.
       * \return
       */
    TransformFeedback &operator= (const TransformFeedback &) = delete;

    /**
       * Label the transform feedback object.
       * Labels the internal OpenGL transform feedback object.
       * \param name Label to be used for the transform feedback object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_TRANSFORM_FEEDBACK, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Bind a transform feedback object.
       * Binds a transform feedback object.
       * \param target Specifies the target to which to bind the
       *               transform feedback object. target must be
       *               GL_TRANSFORM_FEEDBACK.
       */
    void Bind (GLenum target) const
    {
        BindTransformFeedback (target, obj);
        CheckError ();
    }

    /**
         * Determine if a name corresponds to a transform feedback object.
         * Determines if a name corresponds to a transform feedback object.
         * \returns Whether the internal object is a valid OpenGL
         *          transform feedback object.
         */
    GLboolean IsTransformFeedback (void) const
    {
        GLboolean result;
        result = oglp::IsTransformFeedback (obj);
        CheckError ();
        return result;
    }

    /**
         * Pause transform feedback operations.
         * Pauses transform feedback operations.
         */
    static void Pause (void)
    {
        PauseTransformFeedback ();
        CheckError ();
    }

    /**
         * Resume transform feedback operations.
         * Resumes transform feedback operations.
         */
    static void Resume (void)
    {
        ResumeTransformFeedback ();
        CheckError ();
    }
private:
    GLuint obj;
};

/**
 * TransformFeedbackOperation class.
 * Wrapper class for transform feedback operations.
 * When an TransformFeedbackOperation object is created,
 * a transform feedback operation is startet and when
 * it is destructed, the operation is automatically ended.
 */
class TransformFeedbackOperation
{
public:
    /**
     * Constructor.
     * Creates a new TransformFeedbackOperation object and starts
     * a transform feedback operation
     * \param primitiveMode Specify the output type of the primitives
     *                      that will be recorded into the buffer objects
     *                      that are bound for transform feedback.
     */
    TransformFeedbackOperation (GLenum primitiveMode)
    {
        BeginTransformFeedback (primitiveMode);
        CheckError ();
    }

    /**
       * Deleted copy constructor.
       * A TransformFeedbackOperation object can't be copy constructed.
       */
    TransformFeedbackOperation (const TransformFeedbackOperation &) = delete;

    /**
       * A destructor.
       * Deletes the TransformFeedbackOperation object and
       * automatically ends the transform feedback operation.
       */
    ~TransformFeedbackOperation (void)
    {
        EndTransformFeedback ();
    }

    /**
       * Deleted copy assignment.
       * A TransformFeedbackOperation object can't be copy assigned.
       * \return
       */
    TransformFeedbackOperation &operator= (const TransformFeedbackOperation &) = delete;
};

} /* namespace oglp */

#endif /* !defined OGLP_TRANSFORMFEEDBACK_H */
