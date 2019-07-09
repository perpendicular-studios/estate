#include "button.h"

Button::Button(float x1_, float y1_, float x2_, float y2_, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType, ALLEGRO_COLOR fontColor, float fontX, float fontY, const char* text, int returnState_) {
	al_draw_filled_rectangle(x1_, y1_, x2_, y2_, backgroundColor);
	al_draw_text(fontType, fontColor, fontX, fontY, 0, text);
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	returnState = returnState_;
}

bool Button::isInBounds(float x_, float y_) {
	if (x_ < x2 && x_ > x1 && y_ < y2 && y_ > y1) return true;
}