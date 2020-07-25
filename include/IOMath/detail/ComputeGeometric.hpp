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

#ifndef _IO_MATH_COMPUTE_GEOMETRIC_HPP
#define _IO_MATH_COMPUTE_GEOMETRIC_HPP

#include "../types/BasicTypes.hpp"

#include <cmath>
#include <cassert>

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
			if (objectLength < static_cast<T>(0))
				return Types::TVector<S, T>(0);

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

		template <size_t S, typename T>
		constexpr Types::TVector<S, T> ComputeReflect(Types::TVector<S, T> const &object, Types::TVector<S, T> const &normal) noexcept
		{
			return object - static_cast<T>(2) * ComputeDot(normal, object) * normal;
		}
		template <size_t S, typename T>
		constexpr Types::TVector<S, T> ComputeRefract(Types::TVector<S, T> const &object, Types::TVector<S, T> const &normal, T eta) noexcept
		{
			T dotOfNormalAndObject = ComputeDot(normal, object);
			T k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dotOfNormalAndObject * dotOfNormalAndObject);
			
			if (k < static_cast<T>(0))
				return Types::TVector<S, T>(0);

			return eta * object - (eta * dotOfNormalAndObject + std::sqrt(k)) * normal;
		}
	}
}

#endif