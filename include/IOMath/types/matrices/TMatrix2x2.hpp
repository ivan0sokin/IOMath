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

#ifndef _IO_MATH_TMATRIX_2X2_HPP
#define _IO_MATH_TMATRIX_2X2_HPP

#include "../BasicTypes.hpp"

#include <cassert>
#include <memory.h>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<2, 2, T>
		{
			typedef TVector<2, T> row_type;
		private:
			row_type data[2];
		public:
			constexpr TMatrix() noexcept
			{
				this->data[0] = row_type();
				this->data[1] = row_type();
			}
			constexpr TMatrix(T value) noexcept
			{
				this->data[0] = row_type(value, static_cast<T>(0));
				this->data[1] = row_type(static_cast<T>(0), value);
			}
			constexpr TMatrix(T a1, T a2, T b1, T b2) noexcept
			{
				this->data[0] = row_type(a1, a2);
				this->data[1] = row_type(b1, b2);
			}
			constexpr TMatrix(row_type const &firstRow, row_type const &secondRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
			}
			constexpr TMatrix(TMatrix const &other) noexcept
			{
				*this = other;
			}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] = row_type(other[0]);
				this->data[1] = row_type(other[1]);
			}
		
			static constexpr size_t Rows() noexcept
			{
				return static_cast<size_t>(2);
			}
			static constexpr size_t Columns() noexcept
			{
				return static_cast<size_t>(2);
			}

			constexpr row_type& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
			constexpr row_type const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
		
			constexpr TMatrix& operator=(TMatrix const &other) noexcept
			{
				memcpy(&this->data, &other.data, TMatrix::Rows() * TMatrix::Columns() * sizeof(T));
				
				return *this;
			}
			template <typename U>
			constexpr TMatrix& operator=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] = row_type(other[0]);
				this->data[1] = row_type(other[1]);

				return *this;
			}
		};
	}
}

#endif