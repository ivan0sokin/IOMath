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

#ifndef _IO_MATH_TCOLOR_HPP
#define _IO_MATH_TCOLOR_HPP

#include "../BasicTypes.hpp"

namespace IOMath
{
    namespace Types
    {
        template <typename T>
        struct TColor<2, T>
        {
            union 
            {
                struct { T r, g; };
                struct { T b, w; };
            }

            constexpr TColor() noexcept = default;
			constexpr TColor(TColor const &other) noexcept = default;
			constexpr explicit TColor(T scalar) noexcept :
				r{scalar},
				g{scalar} {}
			constexpr TColor(T r, T g) noexcept :
				r{r},
				g{g} {}
            constexpr TColor(TVector<2, T> const& vector) noexcept :
                r{vector.x},
                g{vector.y} {}

			template<typename R, typename G>
			constexpr TColor(R r, G g) noexcept :
				r{static_cast<T>(r)},
				g{static_cast<T>(g)} {}

			template <typename U>
			constexpr TColor(TColor<2, U> const &other) noexcept :
				r{static_cast<T>(other.r)},
				g{static_cast<T>(other.g)} {}

			template <typename U>
			static constexpr TColor<2, T> FromColor3(TColor<3, U> const &color) noexcept
			{
				return TColor<2, T>
				(
					vector.r,
					vector.g
				);
			}
			template <typename U>
			static constexpr TColor<2, T> FromColor4(TColor<4, U> const &color) noexcept
			{
				return TColor<2, T>
				(
					vector.r,
					vector.g
				);
			}

            template <typename U>
            static constexpr TColor<2, T> FromVector3(TVector<3, U> const &color) noexcept
			{
				return TColor<2, T>
				(
					vector.x,
					vector.y
				);
			}
			template <typename U>
			static constexpr TColor<2, T> FromVector4(TVector<4, U> const &color) noexcept
			{
				return TColor<2, T>
				(
					vector.x,
					vector.y
				);
			}


			static constexpr size_t Size() noexcept
			{
				return static_cast<size_t>(2);
			}

			constexpr T& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TColor::Size());

				switch (index)
				{
				default:
					case 0:
						return r;
					case 1:
						return g;
				}
			}
			constexpr T const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TColor::Size());

				switch (index)
				{
				default:
					case 0:
						return r;
					case 1:
						return g;
				}
			}
			
			constexpr TColor<2, T>& operator=(TColor<2, T> const &other) noexcept
			{
				this->r = other.r;
				this->g = other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator=(TColor<2, U> const &other) noexcept
			{
				this->r = static_cast<T>(other.r);
				this->g = static_cast<T>(other.g);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator+=(U scalar) noexcept
			{
				this->r += static_cast<T>(scalar);
				this->g += static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator+=(TColor<2, U> const &other) noexcept
			{
				this->r += static_cast<T>(other.r);
				this->g += static_cast<T>(other.g);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator-=(U scalar) noexcept
			{
				this->r -= static_cast<T>(scalar);
				this->g -= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator-=(TColor<2, U> const &other) noexcept
			{
				this->r -= static_cast<T>(other.r);
				this->g -= static_cast<T>(other.g);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator*=(U scalar) noexcept
			{
				this->r *= static_cast<T>(scalar);
				this->g *= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator*=(TColor<2, U> const &other) noexcept
			{
				this->r *= static_cast<T>(other.r);
				this->g *= static_cast<T>(other.g);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator/=(U scalar) noexcept
			{
				this->r /= static_cast<T>(scalar);
				this->g /= static_cast<T>(scalar);

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator/=(TColor<2, U> const &other) noexcept
			{
				this->r /= static_cast<T>(other.r);
				this->g /= static_cast<T>(other.g);

				return *this;
			}

			constexpr TColor<2, T>& operator++() noexcept
			{
				++this->r;
				++this->g;

				return *this;
			}
			constexpr TColor<2, T>& operator--() noexcept
			{
				--this->r;
				--this->g;

				return *this;
			}
			constexpr TColor<2, T> operator++(int) noexcept
			{
				TColor<2, T> result = TColor<2, T>(*this);

				++(*this);

				return result;
			}
			constexpr TColor<2, T> operator--(int) noexcept
			{
				TColor<2, T> result = TColor<2, T>(*this);

				--(*this);

				return result;
			}

			template <typename U>
			constexpr TColor<2, T>& operator%=(U scalar) noexcept
			{
				this->r %= scalar;
				this->g %= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator%=(TColor<2, U> const &other) noexcept
			{
				this->r %= other.r;
				this->g %= other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator&=(U scalar) noexcept
			{
				this->r &= scalar;
				this->g &= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator&=(TColor<2, U> const &other) noexcept
			{
				this->r &= other.r;
				this->g &= other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator|=(U scalar) noexcept
			{
				this->r |= scalar;
				this->g |= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator|=(TColor<2, U> const &other) noexcept
			{
				this->r |= other.r;
				this->g |= other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator^=(U scalar) noexcept
			{
				this->r ^= scalar;
				this->g ^= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator^=(TColor<2, U> const &other) noexcept
			{
				this->r ^= other.r;
				this->g ^= other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator<<=(U scalar) noexcept
			{
				this->r <<= scalar;
				this->g <<= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator<<=(TColor<2, U> const &other) noexcept
			{
				this->r <<= other.r;
				this->g <<= other.g;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator>>=(U scalar) noexcept
			{
				this->r >>= scalar;
				this->g >>= scalar;

				return *this;
			}
			template <typename U>
			constexpr TColor<2, T>& operator>>=(TColor<2, U> const &other) noexcept
			{
				this->r >>= other.r;
				this->g >>= other.g;

				return *this;
			}
        };
    }
}

#endif