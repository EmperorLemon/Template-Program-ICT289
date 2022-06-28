#pragma once

typedef float Point4[4];

typedef struct
{
    Point4* data;
}Matrix;

void IdentityMatrix(Matrix* m);

void RotationX(Matrix* m, const float angle);
void RotationY(Matrix* m, const float angle);
void RotationZ(Matrix* m, const float angle);
