#include "../include/Controls.h"
#include "../include/Scene.h"
#include <GL/freeglut.h>

void Stare();

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
    case 'c':
        glutIdleFunc(Stare);
        break;
    case 'C':
        glutIdleFunc(NULL);
        break;
    case 'r': case 'R':
        ResetObjects();
        break;
    case 'Z':
        objectArray[0].rigidbody.collider.radius += 0.01;
        break;
    case 'z':
        objectArray[0].rigidbody.collider.radius -= 0.01;
        break;
    case 'Q': case 'q':
        exit(0);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void Stare()
{
    LookAt(&cam, &objectArray[0].transform.position);
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

void arrow_keys(int key, int x, int y)
{
    x = y = x;

    if (key == GLUT_KEY_UP)
        RotateX(&objectArray[1].mesh, 0.05);
    if (key == GLUT_KEY_DOWN)
        RotateX(&objectArray[1].mesh, -0.05);
    if (key == GLUT_KEY_LEFT)
        RotateZ(&objectArray[1].mesh, 0.05);
    if (key == GLUT_KEY_RIGHT)
        RotateZ(&objectArray[1].mesh, -0.05);

    glutPostRedisplay();
}

void mouse_motion(int x, int y)
{
    int centerX = (glutGet(GLUT_WINDOW_WIDTH) / 2);
    int centerY = (glutGet(GLUT_WINDOW_HEIGHT) / 2);

    int lastX = centerX;
    int lastY = centerY;

    Vector2 offset = (Vector2){(x - lastX) * cam.look_speed, (lastY - y) * cam.look_speed};

    cam.view_angle.x += offset.x;
    cam.view_angle.y += offset.y;

    if (x != centerX || y != centerY) glutWarpPointer(centerX, centerY);

    UpdateLookDir(&cam);

    glutPostRedisplay();
}

void mouse_action(int button, int state, int x, int y)
{
    x = y = x;
}
