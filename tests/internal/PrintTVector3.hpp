#ifndef _IO_MATH_TESTS_PRINT_TVECTOR_3_HPP
#define _IO_MATH_TESTS_PRINT_TVECTOR_3_HPP

#include "../../src/types/vectors/TVector3.hpp"

#include <iostream>
#include <limits>
#include <boost/type_index.hpp>

namespace IOMath
{
    namespace Types
    {
        template <typename T>
        std::ostream& boost_test_print_type(std::ostream &outputStream, TVector<3, T> const &object)
        {
            outputStream.precision(std::numeric_limits<T>::max_digits10);
            outputStream << "TVector<" << 3 << ", " << boost::typeindex::type_id<T>().pretty_name() << "> ";
            outputStream << "{ " << "x: " << object.x;
            outputStream << ", y: " << object.y;
            outputStream << ", z: " << object.z << " }";
            outputStream.flush();

            return outputStream;
        }
    }
}

#endif