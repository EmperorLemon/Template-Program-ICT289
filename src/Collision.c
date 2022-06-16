#include "../include/Collision.h"
#include <stdlib.h>
#include <stdio.h>

int SpherePlaneDetection(const Rigidbody* sphere, const Rigidbody* plane)
{
    Vector3 difference = subtract(&sphere->transform.position, &plane->collider.point);
    float distance = abs(dot(&difference, &plane->collider.normal));

    return distance < sphere->collider.radius * sphere->collider.radius;
}

void SpherePlaneResponse(Rigidbody* sphere, const Rigidbody* plane)
{
    sphere->velocity = reflect(&sphere->velocity, &plane->collider.normal);
}
