#include "igm.h"

IGM::IGM(Player* player_, BuildingList* bl_) : player(player_), bl(bl_) {
	currState = defaultState;
	sampleCastle = new Castle(-1);
	sampleTC = new Towncenter(-1);
	newBuilding = sampleCastle;

	bm = new ButtonManager;
	build = new MenuButton(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Build", 0, overviewState);
	flag = new MenuButton(0, 0, 100, 50, AssetLoader::manager->getImage("flagbg"), basic_font20, al_map_rgb(255, 255, 255), "Flag", 0, overviewState);
	production = new MenuButton(0, 50, 50, 100, AssetLoader::manager->getImage("productionbg"), basic_font20, al_map_rgb(255, 255, 255), "Prod", 0, buildState);
	exit = new MenuButton(225, 100, 250, 125, AssetLoader::manager->getImage("x"), basic_font20, al_map_rgb(255, 255, 255), "X", 0, defaultState);
	misc = new MenuButton(Var::WIDTH - 50, 0, Var::WIDTH, 50, AssetLoader::manager->getImage("miscbg"), basic_font20, al_map_rgb(255, 255, 255), "MISC", 0, inventory); // should open an inventory
	castle = new BuildButton(25, 150, 75, 200, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Castle", 0, sampleCastle);
	towncenter = new BuildButton(100, 150, 150, 200, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Towncenter", 0, sampleTC);

	bm->addButton(build);
	bm->addButton(flag);
	bm->addButton(production);
	bm->addButton(exit);
	bm->addButton(misc);
	bm->addButton(castle);
	bm->addButton(towncenter);
}

void IGM::gameBackground() {
	al_draw_filled_rectangle(Var::WIDTH - 550, 0, Var::WIDTH - 50, 40, al_map_rgb(153, 102, 0)); //resources background 
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 530, 5, 0, std::to_string(player->getGold()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 380, 5, 0, std::to_string(player->getFood()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 230, 5, 0, std::to_string(player->getStone()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 80, 5, 0, std::to_string(player->getWood()).c_str());
	al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(0, 0, 0));								//flag black background
	misc->setVisible(true);
	production->setVisible(true);
	flag->setVisible(true);
}

void IGM::menuBackground() {
	al_draw_filled_rectangle(0, 100, 250, 500, al_map_rgb(255, 204, 0));
	al_draw_rectangle(1, 100, 250, 500, al_map_rgb(153, 77, 0), 3);
	exit->setVisible(true);
}

// default state
void IGM::defaultMenu() {}

// overview state
void IGM::overviewMenu() {
	menuBackground();
}

// diplo state
void IGM::diploMenu() {

}

// build state
void IGM::buildingMenu() {
	menuBackground();
	castle->setVisible(true);
	towncenter->setVisible(true);
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
	case buildState:
		buildingMenu();
		break;
	case placingBuilding:
		buildingMenu();
		break;
	default:
		defaultMenu();
		break;
	}
}

void IGM::update(bool clicked, int x, int y){ 
	prevState = currState;

	if (relativeClicks > 1) {
		currState = buildState;
		relativeClicks = 0;
		std::cout << "changed state";
	}

	if (clicked) {
		for (int i = 0; i < bm->size(); i++) {
			// check if state changed
			if (bm->getList()[i]->isInBounds(x, y) == true && bm->getList()[i]->getVisible() == true) {
				currState = bm->getList()[i]->getState(); 
				buttonIndex = i;
				if (currState == placingBuilding) { 
					newBuildingPlaceHolder = (BuildButton*)bm->getList()[buttonIndex]; 
					newBuilding = newBuildingPlaceHolder->getBuilding();
					buildingType = newBuildingPlaceHolder->getText();
					relativeClicks = 0;
					bl->setPlacing(false);
				}
				//when you click exit while placing building
				if (prevState == placingBuilding && currState == defaultState) {
					relativeClicks = 0;
					bl->setPlacing(false);
				}
			}
		}
		if (currState == placingBuilding && relativeClicks <= 1) {
			bl->setBuild(true);
			std::cout << "building..."; 
			relativeClicks++;
		}
	}
}

void IGM::staticRender() {
	for (int i = 0; i < bm->size(); i++) {
		bm->getList()[i]->setVisible(false);
	}
	gameBackground();
	stateSelector(currState);
	for (int i = 0; i < bm->size(); i++) { 
		if (bm->getList()[i]->getVisible() == true) { bm->getList()[i]->drawButton(); }
	}
}

void IGM::isoRender() {


}