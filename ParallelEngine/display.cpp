
#include "display.h"
#include "playstate.h"
#include <iostream>
#include "assetloader.h"

Display::Display(GSM * g) : gsm(g) {
	al_init();
	// Load in assets
	AssetLoader * loader = new AssetLoader();
	display = al_create_display(640, 480);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());

	//set initial state
	gsm->push(new PlayState(gsm));

	// Update
	al_start_timer(timer);
	while (running) {
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		ALLEGRO_KEYBOARD_STATE keyState;
		al_get_keyboard_state(&keyState);

		//Close button pressed, close
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = false;
		}

		if (event.type == ALLEGRO_EVENT_TIMER) {
			gsm->render();
			gsm->update(keyState);
		}

	}
}

Display::~Display() {
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_event_queue(queue);
	al_destroy_timer(timer);
}