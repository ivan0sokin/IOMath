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

#include "../vectors/TVector2.hpp"
#include "../../detail/ComputeBasicMatrixFunctions.hpp"

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<2, 2, T>
		{
			typedef TVector<2, T> row_t;
			typedef TVector<2, T> column_t;
		private:
			row_t data[2];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					row_t(scalar, 0),
					row_t(0, scalar)
				} {}
			constexpr TMatrix(T a1, T a2, T b1, T b2) noexcept :
				data
				{
					row_t(a1, a2),
					row_t(b1, b2)
				} {}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow)
				} {}

			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(A a, B b, C c, D d) noexcept :
				data
				{
					row_t(a, b),
					row_t(c, d)
				} {}
			template <typename A, typename B>
			constexpr TMatrix(TVector<2, A> const &firstRow, TVector<2, B> const &secondRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1])
				} {}
			
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix2x3(TMatrix<2, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector3(matrix[0]),
					row_t::FromVector3(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix2x4(TMatrix<2, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector4(matrix[0]),
					row_t::FromVector4(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix3x2(TMatrix<3, 2, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t(matrix[0]),
					row_t(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix3x3(TMatrix<3, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector3(matrix[0]),
					row_t::FromVector3(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix3x4(TMatrix<3, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector4(matrix[0]),
					row_t::FromVector4(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix4x2(TMatrix<4, 2, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t(matrix[0]),
					row_t(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix4x3(TMatrix<4, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector3(matrix[0]),
					row_t::FromVector3(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix4x4(TMatrix<4, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					row_t::FromVector4(matrix[0]),
					row_t::FromVector4(matrix[1])
				);
			}

			static constexpr TMatrix<2, 2, T> Identity() noexcept
			{
				return TMatrix<2, 2, T>
				(
					1, 0,
					0, 1
				);
			}

			static constexpr size_t Rows() noexcept
			{
				return column_t::Size();
			}
			static constexpr size_t Columns() noexcept
			{
				return row_t::Size();
			}

			constexpr row_t& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
			constexpr row_t const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TMatrix::Rows());
				return data[index];
			}
		
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator+=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator-=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator*=(TMatrix<2, 2, U> const &other) noexcept
			{
				return (*this = *this * other);
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T>& operator/=(TMatrix<2, 2, U> const &other) noexcept
			{
				return (*this *= detail::ComputeInverse(other));
			}

			constexpr TMatrix<2, 2, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 2, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 2, T>& operator++(int) noexcept
			{
				TMatrix<2, 2, T> result = TMatrix<2, 2, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<2, 2, T>& operator--(int) noexcept
			{
				TMatrix<2, 2, T> result = TMatrix<2, 2, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(TMatrix<2, 2, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator-(TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>
			(
				-object[0],
				-object[1]
			);
		}

		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(T scalar, TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator-(T scalar, TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>
			(
				scalar - object[0],
				scalar - object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator-(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator-(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(T scalar, TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1],
				lObject[0][0] * rObject[0][2] + lObject[0][1] * rObject[1][2],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1],
				lObject[1][0] * rObject[0][2] + lObject[1][1] * rObject[1][2]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			return TMatrix<2, 4, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1],
				lObject[0][0] * rObject[0][2] + lObject[0][1] * rObject[1][2],
				lObject[0][0] * rObject[0][3] + lObject[0][1] * rObject[1][3],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1],
				lObject[1][0] * rObject[0][2] + lObject[1][1] * rObject[1][2],
				lObject[1][0] * rObject[0][3] + lObject[1][1] * rObject[1][3]
			);
		}
		template <typename T>
		constexpr typename TMatrix<2, 2, T>::column_t operator*(TMatrix<2, 2, T> const &matrix, typename TMatrix<2, 2, T>::row_t const &vector) noexcept
		{
			return typename TMatrix<2, 2, T>::column_t
			(
				matrix[0][0] * vector.x + matrix[0][1] * vector.y,
				matrix[1][0] * vector.x + matrix[1][1] * vector.y
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator/(T scalar, TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>
			(
				scalar / object[0],
				scalar / object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator/(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>(object) /= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator/(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>(lObject) /= rObject;
		}
		template <typename T>
		constexpr typename TMatrix<2, 2, T>::column_t operator/(TMatrix<2, 2, T> const &matrix, typename TMatrix<2, 2, T>::row_t const &vector) noexcept
		{
			return detail::ComputeInverse(matrix) * vector;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return 
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif