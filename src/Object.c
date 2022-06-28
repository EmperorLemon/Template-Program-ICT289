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
    m->mat.color = (Color){1,1,1};
    SetMaterial(&m->mat);
}

void SetRigidbody(Rigidbody* rb)
{
    rb->acceleration = (Vector3){0,GRAVITY,0};
    rb->velocity = zero();
    rb->force = zero();

    rb->mass = 1;

    rb->transform.position = zero();

    rb->isStatic = 1;
}

void SetCollider(Rigidbody* rb, Object* o)
{
    rb->collider.radius = 1;

    CalculateNormals(&o->mesh);

    rb->collider.point = o->mesh.verts[0];
    rb->collider.normal = o->mesh.normals[0];
}

void UpdateCollider(Rigidbody* rb, Object* o)
{
    CalculateNormals(&o->mesh);

    rb->collider.point = o->mesh.verts[0];
    rb->collider.normal = o->mesh.normals[0];
}

void SetTransform(Transform* tf)
{
    tf->position = zero();
    tf->rotation = zero();
    tf->scale = one();
}

void DrawObject(const Object* o)
{
    if (!o->isVisible) return;

    DrawMesh(&o->mesh);
}

void UpdateObject(Object* o)
{
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColor3f(o->mesh.mat.color.r, o->mesh.mat.color.g, o->mesh.mat.color.b);

    glPushMatrix();

    TranslateV(&o->transform.position);
    RotateV(&o->transform.rotation);
    ScaleV(o->rigidbody.collider.radius);

    DrawObject(o);
    UpdateCollider(&o->rigidbody, o);
    DrawMaterial(&o->mesh.mat);

    glPopMatrix();

    glDisable(GL_COLOR_MATERIAL);
}

void Destroy(Object* o)
{
    FreeMesh(&o->mesh);
}
