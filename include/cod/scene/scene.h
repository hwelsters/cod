#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "cod/game/entity.h"

class Scene
{
public:
    Scene();
    void add_entity(Entity*);

    void update();
    void render();

private:
    std::vector<Entity*> entity_list;
};

#endif