#ifndef TILESET_H
#define TILESET_H
#include "tile.h"
#include "assetloader.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vec2.h"
#include "camera.h"

class TileMap {
public:
	//block types
	static const int NORMAL = 0;
	static const int BLOCKED = 1;

	TileMap(int tileSize) { this->tileSize = tileSize; }
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(ALLEGRO_BITMAP * tileSheet);
	void render();
	void update();

	int getType(int row, int col) { 
		std::cout << "checking type of (row, col): (" << row << ", " << col << ")..." << std::endl;
		if (col > collisionMap[0].size() || row > collisionMap.size()) {
			return 0;
		}
		return collisionMap[row][col];
	}

	int getTileSize() { return tileSize; }

	int getNumCols() { return width; }
	int getNumRows() { return height; }

	Vector2i getTileFromPosition(int x, int y);
private:
	std::vector<std::vector<int>> graphicMap;
	std::vector<std::vector<int>> collisionMap;
	std::vector<std::vector<Tile>> tileSet;
	int width, height;
	int tileSize;
	int numTilesAcross;
};


#endif