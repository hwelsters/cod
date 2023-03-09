#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "cod/graphics/sprite.h"
#include "cod/components/component.h"

struct Context;

class SpriteRenderer : public Component
{
public:
    SpriteRenderer();
    SpriteRenderer(Sprite);

    void render();
    void update();
    void set_sprite(Sprite);

    void sanity_check();

private:
    Sprite active_sprite;
};

#endif