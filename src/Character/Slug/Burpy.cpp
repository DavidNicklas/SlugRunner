#include "Burpy.h"
#include "config.h"

Burpy::Burpy()
{
    position = {200, static_cast<float>(Game::GroundHeight - idleSpriteSheet.height)};

    // Create the animations
    animator.CreateAnimation(idleSpriteSheet, 3, 0.6f, "idle");

    animator.PlayAnimation("idle");
}

// ************************ Update Functions ************************ //

void Burpy::Update()
{
    Slug::BaseUpdate();
}

// ************************ Draw Functions ************************ //

void Burpy::Draw()
{
    Slug::BaseDraw();
}

Burpy::~Burpy()
{
    UnloadTexture(idleSpriteSheet);
}
