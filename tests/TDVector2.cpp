#include "../include/IOMath/extended/vectors/DVector2.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    DVector2 zeroVector = DVector2();
    AssertVector(zeroVector, 0.0);
}

void TestScalarVector()
{
    DVector2 scalarVector = DVector2(1.7);
    AssertVector(scalarVector, 1.7);
}

void TestVectorAdd()
{
    DVector2 firstAdd = DVector2(1.0, 2.0);
    DVector2 secondAdd = DVector2(5.0, 4.0);

    AssertVector(firstAdd + secondAdd, 6.0, 6.0);
}

void TestVectorSubtract()
{
    DVector2 minuend = DVector2(0.5, 1.1);
    DVector2 subtrahend = DVector2(1.0, -1.1);

    AssertVector(minuend - subtrahend, -0.5, 2.2);
}

void TestVectorMultiply()
{
    DVector2 firstMultiplier = DVector2(0.5, 3.0);
    DVector2 secondMultiplier = DVector2(10.0, 2.0);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0, 6.0);
}

void TestVectorDivide()
{
    DVector2 dividend = DVector2(1.0, 7.0);
    DVector2 divider = DVector2(-1.0, 2.0);

    AssertVector(dividend / divider, -1.0, 3.5);
}

void TestVectorBracketsOperator()
{
    DVector2 vector = DVector2(7.7, 3.3);

    AssertVector(vector, vector[0], vector[1]);
}

void TestVectorFromOther()
{
    DVector2 other = DVector2(1.0, 2.0);
    DVector2 vector = DVector2(other);

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