#include "../include/IOMath/extended/vectors/DVector3.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    DVector3 zeroVector = DVector3();
    AssertVector(zeroVector, 0.0);
}

void TestScalarVector()
{
    DVector3 scalarVector = DVector3(1.7);
    AssertVector(scalarVector, 1.7);
}

void TestVectorAdd()
{
    DVector3 firstAdd = DVector3(1.0, 2.0, 3.0);
    DVector3 secondAdd = DVector3(5.0, 4.0, 3.0);

    AssertVector(firstAdd + secondAdd, 6.0, 6.0, 6.0);
}

void TestVectorSubtract()
{
    DVector3 minuend = DVector3(0.5, 1.1, 9.0);
    DVector3 subtrahend = DVector3(1.0, -1.1, 9.0);

    AssertVector(minuend - subtrahend, -0.5, 2.2, 0.0);
}

void TestVectorMultiply()
{
    DVector3 firstMultiplier = DVector3(0.5, 3.0, 2.0);
    DVector3 secondMultiplier = DVector3(10.0, 2.0, -3.0);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0, 6.0, -6.0);
}

void TestVectorDivide()
{
    DVector3 dividend = DVector3(1.0, 7.0, 0.25);
    DVector3 divider = DVector3(-1.0, 2.0, 0.05);

    AssertVector(dividend / divider, -1.0, 3.5, 5.0);
}

void TestVectorBracketsOperator()
{
    DVector3 vector = DVector3(7.7, 3.3, 256.0);

    AssertVector(vector, vector[0], vector[1], vector[2]);
}

void TestVectorFromOther()
{
    DVector3 other = DVector3(1.0, 2.0, 3.0);
    DVector3 vector = DVector3(other);

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