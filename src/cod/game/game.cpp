#include "cod/game/game.h"
#include "cod/input/input.h"
#include "cod/graphics/graphics.h"

Game::Game() : Game(Config()) {}

Game::Game(Config config)
{
    this->context.graphics = new Graphics(config);
    this->context.input = new Input();

    this->game_loop();
}

Game::~Game()
{
    delete this->graphics;
    delete this->input;
}

void Game::game_loop()
{
    while (!this->input->is_window_should_close())
    {
        this->graphics->clear();
        this->input->process_input();
        this->graphics->render();
    }
}