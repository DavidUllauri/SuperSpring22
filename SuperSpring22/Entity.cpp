#include "Entity.h"
#include "TDE.h"

Entity::Entity(const std::vector<std::string>& filenames):
    mImages(filenames.begin(), filenames.end())
{
    collisions.Reset();
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

bool Entity::HorizontalCollisions(Entity& other, int velocity)
{
    int directionX = (velocity < 0) ? -1 : 1;
    int oneLeft{ mXPos };
    int oneRight{ mXPos + mImages[mActiveImage].GetWidth() };
    int twoLeft{ other.GetX() };
    int twoRight{ other.GetX() + other.GetWidth() };

    int oneBottom{ mYPos };
    int oneTop{ mYPos + mImages[mActiveImage].GetHeight() };
    int twoBottom{ other.GetY() };
    int twoTop{ other.GetY() + other.GetHeight() };

    bool collideX{ false };
    if ((oneLeft <= twoLeft && twoLeft <= oneRight) ||
        (twoLeft <= oneLeft && oneLeft <= twoRight))
        collideX = true;

    bool collideY{ false };
    if ((oneBottom <= twoBottom && twoBottom < oneTop) ||
        (twoBottom <= oneBottom && oneBottom < twoTop))
        collideY = true;

    bool hit = collideX && collideY;

    if (hit)
    {
        if (directionX == 1)
            mXPos = twoLeft - mImages[mActiveImage].GetWidth();
        else if (directionX == -1)
            mXPos = twoRight;
    }
    return hit;
}

bool Entity::VerticalCollisions(Entity& other, int velocity)
{
    int directionY = (velocity > 0) ? 1 : -1;
    int oneLeft{ mXPos };
    int oneRight{ mXPos + mImages[mActiveImage].GetWidth() };
    int twoLeft{ other.GetX() };
    int twoRight{ other.GetX() + other.GetWidth() };

    int oneBottom{ mYPos };
    int oneTop{ mYPos + mImages[mActiveImage].GetHeight() };
    int twoBottom{ other.GetY() };
    int twoTop{ other.GetY() + other.GetHeight() };

    bool collideX{ false };
    if ((oneLeft <= twoLeft && twoLeft < oneRight) ||
        (twoLeft <= oneLeft && oneLeft < twoRight))
        collideX = true;

    bool collideY{ false };
    if ((oneBottom <= twoBottom && twoBottom <= oneTop) ||
        (twoBottom <= oneBottom && oneBottom <= twoTop))
        collideY = true;

    bool hit = collideX && collideY;

    if (hit)
    {
        if (directionY == 1)
        {
            mYPos = twoBottom - mImages[mActiveImage].GetHeight();

            collisions.above = true;
            collisions.below = false;
        }
        else if (directionY == -1)
        {
            mYPos = twoTop;

            collisions.above = false;
            collisions.below = true;
        }
    }
    return hit;
}
