#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#include "cod/graphics/rgb.h"

struct Config
{
public:
    Config() : Config("", 640, 480, RGB(), 1, 60) {}
    Config(std::string name,
           int screen_width,
           int screen_height,
           RGB background_color,
           float sprite_scale,
           int max_fps) : name(name),
                      screen_width(screen_width),
                      screen_height(screen_height),
                      background_color(background_color),
                      sprite_scale(sprite_scale),
                      max_fps(max_fps) {}

    RGB background_color;
    std::string name;
    int screen_width;
    int screen_height;
    int max_fps;
    float sprite_scale;
};

#endif