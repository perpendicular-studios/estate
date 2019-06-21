#include "building.h"

Building::Building(std::shared_ptr<TileMap> tm_, int id_) : tm(tm_), id(id_) {
	
}

void Building::draw(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::draw_interface(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::update() {

}