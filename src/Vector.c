#include "../include/Vector.h"
#include <math.h>
#include <stdio.h>

Vector3 one()
{
    return (Vector3)
    {
        1,1,1
    };
}

Vector3 zero()
{
    return (Vector3)
    {
        0,0,0
    };
}

float getMag(const Vector3* u)
{
    return sqrt(getMagSqr(u));
}

float getMagSqr(const Vector3* u)
{
    return u->x * u->x + u->y * u->y + u->z * u->z;
}

Vector3 neg(const Vector3* u)
{
    return multiply(u, -1);
}

Vector3 add(const Vector3* u, const Vector3* v)
{
    return (Vector3)
    {
        u->x + v->x, u->y + v->y, u->z + v->z
    };
}

Vector3 subtract(const Vector3* u, const Vector3* v)
{
    return (Vector3)
    {
        u->x - v->x, u->y - v->y, u->z - v->z
    };
}

Vector3 multiply(const Vector3* u, const float t)
{
    return (Vector3)
    {
        u->x * t, u->y * t, u->z * t
    };
}

Vector3 divide(const Vector3* u, const float t)
{
    if ((int)t != 0)
        return (Vector3){u->x / t, u->y / t, u->z / t};

    return *u;
}

Vector3 cross(const Vector3* u, const Vector3* v)
{
    return (Vector3)
    {
        u->y * v->z - u->z * v->y,
        u->z * v->x - u->x * v->z,
        u->x * v->y - u->y * v->x
    };
}

Vector3 norm(const Vector3* u)
{
    return divide(u, getMag(u));
}
