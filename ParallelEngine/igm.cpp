#include "igm.h"

IGM::IGM() {
	
	//initilalize default menu
	
}

void IGM::background() {
	al_draw_filled_rectangle(0, Var::HEIGHT - 200, Var::WIDTH, Var::HEIGHT, al_map_rgb(255, 204, 102));
	al_draw_rectangle(0, Var::HEIGHT - 200, Var::WIDTH, Var::HEIGHT, al_map_rgb(153, 102, 51), 10);
}

void IGM::defaultMenu() {
	
	al_draw_filled_rectangle(25, Var::HEIGHT - 175, 75, Var::HEIGHT - 125, al_map_rgb(255, 51, 0));
	al_draw_filled_rectangle(25, Var::HEIGHT - 100, 75, Var::HEIGHT - 50, al_map_rgb(255, 51, 0));
	al_draw_text(basic_font20, al_map_rgb(255, 255, 255), 25, Var::HEIGHT - 150, 0, "Build");
}

void IGM::buildingMenu() {
	

}

void IGM::addState(int state) {
	menu.push_back(state);
}

void IGM::update(){ 
	background(); 
	defaultMenu();
}
