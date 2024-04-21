
#pragma once

#include <algorithm>
#include "raylib.h"
#include "config.h"

void InitGameWindow();

void ScaleCanvas(RenderTexture2D& canvas, float renderScale, Rectangle renderRec);

Texture2D FlipTexture(Texture2D texture);