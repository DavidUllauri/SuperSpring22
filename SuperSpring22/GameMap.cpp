#include "GameMap.h"
#include <sstream>

void GameMap::CreateMap()
{
	int width = mMapData[0].size();
	int height = mMapData.size();

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (mMapData[row][col] == 1) // 1 is solid
			{
				Entity tempTile{ {"assets/img/tile.png"} };
				tempTile.SetX(col * 100);
				tempTile.SetY(row * 100);
				mMap.push_back(tempTile);
			}
		}
	}
}

void GameMap::LoadMapData(const std::string filename)
{
	mMapData.clear();

	int currTile;

	std::string line;
	std::ifstream ifs(filename);
	if (ifs)
	{
		while (std::getline(ifs, line)) // read each line from file
		{
			std::istringstream sstream(line);
			std::vector<int> row;
			while (sstream >> currTile) // get each number
				row.push_back(currTile);
			mMapData.insert(mMapData.begin(), row); // Insert backwards. TODO: change to stack<vector<int>>
		}
	}
}

void GameMap::Draw()
{
	for (Entity& tile: mMap)
	{
		tile.Draw();
	}
}
