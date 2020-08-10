#include "../include/IOMath/extended/vectors/IVector2.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    IVector2 zeroVector = IVector2();
    AssertVector(zeroVector, 0);
}

void TestScalarVector()
{
    IVector2 scalarVector = IVector2(3);
    AssertVector(scalarVector, 3);
}

void TestVectorAdd()
{
    IVector2 firstAdd = IVector2(1, 2);
    IVector2 secondAdd = IVector2(5, 4);

    AssertVector(firstAdd + secondAdd, 6, 6);
}

void TestVectorSubtract()
{
    IVector2 minuend = IVector2(5, 11);
    IVector2 subtrahend = IVector2(1, -11);

    AssertVector(minuend - subtrahend, 4, 22);
}

void TestVectorMultiply()
{
    IVector2 firstMultiplier = IVector2(5, 3);
    IVector2 secondMultiplier = IVector2(10, 2);
    
    AssertVector(firstMultiplier * secondMultiplier, 50, 6);
}

void TestVectorDivide()
{
    IVector2 dividend = IVector2(1, 7);
    IVector2 divider = IVector2(-1, 2);

    AssertVector(dividend / divider, -1, 3);
}

void TestVectorBracketsOperator()
{
    IVector2 vector = IVector2(7, 3);

    AssertVector(vector, vector[0], vector[1]);
}

void TestVectorFromOther()
{
    IVector2 other = IVector2(1, 2);
    IVector2 vector = IVector2(other);

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