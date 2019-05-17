#ifndef STATE_H
#define STATE_H
#include <allegro5/allegro.h>
#include "camera.h"
#include "var.h"

class GSM;

class State {
public:
	State(GSM * g) : gsm(g) {
		//xmin, xmax, ymin, ymax
		cam = new Camera(Var::WIDTH / 2, Var::HEIGHT / 2, 32, 32, 0, 640, 0, 720);
	}

	virtual void render() = 0;
	virtual void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) = 0;
protected:
	GSM * gsm;
	Camera * cam;
};
#endif