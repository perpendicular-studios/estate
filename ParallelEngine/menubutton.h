#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "button.h"
#include "menustates.h"

class MenuButton : public Button {
public:
	MenuButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, MenuState returnState_, IGM* igm);

	void render() override;
	void onClick() override;

private:
	IGM* igm;
};

#endif 