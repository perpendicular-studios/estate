#include "tilemap.h"

// Initialize 2d hex array with hex images
void TileMap::loadTileSet(ALLEGRO_BITMAP * tileSheet) {
	int tileCols = al_get_bitmap_width(tileSheet) / tileWidth;
	int tileRows = al_get_bitmap_height(tileSheet) / tileHeight;

	tileSet.resize(tileRows);
	for (int i = 0; i < tileSet.size(); i++) {
		tileSet[i].resize(tileCols);
	}

	for (int row = 0; row < tileRows; row++) {
		for (int col = 0; col < tileCols; col++) {
			tileSet[row][col] = std::shared_ptr<ALLEGRO_BITMAP>(al_create_sub_bitmap(tileSheet, tileWidth * col, tileHeight * row, tileWidth, tileHeight), al_destroy_bitmap);
		}
	}
}

void TileMap::loadTileMap(std::string path) {
	/*
	<width> 
	<height>
	<graphic map>
	<collision map>
	<depth map>
	*/

	std::ifstream file(path);
	if (file.is_open()) {
		std::string line;
		std::getline(file, line);
		cols = std::stoi(line);
		std::getline(file, line);
		rows = std::stoi(line);

		width = cols * tileWidth;
		height = rows * tileHeight;

		/* Resize all the maps to the proper dimensions of the map */
		map.resize(rows);
		for (int i = 0; i < map.size(); i++) {
			map[i].resize(cols);
		}

		collisionMap.resize(rows);
		for (int i = 0; i < collisionMap.size(); i++) {
			collisionMap[i].resize(cols);
		}

		depthMap.resize(rows);
		for (int i = 0; i < depthMap.size(); i++) {
			depthMap[i].resize(cols);
		}

		/* Parse in data of the maps */
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				file >> map[row][col];
			}
		}
		std::getline(file, line);
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				file >> collisionMap[row][col];
			}
		}
		std::getline(file, line);
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				file >> depthMap[row][col];
			}
		}
		
	}

}

void TileMap::update() {
	// moves down
	if (waterY >= 6) {
		time += 1;
		if (time < 60) {
			dy = 0;
		}
		else {
			time = 0;
			dy = -speed;
		}
	}

	// moves up
	if (waterY <= 3.5) {
		time += 1;
		if (time < 60) {
			dy = 0;
		}
		else {
			time = 0;
			dy = speed;
		}
	}

	waterY += dy;
}

void TileMap::render() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			int rc = map[row][col];
			int r = rc / cols;
			int c = rc % cols; 

			int heightScale = 4;
			int depth = depthMap[row][col];
			
			int yOffset = (c == 0) ? waterY : -depth * heightScale;

			// draw tiles under base tile (if there is one)
			for (int i = 0; i < depth; i++) {
				al_draw_bitmap(tileSet[r][c].get(), (col - row) * tileWidth / 2, (col + row) * (tileHeight - 6) / 2 - i * heightScale, 0);
			}

			// draws the base tile
			al_draw_bitmap(tileSet[r][c].get(), (col - row) * tileWidth / 2, (col + row) * (tileHeight - 6) / 2 + yOffset, 0);
		}
	}
}

TileMap::~TileMap() {}