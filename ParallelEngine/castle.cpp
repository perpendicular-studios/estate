#include "castle.h"
void Castle::update(ALLEGRO_KEYBOARD_STATE & ks, float mouseX, float mouseY) {
	

	// update the castle's x and y to the mouse position if the player is placing the castle.
	if (placing) {
		col = tm->getTileCol(mouseX, mouseY);
		row = tm->getTileRow(mouseX, mouseY);
	}

	if (col < 0) col = 0;
	if (row < 0) row = 0;
	if (col > tm->getNumCols()) col = tm->getNumCols();
	if (row > tm->getNumRows()) row = tm->getNumRows();

	x = tm->getTileX(row, col);
	y = tm->getTileY(row, col);
}

void Castle::render() {
	// render the castle if the player is placing or has placed the building.
	if (placing || placed) {
		al_draw_bitmap(img, x, y, 0);
	}	
}