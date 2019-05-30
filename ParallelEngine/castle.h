#ifndef CASTLE_H
#define CASTLE_H
#include <iostream>
#include "tilemap.h"
#include "assetloader.h"

class Castle {
public:
	Castle(std::shared_ptr<TileMap> tm_, int row, int col) : tm(tm_) {
		x = (col - row) * tm->getTileWidth() / 2;
		y = (col + row) * tm->getTileHeight() / 2;
		image = AssetLoader::manager->getImage("castle");
	}

	void render() {
		al_draw_bitmap(image, x, y, 0);
	}
private:
	ALLEGRO_BITMAP * image;
	std::shared_ptr<TileMap> tm;
	int x, y;
};
#endif