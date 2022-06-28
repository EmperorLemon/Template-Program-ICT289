#pragma once

#include "Rigidbody.h"

int SpherePlaneDetection(const Rigidbody* sphere, const Rigidbody* plane);
void SpherePlaneResponse(Rigidbody* sphere, const Rigidbody* plane);
int SphereSphereDetection(const Rigidbody* s1, const Rigidbody* s2);
void SphereSphereResponse(Rigidbody* s1, Rigidbody* s2);
