#include "igm.h"

IGM::IGM(Player* player_) : player(player_) {
	currState = defaultState;
	bm = new ButtonManager;
	build = new Button(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, al_map_rgb(255, 51, 0), basic_font20, al_map_rgb(255, 255, 255), 25, Var::HEIGHT - 150, "Build", overviewState);
	flag = new Button(0, 0, 100, 50, al_map_rgb(0, 204, 0), basic_font20, al_map_rgb(255, 255, 255), 0, 0, "Flag", overviewState);
	production = new Button(0, 50, 50, 100, al_map_rgb(0, 0, 255), basic_font20, al_map_rgb(255, 255, 255), 0, 50, "Prod", buildState);
	exit = new Button(225, 100, 250, 125, al_map_rgb(255, 0, 0), basic_font20, al_map_rgb(255, 255, 255), 225, 100, "X", defaultState);
	castle = new Button(25, 150, 75, 200, al_map_rgb(255, 0, 0), basic_font20, al_map_rgb(255, 255, 255), 25, 150, "Castle", action);
}

void IGM::gameBackground() {
	al_draw_filled_rectangle(Var::WIDTH - 500, 0, Var::WIDTH, 30, al_map_rgb(153, 102, 0)); //resources background 
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 480, 5, 0, std::to_string(player->getGold()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 330, 5, 0, std::to_string(player->getFood()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 180, 5, 0, std::to_string(player->getStone()).c_str());
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), Var::WIDTH - 30, 5, 0, std::to_string(player->getWood()).c_str());
	al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(0, 0, 0));							//flag black background

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
		isBuild = false;
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
	case action:
		buildingMenu();
		isBuild = false;
		break;
	default:
		defaultMenu();
		break;
	}
}

void IGM::update(BuildingList* bl, bool clicked, int x, int y){ 
	prevState = currState;

	if (relativeClicks > 1) {
		currState = buildState;
		relativeClicks = 0;
		std::cout << "changed state";
		isBuild = false;
	}

	if (clicked) {
		for (int i = 0; i < bm->size(); i++) {
			if (bm->getList()[i]->isInBounds(x, y) == true) { currState = bm->getList()[i]->getState(); }
		}
		if (currState == action && relativeClicks <= 1) {
			isBuild = true; std::cout << "building..."; relativeClicks++;
		}
	}

	if (prevState != currState && prevState == action) {
		stateSelector(reset); std::cout << "reset";
	}
	
	bm->clearButtons();
}

void IGM::render() {
	gameBackground();
	stateSelector(currState);
}
