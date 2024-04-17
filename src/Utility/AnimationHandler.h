
#pragma once

#include <vector>
#include <map>
#include "raylib.h"

struct Animation
{
    Animation() = default;
    Animation(Texture2D spriteSheet, int frames, float frameRate, std::string name);

    void Update();
    void DrawCurrentFrame(Vector2 position, Color tint = WHITE) const;

    Texture2D spriteTex;
    std::string name;
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
    void CreateAnimation(Texture2D spriteSheet, int frames, float frameRate, std::string name);
    void AddAnimation(const std::string& name, const Animation& anim);
    void PlayAnimation(const std::string& name);
    void UpdateFrame();
    void DrawAnim(Vector2 position) const;

private:
    std::map<std::string, Animation> animationMap;

    Animation currentAnimation;
};

//typedef AnimationHandler Animator;
