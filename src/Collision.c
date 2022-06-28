#include "../include/Collision.h"
#include <stdlib.h>
#include <stdio.h>

int SpherePlaneDetection(const Rigidbody* sphere, const Rigidbody* plane)
{
    Vector3 difference = subtract(&sphere->transform.position, &plane->collider.point);

    float distance = abs(dot(&difference, &plane->collider.normal));

    return distance <= sphere->collider.radius;
}

int SphereSphereDetection(const Rigidbody* s1, const Rigidbody* s2)
{
    Vector3 difference = subtract(&s1->transform.position, &s2->transform.position);

    float distance = getMag(&difference);

    return distance < (s1->collider.radius + s2->collider.radius);
}

void SpherePlaneResponse(Rigidbody* sphere, const Rigidbody* plane)
{
    sphere->velocity = reflect(&sphere->velocity, &plane->collider.normal);
    sphere->velocity = scalarMultiply(&sphere->velocity, sphere->bounciness);
}

void SphereSphereResponse(Rigidbody* s1, Rigidbody* s2)
{
    Vector3 d1 = subtract(&s2->transform.position, &s1->transform.position);
    Vector3 d2 = subtract(&s1->transform.position, &s2->transform.position);

    Vector3 v1 = s1->velocity;

    Vector3 proj1 = project(&s2->velocity, &d1);
    v1 = add(&v1, &proj1);

    Vector3 proj2 = project(&s1->velocity, &d2);
    v1 = subtract(&v1, &proj2);

    Vector3 v2 = s2->velocity;

    Vector3 proj3 = project(&s1->velocity, &d1);
    v2 = add(&v2, &proj3);

    Vector3 proj4 = project(&s2->velocity, &d2);
    v2 = subtract(&v2, &proj4);

    s1->velocity = v1;
    s2->velocity = v2;
}
