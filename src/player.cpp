#include "cod/cod.h"
#include "player.h"

void Player::init()
{
    Sprite player_sprite;
    player_sprite.texture = this->context->graphics->load_texture("assets/images/actors.png");
    player_sprite.source_size = Vector2(32, 32);
    player_sprite.source_position = Vector2(0, 0);

    this->context->animation_table->add_animation(
        0,
        this->context->graphics->load_texture("assets/images/actors.png"),
        7,
        Vector2(32, 32),
        Vector2(0, 0),
        60);
    Animator *animator = new Animator();

    animator->play_animation(0, true);
    this->add_component(animator);

    SpriteRenderer *sprite_renderer = new SpriteRenderer(player_sprite);
    this->add_component(sprite_renderer);

    this->position = Vector2(50, 50);
}