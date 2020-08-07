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

#ifndef _IO_MATH_COMPUTE_MATRIX_TRANSFORM_HPP
#define _IO_MATH_COMPUTE_MATRIX_TRANSFORM_HPP

#include "../types/matrices/TMatrix4x4.hpp"
#include "../types/vectors/TVector3.hpp"
#include "ComputeVectorGeometric.hpp"

#include <cmath>

namespace IOMath
{
    namespace detail
    {
        template <typename T>
        constexpr Types::TMatrix<4, 4, T> ComputeTranslationMatrix(Types::TVector<3, T> const &translate) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			return Types::TMatrix<4, 4, T>
			(
				one, zero, zero, translate.x,
				zero, one, zero, translate.y,
				zero, zero, one, translate.z,
				zero, zero, zero, one
			);
		}
		
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeRotationMatrix(Types::TVector<3, T> const &axis, T angle) noexcept
		{
			T const sinAngle = std::sin(angle);
			T const cosAngle = std::cos(angle);

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			Types::TVector<3, T> normalizedAxis = Types::TVector<3, T>(ComputeNormalize(axis));
			Types::TVector<3, T> modifier = Types::TVector<3, T>(normalizedAxis * (one - cosAngle));

			return Types::TMatrix<4, 4, T>
			(
				cosAngle + modifier.x * normalizedAxis.x, modifier.y * normalizedAxis.x - sinAngle * normalizedAxis.z, modifier.z * normalizedAxis.x + sinAngle * normalizedAxis.y, zero,
				modifier.x * normalizedAxis.y + sinAngle * normalizedAxis.z, cosAngle + modifier.y * normalizedAxis.y,  modifier.z * normalizedAxis.y - sinAngle * normalizedAxis.x, zero,
				modifier.x * normalizedAxis.z - sinAngle * normalizedAxis.y, modifier.y * normalizedAxis.z + sinAngle * normalizedAxis.x, cosAngle + modifier.z * normalizedAxis.z, zero,
				zero, zero, zero, one
			);
		}
		
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeScaleMatrix(Types::TVector<3, T> const &scale) noexcept
		{
			T const zero = static_cast<T>(0);

			return Types::TMatrix<4, 4, T>
			(
				scale.x, zero, zero, zero,
				zero, scale.y, zero, zero,
				zero, zero, scale.z, zero,
				zero, zero, zero, static_cast<T>(1)
			);
		}
    
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeLookAtRightHandedMatrix(Types::TVector<3, T> const &eye, Types::TVector<3, T> const &target, Types::TVector<3, T> const &_up) noexcept
		{
			Types::TVector<3, T> const forward = Types::TVector<3, T>(detail::ComputeNormalize(target - eye));
			Types::TVector<3, T> const side = Types::TVector<3, T>(detail::ComputeNormalize(detail::ComputeCross(forward, _up)));
			Types::TVector<3, T> const up = Types::TVector<3, T>(detail::ComputeCross(side, forward));

			T const zero = static_cast<T>(0);

			return Types::TMatrix<4, 4, T>
			(
				side.x,		side.y, 	side.z,   -detail::ComputeDot(side, eye),
				up.x, 		up.y, 		up.z, 	  -detail::ComputeDot(up, eye),
			   -forward.x, -forward.y, -forward.z, detail::ComputeDot(forward, eye),
				zero, 		zero, 		zero, 	   static_cast<T>(1)
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeLookAtLeftHandedMatrix(Types::TVector<3, T> const &eye, Types::TVector<3, T> const &target, Types::TVector<3, T> const &_up) noexcept
		{
			Types::TVector<3, T> const forward = Types::TVector<3, T>(detail::ComputeNormalize(target - eye));
			Types::TVector<3, T> const side = Types::TVector<3, T>(detail::ComputeNormalize(detail::ComputeCross(_up, forward)));
			Types::TVector<3, T> const up = Types::TVector<3, T>(detail::ComputeCross(forward, side));

			T const zero = static_cast<T>(0);

			return Types::TMatrix<4, 4, T>
			(
				side.x,    side.y,    side.z,    -detail::ComputeDot(side, eye),
				up.x,	   up.y,      up.z, 	 -detail::ComputeDot(up, eye),
				forward.x, forward.y, forward.z, -detail::ComputeDot(forward, eye),
				zero, 	   zero, 	  zero, 	  static_cast<T>(1)
			);
		}
	
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeSimpleOrthoMatrix(T left, T top, T right, T bottom) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			return Types::TMatrix<4, 4, T>
			(
				two / (right - left), zero, zero, -(right + left) / (right - left),
				zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
				zero, zero, -one, zero,
				zero, zero, zero, one
			);
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoRightHandedZeroToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			Types::TMatrix<4, 4, T> result(1);

			result[0][0] = static_cast<T>(2) / (right - left);
			result[1][1] = static_cast<T>(2) / (top - bottom);
			result[2][2] = - static_cast<T>(1) / (zFar - zNear);

			result[0][3] = - (right + left) / (right - left);
			result[3][3] = - (top + bottom) / (top - bottom);
			result[2][3] = - zNear / (zFar - zNear);

			return result;
			/*T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			return Types::TMatrix<4, 4, T>
			(
				two / (right - left), zero, zero, -(right + left) / (right - left),
				zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
				zero, zero, -one / (zFar - zNear), -zNear / (zFar - zNear),
				zero, zero, zero, one
			);*/
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoRightHandedNegativeToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			return Types::TMatrix<4, 4, T>
			(
				two / (right - left), zero, zero, -(right + left) / (right - left),
				zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
				zero, zero, -two / (zFar - zNear), -(zFar + zNear) / (zFar - zNear),
				zero, zero, zero, one
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoLeftHandedZeroToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			return Types::TMatrix<4, 4, T>
			(
				two / (right - left), zero, zero, -(right + left) / (right - left),
				zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
				zero, zero, one / (zFar - zNear), -zNear / (zFar - zNear),
				zero, zero, zero, one
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoLeftHandedNegativeToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			return Types::TMatrix<4, 4, T>
			(
				two / (right - left), zero, zero, -(right + left) / (right - left),
				zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
				zero, zero, two / (zFar - zNear), -(zFar + zNear) / (zFar - zNear),
				zero, zero, zero, one
			);
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveRightHandedZeroToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			return Types::TMatrix<4, 4, T>
			(
				one / (aspect * tanHalfFovy), zero, zero, zero,
				zero, one / tanHalfFovy, zero, zero,
				zero, zero, zFar / (zNear - zFar), -(zFar * zNear) / (zFar - zNear),
				zero, zero, -one, zero
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveRightHandedNegativeToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			return Types::TMatrix<4, 4, T>
			(
				one / (aspect * tanHalfFovy), zero, zero, zero,
				zero, one / (tanHalfFovy), zero, zero,
				zero, zero, -(zFar + zNear) / (zFar - zNear), -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear),
				zero, zero, -one, zero
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveLeftHandedZeroToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			return Types::TMatrix<4, 4, T>
			(
				one / (aspect * tanHalfFovy), zero, zero, zero,
				zero, one / (tanHalfFovy), zero, zero,
				zero, zero, zFar / (zFar - zNear), -(zFar * zNear) / (zFar - zNear),
				zero, zero, one, zero
			);
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveLeftHandedNegativeToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			return Types::TMatrix<4, 4, T>
			(
				one / (aspect * tanHalfFovy), zero, zero,zero,
				zero, one / (tanHalfFovy), zero, zero,
				zero, zero, (zFar + zNear) / (zFar - zNear), -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear),
				zero, zero, one, zero
			);
		}
	}
}

#endif