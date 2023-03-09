#include "cod/components/animator.h"
#include "cod/game/entity.h"
#include "cod/utility/context.h"

Animator::Animator()
{
    this->frame_index = 0;
}

void Animator::start()
{
    this->sprite_renderer = this->entity->get_component<SpriteRenderer>();
    if (!this->is_sprite_renderer_exist()) return;

    // FOR TESTING
    Sprite new_sprite;
    new_sprite.texture = this->context->graphics->load_texture("assets/images/actors.png");
    new_sprite.source_size = Vector2(32, 32);
    new_sprite.source_position = Vector2(64, 0);
    this->sprite_renderer->set_sprite(new_sprite);
}

void Animator::render()
{
    if (!this->is_sprite_renderer_exist()) return;
    if (this->animation == nullptr) return;
}

void Animator::update()
{
    if (!this->is_sprite_renderer_exist()) return;
    if (this->animation == nullptr) return;

    printf("UPDATE\n");
    time_elapsed += this->context->timer->get_ticks();
    if (time_elapsed >= this->animation->ticks_per_frame)
    {
        this->frame_index++;
        printf("FRAME_INDEX: %d ", this->frame_index);
        printf("SIZE: %d\n", this->animation->animation.size());
        if (this->play_once) this->frame_index = std::min(this->frame_index, static_cast<int>(this->animation->animation.size() - 1));
        else this->frame_index = this->frame_index % this->animation->animation.size();
    }
}

void Animator::play_animation(int animation_ID, bool play_once)
{
    this->animation = this->context->animation_table->get_animation(animation_ID);
    this->play_once = play_once;
}

// Not a pure function. Could be and should be but I dunno
bool Animator::is_sprite_renderer_exist()
{
    if (this->sprite_renderer == nullptr) printf("Animator will not work without a SpriteRenderer\n");
    return this->sprite_renderer != nullptr;
}