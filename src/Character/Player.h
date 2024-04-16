
#pragma once
#include "raylib.h"
#include "../Utility/Sprite.h"
#include "../Utility/AnimationHandler.h"

class Player
{
public:
    Player();
    ~Player();

    void Draw() const;
    void Update();

    Sprite* sprite;

    Vector2 position{};
    float velocityY;
    float moveSpeed;

private:
    void PlayerInput();
    bool IsGrounded() const;

    AnimationHandler animator;

    bool grounded;
    int jumpForce = 700;
    float gravity = 1500;

};