#ifndef _IO_BASIC_TYPES_HPP
#define _IO_BASIC_TYPES_HPP

namespace IOMath
{
	namespace Types
	{
		template<size_t L, typename T> struct TVector;
		template<size_t R, size_t C, typename T> struct TMatrix;
		template<typename T> struct TQuaternion;
	}
}

#endif