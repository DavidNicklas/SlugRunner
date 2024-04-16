
#include "Ground.h"
#include "config.h"

Ground::Ground()
{
    groundRec[0] = {0, Game::ScreenHeight - height, Game::ScreenWidth, height};
    groundRec[1] = {Game::ScreenWidth, Game::ScreenHeight - height, Game::ScreenWidth, height};
}

// ************************ Update Functions ************************ //

void Ground::MoveToLeft()
{
    for (auto & rec : groundRec)
    {
        // Move each ground tile to the left
        rec.x -= speed;

        if (rec.x + rec.width <= 0)
        {
            // If the rectangle leaves the left screen bounds, it gets set back to the right end of the screen
            rec.x = Game::ScreenWidth;
        }
    }
}

// ************************ Draw Functions ************************ //

void Ground::Draw()
{
    // Draw both recs individual with the opposite gradient to get a smooth transition
    DrawRectangleGradientEx(groundRec[0], GREEN, LIME, DARKGREEN, YELLOW);
    DrawRectangleGradientEx(groundRec[1], YELLOW, DARKGREEN, LIME, GREEN);
}
