
#include "Player.h"
#include "config.h"

Player::Player()
{
    idleTexLeft = LoadTexture("assets/graphics/Character/EliShane_IdleL.png");
    idleTexRight = LoadTexture("assets/graphics/Character/EliShane_IdleR.png");
    runTexRight = LoadTexture("assets/graphics/Character/EliShane_RunR.png");
    runTexLeft = LoadTexture("assets/graphics/Character/EliShane_RunL.png");

    position = {100, Game::GroundHeight};
    velocityY = 0;
    moveSpeed = 200;
    grounded = false;
    height = (float)idleTexRight.height;

    // Add all the animations to the animator
    animator.CreateAnimation(idleTexRight, 2, 0.3, "idleRight");
    animator.CreateAnimation(idleTexLeft, 2, 0.3, "idleLeft");
    animator.CreateAnimation(runTexRight, 8, 0.1, "runRight");
    animator.CreateAnimation(runTexLeft, 8, 0.1, "runLeft");

    // Play the idle animation at the start of the game
    animator.PlayAnimation("idleRight");
}

Player::~Player()
{
    UnloadTexture(idleTexLeft);
    UnloadTexture(idleTexRight);
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
        if (!animator.IsPlaying("runRight"))
        {
            animator.PlayAnimation("runRight");
        }
        position.x += moveSpeed * GetFrameTime();
    }
    else if (IsKeyDown(KEY_A))
    {
        if (!animator.IsPlaying("runLeft"))
        {
            animator.PlayAnimation("runLeft");
        }
        position.x -= moveSpeed * GetFrameTime();
    }
    else
    {
        if (!animator.IsPlaying("idleRight"))
        {
            animator.PlayAnimation("idleRight");
        }
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

    // Offset the sprite so it's drawn from the bottom
    Vector2 spriteOffset = {position.x, position.y - height};
    animator.DrawAnim(spriteOffset);
}


