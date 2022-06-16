#pragma once

#include "Rigidbody.h"

int SpherePlaneDetection(const Rigidbody* sphere, const Rigidbody* plane);
void SpherePlaneResponse(Rigidbody* sphere, const Rigidbody* plane);
