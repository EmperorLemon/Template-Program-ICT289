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
    glEnable(GL_DEPTH_TEST);

    CreateCamera();
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
}

void EndScene()
{
    DestroyList(objectList);
    DestroyObjects();
    free(objectArray);
}

