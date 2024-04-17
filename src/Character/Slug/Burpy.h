#pragma once

#include "Slug.h"

class Burpy : Slug
{
public:
    Burpy();
    ~Burpy();

    void Update();
    void Draw();

private:
    Texture2D idleSpriteSheet = LoadTexture("assets/graphics/Character/Slugs/Burpy/Burpy_Idle.png");

};