#include "button.h"

Button::Button(float x1_, float y1_, float x2_, float y2_, ALLEGRO_BITMAP* bitmap_, ALLEGRO_FONT* fontType_, 
	ALLEGRO_COLOR fontColor_, std::string text_, bool visible_, MenuState returnState_) {
	bitmap = bitmap_;
	fontType = fontType_;
	fontColor = fontColor_;
	text = text_;
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	fontX = x1;
	fontY = y1;
	returnState = returnState_;
	visible = visible_;
}



bool Button::isInBounds(float x_, float y_) {
	if (x_ < x2 && x_ > x1 && y_ < y2 && y_ > y1) { return true; }
	
}

void Button::drawButton() {
	al_draw_bitmap(bitmap, x1, y1, 0);
//	al_draw_filled_rectangle(x1, y1, x2, y2, backgroundColor);
	al_draw_text(fontType, fontColor, fontX, fontY, 0, text.c_str());
}