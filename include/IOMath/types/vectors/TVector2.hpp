#ifndef _IO_MATH_TVECTOR_2_HPP
#define _IO_MATH_TVECTOR_2_HPP

#include "../Types.hpp"

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
				this->z = static_cast<T>(0);
			}
			constexpr TVector(TVector const &other) noexcept
			{
				this->x = other.x;
				this->y = other.y;
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
		};
	}
}

#endif