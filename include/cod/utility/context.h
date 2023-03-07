#ifndef CONTEXT_H
#define CONTEXT_H

#include "cod/graphics/graphics.h"
#include "cod/input/input.h"

// Mini singletons (kinda?) except I get to control exactly what has access to it.
struct Context
{
public:
    Context() : graphics(nullptr), input(nullptr);

    Graphics *graphics;
    Input *input;
};

#endif