#include "../include/IOMath/extended/vectors/FVector3.hpp"
#include "VectorAsserts.hpp"

using namespace IOMath;

void TestZeroVector()
{
    FVector3 zeroVector;
    //AssertVector(zeroVector, 0.0f);
}

void TestScalarVector()
{
    FVector3 scalarVector = FVector3(1.7f);
    //AssertVector(scalarVector, 1.7f);
}

void TestVectorAdd()
{
    FVector3 firstAdd = FVector3(1.0f, 2.0f, 3.0f);
    FVector3 secondAdd = FVector3(5.0f, 4.0f, 3.0f);

    AssertVector(firstAdd + secondAdd, 6.0f, 6.0f, 6.0f);
}

void TestVectorSubtract()
{
    FVector3 minuend = FVector3(0.5f, 1.1f, 9.0f);
    FVector3 subtrahend = FVector3(1.0f, -1.1f, 9.0f);

    AssertVector(minuend - subtrahend, -0.5f, 2.2f, 0.0f);
}

void TestVectorMultiply()
{
    FVector3 firstMultiplier = FVector3(0.5f, 3.0f, 2.0f);
    FVector3 secondMultiplier = FVector3(10.0f, 2.0f, -3.0f);
    
    AssertVector(firstMultiplier * secondMultiplier, 5.0f, 6.0f, -6.0f);
}

void TestVectorDivide()
{
    FVector3 dividend = FVector3(1.0f, 7.0f, 0.25f);
    FVector3 divider = FVector3(-1.0f, 2.0f, 0.05f);

    AssertVector(dividend / divider, -1.0f, 3.5f, 5.0f);
}

void TestVectorBracketsOperator()
{
    FVector3 vector = FVector3(7.7f, 3.3f, 256.0f);

    AssertVector(vector, vector[0], vector[1], vector[2]);
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