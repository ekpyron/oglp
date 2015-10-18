/*
 * Copyright 2015 Daniel Kirchner
 *
 * This file is part of midium.
 *
 * midium is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * midium is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with midium.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OGLP_PROGRAMPIPELINE_H
#define OGLP_PROGRAMPIPELINE_H

#include "common.h"
#include "program.h"
#include <string>

namespace oglp {

/** OpenGL shader pipeline object.
 * A wrapper class around an OpenGL shader program pipeline.
 */
class ProgramPipeline
{
public:
    /** Default constructor.
       * Creates a new ProgramPipeline object.
       */
    ProgramPipeline (void)
    {
        CreateProgramPipelines (1, &obj);
        CheckError ();
    }

    /**
       * Move constuctor.
       * Passes the internal OpenGL shader pipeline object to
       * another ProgramPipeline object.
       * \param pipeline The ProgramPipeline object to move.
       */
    ProgramPipeline (ProgramPipeline &&pipeline) noexcept
    {
        GLuint tmp = obj;
        obj = pipeline.obj;
        pipeline.obj = tmp;
    }

    /**
       * Deleted copy constructor.
       * A ProgramPipeline object can't be copy constructed.
       */
    ProgramPipeline (const ProgramPipeline &) = delete;

    /**
       * A destructor.
       * Deletes a ProgramPipeline object.
       */
    ~ProgramPipeline (void)
    {
        DeleteProgramPipelines (1, &obj);
    }

    /**
       * Move assignment.
       * Passes the internal OpenGL shader pipeline object to another
       * ProgramPipeline object.
       * \param pipeline The ProgramPipeline object to move.
       * \return A reference to the ProgramPipeline object.
       */
    ProgramPipeline &operator= (ProgramPipeline &&pipeline) noexcept
    {
        GLuint tmp = obj;
        obj = pipeline.obj;
        pipeline.obj = tmp;
        return *this;
    }

    /**
       * Deleted copy assignment.
       * A ProgramPipeline object can't be copy assigned.
       * \return
       */
    ProgramPipeline &operator= (const ProgramPipeline &) = delete;

    /**
       * Label the program pipeline object.
       * Labels the internal OpenGL program pipeline object.
       * \param name Label to be used for the program pipeline object.
       */
    void Label (const std::string &name)
    {
        ObjectLabel (GL_PROGRAM_PIPELINE, obj, name.length (), name.data ());
        CheckError ();
    }

    /**
       * Bind the ProgramPipeline object.
       * Binds the internal OpenGL shader pipeline object.
       */
    void Bind (void) const
    {
        BindProgramPipeline (obj);
        CheckError ();
    }

    /**
       * Bind stages of a ShaderProgram to a ProgramPipeline.
       * Binds stages of a OpenGL program object contained in a ShaderProgram
       * object to the internal OpenGL program pipeline.
   * \param program Specifies the ShaderProgram object containing the
       *                shader executables to use in the ProgramPipeline.
       * \param stages Specifies a set of program stages to bind
       *               to the program pipeline object.
       */
    void UseProgramStages (GLbitfield stages, const Program &program) const
    {
        oglp::UseProgramStages (obj, stages, program.get ());
        CheckError ();
    }

    /**
       * Validates the ProgramPipeline against the current OpenGL state.
       * \return Returns the validation status.
       */
    bool Validate (void) const
    {
        GLint status;
        ValidateProgramPipeline (obj);
        GetProgramPipelineiv (obj, GL_VALIDATE_STATUS, &status);
        CheckError ();
        return status;
    }

    /**
       * Get the info log.
       * Obtains the info log of the internal OpenGL program pipeline object
       * \return A string containing the info log.
       */
    std::string GetInfoLog (void) const
    {
        GLint length;
        std::vector <GLchar> log;
        GetProgramPipelineiv (obj, GL_INFO_LOG_LENGTH, &length);
        log.resize (length);
        GetProgramPipelineInfoLog (obj, length, &length, &log[0]);
        CheckError ();
        return std::string (&log[0], length);
    }

    /**
         * Set active shader program.
         * Sets the active program object for a program pipeline object.
         * \param program Specifies the program object to set as the
         *                active program.
         */
    void ActiveShaderProgram (const Program &program) const
    {
        oglp::ActiveShaderProgram (obj, program.get ());
        CheckError ();
    }

    /**
       * Return internal object.
       * Returns the internal OpenGL program pipeline object. Use with caution.
       * \return The internal OpenGL program pipeline object.
       */
    GLuint get (void) const
    {
        return obj;
    }

private:
    /**
       * internal OpenGL program pipeline object
       */
    GLuint obj;
};

} /* namespace oglp */

#endif /* !defined PROGRAMPIPELINE_H */
