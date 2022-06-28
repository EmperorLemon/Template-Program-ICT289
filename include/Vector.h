#pragma once

typedef struct
{
    float x,y,z,w;
}Vector4;

typedef struct
{
    float x,y,z;
} Vector3;

typedef struct
{
    float x,y;
}Vector2;

Vector3 one();
Vector3 zero();

Vector3 neg(const Vector3* u);

Vector3 cross(const Vector3* u, const Vector3* v);
float dot(const Vector3* u, const Vector3* v);

Vector3 add(const Vector3* u, const Vector3* v);
Vector3 subtract(const Vector3* u, const Vector3* v);

Vector3 scalarMultiply(const Vector3* u, const float t);
Vector3 scalarDivide(const Vector3* u, const float t);

Vector3 norm(const Vector3* u);

Vector3 reflect(const Vector3* v, const Vector3* n);
Vector3 project(const Vector3* u, const Vector3* v);

float getMagSqr(const Vector3* u);
float getMag(const Vector3* u);
