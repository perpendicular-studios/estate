#include "igm.h"

IGM::IGM(Player* player_, BuildingList* bl_, TileMap* tm_) : player(player_), bl(bl_), tm(tm_) {
	player->getInventory()->addMiscResource(IRON_ORE, 3);
	player->getInventory()->addMiscResource(CLOTH, 1);
	currState = DEFAULTSTATE;
	sampleCastle = new Castle(-1);
	sampleTC = new Towncenter(-1);
	sampleMarket = new Market(-1);
	samplePeasant = new Peasant(tm, player, 20, 0, 0, 0, 0, 0, 0);
	sampleKnight = new Knight(tm, 20, 0, 0, 0, 0, 0, 0);
	newBuilding = sampleCastle;

	bm = new ButtonManager;
	buildingbm = new ButtonManager;
	build = new MenuButton(250, 200, 300, 250, AssetLoader::manager->getImage("basicbutton"), false, PRODUCTIONSTATE, this);
	flag = new MenuButton(0, 0, 100, 100, AssetLoader::manager->getImage("flagbg"), false, OVERVIEWSTATE, this);
	production = new MenuButton(0, 100, 50, 150, AssetLoader::manager->getImage("productionbg"), false, BUILDSTATE, this);
	exit = new MenuButton(275, 150, 300, 175, AssetLoader::manager->getImage("x"), false, DEFAULTSTATE, this);
	exit1 = new MenuButton(Var::WIDTH - 25, 40, Var::WIDTH, 65, AssetLoader::manager->getImage("x"), false, DEFAULTSTATE, this);
	misc = new MenuButton(Var::WIDTH - 50, 0, Var::WIDTH, 50, AssetLoader::manager->getImage("miscbg"), 0, INVENTORY, this); // should open an inventory
	castle = new BuildButton(15, 200, 65, 250, AssetLoader::manager->getImage("basicbutton"), false, sampleCastle, player, this);
	towncenter = new BuildButton(80, 200, 130, 250, AssetLoader::manager->getImage("basicbutton"), false, sampleTC, player, this);
	market = new BuildButton(145, 200, 195, 250, AssetLoader::manager->getImage("basicbutton"), false, sampleMarket, player, this);
	rightExit = new MenuButton(Var::WIDTH - 300, 150, Var::WIDTH - 275, 175, AssetLoader::manager->getImage("x"), false, DEFAULTSTATE, this);

	peasant = new UnitButton(Var::WIDTH - 290, 325, Var::WIDTH - 240, 375, AssetLoader::manager->getImage("basicbutton"), false, samplePeasant, player, this);
	knight = new UnitButton(Var::WIDTH - 290, 325, Var::WIDTH - 240, 375, AssetLoader::manager->getImage("basicbutton"), false, sampleKnight, player, this);

	bm->addButton(build);
	bm->addButton(flag);
	bm->addButton(production);
	bm->addButton(exit);
	bm->addButton(exit1);
	bm->addButton(misc);
	bm->addButton(castle);
	bm->addButton(towncenter);
	bm->addButton(market);
	bm->addButton(rightExit);
	bm->addButton(peasant);
	bm->addButton(knight);

	//all unit queue button stuff below
	int leftEdge = Var::WIDTH - 290;					//variables for easier editing 
	int gap = 55;
	zero = new UnitQueueButton(Var::WIDTH - 290, 475, Var::WIDTH - 240, 525, AssetLoader::manager->getImage("basicbutton"), false, player, this, 0);

	one = new UnitQueueButton(leftEdge, 535, leftEdge + 50, 585, AssetLoader::manager->getImage("basicbutton"), false, player, this, 1);
	two = new UnitQueueButton(leftEdge + gap, 535, leftEdge + gap + 50, 585, AssetLoader::manager->getImage("basicbutton"), false, player, this, 2);
	three = new UnitQueueButton(leftEdge + gap * 2, 535, leftEdge + gap * 2 + 50, 585, AssetLoader::manager->getImage("basicbutton"), false, player, this, 3);
	four = new UnitQueueButton(leftEdge + gap * 3, 535, leftEdge + gap * 3 + 50, 585, AssetLoader::manager->getImage("basicbutton"), false, player, this, 4);
	five = new UnitQueueButton(leftEdge + gap * 4, 535, leftEdge + gap * 4 + 50, 585, AssetLoader::manager->getImage("basicbutton"), false, player, this, 5);

	six = new UnitQueueButton(leftEdge, 595, leftEdge - 50, 645, AssetLoader::manager->getImage("basicbutton"), false, player, this, 6);
	seven = new UnitQueueButton(leftEdge + gap, 595, leftEdge + gap + 50, 645, AssetLoader::manager->getImage("basicbutton"), false, player, this, 7);
	eight = new UnitQueueButton(leftEdge + gap * 2, 595, leftEdge + gap * 2 + 50, 645, AssetLoader::manager->getImage("basicbutton"), false, player, this, 8);
	nine = new UnitQueueButton(leftEdge + gap * 3, 595, leftEdge + gap * 3 + 50, 645, AssetLoader::manager->getImage("basicbutton"), false, player, this, 9);
	ten = new UnitQueueButton(leftEdge + gap * 4, 595, leftEdge + gap * 4 + 50, 645, AssetLoader::manager->getImage("basicbutton"), false, player, this, 10);

	buttonQueue.push_back(zero);
	buttonQueue.push_back(one);
	buttonQueue.push_back(two);
	buttonQueue.push_back(three);
	buttonQueue.push_back(four);
	buttonQueue.push_back(five);
	buttonQueue.push_back(six);
	buttonQueue.push_back(seven);
	buttonQueue.push_back(eight);
	buttonQueue.push_back(nine);
	buttonQueue.push_back(ten);

	bm->addButton(zero);
	bm->addButton(one);
	bm->addButton(two);
	bm->addButton(three);
	bm->addButton(four);
	bm->addButton(five);
	bm->addButton(six);
	bm->addButton(seven);
	bm->addButton(eight);
	bm->addButton(nine);
	bm->addButton(ten);
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
	isLeftWindowOpen = isRightWindowOpen = false;
}

