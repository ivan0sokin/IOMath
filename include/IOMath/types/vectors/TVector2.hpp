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

#ifndef _IO_MATH_TVECTOR_2_HPP
#define _IO_MATH_TVECTOR_2_HPP

#include "../BasicTypes.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TVector<2, T>
		{
			union
			{
				struct { T x, y; };
				struct { T r, g; };
			};

			constexpr TVector() noexcept
			{
				this->x = static_cast<T>(0);
				this->y = static_cast<T>(0);
			}
			constexpr TVector(TVector const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;
			}
			constexpr TVector(T scalar) noexcept
			{
				this->x = scalar;
				this->y = scalar;
			}
			constexpr TVector(T a, T b) noexcept
			{
				this->x = a;
				this->y = b;
			}

			template<typename A, typename B>
			constexpr TVector(A a, B b) noexcept
			{
				this->x = static_cast<T>(a);
				this->y = static_cast<T>(b);
			}

			template <typename U>
			constexpr TVector(TVector<2, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
			}
			template <typename U>
			constexpr TVector(TVector<3, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
			}
			template <typename U>
			constexpr TVector(TVector<4, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
			}

			static constexpr size_t Size() noexcept
			{
				return static_cast<size_t>(2);
			}

			constexpr T& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TVector::Size());

				switch (index)
				{
				case 0:
					return x;
				case 1:
					return y;
				}
			}
			constexpr T const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TVector::Length());

				switch (index)
				{
				case 0:
					return x;
				case 1:
					return y;
				}
			}

			constexpr TVector<2, T>& operator=(TVector const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator=(TVector<2, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);

				return *this;
			}

			template <typename U>
			constexpr TVector<2, T>& operator+=(U scalar) noexcept
			{
				this->x += static_cast<T>(scalar);
				this->y += static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator+=(TVector<2, U> const &other) noexcept
			{
				this->x += static_cast<T>(other.x);
				this->y += static_cast<T>(other.y);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator-=(U scalar) noexcept
			{
				this->x -= static_cast<T>(scalar);
				this->y -= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator-=(TVector<2, U> const &other) noexcept
			{
				this->x -= static_cast<T>(other.x);
				this->y -= static_cast<T>(other.y);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator*=(U scalar) noexcept
			{
				this->x *= static_cast<T>(scalar);
				this->y *= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator*=(TVector<2, U> const &other) noexcept
			{
				this->x *= static_cast<T>(other.x);
				this->y *= static_cast<T>(other.y);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator/=(U scalar) noexcept
			{
				this->x /= static_cast<T>(scalar);
				this->y /= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator/=(TVector<2, U> const &other) noexcept
			{
				this->x /= static_cast<T>(other.x);
				this->y /= static_cast<T>(other.y);

				return *this;
			}

			constexpr TVector<2, T>& operator++() noexcept
			{
				++this->x;
				++this->y;

				return *this;
			}
			constexpr TVector<2, T>& operator--() noexcept
			{
				--this->x;
				--this->y;

				return *this;
			}
			constexpr TVector<2, T>& operator++(int) noexcept
			{
				TVector<2, T> result = TVector<2, T>(*this);

				++*this;

				return result;
			}
			constexpr TVector<2, T>& operator--(int) noexcept
			{
				TVector<2, T> result = TVector<2, T>(*this);

				--*this;

				return result;
			}

			template <typename U>
			constexpr TVector<2, T>& operator%=(U scalar) noexcept
			{
				this->x %= scalar;
				this->y %= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator%=(TVector<2, U> const &other) noexcept
			{
				this->x %= other.x;
				this->y %= other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator&=(U scalar) noexcept
			{
				this->x &= scalar;
				this->y &= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator&=(TVector<2, U> const &other) noexcept
			{
				this->x &= other.x;
				this->y &= other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator|=(U scalar) noexcept
			{
				this->x |= scalar;
				this->y |= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator|=(TVector<2, U> const &other) noexcept
			{
				this->x |= other.x;
				this->y |= other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator^=(U scalar) noexcept
			{
				this->x ^= scalar;
				this->y ^= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator^=(TVector<2, U> const &other) noexcept
			{
				this->x ^= other.x;
				this->y ^= other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator<<=(U scalar) noexcept
			{
				this->x <<= scalar;
				this->y <<= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator<<=(TVector<2, U> const &other) noexcept
			{
				this->x <<= other.x;
				this->y <<= other.y;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator>>=(U scalar) noexcept
			{
				this->x >>= scalar;
				this->y >>= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<2, T>& operator>>=(TVector<2, U> const &other) noexcept
			{
				this->x >>= other.x;
				this->y >>= other.y;

				return *this;
			}
		};

		template <typename T>
		constexpr TVector<2, T> operator+(TVector<2, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TVector<2, T> operator-(TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>
			(
				-object.x,
				-object.y,
				-object.z
			);
		}

		template <typename T>
		constexpr TVector<2, T> operator+(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) += object;
		}
		template <typename T>
		constexpr TVector<2, T> operator+(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) += scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator+(TVector<2, T> const &lObject, TVector<2, T> const &rObject) noexcept
		{
			return TVector<2, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TVector<2, T> operator-(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) -= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator-(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator-(TVector<2, T> const &lObject, TVector<2, T> const &rObject) noexcept
		{
			return TVector<2, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TVector<2, T> operator*(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) *= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator*(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator/(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) /= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator/(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) /= scalar;
		}

		template <typename T>
		constexpr TVector<2, T> operator%(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) %= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator%(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) %= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator&(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) &= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator&(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) &= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator|(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) |= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator|(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) |= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator^(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) ^= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator^(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) ^= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator<<(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) <<= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator<<(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) <<= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator>>(T scalar, TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>(scalar) >>= object;
		}
		template <typename T>
		constexpr TVector<2, T> operator>>(TVector<2, T> const &object, T scalar) noexcept
		{
			return TVector<2, T>(object) >>= scalar;
		}
		template <typename T>
		constexpr TVector<2, T> operator~(TVector<2, T> const &object) noexcept
		{
			return TVector<2, T>
			(
				~object.x,
				~object.y
			);
		}

		template <typename T>
		constexpr bool operator==(TVector<2, T> const &lObject, TVector<2, T> const &rObject) noexcept
		{
			return
			(
				lObject.x == rObject.x &&
				lObject.y == rObject.y
			);
		}
		template <typename T>
		constexpr bool operator!=(TVector<2, T> const &lObject, TVector<2, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
		constexpr TVector<2, bool> operator&&(TVector<2, bool> const &lObject, TVector<2, bool> const &rObject) noexcept
		{
			return TVector<2, bool>(lObject.x && rObject.x, lObject.y && rObject.y);
		}
		constexpr TVector<2, bool> operator||(TVector<2, bool> const &lObject, TVector<2, bool> const &rObject) noexcept
		{
			return TVector<2, bool>(lObject.x || rObject.x, lObject.y || rObject.y);
		}
	}
}

#endif