#ifndef BUTTON_H
#define BUTTON_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "menustates.h"

class Button {
public:
	//variables
	float  x1, y1, x2, y2;
	ALLEGRO_COLOR backgroundColor, fontColor;
	ALLEGRO_FONT* fontType;
	float fontX, fontY;
	std::string text;
	
	MenuState returnState;
	int action;

	//functions
	Button(float x1, float y1, float x2, float y2, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType, 
		ALLEGRO_COLOR fontColor, float fontX, float fontY, std::string text, MenuState returnState_);
	Button(float x1_, float y1_, float x2_, float y2_, ALLEGRO_COLOR backgroundColor_, ALLEGRO_FONT* fontType_,
		ALLEGRO_COLOR fontColor_, float fontX_, float fontY_, std::string text_, int action_);

	MenuState getState() { return returnState; }

	void drawButton();
	bool isInBounds(float x, float y);

	
};

#endif 