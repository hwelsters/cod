#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Component;
enum ComponentType : unsigned int;
struct Context;

class Entity
{
public:
    Entity();
    // Entity(Context);
    ~Entity();

    void update();
    void render();

    void add_component(Component *);

    template <typename T>
    T *get_component();

protected:
    std::vector<Component *> components;
    // Context* context;
};

#endif