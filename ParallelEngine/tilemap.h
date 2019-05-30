#ifndef TILESET_H
#define TILESET_H
#include "assetloader.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vec2.h"

class TileMap {
public:
	//block types
	static const int NORMAL = 0;
	static const int BLOCKED = 1;

	TileMap(int tileWidth_, int tileHeight_) : tileWidth(tileWidth_), tileHeight(tileHeight_) {}
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(ALLEGRO_BITMAP * tileSheet);
	void render();
	void update();

	int getType(int row, int col) { 
		return collisionMap[row][col];
	}

	int getTileWidth() { return tileWidth; }
	int getTileHeight() { return tileHeight; }

	int getNumCols() { return cols; }
	int getNumRows() { return rows; }
private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> collisionMap;
	std::vector<std::vector<int>> depthMap;
	std::vector<std::vector<std::shared_ptr<ALLEGRO_BITMAP>>> tileSet;
	int width, height; // in pixels
	int tileWidth, tileHeight;
	int cols, rows; // in hexes
};


#endif