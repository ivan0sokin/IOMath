#ifndef _IO_MATH_TMATRIX_2X3_HPP
#define _IO_MATH_TMATRIX_2X3_HPP

#include "../vectors/TVector2.hpp"
#include "../vectors/TVector3.hpp"
#include "../BasicTypes.hpp"

#include <cassert>
#include <memory.h>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TMatrix<2, 3, T>
		{
			typedef TVector<3, T> row_t;
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
				this->data[0] = row_t(scalar, 0, 0);
				this->data[1] = row_t(0, scalar, 0);
			}
			constexpr TMatrix(T a1, T a2, T a3, T b1, T b2, T b3) noexcept
			{
				this->data[0] = row_t(a1, a2, a3);
				this->data[1] = row_t(b1, b2, b3);
			}
			constexpr TMatrix(row_t const &firstRow, row_t const &secondRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
			}

			template <typename A, typename B, typename C, typename D, typename E, typename F>
			constexpr TMatrix(A a, B b, C c, D d, E e, F f) noexcept
			{
				this->data[0] = row_t(a, b, c);
				this->data[1] = row_t(d, e, f);
			}
			template <typename A, typename B>
			constexpr TMatrix(TVector<3, A> const &firstRow, TVector<3, B> const &secondRow) noexcept
			{
				this->data[0] = firstRow;
				this->data[1] = secondRow;
			}

			template <typename U>
			constexpr TMatrix(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];
			}

			constexpr TMatrix(TMatrix<2, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<2, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
			}
			constexpr TMatrix(TMatrix<3, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<3, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
			}
			constexpr TMatrix(TMatrix<3, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
			}
			constexpr TMatrix(TMatrix<4, 2, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0], 0);
				this->data[1] = row_t(other[1], 0);
			}
			constexpr TMatrix(TMatrix<4, 3, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
			}
			constexpr TMatrix(TMatrix<4, 4, T> const &other) noexcept
			{
				this->data[0] = row_t(other[0]);
				this->data[1] = row_t(other[1]);
			}

			static constexpr TMatrix<2, 3, T> Identity() noexcept
			{
				return TMatrix<2, 3, T>
				(
					1, 0, 0,
					0, 1, 0
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
			constexpr TMatrix<2, 3, T>& operator=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] = other[0];
				this->data[1] = other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator+=(U scalar) noexcept
			{
				this->data[0] += scalar;
				this->data[1] += scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator+=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] += other[0];
				this->data[1] += other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator-=(U scalar) noexcept
			{
				this->data[0] -= scalar;
				this->data[1] -= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator-=(TMatrix<2, 3, U> const &other) noexcept
			{
				this->data[0] -= other[0];
				this->data[1] -= other[1];

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator*=(U scalar) noexcept
			{
				this->data[0] *= scalar;
				this->data[1] *= scalar;

				return *this;
			}
			template <typename U>
			constexpr TMatrix<2, 3, T>& operator/=(U scalar) noexcept
			{
				this->data[0] /= scalar;
				this->data[1] /= scalar;

				return *this;
			}

			constexpr TMatrix<2, 3, T>& operator++() noexcept
			{
				++this->data[0];
				++this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 3, T>& operator--() noexcept
			{
				--this->data[0];
				--this->data[1];

				return *this;
			}
			constexpr TMatrix<2, 3, T>& operator++(int) noexcept
			{
				TMatrix<2, 3, T> result = TMatrix<2, 3, T>(*this);

				++*this;

				return result;
			}
			constexpr TMatrix<2, 3, T>& operator--(int) noexcept
			{
				TMatrix<2, 3, T> result = TMatrix<2, 3, T>(*this);

				--*this;

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
				-object[1]
			);
		}

		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>(object) += scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator+(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>
			(
				scalar - object[0],
				scalar - object[1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator-(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(T scalar, TMatrix<2, 3, T> const &object) noexcept
		{
			return TMatrix<2, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 3, T> const &object, T scalar) noexcept
		{
			return TMatrix<2, 3, T>(object) *= scalar;
		}
		template <typename T>
		constexpr typename TMatrix<2, 3, T>::column_t operator*(TMatrix<2, 3, T> const &matrix, typename TMatrix<2, 3, T>::row_t const &vector) noexcept
		{
			return typename TMatrix<2, 3, T>::column_t
			(
				matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
				matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z
			);
		}
		template <typename T>
		constexpr TMatrix<2, 2, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 2, T> const &rObject) noexcept
		{
			return TMatrix<2, 2, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0] + lObject[0][2] * rObject[2][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1] + lObject[0][2] * rObject[2][1],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0] + lObject[1][2] * rObject[2][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1] + lObject[1][2] * rObject[2][1]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 3, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 3, T> const &rObject) noexcept
		{
			return TMatrix<2, 3, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0] + lObject[0][2] * rObject[2][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1] + lObject[0][2] * rObject[2][1],
				lObject[0][0] * rObject[0][2] + lObject[0][1] * rObject[1][2] + lObject[0][2] * rObject[2][2],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0] + lObject[1][2] * rObject[2][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1] + lObject[1][2] * rObject[2][1],
				lObject[1][0] * rObject[0][2] + lObject[1][1] * rObject[1][2] + lObject[1][2] * rObject[2][2]
			);
		}
		template <typename T>
		constexpr TMatrix<2, 4, T> operator*(TMatrix<2, 3, T> const &lObject, TMatrix<3, 4, T> const &rObject) noexcept
		{
			return TMatrix<2, 4, T>
			(
				lObject[0][0] * rObject[0][0] + lObject[0][1] * rObject[1][0] + lObject[0][2] * rObject[2][0],
				lObject[0][0] * rObject[0][1] + lObject[0][1] * rObject[1][1] + lObject[0][2] * rObject[2][1],
				lObject[0][0] * rObject[0][2] + lObject[0][1] * rObject[1][2] + lObject[0][2] * rObject[2][2],
				lObject[0][0] * rObject[0][3] + lObject[0][1] * rObject[1][3] + lObject[0][2] * rObject[2][3],
				lObject[1][0] * rObject[0][0] + lObject[1][1] * rObject[1][0] + lObject[1][2] * rObject[2][0],
				lObject[1][0] * rObject[0][1] + lObject[1][1] * rObject[1][1] + lObject[1][2] * rObject[2][1],
				lObject[1][0] * rObject[0][2] + lObject[1][1] * rObject[1][2] + lObject[1][2] * rObject[2][2],
				lObject[1][0] * rObject[0][3] + lObject[1][1] * rObject[1][3] + lObject[1][2] * rObject[2][3]
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
			return TMatrix<2, 3, T>(object) /= scalar;
		}
	
		template <typename T>
		constexpr bool operator==(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return
			(
				lObject[0] == rObject[0] &&
				lObject[1] == rObject[1]
			);
		}
		template <typename T>
		constexpr bool operator!=(TMatrix<2, 3, T> const &lObject, TMatrix<2, 3, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
	}
}

#endif