#pragma once

#include "Vector.h"
#include "Matrix.h"

typedef struct
{
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
} Transform;

void TranslateV(const Vector3* pos);
void RotateV(const Vector3* rot);
void ScaleV(const float scale);
