#include "igm.h"

IGM::IGM() {
	currState = 0;
	bm = new ButtonManager;
	
}

void IGM::background() {
	al_draw_filled_rectangle(0, Var::HEIGHT - 200, Var::WIDTH, Var::HEIGHT, al_map_rgb(255, 204, 102));
	al_draw_rectangle(0, Var::HEIGHT - 200, Var::WIDTH, Var::HEIGHT, al_map_rgb(153, 102, 51), 10);
}

//state 0
void IGM::defaultMenu() {
	build = new Button(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, al_map_rgb(255, 51, 0), basic_font20, al_map_rgb(255, 255, 255), 25, Var::HEIGHT - 150, "Build", 1);
	bm->addButton(build);
	
}

//state 1
void IGM::buildingMenu() {
	al_draw_filled_rectangle(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, al_map_rgb(255, 51, 0));
	al_draw_filled_rectangle(25, Var::HEIGHT - 100, 75, Var::HEIGHT - 50, al_map_rgb(255, 51, 0));
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), 25, Var::HEIGHT - 150, 0, "Castle");
	
}

void IGM::addState(int state) {
	menu.push_back(state);
}

void IGM::stateSelector(int state) {
	switch (state)
	{
	case 0:
		defaultMenu();
		break;
	case 1:
		buildingMenu();
		break;
	default:
		defaultMenu();
		break;
	}
}

void IGM::update(bool clicked, int x, int y){ 
	if (clicked) {
		for (int i = 0; i < bm->size(); i++) {
			if (bm->getList()[i]->isInBounds(x, y)) { currState = bm->getList()[i]->getState(); }
		}
	}

	bm->clearButtons();
}

void IGM::render() {
	background();
	stateSelector(currState);

}
