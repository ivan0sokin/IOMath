#include "../include/IOMath/extended/vectors/UVector4.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    UVector4 zeroVector = UVector4();
    AssertVector(zeroVector, 0u);
}

void TestScalarVector()
{
    UVector4 scalarVector = UVector4(3u);
    AssertVector(scalarVector, 3u);
}

void TestVectorAdd()
{
    UVector4 firstAdd = UVector4(1u, 2u, 3u, 1u);
    UVector4 secondAdd = UVector4(5u, 4u, 3u, 1u);

    AssertVector(firstAdd + secondAdd, 6u, 6u, 6u, 2u);
}

void TestVectorSubtract()
{
    UVector4 minuend = UVector4(5u, 11u, 4u, 5u);
    UVector4 subtrahend = UVector4(1u, 11u, 2u, 3u);

    AssertVector(minuend - subtrahend, 4u, 0u, 2u, 2u);
}

void TestVectorMultiply()
{
    UVector4 firstMultiplier = UVector4(5u, 3u, 4u, 1u);
    UVector4 secondMultiplier = UVector4(10u, 2u, 3u, 2u);
    
    AssertVector(firstMultiplier * secondMultiplier, 50u, 6u, 12u, 2u);
}

void TestVectorDivide()
{
    UVector4 dividend = UVector4(1u, 7u, 10u, 20u);
    UVector4 divider = UVector4(1u, 2u, 2u, 5u);

    AssertVector(dividend / divider, 1u, 3u, 5u, 4u);
}

void TestVectorBracketsOperator()
{
    UVector4 vector = UVector4(7u, 3u, 1u, 2u);

    AssertVector(vector, vector[0], vector[1], vector[2], vector[3]);
}

void TestVectorFromOther()
{
    UVector4 other = UVector4(1u, 2u, 3u, 4u);
    UVector4 vector = UVector4(other);

    AssertVector(vector, other);
}

void Test()
{
    TestZeroVector();
    TestScalarVector();
    TestVectorAdd();
    TestVectorSubtract();
    TestVectorMultiply();
    TestVectorDivide();
    TestVectorBracketsOperator();
}

int main()
{
    Test();
    return 0;
}