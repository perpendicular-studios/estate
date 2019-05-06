#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	player = new Entity(AssetLoader::manager->getImage("image"), 250, 250, 10);
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	al_draw_bitmap(player->getImage() , player->getx(), player->gety(), 0);
	al_flip_display();
}

void PlayState::handleInput(ALLEGRO_KEYBOARD_STATE & ks) {
	if (al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		player->moveRight();
	}
	
	if (al_key_down(&ks, ALLEGRO_KEY_LEFT)) {
		player->moveLeft();
	}
}

void PlayState::update() {

}
