#pragma once
#include "Entity.h"
class GameMap
{
public:
	GameMap(const std::string filename);
	void CreateMap();
	void LoadMapData(const std::string filename);
	void Draw();
	
	std::vector<Entity> mMap;
	int enemyPosX{ 0 };
	int enemyPosY{ 0 };
	int starPosX{ 0 };
	int starPosY{ 0 };
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
