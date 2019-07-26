#ifndef MOUSKEY_H
#define MOUSKEY_H

#include <allegro5/allegro.h>
#include <string>

class InputHandler {
public:
	void update(ALLEGRO_KEYBOARD_STATE & ks_, ALLEGRO_MOUSE_STATE & ms_);
	bool rightClickDown() { return rightClick; }
	bool leftClickDown() { return leftClick; }
	bool keyClickDown() { return keyClick; }
	std::string keyPressed() { return keyPress; }

private:
	ALLEGRO_MOUSE_STATE ms;
	ALLEGRO_KEYBOARD_STATE ks;
	int prevMouseState, currMouseState;
	std::string prevKeyState, currKeyState;
	bool rightClick, leftClick;
	bool keyClick;
	std::string keyPress;
};
#endif 


