#ifndef ANIMATOR_h
#define ANIMATOR_H

#include "cod/components/component.h"
#include "cod/components/sprite_renderer.h"

class Animator : public Component 
{
public: 
    void start() override;
    void render() override;
    void update() override;
    
private:
    SpriteRenderer* sprite_renderer;
};

#endif