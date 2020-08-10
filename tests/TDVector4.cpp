#include "../include/IOMath/extended/vectors/DVector4.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    DVector4 zeroVector = DVector4();
    AssertVector(zeroVector, 0.0);
}

void TestScalarVector()
{
    DVector4 scalarVector = DVector4(1.7);
    AssertVector(scalarVector, 1.7);
}

void TestVectorAdd()
{
    DVector4 firstAdd = DVector4(1.0, 2.0, 3.0, -3.0);
    DVector4 secondAdd = DVector4(5.0, 4.0, 3.0, -3.0);

    AssertVector(firstAdd + secondAdd, 6.0, 6.0, 6.0, -6.0);
}

void TestVectorSubtract()
{
    DVector4 minuend = DVector4(0.5, 1.1, 9.0, 56.0);
    DVector4 subtrahend = DVector4(1.0, -1.1, 9.0, 50.0);

    AssertVector(minuend - subtrahend, -0.5, 2.2, 0.0, 6.0);
}

void TestVectorMultiply()
{
    DVector4 firstMultiplier = DVector4(0.5, 3.0, 2.0, 1.5);
    DVector4 secondMultiplier = DVector4(10.0, 2.0, -3.0, 10.0);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0, 6.0, -6.0, 15.0);
}

void TestVectorDivide()
{
    DVector4 dividend = DVector4(1.0, 7.0, 0.25, -20.0);
    DVector4 divider = DVector4(-1.0, 2.0, 0.05, -20.0);

    AssertVector(dividend / divider, -1.0, 3.5, 5.0, 1.0);
}

void TestVectorBracketsOperator()
{
    DVector4 vector = DVector4(7.7, 3.3, 256.0, 65536.0);

    AssertVector(vector, vector[0], vector[1], vector[2], vector[3]);
}

void TestVectorFromOther()
{
    DVector4 other = DVector4(1.0, 2.0, 3.0, 4.0);
    DVector4 vector = DVector4(other);

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