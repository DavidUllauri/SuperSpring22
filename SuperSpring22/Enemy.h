#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
public:
    Enemy(std::vector<std::string> filenames);
    void Move(int speed, float deltaTime);
    void ResetEnemy(const int xPos, const int yPos);
private:
    float mMoveBuffer{ 0.0f }; // Time before enemy can move
};

