#include "../include/Physics.h"
#include <GL/freeglut.h>

Vector3 curAcc, curFor, curVel, curPos;

void UpdatePhysics(Rigidbody* rb, Transform* tf, float time)
{
    if (!rb->isStatic)
    {
        curFor = Force(rb);
        curAcc = Acceleration(rb);
        curVel = Velocity(rb, time);
        curPos = Displacement(rb,tf,time);

        rb->force = curFor;
        rb->acceleration = curAcc;
        rb->velocity = curVel;

        rb->transform.position = curPos;

        tf->position = rb->transform.position;
    }
}

Vector3 Force(const Rigidbody* rb)
{
    return scalarMultiply(&rb->acceleration, rb->mass);
}

Vector3 Acceleration(const Rigidbody* rb)
{
    return scalarDivide(&rb->force, rb->mass);
}

Vector3 Velocity(const Rigidbody* rb, float time)
{
    Vector3 at = scalarMultiply(&rb->acceleration, time);

    return add(&rb->velocity, &at);
}

Vector3 Displacement(Rigidbody* rb, Transform* tf, float time)
{
    // P
    rb->transform.position = tf->position;

    // vi * t
    Vector3 vit = scalarMultiply(&rb->velocity, time);

    // P + (vi * t)
    Vector3 pvit = add(&rb->transform.position, &vit);

    // a * t^2
    Vector3 aTSqr = scalarMultiply(&rb->acceleration, time * time);

    // 1/2 * (a * t^2)
    Vector3 haTSqr = scalarDivide(&aTSqr, 2);

    // P(vi * t) + (a * t^2)
    return add(&pvit, &haTSqr);
}
