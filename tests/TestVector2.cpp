#include "../src/Vector2.hpp"
#include "../src/Vector3.hpp"
#include "../src/Vector4.hpp"
#include "../src/Quaternion.hpp"

using namespace IOMath;

void Vector2_DefaultConstructor()
{
    Vector2 vector = Vector2();

    assert(vector == Vector2(0.0f, 0.0f));
}

void Vector2_Constructor()
{
    Vector2 vector = Vector2(1.0f, 2.7f);

    assert(vector.x == 1.0f); assert(vector.y == 2.7f);
}

void Vector2_FromScalar()
{
    Vector2 vector = Vector2(2.2f);

    assert(vector == Vector2(2.2f, 2.2f));
}

void Vector2_FromVector3()
{
    Vector2 vector = Vector2::FromVector3(Vector3(1.0f, 2.0f, 3.0f));
    
    assert(vector == Vector2(1.0f, 2.0f));
}

void Vector2_FromVector4()
{
    Vector2 vector = Vector2::FromVector4(Vector4(1.0f, 2.0f, 3.0f, 4.0f));
    
    assert(vector == Vector2(1.0f, 2.0f));
}

void Vector2_FromQuaternion()
{
    Vector2 vector = Vector2::FromQuaternion(Quaternion::Identity());

    assert(vector == Vector2(0.0f, 0.0f));
}

void Vector2_Index()
{
    Vector2 vector = Vector2(5.4f, 2.6f);

    assert(vector == Vector2(vector[0], vector[1]));
}

void Vector2_ChangingValueByIndex()
{
    Vector2 vector = Vector2(5.4f, -1.1f);
    vector[0] = 1.2f;
    vector[1] /= -1.0f;

    assert(vector == Vector2(1.2f, 1.1f));
}

void Vector2_AddScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector + 3.0f;

    assert(result == Vector2(4.0f, 1.0f));
}

void Vector2_AddVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector + Vector2(3.0f, -4.5f);

    assert(result == Vector2(8.0f, 1.5f));
}

void Vector2_AddAssignScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector += 3.0f;

    assert(vector == Vector2(4.0f, 1.0f));
}

void Vector2_AddAssignVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector += Vector2(3.0f, -4.5f);

    assert(vector == Vector2(8.0f, 1.5f));
}

void Vector2_SubtractScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector - 3.0f;

    assert(result == Vector2(-2.0f, -5.0f));
}

void Vector2_SubtractVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector - Vector2(1.0f, -4.5f);

    assert(result == Vector2(4.0f, 10.5f));
}

void Vector2_SubtractAssignScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector -= 3.0f;

    assert(vector == Vector2(-2.0f, -5.0f));
}

void Vector2_SubtractAssignVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector -= Vector2(1.0f, -4.5f);

    assert(vector == Vector2(4.0f, 10.5f));
}

void Vector2_MultiplyByScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector * 3.0f;

    assert(result == Vector2(3.0f, -6.0f));
}

void Vector2_MultiplyByVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector * Vector2(-1.0f, 4.5f);

    assert(result == Vector2(-5.0f, 27.0f));
}

void Vector2_MultiplyAssignByScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector *= 3.0f;

    assert(vector == Vector2(3.0f, -6.0f));
}

void Vector2_MultiplyAssignByVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector *= Vector2(-1.0f, 4.5f);

    assert(vector == Vector2(-5.0f, 27.0f));
}

void Vector2_DivideByScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    Vector2 result = vector / 3.0f;

    assert(result == Vector2(0.3333333432674407958984375f, -0.666666686534881591796875f));
}

void Vector2_DivideByVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    Vector2 result = vector / Vector2(-1.0f, 4.5f);

    assert(result == Vector2(-5.0f, 1.33333337306976318359375f));
}

void Vector2_DivideAssignByScalar()
{
    Vector2 vector = Vector2(1.0f, -2.0f);
    vector /= 3.0f;

    assert(vector == Vector2(0.3333333432674407958984375f, -0.666666686534881591796875f));
}

void Vector2_DivideAssignByVector()
{
    Vector2 vector = Vector2(5.0f, 6.0f);
    vector /= Vector2(-1.0f, 4.5f);

    assert(vector == Vector2(-5.0f, 1.33333337306976318359375f));
}

void Vector2_Negative()
{
    Vector2 vector = -Vector2(-1.0f, 5.3f);

    assert(vector == Vector2(1.0f, -5.3f));
}

void Vector2_PrefixIncrement()
{
    Vector2 vector = Vector2(5.5f, 1.3f);
    
    assert(++vector == Vector2(6.5f, 2.3f));
}

void Vector2_PrefixDecrement()
{
    Vector2 vector = Vector2(5.5f, 1.3f);
        
    assert(--vector == Vector2(4.5f, 0.2999999523162841796875));
}

void Vector2_PostfixIncrement()
{
    Vector2 vector = Vector2(5.5f, 1.3f);
    
    assert(vector++ == Vector2(5.5f, 1.3f));
    assert(vector == Vector2(6.5f, 2.3f));
}

void Vector2_PostifxDecrement()
{
    Vector2 vector = Vector2(5.5f, 1.3f);
    
    assert(vector-- == Vector2(5.5f, 1.3f));
    assert(vector == Vector2(4.5f, 0.2999999523162841796875));
}

int main(int, char**)
{
    Vector2_DefaultConstructor();
    Vector2_Constructor();
    Vector2_FromScalar();
    Vector2_FromVector3();
    Vector2_FromVector4();
    Vector2_FromQuaternion();
    Vector2_Index();
    Vector2_ChangingValueByIndex();
    Vector2_AddScalar();
    Vector2_AddVector();
    Vector2_AddAssignScalar();
    Vector2_AddAssignVector();
    Vector2_SubtractScalar();
    Vector2_SubtractVector();
    Vector2_SubtractAssignScalar();
    Vector2_SubtractAssignVector();
    Vector2_MultiplyByScalar();
    Vector2_MultiplyByVector();
    Vector2_MultiplyAssignByScalar();
    Vector2_MultiplyAssignByVector();
    Vector2_DivideByScalar();
    Vector2_DivideByVector();
    Vector2_DivideAssignByScalar();
    Vector2_DivideAssignByVector();
    Vector2_Negative();
    Vector2_PrefixIncrement();
    Vector2_PrefixDecrement();
    Vector2_PostfixIncrement();
    Vector2_PostifxDecrement();

    return 0;
}