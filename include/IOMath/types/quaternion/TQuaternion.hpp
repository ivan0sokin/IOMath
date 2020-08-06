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

#ifndef _IO_MATH_TQUATERNION_HPP
#define _IO_MATH_TQUATERNION_HPP

#include "../../detail/ComputeBasicQuaternionFunctions.hpp"
#include "../../detail/ComputeGeometric.hpp"

namespace IOMath
{
    namespace Types
    {
        template <typename T>
        struct TQuaternion
        {
            union
            {
                struct { T w, x, y, z; };
                struct { T a, i, j, k; };
            };

            constexpr TQuaternion() noexcept = default;
            constexpr TQuaternion(TQuaternion const &other) noexcept = default;
            constexpr TQuaternion(T w, T x, T y, T z) noexcept :
                w{w},
                x{x},
                y{y},
                z{z} {}
            constexpr TQuaternion(T w, TVector<3, T> const &vector) noexcept :
                w{w},
                x{vector.x},
                y{vector.y},
                z{vector.z} {}

            template <typename U>
            constexpr TQuaternion(TQuaternion<U> const &other) noexcept :
                w{static_cast<T>(other.w)},
                x{static_cast<T>(other.x)},
                y{static_cast<T>(other.y)},
                z{static_cast<T>(other.z)} {}
            template <typename W, typename X, typename Y, typename Z>
            constexpr TQuaternion(W w, X x, Y y, Z z) noexcept :
                w{static_cast<T>(w)},
                x{static_cast<T>(x)},
                y{static_cast<T>(y)},
                z{static_cast<T>(z)} {}
            template <typename W, typename XYZ>
            constexpr TQuaternion(W w, TVector<3, XYZ> const &vectorXYZ) noexcept :
                w{static_cast<T>(w)},
                x{static_cast<T>(vectorXYZ.x)},
                y{static_cast<T>(vectorXYZ.y)},
                z{static_cast<T>(vectorXYZ.z)} {}

            static constexpr TQuaternion<T> FromAxisAngle(TVector<3, T> const &axis, T angle) noexcept
            {
                T const halfAngle = angle / static_cast<T>(2);
                T const sinHalfAngle = std::sin(halfAngle);
                T const cosHalfAngle = std::cos(halfAngle);

                return TQuaternion<T>
                (
                    cosHalfAngle,
                    sinHalfAngle * axis.x,
                    sinHalfAngle * axis.y,
                    sinHalfAngle * axis.z
                );
            }
            static constexpr TQuaternion<T> FromTwoVectors(TVector<3, T> const &vectorA, TVector<3, T> const &vectorB) noexcept
            {
                T normA_normB = std::sqrt(detail::ComputeDot(vectorA, vectorA) * detail::ComputeDot(vectorB, vectorB));
                T real = normA_normB + detail::ComputeDot(vectorA, vectorB);
        
                TVector<3, T> temp;
                if(real < static_cast<T>(1.e-6f) * normA_normB)
                {
                    real = static_cast<T>(0);

                    if (std::abs(vectorA.x) > std::abs(vectorA.z))
                    {
                        temp = TVector<3, T>(-vectorA.y, vectorA.x, static_cast<T>(0));
                    }
                    else
                        temp = TVector<3, T>(static_cast<T>(0), -vectorA.z, vectorA.y);
                }
                else
                    temp = detail::ComputeCross(vectorA, vectorB);


                return detail::ComputeNormalize(TQuaternion<T>
                (
                    real,
                    temp.x,
                    temp.y,
                    temp.z
                ));
            }
            
            template <typename U>
            static constexpr TQuaternion<T> FromMatrix3x3(TMatrix<3, 3, U> const &matrix) noexcept
            {
                return TQuaternion<T>();
            }
            template <typename U>
            static constexpr TQuaternion<T> FromMatrix4x4(TMatrix<4, 4, U> const &matrix) noexcept
            {
                return TQuaternion<T>();
            }

