#include "button.h"

Button::Button(float x1_, float y1_, float x2_, float y2_, ALLEGRO_COLOR backgroundColor_, ALLEGRO_FONT* fontType_, 
	ALLEGRO_COLOR fontColor_, float fontX_, float fontY_, std::string text_, int returnState_) {
	backgroundColor = backgroundColor_;
	fontType = fontType_;
	fontColor = fontColor_;
	fontX = fontX_;
	fontY = fontY_;
	text = text_;
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	returnState = returnState_;
}

bool Button::isInBounds(float x_, float y_) {
	if (x_ < x2 && x_ > x1 && y_ < y2 && y_ > y1) return true;
}

void Button::drawButton() {
	al_draw_filled_rectangle(x1, y1, x2, y2, backgroundColor);
	al_draw_text(fontType, fontColor, fontX, fontY, 0, text.c_str());
}