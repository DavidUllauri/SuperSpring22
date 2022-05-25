#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    Player(const std::vector<std::string>& filename);
    void TurnSprite(int directionX);
    void ResetPlayer();
};
