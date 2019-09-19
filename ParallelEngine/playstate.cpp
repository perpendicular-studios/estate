#include "playstate.h"
#include "assetloader.h"
#include <iostream>

PlayState::PlayState(GSM * gsm) : State(gsm) {
	tm = std::shared_ptr<TileMap>(new TileMap(64, 32));
	tm->loadTileSet(AssetLoader::manager->getImage("tileset"));
	tm->loadResourceSet(std::vector<const Resource*>(allResource, allResource + sizeof(allResource) / sizeof(allResource[0])));
	tm->loadTileMap("data/tilemap.ptm");
	//tm->loadTileMap("data/europe.ptm");
	cam = std::shared_ptr<Camera>(new Camera(1000, 1000, tm)); //100, 500
	bl = new BuildingList(tm);
	player = new Player();
	menu = new IGM(player, bl, tm.get());
}

void PlayState::render() {
	al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
	tm->render(cam->getx(), cam->gety());
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

	hoverTile = tm->getTile(mapCoord.y, mapCoord.x);
	hoverEntity = player->entityInTile(mapCoord.y, mapCoord.x);

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
	
	//for static display images add here
	al_identity_transform(&trans);
	al_use_transform(&trans);

	menu->staticRender();

	// resource hover (tile id is always >= NUM_TILES if tile is a resource)
	if (hoverTile >= TileMap::NUM_TILES) {
		int resourceIndex = hoverTile - TileMap::NUM_TILES;
		const Resource* selectedResource = allResource[resourceIndex];
		al_draw_bitmap(AssetLoader::manager->getImage("popup"), Var::WIDTH / 4 - 75, 0, 0);
		std::string resourceName = selectedResource->getName();
		resourceName[0] = toupper(resourceName[0]);
		al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH / 4 , 5, 0, resourceName.c_str());
		al_draw_bitmap(selectedResource->getTileImage(), Var::WIDTH / 4 - 70, 10, 0);
		if (selectedResource->getType() == Resource::GENERAL) {
			std::string yield = "Yield / Second: " + std::to_string(((const GeneralResource*)selectedResource)->getYield());
			al_draw_text(basic_font12, al_map_rgb(63, 235, 75), Var::WIDTH / 4, 25, 0, yield.c_str());
		}
		else {
			al_draw_text(basic_font12, al_map_rgb(247, 82, 22), Var::WIDTH / 4, 25, 0, ((const MiscResource*)selectedResource)->getDescription().c_str());
		}
	}

	if (hoverEntity && !selectedEntity) {
		al_draw_bitmap(AssetLoader::manager->getImage("popup"), Var::WIDTH / 4 - 75, 0, 0);
		al_draw_bitmap(hoverEntity->getImage(), Var::WIDTH / 4 - 64, 10, 0); 
		al_draw_text(basic_font12, al_map_rgb(247, 82, 22), Var::WIDTH / 4, 15, 0, hoverEntity->getEntityTypeString().c_str());
	}
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
	player->update();
	menu->update(input.leftClickDown(), input.rightClickDown(), input.keyClickDown(), input.keyPressed(), mouseX, mouseY);

	input.update(ks, ms);

	cam->setLeft(al_key_down(&ks, ALLEGRO_KEY_A));
	cam->setUp(al_key_down(&ks, ALLEGRO_KEY_W));
	cam->setRight(al_key_down(&ks, ALLEGRO_KEY_D));
	cam->setDown(al_key_down(&ks, ALLEGRO_KEY_S));
}
