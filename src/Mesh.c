#include "../include/Mesh.h"
#include <GL/freeglut.h>

void DrawMesh(const Mesh* m)
{
    glColor3f(m->color.r, m->color.g, m->color.b);

    for (int i = 0; i < m->nfaces; ++i)
    {
        Vector3 f1 = m->verts[m->faces[i][0]];
        Vector3 f2 = m->verts[m->faces[i][1]];
        Vector3 f3 = m->verts[m->faces[i][2]];

        glBegin(GL_TRIANGLES);
        glVertex3f(f1.x,f1.y,f1.z);
        glVertex3f(f2.x,f2.y,f2.z);
        glVertex3f(f3.x,f3.y,f3.z);
        glNormal3f(m->normals[i].x, m->normals[i].y, m->normals[i].z);
        glEnd();
    }
}

Vector3 ComputeSurfaceNormals(const Vector3* p1, const Vector3* p2, const Vector3* p3)
{
    Vector3 v1 = subtract(p2,p1);
    Vector3 v2 = subtract(p3,p1);
    Vector3 v3 = cross(&v1, &v2);

    return norm(&v3);
}

void CalculateNormals(Mesh* m)
{
    for (int i = 0; i < m->nfaces; ++i)
    {
        Vector3 p1 = m->verts[m->faces[i][0]];
        Vector3 p2 = m->verts[m->faces[i][1]];
        Vector3 p3 = m->verts[m->faces[i][2]];

        m->normals[i] = ComputeSurfaceNormals(&p1,&p2,&p3);
    }
}

void FreeMesh(Mesh* m)
{
    free(m->verts);
    free(m->faces);
    free(m->normals);
}
