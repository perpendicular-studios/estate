#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = new TileMap(32);
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
	hoverImage = AssetLoader::manager->getImage("hover");
	
	//Load in entities
	entityLoader = new EntityLoader(tm);
	currentEntity = EntityLoader::manager->getEntity("player");
}


PlayState::~PlayState() {
	delete entityLoader;
	delete tm;
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	currentEntity->render();
	EntityLoader::manager->getEntity("castle")->render();
	if (canClick) {
		al_draw_tinted_bitmap(hoverImage, al_map_rgba_f(blocked ? 1 : 0, blocked ? 0 : 1, blocked ? 0 : 1, 1), hover.x, hover.y, 0);
	}
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	cam->update(currentEntity->getx(), currentEntity->gety());

	ALLEGRO_TRANSFORM T;
	al_identity_transform(&T);
	al_translate_transform(&T, -cam->getx(), -cam->gety());
	al_use_transform(&T);

	float mouseX = ms.x;
	float mouseY = ms.y;

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
	canClick = currentEntity->getTargetLocation() == currentEntity->getPosition();

	if (al_mouse_button_down(&ms, 1) && !blocked && canClick) {
		currentEntity->setTargetLocation(hover.x, hover.y);
	}
	currentEntity->update();
	tm->update();
}
