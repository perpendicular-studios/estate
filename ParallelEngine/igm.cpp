#include "igm.h"
#include "resources.h"

IGM::IGM(Player* player_, BuildingList* bl_) : player(player_), bl(bl_) {
	player->getInventory()->addResource(IRON_ORE);
	player->getInventory()->addResource(WOOL);
	currState = defaultState;
	sampleCastle = new Castle(-1);
	sampleTC = new Towncenter(-1);
	newBuilding = sampleCastle;

	bm = new ButtonManager;
	build = new MenuButton(200, 200, 250, 250, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Build", 0, productionState);
	flag = new MenuButton(0, 0, 100, 100, AssetLoader::manager->getImage("flagbg"), basic_font20, al_map_rgb(255, 255, 255), "Flag", 0, overviewState);
	production = new MenuButton(0, 100, 50, 150, AssetLoader::manager->getImage("productionbg"), basic_font20, al_map_rgb(255, 255, 255), "Prod", 0, buildState);
	exit = new MenuButton(225, 150, 250, 175, AssetLoader::manager->getImage("x"), basic_font20, al_map_rgb(255, 255, 255), "X", 0, defaultState);
	exit1 = new MenuButton(Var::WIDTH - 25, 40, Var::WIDTH, 65, AssetLoader::manager->getImage("x"), basic_font20, al_map_rgb(255, 255, 255), "X", 0, defaultState);
	misc = new MenuButton(Var::WIDTH - 50, 0, Var::WIDTH, 50, AssetLoader::manager->getImage("miscbg"), basic_font20, al_map_rgb(255, 255, 255), "MISC", 0, inventory); // should open an inventory
	castle = new BuildButton(15, 200, 65, 250, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Castle", 0, sampleCastle);
	towncenter = new BuildButton(80, 200, 130, 250, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Towncenter", 0, sampleTC);

	bm->addButton(build);
	bm->addButton(flag);
	bm->addButton(production);
	bm->addButton(exit);
	bm->addButton(exit1);
	bm->addButton(misc);
	bm->addButton(castle);
	bm->addButton(towncenter);
}

void IGM::gameBackground() {
	al_draw_bitmap(AssetLoader::manager->getImage("resources_menu"), Var::WIDTH - 550, 0, 0);
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 550 + 40      , 8, 0, std::to_string(player->getFood()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 550 + 125 + 40, 8, 0, std::to_string(player->getGold()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 550 + 250 + 40, 8, 0, std::to_string(player->getStone()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 550 + 375 + 40, 8, 0, std::to_string(player->getWood()).c_str());
	al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(0, 0, 0));								//flag black background
	misc->setVisible(true);
	production->setVisible(true);
	flag->setVisible(true);
}

void IGM::menuBackground() {
	al_draw_filled_rectangle(0, 150, 250, 550, al_map_rgb(255, 204, 0));
	al_draw_rectangle(1, 150, 250, 550, al_map_rgb(153, 77, 0), 3);
	exit->setVisible(true);
}

// default state
void IGM::defaultMenu() {}

// overview state
void IGM::overviewMenu() {
	menuBackground();
	build->setVisible(true);
	castle->setVisible(true);
	towncenter->setVisible(true);
}

// diplo state
void IGM::diploMenu() {}

// production state, by default the first menu is the building menu when clciking production button
void IGM::productionMenu() { 
	buildingMenu(); 
}

// build state
void IGM::buildingMenu() {
	menuBackground();
	build->setVisible(true);
	castle->setVisible(true);
	towncenter->setVisible(true);
}

void IGM::inventoryMenu() {
	exit1->setVisible(true);
	std::vector<std::vector<const Resource*>> miscResources = player->getInventory()->getMiscResources();
	al_draw_filled_rectangle(Var::WIDTH - 550, 40, Var::WIDTH, 40 + miscResources.size() * 35, al_map_rgb(255, 204, 0));
	al_draw_rectangle(Var::WIDTH - 549, 41, Var::WIDTH - 1, 40 + miscResources.size() * 35 - 1, al_map_rgb(153, 77, 0), 3);
	for (int i = 0; i < miscResources.size(); i++) {
		int h = 50 + i * 25;
		std::string itemDesc = (miscResources[i][0]->getName() + " - " + std::to_string(miscResources[i].size()));
		miscResources[i][0]->drawImage(miscResources[i][0]->getName(), Var::WIDTH - 225 - (itemDesc.size() * 20 + 28) / 2, h);
		al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 225 - (itemDesc.size() * 20 - 28) / 2, h, 0,
			itemDesc.c_str());
	}
}

void IGM::stateSelector(MenuState state) {
	switch (state)
	{
	case reset:
		break;
	case defaultState:
		defaultMenu();
		break;
	case overviewState:
		overviewMenu();
		break;
	case productionState:
		productionMenu();
		break;
	case buildState:
		buildingMenu();
		break;
	case placingBuilding:
		break;
	case placingBuildingTest:
		break;
	case inventory:
		inventoryMenu();
		break;
	default:
		defaultMenu();
		break;
	}
}

void IGM::update(bool clicked, bool keyClicked, std::string key, int x, int y, BuildingList* bl){ 
	prevState = currState;

	if (clicked) {
		if (currState == placingBuilding) { prevState = currState = placingBuildingTest; }

		//iterate through all current clickables and buttons
		for (int i = 0; i < bm->size(); i++) {
			// check if button is properly clicked
			if (bm->getList()[i]->isInBounds(x, y) == true && bm->getList()[i]->getVisible() == true) {
				currState = bm->getList()[i]->getState();
				buttonIndex = i;
			}
		}
		if (currState == placingBuilding) {
			//set template building info
			newBuildingPlaceHolder = (BuildButton*)bm->getList()[buttonIndex];
			newBuilding = newBuildingPlaceHolder->getBuilding();
			buildingType = newBuildingPlaceHolder->getText();
			bl->setCurrBuilding(newBuilding);
			bl->setPlacing(true);
		}

		//when you click something else while placing building
		if (prevState == placingBuildingTest && currState != prevState && currState != placingBuilding) {
			//relativeClicks = 0;
			bl->setPlacing(false);
		}

		//check if placing building in valid location 
		if (currState == placingBuildingTest) {
			if (bl->checkPlacingBounds(newBuilding)) {
				std::cout << "Cannot place in this location \n";
			}
			//valid placement
			else {
				std::cout << "Placing Building \n";
				bl->update(newBuilding, buildingType);
				bl->setPlacing(false);
				currState = buildState;
			}
		}
	}

	if (keyClicked) {
		if ((currState == placingBuilding || currState == placingBuildingTest) && key == "esc") { 
			bl->setPlacing(false);
			currState = buildState; 
		}
	}
}

void IGM::staticRender() {
	//setting all buttons to be non-visible
	for (int i = 0; i < bm->size(); i++) {
		bm->getList()[i]->setVisible(false);
	}

	gameBackground();
	stateSelector(currState);

	//drawing buttons in currState that are visible
	for (int i = 0; i < bm->size(); i++) { 
		if (bm->getList()[i]->getVisible() == true) { bm->getList()[i]->drawButton(); }
	}
}

void IGM::isoRender() {


}