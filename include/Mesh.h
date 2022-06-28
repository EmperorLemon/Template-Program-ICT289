#pragma once

#include "Vector.h"
#include "Color.h"

typedef int Face[3];

typedef struct
{
    float solid[4];
    float specular[4];
    float shininess[1];
    Color color;
}Material;

typedef struct
{
    int nverts, nfaces;
    Vector3* verts;
    Face* faces;
    Vector3* normals;
    Material mat;
} Mesh;

void SetMaterial(Material* m);
void DrawMaterial(const Material* m);

void DrawMesh(const Mesh* m);
Vector3 ComputeSurfaceNormals(const Vector3* p1, const Vector3* p2, const Vector3* p3);
void RotateX(Mesh* m, const float angle);
void RotateZ(Mesh* m, const float angle);
void FreeMesh(Mesh* m);
void CalculateNormals(Mesh* m);
