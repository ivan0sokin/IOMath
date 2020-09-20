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

#ifndef _IO_MATH_TRIGONOMETRIC_HPP
#define _IO_MATH_TRIGONOMETRIC_HPP

#include "detail/ComputeTrigonometric.hpp"

namespace IOMath
{
	template <typename T>
	constexpr T Radians(T degrees) noexcept
	{
		return detail::ComputeRadians(degrees);
	}

	template <typename T>
	constexpr T Degrees(T radians) noexcept
	{
		return detail::ComputeDegrees(radians);
	}

	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Radians(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeRadians(object);
	}

	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Degrees(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeDegrees(object);
	}

	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Sine(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeSine(object);
	}

	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Cosine(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeCosine(object);
	}
	
	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Tangent(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeTangent(object);
	}
	
	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Arsine(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeArcsine(object);
	}
	
	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Arccosine(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeArccosine(object);
	}
	
	template <size_t S, typename T>
	constexpr Types::TVector<S, T> Arctangent(Types::TVector<S, T> const &object) noexcept
	{
		return detail::ComputeArctangent(object);
	}	
}

#endif