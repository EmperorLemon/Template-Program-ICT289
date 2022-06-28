#include "../include/Matrix.h"
#include "../include/MATH_CONSTANTS.h"

void IdentityMatrix(Matrix* m)
{
    Point4 identity[] = {{1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1}};


    m->data = identity;
}

void RotationX(Matrix* m, const float angle)
{
    Point4 Rx[] = {{1,0,0,0},
                   {0, cos(angle * DEG2RAD), -sin(angle * DEG2RAD),0},
                   {0, sin(angle * DEG2RAD), cos(angle * DEG2RAD), 0},
                   {0,0,0,1}};

    m->data = Rx;
}

void RotationY(Matrix* m, const float angle)
{
    Point4 Ry[] = {{cos(angle * DEG2RAD), 0, sin(angle * DEG2RAD), 0},
                   {0,1,0,0},
                   {-sin(angle * DEG2RAD), 0, cos(angle * DEG2RAD),0},
                   {0,0,0,1}};

    m->data = Ry;
}

void RotationZ(Matrix* m, const float angle)
{
    Point4 Rz[] = {{cos(angle * DEG2RAD), -sin(angle * DEG2RAD), 0, 0},
                   {sin(angle * DEG2RAD), cos(angle * DEG2RAD), 0, 0},
                   {0,0,1,0},
                   {0,0,0,1}};

    m->data = Rz;
}
