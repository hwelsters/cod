#pragma once 
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "cod/math/vector2.h"

struct Sprite
{
public:
    SDL_Texture* texture;
    Vector2 source_size;
    Vector2 source_position;
};

#endif