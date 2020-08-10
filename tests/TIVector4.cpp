#include "../include/IOMath/extended/vectors/IVector4.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    IVector4 zeroVector = IVector4();
    AssertVector(zeroVector, 0);
}

void TestScalarVector()
{
    IVector4 scalarVector = IVector4(3);
    AssertVector(scalarVector, 3);
}

void TestVectorAdd()
{
    IVector4 firstAdd = IVector4(1, 2, -3, 1);
    IVector4 secondAdd = IVector4(5, 4, -3, 1);

    AssertVector(firstAdd + secondAdd, 6, 6, -6, 2);
}

void TestVectorSubtract()
{
    IVector4 minuend = IVector4(5, 11, 4, 5);
    IVector4 subtrahend = IVector4(1, -11, 2, 3);

    AssertVector(minuend - subtrahend, 4, 22, 2, 2);
}

void TestVectorMultiply()
{
    IVector4 firstMultiplier = IVector4(5, 3, 4, 1);
    IVector4 secondMultiplier = IVector4(10, 2, 3, 2);
    
    AssertVector(firstMultiplier * secondMultiplier, 50, 6, 12, 2);
}

void TestVectorDivide()
{
    IVector4 dividend = IVector4(1, 7, 10, 20);
    IVector4 divider = IVector4(-1, 2, 2, 5);

    AssertVector(dividend / divider, -1, 3, 5, 4);
}

void TestVectorBracketsOperator()
{
    IVector4 vector = IVector4(7, 3, 1, 2);

    AssertVector(vector, vector[0], vector[1], vector[2], vector[3]);
}

void TestVectorFromOther()
{
    IVector4 other = IVector4(1, 2, 3, 4);
    IVector4 vector = IVector4(other);

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