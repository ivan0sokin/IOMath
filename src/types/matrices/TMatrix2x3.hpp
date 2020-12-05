#ifndef _IO_MATH_TMATRIX_2X3_HPP
#define _IO_MATH_TMATRIX_2X3_HPP

#include "../vectors/TVector2.hpp"
#include "../vectors/TVector3.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<2, 3, T>
		{
			using row_t = TVector<3, T>;
			using column_t = TVector<2, T>;
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				using data_t = column_t;
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				using data_t = row_t;
			#endif
		private:
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				data_t data[row_t::Size()];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				data_t data[column_t::Size()];
			#endif
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(scalar, 0),
						data_t(0, scalar),
						data_t(0, 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(scalar, 0, 0),
						data_t(0, scalar, 0)
					#endif
				} {}
			constexpr TMatrix(T a, T b, T c, T d, T e, T f) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(a, d),
						data_t(b, e),
						data_t(c, f)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(a, b, c),
						data_t(d, e, f)
					#endif
				} {}
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				constexpr TMatrix(data_t const &first, data_t const &second, data_t const &third) noexcept :
				data
				{
					data_t(first),
					data_t(second),
					data_t(third)
				} {}
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				constexpr TMatrix(data_t const &first, data_t const &second) noexcept :
				data
				{
					data_t(first),
					data_t(second)
				} {}
			#endif

			template <typename A, typename B, typename C, typename D, typename E, typename F>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(a, d),
						data_t(b, e),
						data_t(c, f)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(a, b, c),
						data_t(d, e, f)
					#endif
				} {}
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				template <typename A, typename B, typename C>
				constexpr TMatrix(TVector<2, A> const &first, TVector<2, A> const &second, TVector<2, A> const &third) noexcept :
					data
					{
						data_t(first),
						data_t(second),
						data_t(third)
					} {}
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				template <typename A, typename B>
				constexpr TMatrix(TVector<3, A> const &first, TVector<3, B> const &second) noexcept :
					data
					{
						data_t(first),
						data_t(second)
					} {}
			#endif
			
			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t(other[0]),
						data_t(other[1]),
						data_t(0, 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0),
						data_t(other[1], 0)
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept :
				data
				{
					data_t(other[0]),
					data_t(other[1]),
					data_t(other[2])
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector3(other[0]),
						data_t::FromVector3(other[1]),
						data_t(0, 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0),
						data_t(other[1], 0)
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 3, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector3(other[0]),
						data_t::FromVector3(other[1]),
						data_t::FromVector3(other[2])
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
						data_t::FromVector4(other[0]),
						data_t::FromVector4(other[1]),
						data_t(0, 0)
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0], 0),
						data_t(other[1], 0)
					#endif
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 3, U> const &other) noexcept :
				data
				{
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector4(other[0]),
						data_t::FromVector4(other[1]),
						data_t::FromVector4(other[2])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t(other[0]),
						data_t(other[1])
					#endif
				} {}

			template <typename U>
			static constexpr TMatrix<2, 3, T> FromMatrix2x4(TMatrix<2, 4, U> const &other) noexcept
			{
				return TMatrix<2, 3, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						other[0],
						other[1],
						other[2]
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector4(other[0]),
						data_t::FromVector4(other[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 3, T> FromMatrix3x4(TMatrix<3, 4, U> const &other) noexcept
			{
				return TMatrix<2, 3, T>
				(
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector3(other[0]),
						data_t::FromVector3(other[1]),
						data_t::FromVector3(other[2])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector4(other[0]),
						data_t::FromVector4(other[1])
					#endif
				);
			}
			template <typename U>
			static constexpr TMatrix<2, 3, T> FromMatrix4x4(TMatrix<4, 4, U> const &other) noexcept
			{
				return TMatrix<2, 3, T>
				(
					data_t::FromVector4(other[0]),
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						data_t::FromVector4(other[1]),
						data_t::FromVector4(other[2])
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						data_t::FromVector4(other[1])
					#endif
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
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						assert(index >= 0 && index < TMatrix::Columns())
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						assert(index >= 0 && index < TMatrix::Rows());
					#endif
				#endif
				
				return data[index];
			}
			constexpr data_t const & operator[](size_t index) const noexcept
			{
				#ifdef IO_MATH_SAFE_BRACKETS_OPERATOR
					#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
						assert(index >= 0 && index < TMatrix::Columns())
					#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
						assert(index >= 0 && index < TMatrix::Rows());
					#endif
				#endif

				return data[index];
			}
	
			constexpr TMatrix<2, 3, T> & operator=(TMatrix<2, 3, T> const &other) noexcept
			{
				memcpy(this->data, other.data, sizeof(T) * 6);

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] = other[2];
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] += scalar;
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator+=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] += other[2];
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] -= scalar;
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator-=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] -= other[2];
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] *= scalar;
				#endif

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T> & operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					this->data[2] /= scalar;
				#endif

				return *this;
			}

			constexpr TMatrix<2, 3, T> & operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					++this->data[2];
				#endif

				return *this;
			}
			constexpr TMatrix<2, 3, T> & operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					--this->data[2];
				#endif

				return *this;
			}
			constexpr TMatrix<2, 3, T> & operator++(int) noexcept
			{
				TMatrix<2, 3, T> result = TMatrix<2, 3, T>(*this);

				++(*this);

				return result;
			}
			constexpr TMatrix<2, 3, T> & operator--(int) noexcept
			{
				TMatrix<2, 3, T> result = TMatrix<2, 3, T>(*this);

				--(*this);

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(TMatrix<2, 3, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				-object[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					-object[1],
					-object[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					-object[1]
				#endif
			);
		}

		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				scalar + object[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					scalar + object[1],
					scalar + object[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					scalar + object[1]
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>
			(
				object[0] + scalar,
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					object[1] + scalar,
					object[2] + scalar
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					object[1] + scalar
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>
			(
				lObject[0] + rObject[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					lObject[1] + rObject[1],
					lObject[2] + rObject[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					lObject[1] + rObject[1]
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				scalar - object[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					scalar - object[1],
					scalar - object[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					scalar - object[1]
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>
			(
				object[0] - scalar,
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					object[1] - scalar,
					object[2] - scalar
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					object[1] - scalar
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>
			(
				lObject[0] - rObject[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					lObject[1] - rObject[1],
					lObject[2] - rObject[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					lObject[1] - rObject[1]
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				scalar * object[0],
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					scalar * object[1],
					scalar * object[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					scalar * object[1]
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>
			(
				object[0] * scalar,
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					object[1] * scalar,
					object[2] * scalar
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					object[1] * scalar
				#endif
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[0][1];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[2][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[0][1];
				T const rObjectD = rObject[1][1];
				T const rObjectE = rObject[0][2];
				T const rObjectF = rObject[1][2];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[1][0];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[1][2];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[1][0];
				T const rObjectD = rObject[1][1];
				T const rObjectE = rObject[2][0];
				T const rObjectF = rObject[2][1];
			#endif

			return TMatrix<2, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF,
				lObjectD * rObjectA + lObjectE * rObjectC + lObjectF * rObjectE,
				lObjectD * rObjectB + lObjectE * rObjectD + lObjectF * rObjectF
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[0][1];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[2][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[0][1];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[2][1];
				T const rObjectG = rObject[0][2];
				T const rObjectH = rObject[1][2];
				T const rObjectI = rObject[2][2];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[1][0];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[1][2];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[1][0];
				T const rObjectE = rObject[1][1];
				T const rObjectF = rObject[1][2];
				T const rObjectG = rObject[2][0];
				T const rObjectH = rObject[2][1];
				T const rObjectI = rObject[2][2];
			#endif

			return TMatrix<2, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI,
				lObjectD * rObjectA + lObjectE * rObjectD + lObjectF * rObjectG,
				lObjectD * rObjectB + lObjectE * rObjectE + lObjectF * rObjectH,
				lObjectD * rObjectC + lObjectE * rObjectF + lObjectF * rObjectI
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[1][0];
				T const lObjectC = lObject[2][0];
				T const lObjectD = lObject[0][1];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[2][1];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[1][0];
				T const rObjectC = rObject[2][0];
				T const rObjectD = rObject[3][0];
				T const rObjectE = rObject[0][1];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[2][1];
				T const rObjectH = rObject[3][1];
				T const rObjectI = rObject[0][2];
				T const rObjectJ = rObject[1][2];
				T const rObjectK = rObject[2][2];
				T const rObjectL = rObject[3][2];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				T const lObjectA = lObject[0][0];
				T const lObjectB = lObject[0][1];
				T const lObjectC = lObject[0][2];
				T const lObjectD = lObject[1][0];
				T const lObjectE = lObject[1][1];
				T const lObjectF = lObject[1][2];

				T const rObjectA = rObject[0][0];
				T const rObjectB = rObject[0][1];
				T const rObjectC = rObject[0][2];
				T const rObjectD = rObject[0][3];
				T const rObjectE = rObject[1][0];
				T const rObjectF = rObject[1][1];
				T const rObjectG = rObject[1][2];
				T const rObjectH = rObject[1][3];
				T const rObjectI = rObject[2][0];
				T const rObjectJ = rObject[2][1];
				T const rObjectK = rObject[2][2];
				T const rObjectL = rObject[2][3];
			#endif

			return TMatrix<2, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI,
				lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ,
				lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK,
				lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL,
				lObjectD * rObjectA + lObjectE * rObjectE + lObjectF * rObjectI,
				lObjectD * rObjectB + lObjectE * rObjectF + lObjectF * rObjectJ,
				lObjectD * rObjectC + lObjectE * rObjectG + lObjectF * rObjectK,
				lObjectD * rObjectD + lObjectE * rObjectH + lObjectF * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator/(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				scalar / object[0],
				scalar / object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator/(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>
			(
				object[0] / scalar,
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					object[1] / scalar,
					object[2] / scalar
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					object[1] / scalar
				#endif
			);
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					lObject[1] == rObject[1] &&
					lObject[2] == rObject[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					lObject[1] == rObject[1]
				#endif
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] != rObject[0] ||
				#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
					lObject[1] != rObject[1] ||
					lObject[2] != rObject[2]
				#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
					lObject[1] != rObject[1]
				#endif
			);
		}
	}
}

#endif