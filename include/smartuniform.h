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
#ifndef OGLP_SMART_UNIFORM_H
#define OGLP_SMART_UNIFORM_H

#include "common.h"
#include <vector>

namespace gl {

/**
 * Smart OpenGL uniform abstraction.
 * A wrapper class around an OpenGL uniform location.
 * This class is aware of the current value of the uniform
 * and only sends data to the GL, if a newly assigned value
 * is different from the stored value.
 */
template<typename T>
class SmartUniform
{
public:
	 /**
		* Default constructor.
		* Creates a new SmartUniform object.
		*/
	 SmartUniform (void);
	 /**
		* Constructor.
		* Creates a SmartUniform from a Uniform object and its value.
		* This implicitely assigns the given value to the uniform.
		*/
	 SmartUniform (const Uniform &u, const T &v);
	 /**
		* Copy constuctor.
		* Copies the smart uniform wrapper to another SmartUniform object.
		* \param obj SmartUniform object to copy.
		*/
	 SmartUniform (const SmartUniform<T> &obj);
	 /**
		* A destructor.
		* Deletes a SmartUniform object.
		*/
	 ~SmartUniform (void);
	 /**
		* Copy assignment.
		* Copies the smart uniform wrapper to another SmartUniform object.
		* \param obj SmartUniform object to copy.
		* \return A reference to the SmartUniform object.
		*/
	 SmartUniform<T> &operator= (const SmartUniform<T> &obj);
	 /**
		* Assign a value.
		* Assigns a value to the internal uniform.
		* \param v value to assign
		* \return a reference to the assigned value
		*/
	 const T &operator= (const T &v);
	 /**
		* Checks whether the uniform is valid.
		* \return Whether the uniform is valid.
		*/
	 operator bool (void);
	 /**
		* Get a value.
		* Returns the value of the uniform variable.
		* The result is undefined prior to the first assignment
		* of a value to the uniform by the means of this SmartUniform
		* class.
		* \param param Returns the value of the uniform variable.
		*/
	 void Get (T *param);
private:
	 /**
		* The internal Uniform object.
		*/
	 Uniform uniform;
	 /**
		* The stored value of the uniform;
		*/
	 T value;
};

template<typename T>
inline SmartUniform<T>::SmartUniform (void)
{
}

template<typename T>
inline SmartUniform<T>::SmartUniform (const Uniform &u, const T &v)
	: uniform (u), value (v)
{
	uniform = value;
}

template<typename T>
inline SmartUniform<T>::SmartUniform (const SmartUniform<T> &obj)
{
	uniform = obj.uniform;
	value = obj.value;
}

template<typename T>
inline SmartUniform<T> &SmartUniform<T>::operator= (const SmartUniform<T> &obj)
{
	uniform = obj.uniform;
	value = obj.value;
}

template<typename T>
inline SmartUniform<T>::~SmartUniform (void)
{
}

template<typename T>
inline void SmartUniform<T>::Get (T *param)
{
	*param = value;
}

template<typename T>
inline SmartUniform<T>::operator bool (void)
{
	return uniform;
}

template<>
inline const GLfloat &SmartUniform<GLfloat>::operator= (const GLfloat &v)
{
	if (v != value)
	{
		value = v;
		uniform = v;
	}
}

template<>
inline const GLint &SmartUniform<GLint>::operator= (const GLint &v)
{
	if (v != value)
	{
		value = v;
		uniform = v;
	}
}

template<>
inline const GLuint &SmartUniform<GLuint>::operator= (const GLuint &v)
{
	if (v != value)
	{
		value = v;
		uniform = v;
	}
}

template<typename T>
inline const T &SmartUniform<T>::operator= (const T &v)
{
	if (!glm::equal (v, value))
	{
		value = v;
		uniform = v;
	}
}


} /* namespace gl */

#endif /* !defined OGLP_SMART_UNIFORM_H */
