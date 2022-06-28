#include "../include/Lighting.h"
#include <GL/freeglut.h>

void SetLight(Light* _light)
{
    _light->light_position[0] = 0; // x
    _light->light_position[1] = 10; // y
    _light->light_position[2] = 0; // z
    _light->light_position[3] = 1; // w

    _light->spot_direction[0] = 0; // x
    _light->spot_direction[1] = -5; // y
    _light->spot_direction[2] = 0;  // z
    _light->spot_direction[3] = 1;  // w
}

void DefineLight(const Light* _light)
{
    glEnable(GL_LIGHT0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2);

    //DrawSpotlight(_light);
    glEnable(GL_LIGHTING);
}

// Debug
void DrawSpotlight(const Light* _light)
{
    glColor3f(1,1,0);
    glPointSize(25);

    glBegin(GL_POINTS);
        glVertex3f(_light->light_position[0], _light->light_position[1], _light->light_position[2]);
    glEnd();

    glBegin(GL_LINES);
        glVertex3fv(_light->light_position);
        glVertex3f(_light->light_position[0] + _light->spot_direction[0] * 100,
                   _light->light_position[1] + _light->spot_direction[1] * 100,
                   _light->light_position[2] + _light->spot_direction[2] * 100);
    glEnd();
}

void UpdateLight(const Light* _light)
{
    glPushMatrix();
        glLightfv(GL_LIGHT0, GL_POSITION, _light->light_position);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, _light->spot_direction);
    glPopMatrix();
}
