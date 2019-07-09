#ifndef IGM_H
#define IGM_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "var.h"
#include <string>
#include <vector>
#include "buttonmanager.h"

//in-game menu
class IGM {
public:
	IGM();
	// initialize new state, adds to list.
	void addState(int state);
	// delete state 
	void popState(int buildingID);
	// update states
	void update(bool clicked, int x, int y);
	// render states 
	void render();
	// returns current state
	void stateSelector(int state);

	//basic menu types
	void defaultMenu();
	void buildingMenu();
	void background();
	

private:
	std::vector<int> menu; 
	int defaultMenuNum = 2;
	int currState;
	ALLEGRO_FONT* basic_font20 = al_load_font("arial.ttf", 20, 0);
	bool isClicked = false;
	ButtonManager* bm;
	Button* build;
};
#endif