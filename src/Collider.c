#include "../include/Collider.h"
#include <GL/freeglut.h>

void DrawBoundingSphere(const float radius)
{
    glPushMatrix();

    glColor3f(0,1,0);

    glutWireSphere(radius,16,16);

    glPopMatrix();
}

Vector3 GetCentre(const Mesh* m)
{
    Vector3 centre = {0,0,0};

    for (int i = 0; i < m->nverts; i++)
        centre = add(&centre, &m->verts[i]);

    return scalarDivide(&centre, m->nverts);
}

float GetSphereRadius(const Mesh* m, const Vector3* centre)
{
    float radius = 0;

    float magArr[m->nverts];

    for (int i = 0; i < m->nverts; i++)
    {
        radius = magArr[0];
        Vector3 difference = subtract(&m->verts[i], centre);

        magArr[i] = getMag(&difference);

        if (magArr[i] > radius)
            radius = magArr[i];
    }

    return radius;
}
