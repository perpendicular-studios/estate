#ifndef IGM_H
#define IGM_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "var.h"
#include <string>
#include "buttonmanager.h"
#include "menustates.h"
#include "buildinglist.h"
#include <iostream>

//in-game menu
class IGM {
public:
	IGM();
	// update states
	void update(BuildingList* bl, bool clicked, int x, int y);
	// render states 
	void render();
	// returns current state
	void stateSelector(menuStates state);


	//basic menu types
	void gameBackground();
	void menuBackground();
	void defaultMenu();
	void buildingMenu();
	void diploMenu();
	void overviewMenu();
	
	
	//getter methods
	bool getIsBuild() { return isBuild; }
	 

private:
	menuStates currState, prevState;
	ALLEGRO_FONT* basic_font20 = al_load_font("arial.ttf", 20, 0);
	bool isClicked = false;
	ButtonManager* bm;
	Button *flag, *production, *build, *exit, *castle;
	bool isBuild = false;
	int relativeClicks = 0;
};
#endif