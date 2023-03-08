#ifndef ANIMATOR_TABLE_H
#define ANIMATOR_TABLE_H

#include <vector>
#include "cod/graphics/animation.h"

struct AnimationTable 
{
public:
    // This copies the whole ass struct, maybe I should pass a pointer instead?
    Animation get_animation(int);

    void add_animation(int, Animation);
    void add_animation(int, SDL_Texture*, int, Vector2, Vector2, float);
private:
    std::vector<Animation> animations;
};

#endif