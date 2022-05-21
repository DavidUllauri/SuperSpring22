#pragma once

#include "TDE.h"
#include <vector>

struct CollisionInfo
{
	bool left, right;
	bool above, below;

	void Reset() {
		left = right = false;
		above = below = false;
	}
};

class Entity
{
public:
	Entity(const std::vector<std::string>& filename);

	int GetX() const;
	int GetY() const;
	int GetZ() const;
	int GetSolid() const;
	int GetActiveImage() const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int xPos);
	void SetY(int yPos);
	void SetZ(int zPos);
	void SetSolid(bool solid);
	void SetActiveImage(int activeImage);

	void Draw();

	bool HorizontalCollisions(Entity& other, int velocity);
	bool VerticalCollisions(Entity& other, int velocity);

	CollisionInfo collisions;
private:
	int mXPos{ 0 };
	int mYPos{ 800 };
	int mZPos{ 0 };

	bool isSolid{ true };

	int mActiveImage{ 0 };

	std::vector<TDE::Sprite> mImages;
};

