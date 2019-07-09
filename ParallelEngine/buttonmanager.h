#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "mousekey.h"


class Button {
public:
	Button();
	~Button();
	void drawButton(float x, float y, ALLEGRO_COLOR color);

	MouseKey* mk;
	bool isClicked = false; 
};
#endif