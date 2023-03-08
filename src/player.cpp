#include "cod/cod.h"
#include "player.h"

Player::Player() : Entity(new Context()) {}

Player::Player(Context* context) : Entity(context) 
{
    Sprite player_sprite;
    player_sprite.texture = context->graphics->load_texture("assets/images/actors.png");
    player_sprite.source_size = Vector2(32, 32);
    player_sprite.source_position = Vector2(0,0);

    SpriteRenderer* sprite_renderer = new SpriteRenderer(player_sprite);
    this->add_component(sprite_renderer);
    this->position = Vector2(100, 100);
    printf("HERE 1\n");
}