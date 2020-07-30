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

#ifndef _IO_MATH_COMPUTE_MATRIX_TRANSFORM_HPP
#define _IO_MATH_COMPUTE_MATRIX_TRANSFORM_HPP

#include "../types/matrices/TMatrix4x4.hpp"
#include "../types/vectors/TVector3.hpp"

namespace IOMath
{
    namespace detail
    {
        template <typename T>
        constexpr Types::TMatrix<4, 4, T> ComputeMatrixTranslate(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &translation) noexcept
        {
            Types::TMatrix<4, 4, T> result = Types::TMatrix<4, 4, T>(object);

            result[3][0] += translation.x;
            result[3][1] += translation.y;
            result[3][2] += translation.z;

            return result;
        }
    }
}

#endif