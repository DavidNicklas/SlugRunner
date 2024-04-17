#include <cstdlib>

#include "raylib.h"

#include "config.h"
#include "Game/GameSupport_Lib.h"

// Include the Gizmos Features if game should start in Debug mode
#ifdef GAME_DEBUG
#include "Utility/Debug.h"
#endif

#include "LevelBuilding/Ground.h"
#include "Character/Player.h"
#include "LevelBuilding/Background.h"
#include "Character/Slug/Burpy.h"

int main() {
    InitGameWindow();

    // Those two are relevant to drawing and code-cleanliness
    float renderScale{};
    Rectangle renderRec{};
    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);

    Player player;
    Ground ground;
    Background background;
    Burpy burpy;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        player.Update();
        ground.MoveToLeft();
        burpy.Update();

        BeginDrawing();
        BeginTextureMode(canvas);
        {
            ClearBackground(WHITE);
            background.Draw();
            //ground.Draw();
            player.Draw();
            burpy.Draw();

#ifdef GAME_DEBUG
            Gizmos::DrawGizmos();
#endif
        }

        EndTextureMode();

        // The following lines put the canvas in the middle of the window and have the negative as black
        ScaleCanvas(canvas, renderScale, renderRec);

        EndDrawing();
    } // Main game loop end

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}