void IGM::menuBackground() {
	al_draw_filled_rectangle(0, 150, 300, 650, al_map_rgb(255, 204, 0));
	al_draw_rectangle(1, 150, 300, 650, al_map_rgb(153, 77, 0), 3);
	exit->setVisible(true);
	isLeftWindowOpen = true;
}

bool IGM::isInWindowBounds(int x, int y) {
	if (isLeftWindowOpen) { return x <= 300 && x >= 0 && y >= 150 && y <= 650; }
	if (isRightWindowOpen) { return x >= Var::WIDTH - 300 && x <= Var::WIDTH && y >= 150 && y <= 650; }
	return false;
}

// default state
void IGM::defaultMenu() {
	isLeftWindowOpen = isRightWindowOpen = false;
}

// overview state
void IGM::overviewMenu() {
	menuBackground();
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
	market->setVisible(true);
}

void IGM::buildingInfoBackground() {
	al_draw_filled_rectangle(Var::WIDTH, 150, Var::WIDTH - 300, 650, al_map_rgb(255, 204, 0));
	al_draw_rectangle(Var::WIDTH - 1, 150, Var::WIDTH - 300, 650, al_map_rgb(153, 77, 0), 3);
	rightExit->setVisible(true);
	if (selectedBuilding->getBuildingType() == TOWNCENTER) peasant->setVisible(true);
	if (selectedBuilding->getBuildingType() == CASTLE) knight->setVisible(true);
	for (int i = 0; i < selectedBuilding->getUnitQueue().size(); i++) {
		buttonQueue[i]->setVisible(true);
		buttonQueue[i]->setEntity(selectedBuilding->getUnitQueue()[i]);
	}
	isRightWindowOpen = true;
}

void IGM::entityInfoBackground() {
	al_draw_filled_rectangle(Var::WIDTH, 150, Var::WIDTH - 300, 650, al_map_rgb(255, 204, 0));
	al_draw_rectangle(Var::WIDTH - 1, 150, Var::WIDTH - 300, 650, al_map_rgb(153, 77, 0), 3);
	rightExit->setVisible(true);
}

void IGM::inventoryMenu() {
	exit1->setVisible(true);
	std::vector<std::vector<const MiscResource*>> miscResources = player->getInventory()->getMiscResources();
	al_draw_filled_rectangle(Var::WIDTH - 550, 40, Var::WIDTH, 40 + miscResources.size() * 35, al_map_rgb(255, 204, 0));
	al_draw_rectangle(Var::WIDTH - 549, 41, Var::WIDTH - 1, 40 + miscResources.size() * 35 - 1, al_map_rgb(153, 77, 0), 3);
	for (int i = 0; i < miscResources.size(); i++) {
		int h = 50 + i * 25;
		std::string resourceName = miscResources[i][0]->getName();
		resourceName[0] = toupper(resourceName[0]);
		std::string itemDesc = resourceName + " - " + std::to_string(miscResources[i].size());
		miscResources[i][0]->render(Var::WIDTH - 225 - (itemDesc.size() * 20 + 28) / 2, h);
		al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 225 - (itemDesc.size() * 20 - 28) / 2, h, 0,
			itemDesc.c_str());
	}
}

