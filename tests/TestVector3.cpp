#define BOOST_TEST_MODULE TestVector3
#include <boost/test/included/unit_test.hpp>

#include "../src/Vector2.hpp"
#include "../src/Vector3.hpp"
#include "../src/Vector4.hpp"
#include "../src/Quaternion.hpp"

#include "internal/PrintTVector3.hpp"

using namespace IOMath;

BOOST_AUTO_TEST_CASE(Vector3_DefaultConstructor)
{
    Vector3 vector = Vector3();
    
    BOOST_CHECK_EQUAL(vector, Vector3(0.0f, 0.0f, 0.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_Constructor)
{
    Vector3 vector = Vector3(1.0f, 2.7f, 3.7f);

    BOOST_CHECK_EQUAL(vector.x, 1.0f);
    BOOST_CHECK_EQUAL(vector.y, 2.7f);
    BOOST_CHECK_EQUAL(vector.z, 3.7f);
}

BOOST_AUTO_TEST_CASE(Vector3_FromScalar)
{
    Vector3 vector = Vector3(2.2f);

    BOOST_CHECK_EQUAL(vector, Vector3(2.2f, 2.2f, 2.2f));
}

BOOST_AUTO_TEST_CASE(Vector3_FromValueVector)
{
    Vector3 vector = Vector3(1.0f, Vector2(2.0f, 3.0f));

    BOOST_CHECK_EQUAL(vector, Vector3(1.0f, 2.0f, 3.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_FromVectorValue)
{
    Vector3 vector = Vector3(Vector2(2.0f, 3.0f), 1.0f);

    BOOST_CHECK_EQUAL(vector, Vector3(2.0f, 3.0f, 1.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_FromVector4)
{
    Vector3 vector = Vector3::FromVector4(Vector4(1.0f, 2.0f, 3.0f, 4.0f));
    
    BOOST_CHECK_EQUAL(vector, Vector3(1.0f, 2.0f, 3.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_FromQuaternion)
{
    Vector3 vector = Vector3::FromQuaternion(Quaternion::Identity());

    BOOST_CHECK_EQUAL(vector, Vector3(0.0f, 0.0f, 0.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_UnsafeBracketsOperator)
{
    Vector3 vector = Vector3(5.4f, 2.6f, 3.7f);

    BOOST_CHECK_EQUAL(vector, Vector3(vector[0], vector[1], vector[2]));
}

BOOST_AUTO_TEST_CASE(Vector3_ChangingValueUsingUnsafeBracketsOperator)
{
    Vector3 vector = Vector3(5.4f, -1.1f, 3.0f);
    vector[0] = 1.2f;
    vector[1] /= -1.0f;
    vector[2] *= 1.5f;

    BOOST_CHECK_EQUAL(vector, Vector3(1.2f, 1.1f, 4.5f));
}

BOOST_AUTO_TEST_CASE(Vector3_ValueByIndex)
{
    Vector3 vector = Vector3(5.4f, 2.6f, 1.1f);

    BOOST_CHECK_EQUAL(vector, Vector3(vector.ValueByIndex(0), vector.ValueByIndex(1), vector.ValueByIndex(2)));
}

BOOST_AUTO_TEST_CASE(Vector3_ValueByIndexOutOfBounds)
{
    Vector3 vector = Vector3(5.4f, 2.6f, 1.1f);

    BOOST_CHECK_EQUAL(vector, Vector3(vector.ValueByIndex(0), vector.ValueByIndex(1), vector.ValueByIndex(2)));
}

BOOST_AUTO_TEST_CASE(Vector3_ChangingValueByIndex)
{
    Vector3 vector = Vector3(5.6f, 3.8f, 27.0f);
    vector.ValueByIndex(0) *= 0.5f;
    vector.ValueByIndex(1) *= 2.0f;
    vector.ValueByIndex(2) /= 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector3(2.8f, 7.6f, 9.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_ChangingValueByIndexOutOfBounds)
{
    Vector3 vector = Vector3(5.6f, 3.8f, 7.2);
    vector.ValueByIndex(128) = -1.0f;

    BOOST_CHECK_EQUAL(vector, Vector3(5.6f, 3.8f, -1.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_AddScalar)
{
    Vector3 vector = Vector3(1.0f, -2.0f, 3.0f);
    Vector3 result = vector + 3.0f;

    BOOST_CHECK_EQUAL(result, Vector3(4.0f, 1.0f, 6.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_AddVector)
{
    Vector3 vector = Vector3(5.0f, 6.0f, 4.0f);
    Vector3 result = vector + Vector3(3.0f, -4.5f, 4.2f);

    BOOST_CHECK_EQUAL(result, Vector3(8.0f, 1.5f, 8.2f));
}

BOOST_AUTO_TEST_CASE(Vector3_AddAssignScalar)
{
    Vector3 vector = Vector3(1.0f, -2.0f, 3.0f);
    vector += 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector3(4.0f, 1.0f, 6.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_AddAssignVector)
{
    Vector3 vector = Vector3(5.0f, 6.0f, 4.0f);
    vector += Vector3(3.0f, -4.5f, 4.2f);

    BOOST_CHECK_EQUAL(vector, Vector3(8.0f, 1.5f, 8.2f));
}

BOOST_AUTO_TEST_CASE(Vector3_SubtractScalar)
{
    Vector3 vector = Vector3(1.0f, -2.0f, 3.0f);
    Vector3 result = vector - 3.0f;

    BOOST_CHECK_EQUAL(result, Vector3(-2.0f, -5.0f, 0.0f));
}

BOOST_AUTO_TEST_CASE(Vector3_SubtractVector)
{
    Vector3 vector = Vector3(5.0f, 6.0f, 4.0f);
    Vector3 result = vector - Vector3(1.0f, -4.5f, 4.2f);

    BOOST_CHECK_EQUAL(result, Vector3(4.0f, 10.5f, -0.199999809f));
}

// BOOST_AUTO_TEST_CASE(Vector3_SubtractAssignScalar)
// {
//     Vector3 vector = Vector3(1.0f, -2.0f);
//     vector -= 3.0f;

//     BOOST_CHECK_EQUAL(vector, Vector3(-2.0f, -5.0f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_SubtractAssignVector)
// {
//     Vector3 vector = Vector3(5.0f, 6.0f);
//     vector -= Vector3(1.0f, -4.5f);

//     BOOST_CHECK_EQUAL(vector, Vector3(4.0f, 10.5f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_MultiplyByScalar)
// {
//     Vector3 vector = Vector3(1.0f, -2.0f);
//     Vector3 result = vector * 3.0f;

//     BOOST_CHECK_EQUAL(result, Vector3(3.0f, -6.0f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_MultiplyByVector)
// {
//     Vector3 vector = Vector3(5.0f, 6.0f);
//     Vector3 result = vector * Vector3(-1.0f, 4.5f);

//     BOOST_CHECK_EQUAL(result, Vector3(-5.0f, 27.0f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_MultiplyAssignByScalar)
// {
//     Vector3 vector = Vector3(1.0f, -2.0f);
//     vector *= 3.0f;

//     BOOST_CHECK_EQUAL(vector, Vector3(3.0f, -6.0f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_MultiplyAssignByVector)
// {
//     Vector3 vector = Vector3(5.0f, 6.0f);
//     vector *= Vector3(-1.0f, 4.5f);

//     BOOST_CHECK_EQUAL(vector, Vector3(-5.0f, 27.0f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_DivideByScalar)
// {
//     Vector3 vector = Vector3(1.0f, -2.0f);
//     Vector3 result = vector / 3.0f;

//     BOOST_CHECK_EQUAL(result, Vector3(0.333333343f, -0.666666687f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_DivideByVector)
// {
//     Vector3 vector = Vector3(5.0f, 6.0f);
//     Vector3 result = vector / Vector3(-1.0f, 4.5f);

//     BOOST_CHECK_EQUAL(result, Vector3(-5.0f, 1.33333337f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_DivideAssignByScalar)
// {
//     Vector3 vector = Vector3(1.0f, -2.0f);
//     vector /= 3.0f;

//     BOOST_CHECK_EQUAL(vector, Vector3(0.333333343f, -0.666666687f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_DivideAssignByVector)
// {
//     Vector3 vector = Vector3(5.0f, 6.0f);
//     vector /= Vector3(-1.0f, 4.5f);

//     BOOST_CHECK_EQUAL(vector, Vector3(-5.0f, 1.33333337f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_Negative)
// {
//     Vector3 vector = -Vector3(-1.0f, 5.3f);

//     BOOST_CHECK_EQUAL(vector, Vector3(1.0f, -5.3f));
// }

// BOOST_AUTO_TEST_CASE(Vector3_PrefixIncrement)
// {
//     IVector3 vector = IVector3(5, 1);
    
//     BOOST_CHECK_EQUAL(++vector, IVector3(6, 2));
// }

// BOOST_AUTO_TEST_CASE(Vector3_PrefixDecrement)
// {
//     IVector3 vector = IVector3(5, 1);
        
//     BOOST_CHECK_EQUAL(--vector, IVector3(4, 0));
// }

// BOOST_AUTO_TEST_CASE(Vector3_PostfixIncrement)
// {
//     IVector3 vector = IVector3(5, 1);
    
//     BOOST_CHECK_EQUAL(vector++, IVector3(5, 1));
//     BOOST_CHECK_EQUAL(vector, IVector3(6, 2));
// }

// BOOST_AUTO_TEST_CASE(Vector3_PostfixDecrement)
// {
//     IVector3 vector = IVector3(5, 1);
    
//     BOOST_CHECK_EQUAL(vector--, IVector3(5, 1));
//     BOOST_CHECK_EQUAL(vector, IVector3(4, 0));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_AndScalar)
// {
//     UVector3 vector = UVector3(2u, 4u);
//     UVector3 result = vector & 2u;

//     BOOST_CHECK_EQUAL(result, UVector3(2u, 0u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_AndVector)
// {
//     UVector3 vector = UVector3(4u, 1u);
//     UVector3 result = vector & UVector3(1u, 1u);

//     BOOST_CHECK_EQUAL(result, UVector3(0u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_AndAssignScalar)
// {
//     UVector3 vector = UVector3(3u, 7u);
//     vector &= 3u;

//     BOOST_CHECK_EQUAL(vector, UVector3(3u, 3u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_AndAssignVector)
// {
//     UVector3 vector = UVector3(9u, 3u);
//     vector &= UVector3(3u, 9u);

//     BOOST_CHECK_EQUAL (vector, UVector3(1u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_OrScalar)
// {
//     UVector3 vector = UVector3(2u, 4u);
//     UVector3 result = vector | 2u;

//     BOOST_CHECK_EQUAL(result, UVector3(2u, 6u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_OrVector)
// {
//     UVector3 vector = UVector3(4u, 1u);
//     UVector3 result = vector | UVector3(1u, 1u);

//     BOOST_CHECK_EQUAL(result, UVector3(5u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_OrAssignScalar)
// {
//     UVector3 vector = UVector3(3u, 7u);
//     vector |= 3u;

//     BOOST_CHECK_EQUAL(vector, UVector3(3u, 7u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_OrAssignVector)
// {
//     UVector3 vector = UVector3(9u, 3u);
//     vector |= UVector3(3u, 9u);

//     BOOST_CHECK_EQUAL (vector, UVector3(11u, 11u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_XorScalar)
// {
//     UVector3 vector = UVector3(2u, 4u);
//     UVector3 result = vector ^ 2u;

//     BOOST_CHECK_EQUAL(result, UVector3(0u, 6u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_XorVector)
// {
//     UVector3 vector = UVector3(4u, 1u);
//     UVector3 result = vector ^ UVector3(1u, 1u);

//     BOOST_CHECK_EQUAL(result, UVector3(5u, 0u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_XorAssignScalar)
// {
//     UVector3 vector = UVector3(3u, 7u);
//     vector ^= 3u;

//     BOOST_CHECK_EQUAL(vector, UVector3(0u, 4u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_XorAssignVector)
// {
//     UVector3 vector = UVector3(9, 3);
//     vector ^= UVector3(3, 9);

//     BOOST_CHECK_EQUAL (vector, UVector3(10, 10));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_RemainderScalar)
// {
//     UVector3 vector = UVector3(15u, 11u);
//     UVector3 result = vector % 10u;

//     BOOST_CHECK_EQUAL(result, UVector3(5u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_RemainderVector)
// {
//     UVector3 vector = UVector3(5u, 7u);
//     UVector3 result = vector % UVector3(5u, 3u);

//     BOOST_CHECK_EQUAL(result, UVector3(0u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_RemainderAssignScalar)
// {
//     UVector3 vector = UVector3(15u, 11u);
//     vector %= 10u;

//     BOOST_CHECK_EQUAL(vector, UVector3(5u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_RemainderAssignVector)
// {
//     UVector3 vector = UVector3(5u, 7u);
//     vector %= UVector3(5u, 3u);

//     BOOST_CHECK_EQUAL(vector, UVector3(0u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_Not)
// {
//     IVector3 vector = IVector3(14, 5);
//     IVector3 result = ~vector;

//     BOOST_CHECK_EQUAL(result, IVector3(-15, -6));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftLeftScalar)
// {
//     UVector3 vector = UVector3(2u, 3u);
//     UVector3 result = vector << 4u;

//     BOOST_CHECK_EQUAL(result, UVector3(32u, 48u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftLeftVector)
// {
//     UVector3 vector = UVector3(4u, 5u);
//     UVector3 result = vector << UVector3(1u, 2u);

//     BOOST_CHECK_EQUAL(result, UVector3(8u, 20u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftLeftAssignScalar)
// {
//     UVector3 vector = UVector3(2u, 3u);
//     vector <<= 4u;

//     BOOST_CHECK_EQUAL(vector, UVector3(32u, 48u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftLeftAssignVector)
// {
//     UVector3 vector = UVector3(4u, 5u);
//     vector <<= UVector3(1u, 2u);

//     BOOST_CHECK_EQUAL(vector, UVector3(8u, 20u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftRightScalar)
// {
//     UVector3 vector = UVector3(2u, 10u);
//     UVector3 result = vector >> 3u;

//     BOOST_CHECK_EQUAL(result, UVector3(0u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftRightVector)
// {
//     UVector3 vector = UVector3(17u, 26u);
//     UVector3 result = vector >> UVector3(4u, 2u);

//     BOOST_CHECK_EQUAL(result, UVector3(1u, 6u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftRightAssignScalar)
// {
//     UVector3 vector = UVector3(2u, 10u);
//     vector >>= 3u;

//     BOOST_CHECK_EQUAL(vector, UVector3(0u, 1u));
// }

// BOOST_AUTO_TEST_CASE(Bit_Vector3_ShiftRightAssignVector)
// {
//     UVector3 vector = UVector3(17u, 26u);
//     vector >>= UVector3(4u, 2u);

//     BOOST_CHECK_EQUAL(vector, UVector3(1u, 6u));
// }