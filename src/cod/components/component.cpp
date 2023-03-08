#include "cod/components/component.h"
#include "cod/utility/context.h"
#include "cod/game/entity.h"

Component::Component() {}

void Component::set_context(Context *context) { this->context = context; }
void Component::set_entity(Entity *entity) { this->entity = entity; }