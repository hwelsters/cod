#ifndef PLAYER_H
#define PLAYER_H

#include "cod/game/entity.h"

class Player : public Entity
{
public:
    void init() override;
};

#endif