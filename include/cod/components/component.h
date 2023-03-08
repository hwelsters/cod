#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

struct Context;
class Entity;

class Component
{
public:
    Component();
    Component(Context*, Entity*);

    virtual void update() = 0;
    virtual void render() = 0;

    friend Entity;

protected:
    void set_context(Context*);
    void set_entity(Entity*);
    
    Context* context;
    Entity* entity;
};

#endif