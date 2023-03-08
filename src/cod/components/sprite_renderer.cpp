#include "cod/components/sprite_renderer.h"
#include "cod/utility/context.h"
#include "cod/graphics/graphics.h"
#include "cod/game/entity.h"

SpriteRenderer::SpriteRenderer() : SpriteRenderer(Sprite()) {}
SpriteRenderer::SpriteRenderer(Sprite active_sprite) : active_sprite(active_sprite) {}

void SpriteRenderer::render() 
{
    this->context->graphics->blit_sprite(this->active_sprite, this->entity->get_position());
}

void SpriteRenderer::update() {}

void SpriteRenderer::sanity_check() 
{
    printf("CHECKED SANITY\n");
}