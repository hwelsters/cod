#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>

#include "cod/config/config.h"
#include "cod/utility/context.h"

class Input;
class Graphics;

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
private:
    Context context;
    std::string name;
};

#endif