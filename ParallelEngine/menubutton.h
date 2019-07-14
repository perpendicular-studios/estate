#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "button.h"
#include "menustates.h"

class MenuButton : public Button {
public:
	MenuButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
		ALLEGRO_COLOR fontColor, std::string text, bool visible, MenuState returnState_);
};

#endif 