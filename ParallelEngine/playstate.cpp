#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = std::shared_ptr<TileMap>(new TileMap(64, 32));
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadResourceSet(std::vector<const Resource*>(allResource, allResource + sizeof(allResource) / sizeof(allResource[0])));
	tm->loadTileMap("data/tilemap.ptm");
	cam = std::shared_ptr<Camera>(new Camera(500, 500, tm)); //100, 500
	bl = new BuildingList(tm);
	player = new Player();
	menu = new IGM(player, bl, tm.get());
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render();
	player->renderEntities();
	bl->render();
	menu->isoRender();

	ALLEGRO_TRANSFORM trans;

	//for mouse or isometric images add here
	al_identity_transform(&trans);
	al_translate_transform(&trans, cam->getx(), cam->gety());
	al_transform_coordinates(&trans, &mouseX, &mouseY);

	mapCoord = tm->screenToIso(mouseX, mouseY);
	screenCoord = tm->isoToScreen(mapCoord.y, mapCoord.x);

	bl->setCol(mapCoord.x);
	bl->setRow(mapCoord.y);
	menu->setCol(mapCoord.x);
	menu->setRow(mapCoord.y);

	//hover
	al_draw_bitmap(AssetLoader::manager->getImage("hover"), screenCoord.x, screenCoord.y, 0);

		//building
	Vector2f buildOffset = tm->screenToIso(menu->getBuilding()->getWidth() / 2, menu->getBuilding()->getHeight());
	buildOffset = tm->isoToScreen(buildOffset.x, buildOffset.y);
	placingCoordX = screenCoord.x + buildOffset.x;
	placingCoordY = screenCoord.y - buildOffset.y;

	bl->setx(placingCoordX);
	bl->sety(placingCoordY);

	if (bl->getPlacing() == true) { bl->placingBuilding(menu->getBuilding(), placingCoordX, placingCoordY); }
	
	if (selectedEntity) selectedEntity->renderRadius();
	
	//for static display images add here
	al_identity_transform(&trans);
	al_use_transform(&trans);

	menu->staticRender();

	//used for camera
	al_identity_transform(&trans);
	al_translate_transform(&trans, -cam->getx(), -cam->gety());
	al_use_transform(&trans);
	
	al_flip_display();
}

void PlayState::update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) {
	mouseX = ms.x;
	mouseY = ms.y;

	tm->update();
	cam->update();
	menu->update(input.leftClickDown(), input.keyClickDown(), input.keyPressed(), mouseX, mouseY, bl);

	input.update(ks, ms);

	if (input.leftClickDown()) {
		player->addTileToInventory(tm->getTile(mapCoord.y, mapCoord.x));
		Entity* clickEntity = player->entityInTile(mapCoord.y, mapCoord.x);

		if (selectedEntity && clickEntity == selectedEntity) {
			selectedEntity = NULL; // deselect
		}
		else {
			selectedEntity = clickEntity; // select
		}
	}

	cam->setLeft(al_key_down(&ks, ALLEGRO_KEY_A));
	cam->setUp(al_key_down(&ks, ALLEGRO_KEY_W));
	cam->setRight(al_key_down(&ks, ALLEGRO_KEY_D));
	cam->setDown(al_key_down(&ks, ALLEGRO_KEY_S));
}
