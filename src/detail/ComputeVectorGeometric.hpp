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

#ifndef _IO_MATH_COMPUTE_VECTOR_GEOMETRIC_HPP
#define _IO_MATH_COMPUTE_VECTOR_GEOMETRIC_HPP

#include "../types/BasicTypes.hpp"

#include <cmath>

namespace IOMath
{
	namespace detail
	{
		template <typename T>
		constexpr T ComputeDot(Types::TVector<2, T> const &lObject, Types::TVector<2, T> const &rObject) noexcept
		{
			return
			(
				lObject.x * rObject.x +
				lObject.y * rObject.y
			);
		}
		template <typename T>
		constexpr T ComputeDot(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
		{
			return
			(
				lObject.x * rObject.x +
				lObject.y * rObject.y +
				lObject.z * rObject.z
			);
		}
		template <typename T>
		constexpr T ComputeDot(Types::TVector<4, T> const &lObject, Types::TVector<4, T> const &rObject) noexcept
		{
			return
			(
				lObject.x * rObject.x + 
				lObject.y * rObject.y +
				lObject.z * rObject.z +
				lObject.w * rObject.w
			);
		}
		
		template <typename T>
		constexpr T ComputeLength(Types::TVector<2, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;

			return std::sqrt(objectX * objectX + objectY * objectY);
		}
		template <typename T>
		constexpr T ComputeLength(Types::TVector<3, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;

			return std::sqrt(objectX * objectX + objectY * objectY + objectZ * objectZ);
		}
		template <typename T>
		constexpr T ComputeLength(Types::TVector<4, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;
			T const objectW = object.w;

			return std::sqrt(objectX * objectX + objectY * objectY + objectZ * objectZ + objectW * objectW);
		}

		template <typename T>
		constexpr T ComputeDistance(Types::TVector<2, T> const &lObject, Types::TVector<2, T> const &rObject) noexcept
		{
			T const resultX = lObject.x - rObject.x;
			T const resultY = lObject.y - rObject.y;

			return std::sqrt(resultX * resultX + resultY * resultY);
		}
		template <typename T>
		constexpr T ComputeDistance(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
		{
			T const resultX = lObject.x - rObject.x;
			T const resultY = lObject.y - rObject.y;
			T const resultZ = lObject.z - rObject.z;

			return std::sqrt(resultX * resultX + resultY * resultY + resultZ * resultZ);
		}
		template <typename T>
		constexpr T ComputeDistance(Types::TVector<4, T> const &lObject, Types::TVector<4, T> const &rObject) noexcept
		{
			T const resultX = lObject.x - rObject.x;
			T const resultY = lObject.y - rObject.y;
			T const resultZ = lObject.z - rObject.z;
			T const resultW = lObject.w - rObject.w;

			return std::sqrt(resultX * resultX + resultY * resultY + resultZ * resultZ + resultW * resultW);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeNormalize(Types::TVector<2, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;

			return object * (static_cast<T>(1) / std::sqrt(objectX * objectX + objectY * objectY));
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeNormalize(Types::TVector<3, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;

			return object * (static_cast<T>(1) / std::sqrt(objectX * objectX + objectY * objectY + objectZ * objectZ));
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeNormalize(Types::TVector<4, T> const &object) noexcept
		{
			T const objectX = object.x;
			T const objectY = object.y;
			T const objectZ = object.z;
			T const objectW = object.w;

			return object * (static_cast<T>(1) / std::sqrt(objectX * objectX + objectY * objectY + objectZ * objectZ + objectW * objectW));
		}
		
		template <typename T>
		constexpr Types::TVector<3, T> ComputeCross(Types::TVector<3, T> const &lObject, Types::TVector<3, T> const &rObject) noexcept
		{
			T const lObjectX = lObject.x;
			T const lObjectY = lObject.y;
			T const lObjectZ = lObject.z;

			T const rObjectX = rObject.x;
			T const rObjectY = rObject.y;
			T const rObjectZ = rObject.z;

			return Types::TVector<3, T>
			(
				lObjectY * rObjectZ - rObjectY * lObjectZ,
				lObjectZ * rObjectX - rObjectZ * lObjectX,
				lObjectX * rObjectY - rObjectX * lObjectY
			);
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeReflect(Types::TVector<2, T> const &object, Types::TVector<2, T> const &normal) noexcept
		{
			return object - static_cast<T>(2) * (object.x * normal.x + object.y * normal.y) * normal;
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeReflect(Types::TVector<3, T> const &object, Types::TVector<3, T> const &normal) noexcept
		{
			return object - static_cast<T>(2) * (object.x * normal.x + object.y * normal.y + object.z * normal.z) * normal;
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeReflect(Types::TVector<4, T> const &object, Types::TVector<4, T> const &normal) noexcept
		{
			return object - static_cast<T>(2) * (object.x * normal.x + object.y * normal.y + object.z * normal.z + object.w * normal.w) * normal;
		}

		template <typename T>
		constexpr Types::TVector<2, T> ComputeRefract(Types::TVector<2, T> const &object, Types::TVector<2, T> const &normal, T eta) noexcept
		{
			T const dot = object.x * normal.x + object.y * normal.y;
			T const k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dot * dot);
			
			if (k < static_cast<T>(0))
				return Types::TVector<2, T>(0);

			return eta * object - (eta * dot + std::sqrt(k)) * normal;
		}
		template <typename T>
		constexpr Types::TVector<3, T> ComputeRefract(Types::TVector<3, T> const &object, Types::TVector<3, T> const &normal, T eta) noexcept
		{
			T const dot = object.x * normal.x + object.y * normal.y + object.z * normal.z;
			T const k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dot * dot);
			
			if (k < static_cast<T>(0))
				return Types::TVector<3, T>(0);

			return eta * object - (eta * dot + std::sqrt(k)) * normal;
		}
		template <typename T>
		constexpr Types::TVector<4, T> ComputeRefract(Types::TVector<4, T> const &object, Types::TVector<4, T> const &normal, T eta) noexcept
		{
			T const dot = object.x * normal.x + object.y * normal.y + object.z * normal.z + object.w * normal.w;
			T const k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dot * dot);
			
			if (k < static_cast<T>(0))
				return Types::TVector<4, T>(0);

			return eta * object - (eta * dot + std::sqrt(k)) * normal;
		}
	}
}

#endif