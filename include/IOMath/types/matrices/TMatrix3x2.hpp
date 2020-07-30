#ifndef _IO_MATH_TMATRIX_3X2_HPP
#define _IO_MATH_TMATRIX_3X2_HPP

#include "../vectors/TVector3.hpp"
#include "../vectors/TVector2.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<3, 2, T>
		{
			typedef TVector<2, T> row_t;
			typedef TVector<3, T> column_t;
		private:
			row_t data[3];
		public:
			constexpr TMatrix() noexcept
			{
				this->data[0] = row_t();
				this->data[1] = row_t();
				this->data[2] = row_t();
			}
			constexpr TMatrix(TMatrix const &other) noexcept
			{
				*this = other;
			}
			constexpr TMatrix(T scalar) noexcept
			{
				this->data[0] = row_t(scalar, 0);
				this->data[1] = row_t(0, scalar);
				this->data[2] = row_t();
			}
			constexpr TMatrix(T a1, T a2, T b1, T b2, T c1, T c2) noexcept
			{
				this->data[0] = row_t(a1, a2);
				this->data[1] = row_t(b1, b2);
				this->data[2] = row_t(c1, c2);
			}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow, row_t const &thirdRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
				this->data[2] = thirdRow;
			}

			template <typename A, typename B, typename C, typename D, typename E, typename F>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f) noexcept
			{
				this->data[0] = row_t(a, b);
				this->data[1] = row_t(c, d);
				this->data[2] = row_t(e, f);
			}
			template <typename A, typename B, typename C>
			constexpr TMatrix(TVector<2, A> const &firstRow, TVector<2, B> const &secondRow, TVector<2, C> const &thirdRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
				this->data[2] = thirdRow;
			}

			template <typename U>
			constexpr TMatrix(TMatrix<3, 2, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
			}
			
			constexpr TMatrix(TMatrix<2, 2, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = row_t();
			}
			constexpr TMatrix(TMatrix<2, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[2] = row_t();
			}
			constexpr TMatrix(TMatrix<2, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[2] = row_t();
			}
			constexpr TMatrix(TMatrix<3, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[2] = row_t(other[2]);
			}
			constexpr TMatrix(TMatrix<3, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[3] = row_t(other[2]);
			}
			constexpr TMatrix(TMatrix<4, 2, T> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];
			}
			constexpr TMatrix(TMatrix<4, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[2] = row_t(other[2]);
			}
			constexpr TMatrix(TMatrix<4, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
				this->data[2] = row_t(other[2]);
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
			constexpr TMatrix<3, 2, T>& operator=(TMatrix<3, 2, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
				this->data[2] = other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;
				this->data[2] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator+=(TMatrix<3, 2, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];
				this->data[2] += other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;
				this->data[2] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator-=(TMatrix<3, 2, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];
				this->data[2] -= other[2];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;
				this->data[2] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<3, 2, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;
				this->data[2] /= scalar;

				return *this;
			}

			constexpr TMatrix<3, 2, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];
				++this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 2, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];
				--this->data[2];

				return *this;
			}
			constexpr TMatrix<3, 2, T>& operator++(int) noexcept
			{
				TMatrix<3, 2, T> result = TMatrix<3, 2, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<3, 2, T>& operator--(int) noexcept
			{
				TMatrix<3, 2, T> result = TMatrix<3, 2, T>(*this);

				--*this;

				return result;
			}
		};

		template <typename T>
		constexpr TMatrix<3, 2, T> operator+(TMatrix<3, 2, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator-(TMatrix<3, 2, T> const &object) noexcept
		{
			return TMatrix<3, 2, T>
			(
				-object[0],
				-object[1],
				-object[2]
			);
		}
	
		template <typename T>
		constexpr TMatrix<3, 2, T> operator+(T scalar, TMatrix<3, 2, T> const &object) noexcept
		{
			return TMatrix<3, 2, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator+(TMatrix<3, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 2, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator+(TMatrix<3, 2, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			return TMatrix<3, 2, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator-(T scalar, TMatrix<3, 2, T> const &object) noexcept
		{
			return TMatrix<3, 2, T>
			(
				scalar - object[0],
				scalar - object[1],
				scalar - object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator-(TMatrix<3, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 2, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator-(TMatrix<3, 2, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			return TMatrix<3, 2, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator*(T scalar, TMatrix<3, 2, T> const &object) noexcept
		{
			return TMatrix<3, 2, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator*(TMatrix<3, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 2, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator*(TMatrix<3, 2, T> const &lObject, TMatrix<2, 2, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[1][0];
			T const lObjectD = lObject[1][1];
			T const lObjectE = lObject[2][0];
			T const lObjectF = lObject[2][1];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[1][0];
			T const rObjectD = rObject[1][1];

			return TMatrix<3, 2, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectC,
				lObjectA * rObjectB + lObjectB * rObjectD,
				lObjectC * rObjectA + lObjectD * rObjectC,
				lObjectC * rObjectB + lObjectD * rObjectD,
				lObjectE * rObjectA + lObjectF * rObjectC,
				lObjectE * rObjectB + lObjectF * rObjectD
			);
		}
		template <typename T>
		constexpr TMatrix<3, 3, T> operator*(TMatrix<3, 2, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[1][0];
			T const lObjectD = lObject[1][1];
			T const lObjectE = lObject[2][0];
			T const lObjectF = lObject[2][1];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[0][2];
			T const rObjectD = rObject[1][0];
			T const rObjectE = rObject[1][1];
			T const rObjectF = rObject[1][2];

			return TMatrix<3, 3, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectD,
				lObjectA * rObjectB + lObjectB * rObjectE,
				lObjectA * rObjectC + lObjectB * rObjectF,
				lObjectC * rObjectA + lObjectD * rObjectD,
				lObjectC * rObjectB + lObjectD * rObjectE,
				lObjectC * rObjectC + lObjectD * rObjectF,
				lObjectE * rObjectA + lObjectF * rObjectD,
				lObjectE * rObjectB + lObjectF * rObjectE,
				lObjectE * rObjectC + lObjectF * rObjectF
			);
		}
		template <typename T>
		constexpr TMatrix<3, 4, T> operator*(TMatrix<3, 2, T> const &lObject, TMatrix<2, 4, T> const &rObject) noexcept
		{
			T const lObjectA = lObject[0][0];
			T const lObjectB = lObject[0][1];
			T const lObjectC = lObject[1][0];
			T const lObjectD = lObject[1][1];
			T const lObjectE = lObject[2][0];
			T const lObjectF = lObject[2][1];

			T const rObjectA = rObject[0][0];
			T const rObjectB = rObject[0][1];
			T const rObjectC = rObject[0][2];
			T const rObjectD = rObject[0][3];
			T const rObjectE = rObject[1][0];
			T const rObjectF = rObject[1][1];
			T const rObjectG = rObject[1][2];
			T const rObjectH = rObject[1][3];

			return TMatrix<3, 4, T>
			(
				lObjectA * rObjectA + lObjectB * rObjectE,
				lObjectA * rObjectB + lObjectB * rObjectF,
				lObjectA * rObjectC + lObjectB * rObjectG,
				lObjectA * rObjectD + lObjectB * rObjectH,
				lObjectC * rObjectA + lObjectD * rObjectE,
				lObjectC * rObjectB + lObjectD * rObjectF,
				lObjectC * rObjectC + lObjectD * rObjectG,
				lObjectC * rObjectD + lObjectD * rObjectH,
				lObjectE * rObjectA + lObjectF * rObjectE,
				lObjectE * rObjectB + lObjectF * rObjectF,
				lObjectE * rObjectC + lObjectF * rObjectG,
				lObjectE * rObjectD + lObjectF * rObjectH
			);
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator/(T scalar, TMatrix<3, 2, T> const &object) noexcept
		{
			return TMatrix<3, 2, T>
			(
				scalar / object[0],
				scalar / object[1],
				scalar / object[2]
			);
		}
		template <typename T>
		constexpr TMatrix<3, 2, T> operator/(TMatrix<3, 2, T> const &object, T scalar) noexcept
		{
			return TMatrix<3, 2, T>(object) /= scalar;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<3, 2, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1] &&
				lObject[2] == rObject[2]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<3, 2, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif