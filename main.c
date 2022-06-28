#include <stdio.h>
#include <GL/freeglut.h>
#include "./include/Scene.h"

void init();
void animate();
void reshape(int w, int h);
void display();

const int WIDTH = 800;
const int HEIGHT = 600;

#define TARGET_FPS 1000/60

void init()
{
    glClearColor(0,0,0,0);
    glLineWidth(2);

    CreateScene();

    glutPassiveMotionFunc(mouse_motion);
    glutKeyboardFunc(keyboard_down);
    glutKeyboardUpFunc(keyboard_up);
    glutSpecialFunc(arrow_keys);

    StartTime(&time);

    glutTimerFunc(TARGET_FPS, animate, 0);
}

void animate()
{
    glutTimerFunc(TARGET_FPS, animate, 0);

    UpdateTime(&time);
    UpdateRigidbodies(time.deltaTime);
    UpdateCollisions();
    ResetTime(&time);

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (h != 0)
        cam.perspective.aspect = (GLfloat) w / (GLfloat) h;
    else
        cam.perspective.aspect = (GLfloat) w / (GLfloat) 1;

    gluPerspective(cam.perspective.fov, cam.perspective.aspect, cam.perspective.nearVal, cam.perspective.farVal);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    UpdateCamera(&cam);

    DrawAxes();
    DefineLight(&light);
    UpdateLight(&light);

    DrawObjects();

    glDisable(GL_LIGHTING);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(1100,10);
    glutCreateWindow("Template Program");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    EndScene();
    return 0;
}
