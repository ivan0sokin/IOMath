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

#ifndef _IO_MATH_COMPUTE_QUATERNION_EQUATIONS
#define _IO_MATH_COMPUTE_QUATERNION_EQUATIONS

#include "../types/BasicTypes.hpp"

#include <cmath>
#include <limits>

namespace IOMath
{
    
    namespace detail
    {
        template <typename T>
        constexpr T ComputeRoll(Types::TQuaternion<T> const &quaternion) noexcept
        {
            T const quatW = quaternion.w;
            T const quatX = quaternion.x;
            T const quatY = quaternion.y;
            T const quatZ = quaternion.z;

            return static_cast<T>(std::atan2
            (
                static_cast<T>(2) * (quatX * quatY + quatW * quatZ),
                quatW * quatW + quatX * quatX - quatY * quatY - quatZ * quatZ
            ));
        }

        template <typename T>
        constexpr T ComputePitch(Types::TQuaternion<T> const &quaternion) noexcept
        {
            T const quatW = quaternion.w;
            T const quatX = quaternion.x;
            T const quatY = quaternion.y;
            T const quatZ = quaternion.z;

            T const x = quatW * quatW - quatX * quatX - quatY * quatY + quatZ * quatZ;
            T const y = static_cast<T>(2) * (quatY * quatZ + quatW * quatX);

            T const epsilon = std::numeric_limits<T>::epsilon();

            if(x == epsilon && y == epsilon)
                return static_cast<T>(static_cast<T>(2) * std::atan2(quatX, quatW));

            return static_cast<T>(std::atan2(y, x));
        }

        template <typename T>
        constexpr T ComputeYaw(Types::TQuaternion<T> const &quaternion) noexcept
        {
            return std::asin
            (
                std::min(std::max(static_cast<T>(-2) * (quaternion.x * quaternion.z - quaternion.w * quaternion.y), static_cast<T>(-1)), static_cast<T>(1))
            );
        }

        template <typename T>
        constexpr Types::TVector<3, T> ComputeEulerAngles(Types::TQuaternion<T> const &quaternion) noexcept
        {
            return Types::TVector<3, T>
            (
                ComputePitch(quaternion),
                ComputeYaw(quaternion),
                ComputeRoll(quaternion)
            );
        }
    }
}

#endif