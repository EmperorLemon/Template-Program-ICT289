#include "../include/Collections.h"

void TweakObjects()
{
    Object sphere = FindObject(0, objectList);

    sphere.transform.position = (Vector3){0,5,0};

    sphere.mesh.mat.color = (Color){0.5,.3,.6};

    sphere.rigidbody.collider.MODE = SPHERE;

    sphere.rigidbody.isStatic = 0;
    sphere.rigidbody.bounciness = 0.9;

    ReplaceObject(0,&sphere,objectList);

    //////////////////////////////////////////////
    Object plane = FindObject(1, objectList);

    plane.transform.position = (Vector3){0,0,0};
    plane.mesh.mat.color = (Color){0.75,0,0};

    ReplaceObject(1,&plane,objectList);

    //////////////////////////////////////////////////
    Object sphere_two = FindObject(2, objectList);

    sphere_two.transform.position = (Vector3){0,8,0};
    sphere_two.rigidbody.collider.MODE = SPHERE;

    sphere_two.rigidbody.isStatic = 0;
    sphere_two.rigidbody.bounciness = 0.9;

    ReplaceObject(2,&sphere_two, objectList);


    objectArray = ToArray(objectList);
}

void DestroyObjects()
{
    for (int i = 0; i < OBJECT_COUNT; ++i)
        Destroy(&objectArray[i]);
}
