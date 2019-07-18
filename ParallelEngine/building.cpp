#include "building.h"

Building::Building(ALLEGRO_BITMAP* bitmap_, int width_, int height_) : bitmap(bitmap_), width(width_), height(height_) {
	for (int i = width; i % 64 != 0; i++) {
		colWidth = i/64;
	}
	for (int j = height; j % 32 != 0; j++) {
		rowHeight = j/32;
	}
}

void Building::draw(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::draw_interface(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

