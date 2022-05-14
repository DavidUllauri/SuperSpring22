#include "Entity.h"
#include "TDE.h"

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

int Entity::GetActiveImage() const
{
    return mActiveImage;
}

int Entity::GetWidth() const
{
    return mImages[mActiveImage].GetWidth();
}

int Entity::GetHeight() const
{
    return mImages[mActiveImage].GetHeight();
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

void Entity::SetActiveImage(int activeImage)
{
    mActiveImage = activeImage;
}

void Entity::Draw()
{
    TDE::Renderer::Draw(mImages[mActiveImage], mXPos, mYPos, mZPos);
}
