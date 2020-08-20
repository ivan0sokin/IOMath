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

#ifndef _IO_MATH_QUATERNION_FUNCTIONS_HPP
#define _IO_MATH_QUATERNION_FUNCTIONS_HPP

#include "detail/ComputeBasicQuaternionFunctions.hpp"
#include "detail/ComputeQuaternionEquations.hpp"
#include "detail/ComputeQuaternionTransform.hpp"

namespace IOMath
{
    template <typename T>
    constexpr Types::TQuaternion<T> Conjugate(Types::TQuaternion<T> const &object) noexcept
    {
        return detail::ComputeConjugate(object);
    }

    template <typename T>
    constexpr Types::TQuaternion<T> Inverse(Types::TQuaternion<T> const &object) noexcept
    {
        return detail::ComputeInverse(object);
    }

	template <typename T>
	constexpr Types::TVector<3, T> EulerAngles(Types::TQuaternion<T> const &quaternion) noexcept
	{
		return detail::ComputeEulerAngles(quaternion);
	}

	template <typename T>
	constexpr T Roll(Types::TQuaternion<T> const &quaternion) noexcept
	{
		return detail::ComputeRoll(quaternion);
	}

	template <typename T>
	constexpr T Pitch(Types::TQuaternion<T> const &quaternion) noexcept
	{
		return detail::ComputePitch(quaternion);
	}

	template <typename T>
	constexpr T Yaw(Types::TQuaternion<T> const &quaternion) noexcept
	{
		return detail::ComputeYaw(quaternion);
	}

	template <typename T>
	constexpr Types::TQuaternion<T> Rotate(Types::TQuaternion<T> const &quaternion, Types::TVector<3, T> const &axis, T angle) noexcept
	{
		return detail::ComputeRotate(quaternion, axis, angle);
	}
}

#endif