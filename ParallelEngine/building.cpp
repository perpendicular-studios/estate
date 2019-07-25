#include "building.h"

Building::Building(ALLEGRO_BITMAP* bitmap_, int width_, int height_) : bitmap(bitmap_), width(width_), height(height_) {
	//for whole number cols and rows
	colWidth = (width + 63) / 64;			
	rowHeight = (height + 63) / 64;
}

void Building::draw(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::draw_interface(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

