#include "igm.h"

IGM::IGM(Player* player_) : player(player_) {
	currState = defaultState;
	bm = new ButtonManager;
	build = new MenuButton(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Build", overviewState);
	flag = new MenuButton(0, 0, 100, 50, AssetLoader::manager->getImage("flagbg"), basic_font20, al_map_rgb(255, 255, 255), "Flag", overviewState);
	production = new MenuButton(0, 50, 50, 100, AssetLoader::manager->getImage("productionbg"), basic_font20, al_map_rgb(255, 255, 255), "Prod", buildState);
	exit = new MenuButton(225, 100, 250, 125, AssetLoader::manager->getImage("x"), basic_font20, al_map_rgb(255, 255, 255), "X", defaultState);
	misc = new MenuButton(Var::WIDTH - 50, 0, Var::WIDTH, 50, AssetLoader::manager->getImage("miscbg"), basic_font20, al_map_rgb(255, 255, 255), "MISC", inventory); // should open an inventory
	castle = new BuildButton(25, 150, 75, 200, AssetLoader::manager->getImage("basicbutton"), basic_font20, al_map_rgb(255, 255, 255), "Castle", c);
}

void IGM::gameBackground() {
	al_draw_filled_rectangle(Var::WIDTH - 550, 0, Var::WIDTH - 50, 40, al_map_rgb(153, 102, 0)); //resources background 
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 530, 5, 0, std::to_string(player->getGold()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 380, 5, 0, std::to_string(player->getFood()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 230, 5, 0, std::to_string(player->getStone()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 80, 5, 0, std::to_string(player->getWood()).c_str());
	misc->drawButton();
	al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(0, 0, 0));								//flag black background

	production->drawButton();
	bm->addButton(production);
	flag->drawButton();
	bm->addButton(flag);
}

void IGM::menuBackground() {
	al_draw_filled_rectangle(0, 100, 250, 500, al_map_rgb(255, 204, 0));
	al_draw_rectangle(1, 100, 250, 500, al_map_rgb(153, 77, 0), 3);
	exit->drawButton();
	bm->addButton(exit);
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
	castle->drawButton();
	bm->addButton(castle);
	
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

void IGM::update(BuildingList* bl, bool clicked, int x, int y){ 
	prevState = currState;

	if (relativeClicks > 1) {
		currState = placingBuilding;
		relativeClicks = 0;
		std::cout << "changed state";
	}

	if (clicked) {
		for (int i = 0; i < bm->size(); i++) {
			if (bm->getList()[i]->isInBounds(x, y) == true) { 
				currState = bm->getList()[i]->getState(); 
				buttonIndex = i;
				if (currState == placingBuilding) { 
					newBuildingPlaceHolder = (BuildButton*)bm->getList()[buttonIndex]; 
					newBuilding = newBuildingPlaceHolder->getBuilding();
					buildingType = newBuildingPlaceHolder->getText();
				}
			}
		}
		if (currState == placingBuilding && relativeClicks <= 1) {
			bl->setBuild(true);
			std::cout << "building..."; 
			relativeClicks++;
		}
	}

	if (prevState != currState && prevState == placingBuilding) {
		stateSelector(reset); std::cout << "reset";
	}
	
	bm->clearButtons();
}

void IGM::render() {
	gameBackground();
	stateSelector(currState);
}
