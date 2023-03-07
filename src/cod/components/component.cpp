#include "cod/components/component.h"
#include "cod/utility/context.h"

Component::Component() : Component(Context()) {}

Component::Component(Context* context) context(context) {}