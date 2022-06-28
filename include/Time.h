#pragma once

typedef struct
{
    int curTime, prevTime;
    float deltaTime;
}Time;

Time time;

void StartTime(Time* t);
void UpdateTime(Time* t);
void ResetTime(Time* t);
