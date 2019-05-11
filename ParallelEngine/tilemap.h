#ifndef TILESET_H
#define TILESET_H
#include <vector>
#include "tile.h"
#include <string>
#include <fstream>

class TileMap {
public:
	TileMap() {}
	~TileMap();

	void loadTileMap(std::string path);
	void loadTileSet(std::string path);
	void render();
	void update();
private:
	std::vector<std::vector<int>> graphicMap;
	std::vector<std::vector<int>> collisionMap;
	std::vector<Tile *> tileSet;
	int width, height;
	int tileSize;
};


#endif