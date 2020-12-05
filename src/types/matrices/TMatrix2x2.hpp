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
			using row_t = TVector<2, T>;
			using column_t = TVector<2, T>;
			using data_t = TVector<2, T>;
		private:
			data_t data[data_t::Size()];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					data_t(scalar, 0),
					data_t(0, scalar)
				} {}
			constexpr TMatrix(T a, T b, T c, T d) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(a, c),
						data_t(b, d)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(a, b),
						data_t(c, d)
					#endif
				} {}

			constexpr TMatrix(data_t const &first, data_t const &second) noexcept :
				data
				{
					data_t(first),
					data_t(second)
				} {}

			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(A a, B b, C c, D d) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(a, c),
						data_t(b, d)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(a, b),
						data_t(c, d)
					#endif
				} {}
			template <typename A, typename B>
			constexpr TMatrix(TVector<2, A> const &first, TVector<2, B> const &second) noexcept :
				data
				{
					data_t(first),
					data_t(second)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					data_t(other[0]),
					data_t(other[1])
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0][0], other[0][1]),
						data_t(other[1][0], other[1][1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0]),
						data_t(other[1])
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0][0], other[0][1]),
						data_t(other[1][0], other[1][1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0]),
						data_t(other[1])
					#endif
				} {}

			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix2x3(TMatrix<2, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						matrix[0],
						matrix[1]
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector3(matrix[0]),
						data_t::FromVector3(matrix[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix2x4(TMatrix<2, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						matrix[0],
						matrix[1]
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector4(matrix[0]),
						data_t::FromVector4(matrix[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix3x3(TMatrix<3, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					data_t::FromVector3(matrix[0]),
					data_t::FromVector3(matrix[1])
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix3x4(TMatrix<3, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector3(matrix[0]),
						data_t::FromVector3(matrix[1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector4(matrix[0]),
						data_t::FromVector4(matrix[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix4x3(TMatrix<4, 3, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector4(matrix[0]),
						data_t::FromVector4(matrix[1])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector3(matrix[0]),
						data_t::FromVector3(matrix[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 2, T> FromMatrix4x4(TMatrix<4, 4, U> const &matrix) noexcept
			{
				return TMatrix<2, 2, T>
				(
					data_t::FromVector4(matrix[0]),
					data_t::FromVector4(matrix[1])
				);
			}

			static constexpr TMatrix<2, 2, T> Identity() noexcept
			{
				T const zero = static_cast<T>(0);
				T const one = static_cast<T>(1);

				return TMatrix<2, 2, T>
				(
					one, zero,
					zero, one
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

			constexpr data_t & operator[](size_t index) noexcept
			{
				#ifdef IO_MATH_SAFE_BRACKETS_OPERATOR
					assert(index >= 0 && index < TMatrix::Rows());
				#endif

				return data[index];
			}
			constexpr data_t const & operator[](size_t index) const noexcept
			{
				#ifdef IO_MATH_SAFE_BRACKETS_OPERATOR
					assert(index >= 0 && index < TMatrix::Rows());
				#endif

				return data[index];
			}
		
			constexpr TMatrix<2, 2, T> & operator=(TMatrix<2, 2, T> const &other) noexcept
			{
				memcpy(this->data, other.data, sizeof(T) * 4);

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator+=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator-=(TMatrix<2, 2, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator*=(TMatrix<2, 2, U> const &other) noexcept
			{
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					T const lObjectA = this->data[0][0];
					T const lObjectB = this->data[1][0];
					T const lObjectC = this->data[0][1];
					T const lObjectD = this->data[1][1];

					T const rObjectA = other[0][0];
					T const rObjectB = other[1][0];
					T const rObjectC = other[0][1];
					T const rObjectD = other[1][1];
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					T const lObjectA = this->data[0][0];
					T const lObjectB = this->data[0][1];
					T const lObjectC = this->data[1][0];
					T const lObjectD = this->data[1][1];

					T const rObjectA = other[0][0];
					T const rObjectB = other[0][1];
					T const rObjectC = other[1][0];
					T const rObjectD = other[1][1];
				#endif

				return (*this = TMatrix<2, 2, T>
				(
					lObjectA * rObjectA + lObjectB * rObjectC,
					lObjectA * rObjectB + lObjectB * rObjectD,
					lObjectC * rObjectA + lObjectD * rObjectC,
					lObjectC * rObjectB + lObjectD * rObjectD
				));
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 2, T> & operator/=(TMatrix<2, 2, U> const &other) noexcept
			{
				return (*this *= detail::ComputeInverse(other));
			}

			constexpr TMatrix<2, 2, T> & operator++() noexcept
			{
				++this->data[0];
				++this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 2, T> & operator--() noexcept
			{
				--this->data[0];
				--this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 2, T> & operator++(int) noexcept
			{
				TMatrix<2, 2, T> result = TMatrix<2, 2, T>(*this);

				++(*this);

				return result;
			}
			constexpr TMatrix<2, 2, T> & operator--(int) noexcept
			{
				TMatrix<2, 2, T> result = TMatrix<2, 2, T>(*this);

				--(*this);

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
			return TMatrix<2, 2, T>
			(
				scalar + object[0],
				scalar + object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>
			(
				object[0] + scalar,
				object[1] + scalar
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator+(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>
			(
				lObject[0] + rObject[0],
				lObject[1] + rObject[1]
			);
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
			return TMatrix<2, 2, T>
			(
				object[0] - scalar,
				object[1] - scalar
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator-(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>
			(
				lObject[0] - rObject[0],
				lObject[1] - rObject[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(T scalar, TMatrix<2, 2, T> const &object) noexcept
		{
			return TMatrix<2, 2, T>
			(
				scalar * object[0],
				scalar * object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 2, T>
			(
				object[0] * scalar,
				object[1] * scalar
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[0][1];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[0][1];
				T const rObjectD = rObject[1][1];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[1][0];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[1][0];
				T const rObjectD = rObject[1][1];
			#endif

			return TMatrix<2, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC,
				lObjectA * rObjectB + lObjectB * rObjectD,
				lObjectC * rObjectA + lObjectD * rObjectC,
				lObjectC * rObjectB + lObjectD * rObjectD
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[0][1];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[0][1];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[2][1];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[1][0];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[1][0];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[1][2];
			#endif

			return TMatrix<2, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD,
				lObjectA * rObjectB + lObjectB * rObjectE,
				lObjectA * rObjectC + lObjectB * rObjectF,
				lObjectC * rObjectA + lObjectD * rObjectD,
				lObjectC * rObjectB + lObjectD * rObjectE,
				lObjectC * rObjectC + lObjectD * rObjectF
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 2, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[0][1];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[3][0];
				T const rObjectE = rObject[0][1];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[2][1];
				T const rObjectH = rObject[3][1];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[1][0];
				T const lObjectD = lObject[1][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[0][3];
				T const rObjectE = rObject[1][0];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[1][2];
				T const rObjectH = rObject[1][3];
			#endif

			return TMatrix<2, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE,
				lObjectA * rObjectB + lObjectB * rObjectF,
				lObjectA * rObjectC + lObjectB * rObjectG,
				lObjectA * rObjectD + lObjectB * rObjectH,
				lObjectC * rObjectA + lObjectD * rObjectE,
				lObjectC * rObjectB + lObjectD * rObjectF,
				lObjectC * rObjectC + lObjectD * rObjectG,
				lObjectC * rObjectD + lObjectD * rObjectH
			);
		}
		template <typename T>
		constexpr typename TMatrix<2, 2, T>::column_t operator*(TMatrix<2, 2, T> const &matrix, typename TMatrix<2, 2, T>::data_t const &vector) noexcept
		{
			return typename TMatrix<2, 2, T>::column_t
			(
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					matrix[0][0] * vector.x + matrix[1][0] * vector.y,
					matrix[0][1] * vector.x + matrix[1][1] * vector.y
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					matrix[0][0] * vector.x + matrix[0][1] * vector.y,
					matrix[1][0] * vector.x + matrix[1][1] * vector.y
				#endif
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
			return TMatrix<2, 2, T>
			(
				object[0] / scalar,
				object[1] / scalar
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator/(TMatrix<2, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>
			(
				lObject[0] * rObject[0],
				lObject[1] * rObject[1]
			);
		}
		template <typename T>
		constexpr typename TMatrix<2, 2, T>::column_t operator/(TMatrix<2, 2, T> const &matrix, typename TMatrix<2, 2, T>::data_t const &vector) noexcept
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
			return
			(
				lObject[0] != rObject[0] ||
				lObject[1] != rObject[1]
			);
		}
	}
}

#endif