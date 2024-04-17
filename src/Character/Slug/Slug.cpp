//
// Created by kordz on 17/04/2024.
//

#include "Slug.h"

Slug::~Slug()
{

}

// ************************ Update Functions ************************ //

void Slug::BaseUpdate()
{
    animator.UpdateFrame();
}

// ************************ Draw Functions ************************ //

void Slug::BaseDraw()
{
    animator.DrawAnim(position);
}
