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

#ifndef _IO_MATH_MATRIX_FUNCTIONS_HPP
#define _IO_MATH_MATRIX_FUNCTIONS_HPP

#ifndef IO_MATH_LEFT_HANDED_COORDINATE_SYSTEM
	#define IO_MATH_RIGHT_HANDED_COORDINATE_SYSTEM
#endif

#ifndef IO_MATH_CLIP_SPACE_FROM_NEGATIVE_TO_ONE
	#define IO_MATH_CLIP_SPACE_FROM_ZERO_TO_ONE
#endif

#include "detail/ComputeBasicMatrixFunctions.hpp"
#include "detail/ComputeMatrixTransform.hpp"

namespace IOMath
{
    template <size_t R, size_t C, typename T>
    constexpr Types::TMatrix<C, R, T> Transpose(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeTranspose(object);
    }

    template <size_t R, size_t C, typename T>
    constexpr T Determinant(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeDeterminant(object);
	}

    template <size_t R, size_t C, typename T>
    constexpr Types::TMatrix<R, C, T> Inverse(Types::TMatrix<R, C, T> const &object) noexcept
    {
        return detail::ComputeInverse(object);
    }

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> TranslationMatrix(Types::TVector<3, T> const &translate) noexcept
	{
		return detail::ComputeTranslationMatrix(translate);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> RotationMatrix(Types::TVector<3, T> const &axis, T angle) noexcept
	{
		return detail::ComputeRotationMatrix(axis, angle);
	}
	
	template <typename T>
	constexpr Types::TMatrix<4, 4, T> ScaleMatrix(Types::TVector<3, T> const &scale) noexcept
	{
		return detail::ComputeScaleMatrix(scale);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> Translate(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &translate) noexcept
	{
		return detail::ComputeTranslate(object, translate);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> Rotate(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &axis, T angle) noexcept
	{
		return detail::ComputeRotate(object, axis, angle);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> Scale(Types::TMatrix<4, 4, T> const &object, Types::TVector<3, T> const &scale) noexcept
	{
		return detail::ComputeScale(object, scale);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> LookAtMatrix(Types::TVector<3, T> const &eye, Types::TVector<3, T> const &target, Types::TVector<3, T> const &up) noexcept
	{
		#ifdef IO_MATH_LEFT_HANDED_COORDINATE_SYSTEM
			return detail::ComputeLookAtLeftHandedMatrix(eye, target, up);
		#elif defined(IO_MATH_RIGHT_HANDED_COORDINATE_SYSTEM)
			return detail::ComputeLookAtRightHandedMatrix(eye, target, up);
		#endif
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> OrthoMatrix(T left, T top, T right, T bottom) noexcept
	{
		return detail::ComputeSimpleOrthoMatrix(left, top, right, bottom);
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> OrthoMatrix(T left, T top, T right, T bottom, T zNear, T zFar) noexcept
	{
		#ifdef IO_MATH_LEFT_HANDED_COORDINATE_SYSTEM
			#ifdef IO_MATH_CLIP_SPACE_FROM_NEGATIVE_TO_ONE
				return detail::ComputeOrthoLeftHandedFromNegativeToOneMatrix(left, top, right, bottom, zNear, zFar);
			#elif defined(IO_MATH_CLIP_SPACE_FROM_ZERO_TO_ONE)
				return detail::ComputeOrthoLeftHandedFromZeroToOneMatrix(left, top, right, bottom, zNear, zFar);
			#endif
		#elif defined(IO_MATH_RIGHT_HANDED_COORDINATE_SYSTEM)
			#ifdef IO_MATH_CLIP_SPACE_FROM_NEGATIVE_TO_ONE
				return detail::ComputeOrthoRightHandedFromNegativeToOneMatrix(left, top, right, bottom, zNear, zFar);
			#elif defined(IO_MATH_CLIP_SPACE_FROM_ZERO_TO_ONE)
				return detail::ComputeOrthoRightHandedFromZeroToOneMatrix(left, top, right, bottom, zNear, zFar);
			#endif
		#endif
	}

	template <typename T>
	constexpr Types::TMatrix<4, 4, T> PerspectiveMatrix(T fovy, T aspect, T zNear, T zFar) noexcept
	{
		#ifdef IO_MATH_LEFT_HANDED_COORDINATE_SYSTEM
			#ifdef IO_MATH_CLIP_SPACE_FROM_NEGATIVE_TO_ONE
				return detail::ComputePerspectiveLeftHandedFromNegativeToOneMatrix(fovy, aspect, zNear, zFar);
			#elif defined(IO_MATH_CLIP_SPACE_FROM_ZERO_TO_ONE)
				return detail::ComputePerspectiveLeftHandedFromZeroToOneMatrix(fovy, aspect, zNear, zFar);
			#endif
		#elif defined(IO_MATH_RIGHT_HANDED_COORDINATE_SYSTEM)
			#ifdef IO_MATH_CLIP_SPACE_FROM_NEGATIVE_TO_ONE
				return detail::ComputePerspectiveRightHandedFromNegativeToOneMatrix(fovy, aspect, zNear, zFar);
			#elif defined(IO_MATH_CLIP_SPACE_FROM_ZERO_TO_ONE)
				return detail::ComputePerspectiveRightHandedFromZeroToOneMatrix(fovy, aspect, zNear, zFar);
			#endif
		#endif
	}
}

#endif