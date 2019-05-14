#ifndef TILESET_H
#define TILESET_H
#include "tile.h"
#include "assetloader.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

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

	int getType(int row, int col) { return collisionMap[row][col]; };
	int getTileSize() { return tileSize; }

	int getNumCols() { return width; }
	int getNumRows() { return height; }
private:
	std::vector<std::vector<int>> graphicMap;
	std::vector<std::vector<int>> collisionMap;
	std::vector<std::vector<Tile>> tileSet;
	int width, height;
	int tileSize;
	int numTilesAcross;
};


#endif