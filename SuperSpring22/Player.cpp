#include "Player.h"

Player::Player(const std::vector<std::string>& filename)
    : Entity{ filename }
{
}

void Player::TurnSprite(int directionX)
{
    if (collisions.below)
    {
        if (directionX > 0 || GetActiveImage() == 2)
        {
            SetActiveImage(0);
        }
        else if (directionX < 0 || GetActiveImage() == 3)
        {
            SetActiveImage(1);
        }
    }
    else if (!collisions.below)
    {
        if (directionX > 0 || GetActiveImage() == 0)
        {
            SetActiveImage(2);
        }
        else if (directionX < 0 || GetActiveImage() == 1)
        {
            SetActiveImage(3);
        }
    }
}

void Player::ResetPlayer()
{
    SetX(0);
    SetY(700);
    collisions.Reset();
}
