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
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	player->render();

	if (canClick) {
		al_draw_tinted_bitmap(hoverImage, al_map_rgba_f(blocked ? 1 : 0, blocked ? 0 : 1, blocked ? 0 : 1, 1), hover.x, hover.y, 0);
	}

	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	cam->update(player->getx() / 2, player->gety() / 2);

	ALLEGRO_TRANSFORM T;
	al_identity_transform(&T);
	al_translate_transform(&T, -cam->getx(), -cam->gety());
	al_use_transform(&T);

	float mouseX = al_get_mouse_state_axis(&ms, 0);
	float mouseY = al_get_mouse_state_axis(&ms, 1);

	al_identity_transform(&T);
	al_translate_transform(&T, cam->getx(), cam->gety());
	al_transform_coordinates(&T, &mouseX, &mouseY);

	int tileSize = tm->getTileSize();

	hover = tm->getTileFromPosition(mouseX, mouseY);
	int row = hover.y / tileSize;
	int col = hover.x / tileSize;

	if (row > tm->getNumRows() - 1) row = tm->getNumRows() - 1;
	if (col > tm->getNumCols() - 1) col = tm->getNumCols() - 1;

	blocked = tm->getType(row, col) == TileMap::BLOCKED;
	canClick = player->getTargetLocation() == player->getPosition();

	if (al_mouse_button_down(&ms, 1) && !blocked && canClick) {
		player->setTargetLocation(hover.x, hover.y);
	}

	player->update();
	tm->update();
}
