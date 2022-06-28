#pragma once

#include "Camera.h"
#include "Physics.h"
#include "Collections.h"
#include "Lighting.h"
#include "Controls.h"
#include "Time.h"

void DrawAxes();
void CreateScene();
void CreateCamera();
void LoadObjects();
void DrawObjects();
void UpdateRigidbodies(float deltaTime);
void UpdateCollisions();
void ResetObjects();
//void PrintVector(const Vector3* v);
void EndScene();
