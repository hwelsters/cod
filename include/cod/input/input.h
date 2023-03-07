#pragma once
#ifndef INPUT_H
#define INPUT_H

#include "cod/constants/cod_keys.h"

#include <unordered_map>

class Input
{
public:
    Input();
    void process_input();

    bool is_window_should_close();
    bool is_key_pressed(COD_KEY);
    bool is_key_held(COD_KEY);
    bool is_key_released(COD_KEY);
private:
    void key_up_event(COD_KEY);
    void key_down_event(COD_KEY);
    void quit_event();

    std::unordered_map<COD_KEY, bool> pressed_keys;
    std::unordered_map<COD_KEY, bool> held_keys;
    std::unordered_map<COD_KEY, bool> released_keys;

    SDL_Event* event;
    bool window_should_close;
};

#endif