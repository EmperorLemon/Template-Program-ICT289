#include "../include/Camera.h"
#include <GL/freeglut.h>
#include <math.h>

void InitCamera(Camera* camera)
{
    camera->position = (Vector3){0,0,5};
    camera->front = (Vector3){0,0,-1};
    camera->up = (Vector3){0,1,0};
    camera->right = cross(&camera->front, &camera->right);

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
