
#pragma once
#include "raylib.h"
#include "../Utility/Sprite.h"

class Ground
{
public:
    Ground();

    void MoveToLeft();
    void Draw();

    Rectangle groundRec[2] {};

private:
    float height = 80;
    float speed = 10;
};