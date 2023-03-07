#include <stdexcept>

#include "cod/game/entity.h"
#include "cod/components/component.h"
#include "cod/constants/component_type.h"
#include "cod/utility/utils.h"

// Entity::Entity() : Entity(Context()) {}

// Entity::Entity(Context context) {}

Entity::~Entity()
{
    for (Component *component : components)
        delete component;
}

void Entity::add_component(Component *component)
{
    if (component == nullptr)
        throw std::invalid_argument("add_component argument [component] cannot be null.");

    this->components.push_back(component);
}

template <typename T>
T *Entity::get_component()
{
    for (Component *component : components)
        if (Utils::is_same_type<decltype(component), T>())
            return component;
}

void Entity::update()
{
    for (Component *component : components)
        component->update();
}

void Entity::render()
{
    for (Component *component : components)
        component->render();
}