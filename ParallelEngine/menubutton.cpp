#include "menubutton.h"

MenuButton::MenuButton(float x1, float y1, float x2, float y2, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType,
	ALLEGRO_COLOR fontColor, std::string text, MenuState returnState_) : 
	Button(x1, y1, x2, y2, backgroundColor, fontType, fontColor, text, returnState_) {}