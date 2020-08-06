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

#ifndef _IO_MATH_TVECTOR_3_HPP
#define _IO_MATH_TVECTOR_3_HPP

#include "../BasicTypes.hpp"

#include <cassert>

namespace IOMath
{
	namespace Types
	{
		template<typename T>
		struct TVector<3, T>
		{
			union
			{
				struct { T x, y, z; };
			};

			constexpr TVector() noexcept = default;
			constexpr TVector(TVector const &other) noexcept = default;
			constexpr explicit TVector(T scalar) noexcept : 
				x{scalar},
				y{scalar},
				z{scalar} {}
			constexpr TVector(T a, T b, T c) noexcept :
				x{a},
				y{b},
				z{c} {}

			template <typename X, typename Y, typename Z>
			constexpr TVector(X x, Y y, Z z) noexcept :
				x{static_cast<T>(x)},
				y{static_cast<T>(y)},
				z{static_cast<T>(z)} {}
			template <typename X, typename YZ>
			constexpr TVector(X x, TVector<2, YZ> const &other) noexcept :
				x{static_cast<T>(x)},
				y{static_cast<T>(other.x)},
				z{static_cast<T>(other.y)} {}
			template <typename XY, typename Z>
			constexpr TVector(TVector<2, XY> const &other, Z z) noexcept :
				x{static_cast<T>(other.x)},
				y{static_cast<T>(other.y)},
				z{static_cast<T>(z)} {}

			template <typename U>
			constexpr TVector(TVector<3, U> const &other) noexcept :
				x{static_cast<T>(other.x)},
				y{static_cast<T>(other.y)},
				z{static_cast<T>(other.z)} {}
			
			template <typename U>
			static constexpr TVector<3, T> FromVector4(TVector<4, U> const &vector) noexcept
			{
				return TVector<3, T>
				(
					vector.x,
					vector.y,
					vector.z
				);
			}
			template <typename U>
			static constexpr TVector<3, T> FromQuaternion(TQuaternion<U> const &quaternion) noexcept
			{
				return TVector<3, T>
				(
					quaternion.x,
					quaternion.y,
					quaternion.z
				);
			}

			static constexpr size_t Size() noexcept
			{
				return static_cast<size_t>(3);
			}

			constexpr T& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TVector::Size());

