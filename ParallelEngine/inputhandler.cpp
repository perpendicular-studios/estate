#include "inputhandler.h"

void InputHandler::update(ALLEGRO_KEYBOARD_STATE& ks_, ALLEGRO_MOUSE_STATE& ms_) {
	ms = ms_;
	ks = ks_;

	//mouse single clicks
	prevMouseState = currMouseState;
	if (ms.buttons & 1) { currMouseState = 1; }
	else if (ms.buttons & 2) { currMouseState = 2; }
	else currMouseState = 0;

	if (prevMouseState != currMouseState && prevMouseState == 1) { leftClick = true; }
	else if (prevMouseState != currMouseState && prevMouseState == 2) { rightClick = true; }
	else rightClick = leftClick = false;

	//keyboard single presses
	prevKeyState = currKeyState;
	//b key
	if (al_key_down(&ks, ALLEGRO_KEY_B)) { currKeyState = "b"; }
	else currKeyState = ' ';

	if (prevKeyState != currKeyState && currKeyState == "b") { 
		keyPress = "b"; 
		keyClick = true;
	}
	else keyClick = false;

	//escape key
	if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) { currKeyState = "esc"; }
	else currKeyState = ' ';

	if (prevKeyState != currKeyState && currKeyState == "esc") {
		keyPress = "esc";
		keyClick = true;
	}
	else keyClick = false;

}