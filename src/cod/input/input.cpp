#include "cod/input/input.h"

Input::Input()
{
    this->event = new SDL_Event();
    this->window_should_close = false;
}

void Input::process_input()
{
    this->pressed_keys.clear();
    this->released_keys.clear();

    while (SDL_PollEvent(this->event))
    {
        switch (this->event->type)
        {
        case SDL_QUIT:
            this->quit_event();
            break;
        case SDL_KEYDOWN:
            this->key_down_event(static_cast<COD_KEY>(this->event->key.keysym.scancode));
            break;
        case SDL_KEYUP:
            this->key_up_event(static_cast<COD_KEY>(this->event->key.keysym.scancode));
            break;
        }
    }
}

bool Input::is_window_should_close() { return this->window_should_close; }
bool Input::is_key_pressed(COD_KEY key) { return this->pressed_keys[key]; }
bool Input::is_key_held(COD_KEY key) { return this->held_keys[key]; }
bool Input::is_key_released(COD_KEY key) { return this->released_keys[key]; }

void Input::key_up_event(COD_KEY cod_key)
{
    this->released_keys[cod_key] = true;
    this->held_keys[cod_key] = false;
}

void Input::key_down_event(COD_KEY cod_key)
{
    this->pressed_keys[cod_key] = true;
    this->held_keys[cod_key] = true;
}

void Input::quit_event()
{
    this->window_should_close = true;
}