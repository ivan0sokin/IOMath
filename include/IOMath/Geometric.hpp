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

#ifndef _IO_MATH_GEOMETRIC_HPP
#define _IO_MATH_GEOMETRIC_HPP

#include <cmath>
#include <cassert>

#include "types/BasicTypes.hpp"

namespace IOMath
{
	namespace Detail
	{
		template <typename T>
		constexpr T ComputeDot(Types::TVector<2, T> const &lObject, Types::TVector<2, T> const &rObject) noexcept
		{
			return (lObject.x * rObject.x + lObject.y * rObject.y);
		}
		template <typename T>
		constexpr T ComputeDot(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
		{
			return (lObject.x * rObject.x + lObject.y * rObject.y + lObject.z * rObject.z);
		}
		template <typename T>
		constexpr T ComputeDot(Types::TVector<4, T> const &lObject, Types::TVector<4, T> const &rObject) noexcept
		{
			return (lObject.x * rObject.x + lObject.y * rObject.y + lObject.z * rObject.z + lObject.w * rObject.w);
		}
	
		template <size_t S, typename T>
		constexpr T ComputeLength(Types::TVector<S, T> const &object) noexcept
		{
			return std::sqrt(ComputeDot(object, object));
		}

		template <size_t S, typename T>
		constexpr T ComputeDistance(Types::TVector<S, T> const &lObject, Types::TVector<S, T> const &rObject) noexcept
		{
			return ComputeLength(rObject - lObject);
		}

		template <size_t S, typename T>
		constexpr Types::TVector<S, T> ComputeNormalize(Types::TVector<S, T> const &object) noexcept
		{
			T objectLength = ComputeLength(object);
			assert(objectLength > static_cast<T>(0));

			return Types::TVector<S, T>(object) /= objectLength;
		}
	
		template <typename T>
		constexpr Types::TVector<3, T> ComputeCross(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
		{
			return Types::TVector<3, T>
			(
				lObject.y * rObject.z - rObject.y * lObject.z,
				lObject.z * rObject.x - rObject.z * lObject.x,
				lObject.x * rObject.y - rObject.x * lObject.y
			);
		}
	}

	template <size_t S, typename T>
	constexpr T Length(Types::TVector<S, T> const &object) noexcept
	{
		return Detail::ComputeLength(object);
	}
	template <size_t S, typename T>
	constexpr T Distance(Types::TVector<S, T> const &lObject, Types::TVector<S, T> const &rObject) noexcept
	{
		return Detail::ComputeDistance(lObject, rObject);
	}

	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Normalize(Types::TVector<S, T> const &object) noexcept
	{
		return Detail::ComputeNormalize(object);
	}

	template <size_t S, typename T>
	constexpr T Dot(Types::TVector<S, T> const &lObject, Types::TVector<S, T> const &rObject) noexcept
	{
		return Detail::ComputeDot(lObject, rObject);
	}
	template <typename T>
	constexpr Types::TVector<3, T> Cross(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
	{
		return Detail::ComputeCross(lObject, rObject);
	}
}

#endif