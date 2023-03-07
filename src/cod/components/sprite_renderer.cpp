#include "cod/components/sprite_renderer.h"
#include "cod/utility/context.h"
#include "cod/graphics/graphics.h"

SpriteRenderer::SpriteRenderer() : active_sprite(Sprite()) {}
SpriteRenderer::SpriteRenderer(Sprite active_sprite) : active_sprite(active_sprite) {}

void SpriteRenderer::render() 
{
    this->context.graphics->blitS
}

void SpriteRenderer::update() {}