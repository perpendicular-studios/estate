#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = new TileMap(64, 32);
	tm->loadTileMap("data/tilemap.ptm");
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
}


PlayState::~PlayState() {
	delete tm;
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	tm->update();
}
