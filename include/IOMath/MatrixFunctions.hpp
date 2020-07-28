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

#ifndef _IO_MATH_MATRIX_FUNCTIONS_HPP
#define _IO_MATH_MATRIX_FUNCTIONS_HPP

#include "detail/ComputeMatrixFunctions.hpp"

namespace IOMath
{
    template <size_t R, size_t C, typename T>
    constexpr Types::TMatrix<C, R, T> Transpose(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeTranspose(object);
    }

    template <size_t R, size_t C, typename T>
    constexpr T Determinant(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeDeterminant(object);
    }

    template <size_t R, size_t C, typename T>
    constexpr Types::TMatrix<R, C, T> Inverse(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeInverse(object);
    }
}

#endif