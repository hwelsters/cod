#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>

#include "cod/config/config.h"
#include "cod/utility/context.h"

class Input;
class Graphics;
class Scene;

class Game
{
public:
    Game();
    Game(Config);
    ~Game();

    void game_loop();

    void process_input();
    void update();
    void render();

    void set_active_scene(Scene*);
private:
    Context* context;
    Scene* active_scene;

    int max_fps;
    std::string name;
};

#endif