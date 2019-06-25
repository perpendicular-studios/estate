#ifndef DISPLAY_H
#define DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "gsm.h"
#include "assetmanager.h"
#include "playstate.h"
#include "assetloader.h"
#include "var.h"

class Display {
public:
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