void IGM::setState(MenuState state) {
	currState = state;
	switch (state)
	{
	case RESET:
		break;
	case DEFAULTSTATE:
		defaultMenu();
		break;
	case OVERVIEWSTATE:
		overviewMenu();
		break;
	case PRODUCTIONSTATE:
		productionMenu();
		break;
	case BUILDSTATE:
		buildingMenu();
		break;
	case PLACINGBUILDING:
		break;
	case PLACINGBUILDINGTEST:
		break;
	case BUILDINGINFOSTATE:
		buildingInfoBackground();
		selectedBuilding->drawBuildingWindow();
		break;
	case ENTITYINFOSTATE:
		entityInfoBackground();
		selectedEntity->drawEntityWindow();
		break;
	case INVENTORY:
		inventoryMenu();
		break;
	default:
		defaultMenu();
		break;
	}
}

void IGM::edgeCaseStates(int x, int y) {
	//edge case conditions, feel free to add
	if (currState == BUILDINGINFOSTATE && !isInWindowBounds(x, y)) { currState = DEFAULTSTATE; }
	if (currState == PLACINGBUILDING) { prevState = currState = PLACINGBUILDINGTEST; }
}

void IGM::buildingChecks() {
	//when you click something else while placing building
	if (prevState == PLACINGBUILDINGTEST && currState != prevState && currState != PLACINGBUILDING) {
		bl->setPlacing(false);
	}

	//check if placing building in valid location 
	if (currState == PLACINGBUILDINGTEST) {
		if (bl->checkPlacingBounds(newBuilding)) {
			std::cout << "Cannot place in this location \n";
		}
		//valid placement
		else {
			std::cout << "Placing Building \n";
			bl->update(newBuilding, player);
			bl->setPlacing(false);
			currState = BUILDSTATE;
		}
	}
}

void IGM::iterateBuildings(int x, int y) {
	//iterate buildings and check to make sure the click is not behind a window
	if (!isInWindowBounds(x, y)) {
		selectedBuilding = bl->isTileInBounds(currCol, currRow);
		if (selectedBuilding != NULL) {
			// prevSelectedBuilding gives game "memory" of its last focused building
			prevSelectedBuilding = selectedBuilding;
			if (currState != PLACINGBUILDINGTEST) {
				currState = BUILDINGINFOSTATE;
			}
		}
	}
}

void IGM::iterateEntities(int x, int y) {
	if (!isInWindowBounds(x, y)) {
		Entity* clickEntity = player->entityInTile(currRow, currCol);
		if (selectedEntity != NULL && clickEntity == NULL) {
			player->updateEntityPosition(selectedEntity, currRow, currCol);
			currState = DEFAULTSTATE;
		}
		if (clickEntity != NULL) {
			if (clickEntity == selectedEntity) {
				selectedEntity = NULL; // deselect
				currState = DEFAULTSTATE;
			}
			else {
				selectedEntity = clickEntity; // select
				currState = ENTITYINFOSTATE;
			}
		} else {
				selectedEntity = NULL;
		}
	}
}

void IGM::iterateButtons(int x, int y) {
	for (int i = 0; i < bm->size(); i++) {
		// check if button is properly clicked
		if (bm->getList()[i]->isInBounds(x, y) && bm->getList()[i]->isVisible()) {
			bm->getList()[i]->onClick();
			buttonIndex = i;
		}
	}
	if (currState == PLACINGBUILDING) {
		//set template building info
		newBuildingPlaceHolder = (BuildButton*)bm->getList()[buttonIndex];
		newBuilding = newBuildingPlaceHolder->getBuilding();
		bl->setCurrBuilding(newBuilding);
		bl->setPlacing(true);
	}
}

void IGM::update(bool clicked, bool keyClicked, std::string key, int x, int y){ 
	prevState = currState;
	
	//mouse inputs for left click
	if (clicked) {
		//edge case checking for beginning
		edgeCaseStates(x, y);

		//iterate through all current clickables and menu buttons
		iterateBuildings(x, y);
		iterateEntities(x, y);
		iterateButtons(x, y);

		//building checks
		buildingChecks();
	}

	//keyboard inputs
	if (keyClicked) {
		if ((currState == PLACINGBUILDING || currState == PLACINGBUILDINGTEST) && key == "esc") { 
			bl->setPlacing(false);
			currState = BUILDSTATE; 
		}
	}

	//automatic updates
	bl->produceUnits();
}

void IGM::staticRender() {
	//setting all buttons to be non-visible
	for (int i = 0; i < bm->size(); i++) {
		bm->getList()[i]->setVisible(false);
	}

	gameBackground();
	setState(currState);

	//drawing buttons in currState that are visible
	for (int i = 0; i < bm->size(); i++) { 
		if (bm->getList()[i]->isVisible()) { bm->getList()[i]->render(); }
	}
}

void IGM::isoRender() {
	for (int i = 0; i < buildingbm->size(); i++) {
		if (buildingbm->getList()[i]->isVisible()) { buildingbm->getList()[i]->render(); }
	}
}