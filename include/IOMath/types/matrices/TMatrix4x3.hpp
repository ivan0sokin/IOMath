#ifndef _IO_MATH_TMATRIX_4X3_HPP
#define _IO_MATH_TMATRIX_4X3_HPP

#include "../vectors/TVector4.hpp"
#include "../vectors/TVector3.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<4, 3, T>
		{
			typedef TVector<3, T> row_t;
			typedef TVector<4, T> column_t;
		private:
			row_t data[4];
		public:
			constexpr TMatrix() noexcept = default;
			constexpr TMatrix(TMatrix const &other) noexcept = default;
			constexpr explicit TMatrix(T scalar) noexcept :
				data
				{
					row_t(scalar, 0, 0),
					row_t(0, scalar, 0),
					row_t(0, 0, scalar),
					row_t(),
				} {}
			constexpr TMatrix(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3, T d1, T d2, T d3) noexcept :
				data
				{
					row_t(a1, a2, a3),
					row_t(b1, b2, b3),
					row_t(c1, c2, c3),
					row_t(d1, d2, d3)
				} {}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow, row_t const &thirdRow, row_t const &fourthRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow),
					row_t(fourthRow)
				} {}

			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l) noexcept :
				data
				{
					row_t(a, b, c),
					row_t(d, e, f),
					row_t(g, h, i),
					row_t(j, k, l)
				} {}
			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(TVector<3, A> const &firstRow, TVector<3, B> const &secondRow, TVector<3, C> const &thirdRow, TVector<3, D> const &fourthRow) noexcept :
				data
				{
					row_t(firstRow),
					row_t(secondRow),
					row_t(thirdRow),
					row_t(fourthRow)
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<3, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2]),
					row_t()
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 3, U> const &other) noexcept :
				data
				{
					row_t(other[0], 0),
					row_t(other[1], 0),
					row_t(other[2], 0),
					row_t(other[3], 0)
				} {}
			template <typename U>
			constexpr TMatrix(TMatrix<4, 2, U> const &other) noexcept :
				data
				{
					row_t(other[0]),
					row_t(other[1]),
					row_t(other[2]),
					row_t(other[3])
				} {}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &otherA, TMatrix<2, 3, U> const &otherB) noexcept :
				data
				{
					row_t(otherA[0]),
					row_t(otherA[1]),
					row_t(otherB[0]),
					row_t(otherB[1])
				} {}

			template <typename U>
			static constexpr TMatrix<4, 3, T> FromMatrix2x4(TMatrix<2, 4, U> const &other) noexcept
			{
				return TMatrix<4, 3, T>
				(
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t(),
					row_t()
				);
			}
			template <typename U>
			static constexpr TMatrix<4, 3, T> FromMatrix3x4(TMatrix<3, 4, U> const &other) noexcept
			{
				return TMatrix<4, 3, T>
				(
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t::FromVector4(other[2]),
					row_t()
				);
			}
			template <typename U>
			static constexpr TMatrix<4, 3, T> FromMatrix4x4(TMatrix<4, 4, U> const &other) noexcept
			{
				return TMatrix<4, 3, T>
				(
					row_t::FromVector4(other[0]),
					row_t::FromVector4(other[1]),
					row_t::FromVector4(other[2]),
					row_t::FromVector4(other[3])
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
			constexpr TMatrix<4, 3, T>& operator=(TMatrix<4, 3, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
				this->data[3] = other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;
				this->data[3] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator+=(TMatrix<4, 3, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];
				this->data[3] += other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;
				this->data[3] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator-=(TMatrix<4, 3, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];
				this->data[3] -= other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;
				this->data[3] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 3, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;
				this->data[3] /= scalar;

				return *this;
			}

			constexpr TMatrix<4, 3, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];
				++this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 3, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];
				--this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 3, T>& operator++(int) noexcept
			{
				TMatrix<4, 3, T> result = TMatrix<4, 3, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<4, 3, T>& operator--(int) noexcept
			{
				TMatrix<4, 3, T> result = TMatrix<4, 3, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<4, 3, T> operator+(TMatrix<4, 3, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator-(TMatrix<4, 3, T> const &object) noexcept
		{
			return TMatrix<4, 3, T>
			(
				-object[0],
				-object[1],
				-object[2],
				-object[3]
			);
		}
	
		template <typename T>
		constexpr TMatrix<4, 3, T> operator+(T scalar, TMatrix<4, 3, T> const &object) noexcept
		{
			return TMatrix<4, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator+(TMatrix<4, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator+(TMatrix<4, 3, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			return TMatrix<4, 3, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator-(T scalar, TMatrix<4, 3, T> const &object) noexcept
		{
			return TMatrix<4, 3, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2],
				scalar - object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator-(TMatrix<4, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 3, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator-(TMatrix<4, 3, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			return TMatrix<4, 3, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator*(T scalar, TMatrix<4, 3, T> const &object) noexcept
		{
			return TMatrix<4, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator*(TMatrix<4, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 2, T> operator*(TMatrix<4, 3, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
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
			T const lObjectJ = lObject[3][0];
			T const lObjectK = lObject[3][1];
			T const lObjectL = lObject[3][2];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];
			T const rObjectE = rObject[2][0];
			T const rObjectF = rObject[2][1];

			return TMatrix<4, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF,
				lObjectD * rObjectA + lObjectE * rObjectC + lObjectF * rObjectE,
				lObjectD * rObjectB + lObjectE * rObjectD + lObjectF * rObjectF,
				lObjectG * rObjectA + lObjectH * rObjectC + lObjectI * rObjectE,
				lObjectG * rObjectB + lObjectH * rObjectD + lObjectI * rObjectF,
				lObjectJ * rObjectA + lObjectK * rObjectC + lObjectL * rObjectE,
				lObjectJ * rObjectB + lObjectK * rObjectD + lObjectL * rObjectF
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator*(TMatrix<4, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
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
			T const lObjectJ = lObject[3][0];
			T const lObjectK = lObject[3][1];
			T const lObjectL = lObject[3][2];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[0][2];
			T const rObjectD = rObject[1][0];
			T const rObjectE = rObject[1][1];
			T const rObjectF = rObject[1][2];
			T const rObjectG = rObject[2][0];
			T const rObjectH = rObject[2][1];
			T const rObjectI = rObject[2][2];

			return TMatrix<4, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI,
				lObjectD * rObjectA + lObjectE * rObjectD + lObjectF * rObjectG,
				lObjectD * rObjectB + lObjectE * rObjectE + lObjectF * rObjectH,
				lObjectD * rObjectC + lObjectE * rObjectF + lObjectF * rObjectI,
				lObjectG * rObjectA + lObjectH * rObjectD + lObjectI * rObjectG,
				lObjectG * rObjectB + lObjectH * rObjectE + lObjectI * rObjectH,
				lObjectG * rObjectC + lObjectH * rObjectF + lObjectI * rObjectI,
				lObjectJ * rObjectA + lObjectK * rObjectD + lObjectL * rObjectG,
				lObjectJ * rObjectB + lObjectK * rObjectE + lObjectL * rObjectH,
				lObjectJ * rObjectC + lObjectK * rObjectF + lObjectL * rObjectI
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(TMatrix<4, 3, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
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
			T const lObjectJ = lObject[3][0];
			T const lObjectK = lObject[3][1];
			T const lObjectL = lObject[3][2];

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

			return TMatrix<4, 4, T>
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
				lObjectG * rObjectD + lObjectH * rObjectH + lObjectI * rObjectL,
				lObjectJ * rObjectA + lObjectK * rObjectE + lObjectL * rObjectI,
				lObjectJ * rObjectB + lObjectK * rObjectF + lObjectL * rObjectJ,
				lObjectJ * rObjectC + lObjectK * rObjectG + lObjectL * rObjectK,
				lObjectJ * rObjectD + lObjectK * rObjectH + lObjectL * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator/(T scalar, TMatrix<4, 3, T> const &object) noexcept
		{
			return TMatrix<4, 3, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2],
				scalar / object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator/(TMatrix<4, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 3, T>(object) /= scalar;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<4, 3, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1] &&
				lObject[2] == rObject[2] &&
				lObject[3] == rObject[3]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<4, 3, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	
	}
}

#endif