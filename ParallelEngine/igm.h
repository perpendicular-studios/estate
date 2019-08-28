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
#include "resources.h"
#include "units.h"

//in-game menu
class IGM {
public:
	IGM(Player * player_, BuildingList* bl, TileMap * tm_);
	// update states
	void update(bool clicked, bool keyClicked, std::string key, int x, int y);
	// render states 
	void staticRender();
	void isoRender();
	// returns current state
	void setState(MenuState state);

	//basic menu types
	void gameBackground();
	void menuBackground();
	void defaultMenu();
	void buildingMenu();
	void diploMenu();
	void overviewMenu();
	void productionMenu();
	void inventoryMenu();
	void buildingInfoBackground();
	void entityInfoBackground();

	//error checking methods
	bool isInWindowBounds(int x, int y);
	void edgeCaseStates(int x, int y);
	void buildingChecks();

	//iteration methods
	void iterateBuildings(int x, int y);
	void iterateEntities(int x, int y);
	void iterateButtons(int x, int y);
	void iterateResourceTiles(int x, int y);

	// getter methods
	Building* getBuilding() { return newBuilding; }
	Building* getPrevSelectedBuilding() { return prevSelectedBuilding; }

	//setter methods
	void setCol(float col) { currCol = col; }
	void setRow(float row) { currRow = row; }
private:
	//fonts
	ALLEGRO_FONT* basic_font20 = al_load_font("basicfont.ttf", 20, 0);

	//player
	Player* player;

	//states
	MenuState currState, prevState;

	//boolean checks
	bool isLeftWindowOpen, isRightWindowOpen;

	//buttons
	ButtonManager* bm, * buildingbm;
	MenuButton *flag, *production, *build, *exit, *exit1, *misc, *rightExit;
	BuildButton *castle, *towncenter, *market, *newBuildingPlaceHolder;
	UnitButton* peasant, *knight;
	UnitQueueButton* zero, * one, * two, * three, * four, * five, * six, * seven, * eight, * nine, * ten;
	std::vector<UnitQueueButton*> buttonQueue;
	int buttonIndex;

	//buildings
	BuildingList* bl;
	Building* newBuilding, * selectedBuilding, * prevSelectedBuilding;
	//template buildings
	Castle* sampleCastle;
	Towncenter* sampleTC;
	Market* sampleMarket;

	//units
	Entity* selectedEntity;
	//template units
	Peasant* samplePeasant;
	Knight* sampleKnight;
	
	//map stuff
	TileMap* tm;
	float currCol = 0, currRow = 0;
};
#endif