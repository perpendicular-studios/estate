#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	player = new Player(AssetLoader::manager->getImage("image"), 250, 250, 10);
	tile = new Tile(AssetLoader::manager->getImage("image"));
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	player->render();
	tile->render(0, 0);
	al_flip_display();
}

void PlayState::handleInput(ALLEGRO_KEYBOARD_STATE & ks) {
	player->update(ks);
}

void PlayState::update() {

}
