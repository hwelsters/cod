#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "cod/graphics/sprite.h"
#include "cod/components/component.h"

class SpriteRenderer : Component
{
public:
    SpriteRenderer();
    SpriteRenderer(Sprite);

    void render() override;
    void update() override;

private:
    Sprite active_sprite;
};

#endif