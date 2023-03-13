#include <algorithm>

#include "cod/scene/scene.h"

#include <iostream>

Scene::Scene() {}

Scene::~Scene()
{
    auto entity_init = [](Entity *entity) { delete entity; };
    std::for_each(this->entity_list.begin(), this->entity_list.end(), entity_init);
}

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

void Scene::start()
{
    auto entity_start = [](Entity *entity) { entity->start(); };
    std::for_each(this->entity_list.begin(), this->entity_list.end(), entity_start);
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

void Scene::set_context(Context *context) { this->context = context; }