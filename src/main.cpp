#include <iostream>

#include "cod/cod.h"
#include "player.h"

int main(int argc, char** argv)
{
    Config config;
    config.name = "Eggosan's splendid adventure";
    config.sprite_scale = 3;
    config.background_color = RGB(31, 16, 42);

    Game game = Game(config);

    return 0;
}