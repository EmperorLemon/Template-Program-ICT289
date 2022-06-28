#pragma once

#include "Vector.h"

typedef struct
{
    float fov, aspect, nearVal, farVal;
}Perspective;

typedef struct
{
    int FORWARD,BACKWARD,LEFT,RIGHT;
}MOTION;

typedef struct
{
    Vector3 position;
    Vector3 front;
    Vector3 up;
    Vector3 right;
    Perspective perspective;
    Vector2 view_angle;

    float move_speed;
    float look_speed;
} Camera;

Camera cam;
MOTION motion;
void InitCamera(Camera* camera);
void UpdateCamera(Camera* camera);
void LookAt(Camera* camera, const Vector3* toLook);
void UpdateLookDir(Camera* camera);
