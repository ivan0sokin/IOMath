#include "../include/IOMath/extended/vectors/UVector3.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    UVector3 zeroVector = UVector3();
    AssertVector(zeroVector, 0u);
}

void TestScalarVector()
{
    UVector3 scalarVector = UVector3(3u);
    AssertVector(scalarVector, 3u);
}

void TestVectorAdd()
{
    UVector3 firstAdd = UVector3(1u, 2u, -3u);
    UVector3 secondAdd = UVector3(5u, 4u, -3u);

    AssertVector(firstAdd + secondAdd, 6u, 6u, -6u);
}

void TestVectorSubtract()
{
    UVector3 minuend = UVector3(5u, 11u, 4u);
    UVector3 subtrahend = UVector3(1u, -11u, 2u);

    AssertVector(minuend - subtrahend, 4u, 22u, 2u);
}

void TestVectorMultiply()
{
    UVector3 firstMultiplier = UVector3(5u, 3u, 4u);
    UVector3 secondMultiplier = UVector3(10u, 2u, 3u);
    
    AssertVector(firstMultiplier * secondMultiplier, 50u, 6u, 12u);
}

void TestVectorDivide()
{
    UVector3 dividend = UVector3(2u, 7u, 10u);
    UVector3 divider = UVector3(2u, 2u, 2u);

    AssertVector(dividend / divider, 1u, 3u, 5u);
}

void TestVectorBracketsOperator()
{
    UVector3 vector = UVector3(7u, 3u, 1u);

    AssertVector(vector, vector[0], vector[1], vector[2]);
}

void TestVectorFromOther()
{
    UVector3 other = UVector3(1u, 2u, 3u);
    UVector3 vector = UVector3(other);

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