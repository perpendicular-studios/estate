#ifndef DISPLAY_H
#define DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "gsm.h"
#include "assetmanager.h"

class Display {
public:
	static const int WIDTH = 640;
	static const int HEIGHT = 360;

	Display(GSM * gsm);
	~Display();
private:
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE * queue;
	ALLEGRO_TIMER * timer;
	GSM * gsm;
	bool running = true;

};
#endif DISPLAY_H