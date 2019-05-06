#ifndef STATE_H
#define STATE_H
#include <allegro5/allegro.h>

class GSM;

class State {
public:
	State(GSM * g) : gsm(g) {}
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleInput(ALLEGRO_KEYBOARD_STATE & state) = 0;
private:
	GSM * gsm;
};
#endif