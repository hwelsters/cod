#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

struct Context;

class Component
{
public:
    Component();
    Component(Context*);

    virtual void update() = 0;
    virtual void render() = 0;

// protected:
//     Context* context;
};

#endif