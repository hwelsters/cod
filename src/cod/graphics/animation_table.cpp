#include "cod/graphics/animation_table.h"

// Maybe I could use pointers instead. Maybe I will benchmarks and then make decisions later down the line
Animation* AnimationTable::get_animation(int animation_ID)
{
    return this->animations[animation_ID];
}

void AnimationTable::add_animation(int animation_ID, Animation* animation)
{
    if (this->animations.size() <= animation_ID)
    {
        this->animations.resize(animation_ID + 1);
        this->animations[animation_ID] = animation;
    }
}

void AnimationTable::add_animation(int animation_ID, SDL_Texture* texture, int num_of_frames, Vector2 source_size, Vector2 source_position, float ticks_per_frame)
{
    std::vector<Sprite> sprite_list;

    Sprite sprite;
    sprite.texture = texture;
    sprite.source_size = source_size;

    for (int i = 0; i < num_of_frames; i++)
    {
        // RENAME THIS
        Vector2 new_source_position = Vector2(source_position.x + source_size.x * i, source_position.y + source_size.y);

        sprite.source_position = new_source_position;
        sprite_list.push_back(sprite);
    }

    Animation* animation;
    animation->ticks_per_frame = ticks_per_frame;
    animation->animation = sprite_list;
    this->add_animation(animation_ID, animation);
}