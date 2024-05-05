
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
    position.x += currentMoveSpeed * GetFrameTime();

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

    DetermineAnimationState();
    animator.UpdateFrame();
}

void Player::PlayerInput()
{
    // Movement
    if (IsKeyDown(KEY_D))
    {
        lastInputKey = KEY_D;
        currentMoveSpeed = moveSpeed;
    }
    else if (IsKeyDown(KEY_A))
    {
        lastInputKey = KEY_A;
        currentMoveSpeed = moveSpeed * -1;
    }
    else
    {
        currentMoveSpeed = 0;
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

void Player::DetermineAnimationState()
{
    if (currentMoveSpeed == 0)
    {
        switch (lastInputKey)
        {
            case KEY_D:
                if (!animator.IsPlaying("idleRight"))
                {
                    animator.PlayAnimation("idleRight");
                    return;
                }
                break;
            case KEY_A:
                if (!animator.IsPlaying("idleLeft"))
                {
                    animator.PlayAnimation("idleLeft");
                    return;
                }
                break;
            default:
                break;
        }
    }
    else if (currentMoveSpeed > 0)
    {
        if (!animator.IsPlaying("runRight"))
        {
            animator.PlayAnimation("runRight");
        }
    }
    else if (currentMoveSpeed < 0)
    {
        if (!animator.IsPlaying("runLeft"))
        {
            animator.PlayAnimation("runLeft");
        }
    }
}

// ************************ Draw Functions ************************ //

void Player::Draw() const
{
#ifdef GAME_DEBUG
    DrawCircleV(position, 1, YELLOW);
    DrawInspector();
#endif

    // Offset the sprite so it's drawn from the bottom
    Vector2 spriteOffset = {position.x, position.y - height};
    animator.DrawAnim(spriteOffset);
}

void Player::DrawInspector() const
{
    DrawRectangle(10, 10, 300, 100, BLACK);
    DrawText(("Move Speed: " + std::to_string(moveSpeed)).c_str(), 12, 12, 10, RED);
    DrawText(("Gravity: " + std::to_string(gravity)).c_str(), 12, 22, 10, RED);
    DrawText(("Jump Force: " + std::to_string(jumpForce)).c_str(), 12, 32, 10, RED);
}