            static constexpr TQuaternion<T> Identity() noexcept
            {
                T const zero = static_cast<T>(0);

                return TQuaternion<T>
                (
                    static_cast<T>(1),
                    zero,
                    zero,
                    zero
                );
            }

            static constexpr size_t Size() noexcept
            {
                return static_cast<T>(4);
            }

            constexpr T& operator[](size_t index) noexcept
			{
				assert(index >= 0 && index < TQuaternion::Size());

				switch (index)
				{
				default:
					case 0:
						return x;
					case 1:
						return y;
                    case 2:
                        return z;
                    case 3:
                        return w;
				}
			}
			constexpr T const& operator[](size_t index) const noexcept
			{
				assert(index >= 0 && index < TQuaternion::Size());

				switch (index)
				{
				default:
					case 0:
						return x;
					case 1:
						return y;
                    case 2:
                        return z;
                    case 3:
                        return w;
				}
			}

            constexpr TQuaternion<T>& operator=(TQuaternion<T> const &other) noexcept
            {
                this->w = other.w;
                this->x = other.x;
                this->y = other.y;
                this->z = other.z;

                return *this;
            }
            template <typename U>
            constexpr TQuaternion<T>& operator=(TQuaternion<U> const &other) noexcept
            {
                this->w = static_cast<T>(other.w);
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                this->z = static_cast<T>(other.z);

                return *this;
            }
            template <typename U>
            constexpr TQuaternion<T>& operator+=(TQuaternion<U> const &other) noexcept
            {
                this->w += static_cast<T>(other.w);
                this->x += static_cast<T>(other.x);
                this->y += static_cast<T>(other.y);
                this->z += static_cast<T>(other.z);
            }
            template <typename U>
            constexpr TQuaternion<T>& operator-=(TQuaternion<U> const &other) noexcept
            {
                this->w -= static_cast<T>(other.w);
                this->x -= static_cast<T>(other.x);
                this->y -= static_cast<T>(other.y);
                this->z -= static_cast<T>(other.z);
            }
            template <typename U>
            constexpr TQuaternion<T>& operator*=(U scalar) noexcept
            {
                this->w *= static_cast<T>(scalar);
                this->x *= static_cast<T>(scalar);
                this->y *= static_cast<T>(scalar);
                this->z *= static_cast<T>(scalar);

                return *this;
            }
            template <typename U>
            constexpr TQuaternion<T>& operator*=(TQuaternion<U> const &other) noexcept
            {
                T const thisW = this->w;
                T const thisX = this->x;
                T const thisY = this->y;
                T const thisZ = this->z;

                T const otherW = other.w;
                T const otherX = other.x;
                T const otherY = other.y;
                T const otherZ = other.z;

                this->w = thisW * otherW - thisX * otherX - thisY * otherY - thisZ * otherZ;
                this->x = thisW * otherX + thisX * otherW + thisY * otherZ - thisZ * otherY;
                this->y = thisW * otherY + thisY * otherW + thisZ * otherX - thisX * otherZ;
                this->z = thisW * otherZ + thisZ * otherW + thisX * otherY - thisY * otherX;

                return *this;
            }
            template <typename U>
            constexpr TQuaternion<T>& operator/=(U scalar) noexcept
            {
                this->w /= static_cast<T>(scalar);
                this->x /= static_cast<T>(scalar);
                this->y /= static_cast<T>(scalar);
                this->z /= static_cast<T>(scalar);

                return *this;
            }
        };
        
