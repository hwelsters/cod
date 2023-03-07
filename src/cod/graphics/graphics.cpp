#include <SDL.h>

#include "cod/graphics/graphics.h"
#include "cod/config/config.h"
#include "cod/constants/globals.h"

Graphics::Graphics() : Graphics(Config()) {}

Graphics::Graphics(Config config)
{
    this->window = SDL_CreateWindow(config.name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.screen_width, config.screen_height, 0);
    this->renderer = SDL_CreateRenderer(this->window, 0, 0);

    SDL_SetRenderDrawColor(this->renderer, config.background_color.red, config.background_color.green, config.background_color.blue, 255);
    this->sprite_scale = config.
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    this->window = nullptr;
    this->renderer = nullptr;
}

void Graphics::clear()
{
    SDL_RenderClear(this->renderer);
}

void Graphics::render()
{
    SDL_RenderPresent(this->renderer);
}

void Graphics::blitSprite(Sprite sprite, Vector2 position)
{
    SDL_Rect source_rect;
    source_rect.x = sprite.source_position.x;
    source_rect.y = sprite.source_position.y;
    source_rect.w = sprite.source_size.x;
    source_rect.h = sprite.source_size.y;

    SDL_Rect destination_rect;
    destination_rect.x = position.x * this->sprite_scale;
    destination_rect.y = position.y * this->sprite_scale;
    destination_rect.w = sprite.source_size.x * this->sprite_scale;
    destination_rect.h = sprite.source_size.y * this->sprite_scale;

    SDL_RenderCopy(this->renderer, sprite.texture, source_rect, destination_rect);
}