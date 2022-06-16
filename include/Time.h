#pragma once

typedef struct
{
    int curTime, prevTime;
    float deltaTime;
}Time;

void StartTime();
void UpdateTime();
