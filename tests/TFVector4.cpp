#include "../include/IOMath/extended/vectors/FVector4.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    FVector4 zeroVector = FVector4();
    AssertVector(zeroVector, 0.0f);
}

void TestScalarVector()
{
    FVector4 scalarVector = FVector4(1.7f);
    AssertVector(scalarVector, 1.7f);
}

void TestVectorAdd()
{
    FVector4 firstAdd = FVector4(1.0f, 2.0f, 3.0f, -3.0f);
    FVector4 secondAdd = FVector4(5.0f, 4.0f, 3.0f, -3.0f);

    AssertVector(firstAdd + secondAdd, 6.0f, 6.0f, 6.0f, 6.0f);
}

void TestVectorSubtract()
{
    FVector4 minuend = FVector4(0.5f, 1.1f, 9.0f, 56.0f);
    FVector4 subtrahend = FVector4(1.0f, -1.1f, 9.0f, 50.0f);

    AssertVector(minuend - subtrahend, -0.5f, 2.2f, 0.0f, 6.0f);
}

void TestVectorMultiply()
{
    FVector4 firstMultiplier = FVector4(0.5f, 3.0f, 2.0f, 1.5f);
    FVector4 secondMultiplier = FVector4(10.0f, 2.0f, -3.0f, 10.0f);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0f, 6.0f, -6.0f, 15.0f);
}

void TestVectorDivide()
{
    FVector4 dividend = FVector4(1.0f, 7.0f, 0.25f, -20.0f);
    FVector4 divider = FVector4(-1.0f, 2.0f, 0.05f, -20.0f);

    AssertVector(dividend / divider, -1.0f, 3.5f, 5.0f, 1.0f);
}

void TestVectorBracketsOperator()
{
    FVector4 vector = FVector4(7.7f, 3.3f, 256.0f, 65536.0f);

    AssertVector(vector, vector[0], vector[1], vector[2], vector[3]);
}

void TestVectorFromOther()
{
    FVector4 other = FVector4(1.0f, 2.0f, 3.0f, 4.0f);
    FVector4 vector = FVector4(other);

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