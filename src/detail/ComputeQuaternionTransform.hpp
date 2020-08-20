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

#ifndef _IO_MATH_COMPUTE_QUATERNION_TRANSFORM_HPP
#define _IO_MATH_COMPUTE_QUATERNION_TRANSFORM_HPP

#include "../types/BasicTypes.hpp"

#include <cmath>

namespace IOMath
{
    namespace detail
    {
        template <typename T>
        constexpr Types::TQuaternion<T> ComputeRotate(Types::TQuaternion<T> const &quaternion, Types::TVector<3, T> const &_axis, T _angle) noexcept
        {
            Types::TVector<3, T> axis = _axis;

            T const half = static_cast<T>(0.5);
            T const one = static_cast<T>(1);

            T length = std::sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
            if(std::abs(length - one) > static_cast<T>(0.001))
            {
                T oneOverLength = one / length;
                axis.x *= oneOverLength;
                axis.y *= oneOverLength;
                axis.z *= oneOverLength;
            }

            T const angle = _angle;
            T const halfAngle = angle * half;
            T const sinHalfAngle = std::sin(halfAngle);

            return quaternion * Types::TQuaternion<T>
            (
                std::cos(halfAngle),
                sinHalfAngle * axis.x,
                sinHalfAngle * axis.y,
                sinHalfAngle * axis.z
            );
        }
    }
}

#endif