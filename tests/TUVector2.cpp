#include "../include/IOMath/extended/vectors/UVector2.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    UVector2 zeroVector = UVector2();
    AssertVector(zeroVector, 0u);
}

void TestScalarVector()
{
    UVector2 scalarVector = UVector2(3u);
    AssertVector(scalarVector, 3u);
}

void TestVectorAdd()
{
    UVector2 firstAdd = UVector2(1u, 2u);
    UVector2 secondAdd = UVector2(5u, 4u);

    AssertVector(firstAdd + secondAdd, 6u, 6u);
}

void TestVectorSubtract()
{
    UVector2 minuend = UVector2(5u, 11u);
    UVector2 subtrahend = UVector2(1u, -11u);

    AssertVector(minuend - subtrahend, 4u, 22u);
}

void TestVectorMultiply()
{
    UVector2 firstMultiplier = UVector2(5u, 3u);
    UVector2 secondMultiplier = UVector2(10u, 2u);
    
    AssertVector(firstMultiplier * secondMultiplier, 50u, 6u);
}

void TestVectorDivide()
{
    UVector2 dividend = UVector2(2u, 7u);
    UVector2 divider = UVector2(2u, 2u);

    AssertVector(dividend / divider, 1u, 3u);
}

void TestVectorBracketsOperator()
{
    UVector2 vector = UVector2(7u, 3u);

    AssertVector(vector, vector[0], vector[1]);
}

void TestVectorFromOther()
{
    UVector2 other = UVector2(1u, 2u);
    UVector2 vector = UVector2(other);

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