#pragma once

#include "Vector.h"
#include <math.h>

#define PI 3.141592654

Vector3 Gravity();

Vector3 Gravity(){return (Vector3){0,-9.81f,0};}
