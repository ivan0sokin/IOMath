#ifndef _IO_MATH_TMATRIX_2X4_HPP
#define _IO_MATH_TMATRIX_2X4_HPP

#include "../vectors/TVector2.hpp"
#include "../vectors/TVector4.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<2, 4, T>
		{
			typedef TVector<4, T> row_t;
			typedef TVector<2, T> column_t;
		private:
			row_t data[2];
		public:
			constexpr TMatrix() noexcept
			{
				this->data[0] = row_t();
				this->data[1] = row_t();
			}
			constexpr TMatrix(TMatrix const &other) noexcept
			{
				*this = other;
			}
			constexpr TMatrix(T scalar) noexcept
			{
				this->data[0] = row_t(scalar, 0, 0, 0);
				this->data[1] = row_t(0, scalar, 0, 0);
			}
			constexpr TMatrix(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4) noexcept
			{
				this->data[0] = row_t(a1, a2, a3, a4);
				this->data[1] = row_t(b1, b2, b3, b4);
			}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
			}

			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h) noexcept
			{
				this->data[0] = row_t(a, b, c, d);
				this->data[1] = row_t(e, f, g, h);
			}
			template <typename A, typename B>
			constexpr TMatrix(TVector<4, A> const &firstRow, TVector<4, B> const &secondRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
			}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
			}

			constexpr TMatrix(TMatrix<2, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0, 0);
				this->data[1] = row_t(other[1], 0, 0);
			}
			constexpr TMatrix(TMatrix<2, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<3, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0, 0);
				this->data[1] = row_t(other[1], 0, 0);
			}
			constexpr TMatrix(TMatrix<3, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<3, 4, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
			}
			constexpr TMatrix(TMatrix<4, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0, 0);
				this->data[1] = row_t(other[1], 0, 0);
			}
			constexpr TMatrix(TMatrix<4, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<4, 4, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
			}
			constexpr TMatrix(TMatrix<2, 2, T> const &otherA, TMatrix<2, 2, T> const &otherB) noexcept
			{
				this->data[0] = row_t(otherA[0], otherB[0]);
				this->data[1] = row_t(otherA[1], otherB[1]);
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
			constexpr TMatrix<2, 4, T>& operator=(TMatrix<2, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator+=(TMatrix<2, 4, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator-=(TMatrix<2, 4, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 4, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;

				return *this;
			}

			constexpr TMatrix<2, 4, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 4, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 4, T>& operator++(int) noexcept
			{
				TMatrix<2, 4, T> result = TMatrix<2, 4, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<2, 4, T>& operator--(int) noexcept
			{
				TMatrix<2, 4, T> result = TMatrix<2, 4, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<2, 4, T> operator+(TMatrix<2, 4, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator-(TMatrix<2, 4, T> const &object) noexcept
		{
			return TMatrix<2, 4, T>
			(
				-object[0],
				-object[1]
			);
		}

		template <typename T>
		constexpr TMatrix<2, 4, T> operator+(T scalar, TMatrix<2, 4, T> const &object) noexcept
		{
			return TMatrix<2, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator+(TMatrix<2, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator+(TMatrix<2, 4, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			return TMatrix<2, 4, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator-(T scalar, TMatrix<2, 4, T> const &object) noexcept
		{
			return TMatrix<2, 4, T>
			(
				scalar - object[0],
				scalar - object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator-(TMatrix<2, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 4, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator-(TMatrix<2, 4, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			return TMatrix<2, 4, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(T scalar, TMatrix<2, 4, T> const &object) noexcept
		{
			return TMatrix<2, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 4, T> const &lObject, TMatrix<4, 2, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];
			T const rObjectE = rObject[2][0];
			T const rObjectF = rObject[2][1];
			T const rObjectG = rObject[3][0];
			T const rObjectH = rObject[3][1];

			return TMatrix<2, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE + lObjectD * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF + lObjectD * rObjectH,
				lObjectE * rObjectA + lObjectF * rObjectC + lObjectG * rObjectE + lObjectH * rObjectG,
				lObjectE * rObjectB + lObjectF * rObjectD + lObjectG * rObjectF + lObjectH * rObjectH
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 4, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[0][2];
			T const rObjectD = rObject[1][0];
			T const rObjectE = rObject[1][1];
			T const rObjectF = rObject[1][2];
			T const rObjectG = rObject[2][0];
			T const rObjectH = rObject[2][1];
			T const rObjectI = rObject[2][2];
			T const rObjectJ = rObject[3][0];
			T const rObjectK = rObject[3][1];
			T const rObjectL = rObject[3][2];

			return TMatrix<2, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG + lObjectD * rObjectJ,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH + lObjectD * rObjectK,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI + lObjectD * rObjectL,
				lObjectE * rObjectA + lObjectF * rObjectD + lObjectG * rObjectG + lObjectH * rObjectJ,
				lObjectE * rObjectB + lObjectF * rObjectE + lObjectG * rObjectH + lObjectH * rObjectK,
				lObjectE * rObjectC + lObjectF * rObjectF + lObjectG * rObjectI + lObjectH * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];

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
			T const rObjectM = rObject[3][0];
			T const rObjectN = rObject[3][1];
			T const rObjectO = rObject[3][2];
			T const rObjectP = rObject[3][3];

			return TMatrix<2, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI + lObjectD * rObjectM,
				lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ + lObjectD * rObjectN,
				lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK + lObjectD * rObjectO,
				lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL + lObjectD * rObjectP,
				lObjectE * rObjectA + lObjectF * rObjectE + lObjectG * rObjectI + lObjectH * rObjectM,
				lObjectE * rObjectB + lObjectF * rObjectF + lObjectG * rObjectJ + lObjectH * rObjectN,
				lObjectE * rObjectC + lObjectF * rObjectG + lObjectG * rObjectK + lObjectH * rObjectO,
				lObjectE * rObjectD + lObjectF * rObjectH + lObjectG * rObjectL + lObjectH * rObjectP
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator/(T scalar, TMatrix<2, 4, T> const &object) noexcept
		{
			return TMatrix<2, 4, T>
			(
				scalar / object[0],
				scalar / object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator/(TMatrix<2, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 4, T>(object) /= scalar;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<2, 4, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<2, 4, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	
	}
}

#endif