#pragma once 
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "cod/math/vector2.h"

struct Sprite
{
public:
    Vector2 source_size;
    Vector2 source_position;
    SDL_Texture* texture;
};

#endif