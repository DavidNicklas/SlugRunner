
#include "Background.h"

Background::Background()
{
    environment = new Sprite("assets/graphics/backgrounds/SlugterraEnvironmentDark_Real.png");
}

Background::~Background()
{
    delete environment;
}

// ************************ Update Functions ************************ //

void Background::Update()
{

}

// ************************ Draw Functions ************************ //

void Background::Draw() const
{
    DrawTextureV(environment->texture, environment->position, WHITE);
}

