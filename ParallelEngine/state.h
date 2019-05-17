#ifndef STATE_H
#define STATE_H
#include <allegro5/allegro.h>

class GSM;

class State {
public:
	State(GSM * g) : gsm(g) {}
	virtual void render() = 0;
	virtual void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) = 0;
protected:
	GSM * gsm;
};
#endif