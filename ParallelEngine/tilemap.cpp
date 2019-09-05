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

void TileMap::loadResourceSet(std::vector<const Resource*> allResources) {
	resourceSet.resize(allResources.size());
	std::cout << "Loading " << allResources.size() << " Resources." << std::endl;
	for (int i = 0; i < resourceSet.size(); i++) {
		std::cout << "Loading tile_" + allResources[i]->getName() << std::endl;
		resourceSet[i] = std::shared_ptr<ALLEGRO_BITMAP>(allResources[i]->getTileImage(), al_destroy_bitmap);
	}

}

void TileMap::loadTileMap(std::string path) {
	std::cout << "Loading Tilemap..." << std::endl;
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
		cols = std::stoi(line);
		std::getline(file, line);
		rows = std::stoi(line);

		width = cols * tileWidth;
		height = rows * tileHeight;

		std::cout << "Tilemap is " << cols << " x " << rows << "." << std::endl;
		std::cout << "Tilemap is " << width << " pixels wide and " << height << " pixels tall." << std::endl;

		/* Resize all the maps to the proper dimensions of the map */
		map.resize(rows);
		for (int i = 0; i < map.size(); i++) {
			map[i].resize(cols);
		}

		collisionMap.resize(rows);
		for (int i = 0; i < collisionMap.size(); i++) {
			collisionMap[i].resize(cols);
		}

		occupiedMap.resize(rows);
		for (int i = 0; i < occupiedMap.size(); i++) {
			occupiedMap[i].resize(cols);
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
	}
	std::cout << "Finished Loading Tilemap!" << std::endl;
}

bool TileMap::checkOccupied(int row, int col) {
	return (occupiedMap[row][col] == BLOCKED);
}

void TileMap::setOccupyStatus(int row, int col, int status) {
	occupiedMap[row][col] = status;
}

void TileMap::update() {}

void TileMap::render(int currX, int currY) {
	// render tilemap
	
	Vector2f isoCoord = screenToIso(currX + Var::WIDTH /2, currY + Var::HEIGHT /2);
	
	int rowStart = isoCoord.y - 25;
	int colStart = isoCoord.x - 25;
	if (rowStart < 0) { rowStart = 0; }
	if (colStart < 0) { colStart = 0; }
	isoCoord.x += 25;
	isoCoord.y += 25;
	if (isoCoord.y > rows) { isoCoord.y = rows; }
	if (isoCoord.x > cols) { isoCoord.x = cols; }
	for (int row = rowStart; row < isoCoord.y; row++) {
		for (int col = colStart; col < isoCoord.x; col++) {
			int rc = map[row][col];
			int r = rc / cols;
			int c = rc % cols; 

			Vector2f screenCoord = isoToScreen(row, col);
			
			// draws the base tile
			if (rc < TileMap::NUM_TILES) {
				al_draw_bitmap(tileSet[r][c].get(), screenCoord.x, screenCoord.y, 0);
			}
			else { 
				int resourceIndex = rc - TileMap::NUM_TILES;
			    al_draw_bitmap(resourceSet[resourceIndex].get(), screenCoord.x, screenCoord.y, 0);
			}

			if (checkOccupied(row, col)) {
				al_draw_bitmap(AssetLoader::manager->getImage("radius"), screenCoord.x, screenCoord.y, 0);
			}
		}
	}	
}

TileMap::~TileMap() {}