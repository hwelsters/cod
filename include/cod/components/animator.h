#ifndef ANIMATOR_h
#define ANIMATOR_H

#include "cod/components/component.h"

class Animator : public Component 
{
public: 
    Animator();

    void render() override;
    void update() override;
};

#endif