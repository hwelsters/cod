#include "cod/game/game.h"
#include "cod/input/input.h"
#include "cod/graphics/graphics.h"
#include "cod/scene/scene.h"

// TESTING
#include "player.h"

Game::Game() : Game(Config()) {}

Game::Game(Config config)
{
    this->context = new Context();
    this->context->graphics = new Graphics(config);
    this->context->input = new Input();

    // TEST
    this->set_active_scene(new Scene());
    this->active_scene->add_entity(new Player());

    this->game_loop();
}

Game::~Game()
{
    delete this->context;
}

void Game::game_loop()
{
    this->active_scene->init();

    while (!this->context->input->is_window_should_close())
    {
        this->context->graphics->clear();
        this->context->input->process_input();

        this->active_scene->update();

        this->active_scene->render();
        this->context->graphics->render();
    }
}

void Game::set_active_scene(Scene* active_scene)
{
    this->active_scene = active_scene;
    this->active_scene->set_context(this->context);
}