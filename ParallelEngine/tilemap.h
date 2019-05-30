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

	TileMap(int tileWidth_, int tileHeight_) : tileWidth(tileWidth_), tileHeight(tileHeight_) { waterY = 4, speed = 0.02f, dy = speed, time = 0; }
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(ALLEGRO_BITMAP * tileSheet);
	void render();
	void update();

	int getType(int row, int col) { 
		return collisionMap[row][col];
	}

	int getTileCol(int x) {}

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
	int cols, rows; // in tiles
	float waterY, speed, dy; // y offset of animation of water
	float time;
};


#endif