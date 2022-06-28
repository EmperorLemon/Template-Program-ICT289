#include "../include/Camera.h"
#include <GL/freeglut.h>
#include <math.h>

void InitCamera(Camera* camera)
{
    camera->view_angle.x = 0;
    camera->view_angle.y = 0;

    camera->look_speed = 0.001;
    camera->move_speed = 0.05;

    camera->position = (Vector3){0,5,12};
    camera->front = (Vector3){0,0,-1};
    camera->up = (Vector3){0,1,0};
    camera->right = cross(&camera->front, &camera->right);
    camera->right = norm(&camera->right);

    camera->perspective.fov = 70;
    camera->perspective.aspect = 1;
    camera->perspective.nearVal = 0.01;
    camera->perspective.farVal = 100.0;
}

void UpdateCamera(Camera* camera)
{
    gluLookAt(camera->position.x, camera->position.y, camera->position.z,
              camera->position.x + camera->front.x,
              camera->position.y + camera->front.y,
              camera->position.z + camera->front.z,
              camera->up.x, camera->up.y, camera->up.z);
}

void LookAt(Camera* camera, const Vector3* toLook)
{
    Vector3 offset = (Vector3){0,5,10};
    camera->front = subtract(toLook, &offset);
}

void UpdateLookDir(Camera* camera)
{
    camera->front.x = sin(camera->view_angle.x);
    camera->front.y = sin(camera->view_angle.y);
    camera->front.z = -cos(camera->view_angle.x);
}
