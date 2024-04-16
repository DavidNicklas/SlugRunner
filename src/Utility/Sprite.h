
#pragma once

#include <string>
#include <vector>
#include "raylib.h"

class Sprite
{
public:
    Sprite() = default;
    explicit Sprite(Texture2D texture);
    explicit Sprite(const char* texturePath);

    ~Sprite();

    Texture2D texture {};
    Vector2 position {};
    Color color {};

private:

};

class AnimatedSprite : public Sprite
{
public:

private:
    std::vector<int> animations;
    int frames;

};