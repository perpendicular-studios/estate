#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = new TileMap(32);
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
	player = new Player(tm);
	hoverImage = AssetLoader::manager->getImage("hover");
}

PlayState::~PlayState() {
	delete player;
	delete tm;
}

void PlayState::render() {
	int tileSize = tm->getTileSize();

	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	player->render();
	al_draw_bitmap(hoverImage, hover.x, hover.y, 0);

	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	int mouseX = al_get_mouse_state_axis(&ms, 0);
	int mouseY = al_get_mouse_state_axis(&ms, 1);

	if (al_mouse_button_down(&ms, 1)) {
		player->setTargetLocation(hover.x, hover.y);
	}

	hover = tm->getTileFromPosition(mouseX, mouseY);
	player->update();
	tm->update();
}
