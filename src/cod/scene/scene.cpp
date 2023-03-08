#include <algorithm>

#include "cod/scene/scene.h"

#include <iostream>

Scene::Scene() {}

void Scene::add_entity(Entity *entity)
{
    this->entity_list.push_back(entity);
}

void Scene::update()
{
    // auto entity_update = [](Entity *entity) { entity->update(); };
    // std::for_each(entity_list.begin(), entity_list.end(), entity_update);
}

void Scene::render()
{
    printf("HERE 2\n");
    // auto entity_render = [](Entity *entity) { entity->render(); };
    // std::for_each(entity_list.begin(), entity_list.end(), entity_render);
    for(Entity* entity : this->entity_list) entity->render();
    printf("HERE 3\n");
}