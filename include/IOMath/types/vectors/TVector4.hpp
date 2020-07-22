#ifndef _IO_MATH_TVECTOR_4_HPP
#define _IO_MATH_TVECTOR_4_HPP

#include "../Types.hpp"

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
		};
	}
}

#endif