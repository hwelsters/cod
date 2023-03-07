#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

#include "cod/config/config.h"

class Graphics
{
public:
    Graphics();
    Graphics(Config);
    ~Graphics();

    void clear();
    void render();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    float sprite_scale;
};

#endif