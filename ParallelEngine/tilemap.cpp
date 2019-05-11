#include "tilemap.h"

/* 
Every tile in the tileset is assigned a number 
For a 256x256 tilesheet with 32x32 sized tiles, the there are 8 tiles in the rows and 8 in the columns
The top left tile will be assigned 0
The bottom right tile will be assigned 63
These numbers are then used in the tile map to identify which tile to use from the tileset.
*/
void TileMap::loadTileSet(std::string path) {
	ALLEGRO_BITMAP * tileSheet = al_load_bitmap(path.c_str());
	int width = al_get_bitmap_width(tileSheet);
	int height = al_get_bitmap_height(tileSheet);

	assert(width % tileSize == 0 && height % tileSize == 0); //require that the width and height of the tilesheet is divisible by the tileSize

	int numTilesX = width / tileSize, numTilesY = height / tileSize;
	tileSet.resize(numTilesX * numTilesY);

	for (int i = 0; i < tileSet.size(); i++) {
		tileSet[i] =
			new Tile(al_create_sub_bitmap(
				tileSheet,
				(i % numTilesX) * tileSize,
				(i % numTilesY) * tileSize,
				tileSize, tileSize));
	}
}

void TileMap::loadTileMap(std::string path) {
	/*
	<width> 
	<height>
	<tile size>
	<tileset path>
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
		std::getline(file, line);
		tileSize = std::stoi(line);
		std::getline(file, line);
		loadTileSet(line);

		graphicMap.resize(height);
		for (int i = 0; i < graphicMap.size(); i++) {
			graphicMap[i].resize(width);
		}

		collisionMap.resize(height);
		for (int i = 0; i < collisionMap.size(); i++) {
			collisionMap[i].resize(width);
		}

		while (!file.eof()) {
			for (int row = 0; row < height; row++) {
				for (int col = 0; col < width; col++) {
					file >> graphicMap[row][col];
				}
			}
		}
	}
}

void TileMap::update() {

}

void TileMap::render() {
	for (int row = 0; row < graphicMap.size(); row++) {
		for (int col = 0; col < graphicMap[row].size(); col++) {
			tileSet[graphicMap[row][col]]->render(tileSize * col, tileSize * row);
		}
	}
}

TileMap::~TileMap() {
	//delete the memory allocated for the tiles
	for (int i = 0; i < tileSet.size(); i++) {
		delete tileSet[i];
	}
}