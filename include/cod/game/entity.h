#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "cod/math/vector2.h"

class Component;
enum ComponentType : unsigned int;
struct Context;

class Entity
{
public:
    Entity();
    Entity(Context*);
    ~Entity();

    void update();
    void render();

    void add_component(Component *);

    template <typename T>
    T *get_component();

    Vector2 get_position();

    friend Component;
protected:
    std::vector<Component *> components;
    Context* context;

    Vector2 position;
};

#endif