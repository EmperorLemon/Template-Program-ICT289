#pragma once

#include "Vector.h"

typedef struct
{
    float fov, aspect, nearVal, farVal;
}Perspective;

typedef struct
{
    Vector3 position;
    Vector3 front;
    Vector3 up;
    Vector3 right;
    Perspective perspective;
    Vector2 view_angle;
} Camera;

Camera cam;
void InitCamera(Camera* camera);
void UpdateCamera(Camera* camera);
