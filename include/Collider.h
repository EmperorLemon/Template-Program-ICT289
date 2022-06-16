#pragma once

#include "Vector.h"
#include "Mesh.h"

typedef enum
{
    PLANE,SPHERE
} Collider_Mode;

typedef struct
{
    Collider_Mode MODE;
    float radius;
    Vector3 point, normal;
} Collider;

void DrawBoundingSphere(const float radius);
Vector3 GetCentre(const Mesh* m);
float GetSphereRadius(const Mesh* m, const Vector3* centre);
