#ifndef IGM_H
#define IGM_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "var.h"
#include <string>
#include "player.h"
#include "buttonmanager.h"
#include "menustates.h"
#include "buildinglist.h"
#include <iostream>
#include "assetloader.h"

//in-game menu
class IGM {
public:
	IGM(Player * player_);
	// update states
	void update(BuildingList* bl, bool clicked, int x, int y);
	// render states 
	void render();
	// returns current state
	void stateSelector(MenuState state);


	//basic menu types
	void gameBackground();
	void menuBackground();
	void defaultMenu();
	void buildingMenu();
	void diploMenu();
	void overviewMenu();
	
	// getter methods
	Building* getBuilding() { return newBuilding; }
	std::string getBuildingType() { return buildingType; }
	 
private:
	MenuState currState, prevState;
	ALLEGRO_FONT* basic_font20 = al_load_font("basicfont.ttf", 20, 0);
	bool isClicked = false;
	ButtonManager* bm;
	Player* player;
	MenuButton *flag, *production, *build, *exit, *misc;
	BuildButton *castle, *towncenter, *newBuildingPlaceHolder;
	Building* newBuilding;
	std::string buildingType;
	int relativeClicks = 0;
	int buttonIndex;
	Castle* c;
	Towncenter* tc;
};
#endif