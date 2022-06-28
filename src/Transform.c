#include "../include/Transform.h"
#include <GL/freeglut.h>

void TranslateV(const Vector3* pos)
{
    glTranslatef(pos->x, pos->y, pos->z);
}

void RotateV(const Vector3* rot)
{
    glRotatef(rot->x,1,0,0);
    glRotatef(rot->y,0,1,0);
    glRotatef(rot->z,0,0,1);
}

void ScaleV(const float scale)
{
    glScalef(scale, scale, scale);
}
