#include "../include/Scene.h"
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

void DrawAxes()
{
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(50,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,50,0);

    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,50);
    glEnd();

    glColor3f(1,1,1);
}

void CreateScene()
{
    glutSetCursor(GLUT_CURSOR_NONE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    CreateCamera();
    SetLight(&light);
    LoadObjects();
}

void CreateCamera()
{
    InitCamera(&cam);
}

void LoadObjects()
{
    OBJECT_COUNT = 0;

    objectList = CreateList();

    AddObject(GenerateObject("sphere"), objectList);
    AddObject(GenerateObject("plane"), objectList);
    AddObject(GenerateObject("sphere"), objectList);

    OBJECT_COUNT = Size(objectList);

    TweakObjects();
}

void DrawObjects()
{
    for (int i = 0; i < OBJECT_COUNT; i++)
        UpdateObject(&objectArray[i]);
}

void UpdateRigidbodies(float deltaTime)
{
    for (int i = 0; i < OBJECT_COUNT; i++)
        UpdatePhysics(&objectArray[i].rigidbody, &objectArray[i].transform, deltaTime);
}

void UpdateCollisions()
{
    if (SpherePlaneDetection(&objectArray[0].rigidbody, &objectArray[1].rigidbody))
        SpherePlaneResponse(&objectArray[0].rigidbody, &objectArray[1].rigidbody);

    if (SpherePlaneDetection(&objectArray[2].rigidbody, &objectArray[1].rigidbody))
        SpherePlaneResponse(&objectArray[2].rigidbody, &objectArray[1].rigidbody);

    if (SphereSphereDetection(&objectArray[0].rigidbody, &objectArray[2].rigidbody))
        SphereSphereResponse(&objectArray[0].rigidbody, &objectArray[2].rigidbody);
}

void ResetObjects()
{
    for (int i = 0; i < OBJECT_COUNT; i++)
    {
        if (objectArray[i].rigidbody.collider.MODE == SPHERE)
        {
            objectArray[0].transform.position = (Vector3){0,6,0};
            objectArray[0].rigidbody.velocity = zero();
            objectArray[2].transform.position = (Vector3){0,3,0};
            objectArray[2].rigidbody.velocity = zero();
        }
    }
}

//void PrintVector(const Vector3* v)
//{
//    printf("(%f,%f,%f)\n", v->x, v->y, v->z);
//}

void EndScene()
{
    DestroyList(objectList);
    DestroyObjects();
    free(objectArray);
}

