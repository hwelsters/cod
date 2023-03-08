#include <SDL.h>
#include <SDL_image.h>

#include "cod/graphics/graphics.h"
#include "cod/graphics/sprite.h"
#include "cod/config/config.h"
#include "cod/math/vector2.h"

Graphics::Graphics() : Graphics(Config()) {}

Graphics::Graphics(Config config)
{
    this->window = SDL_CreateWindow(config.name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.screen_width, config.screen_height, 0);
    this->renderer = SDL_CreateRenderer(this->window, 0, 0);

    SDL_SetRenderDrawColor(this->renderer, config.background_color.red, config.background_color.green, config.background_color.blue, 255);
    this->sprite_scale = config.sprite_scale;
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

SDL_Texture* Graphics::load_texture(std::string file_path)
{
    if (this->textures.count(file_path) != 0) return this->textures[file_path];
    
    SDL_Surface* loaded_surface = IMG_Load(file_path.c_str());
    if (loaded_surface == nullptr) printf("Failed to load surface %s! SDL_image error: %s", file_path.c_str(), IMG_GetError());

    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(this->renderer, loaded_surface);
    SDL_FreeSurface(loaded_surface);
    this->textures[file_path] = new_texture;
    return this->textures[file_path];
}

void Graphics::blit_sprite(Sprite sprite, Vector2 position)
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

    SDL_RenderCopy(this->renderer, sprite.texture, &source_rect, &destination_rect);
}