#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = std::shared_ptr<TileMap>(new TileMap(64, 32));
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
	cam = std::shared_ptr<Camera>(new Camera(0, 0, tm)); //100, 500

}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();

	ALLEGRO_TRANSFORM trans;

	al_identity_transform(&trans);
	al_translate_transform(&trans, -cam->getx(), -cam->gety());
	al_use_transform(&trans);

	al_identity_transform(&trans);
	al_translate_transform(&trans, cam->getx(), cam->gety());
	al_transform_coordinates(&trans, &mouseX, &mouseY);

	Vector2f mapCoord = tm->screenToIso(mouseX, mouseY);
	Vector2f screenCoord = tm->isoToScreen(mapCoord.y, mapCoord.x);

	hoverX = screenCoord.x;
	hoverY = screenCoord.y;

	al_draw_bitmap(AssetLoader::manager->getImage("hover"), hoverX, hoverY, 0);
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	tm->update();
	cam->update();

	mouseX = ms.x;
	mouseY = ms.y;

	cam->setLeft(al_key_down(&ks, ALLEGRO_KEY_A));
	cam->setUp(al_key_down(&ks, ALLEGRO_KEY_W));
	cam->setRight(al_key_down(&ks, ALLEGRO_KEY_D));
	cam->setDown(al_key_down(&ks, ALLEGRO_KEY_S));

	if (al_mouse_button_down(&ms, 0)) {
		
	}
}
