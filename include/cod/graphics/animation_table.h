#ifndef ANIMATOR_TABLE_H
#define ANIMATOR_TABLE_H

#include <vector>
#include <unordered_map>
#include "cod/graphics/animation.h"

class AnimationTable 
{
public:
    AnimationTable();
    // This copies the whole ass struct, maybe I should pass a pointer instead?
    Animation get_animation(int);

    void add_animation(int, Animation);
    void add_animation(
        int animation_ID, 
        SDL_Texture* texture, 
        int num_of_frames, 
        Vector2 source_size, 
        Vector2 source_position, 
        float ticks_per_frame);

private:
    // std::vector<Animation> animations;
    std::unordered_map<int, Animation> animations;
};

#endif