#include "Entity.h"

Entity::Entity(const std::vector<std::string>& filenames):
    mImages(filenames.begin(), filenames.end())
{
}

int Entity::GetX() const
{
    return mXPos;
}

int Entity::GetY() const
{
    return mYPos;
}

int Entity::GetZ() const
{
    return mZPos;
}

int Entity::GetSolid() const
{
    return isSolid;
}

void Entity::SetX(int xPos)
{
    mXPos = xPos;
}

void Entity::SetY(int yPos)
{
    mYPos = yPos;
}

void Entity::SetZ(int zPos)
{
    mZPos = zPos;
}

void Entity::SetSolid(bool solid)
{
    isSolid = solid;
}
