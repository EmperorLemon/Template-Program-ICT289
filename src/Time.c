#include "../include/Time.h"
#include <GL/freeglut.h>

void StartTime(Time* t)
{
    t->curTime = glutGet(GLUT_ELAPSED_TIME);
}

void UpdateTime(Time* t)
{
    t->curTime = glutGet(GLUT_ELAPSED_TIME);
    t->deltaTime = (float) (t->curTime - t->prevTime) / 1000.0f;
    t->prevTime = t->curTime;
}
