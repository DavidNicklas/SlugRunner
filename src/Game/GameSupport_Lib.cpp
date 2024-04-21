#include "GameSupport_Lib.h"


void InitGameWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
    ToggleFullscreen();
#endif
}

void ScaleCanvas(RenderTexture2D& canvas, float renderScale, Rectangle renderRec)
{
    ClearBackground(BLACK);
    renderScale = std::min(GetScreenHeight() / (float) canvas.texture.height, // Calculates how big or small the canvas has to be rendered.
                           GetScreenWidth() / (float) canvas.texture.width);
    renderRec.width = canvas.texture.width * renderScale;
    renderRec.height = canvas.texture.height * renderScale;
    renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
    renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;
    DrawTexturePro(canvas.texture, Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                   renderRec,
                   {}, 0, WHITE);
}

Texture2D FlipTexture(Texture2D texture)
{
    Image img = LoadImageFromTexture(texture);
    ImageFlipVertical(&img);
    Texture2D flipped = LoadTextureFromImage(img);
    UnloadImage(img);
    return flipped;
}