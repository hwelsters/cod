#ifndef CONTEXT_H
#define CONTEXT_H

#include "cod/graphics/animation_table.h"
#include "cod/graphics/graphics.h"
#include "cod/input/input.h"

// Mini singletons (kinda?) except I get to control exactly what has access to it.
struct Context
{
public:
    Context() : graphics(nullptr), input(nullptr) {}
    ~Context()
    {
        delete this->graphics;
        delete this->input;
    }

    AnimationTable* animator_table;
    Graphics *graphics;
    Input *input;
};

#endif