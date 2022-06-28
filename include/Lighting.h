#pragma once

typedef struct
{
    float light_position[4];
    float spot_direction[4];
}Light;

Light light;
void SetLight(Light* _light);
void DrawSpotlight(const Light* _light);
void DefineLight(const Light* _light);
void UpdateLight();
