#pragma once

#include "Rigidbody.h"

void UpdatePhysics(Rigidbody* rb, Transform* tf, float time);

Vector3 Acceleration(const Rigidbody* rb);
Vector3 Force(const Rigidbody* rb);
Vector3 Velocity(const Rigidbody* rb, float time);
Vector3 Displacement(Rigidbody* rb, Transform* tf, float time);
