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

#ifndef _IO_MATH_COMPUTE_TRIGONOMETRIC_HPP
#define _IO_MATH_COMPUTE_TRIGONOMETRIC_HPP

#include "../types/BasicTypes.hpp"

#include <cmath>

namespace IOMath
{
	namespace detail
	{
		template <typename T>
		constexpr T ComputeRadians(T degrees) noexcept
		{
			return degrees * static_cast<T>(0.0174532925199432957692369);
		}
		template <typename T>
		constexpr T ComputeDegrees(T radians) noexcept
		{
			return radians * static_cast<T>(57.2957795130823208767981548);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeRadians(Types::TVector<2, T> degrees) noexcept
		{
			return Types::TVector<2, T>
			(
				degrees.x * static_cast<T>(0.0174532925199432957692369),
				degrees.y * static_cast<T>(0.0174532925199432957692369)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeRadians(Types::TVector<3, T> degrees) noexcept
		{
			return Types::TVector<2, T>
			(
				degrees.x * static_cast<T>(0.0174532925199432957692369),
				degrees.y * static_cast<T>(0.0174532925199432957692369),
				degrees.z * static_cast<T>(0.0174532925199432957692369)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeRadians(Types::TVector<4, T> degrees) noexcept
		{
			return Types::TVector<2, T>
			(
				degrees.x * static_cast<T>(0.0174532925199432957692369),
				degrees.y * static_cast<T>(0.0174532925199432957692369),
				degrees.z * static_cast<T>(0.0174532925199432957692369),
				degrees.w * static_cast<T>(0.0174532925199432957692369)
			);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeDegrees(Types::TVector<2, T> radians) noexcept
		{
			return Types::TVector<2, T>
			(
				radians.x * static_cast<T>(57.2957795130823208767981548),
				radians.y * static_cast<T>(57.2957795130823208767981548)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeDegrees(Types::TVector<3, T> radians) noexcept
		{
			return Types::TVector<3, T>
			(
				radians.x * static_cast<T>(57.2957795130823208767981548),
				radians.y * static_cast<T>(57.2957795130823208767981548),
				radians.z * static_cast<T>(57.2957795130823208767981548)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeDegrees(Types::TVector<4, T> radians) noexcept
		{
			return Types::TVector<3, T>
			(
				radians.x * static_cast<T>(57.2957795130823208767981548),
				radians.y * static_cast<T>(57.2957795130823208767981548),
				radians.z * static_cast<T>(57.2957795130823208767981548),
				radians.w * static_cast<T>(57.2957795130823208767981548)
			);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeSine(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::sin(object.x),
				std::sin(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeSine(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::sin(object.x),
				std::sin(object.y),
				std::sin(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeSine(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::sin(object.x),
				std::sin(object.y),
				std::sin(object.z),
				std::sin(object.w)
			);
		}
		
		template <typename T>
		constexpr Types::TVector<2, T> ComputeCosine(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::cos(object.x),
				std::cos(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeCosine(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::cos(object.x),
				std::cos(object.y),
				std::cos(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeCosine(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::cos(object.x),
				std::cos(object.y),
				std::cos(object.z),
				std::cos(object.w)
			);
		}
	
		template <typename T>
		constexpr Types::TVector<2, T> ComputeTangent(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::tan(object.x),
				std::tan(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeTangent(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::tan(object.x),
				std::tan(object.y),
				std::tan(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeTangent(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::tan(object.x),
				std::tan(object.y),
				std::tan(object.z),
				std::tan(object.w)
			);
		}
	
		template <typename T>
		constexpr Types::TVector<2, T> ComputeArcsine(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::asin(object.x),
				std::asin(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeArcsine(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::asin(object.x),
				std::asin(object.y),
				std::asin(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeArcsine(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::asin(object.x),
				std::asin(object.y),
				std::asin(object.z),
				std::asin(object.w)
			);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeArccosine(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::acos(object.x),
				std::acos(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeArccosine(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::acos(object.x),
				std::acos(object.y),
				std::acos(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeArccosine(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::acos(object.x),
				std::acos(object.y),
				std::acos(object.z),
				std::acos(object.w)
			);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeArctangent(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::atan(object.x),
				std::atan(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeArctangent(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::atan(object.x),
				std::atan(object.y),
				std::atan(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeArctangent(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::atan(object.x),
				std::atan(object.y),
				std::atan(object.z),
				std::atan(object.w)
			);
		}
	}
}

#endif