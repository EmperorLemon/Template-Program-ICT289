#pragma once

#include "Vector.h"

typedef struct
{
    Vector3 position;
    Vector3 scale;
} Transform;

void TranslateV(const Vector3* pos);
