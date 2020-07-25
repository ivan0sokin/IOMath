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

#ifndef _IO_MATH_TVECTOR_4_HPP
#define _IO_MATH_TVECTOR_4_HPP

#include "../BasicTypes.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template <typename T>
		struct TVector<4, T>
		{
			union
			{
				struct { T x, y, z, w; };
				struct { T r, g, b, a; };
			};

			constexpr TVector() noexcept
			{
				this->x = static_cast<T>(0);
				this->y = static_cast<T>(0);
				this->z = static_cast<T>(0);
				this->w = static_cast<T>(0);
			}
			constexpr TVector(TVector const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;
				this->z = other.z;
				this->w = other.w;
			}
			constexpr TVector(T scalar) noexcept
			{
				this->x = scalar;
				this->y = scalar;
				this->z = scalar;
				this->w = scalar;
			}
			constexpr TVector(T a, T b, T c, T d) noexcept
			{
				this->x = a;
				this->y = b;
				this->z = c;
				this->w = d;
			}

			template <typename A, typename B, typename C, typename D>
			constexpr TVector(A a, B b, C c, D d) noexcept
			{
				this->x = static_cast<T>(a);
				this->y = static_cast<T>(b);
				this->z = static_cast<T>(c);
				this->w = static_cast<T>(d);
			}
			template <typename A, typename B, typename C>
			constexpr TVector(A a, B b, TVector<2, C> const &other) noexcept
			{
				this->x = static_cast<T>(a);
				this->y = static_cast<T>(b);
				this->z = static_cast<T>(other.x);
				this->w = static_cast<T>(other.y);
			}
			template <typename A, typename B, typename C>
			constexpr TVector(A a, TVector<2, B> const &other, C c) noexcept
			{
				this->x = static_cast<T>(a);
				this->y = static_cast<T>(other.x);
				this->z = static_cast<T>(other.y);
				this->w = static_cast<T>(c);
			}
			template <typename A, typename B, typename C>
			constexpr TVector(TVector<2, A> const &other, B b, C c) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
				this->z = static_cast<T>(b);
				this->w = static_cast<T>(c);
			}
			template <typename A, typename B>
			constexpr TVector(A a, TVector<3, B> const &other) noexcept
			{
				this->x = static_cast<T>(a);
				this->y = static_cast<T>(other.x);
				this->z = static_cast<T>(other.y);
				this->w = static_cast<T>(other.z);
			}
			template <typename A, typename B>
			constexpr TVector(TVector<3, A> const &other, B b) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
				this->z = static_cast<T>(other.z);
				this->w = static_cast<T>(b);
			}

			template <typename U>
			constexpr TVector(TVector<4, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
				this->z = static_cast<T>(other.z);
				this->w = static_cast<T>(other.w);
			}

			static constexpr size_t Size() noexcept
			{
				return static_cast<size_t>(4);
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
				case 2:
					return z;
				case 3:
					return w;
				}
			}
			constexpr T const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TVector::Size());

				switch (index)
				{
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				case 3:
					return w;
				}
			}
		
			constexpr TVector<4, T>& operator=(TVector const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;
				this->z = other.z;
				this->w = other.w;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator=(TVector<4, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
				this->z = static_cast<T>(other.z);
				this->w = static_cast<T>(other.w);

				return *this;
			}

			template <typename U>
			constexpr TVector<4, T>& operator+=(U scalar) noexcept
			{
				this->x += static_cast<T>(scalar);
				this->y += static_cast<T>(scalar);
				this->z += static_cast<T>(scalar);
				this->w += static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator+=(TVector<4, U> const &other) noexcept
			{
				this->x += static_cast<T>(other.x);
				this->y += static_cast<T>(other.y);
				this->z += static_cast<T>(other.z);
				this->w += static_cast<T>(other.w);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator-=(U scalar) noexcept
			{
				this->x -= static_cast<T>(scalar);
				this->y -= static_cast<T>(scalar);
				this->z -= static_cast<T>(scalar);
				this->w -= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator-=(TVector<4, U> const &other) noexcept
			{
				this->x -= static_cast<T>(other.x);
				this->y -= static_cast<T>(other.y);
				this->z -= static_cast<T>(other.z);
				this->w -= static_cast<T>(other.w);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator*=(U scalar) noexcept
			{
				this->x *= static_cast<T>(scalar);
				this->y *= static_cast<T>(scalar);
				this->z *= static_cast<T>(scalar);
				this->w *= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator*=(TVector<4, U> const &other) noexcept
			{
				this->x *= static_cast<T>(other.x);
				this->y *= static_cast<T>(other.y);
				this->z *= static_cast<T>(other.z);
				this->w *= static_cast<T>(other.w);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator/=(U scalar) noexcept
			{
				this->x /= static_cast<T>(scalar);
				this->y /= static_cast<T>(scalar);
				this->z /= static_cast<T>(scalar);
				this->w /= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator/=(TVector<4, U> const &other) noexcept
			{
				this->x /= static_cast<T>(other.x);
				this->y /= static_cast<T>(other.y);
				this->z /= static_cast<T>(other.z);
				this->z /= static_cast<T>(other.w);

				return *this;
			}

			constexpr TVector<4, T>& operator++() noexcept
			{
				++this->x;
				++this->y;
				++this->z;
				++this->w;

				return *this;
			}
			constexpr TVector<4, T>& operator--() noexcept
			{
				--this->x;
				--this->y;
				--this->z;
				--this->z;

				return *this;
			}
			constexpr TVector<4, T>& operator++(int) noexcept
			{
				TVector<4, T> result = TVector<4, T>(*this);

				++*this;

				return result;
			}
			constexpr TVector<4, T>& operator--(int) noexcept
			{
				TVector<4, T> result = TVector<4, T>(*this);

				--*this;

				return result;
			}

			template <typename U>
			constexpr TVector<4, T>& operator%=(U scalar) noexcept
			{
				this->x %= scalar;
				this->y %= scalar;
				this->z %= scalar;
				this->w %= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator%=(TVector<4, U> const &other) noexcept
			{
				this->x %= other.x;
				this->y %= other.y;
				this->z %= other.z;
				this->w %= other.w;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator&=(U scalar) noexcept
			{
				this->x &= scalar;
				this->y &= scalar;
				this->z &= scalar;
				this->w &= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator&=(TVector<4, U> const &other) noexcept
			{
				this->x &= other.x;
				this->y &= other.y;
				this->z &= other.z;
				this->w &= other.w;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator|=(U scalar) noexcept
			{
				this->x |= scalar;
				this->y |= scalar;
				this->z |= scalar;
				this->w |= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator|=(TVector<4, U> const &other) noexcept
			{
				this->x |= other.x;
				this->y |= other.y;
				this->z |= other.z;
				this->w |= other.w;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator^=(U scalar) noexcept
			{
				this->x ^= scalar;
				this->y ^= scalar;
				this->z ^= scalar;
				this->w ^= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator^=(TVector<4, U> const &other) noexcept
			{
				this->x ^= other.x;
				this->y ^= other.y;
				this->z ^= other.z;
				this->w ^= other.w;
				
				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator<<=(U scalar) noexcept
			{
				this->x <<= scalar;
				this->y <<= scalar;
				this->z <<= scalar;
				this->w <<= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator<<=(TVector<4, U> const &other) noexcept
			{
				this->x <<= other.x;
				this->y <<= other.y;
				this->z <<= other.z;
				this->w <<= other.w;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator>>=(U scalar) noexcept
			{
				this->x >>= scalar;
				this->y >>= scalar;
				this->z >>= scalar;
				this->w >>= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<4, T>& operator>>=(TVector<4, U> const &other) noexcept
			{
				this->x >>= other.x;
				this->y >>= other.y;
				this->z >>= other.z;
				this->w >>= other.w;

				return *this;
			}
		};

		template <typename T>
		constexpr TVector<4, T> operator+(TVector<4, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TVector<4, T> operator-(TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>
			(
				-object.x,
				-object.y,
				-object.z,
				-object.w
			);
		}

		template <typename T>
		constexpr TVector<4, T> operator+(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) += object;
		}
		template <typename T>
		constexpr TVector<4, T> operator+(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) += scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator+(TVector<4, T> const &lObject, TVector<4, T> const &rObject) noexcept
		{
			return TVector<4, T>(lObject) += rObject;
		}
		template <typename T>
		constexpr TVector<4, T> operator-(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) -= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator-(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) -= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator-(TVector<4, T> const &lObject, TVector<4, T> const &rObject) noexcept
		{
			return TVector<4, T>(lObject) -= rObject;
		}
		template <typename T>
		constexpr TVector<4, T> operator*(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) *= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator*(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) *= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator/(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) /= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator/(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) /= scalar;
		}

		template <typename T>
		constexpr TVector<4, T> operator%(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) %= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator%(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) %= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator&(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) &= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator&(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) &= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator|(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) |= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator|(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) |= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator^(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) ^= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator^(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) ^= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator<<(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) <<= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator<<(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) <<= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator>>(T scalar, TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>(scalar) >>= object;
		}
		template <typename T>
		constexpr TVector<4, T> operator>>(TVector<4, T> const &object, T scalar) noexcept
		{
			return TVector<4, T>(object) >>= scalar;
		}
		template <typename T>
		constexpr TVector<4, T> operator~(TVector<4, T> const &object) noexcept
		{
			return TVector<4, T>
			(
				~object.x,
				~object.y,
				~object.z
			);
		}

		template <typename T>
		constexpr bool operator==(TVector<4, T> const &lObject, TVector<4, T> const &rObject) noexcept
		{
			return
			(
				lObject.x == rObject.x &&
				lObject.y == rObject.y &&
				lObject.z == rObject.z &&
				lObject.w == rObject.w
			);
		}
		template <typename T>
		constexpr bool operator!=(TVector<4, T> const &lObject, TVector<4, T> const &rObject) noexcept
		{
			return !(lObject == rObject);
		}
		constexpr TVector<4, bool> operator&&(TVector<4, bool> const &lObject, TVector<4, bool> const &rObject) noexcept
		{
			return TVector<4, bool>(lObject.x && rObject.x, lObject.y && rObject.y, lObject.z && rObject.z, lObject.w && rObject.w);
		}
		constexpr TVector<4, bool> operator||(TVector<4, bool> const &lObject, TVector<4, bool> const &rObject) noexcept
		{
			return TVector<4, bool>(lObject.x || rObject.x, lObject.y || rObject.y, lObject.z || rObject.z, lObject.w || rObject.w);
		}

	}
}

#endif