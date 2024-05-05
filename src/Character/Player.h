
#pragma once
#include "raylib.h"
#include "../Utility/Sprite.h"
#include "../Utility/AnimationHandler.h"
#include "../Game/GameSupport_Lib.h"

class Player
{
public:
    Player();
    ~Player();

    void Draw() const;
    void Update();

    Vector2 position{};
    float velocityY;
    float moveSpeed;

private:
    void PlayerInput();
    bool IsGrounded() const;
    void DrawInspector() const;

    AnimationHandler animator;

    bool grounded;
    float currentMoveSpeed = 0;
    int jumpForce = 700;
    float gravity = 1500;
    float height;

    Texture2D idleTexLeft;
    Texture2D idleTexRight;
    Texture2D runTexRight;
    Texture2D runTexLeft;

    KeyboardKey lastInputKey;

    void DetermineAnimationState();
};