#include "../include/IOMath/extended/vectors/IVector3.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    IVector3 zeroVector = IVector3();
    AssertVector(zeroVector, 0);
}

void TestScalarVector()
{
    IVector3 scalarVector = IVector3(3);
    AssertVector(scalarVector, 3);
}

void TestVectorAdd()
{
    IVector3 firstAdd = IVector3(1, 2, -3);
    IVector3 secondAdd = IVector3(5, 4, -3);

    AssertVector(firstAdd + secondAdd, 6, 6, -6);
}

void TestVectorSubtract()
{
    IVector3 minuend = IVector3(5, 11, 4);
    IVector3 subtrahend = IVector3(1, -11, 2);

    AssertVector(minuend - subtrahend, 4, 22, 2);
}

void TestVectorMultiply()
{
    IVector3 firstMultiplier = IVector3(5, 3, 4);
    IVector3 secondMultiplier = IVector3(10, 2, 3);
    
    AssertVector(firstMultiplier * secondMultiplier, 50, 6, 12);
}

void TestVectorDivide()
{
    IVector3 dividend = IVector3(1, 7, 10);
    IVector3 divider = IVector3(-1, 2, 2);

    AssertVector(dividend / divider, -1, 3, 5);
}

void TestVectorBracketsOperator()
{
    IVector3 vector = IVector3(7, 3, 1);

    AssertVector(vector, vector[0], vector[1], vector[2]);
}

void TestVectorFromOther()
{
    IVector3 other = IVector3(1, 2, 3);
    IVector3 vector = IVector3(other);

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