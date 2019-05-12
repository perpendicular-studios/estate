#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	player = new Player(AssetLoader::manager->getImage("player"), 250, 250);
	tm = new TileMap(32);
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	player->render();
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks) {
	player->update(ks);
	tm->update();
}