        template <typename T>
        constexpr TQuaternion<T> operator+(TQuaternion<T> const &object) noexcept
        {
            return object;
        }
        template <typename T>
        constexpr TQuaternion<T> operator-(TQuaternion<T> const &object) noexcept
        {
            return TQuaternion<T>
            (
                -object.w,
                -object.x,
                -object.y,
                -object.z
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator+(TQuaternion<T> const &lObject, TQuaternion<T> const &rObject) noexcept
        {
            return TQuaternion<T>
            (
                lObject.w + rObject.w,
                lObject.x + rObject.x,
                lObject.y + rObject.y,
                lObject.z + rObject.z
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator-(TQuaternion<T> const &lObject, TQuaternion<T> const &rObject) noexcept
        {
            return TQuaternion<T>
            (
                lObject.w - rObject.w,
                lObject.x - rObject.x,
                lObject.y - rObject.y,
                lObject.z - rObject.z
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator*(T scalar, TQuaternion<T> const &object) noexcept
        {
            return TQuaternion<T>
            (
                scalar * object.w,
                scalar * object.x,
                scalar * object.y,
                scalar * object.z
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator*(TQuaternion<T> const &object, T scalar) noexcept
        {
            return TQuaternion<T>
            (
                object.w * scalar,
                object.x * scalar,
                object.y * scalar,
                object.z * scalar
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator*(TQuaternion<T> const &lObject, TQuaternion<T> const &rObject) noexcept
        {
            T const lObjectW = lObject.w;
            T const lObjectX = lObject.x;
            T const lObjectY = lObject.y;
            T const lObjectZ = lObject.z;

            T const rObjectW = rObject.w;
            T const rObjectX = rObject.x;
            T const rObjectY = rObject.y;
            T const rObjectZ = rObject.z;

            return TQuaternion<T>
            (
                lObjectW * rObjectW - lObjectX * rObjectX - lObjectY * rObjectY - lObjectZ * rObjectZ,
                lObjectW * rObjectX + lObjectX * rObjectW + lObjectY * rObjectZ - lObjectZ * rObjectY,
                lObjectW * rObjectY + lObjectY * rObjectW + lObjectZ * rObjectX - lObjectX * rObjectZ,
                lObjectW * rObjectZ + lObjectZ * rObjectW + lObjectX * rObjectY - lObjectY * rObjectX
            );
        }
        template <typename T>
        constexpr TVector<3, T> operator*(TVector<3, T> const& vector, TQuaternion<T> const &object) noexcept
        {
            return detail::ComputeInverse(object) * vector;
        }
        template <typename T>
        constexpr TVector<3, T> operator*(TQuaternion<T> const &object, TVector<3, T> const &vector) noexcept
        {
            TVector<3, T> const vectorFromQuaternion = TVector<3, T>(object.x, object.y, object.z);
            TVector<3, T> const uv = detail::ComputeCross(vectorFromQuaternion, vector);
            TVector<3, T> const uuv = detail::ComputeCross(vectorFromQuaternion, uv);

            return vector + static_cast<T>(2) * ((uv * object.w) + uuv);
        }
        template <typename T>
        constexpr TVector<4, T> operator*(TVector<4, T> const& vector, TQuaternion<T> const &object) noexcept
        {
            return detail::ComputeInverse(object) * vector;
        }
        template <typename T>
        constexpr TVector<4, T> operator*(TQuaternion<T> const &object, TVector<4, T> const &vector) noexcept
        {
            return TVector<4, T>
            (
                object * TVector<3, T>(vector),
                vector.w
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator/(T scalar, TQuaternion<T> const &object) noexcept
        {
            return TQuaternion<T>
            (
                scalar / object.w,
                scalar / object.x,
                scalar / object.y,
                scalar / object.z
            );
        }
        template <typename T>
        constexpr TQuaternion<T> operator/(TQuaternion<T> const &object, T scalar) noexcept
        {
            return TQuaternion<T>
            (
                object.w / scalar,
                object.x / scalar,
                object.y / scalar,
                object.z / scalar
            );
        }
    
        template <typename T>
        constexpr bool operator==(TQuaternion<T> const &lObject, TQuaternion<T> const &rObject) noexcept
        {
            return
            (
                lObject.x == rObject.x &&
                lObject.y == rObject.y &&
                lObject.z == rObject.z &&
                lObject.w == rObject.w
            );
        }
        template <typename T>
        constexpr bool operator!=(TQuaternion<T> const &lObject, TQuaternion<T> const &rObject) noexcept
        {
            return
            (
                lObject.w != rObject.w ||
                lObject.x != rObject.x ||
                lObject.y != rObject.y ||
                lObject.z != rObject.z
            );
        }
    }
}

#endif