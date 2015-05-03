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
#ifndef OGLP_UNIFORM_H
#define OGLP_UNIFORM_H

#include "common.h"
#include <vector>
#include <array>

namespace oglp {

/**
 * OpenGL uniform location object.
 * A wrapper class around an OpenGL uniform location.
 */
class Uniform
{
public:
    /**
       * Default constructor.
       * Creates a new Uniform object.
       */
    Uniform (void) : location (-1), program (0)
    {
    }

    /**
       * Copy constuctor.
       * Copies the internal uniform location to another Uniform object.
       * \param u Uniform object to copy.
       */
    Uniform (const Uniform &u) : location (u.location),
                                 program (u.program)
    {
    }

    /**
   * Move constuctor.
   * Moves the internal uniform location to another Uniform object.
   * \param u Uniform object to move.
   */
    Uniform (Uniform &&u) noexcept : location (u.location), program (u.program)
    {
        u.location = -1;
        u.program = 0;
    }

    /**
       * A destructor.
       * Deletes a Uniform object.
       */
    ~Uniform (void)
    {
    }

    /**
       * Copy assignment.
       * Copies the internal uniform location to another Uniform object.
       * \param u Uniform object to copy.
       * \return A reference to the Uniform object.
       */
    Uniform &operator= (const Uniform &u)
    {
        location = u.location;
        program = u.program;
        return *this;
    }

    /**
   * Move assignment.
   * Moves the internal uniform location to another Uniform object.
   * \param u Uniform object to move.
   * \return A reference to the Uniform object.
   */
    Uniform &operator= (Uniform &&u)
    {
        location = u.location; u.location = -1;
        program = u.program; u.program = 0;
        return *this;
    }

    /**
       * Assign a value.
       * Assigns a float value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    GLfloat operator= (GLfloat v)
    {
        if (location != -1) {
            ProgramUniform1f (program, location, v);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign an array of values.
       * Assigns an array of float values to the uniform location.
       * \param v array of values to assign
       * \return a reference to the assigned array of values
       */
    template<size_t N>
    inline const std::array <GLfloat, N>
    &operator= (const std::array <GLfloat, N> &v)
    {
        Set (v.data (), N);
        return v;
    }

    /**
       * Assign an array of values.
       * Assigns an array of float values to the uniform location.
       * \param v array of values to assign
       * \param N number of values in the array
       */
    void Set (const GLfloat *v, size_t N)
    {
        if (location != -1) {
            ProgramUniform1fv (program, location, N, v);
            CheckError ();
        }
    }

    /**
       * Assign a value.
       * Assigns a glm::vec2 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::vec2 &operator= (const glm::vec2 &v)
    {
        if (location != -1) {
            ProgramUniform2fv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::vec3 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::vec3 &operator= (const glm::vec3 &v)
    {
        if (location != -1) {
            ProgramUniform3fv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::vec4 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::vec4 &operator= (const glm::vec4 &v)
    {
        if (location != -1) {
            ProgramUniform4fv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns an int value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    GLint operator= (GLint v)
    {
        if (location != -1) {
            ProgramUniform1i (program, location, v);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::ivec2 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::ivec2 &operator= (const glm::ivec2 &v)
    {
        if (location != -1) {
            ProgramUniform2iv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::ivec3 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::ivec3 &operator= (const glm::ivec3 &v)
    {
        if (location != -1) {
            ProgramUniform3iv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::ivec4 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::ivec4 &operator= (const glm::ivec4 &v)
    {
        if (location != -1) {
            ProgramUniform4iv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns an unsigned int value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    GLuint64 operator= (GLuint64 v)
    {
        if (location != -1) {
            ProgramUniformHandleui64ARB (program, location, v);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns an unsigned int value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    GLuint operator= (GLuint v)
    {
        if (location != -1) {
            ProgramUniform1ui (program, location, v);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::uvec2 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::uvec2 &operator= (const glm::uvec2 &v)
    {
        if (location != -1) {
            ProgramUniform2uiv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::uvec3 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::uvec3 &operator= (const glm::uvec3 &v)
    {
        if (location != -1) {
            ProgramUniform3uiv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::uvec4 value to the uniform location.
       * \param v value to assign
       * \return a reference to the assigned value
       */
    const glm::uvec4 &operator= (const glm::uvec4 &v)
    {
        if (location != -1) {
            ProgramUniform4uiv (program, location, 1, &v[0]);
            CheckError ();
        }
        return v;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat2 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat2 &operator= (const glm::mat2 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix2fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat3 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat3 &operator= (const glm::mat3 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix3fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat4 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat4 &operator= (const glm::mat4 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix4fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat2x3 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat2x3 &operator= (const glm::mat2x3 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix2x3fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat3x2 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat3x2 &operator= (const glm::mat3x2 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix3x2fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat2x4 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat2x4 &operator= (const glm::mat2x4 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix2x4fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat4x2 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat4x2 &operator= (const glm::mat4x2 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix4x2fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat3x4 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat3x4 &operator= (const glm::mat3x4 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix3x4fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Assign a value.
       * Assigns a glm::mat4x3 value to the uniform location.
       * \param m value to assign
       * \return a reference to the assigned value
       */
    const glm::mat4x3 &operator= (const glm::mat4x3 &m)
    {
        if (location != -1) {
            ProgramUniformMatrix4x3fv (program, location, 1, GL_FALSE, &m[0][0]);
            CheckError ();
        }
        return m;
    }

    /**
       * Checks whether the uniform is valid.
       * \return Whether the uniform is valid.
       */
    operator bool (void)
    {
        return location != -1;
    }

    /**
       * Get a value.
       * Returns the value of the uniform variable.
       * \param params Returns the value of the uniform variable.
       */
    void Get (GLfloat *params)
    {
        GetUniformfv (program, location, params);
        CheckError ();
    }

    /**
       * Get a value.
       * Returns the value of the uniform variable.
       * \param params Returns the value of the uniform variable.
       */
    void Get (GLint *params)
    {
        GetUniformiv (program, location, params);
        CheckError ();
    }

private:
    /**
       * Private constructor.
       * Creates a Uniform object using the specified internal parameters.
       * \param prog the internal OpenGL shader program to use
       * \param loc the internal OpenGL uniform location to use
       */
    Uniform (GLuint prog, GLint loc)
            : program (prog), location (loc)
    {
    }

    /**
       * The internal OpenGL program name containing the Uniform.
       */
    GLuint program;
    /**
       * The internal OpenGL uniform location of the uniform variable.
       */
    GLint location;

    friend class Program;
};

} /* namespace oglp */

#endif /* !defined OGLP_UNIFORM_H */
