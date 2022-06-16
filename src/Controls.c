#include "../include/Controls.h"
#include "../include/Scene.h"
#include <GL/freeglut.h>

void keyboard_down(unsigned char key, int x, int y)
{
    x = y = x;

    switch (key)
    {
    case 'W': case 'w':
        break;
    case 'A': case 'a':
        break;
    case 'S': case 's':
        break;
    case 'D': case 'd':
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
    x = y = x;

    switch (key)
    {
    case 'W': case 'w':
        break;
    case 'A': case 'a':
        break;
    case 'S': case 's':
        break;
    case 'D': case 'd':
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void mouse_motion(int x, int y)
{
    int centerX = (glutGet(GLUT_WINDOW_WIDTH) / 2);
    int centerY = (glutGet(GLUT_WINDOW_HEIGHT) / 2);

    int lastX = centerX;
    int lastY = centerY;

    float offsetX = x - lastX;
    float offsetY = lastY - y;

    cam.view_angle.x += offsetX;
    cam.view_angle.y += offsetY;

    if (x != centerX || y != centerY) glutWarpPointer(centerX, centerY);

    glutPostRedisplay();
}

void mouse_action(int button, int state, int x, int y)
{
    x = y = x;
}
