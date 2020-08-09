#include "../include/IOMath/extended/vectors/FVector2.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    FVector2 zeroVector = FVector2();
    AssertVector(zeroVector, 0.0f);
}

void TestScalarVector()
{
    FVector2 scalarVector = FVector2(1.7f);
    AssertVector(scalarVector, 1.7f);
}

void TestVectorAdd()
{
    FVector2 firstAdd = FVector2(1.0f, 2.0f);
    FVector2 secondAdd = FVector2(5.0f, 4.0f);

    AssertVector(firstAdd + secondAdd, 6.0f, 6.0f);
}

void TestVectorSubtract()
{
    FVector2 minuend = FVector2(0.5f, 1.1f);
    FVector2 subtrahend = FVector2(1.0f, -1.1f);

    AssertVector(minuend - subtrahend, -0.5f, 2.2f);
}

void TestVectorMultiply()
{
    FVector2 firstMultiplier = FVector2(0.5f, 3.0f);
    FVector2 secondMultiplier = FVector2(10.0f, 2.0f);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0f, 6.0f);
}

void TestVectorDivide()
{
    FVector2 dividend = FVector2(1.0f, 7.0f);
    FVector2 divider = FVector2(-1.0f, 2.0f);

    AssertVector(dividend / divider, -1.0f, 3.5f);
}

void TestVectorBracketsOperator()
{
    FVector2 vector = FVector2(7.7f, 3.3f);

    AssertVector(vector, vector[0], vector[1]);
}

void TestVectorFromOther()
{
    FVector2 other = FVector2(1.0f, 2.0f);
    FVector2 vector = FVector2(other);

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