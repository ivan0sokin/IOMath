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
    namespace detail
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
            T const objectA = object[0][0];
			T const objectB = object[0][1];
			T const objectC = object[0][2];
			T const objectD = object[1][0];
			T const objectE = object[1][1];
			T const objectF = object[1][2];
			T const objectG = object[2][0];
			T const objectH = object[2][1];
			T const objectI = object[2][2];
            
            return
                objectA * (objectE * objectI - objectF * objectH) -
                objectB * (objectD * objectI - objectF * objectG) -
                objectC * (objectE * objectG - objectD * objectH);   
        }
        template <typename T>
        constexpr T ComputeDeterminant(Types::TMatrix<4, 4, T> const &object) noexcept
        {
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
            T oneOverDeterminant = static_cast<T>(1) / ComputeDeterminant(object);
            
			return Types::TMatrix<2, 2, T>
            (
                  object[1][1] * oneOverDeterminant,
                -(object[0][1] * oneOverDeterminant),
                -(object[1][0] * oneOverDeterminant),
                  object[0][0] * oneOverDeterminant
            );
        }
        template <typename T>
        constexpr Types::TMatrix<3, 3, T> ComputeInverse(Types::TMatrix<3, 3, T> const &object) noexcept
        {
            T oneOverDeterminant = static_cast<T>(1) / ComputeDeterminant(object);

            T const objectA = object[0][0];
			T const objectB = object[0][1];
			T const objectC = object[0][2];
			T const objectD = object[1][0];
			T const objectE = object[1][1];
			T const objectF = object[1][2];
			T const objectG = object[2][0];
			T const objectH = object[2][1];
			T const objectI = object[2][2];

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

			Types::TVector<4, T> factorA = Types::TVector<4, T>(coefA, coefA, coefB, coefC);
			Types::TVector<4, T> factorB = Types::TVector<4, T>(coefD, coefD, coefE, coefF);
			Types::TVector<4, T> factorC = Types::TVector<4, T>(coefG, coefG, coefH, coefI);
			Types::TVector<4, T> factorD = Types::TVector<4, T>(coefJ, coefJ, coefK, coefL);
			Types::TVector<4, T> factorE = Types::TVector<4, T>(coefM, coefM, coefN, coefO);
			Types::TVector<4, T> factorF = Types::TVector<4, T>(coefP, coefP, coefQ, coefR);

			Types::TVector<4, T> vectorBAAA = Types::TVector<4, T>(objectB, objectA, objectA, objectA); // A
			Types::TVector<4, T> vectorFEEE = Types::TVector<4, T>(objectF, objectE, objectE, objectE); // B
			Types::TVector<4, T> vectorJIII = Types::TVector<4, T>(objectJ, objectI, objectI, objectI); // C
			Types::TVector<4, T> vectorNMMM = Types::TVector<4, T>(objectN, objectM, objectM, objectM); // D

			Types::TVector<4, T> inverseA = Types::TVector<4, T>(vectorFEEE * factorA - vectorJIII * factorB + vectorNMMM * factorC);
			Types::TVector<4, T> inverseB = Types::TVector<4, T>(vectorBAAA * factorA - vectorJIII * factorD + vectorNMMM * factorE);
			Types::TVector<4, T> inverseC = Types::TVector<4, T>(vectorBAAA * factorB - vectorFEEE * factorD + vectorNMMM * factorF);
			Types::TVector<4, T> inverseD = Types::TVector<4, T>(vectorBAAA * factorC - vectorFEEE * factorE + vectorJIII * factorF);

			Types::TVector<4, T> patternA = Types::TVector<4, T>(+1, -1, +1, -1);
			Types::TVector<4, T> patternB = Types::TVector<4, T>(-1, +1, -1, +1);
			Types::TMatrix<4, 4, T> const result = Types::TMatrix<4, 4, T>
            (
                inverseA * patternA,
                inverseB * patternB,
                inverseC * patternA,
                inverseD * patternB
            );

			Types::TVector<4, T> dot = Types::TVector<4, T>(object[0] * result[0]);
			T determinant = dot.x + dot.y + dot.z + dot.w;

			T oneOverDeterminant = static_cast<T>(1) / determinant;

			return result * oneOverDeterminant;
        }
    }
}

#endif