				switch (index)
				{
				default:
					case 0:
						return x;
					case 1:
						return y;
					case 2:
						return z;
				}
			}
			constexpr T const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TVector::Size());

				switch (index)
				{
				default:
					case 0:
						return x;
					case 1:
						return y;
					case 2:
						return z;
				}
			}

			constexpr TVector<3, T>& operator=(TVector<3, T> const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;
				this->z = other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator=(TVector<3, U> const &other) noexcept
			{
				this->x = static_cast<T>(other.x);
				this->y = static_cast<T>(other.y);
				this->z = static_cast<T>(other.z);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator+=(U scalar) noexcept
			{
				this->x += static_cast<T>(scalar);
				this->y += static_cast<T>(scalar);
				this->z += static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator+=(TVector<3, U> const &other) noexcept
			{
				this->x += static_cast<T>(other.x);
				this->y += static_cast<T>(other.y);
				this->z += static_cast<T>(other.z);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator-=(U scalar) noexcept
			{
				this->x -= static_cast<T>(scalar);
				this->y -= static_cast<T>(scalar);
				this->z -= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator-=(TVector<3, U> const &other) noexcept
			{
				this->x -= static_cast<T>(other.x);
				this->y -= static_cast<T>(other.y);
				this->z -= static_cast<T>(other.z);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator*=(U scalar) noexcept
			{
				this->x *= static_cast<T>(scalar);
				this->y *= static_cast<T>(scalar);
				this->z *= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator*=(TVector<3, U> const &other) noexcept
			{
				this->x *= static_cast<T>(other.x);
				this->y *= static_cast<T>(other.y);
				this->z *= static_cast<T>(other.z);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator/=(U scalar) noexcept
			{
				this->x /= static_cast<T>(scalar);
				this->y /= static_cast<T>(scalar);
				this->z /= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator/=(TVector<3, U> const &other) noexcept
			{
				this->x /= static_cast<T>(other.x);
				this->y /= static_cast<T>(other.y);
				this->z /= static_cast<T>(other.z);

				return *this;
			}

			constexpr TVector<3, T>& operator++() noexcept
			{
				++this->x;
				++this->y;
				++this->z;

				return *this;
			}
			constexpr TVector<3, T>& operator--() noexcept
			{
				--this->x;
				--this->y;
				--this->z;

				return *this;
			}
			constexpr TVector<3, T> operator++(int) noexcept
			{
				TVector<3, T> result = TVector<3, T>(*this);

				++(*this);

				return result;
			}
			constexpr TVector<3, T> operator--(int) noexcept
			{
				TVector<3, T> result = TVector<3, T>(*this);

				--(*this);

				return result;
			}

			template <typename U>
			constexpr TVector<3, T>& operator%=(U scalar) noexcept
			{
				this->x %= scalar;
				this->y %= scalar;
				this->z %= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator%=(TVector<3, U> const &other) noexcept
			{
				this->x %= other.x;
				this->y %= other.y;
				this->z %= other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator&=(U scalar) noexcept
			{
				this->x &= scalar;
				this->y &= scalar;
				this->z &= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator&=(TVector<3, U> const &other) noexcept
			{
				this->x &= other.x;
				this->y &= other.y;
				this->z &= other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator|=(U scalar) noexcept
			{
				this->x |= scalar;
				this->y |= scalar;
				this->z |= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator|=(TVector<3, U> const &other) noexcept
			{
				this->x |= other.x;
				this->y |= other.y;
				this->z |= other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator^=(U scalar) noexcept
			{
				this->x ^= scalar;
				this->y ^= scalar;
				this->z ^= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator^=(TVector<3, U> const &other) noexcept
			{
				this->x ^= other.x;
				this->y ^= other.y;
				this->z ^= other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator<<=(U scalar) noexcept
			{
				this->x <<= scalar;
				this->y <<= scalar;
				this->z <<= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator<<=(TVector<3, U> const &other) noexcept
			{
				this->x <<= other.x;
				this->y <<= other.y;
				this->z <<= other.z;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator>>=(U scalar) noexcept
			{
				this->x >>= scalar;
				this->y >>= scalar;
				this->z >>= scalar;

				return *this;
			}
			template <typename U>
			constexpr TVector<3, T>& operator>>=(TVector<3, U> const &other) noexcept
			{
				this->x >>= other.x;
				this->y >>= other.y;
				this->z >>= other.z;

				return *this;
			}
		};

		template <typename T>
		constexpr TVector<3, T> operator+(TVector<3, T> const &object) noexcept
		{
			return object;
		}
		template <typename T>
		constexpr TVector<3, T> operator-(TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				-object.x,
				-object.y,
				-object.z
			);
		}
	
		template <typename T>
		constexpr TVector<3, T> operator+(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar + object.x,
				scalar + object.y,
				scalar + object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator+(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x + scalar,
				object.y + scalar,
				object.z + scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator+(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x + rObject.x,
				lObject.y + rObject.y,
				lObject.z + rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator-(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar - object.x,
				scalar - object.y,
				scalar - object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator-(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x - scalar,
				object.y - scalar,
				object.z - scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator-(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x - rObject.x,
				lObject.y - rObject.y,
				lObject.z - rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator*(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar * object.x,
				scalar * object.y,
				scalar * object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator*(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x * scalar,
				object.y * scalar,
				object.z * scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator*(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x * rObject.x,
				lObject.y * rObject.y,
				lObject.z * rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator/(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar / object.x,
				scalar / object.y,
				scalar / object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator/(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x / scalar,
				object.y / scalar,
				object.z / scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator/(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x / rObject.x,
				lObject.y / rObject.y,
				lObject.z / rObject.z
			);
		}

		template <typename T>
		constexpr TVector<3, T> operator%(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar % object.x,
				scalar % object.y,
				scalar % object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator%(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x % scalar,
				object.y % scalar,
				object.z % scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator%(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x % rObject.x,
				lObject.y % rObject.y,
				lObject.z % rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator&(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar & object.x,
				scalar & object.y,
				scalar & object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator&(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x & scalar,
				object.y & scalar,
				object.z & scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator&(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x & rObject.x,
				lObject.y & rObject.y,
				lObject.z & rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator|(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar | object.x,
				scalar | object.y,
				scalar | object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator|(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x & scalar,
				object.y & scalar,
				object.z & scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator|(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x | rObject.x,
				lObject.y | rObject.y,
				lObject.z | rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator^(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar ^ object.x,
				scalar ^ object.y,
				scalar ^ object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator^(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x ^ scalar,
				object.y ^ scalar,
				object.z ^ scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator^(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x ^ rObject.x,
				lObject.y ^ rObject.y,
				lObject.z ^ rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator<<(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar << object.x,
				scalar << object.y,
				scalar << object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator<<(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x << scalar,
				object.y << scalar,
				object.z << scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator<<(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x << rObject.x,
				lObject.y << rObject.y,
				lObject.z << rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator>>(T scalar, TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				scalar >> object.x,
				scalar >> object.y,
				scalar >> object.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator>>(TVector<3, T> const &object, T scalar) noexcept
		{
			return TVector<3, T>
			(
				object.x >> scalar,
				object.y >> scalar,
				object.z >> scalar
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator>>(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return TVector<3, T>
			(
				lObject.x >> rObject.x,
				lObject.y >> rObject.y,
				lObject.z >> rObject.z
			);
		}
		template <typename T>
		constexpr TVector<3, T> operator~(TVector<3, T> const &object) noexcept
		{
			return TVector<3, T>
			(
				~object.x,
				~object.y,
				~object.z
			);
		}

		template <typename T>
		constexpr bool operator==(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return
			(
				lObject.x == rObject.x &&
				lObject.y == rObject.y &&
				lObject.z == rObject.z
			);
		}
		template <typename T>
		constexpr bool operator!=(TVector<3, T> const &lObject, TVector<3, T> const &rObject) noexcept
		{
			return
			(
				lObject.x != rObject.x ||
				lObject.y != rObject.y ||
				lObject.z != rObject.z
			);
		}
		constexpr TVector<3, bool> operator&&(TVector<3, bool> const &lObject, TVector<3, bool> const &rObject) noexcept
		{
			return TVector<3, bool>
			(
				lObject.x && rObject.x,
				lObject.y && rObject.y,
				lObject.z && rObject.z
			);
		}
		constexpr TVector<3, bool> operator||(TVector<3, bool> const &lObject, TVector<3, bool> const &rObject) noexcept
		{
			return TVector<3, bool>
			(
				lObject.x || rObject.x,
				lObject.y || rObject.y,
				lObject.z || rObject.z
			);
		}
	}
}

#endif