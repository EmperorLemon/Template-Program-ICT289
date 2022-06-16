#include "../include/Transform.h"
#include <GL/freeglut.h>

void TranslateV(const Vector3 pos)
{
    glTranslatef(pos.x, pos.y, pos.z);
}
