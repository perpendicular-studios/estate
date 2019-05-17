#include "tilemap.h"

/* 
Every tile in the tileset is assigned a number 
For a 256x256 tilesheet with 32x32 sized tiles, the there are 8 tiles in the rows and 8 in the columns
The top left tile will be assigned 0
The bottom right tile will be assigned 63
These numbers are then used in the tile map to identify which tile to use from the tileset.
*/
void TileMap::loadTileSet(ALLEGRO_BITMAP * tileSheet) {
	int width = al_get_bitmap_width(tileSheet);
	int height = al_get_bitmap_height(tileSheet);

	assert(width % tileSize == 0 && height % tileSize == 0); //require that the width and height of the tilesheet is divisible by the tileSize

	tileSet.resize(height / tileSize);
	for (int i = 0; i < tileSet.size(); i++) { 
		tileSet[i].resize(width / tileSize);
	}

	std::cout << "tileSet size: " << tileSet.size() << std::endl;
	for (int row = 0; row < tileSet.size(); row++) {
		std::cout << "tileSet[" << row << "] size: " << tileSet[row].size() << std::endl;
		for (int col = 0; col < tileSet[row].size(); col++) {
			tileSet[row][col] = 
				Tile(al_create_sub_bitmap(
					tileSheet,
					col * tileSize,
					row * tileSize,
					tileSize, tileSize));
		}
	}
}

void TileMap::loadTileMap(std::string path) {
	/*
	<width> 
	<height>
	<graphic map>
	<collision map>
	*/

	std::ifstream file(path);
	if (file.is_open()) {
		std::string line;
		std::getline(file, line);
		width = std::stoi(line);
		std::getline(file, line);
		height = std::stoi(line);

		graphicMap.resize(height);
		for (int i = 0; i < graphicMap.size(); i++) {
			graphicMap[i].resize(width);
		}

		collisionMap.resize(height);
		for (int i = 0; i < collisionMap.size(); i++) {
			collisionMap[i].resize(width);
		}
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				file >> graphicMap[row][col];
			}
		}

		std::cout << std::endl;
		//skip a line 
		std::getline(file, line);
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				file >> collisionMap[row][col];
			}
		}
	}

}

void TileMap::update() {}

Vector2i TileMap::getTileFromPosition(int x, int y) {
	int c = (int)(x / tileSize);
	int r = (int) (y / tileSize);
	return Vector2i(c * tileSize, r * tileSize);
}

void TileMap::render() {

	for (int row = 0; row < graphicMap.size(); row++) {
		for (int col = 0; col < graphicMap[row].size(); col++) {
			int rc = graphicMap[row][col];
			int r = rc / tileSet[0].size();
			int c = rc % tileSet[0].size();

			tileSet[r][c].render(tileSize * col, tileSize * row);
		}
	}
}

TileMap::~TileMap() {}