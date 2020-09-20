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

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					one, 		 zero,		  zero, 	   zero,
					zero, 		 one, 		  zero, 	   zero,
					zero, 		 zero, 		  one,  	   zero,
					translate.x, translate.y, translate.z, one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					one, zero, zero, translate.x,
					zero, one, zero, translate.y,
					zero, zero, one, translate.z,
					zero, zero, zero, one
				);
			#endif
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

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					cosAngle + modifier.x * normalizedAxis.x, modifier.x * normalizedAxis.y + sinAngle * normalizedAxis.z, modifier.x * normalizedAxis.z - sinAngle * normalizedAxis.y, zero,
					modifier.y * normalizedAxis.x - sinAngle * normalizedAxis.z, cosAngle + modifier.y * normalizedAxis.y, modifier.y * normalizedAxis.z + sinAngle * normalizedAxis.x, zero,
					modifier.z * normalizedAxis.x + sinAngle * normalizedAxis.y, modifier.z * normalizedAxis.y - sinAngle * normalizedAxis.x, cosAngle + modifier.z * normalizedAxis.z, zero,
					zero, zero, zero, one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					cosAngle + modifier.x * normalizedAxis.x, modifier.y * normalizedAxis.x - sinAngle * normalizedAxis.z, modifier.z * normalizedAxis.x + sinAngle * normalizedAxis.y, zero,
					modifier.x * normalizedAxis.y + sinAngle * normalizedAxis.z, cosAngle + modifier.y * normalizedAxis.y,  modifier.z * normalizedAxis.y - sinAngle * normalizedAxis.x, zero,
					modifier.x * normalizedAxis.z - sinAngle * normalizedAxis.y, modifier.y * normalizedAxis.z + sinAngle * normalizedAxis.x, cosAngle + modifier.z * normalizedAxis.z, zero,
					zero, zero, zero, one
				);
			#endif
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
		constexpr Types::TMatrix<4, 4, T> ComputeTranslate(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &_translate) noexcept
		{
			Types::TMatrix<4, 4, T> result = object;
			
			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				result[3] = object[0] * _translate[0] + object[1] * _translate[1] + object[2] * _translate[2] + object[3];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				Types::TVector<4, T> translate = Types::TVector<4, T>(_translate, static_cast<T>(1));
				result[0][3] = detail::ComputeDot(result[0], translate);
				result[1][3] = detail::ComputeDot(result[1], translate);
				result[2][3] = detail::ComputeDot(result[2], translate);
			#endif

			return result;
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeRotate(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &axis, T angle) noexcept
		{
			T const sinAngle = std::sin(angle);
			T const cosAngle = std::cos(angle);

			Types::TVector<3, T> normalizedAxis = Types::TVector<3, T>(ComputeNormalize(axis));
			Types::TVector<3, T> modifier = Types::TVector<3, T>(normalizedAxis * (static_cast<T>(1) - cosAngle));

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				Types::TMatrix<3, 3, T> rotateMatrix = Types::TMatrix<3, 3, T>
				(
					cosAngle + modifier.x * normalizedAxis.x, modifier.y * normalizedAxis.x - sinAngle * normalizedAxis.z, modifier.z * normalizedAxis.x + sinAngle * normalizedAxis.y,
					modifier.x * normalizedAxis.y + sinAngle * normalizedAxis.z, cosAngle + modifier.y * normalizedAxis.y,  modifier.z * normalizedAxis.y - sinAngle * normalizedAxis.x,
					modifier.x * normalizedAxis.z - sinAngle * normalizedAxis.y, modifier.y * normalizedAxis.z + sinAngle * normalizedAxis.x, cosAngle + modifier.z * normalizedAxis.z
				);

				return Types::TMatrix<4, 4, T>
				(
					object[0] * rotateMatrix[0][0] + object[1] * rotateMatrix[1][0] + object[2] * rotateMatrix[2][0],
					object[0] * rotateMatrix[0][1] + object[1] * rotateMatrix[1][1] + object[2] * rotateMatrix[2][1],
					object[0] * rotateMatrix[0][2] + object[1] * rotateMatrix[1][2] + object[2] * rotateMatrix[2][2],
					object[3]
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				Types::TMatrix<3, 3, T> transposedRotateMatrix = Types::TMatrix<3, 3, T>
				(
					cosAngle + modifier.x * normalizedAxis.x, modifier.x * normalizedAxis.y + sinAngle * normalizedAxis.z, modifier.x * normalizedAxis.z - sinAngle * normalizedAxis.y,
					modifier.y * normalizedAxis.x - sinAngle * normalizedAxis.z, cosAngle + modifier.y * normalizedAxis.y, modifier.y * normalizedAxis.z + sinAngle * normalizedAxis.x,
					modifier.z * normalizedAxis.x + sinAngle * normalizedAxis.y, modifier.z * normalizedAxis.y - sinAngle * normalizedAxis.x, cosAngle + modifier.z * normalizedAxis.z
				);

				Types::TMatrix<4, 3, T> object4x3 = Types::TMatrix<4, 3, T>::FromMatrix4x4(object);

				return Types::TMatrix<4, 4, T>
				(
					detail::ComputeDot(object4x3[0], transposedRotateMatrix[0]), detail::ComputeDot(object4x3[0], transposedRotateMatrix[1]), detail::ComputeDot(object4x3[0], transposedRotateMatrix[2]), object[0][3],
					detail::ComputeDot(object4x3[1], transposedRotateMatrix[0]), detail::ComputeDot(object4x3[1], transposedRotateMatrix[1]), detail::ComputeDot(object4x3[1], transposedRotateMatrix[2]), object[1][3],
					detail::ComputeDot(object4x3[2], transposedRotateMatrix[0]), detail::ComputeDot(object4x3[2], transposedRotateMatrix[1]), detail::ComputeDot(object4x3[2], transposedRotateMatrix[2]), object[2][3],
					detail::ComputeDot(object4x3[3], transposedRotateMatrix[0]), detail::ComputeDot(object4x3[3], transposedRotateMatrix[1]), detail::ComputeDot(object4x3[3], transposedRotateMatrix[2]), object[3][3]
				);
			#endif
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeScale(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &_scale) noexcept
		{
			Types::TMatrix<4, 4, T> result = object;

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				result[0] = object[0] * _scale[0];
				result[1] = object[1] * _scale[1];
				result[2] = object[2] * _scale[2];
				result[3] = object[3];
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				Types::TVector<4, T> scale = Types::TVector<4, T>(_scale, 1);
				result[0] *= scale;
				result[1] *= scale;
				result[2] *= scale;
				result[3] *= scale;
			#endif

			return result;
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeLookAtRightHandedMatrix(Types::TVector<3, T> const &eye, Types::TVector<3, T> const &target, Types::TVector<3, T> const &_up) noexcept
		{
			Types::TVector<3, T> const forward = Types::TVector<3, T>(detail::ComputeNormalize(target - eye));
			Types::TVector<3, T> const side = Types::TVector<3, T>(detail::ComputeNormalize(detail::ComputeCross(forward, _up)));
			Types::TVector<3, T> const up = Types::TVector<3, T>(detail::ComputeCross(side, forward));

			T const zero = static_cast<T>(0);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					side.x, up.x, -forward.x, zero,
					side.y, up.y, -forward.y, zero,
					side.z, up.z, -forward.z, zero,
					-detail::ComputeDot(side, eye), -detail::ComputeDot(up, eye), detail::ComputeDot(forward, eye), static_cast<T>(1)
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					side.x,		side.y, 	side.z,   -detail::ComputeDot(side, eye),
					up.x, 		up.y, 		up.z, 	  -detail::ComputeDot(up, eye),
				   -forward.x, -forward.y, -forward.z, detail::ComputeDot(forward, eye),
					zero, 		zero, 		zero, 	   static_cast<T>(1)
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeLookAtLeftHandedMatrix(Types::TVector<3, T> const &eye, Types::TVector<3, T> const &target, Types::TVector<3, T> const &_up) noexcept
		{
			Types::TVector<3, T> const forward = Types::TVector<3, T>(detail::ComputeNormalize(target - eye));
			Types::TVector<3, T> const side = Types::TVector<3, T>(detail::ComputeNormalize(detail::ComputeCross(_up, forward)));
			Types::TVector<3, T> const up = Types::TVector<3, T>(detail::ComputeCross(forward, side));

			T const zero = static_cast<T>(0);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					side.x, up.x, forward.x, zero,
					side.y, up.y, forward.y, zero,
					side.z, up.z, forward.z, zero,
					-detail::ComputeDot(side, eye), -detail::ComputeDot(up, eye), -detail::ComputeDot(forward, eye), static_cast<T>(1)
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					side.x,    side.y,    side.z,    -detail::ComputeDot(side, eye),
					up.x,	   up.y,      up.z, 	 -detail::ComputeDot(up, eye),
					forward.x, forward.y, forward.z, -detail::ComputeDot(forward, eye),
					zero, 	   zero, 	  zero, 	  static_cast<T>(1)
				);
			#endif
		}
	
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeSimpleOrthoMatrix(T left, T top, T right, T bottom) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, zero,
					zero, two / (top - bottom), zero, zero,
					zero, zero, -one, zero,
					-(right + left) / (right - left), -(top + bottom) / (top - bottom), zero, one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, -(right + left) / (right - left),
					zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
					zero, zero, -one, zero,
					zero, zero, zero, one
				);
			#endif
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoRightHandedFromZeroToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, zero,
					zero, two / (top - bottom), zero, zero,
					zero, zero, -one / (zFar - zNear), zero,
					-(right + left) / (right - left), -(top + bottom) / (top - bottom), -zNear / (zFar - zNear), one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, -(right + left) / (right - left),
					zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
					zero, zero, -one / (zFar - zNear), -zNear / (zFar - zNear),
					zero, zero, zero, one
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoRightHandedFromNegativeToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, zero,
					zero, two / (top - bottom), zero, zero,
					zero, zero, -two / (zFar - zNear), zero,
					-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zFar + zNear) / (zFar - zNear), one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, -(right + left) / (right - left),
					zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
					zero, zero, -two / (zFar - zNear), -(zFar + zNear) / (zFar - zNear),
					zero, zero, zero, one
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoLeftHandedFromZeroToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, zero,
					zero, two / (top - bottom), zero, zero,
					zero, zero, one / (zFar - zNear), zero,
					-(right + left) / (right - left), -(top + bottom) / (top - bottom), -zNear / (zFar - zNear), one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, -(right + left) / (right - left),
					zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
					zero, zero, one / (zFar - zNear), -zNear / (zFar - zNear),
					zero, zero, zero, one
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputeOrthoLeftHandedFromNegativeToOneMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
		{
			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);
			T const two = static_cast<T>(2);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, zero,
					zero, two / (top - bottom), zero, zero,
					zero, zero, two / (zFar - zNear), zero,
					-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zFar + zNear) / (zFar - zNear), one
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					two / (right - left), zero, zero, -(right + left) / (right - left),
					zero, two / (top - bottom), zero, -(top + bottom) / (top - bottom),
					zero, zero, two / (zFar - zNear), -(zFar + zNear) / (zFar - zNear),
					zero, zero, zero, one
				);
			#endif
		}

		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveRightHandedFromZeroToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / tanHalfFovy, zero, zero,
					zero, zero, zFar / (zNear - zFar), -one,
					zero, zero, -(zFar * zNear) / (zFar - zNear), zero
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / tanHalfFovy, zero, zero,
					zero, zero, zFar / (zNear - zFar), -(zFar * zNear) / (zFar - zNear),
					zero, zero, -one, zero
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveRightHandedFromNegativeToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, -(zFar + zNear) / (zFar - zNear), -one,
					zero, zero, -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear), zero

				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, -(zFar + zNear) / (zFar - zNear), -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear),
					zero, zero, -one, zero
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveLeftHandedFromZeroToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, zFar / (zFar - zNear), one,
					zero, zero, -(zFar * zNear) / (zFar - zNear), zero
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, zFar / (zFar - zNear), -(zFar * zNear) / (zFar - zNear),
					zero, zero, one, zero
				);
			#endif
		}
		template <typename T>
		constexpr Types::TMatrix<4, 4, T> ComputePerspectiveLeftHandedFromNegativeToOneMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
		{
			T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

			T const zero = static_cast<T>(0);
			T const one = static_cast<T>(1);

			#ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, (zFar + zNear) / (zFar - zNear), one,
					zero, zero, -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear), zero
				);
			#elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
				return Types::TMatrix<4, 4, T>
				(
					one / (aspect * tanHalfFovy), zero, zero, zero,
					zero, one / (tanHalfFovy), zero, zero,
					zero, zero, (zFar + zNear) / (zFar - zNear), -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear),
					zero, zero, one, zero
				);
			#endif
		}
	}
}

#endif