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

	TileMap(int tileWidth_, int tileHeight_) : tileWidth(tileWidth_), tileHeight(tileHeight_) { waterY = 4, speed = 0.02f, dy = speed, time = 0; cols = rows = 0; height = width = 0; }
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(ALLEGRO_BITMAP * tileSheet);
	void render();
	void update();

	int getType(int row, int col) { 
		return collisionMap[row][col];
	}

	Vector2f screenToIso(int x, int y) {

		float col = (x / (tileWidth / 2) + y / (tileHeight / 2)) / 2;
		float row = (y / (tileHeight / 2) - x / (tileWidth / 2)) / 2;
		
		if (x < 0) row++;			// for mouse offset adjustment when negative
		if (col < 0) col = 0;
		if (col > cols - 1) col = cols - 1;
		if (row < 0) row = 0;
		if (row > rows - 1) row = rows - 1;

		return Vector2f(col, row);
	}

	Vector2f isoToScreen(int row, int col) { 
		return Vector2f(
			(col - row) * tileWidth / 2,
			(col + row) * tileHeight / 2);
	}

	int getTileWidth() { return tileWidth; }
	int getTileHeight() { return tileHeight; }

	int getNumCols() { return cols; }
	int getNumRows() { return rows; }

private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> collisionMap;
	std::vector<std::vector<std::shared_ptr<ALLEGRO_BITMAP>>> tileSet;
	int width, height; // in pixels
	int tileWidth, tileHeight;
	int cols, rows; // in tiles
	float waterY, speed, dy; // y offset of animation of water
	float time;
};


#endif