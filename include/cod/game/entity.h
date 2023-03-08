#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "cod/math/vector2.h"
#include "cod/utility/utils.h"

class Component;
class Scene;
enum ComponentType : unsigned int;
struct Context;

class Entity
{
public:
    Entity();
    ~Entity();

    virtual void init();
    void start();
    void update();
    void render();

    void add_component(Component *);

    template <class T>
    T *get_component()
    {
        for (Component *component : components)
            if (Utils::is_same_type<decltype(component), T>())
                return static_cast<T*>(component);
        return nullptr;
    }

    Vector2 get_position();

    friend Scene;

protected:
    void set_context(Context *);

    std::vector<Component *> components;
    Context *context;

    Vector2 position;
};

#endif