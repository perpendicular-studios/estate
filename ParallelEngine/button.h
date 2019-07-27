#ifndef BUTTON_H
#define BUTTON_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "menustates.h"

class IGM;


class Button {
public:
	Button(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, MenuState returnState);

	Button(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType, 
		ALLEGRO_COLOR fontColor, std::string text, bool visible, MenuState returnState);

	MenuState getState() { return returnState; }
	std::string getText() { return text; }

	bool isVisible() { return visible; }
	void setVisible(bool b) { visible = b; }

	virtual void render() = 0;
	virtual void onClick() = 0;

	bool isInBounds(float x, float y);

protected:
	MenuState returnState;
	ALLEGRO_BITMAP* bitmap;
	float  x1, y1, x2, y2;
	ALLEGRO_COLOR fontColor;
	ALLEGRO_FONT* fontType;
	float fontX, fontY;
	std::string text;
	bool visible;


};

#endif 