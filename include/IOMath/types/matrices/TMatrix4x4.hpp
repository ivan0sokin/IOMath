#ifndef _IO_MATH_TMATRIX_4X4_HPP
#define _IO_MATH_TMATRIX_4X4_HPP

#include "../vectors/TVector4.hpp"
#include "../../detail/ComputeMatrixFunctions.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<4, 4, T>
		{
			typedef TVector<4, T> row_t;
			typedef TVector<4, T> column_t;
		private:
			row_t data[4];
		public:
			constexpr TMatrix() noexcept
			{
				this->data[0] = row_t();
				this->data[1] = row_t();
				this->data[2] = row_t();
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix const &other) noexcept
			{
				*this = other;
			}
			constexpr TMatrix(T scalar) noexcept
			{
				this->data[0] = row_t(scalar, 0, 0, 0);
				this->data[1] = row_t(0, scalar, 0, 0);
				this->data[2] = row_t(0, 0, scalar, 0);
				this->data[3] = row_t(0, 0, 0, scalar);
			}
			constexpr TMatrix(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4, T d1, T d2, T d3, T d4) noexcept
			{
				this->data[0] = row_t(a1, a2, a3, a4);
				this->data[1] = row_t(b1, b2, b3, b4);
				this->data[2] = row_t(c1, c2, c3, c4);
				this->data[3] = row_t(d1, d2, d3, d4);
			}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow, row_t const& thirdRow, row_t const &fourthRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
				this->data[2] = thirdRow;
				this->data[3] = fourthRow;
			}

			template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J, typename K, typename L, typename M, typename N, typename O, typename P>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f, G g, H h, I i, J j, K k, L l, M m, N n, O o, P p) noexcept
			{
				this->data[0] = row_t(a, b, c, d);
				this->data[1] = row_t(e, f, g, h);
				this->data[2] = row_t(i, j, k, l);
				this->data[3] = row_t(m, n, o, p);
			}
			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(TVector<2, A> const &firstRow, TVector<2, B> const &secondRow, TVector<2, C> const &thirdRow, TVector<2, D> const &fourthRow) noexcept
			{
				this->data[0] = row_t(firstRow, 0, 0);
				this->data[1] = row_t(secondRow, 0, 0);
				this->data[2] = row_t(thirdRow, 0, 0);
				this->data[3] = row_t(fourthRow, 0, 0);
			}
			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(TVector<3, A> const &firstRow, TVector<3, B> const &secondRow, TVector<3, C> const &thirdRow, TVector<3, D> const &fourthRow) noexcept
			{
				this->data[0] = row_t(firstRow, 0);
				this->data[1] = row_t(secondRow, 0);
				this->data[2] = row_t(thirdRow, 0);
				this->data[3] = row_t(fourthRow, 0);
			}
			template <typename A, typename B, typename C, typename D>
			constexpr TMatrix(TVector<4, A> const &firstRow, TVector<2, B> const &secondRow, TVector<2, C> const &thirdRow, TVector<3, D> const &fourthRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
				this->data[2] = thirdRow;
				this->data[3] = fourthRow;
			}

			template <typename U>
			constexpr TMatrix(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
				this->data[3] = other[3];
			}
			
			constexpr TMatrix(TMatrix<2, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0, 0);
				this->data[1] = row_t(other[1], 0, 0);
				this->data[2] = row_t();
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<2, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
				this->data[2] = row_t();
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<2, 4, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = row_t();
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<3, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0, 0);
				this->data[1] = row_t(other[1], 0, 0);
				this->data[2] = row_t(other[2], 0, 0);
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<3, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
				this->data[2] = row_t(other[2], 0);
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<3, 4, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
				this->data[3] = row_t();
			}
			constexpr TMatrix(TMatrix<4, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
				this->data[2] = row_t(other[2], 0);
				this->data[3] = row_t(other[3], 0);
			}
			constexpr TMatrix(TMatrix<4, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
				this->data[2] = row_t(other[2], 0);
				this->data[3] = row_t(other[3], 0);
			}
			constexpr TMatrix(TMatrix<2, 2, T> const &otherA, TMatrix<2, 2, T> const &otherB, TMatrix<2, 2, T> const &otherC, TMatrix<2, 2, T> const &otherD) noexcept
			{
				this->data[0] = row_t(otherA[0], otherB[0]);
				this->data[1] = row_t(otherA[1], otherB[1]);
				this->data[2] = row_t(otherC[0], otherD[0]);
				this->data[3] = row_t(otherC[1], otherD[1]);
			}

			static constexpr TMatrix<4, 4, T> Identity() noexcept
			{
				return TMatrix<4, 4, T>
				(
					1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
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
			constexpr TMatrix<4, 4, T>& operator=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
				this->data[3] = other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;
				this->data[3] += scalar;
				
				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator+=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];
				this->data[3] += other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;
				this->data[3] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator-=(TMatrix<4, 4, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];
				this->data[3] -= other[3];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;
				this->data[3] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator*=(TMatrix<4, 4, U> const &other) noexcept
			{
				return (*this = *this * other);
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;
				this->data[3] /= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<4, 4, T>& operator/=(TMatrix<4, 4, U> const &other) noexcept
			{
				return *this *= detail::ComputeInverse(other);
			}

			constexpr TMatrix<4, 4, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];
				++this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 4, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];
				--this->data[3];

				return *this;
			}
			constexpr TMatrix<4, 4, T>& operator++(int) noexcept
			{
				TMatrix<4, 4, T> result = TMatrix<4, 4, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<4, 4, T>& operator--(int) noexcept
			{
				TMatrix<4, 4, T> result = TMatrix<4, 4, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				-object[0],
				-object[1],
				-object[2],
				-object[3]
			);
		}
	
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator+(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2],
				scalar - object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator-(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr typename TMatrix<4, 4, T>::column_t operator*(TMatrix<4, 4, T> const &matrix, typename TMatrix<4, 4, T>::row_t const &vector) noexcept
		{
			return typename TMatrix<4, 4, T>::column_t
			(
				matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z + matrix[0][3] * vector.w,
				matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z + matrix[1][3] * vector.w,
				matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z + matrix[2][3] * vector.w,
				matrix[3][0] * vector.x + matrix[3][1] * vector.y + matrix[3][2] * vector.z + matrix[3][3] * vector.w
			);
		}
		template <typename T>
		constexpr TMatrix<4, 2, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 2, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];
			T const lObjectI = lObject[2][0];
			T const lObjectJ = lObject[2][1];
			T const lObjectK = lObject[2][2];
			T const lObjectL = lObject[2][3];
			T const lObjectM = lObject[3][0];
			T const lObjectN = lObject[3][1];
			T const lObjectO = lObject[3][2];
			T const lObjectP = lObject[3][3];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];
			T const rObjectE = rObject[2][0];
			T const rObjectF = rObject[2][1];
			T const rObjectG = rObject[3][0];
			T const rObjectH = rObject[3][1];

			return TMatrix<4, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC + lObjectC * rObjectE + lObjectD * rObjectG,
				lObjectA * rObjectB + lObjectB * rObjectD + lObjectC * rObjectF + lObjectD * rObjectH,
				lObjectE * rObjectA + lObjectF * rObjectC + lObjectG * rObjectE + lObjectH * rObjectG,
				lObjectE * rObjectB + lObjectF * rObjectD + lObjectG * rObjectF + lObjectH * rObjectH,
				lObjectI * rObjectA + lObjectJ * rObjectC + lObjectK * rObjectE + lObjectL * rObjectG,
				lObjectI * rObjectB + lObjectJ * rObjectD + lObjectK * rObjectF + lObjectL * rObjectH,
				lObjectM * rObjectA + lObjectN * rObjectC + lObjectO * rObjectE + lObjectP * rObjectG,
				lObjectM * rObjectB + lObjectN * rObjectD + lObjectO * rObjectF + lObjectP * rObjectH
			);
		}
		template <typename T>
		constexpr TMatrix<4, 3, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 3, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];
			T const lObjectI = lObject[2][0];
			T const lObjectJ = lObject[2][1];
			T const lObjectK = lObject[2][2];
			T const lObjectL = lObject[2][3];
			T const lObjectM = lObject[3][0];
			T const lObjectN = lObject[3][1];
			T const lObjectO = lObject[3][2];
			T const lObjectP = lObject[3][3];

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

			return TMatrix<4, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD + lObjectC * rObjectG + lObjectD * rObjectJ,
				lObjectA * rObjectB + lObjectB * rObjectE + lObjectC * rObjectH + lObjectD * rObjectK,
				lObjectA * rObjectC + lObjectB * rObjectF + lObjectC * rObjectI + lObjectD * rObjectL,
				lObjectE * rObjectA + lObjectF * rObjectD + lObjectG * rObjectG + lObjectH * rObjectJ,
				lObjectE * rObjectB + lObjectF * rObjectE + lObjectG * rObjectH + lObjectH * rObjectK,
				lObjectE * rObjectC + lObjectF * rObjectF + lObjectG * rObjectI + lObjectH * rObjectL,
				lObjectI * rObjectA + lObjectJ * rObjectD + lObjectK * rObjectG + lObjectL * rObjectJ,
				lObjectI * rObjectB + lObjectJ * rObjectE + lObjectK * rObjectH + lObjectL * rObjectK,
				lObjectI * rObjectC + lObjectJ * rObjectF + lObjectK * rObjectI + lObjectL * rObjectL,
				lObjectM * rObjectA + lObjectN * rObjectD + lObjectO * rObjectG + lObjectP * rObjectJ,
				lObjectM * rObjectB + lObjectN * rObjectE + lObjectO * rObjectH + lObjectP * rObjectK,
				lObjectM * rObjectC + lObjectN * rObjectF + lObjectO * rObjectI + lObjectP * rObjectL
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator*(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[0][2];
			T const lObjectD = lObject[0][3];
			T const lObjectE = lObject[1][0];
			T const lObjectF = lObject[1][1];
			T const lObjectG = lObject[1][2];
			T const lObjectH = lObject[1][3];
			T const lObjectI = lObject[2][0];
			T const lObjectJ = lObject[2][1];
			T const lObjectK = lObject[2][2];
			T const lObjectL = lObject[2][3];
			T const lObjectM = lObject[3][0];
			T const lObjectN = lObject[3][1];
			T const lObjectO = lObject[3][2];
			T const lObjectP = lObject[3][3];

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

			return TMatrix<4, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE + lObjectC * rObjectI + lObjectD * rObjectM,
				lObjectA * rObjectB + lObjectB * rObjectF + lObjectC * rObjectJ + lObjectD * rObjectN,
				lObjectA * rObjectC + lObjectB * rObjectG + lObjectC * rObjectK + lObjectD * rObjectO,
				lObjectA * rObjectD + lObjectB * rObjectH + lObjectC * rObjectL + lObjectD * rObjectP,
				lObjectE * rObjectA + lObjectF * rObjectE + lObjectG * rObjectI + lObjectH * rObjectM,
				lObjectE * rObjectB + lObjectF * rObjectF + lObjectG * rObjectJ + lObjectH * rObjectN,
				lObjectE * rObjectC + lObjectF * rObjectG + lObjectG * rObjectK + lObjectH * rObjectO,
				lObjectE * rObjectD + lObjectF * rObjectH + lObjectG * rObjectL + lObjectH * rObjectP,
				lObjectI * rObjectA + lObjectJ * rObjectE + lObjectK * rObjectI + lObjectL * rObjectM,
				lObjectI * rObjectB + lObjectJ * rObjectF + lObjectK * rObjectJ + lObjectL * rObjectN,
				lObjectI * rObjectC + lObjectJ * rObjectG + lObjectK * rObjectK + lObjectL * rObjectO,
				lObjectI * rObjectD + lObjectJ * rObjectH + lObjectK * rObjectL + lObjectL * rObjectP,
				lObjectM * rObjectA + lObjectN * rObjectE + lObjectO * rObjectI + lObjectP * rObjectM,
				lObjectM * rObjectB + lObjectN * rObjectF + lObjectO * rObjectJ + lObjectP * rObjectN,
				lObjectM * rObjectC + lObjectN * rObjectG + lObjectO * rObjectK + lObjectP * rObjectO,
				lObjectM * rObjectD + lObjectN * rObjectH + lObjectO * rObjectL + lObjectP * rObjectP
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(T scalar, TMatrix<4, 4, T> const &object) noexcept
		{
			return TMatrix<4, 4, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2],
				scalar / object[3]
			);
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(TMatrix<4, 4, T> const &object, T scalar) noexcept
		{
			return TMatrix<4, 4, T>(object) /= scalar;
		}
		template <typename T>
		constexpr typename TMatrix<4, 4, T>::row_t operator/(TMatrix<4, 4, T> const& matrix, typename TMatrix<4, 4, T>::row_t const &vector) noexcept
		{
			return detail::ComputeInverse(matrix) * vector;
		}
		template <typename T>
		constexpr TMatrix<4, 4, T> operator/(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return TMatrix<4, 4, T>(lObject) /= rObject;
		}

		template <typename T>
		constexpr bool operator==(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
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
		constexpr bool operator!=(TMatrix<4, 4, T> const &lObject, TMatrix<4, 4, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif