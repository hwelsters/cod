#include <algorithm>

#include "cod/scene/scene.h"

#include <iostream>

Scene::Scene() {}

void Scene::add_entity(Entity *entity)
{
    entity->set_context(this->context);
    this->entity_list.push_back(entity);
}

void Scene::init()
{
    auto entity_init = [](Entity *entity) { entity->init(); };
    std::for_each(this->entity_list.begin(), this->entity_list.end(), entity_init);
}

void Scene::update()
{
    auto entity_update = [](Entity *entity) { entity->update(); };
    std::for_each(this->entity_list.begin(), this->entity_list.end(), entity_update);
}

void Scene::render()
{
    auto entity_render = [](Entity *entity) { entity->render(); };
    std::for_each(this->entity_list.begin(), this->entity_list.end(), entity_render);
}

void Scene::set_context(Context* context) { this->context = context; }