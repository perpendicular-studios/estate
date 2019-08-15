#ifndef TILESET_H
#define TILESET_H
#include "assetloader.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "vec2.h"
#include "resources.h"

class TileMap {
public:
	//block types
	static const int NORMAL = 0;
	static const int BLOCKED = 1;
	static const int NUM_TILES = 5;

	TileMap(int tileWidth_, int tileHeight_) : tileWidth(tileWidth_), tileHeight(tileHeight_) { 
		cols = rows = 0; height = width = 0;
	}
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(ALLEGRO_BITMAP * tileSheet);
	void loadResourceSet(std::vector<const Resource*> allResources);
	void render();
	void update();

	int getType(int row, int col) { 
		return collisionMap[row][col];
	}

	int getTile(int row, int col) {
		return map[row][col];
	}

	bool isResource(int row, int col) {
		return getTile(row, col) == 5 || getTile(row, col) == 6 || getTile(row, col) == 7;
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

	bool checkOccupied(int row, int col);
	void setOccupyStatus(int row, int col, int status);

	int getTileWidth() { return tileWidth; }
	int getTileHeight() { return tileHeight; }

	int getNumCols() { return cols; }
	int getNumRows() { return rows; }

private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> collisionMap;
	std::vector<std::vector<bool>> occupiedMap;
	std::vector<std::vector<std::shared_ptr<ALLEGRO_BITMAP>>> tileSet;
	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> resourceSet;
	int width, height; // in pixels
	int tileWidth, tileHeight;
	int cols, rows; // in tiles
};


#endif