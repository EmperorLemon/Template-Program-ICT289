#include "../include/Object.h"
#include "../include/ReadFile.h"
#include "../include/MATH_CONSTANTS.h"
#include <GL/freeglut.h>

Object GenerateObject(char* name)
{
    Object obj;

    obj.name = name;

    SetMesh(&obj.mesh, &obj);
    SetRigidbody(&obj.rigidbody);
    SetCollider(&obj.rigidbody, &obj);
    SetTransform(&obj.transform);

    return obj;
}

void SetMesh(Mesh* m, const Object* o)
{
    *m = readMeshFile(o->name);
    m->color = (Color){1,1,1};
}

void SetRigidbody(Rigidbody* rb)
{
    rb->acceleration = Gravity();
    rb->velocity = zero();
    rb->force = zero();

    rb->mass = 1;

    rb->transform.position = zero();

    rb->isStatic = 1;
}

void SetCollider(Rigidbody* rb, Object* o)
{
    rb->centre = GetCentre(&o->mesh);
    rb->collider.radius = GetSphereRadius(&o->mesh, &o->rigidbody.centre);

    CalculateNormals(&o->mesh);

    rb->collider.point = o->mesh.verts[0];
    rb->collider.normal = o->mesh.normals[0];
}

void SetTransform(Transform* tf)
{
    tf->position = zero();
    tf->scale = one();
}

void DrawObject(const Object* o)
{
    if (!o->isVisible) return;

    DrawMesh(&o->mesh);
}

void UpdateObject(const Object* o)
{
    glPushMatrix();
    TranslateV(&o->transform.position);
    DrawObject(o);
    glPopMatrix();
}

void Destroy(Object* o)
{
    FreeMesh(&o->mesh);
}
