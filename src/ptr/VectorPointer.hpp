/*
	MIT License

	Copyright (c) 2020 x4kkk3r

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef _IO_MATH_VECTOR_POINTER_HPP
#define _IO_MATH_VECTOR_POINTER_HPP

#include "../types/vectors/TVector2.hpp"
#include "../types/vectors/TVector3.hpp"
#include "../types/vectors/TVector4.hpp"

#include <memory.h>

namespace IOMath
{
    namespace Pointers
    {
        template <typename T>
        constexpr T* Value(Types::TVector<2, T> &object)
        {
            return &(object.x);
        }
        template <typename T>
        constexpr T* Value(Types::TVector<3, T> &object)
        {
            return &(object.x);
        }
        template <typename T>
        constexpr T* Value(Types::TVector<4, T> &object)
        {
            return &(object.x);
        }

        template <typename T>
        constexpr T const* ValueConst(Types::TVector<2, T> const &object)
        {
            return &(object.x);
        }
        template <typename T>
        constexpr T const* ValueConst(Types::TVector<3, T> const &object)
        {
            return &(object.x);
        }
        template <typename T>
        constexpr T const* ValueConst(Types::TVector<4, T> const &object)
        {
            return &(object.x);
        }

        template <typename V, typename T>
        constexpr V Make(T const* ptr)
        {
            V result;
            memcpy(Value(result), ptr, sizeof(V));
            return result;
        }
    }
}

#endif