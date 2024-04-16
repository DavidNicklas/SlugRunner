
#include "Sprite.h"

Sprite::Sprite(Texture2D texture)
{
    this->texture = texture;
    position = {0, 0};
    color = WHITE;
}

Sprite::Sprite(const char* texturePath)
{
    texture = LoadTexture(texturePath);
    position = {0, 0};
    color = WHITE;
}

Sprite::~Sprite()
{
    UnloadTexture(texture);
}

