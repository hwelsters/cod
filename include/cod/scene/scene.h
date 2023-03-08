#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "cod/game/entity.h"

class Game;

class Scene
{
public:
    Scene();
    void add_entity(Entity*);

    void init();
    void update();
    void render();

    friend Game;
private:
    void set_context(Context*);

    std::vector<Entity*> entity_list;
    Context* context;
};

#endif