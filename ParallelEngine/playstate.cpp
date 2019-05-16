#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = new TileMap(32);
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
	player = new Player(tm);
}

PlayState::~PlayState() {
	delete player;
	delete tm;
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	player->render();
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks) {
	player->update();

	tm->update();
}
