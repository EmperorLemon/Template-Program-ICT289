#pragma once

#include "Collider.h"
#include "Transform.h"

typedef struct
{
    Vector3 centre;

    Vector3 acceleration;
    Vector3 force;
    Vector3 velocity;

    Transform transform;

    Collider collider;

    float mass;
    float bounciness;

    int isStatic;
} Rigidbody;
