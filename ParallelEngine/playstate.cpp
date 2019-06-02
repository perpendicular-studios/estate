#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = std::shared_ptr<TileMap>(new TileMap(64, 32));
	cam = std::shared_ptr<Camera>(new Camera(0, 0, 64, 32));

	std::string id = std::to_string(Var::getUniqueBuildingID());
	buildings[id] = (std::shared_ptr<Castle>(new Castle(tm, id)));
	buildingPlacing = id;
	buildings[buildingPlacing]->enablePlacing();
	placing = true;

	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadTileMap("data/tilemap.ptm");
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));

	tm->render();
	for (auto it = buildings.begin(); it != buildings.end(); it++) {
		it->second->render();
	}

	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	tm->update();
	cam->update();

	float mouseX = ms.x;
	float mouseY = ms.y;

	std::cout << "mouseX: " << mouseX << ", mouseY: " << mouseY << std::endl;

	ALLEGRO_TRANSFORM trans;
	
	al_identity_transform(&trans);
	al_translate_transform(&trans, cam->getx(), cam->gety());
	al_transform_coordinates(&trans, &mouseX, &mouseY);
	
	std::cout << " translated mouseX: " << mouseX << ", translated mouseY: " << mouseY << std::endl;

	al_identity_transform(&trans);
	al_translate_transform(&trans, -cam->getx(), -cam->gety());
	al_use_transform(&trans);

	for (auto it = buildings.begin(); it != buildings.end(); it++) {
		it->second->update(ks, mouseX, mouseY);
	}

	if (al_mouse_button_down(&ms, 1) && placing) {
		buildings[buildingPlacing]->setPlaced();
		placing = false;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_SPACE) && !placing) {
		std::string id = std::to_string(Var::getUniqueBuildingID());
		buildings[id] = std::shared_ptr<Castle>(new Castle(tm, id));
		buildingPlacing = id;
		buildings[buildingPlacing]->enablePlacing();
		placing = true;
	}


	cam->setLeft(al_key_down(&ks, ALLEGRO_KEY_A));
	cam->setUp(al_key_down(&ks, ALLEGRO_KEY_W));
	cam->setRight(al_key_down(&ks, ALLEGRO_KEY_D));
	cam->setDown(al_key_down(&ks, ALLEGRO_KEY_S));

}
