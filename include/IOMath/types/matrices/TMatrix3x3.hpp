#ifndef _IO_MATH_TMATRIX_3X3_HPP
#define _IO_MATH_TMATRIX_3X3_HPP

#include "../vectors/TVector3.hpp"
#include "../../detail/ComputeBasicMatrixFunctions.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<3, 3, T>
		{
			typedef TVector<3, T> row_t;
			typedef TVector<3, T> column_t;
		private:
			row_t data[3];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					row_t(scalar, 0, 0),
					row_t(0, scalar, 0),
					row_t(0, 0, scalar)
				} {}
			constexpr TMatrix(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3) noexcept :
				data
				{
					row_t(a1, a2, a3),
					row_t(b1, b2, b3),
					row_t(c1, c2, c3)
				} {}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow, row_t const& thirdRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow)
				} {}

			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h, I i) noexcept :
				data
				{
					row_t(a, b, c),
					row_t(d, e, f),
					row_t(g, h, i)
				} {}
			template <typename A, typename B, typename C>
			constexpr TMatrix(TVector<3, A> const &firstRow, TVector<3, B> const &secondRow, TVector<3, C> const &thirdRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<3, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2])
				} {}
			
			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 4, U> const &other) noexcept :
				data
				{
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0)
				} {}
			
			template <typename U>
			static constexpr TMatrix<3, 3, T> FromMatrix3x4(TMatrix<3, 4, U> const &other) noexcept
			{
				return TMatrix<3, 3, T>
				(
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t::FromVector4(other[2])
				);
			}
			template <typename U>
			static constexpr TMatrix<3, 3, T> FromMatrix4x3(TMatrix<4, 3, T> const &other) noexcept
			{
				return TMatrix<3, 3, T>
				(
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2])
				);
			}
			template <typename U>
			static constexpr TMatrix<3, 3, T> FromMatrix4x4(TMatrix<4, 4, T> const &other) noexcept
			{
				return TMatrix<3, 3, T>
				(
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t::FromVector4(other[2])
				);
			}

			static constexpr TMatrix<3, 3, T> Identity() noexcept
			{
				return TMatrix<3, 3, T>
				(
					1, 0, 0,
					0, 1, 0,
					0, 0, 1
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
			constexpr TMatrix<3, 3, T>& operator=(TMatrix<3, 3, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator+=(TMatrix<3, 3, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator-=(TMatrix<3, 3, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator*=(TMatrix<3, 3, U> const &other) noexcept
			{
				return (*this = *this * other);
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 3, T>& operator/=(TMatrix<3, 3, U> const &other) noexcept
			{
				return (*this *= detail::ComputeInverse(other));
			}

			constexpr TMatrix<3, 3, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 3, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 3, T>& operator++(int) noexcept
			{
				TMatrix<3, 3, T> result = TMatrix<3, 3, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<3, 3, T>& operator--(int) noexcept
			{
				TMatrix<3, 3, T> result = TMatrix<3, 3, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<3, 3, T> operator+(TMatrix<3, 3, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator-(TMatrix<3, 3, T> const &object) noexcept
		{
			return TMatrix<3, 3, T>
			(
				-object[0],
				-object[1],
				-object[2]
			);
		}
	
		template <typename T>
		constexpr TMatrix<3, 3, T> operator+(T scalar, TMatrix<3, 3, T> const &object) noexcept
		{
			return TMatrix<3, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator+(TMatrix<3, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator+(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return TMatrix<3, 3, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator-(T scalar, TMatrix<3, 3, T> const &object) noexcept
		{
			return TMatrix<3, 3, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator-(TMatrix<3, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 3, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator-(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return TMatrix<3, 3, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator*(T scalar, TMatrix<3, 3, T> const &object) noexcept
		{
			return TMatrix<3, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator*(TMatrix<3, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator*(TMatrix<3, 3, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[1][0];
			T const lObjectE = lObject[1][1];
			T const lObjectF = lObject[1][2];
			T const lObjectG = lObject[2][0];
			T const lObjectH = lObject[2][1];
			T const lObjectI = lObject[2][2];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];
			T const rObjectE = rObject[2][0];
			T const rObjectF = rObject[2][1];

			return TMatrix<3, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF,
				lObjectD * rObjectA + lObjectE * rObjectC + lObjectF * rObjectE,
				lObjectD * rObjectB + lObjectE * rObjectD + lObjectF * rObjectF,
				lObjectG * rObjectA + lObjectH * rObjectC + lObjectI * rObjectE,
				lObjectG * rObjectB + lObjectH * rObjectD + lObjectI * rObjectF
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator*(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[1][0];
			T const lObjectE = lObject[1][1];
			T const lObjectF = lObject[1][2];
			T const lObjectG = lObject[2][0];
			T const lObjectH = lObject[2][1];
			T const lObjectI = lObject[2][2];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[0][2];
			T const rObjectD = rObject[1][0];
			T const rObjectE = rObject[1][1];
			T const rObjectF = rObject[1][2];
			T const rObjectG = rObject[2][0];
			T const rObjectH = rObject[2][1];
			T const rObjectI = rObject[2][2];

			return TMatrix<3, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI,
				lObjectD * rObjectA + lObjectE * rObjectD + lObjectF * rObjectG,
				lObjectD * rObjectB + lObjectE * rObjectE + lObjectF * rObjectH,
				lObjectD * rObjectC + lObjectE * rObjectF + lObjectF * rObjectI,
				lObjectG * rObjectA + lObjectH * rObjectD + lObjectI * rObjectG,
				lObjectG * rObjectB + lObjectH * rObjectE + lObjectI * rObjectH,
				lObjectG * rObjectC + lObjectH * rObjectF + lObjectI * rObjectI
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator*(TMatrix<3, 3, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[1][0];
			T const lObjectE = lObject[1][1];
			T const lObjectF = lObject[1][2];
			T const lObjectG = lObject[2][0];
			T const lObjectH = lObject[2][1];
			T const lObjectI = lObject[2][2];

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

			return TMatrix<3, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI,
				lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ,
				lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK,
				lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL,
				lObjectD * rObjectA + lObjectE * rObjectE + lObjectF * rObjectI,
				lObjectD * rObjectB + lObjectE * rObjectF + lObjectF * rObjectJ,
				lObjectD * rObjectC + lObjectE * rObjectG + lObjectF * rObjectK,
				lObjectD * rObjectD + lObjectE * rObjectH + lObjectF * rObjectL,
				lObjectG * rObjectA + lObjectH * rObjectE + lObjectI * rObjectI,
				lObjectG * rObjectB + lObjectH * rObjectF + lObjectI * rObjectJ,
				lObjectG * rObjectC + lObjectH * rObjectG + lObjectI * rObjectK,
				lObjectG * rObjectD + lObjectH * rObjectH + lObjectI * rObjectL
			);
		}
		template <typename T>
		constexpr typename TMatrix<3, 3, T>::column_t operator*(TMatrix<3, 3, T> const &matrix, typename TMatrix<3, 3, T>::row_t const &vector) noexcept
		{
			return typename TMatrix<3, 3, T>::column_t
			(
				matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
				matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
				matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator/(T scalar, TMatrix<3, 3, T> const &object) noexcept
		{
			return TMatrix<3, 3, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator/(TMatrix<3, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 3, T>(object) /= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator/(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return TMatrix<3, 3, T>(lObject) /= rObject;
		}
		template <typename T>
		constexpr typename TMatrix<3, 3, T>::column_t operator/(TMatrix<3, 3, T> const &matrix, typename TMatrix<3, 3, T>::row_t const &vector) noexcept
		{
			return detail::ComputeInverse(matrix) * vector;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1] &&
				lObject[2] == rObject[2]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<3, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif