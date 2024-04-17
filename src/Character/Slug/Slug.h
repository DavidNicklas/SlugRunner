#pragma once

#include "../../Utility/Sprite.h"
#include "../../Utility/AnimationHandler.h"

class Slug
{
public:
    ~Slug();

    Vector2 position;
    AnimationHandler animator;

protected:
    void BaseUpdate();
    void BaseDraw();

private:

};