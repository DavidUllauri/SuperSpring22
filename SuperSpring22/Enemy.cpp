#include "Enemy.h"

Enemy::Enemy(std::vector<std::string> filenames)
    : Entity{ filenames }
{
}

void Enemy::Move(int speed, float deltaTime)
{
    if (mMoveBuffer > 1.5) // Wait 1.5 seconds
    {
        if (speed > 0 || GetActiveImage() == 2)
        {
            SetActiveImage(0);
        }
        else if (speed < 0 || GetActiveImage() == 3)
        {
            SetActiveImage(1);
        }
        SetX(GetX() + speed);
    }
    else
    {
        mMoveBuffer += deltaTime;
    }
}

void Enemy::ResetEnemy(const int xPos, const int yPos)
{
    SetX(700);
    SetActiveImage(0);
    mMoveBuffer = 0.0f;
}
