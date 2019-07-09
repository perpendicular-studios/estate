#ifndef BUTTON_H
#define BUTTON_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Button {
public:
	Button(float x1, float y1, float x2, float y2, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType, ALLEGRO_COLOR fontColor, float fontX, float fontY, const char* text, int returnState_);
	
	int getState() { return returnState; }

	bool isInBounds(float x, float y);

	//variables
	int returnState;
	int x1, y1, x2, y2;
};

#endif 