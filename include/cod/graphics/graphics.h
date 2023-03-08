#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

#include <unordered_map>
#include <string>

#include "cod/config/config.h"

class Sprite;
struct Vector2;

class Graphics
{
public:
    Graphics();
    Graphics(Config);
    ~Graphics();

    void clear();
    void render();
    void blit_sprite(Sprite, Vector2);

    SDL_Texture* load_texture(std::string);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    std::unordered_map<std::string, SDL_Texture*> textures;

    float sprite_scale;
};

#endif