
#pragma once
#include "../Utility/Sprite.h"

class Background
{
public:
    Background();
    ~Background();

    void Draw() const;
    void Update();

private:
    Sprite* environment;

    // For the Future we could go with speed and let the background move as well
};
