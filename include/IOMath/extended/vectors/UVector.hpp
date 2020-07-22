#ifndef _IO_MATH_UVECTOR_HPP
#define _IO_MATH_UVECTOR_HPP

#include "../../types/vectors/TVector2.hpp"
#include "../../types/vectors/TVector3.hpp"
#include "../../types/vectors/TVector4.hpp"

namespace IOMath
{
	typedef Types::TVector<2, unsigned int> UVector2;
	typedef Types::TVector<3, unsigned int> UVector3;
	typedef Types::TVector<4, unsigned int> UVector4;
}

#endif