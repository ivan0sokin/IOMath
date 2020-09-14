#define BOOST_TEST_MODULE TestVector2
#include <boost/test/included/unit_test.hpp>

#include "../src/Vector2.hpp"
#include "../src/Vector3.hpp"
#include "../src/Vector4.hpp"
#include "../src/Quaternion.hpp"

#include "internal/PrintTVector2.hpp"

using namespace IOMath;

BOOST_AUTO_TEST_CASE(Vector2_DefaultConstructor)
{
    Vector2 vector = Vector2();

    BOOST_CHECK_EQUAL(vector, Vector2(0.0f, 0.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_Constructor)
{
    Vector2 vector = Vector2(1.0f, 2.7f);

    BOOST_CHECK_EQUAL(vector.x, 1.0f);
    BOOST_CHECK_EQUAL(vector.y, 2.7f);
}

BOOST_AUTO_TEST_CASE(Vector2_FromScalar)
{
    Vector2 vector = Vector2(2.2f);

    BOOST_CHECK_EQUAL(vector, Vector2(2.2f, 2.2f));
}

BOOST_AUTO_TEST_CASE(Vector2_FromVector3)
{
    Vector2 vector = Vector2::FromVector3(Vector3(1.0f, 2.0f, 3.0f));
    
    BOOST_CHECK_EQUAL(vector, Vector2(1.0f, 2.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_FromVector4)
{
    Vector2 vector = Vector2::FromVector4(Vector4(1.0f, 2.0f, 3.0f, 4.0f));
    
    BOOST_CHECK_EQUAL(vector, Vector2(1.0f, 2.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_FromQuaternion)
{
    Vector2 vector = Vector2::FromQuaternion(Quaternion::Identity());

    BOOST_CHECK_EQUAL(vector, Vector2(0.0f, 0.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_UnsafeBracketsOperator)
{
    Vector2 vector = Vector2(5.4f, 2.6f);

    BOOST_CHECK_EQUAL(vector, Vector2(vector[0], vector[1]));
}

BOOST_AUTO_TEST_CASE(Vector2_ChangingValueUsingUnsafeBracketsOperator)
{
    Vector2 vector = Vector2(5.4f, -1.1f);
    vector[0] = 1.2f;
    vector[1] /= -1.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(1.2f, 1.1f));
}

BOOST_AUTO_TEST_CASE(Vector2_ValueByIndex)
{
    Vector2 vector = Vector2(5.4f, 2.6f);

    BOOST_CHECK_EQUAL(vector, Vector2(vector.ValueByIndex(0), vector.ValueByIndex(1)));
}

BOOST_AUTO_TEST_CASE(Vector2_ValueByIndexOutOfBounds)
{
    Vector2 vector = Vector2(5.4f, 2.6f);

    BOOST_CHECK_EQUAL(vector, Vector2(vector.ValueByIndex(0), vector.ValueByIndex(256)));
}

BOOST_AUTO_TEST_CASE(Vector2_ChangingValueByIndex)
{
    Vector2 vector = Vector2(5.6f, 3.8f);
    vector.ValueByIndex(0) *= 0.5f;
    vector.ValueByIndex(1) *= 2.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(2.8f, 7.6f));
}

BOOST_AUTO_TEST_CASE(Vector2_ChangingValueByIndexOutOfBounds)
{
    Vector2 vector = Vector2(5.6f, 3.8f);
    vector.ValueByIndex(0) *= 0.5f;
    vector.ValueByIndex(256) *= 2.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(2.8f, 7.6f));
}

BOOST_AUTO_TEST_CASE(Vector2_AddScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector + 3.0f;

    BOOST_CHECK_EQUAL(result, Vector2(4.0f, 1.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_AddVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector + Vector2(3.0f, -4.5f);

    BOOST_CHECK_EQUAL(result, Vector2(8.0f, 1.5f));
}

BOOST_AUTO_TEST_CASE(Vector2_AddAssignScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector += 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(4.0f, 1.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_AddAssignVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector += Vector2(3.0f, -4.5f);

    BOOST_CHECK_EQUAL(vector, Vector2(8.0f, 1.5f));
}

BOOST_AUTO_TEST_CASE(Vector2_SubtractScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector - 3.0f;

    BOOST_CHECK_EQUAL(result, Vector2(-2.0f, -5.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_SubtractVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector - Vector2(1.0f, -4.5f);

    BOOST_CHECK_EQUAL(result, Vector2(4.0f, 10.5f));
}

BOOST_AUTO_TEST_CASE(Vector2_SubtractAssignScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector -= 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(-2.0f, -5.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_SubtractAssignVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector -= Vector2(1.0f, -4.5f);

    BOOST_CHECK_EQUAL(vector, Vector2(4.0f, 10.5f));
}

BOOST_AUTO_TEST_CASE(Vector2_MultiplyByScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector * 3.0f;

    BOOST_CHECK_EQUAL(result, Vector2(3.0f, -6.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_MultiplyByVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector * Vector2(-1.0f, 4.5f);

    BOOST_CHECK_EQUAL(result, Vector2(-5.0f, 27.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_MultiplyAssignByScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector *= 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(3.0f, -6.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_MultiplyAssignByVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector *= Vector2(-1.0f, 4.5f);

    BOOST_CHECK_EQUAL(vector, Vector2(-5.0f, 27.0f));
}

BOOST_AUTO_TEST_CASE(Vector2_DivideByScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector / 3.0f;

    BOOST_CHECK_EQUAL(result, Vector2(0.333333343f, -0.666666687f));
}

BOOST_AUTO_TEST_CASE(Vector2_DivideByVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector / Vector2(-1.0f, 4.5f);

    BOOST_CHECK_EQUAL(result, Vector2(-5.0f, 1.33333337f));
}

BOOST_AUTO_TEST_CASE(Vector2_DivideAssignByScalar)
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector /= 3.0f;

    BOOST_CHECK_EQUAL(vector, Vector2(0.333333343f, -0.666666687f));
}

BOOST_AUTO_TEST_CASE(Vector2_DivideAssignByVector)
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector /= Vector2(-1.0f, 4.5f);

    BOOST_CHECK_EQUAL(vector, Vector2(-5.0f, 1.33333337f));
}

BOOST_AUTO_TEST_CASE(Vector2_Negative)
{
    Vector2 vector = -Vector2(-1.0f, 5.3f);

    BOOST_CHECK_EQUAL(vector, Vector2(1.0f, -5.3f));
}

BOOST_AUTO_TEST_CASE(Vector2_PrefixIncrement)
{
    IVector2 vector = IVector2(5, 1);
    
    BOOST_CHECK_EQUAL(++vector, IVector2(6, 2));
}

BOOST_AUTO_TEST_CASE(Vector2_PrefixDecrement)
{
    IVector2 vector = IVector2(5, 1);
        
    BOOST_CHECK_EQUAL(--vector, IVector2(4, 0));
}

BOOST_AUTO_TEST_CASE(Vector2_PostfixIncrement)
{
    IVector2 vector = IVector2(5, 1);
    
    BOOST_CHECK_EQUAL(vector++, IVector2(5, 1));
    BOOST_CHECK_EQUAL(vector, IVector2(6, 2));
}

BOOST_AUTO_TEST_CASE(Vector2_PostfixDecrement)
{
    IVector2 vector = IVector2(5, 1);
    
    BOOST_CHECK_EQUAL(vector--, IVector2(5, 1));
    BOOST_CHECK_EQUAL(vector, IVector2(4, 0));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_AndScalar)
{
    UVector2 vector = UVector2(2u, 4u);
    UVector2 result = vector & 2u;

    BOOST_CHECK_EQUAL(result, UVector2(2u, 0u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_AndVector)
{
    UVector2 vector = UVector2(4u, 1u);
    UVector2 result = vector & UVector2(1u, 1u);

    BOOST_CHECK_EQUAL(result, UVector2(0u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_AndAssignScalar)
{
    UVector2 vector = UVector2(3u, 7u);
    vector &= 3u;

    BOOST_CHECK_EQUAL(vector, UVector2(3u, 3u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_AndAssignVector)
{
    UVector2 vector = UVector2(9u, 3u);
    vector &= UVector2(3u, 9u);

    BOOST_CHECK_EQUAL (vector, UVector2(1u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_OrScalar)
{
    UVector2 vector = UVector2(2u, 4u);
    UVector2 result = vector | 2u;

    BOOST_CHECK_EQUAL(result, UVector2(2u, 6u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_OrVector)
{
    UVector2 vector = UVector2(4u, 1u);
    UVector2 result = vector | UVector2(1u, 1u);

    BOOST_CHECK_EQUAL(result, UVector2(5u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_OrAssignScalar)
{
    UVector2 vector = UVector2(3u, 7u);
    vector |= 3u;

    BOOST_CHECK_EQUAL(vector, UVector2(3u, 7u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_OrAssignVector)
{
    UVector2 vector = UVector2(9u, 3u);
    vector |= UVector2(3u, 9u);

    BOOST_CHECK_EQUAL (vector, UVector2(11u, 11u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_XorScalar)
{
    UVector2 vector = UVector2(2u, 4u);
    UVector2 result = vector ^ 2u;

    BOOST_CHECK_EQUAL(result, UVector2(0u, 6u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_XorVector)
{
    UVector2 vector = UVector2(4u, 1u);
    UVector2 result = vector ^ UVector2(1u, 1u);

    BOOST_CHECK_EQUAL(result, UVector2(5u, 0u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_XorAssignScalar)
{
    UVector2 vector = UVector2(3u, 7u);
    vector ^= 3u;

    BOOST_CHECK_EQUAL(vector, UVector2(0u, 4u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_XorAssignVector)
{
    UVector2 vector = UVector2(9, 3);
    vector ^= UVector2(3, 9);

    BOOST_CHECK_EQUAL (vector, UVector2(10, 10));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_RemainderScalar)
{
    UVector2 vector = UVector2(15u, 11u);
    UVector2 result = vector % 10u;

    BOOST_CHECK_EQUAL(result, UVector2(5u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_RemainderVector)
{
    UVector2 vector = UVector2(5u, 7u);
    UVector2 result = vector % UVector2(5u, 3u);

    BOOST_CHECK_EQUAL(result, UVector2(0u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_RemainderAssignScalar)
{
    UVector2 vector = UVector2(15u, 11u);
    vector %= 10u;

    BOOST_CHECK_EQUAL(vector, UVector2(5u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_RemainderAssignVector)
{
    UVector2 vector = UVector2(5u, 7u);
    vector %= UVector2(5u, 3u);

    BOOST_CHECK_EQUAL(vector, UVector2(0u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_Not)
{
    IVector2 vector = IVector2(14, 5);
    IVector2 result = ~vector;

    BOOST_CHECK_EQUAL(result, IVector2(-15, -6));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftLeftScalar)
{
    UVector2 vector = UVector2(2u, 3u);
    UVector2 result = vector << 4u;

    BOOST_CHECK_EQUAL(result, UVector2(32u, 48u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftLeftVector)
{
    UVector2 vector = UVector2(4u, 5u);
    UVector2 result = vector << UVector2(1u, 2u);

    BOOST_CHECK_EQUAL(result, UVector2(8u, 20u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftLeftAssignScalar)
{
    UVector2 vector = UVector2(2u, 3u);
    vector <<= 4u;

    BOOST_CHECK_EQUAL(vector, UVector2(32u, 48u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftLeftAssignVector)
{
    UVector2 vector = UVector2(4u, 5u);
    vector <<= UVector2(1u, 2u);

    BOOST_CHECK_EQUAL(vector, UVector2(8u, 20u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftRightScalar)
{
    UVector2 vector = UVector2(2u, 10u);
    UVector2 result = vector >> 3u;

    BOOST_CHECK_EQUAL(result, UVector2(0u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftRightVector)
{
    UVector2 vector = UVector2(17u, 26u);
    UVector2 result = vector >> UVector2(4u, 2u);

    BOOST_CHECK_EQUAL(result, UVector2(1u, 6u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftRightAssignScalar)
{
    UVector2 vector = UVector2(2u, 10u);
    vector >>= 3u;

    BOOST_CHECK_EQUAL(vector, UVector2(0u, 1u));
}

BOOST_AUTO_TEST_CASE(Bit_Vector2_ShiftRightAssignVector)
{
    UVector2 vector = UVector2(17u, 26u);
    vector >>= UVector2(4u, 2u);

    BOOST_CHECK_EQUAL(vector, UVector2(1u, 6u));
}