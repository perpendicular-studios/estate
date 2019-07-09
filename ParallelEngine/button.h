#ifndef BUTTON_H
#define BUTTON_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

class Button {
public:
	Button(float x1, float y1, float x2, float y2, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType, 
		ALLEGRO_COLOR fontColor, float fontX, float fontY, std::string text, int returnState_);
	
	int getState() { return returnState; }

	void drawButton();
	bool isInBounds(float x, float y);

	//variables
	int returnState;
	float  x1, y1, x2, y2;
	ALLEGRO_COLOR backgroundColor, fontColor;
	ALLEGRO_FONT* fontType;
	float fontX, fontY;
	std::string text;
};

#endif 