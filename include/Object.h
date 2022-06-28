#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "Rigidbody.h"

typedef struct
{
    char* name;
    Mesh mesh;
    Transform transform;
    Rigidbody rigidbody;
    int isVisible;
} Object;

Object GenerateObject(char* name);
void SetMesh(Mesh* m, const Object* o);
void SetRigidbody(Rigidbody* rb);
void SetCollider(Rigidbody* rb, Object* o);
void SetTransform(Transform* tf);
void DrawObject(const Object* o);
void NormalizeObject(Object* o);
void UpdateObject(Object* o);
void Destroy(Object* o);
