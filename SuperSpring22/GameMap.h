#pragma once
#include "Entity.h"
class GameMap
{
public:
	void CreateMap();
	void LoadMapData(const std::string filename);
	void Draw();
	std::vector<Entity> mMap;
private:
	std::vector<std::vector<int>> mMapData{ // Map is made upside down
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
};
