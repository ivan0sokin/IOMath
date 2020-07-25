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
	namespace Detail
	{
		template <typename T>
		constexpr Types::TVector<2, T> ComputeSin(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::sin(object.x),
				std::sin(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeSin(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::sin(object.x),
				std::sin(object.y),
				std::sin(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeSin(Types::TVector<4, T> const &object) noexcept
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
		constexpr Types::TVector<2, T> ComputeCos(Types::TVector<2, T> const &object) noexcept
		{
			return Types::TVector<2, T>
			(
				std::cos(object.x),
				std::cos(object.y)
			);
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeCos(Types::TVector<3, T> const &object) noexcept
		{
			return Types::TVector<3, T>
			(
				std::cos(object.x),
				std::cos(object.y),
				std::cos(object.z)
			);
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeCos(Types::TVector<4, T> const &object) noexcept
		{
			return Types::TVector<4, T>
			(
				std::cos(object.x),
				std::cos(object.y),
				std::cos(object.z),
				std::cos(object.w)
			);
		}
	}
}

#endif