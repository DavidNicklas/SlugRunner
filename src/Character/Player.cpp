
#include <iostream>
#include "Player.h"
#include "config.h"

Player::Player()
{
    sprite = new Sprite("assets/graphics/Character/EliShane_Idle.png");
    position = {50, 300};
    velocityY = 0;
    moveSpeed = 200;
    grounded = false;

    // Add all the animations to the animator
    Animation idleAnim = Animation(sprite->texture, 2, 0.3);
    animator.AddAnimation(idleAnim);

    // Play the idle animation at the start of the game
    animator.PlayAnimation(idleAnim);
}

Player::~Player()
{
    delete sprite;
}

// ************************ Update Functions ************************ //

void Player::Update()
{
    position.y += velocityY * GetFrameTime();

    // Check if the player is grounded
    if (!IsGrounded())
    {
        velocityY += gravity * GetFrameTime();
    }
    else
    {
        velocityY = 0;
        grounded = true;
        position.y = (float)Game::GroundHeight - (float)sprite->texture.height;
    }

    PlayerInput();

    animator.UpdateFrame();
}

void Player::PlayerInput()
{
    // Movement
    if (IsKeyDown(KEY_D))
    {
        position.x += moveSpeed * GetFrameTime();
    }
    if (IsKeyDown(KEY_A))
    {
        position.x -= moveSpeed * GetFrameTime();
    }

    // Jump
    if (IsKeyPressed(KEY_SPACE) && grounded)
    {
        velocityY = (float)-jumpForce;
        grounded = false;
    }
}

bool Player::IsGrounded() const
{
    return position.y + (float)sprite->texture.height <= Game::GroundHeight;
}

// ************************ Draw Functions ************************ //

void Player::Draw() const
{
    //DrawTextureV(sprite->texture, position, WHITE);
    //DrawTextureRec(sprite->texture, {0, 0, sprite->texture.width / 2, sprite->texture.height}, position, WHITE);
    animator.DrawAnim(position);
}


