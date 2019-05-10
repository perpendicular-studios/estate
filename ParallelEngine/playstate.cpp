#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	player = new Player(AssetLoader::manager->getImage("player"), 250, 250, 10);
	tile = new Tile(AssetLoader::manager->getImage("image"));
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	player->render();
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks) {
	player->update(ks);
}
