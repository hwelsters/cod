#include <iostream>

#include "cod/cod.h"

int main(int argc, char** argv)
{
    Config config;
    config.name = "Eggosan's splendid adventure";

    Game game = Game(config);
    return 0;
}