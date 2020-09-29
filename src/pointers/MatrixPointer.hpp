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

#ifndef _IO_MATH_MATRIX_POINTER_HPP
#define _IO_MATH_MATRIX_POINTER_HPP

#include "../types/matrices/TMatrix2x2.hpp"
#include "../types/matrices/TMatrix2x3.hpp"
#include "../types/matrices/TMatrix2x4.hpp"
#include "../types/matrices/TMatrix3x2.hpp"
#include "../types/matrices/TMatrix3x3.hpp"
#include "../types/matrices/TMatrix3x4.hpp"
#include "../types/matrices/TMatrix4x2.hpp"
#include "../types/matrices/TMatrix4x3.hpp"
#include "../types/matrices/TMatrix4x4.hpp"

#include <memory.h>

namespace IOMath
{
	template <typename T, size_t R, size_t C>
	constexpr T * ValuePtr(Types::TMatrix<R, C, T> &object) noexcept
	{
		return &(object[0][0]);
	}

	template <typename T, size_t R, size_t C>
	constexpr T const * ValuePtr(Types::TMatrix<R, C, T> const &object) noexcept
	{
		return &(object[0][0]);
	}

	template <size_t R, size_t C, typename T>
	constexpr Types::TMatrix<R, C, T> MakeFromPtr(T const *ptr) noexcept
	{
		Types::TMatrix<R, C, T> result;
		memcpy(ValuePtr(result), ptr, sizeof(Types::TMatrix<R, C, T>));

		return result;
	}
}

#endif