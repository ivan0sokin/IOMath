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

#ifndef _IO_MATH_FMATRIX_HPP
#define _IO_MATH_FMATRIX_HPP

#include "../../types/matrices/TMatrix2x2.hpp"
#include "../../types/matrices/TMatrix2x3.hpp"
#include "../../types/matrices/TMatrix2x4.hpp"
#include "../../types/matrices/TMatrix3x2.hpp"
#include "../../types/matrices/TMatrix3x3.hpp"
#include "../../types/matrices/TMatrix3x4.hpp"
#include "../../types/matrices/TMatrix4x2.hpp"
#include "../../types/matrices/TMatrix4x3.hpp"
#include "../../types/matrices/TMatrix4x4.hpp"

namespace IOMath
{
	typedef Types::TMatrix<2, 2, float> Matrix2;

	typedef Types::TMatrix<2, 2, float> Matrix2x2;
	typedef Types::TMatrix<2, 3, float> Matrix2x3;
	typedef Types::TMatrix<2, 4, float> Matrix2x4;

	typedef Types::TMatrix<3, 3, float> Matrix3;

	typedef Types::TMatrix<3, 2, float> Matrix3x2;
	typedef Types::TMatrix<3, 3, float> Matrix3x3;
	typedef Types::TMatrix<3, 4, float> Matrix3x4;

	typedef Types::TMatrix<4, 3, float> Matrix4;

	typedef Types::TMatrix<4, 2, float> Matrix4x2;
	typedef Types::TMatrix<4, 3, float> Matrix4x3;
	typedef Types::TMatrix<4, 4, float> Matrix4x4;
}

#endif