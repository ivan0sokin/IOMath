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

#ifndef _IO_MATH_COMPUTE_MATRIX_FUNCTIONS_HPP
#define _IO_MATH_COMPUTE_MATRIX_FUNCTIONS_HPP

#include "../types/BasicTypes.hpp"

namespace IOMath
{
    namespace Detail
    {
        template <typename T>
        constexpr Types::TMatrix<2, 2, T> ComputeTranspose(Types::TMatrix<2, 2, T> const &object) noexcept
        {
            Types::TMatrix<2, 2, T> result = Types::TMatrix<2, 2, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<3, 2, T> ComputeTranspose(Types::TMatrix<2, 3, T> const &object) noexcept
        {
            Types::TMatrix<3, 2, T> result = Types::TMatrix<3, 2, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<4, 2, T> ComputeTranspose(Types::TMatrix<2, 4, T> const &object) noexcept
        {
            Types::TMatrix<4, 2, T> result = Types::TMatrix<4, 2, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];

            result[3][0] = object[0][3];
            result[3][1] = object[1][3];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<2, 3, T> ComputeTranspose(Types::TMatrix<3, 2, T> const &object) noexcept
        {
            Types::TMatrix<2, 3, T> result = Types::TMatrix<2, 3, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<3, 3, T> ComputeTranspose(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            Types::TMatrix<3, 3, T> result = Types::TMatrix<3, 3, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];
            result[2][2] = object[2][2];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<4, 3, T> ComputeTranspose(Types::TMatrix<3, 4, T> const &object) noexcept
        {
            Types::TMatrix<4, 3, T> result = Types::TMatrix<4, 3, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];
            result[2][2] = object[2][2];

            result[3][0] = object[0][3];
            result[3][1] = object[1][3];
            result[3][2] = object[2][3];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<2, 4, T> ComputeTranspose(Types::TMatrix<4, 2, T> const &object) noexcept
        {
            Types::TMatrix<2, 4, T> result = Types::TMatrix<2, 4, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];
            result[0][3] = object[3][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];
            result[1][3] = object[3][1];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<3, 4, T> ComputeTranspose(Types::TMatrix<4, 3, T> const &object) noexcept
        {
            Types::TMatrix<3, 4, T> result = Types::TMatrix<3, 4, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];
            result[0][3] = object[3][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];
            result[1][3] = object[3][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];
            result[2][2] = object[2][2];
            result[2][3] = object[3][2];

            return result;
        }
        template <typename T>
        constexpr Types::TMatrix<4, 4, T> ComputeTranspose(Types::TMatrix<4, 4, T> const &object) noexcept
        {
            Types::TMatrix<4, 4, T> result = Types::TMatrix<4, 4, T>();

            result[0][0] = object[0][0];
            result[0][1] = object[1][0];
            result[0][2] = object[2][0];
            result[0][3] = object[3][0];

            result[1][0] = object[0][1];
            result[1][1] = object[1][1];
            result[1][2] = object[2][1];
            result[1][3] = object[3][1];

            result[2][0] = object[0][2];
            result[2][1] = object[1][2];
            result[2][2] = object[2][2];
            result[2][3] = object[3][2];

            result[3][0] = object[0][3];
            result[3][1] = object[1][3];
            result[3][2] = object[2][3];
            result[3][3] = object[3][3];

            return result;
        }
    
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<2, 2, T> const &object) noexcept
        {
            return object[0][0] * object[1][1] - object[0][1] * object[1][0];
        }
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            return
                object[0][0] * (object[1][1] * object[2][2] - object[1][2] * object[2][1]) -
                object[0][1] * (object[1][0] * object[2][2] - object[1][2] * object[2][0]) -
                object[0][2] * (object[1][1] * object[2][0] - object[1][0] * object[2][1]);   
        }
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<4, 4, T> const &object) noexcept
        {
            T f0 = object[2][2] * object[3][3] - object[2][3] * object[3][2];
			T f1 = object[1][2] * object[3][3] - object[1][3] * object[3][2];
			T f2 = object[1][2] * object[2][3] - object[1][3] * object[2][2];
			T f3 = object[0][2] * object[3][3] - object[0][3] * object[3][2];
			T f4 = object[0][2] * object[2][3] - object[0][3] * object[2][2];
			T f5 = object[0][2] * object[1][3] - object[0][3] * object[1][2];

			Types::TVector<4, T> DetCof = Types::TVector<4, T>
            (
				(object[1][1] * f0 - object[2][1] * f1 + object[3][1] * f2),
				-(object[0][1] * f0 - object[2][1] * f3 + object[3][1] * f4),
				(object[0][1] * f1 - object[1][1] * f3 + object[3][1] * f5),
				-(object[0][1] * f2 - object[1][1] * f4 + object[2][1] * f5)
            );

			return
				object[0][0] * DetCof[0] + object[1][0] * DetCof[1] +
				object[2][0] * DetCof[2] + object[3][0] * DetCof[3];
        }

        //template <typename T>
        constexpr Types::TMatrix<2, 2, float> ComputeInverse(Types::TMatrix<2, 2, float> const &object) noexcept
        {
            T oneOverDeterminant = 1.0f / ComputeDeterminant(object);

			return Types::TMatrix<2, 2, float>
            (
                  object[1][1] * oneOverDeterminant,
                -(object[0][1] * oneOverDeterminant),
                -(object[1][0] * oneOverDeterminant),
                  object[0][0] * oneOverDeterminant
            );
        }
    }
}

#endif