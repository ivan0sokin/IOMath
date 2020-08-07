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

#ifndef _IO_MATH_COMPUTE_QUATERNION_GEOMETRIC_HPP
#define _IO_MATH_COMPUTE_QUATERNION_GEOMETRIC_HPP

#include "../types/BasicTypes.hpp"

#include <cmath>

namespace IOMath
{
    namespace detail
    {
        template <typename T>
		constexpr T ComputeDot(Types::TQuaternion<T> const &lObject, Types::TQuaternion<T> const &rObject) noexcept
		{
			return
			(
				lObject.w * rObject.w +
				lObject.x * rObject.x +
				lObject.y * rObject.y +
				lObject.z * rObject.z
			);
		}

        template <typename T>
		constexpr T ComputeLength(Types::TQuaternion<T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;
			T const objectW = object.w;

			return std::sqrt(objectW * objectW * objectX * objectX + objectY * objectY + objectZ * objectZ);
		}
    
        template <typename T>
		constexpr Types::TQuaternion<T> ComputeNormalize(Types::TQuaternion<T> const &object) noexcept
		{
			T const objectW = object.w;
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;

			return object * (static_cast<T>(1) / std::sqrt(objectW * objectW + objectX * objectX + objectY * objectY + objectZ * objectZ));
		
		}
    
        template <typename T>
		constexpr Types::TQuaternion<T> ComputeCross(Types::TQuaternion<T> const &lObject, Types::TQuaternion<T> const &rObject) noexcept
		{
			T const lObjectW = lObject.w;
			T const lObjectX = lObject.x;
			T const lObjectY = lObject.y;
			T const lObjectZ = lObject.z;

			T const rObjectW = rObject.w;
			T const rObjectX = rObject.x;
			T const rObjectY = rObject.y;
			T const rObjectZ = rObject.z;

			return Types::TQuaternion<T>
			(
				lObjectW * rObjectW - lObjectX * rObjectX - lObjectY * rObjectY - lObjectZ * rObjectZ,
				lObjectW * rObjectX + lObjectX * rObjectW + lObjectY * rObjectZ - lObjectZ * rObjectY,
				lObjectW * rObjectY + lObjectY * rObjectW + lObjectZ * rObjectX - lObjectX * rObjectZ,
				lObjectW * rObjectZ + lObjectZ * rObjectW + lObjectX * rObjectY - lObjectY * rObjectX
			);
		}
    }
}

#endif