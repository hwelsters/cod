#include "cod/components/animator.h"
#include "cod/game/entity.h"

void Animator::start() 
{
    this->sprite_renderer = this->entity->get_component<SpriteRenderer>();
}

void Animator::render() {}
void Animator::update() {}