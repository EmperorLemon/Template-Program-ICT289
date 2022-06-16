#pragma once

#include "Camera.h"
#include "Physics.h"
#include "Collections.h"
#include "Controls.h"
#include "Time.h"

Time time;
void DrawAxes();
void CreateScene();
void CreateCamera();
void LoadObjects();
void DrawObjects();
void UpdateRigidbodies(float deltaTime);
void UpdateCollisions();
void EndScene();
