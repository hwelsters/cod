#include <stdexcept>
#include <algorithm>

#include "cod/game/entity.h"
#include "cod/components/component.h"
#include "cod/utility/context.h"

Entity::Entity() {}

Entity::~Entity()
{
    for (Component *component : components) delete component;
}

void Entity::init() {}

void Entity::start() 
{
    auto entity_start = [](Component *entity) { entity->start(); };
    std::for_each(this->components.begin(), this->components.end(), entity_start);
}

void Entity::update()
{
    auto entity_update = [](Component *entity) { entity->update(); };
    std::for_each(this->components.begin(), this->components.end(), entity_update);
}

void Entity::render()
{
    auto entity_render = [](Component *entity) { entity->render(); };
    std::for_each(this->components.begin(), this->components.end(), entity_render);
}

void Entity::add_component(Component *component)
{
    if (component == nullptr)
        throw std::invalid_argument("add_component argument [component] cannot be null.");

    component->set_context(this->context);
    component->set_entity(this);

    this->components.push_back(component);
}

Vector2 Entity::get_position()
{
    return this->position;
}

void Entity::set_context(Context* context)
{
    this->context = context;
}