#include "../include/Collections.h"

void TweakObjects()
{
    Object sphere = FindObject(0, objectList);

    sphere.transform.position = (Vector3){0,5,0};
    sphere.rigidbody.isStatic = 0;
    sphere.rigidbody.collider.MODE = SPHERE;
    sphere.rigidbody.collider.radius = 1;

    ReplaceObject(0,&sphere,objectList);

    Object plane = FindObject(1, objectList);

    plane.transform.position = (Vector3){0,0,0};
    plane.mesh.color = (Color){0.5,0.2,0.6};
    ReplaceObject(1,&plane,objectList);

    objectArray = ToArray(objectList);
}

void DestroyObjects()
{
    for (int i = 0; i < OBJECT_COUNT; ++i)
        Destroy(&objectArray[i]);
}
