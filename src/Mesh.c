#include "../include/Mesh.h"
#include <GL/freeglut.h>
#include <math.h>

void DrawMesh(const Mesh* m)
{
    for (int i = 0; i < m->nfaces; ++i)
    {
        glNormal3f(m->normals[i].x, m->normals[i].y, m->normals[i].z);

        Vector3 f1 = m->verts[m->faces[i][0]];
        Vector3 f2 = m->verts[m->faces[i][1]];
        Vector3 f3 = m->verts[m->faces[i][2]];

        glBegin(GL_TRIANGLES);
            glVertex3f(f1.x,f1.y,f1.z);
            glVertex3f(f2.x,f2.y,f2.z);
            glVertex3f(f3.x,f3.y,f3.z);
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

void RotateX(Mesh* m, const float angle)
{
    float zTemp[m->nverts];

    for (int i = 0; i < m->nverts; i++)
    {
        zTemp[i] = m->verts[i].z;

        m->verts[i].z = cos(angle) * m->verts[i].z - sin(angle) * m->verts[i].y;
        m->verts[i].y = sin(angle) * zTemp[i] + cos(angle) * m->verts[i].y;
    }
}

void RotateZ(Mesh* m, const float angle)
{
    float xTemp[m->nverts];

    for (int i = 0; i < m->nverts; i++)
    {
        xTemp[i] = m->verts[i].x;

        m->verts[i].x = cos(angle) * m->verts[i].x - sin(angle) * m->verts[i].y;
        m->verts[i].y = sin(angle) * xTemp[i] + cos(angle) * m->verts[i].y;
    }
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

void SetMaterial(Material* mat)
{
    Vector4 solid = (Vector4){mat->color.r,mat->color.g,mat->color.b,1};

    mat->solid[0] = solid.x;
    mat->solid[1] = solid.y;
    mat->solid[2] = solid.z;
    mat->solid[3] = solid.w;

    Vector4 specular = (Vector4){1,1,1,0.01};
    mat->specular[0] = specular.x;
    mat->specular[1] = specular.y;
    mat->specular[2] = specular.z;
    mat->specular[3] = specular.w;

    mat->shininess[0] = 50;
}

void DrawMaterial(const Material* mat)
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat->specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat->shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat->solid);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat->solid);
}

void FreeMesh(Mesh* m)
{
    free(m->verts);
    free(m->faces);
    free(m->normals);
}
