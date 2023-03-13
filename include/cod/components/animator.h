#ifndef ANIMATOR_h
#define ANIMATOR_H

#include "cod/components/component.h"
#include "cod/components/sprite_renderer.h"
#include "cod/graphics/animation.h"

class Animator : public Component 
{
public: 
    Animator();
    void start() override;
    void render() override;
    void update() override;

    void play_animation(int animation_ID, bool play_once);
private:
    bool is_sprite_renderer_exist();
    
    bool play_once;
    bool is_playing_animation;

    SpriteRenderer* sprite_renderer;

    float time_elapsed;
    int frame_index;
    Animation animation;
};

#endif