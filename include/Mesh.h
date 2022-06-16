#pragma once

#include "Vector.h"
#include "Color.h"

typedef int Face[3];

typedef struct
{
    int nverts, nfaces;
    Vector3* verts;
    Face* faces;
    Vector3* normals;
    Color color;
} Mesh;

void DrawMesh(const Mesh* m);
Vector3 ComputeSurfaceNormals(const Vector3* p1, const Vector3* p2, const Vector3* p3);
void FreeMesh(Mesh* m);
void CalculateNormals(Mesh* m);
