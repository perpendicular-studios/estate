#ifndef MOUSKEY_H
#define MOUSKEY_H

#include <allegro5/allegro.h>

class InputHandler {
public:
	void update(ALLEGRO_KEYBOARD_STATE & ks_, ALLEGRO_MOUSE_STATE & ms_);
	bool rightClickDown() { return rightClick; }
	bool leftClickDown() { return leftClick; }

private:
	ALLEGRO_MOUSE_STATE ms;
	ALLEGRO_KEYBOARD_STATE ks;
	int prevMouseState, currMouseState;
	char prevKeyState, currKeyState;
	bool rightClick, leftClick;
	bool b;

};
#endif 


