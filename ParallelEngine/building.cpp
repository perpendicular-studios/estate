#include "building.h"

Building::Building(ALLEGRO_BITMAP* bitmap_, int width_, int height_) : bitmap(bitmap_), width(width_), height(height_) {
	//for whole number cols and rows
	colWidth = (width + 63) / 64;			
	rowHeight = (height + 63) / 64;
}

void Building::draw(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::drawBuildingHP() {
	float percentage = ((float)currHp / hp);
	percentage = percentage * 75;
	al_draw_filled_rectangle(Var::WIDTH - 160, 255, Var::WIDTH - 75, 270, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(Var::WIDTH - 155, 260, Var::WIDTH - 155 + percentage, 265, al_map_rgb(0, 255, 0));
}

void Building::drawBuildingWindowBackground() {
	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 120, 175, ALLEGRO_ALIGN_CENTRE, buildingTypeString.c_str());
	al_draw_scaled_bitmap(bitmap, 0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), Var::WIDTH - 145, 200, 50, 50, 0);
	drawBuildingHP();

	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 240, 300, 0, "Units");
	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 240, 475, 0, "Queue");
}
