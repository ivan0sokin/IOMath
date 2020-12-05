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

#ifndef _IO_MATH_COMPUTE_BASIC_MATRIX_FUNCTIONS_HPP
#define _IO_MATH_COMPUTE_BASIC_MATRIX_FUNCTIONS_HPP

#include "../types/BasicTypes.hpp"

namespace IOMath
{
    namespace detail
    {
        template <typename T>
        constexpr Types::TMatrix<2, 2, T> ComputeTranspose(Types::TMatrix<2, 2, T> const &object) noexcept
        {
            return Types::TMatrix<2, 2, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1],
                    object[1][0], object[1][1]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0],
                    object[0][1], object[1][1]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<3, 2, T> ComputeTranspose(Types::TMatrix<2, 3, T> const &object) noexcept
        {
            return Types::TMatrix<3, 2, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1],
                    object[1][0], object[1][1],
                    object[2][0], object[2][1]
			    #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0],
                    object[0][1], object[1][1],
                    object[0][2], object[1][2]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<4, 2, T> ComputeTranspose(Types::TMatrix<2, 4, T> const &object) noexcept
        {
            return Types::TMatrix<4, 2, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1],
                    object[1][0], object[1][1],
                    object[2][0], object[2][1],
                    object[3][0], object[3][1]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0],
                    object[0][1], object[1][1],
                    object[0][2], object[1][2],
                    object[0][3], object[1][3]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<2, 3, T> ComputeTranspose(Types::TMatrix<3, 2, T> const &object) noexcept
        {
            return Types::TMatrix<2, 3, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2],
                    object[1][0], object[1][1], object[1][2]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0],
                    object[0][1], object[1][1], object[2][1]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<3, 3, T> ComputeTranspose(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            return Types::TMatrix<3, 3, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2],
                    object[1][0], object[1][1], object[1][2],
                    object[2][0], object[2][1], object[2][2]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0],
                    object[0][1], object[1][1], object[2][1],
                    object[0][2], object[1][2], object[2][2]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<4, 3, T> ComputeTranspose(Types::TMatrix<3, 4, T> const &object) noexcept
        {
            return Types::TMatrix<4, 3, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2],
                    object[1][0], object[1][1], object[1][2],
                    object[2][0], object[2][1], object[2][2],
                    object[3][0], object[3][1], object[3][2]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0],
                    object[0][1], object[1][1], object[2][1],
                    object[0][2], object[1][2], object[2][2],
                    object[0][3], object[1][3], object[2][3]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<2, 4, T> ComputeTranspose(Types::TMatrix<4, 2, T> const &object) noexcept
        {
            return Types::TMatrix<2, 4, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2], object[0][3],
                    object[1][0], object[1][1], object[1][2], object[1][3]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0], object[3][0],
                    object[0][1], object[1][1], object[2][1], object[3][1]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<3, 4, T> ComputeTranspose(Types::TMatrix<4, 3, T> const &object) noexcept
        {
            return Types::TMatrix<3, 4, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2], object[0][3],
                    object[1][0], object[1][1], object[1][2], object[1][3],
                    object[2][0], object[2][1], object[2][2], object[2][3]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0], object[3][0],
                    object[0][1], object[1][1], object[2][1], object[3][1],
                    object[0][2], object[1][2], object[2][2], object[3][2]
                #endif
            );
        }
        template <typename T>
        constexpr Types::TMatrix<4, 4, T> ComputeTranspose(Types::TMatrix<4, 4, T> const &object) noexcept
        {
            return Types::TMatrix<4, 4, T>
            (
                #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                    object[0][0], object[0][1], object[0][2], object[0][3],
                    object[1][0], object[1][1], object[1][2], object[1][3],
                    object[2][0], object[2][1], object[2][2], object[2][3],
                    object[3][0], object[3][1], object[3][2], object[3][3]
                #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                    object[0][0], object[1][0], object[2][0], object[3][0],
                    object[0][1], object[1][1], object[2][1], object[3][1],
                    object[0][2], object[1][2], object[2][2], object[3][2],
                    object[0][3], object[1][3], object[2][3], object[3][3]
                #endif
            );
        }
    
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<2, 2, T> const &object) noexcept
        {
            return object[0][0] * object[1][1] - object[0][1] * object[1][0];
        }
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                T const objectA = object[0][0];
                T const objectB = object[1][0];
                T const objectC = object[2][0];
                T const objectD = object[0][1];
                T const objectE = object[1][1];
                T const objectF = object[2][1];
                T const objectG = object[0][2];
                T const objectH = object[1][2];
                T const objectI = object[2][2];
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                T const objectA = object[0][0];
                T const objectB = object[0][1];
                T const objectC = object[0][2];
                T const objectD = object[1][0];
                T const objectE = object[1][1];
                T const objectF = object[1][2];
                T const objectG = object[2][0];
                T const objectH = object[2][1];
                T const objectI = object[2][2];
            #endif

            return
                objectA * (objectE * objectI - objectF * objectH) -
                objectB * (objectD * objectI - objectF * objectG) -
                objectC * (objectE * objectG - objectD * objectH);   
        }
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<4, 4, T> const &object) noexcept
        {
            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                T const objectA = object[0][0];
                T const objectB = object[1][0];
                T const objectC = object[2][0];
                T const objectD = object[3][0];
                T const objectE = object[0][1];
                T const objectF = object[1][1];
                T const objectG = object[2][1];
                T const objectH = object[3][1];
                T const objectI = object[0][2];
                T const objectJ = object[1][2];
                T const objectK = object[2][2];
                T const objectL = object[3][2];
                T const objectM = object[0][3];
                T const objectN = object[1][3];
                T const objectO = object[2][3];
                T const objectP = object[3][3];
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                T const objectA = object[0][0];
                T const objectB = object[0][1];
                T const objectC = object[0][2];
                T const objectD = object[0][3];
                T const objectE = object[1][0];
                T const objectF = object[1][1];
                T const objectG = object[1][2];
                T const objectH = object[1][3];
                T const objectI = object[2][0];
                T const objectJ = object[2][1];
                T const objectK = object[2][2];
                T const objectL = object[2][3];
                T const objectM = object[3][0];
                T const objectN = object[3][1];
                T const objectO = object[3][2];
                T const objectP = object[3][3];
            #endif

            T const factorA = objectK * objectP - objectL * objectO;
			T const factorB = objectG * objectP - objectH * objectO;
			T const factorC = objectG * objectL - objectH * objectK;
			T const factorD = objectC * objectP - objectD * objectO;
			T const factorE = objectC * objectL - objectD * objectK;
			T const factorF = objectC * objectH - objectD * objectG;

            T const determinantCofactorA = objectF * factorA - objectJ * factorB + objectN * factorC;
            T const determinantCofactorB = -(objectB * factorA - objectJ * factorD + objectN * factorE);
            T const determinantCofactorC = objectB * factorB - objectF * factorD + objectN * factorF;
            T const determinantCofactorD = -(objectB * factorC - objectF * factorE + objectJ * factorF);

			return
				objectA * determinantCofactorA + objectE * determinantCofactorB +
				objectI * determinantCofactorC + objectM * determinantCofactorD;
        }

        template <typename T>
        constexpr Types::TMatrix<2, 2, T> ComputeInverse(Types::TMatrix<2, 2, T> const &object) noexcept
        {
            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                T const objectA = object[0][0];
                T const objectB = object[1][0];
                T const objectC = object[0][1];
                T const objectD = object[1][1];
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                T const objectA = object[0][0];
                T const objectB = object[0][1];
                T const objectC = object[1][0];
                T const objectD = object[1][1];
            #endif

            T const oneOverDeterminant = static_cast<T>(1) / (objectA * objectD - objectB * objectC);
            
			return Types::TMatrix<2, 2, T>
            (
                  objectD * oneOverDeterminant,
                -(objectB * oneOverDeterminant),
                -(objectC * oneOverDeterminant),
                  objectA * oneOverDeterminant
            );
        }
        template <typename T>
        constexpr Types::TMatrix<3, 3, T> ComputeInverse(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                T const objectA = object[0][0];
                T const objectB = object[1][0];
                T const objectC = object[2][0];
                T const objectD = object[0][1];
                T const objectE = object[1][1];
                T const objectF = object[2][1];
                T const objectG = object[0][2];
                T const objectH = object[1][2];
                T const objectI = object[2][2];
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                T const objectA = object[0][0];
                T const objectB = object[0][1];
                T const objectC = object[0][2];
                T const objectD = object[1][0];
                T const objectE = object[1][1];
                T const objectF = object[1][2];
                T const objectG = object[2][0];
                T const objectH = object[2][1];
                T const objectI = object[2][2];
            #endif

            T const oneOverDeterminant = static_cast<T>(1) / (objectA * (objectE * objectI - objectF * objectH) -
                                                        objectB * (objectD * objectI - objectF * objectG) -
                                                        objectC * (objectE * objectG - objectD * objectH));

            return Types::TMatrix<3, 3, T>
            (
                (objectE * objectI - objectF * objectH) * oneOverDeterminant,
			   -(objectB * objectI - objectC * objectH) * oneOverDeterminant,
			    (objectB * objectF - objectC * objectE) * oneOverDeterminant,
			   -(objectD * objectI - objectF * objectG) * oneOverDeterminant,
			    (objectA * objectI - objectC * objectG) * oneOverDeterminant,
			   -(objectA * objectF - objectC * objectD) * oneOverDeterminant,
		        (objectD * objectH - objectE * objectG) * oneOverDeterminant,
			   -(objectA * objectH - objectB * objectG) * oneOverDeterminant,
			    (objectA * objectE - objectB * objectD) * oneOverDeterminant
            );
        }
        template <typename T>
        constexpr Types::TMatrix<4, 4, T> ComputeInverse(Types::TMatrix<4, 4, T> const &object) noexcept
        {
            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                T const objectA = object[0][0];
                T const objectB = object[1][0];
                T const objectC = object[2][0];
                T const objectD = object[3][0];
                T const objectE = object[0][1];
                T const objectF = object[1][1];
                T const objectG = object[2][1];
                T const objectH = object[3][1];
                T const objectI = object[0][2];
                T const objectJ = object[1][2];
                T const objectK = object[2][2];
                T const objectL = object[3][2];
                T const objectM = object[0][3];
                T const objectN = object[1][3];
                T const objectO = object[2][3];
                T const objectP = object[3][3];
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                T const objectA = object[0][0];
                T const objectB = object[0][1];
                T const objectC = object[0][2];
                T const objectD = object[0][3];
                T const objectE = object[1][0];
                T const objectF = object[1][1];
                T const objectG = object[1][2];
                T const objectH = object[1][3];
                T const objectI = object[2][0];
                T const objectJ = object[2][1];
                T const objectK = object[2][2];
                T const objectL = object[2][3];
                T const objectM = object[3][0];
                T const objectN = object[3][1];
                T const objectO = object[3][2];
                T const objectP = object[3][3];
            #endif

            T const coefA = objectK * objectP - objectL * objectO;
			T const coefB = objectJ * objectP - objectL * objectN;
			T const coefC = objectJ * objectO - objectK * objectN;

			T const coefD = objectG * objectP - objectH * objectO;
			T const coefE = objectF * objectP - objectH * objectN;
			T const coefF = objectF * objectO - objectG * objectN;

			T const coefG = objectG * objectL - objectH * objectK;
			T const coefH = objectF * objectL - objectH * objectJ;
			T const coefI = objectF * objectK - objectG * objectJ;

			T const coefJ = objectC * objectP - objectD * objectO;
			T const coefK = objectB * objectP - objectD * objectN;
			T const coefL = objectB * objectO - objectC * objectN;

			T const coefM = objectC * objectL - objectD * objectK;
			T const coefN = objectB * objectL - objectD * objectJ;
			T const coefO = objectB * objectK - objectC * objectJ;

			T const coefP = objectC * objectH - objectD * objectG;
			T const coefQ = objectB * objectH - objectD * objectF;
			T const coefR = objectB * objectG - objectC * objectF;

			Types::TVector<4, T> const factorA = Types::TVector<4, T>(coefA, coefA, coefB, coefC);
			Types::TVector<4, T> const factorB = Types::TVector<4, T>(coefD, coefD, coefE, coefF);
			Types::TVector<4, T> const factorC = Types::TVector<4, T>(coefG, coefG, coefH, coefI);
			Types::TVector<4, T> const factorD = Types::TVector<4, T>(coefJ, coefJ, coefK, coefL);
			Types::TVector<4, T> const factorE = Types::TVector<4, T>(coefM, coefM, coefN, coefO);
			Types::TVector<4, T> const factorF = Types::TVector<4, T>(coefP, coefP, coefQ, coefR);

			Types::TVector<4, T> const vectorBAAA = Types::TVector<4, T>(objectB, objectA, objectA, objectA);
			Types::TVector<4, T> const vectorFEEE = Types::TVector<4, T>(objectF, objectE, objectE, objectE);
			Types::TVector<4, T> const vectorJIII = Types::TVector<4, T>(objectJ, objectI, objectI, objectI);
			Types::TVector<4, T> const vectorNMMM = Types::TVector<4, T>(objectN, objectM, objectM, objectM);

			Types::TVector<4, T> const inverseA = Types::TVector<4, T>(vectorFEEE * factorA - vectorJIII * factorB + vectorNMMM * factorC);
			Types::TVector<4, T> const inverseB = Types::TVector<4, T>(vectorBAAA * factorA - vectorJIII * factorD + vectorNMMM * factorE);
			Types::TVector<4, T> const inverseC = Types::TVector<4, T>(vectorBAAA * factorB - vectorFEEE * factorD + vectorNMMM * factorF);
			Types::TVector<4, T> const inverseD = Types::TVector<4, T>(vectorBAAA * factorC - vectorFEEE * factorE + vectorJIII * factorF);

			Types::TVector<4, T> const patternA = Types::TVector<4, T>(+1, -1, +1, -1);
			Types::TVector<4, T> const patternB = Types::TVector<4, T>(-1, +1, -1, +1);
			Types::TMatrix<4, 4, T> const result = Types::TMatrix<4, 4, T>
            (
                inverseA * patternA,
                inverseB * patternB,
                inverseC * patternA,
                inverseD * patternB
            );

            #ifdef IO_MATH_COLUMN_MAJOR_MATRIX_ORDER
                Types::TVector<4, T> const firstRow = Types::TVector<4, T>
                (
                    result[0][0], result[1][0], result[2][0], result[3][0]
                );
            #elif defined(IO_MATH_ROW_MAJOR_MATRIX_ORDER)
                Types::TVector<4, T> const firstRow = Types::TVector<4, T>
                (
                    result[0]
                );
            #endif

			Types::TVector<4, T> const dot = Types::TVector<4, T>
            (
                object[0] * firstRow
            );

			T const determinant = dot.x + dot.y + dot.z + dot.w;
			T const oneOverDeterminant = static_cast<T>(1) / determinant;

			return result * oneOverDeterminant;
        }
    }
}

#endif