
#pragma once

#include "raylib.h"
#include "config.h"

namespace Gizmos
{
    void DrawGroundHeight()
    {
        DrawLineEx({0, Game::GroundHeight}, {Game::ScreenWidth, Game::GroundHeight}, 2,RED);
    }

    void DrawGizmos()
    {
        DrawGroundHeight();
    }
}