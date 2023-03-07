#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

#include "cod/graphics/sprite.h"

struct Animation
{
public:
    float miliseconds_per_frame;
    std::vector<Sprite> animation;
}

#endif