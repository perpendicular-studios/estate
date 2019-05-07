#include "tile.h"
Tile::Tile(ALLEGRO_BITMAP * image) : baseImage(image) {}

void Tile::render(int x, int y) {
	al_draw_bitmap(baseImage, 0, 0, 0);

}

Tile::~Tile() {

}