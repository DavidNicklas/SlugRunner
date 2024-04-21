
#include <iostream>
#include "AnimationHandler.h"

// ##################################################################################
//                               class: Animation
// ##################################################################################
/**
 * \brief Initializes the animation with the provided parameters and creates the source recs to draw the animation.
 *
 * \param spriteSheet The texture of the sprite sheet to be used for the animation.
 * \param frames The total number of frames in the sprite sheet.
 * \param frameRate The frame rate at which the animation should be played (frames per second).
 *
 * \return void
 */
Animation::Animation(Texture2D spriteSheet, int frames, float frameRate, std::string name)
: spriteTex(spriteSheet), frames(frames), frameRate(frameRate), name(name)
{
    frameWidth = (float)spriteSheet.width / (float)this->frames;
    currentFrame = 0;
    currentTime = 0;

    // Create all source recs that are needed to draw the correct sprite
    int recCounter = 0;
    for (int i = 0; i < this->frames; ++i)
    {
        Rectangle fRec = {(float)recCounter * frameWidth, 0, frameWidth, static_cast<float>(spriteTex.height)};
        frameRecs.push_back(fRec);
        recCounter++;
    }
}

// ************************ Update Functions ************************ //

void Animation::Update()
{
    currentTime += GetFrameTime();
    // if the time reaches the frameRate, switch to the next frame
    if (currentTime >= frameRate)
    {
        currentTime = 0.0f;
        currentFrame = (currentFrame + 1) % (int)frameRecs.size();         // ensures that the current frame is in the bounds
    }
}

// ************************ Draw Functions ************************ //

void Animation::DrawCurrentFrame(Vector2 position, Color tint) const
{
    Rectangle sourceRec = frameRecs[currentFrame];
    DrawTextureRec(spriteTex, sourceRec, position, tint);
}

// ##################################################################################
//                               class: Animation Handler
// ##################################################################################
/**
 * @brief Creates an animation with the provided parameters and adds it to the animation map.
 */
void AnimationHandler::CreateAnimation(Texture2D spriteSheet, int frames, float frameRate, std::string name)
{
    Animation anim = Animation(spriteSheet, frames, frameRate, name);
    animationMap.insert(std::make_pair(name, anim));
}

void AnimationHandler::AddAnimation(const std::string& name, const Animation& anim)
{
    animationMap.insert(std::make_pair(name, anim));
}

void AnimationHandler::PlayAnimation(const std::string& name)
{
    if (animationMap.find(name) != animationMap.end())
    {
        currentAnimation = animationMap[name];
    }
    else
    {
        std::cerr << "Animation with name " << name << " not found!" << std::endl;
    }
}

// ************************ Update Functions ************************ //

void AnimationHandler::UpdateFrame()
{
    currentAnimation.Update();
}

// ************************ Draw Functions ************************ //

void AnimationHandler::DrawAnim(Vector2 position) const
{
    currentAnimation.DrawCurrentFrame(position);
}