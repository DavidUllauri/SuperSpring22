#pragma once

#include "TDE.h"
#include <vector>

class Entity
{
public:
	Entity(const std::vector<std::string>& filename);

	int GetX() const;
	int GetY() const;
	int GetZ() const;
	int GetSolid() const;

	void SetX(int xPos);
	void SetY(int yPos);
	void SetZ(int zPos);
	void SetSolid(bool solid);

private:
	int mXPos{ 0 };
	int mYPos{ 0 };
	int mZPos{ 0 };

	bool isSolid{ true };

	std::vector<TDE::Sprite> mImages;
};

