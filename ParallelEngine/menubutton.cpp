#include "menubutton.h"
#include "igm.h"

MenuButton::MenuButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible_, MenuState returnState_, IGM* igm_) :
	Button(x1, y1, x2, y2, bitmap, visible_, returnState_), igm(igm_) {}

void MenuButton::onClick() {
	igm->setState(returnState);
}

void MenuButton::render() {
	al_draw_bitmap(bitmap, x1, y1, 0);
	if (text.length() > 0 && fontType != NULL) {
		al_draw_text(fontType, fontColor, fontX, fontY, 0, text.c_str());
	}
}