
#pragma once

#include <vector>
#include <map>
#include "raylib.h"

struct Animation
{
    Animation() = default;
    Animation(Texture2D spriteSheet, int frames, float frameRate);

    void Update();
    void DrawCurrentFrame(Vector2 position, Color tint = WHITE) const;

    Texture2D spriteTex;
    std::vector<Rectangle> frameRecs;

    int frames;
    float frameWidth;

    int currentFrame;           // stores the current frame as integer
    float frameRate;            // defines the time that is used for one frame
    float currentTime;          // stores the passed time
};


class AnimationHandler
{
public:
    void UpdateFrame();
    void DrawAnim(Vector2 position) const;
    void AddAnimation(const Animation& anim);
    void PlayAnimation(const Animation& type);

private:
    std::vector<Animation> animations;
    std::vector<Rectangle> frameRecs;

    Animation currentAnimation;
};

//typedef AnimationHandler Animator;