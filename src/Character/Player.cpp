
#include "Player.h"
#include "config.h"

Player::Player()
{
    sprite = new Sprite("assets/graphics/Character/EliShane_Idle.png");
    position = {100, Game::GroundHeight};
    velocityY = 0;
    moveSpeed = 200;
    grounded = false;

    // Add all the animations to the animator
    animator.CreateAnimation(sprite->texture, 2, 0.3, "idle");

    // Play the idle animation at the start of the game
    animator.PlayAnimation("idle");
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
    if (IsGrounded())
    {
        velocityY += gravity * GetFrameTime();
    }
    else
    {
        velocityY = 0;
        grounded = true;
        position.y = Game::GroundHeight;
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
    return position.y <= Game::GroundHeight;
}

// ************************ Draw Functions ************************ //

void Player::Draw() const
{
#ifdef GAME_DEBUG
    DrawCircleV(position, 1, YELLOW);
#endif

    Vector2 spriteOffset = {position.x, position.y - (float)sprite->texture.height};
    animator.DrawAnim(spriteOffset);
}


