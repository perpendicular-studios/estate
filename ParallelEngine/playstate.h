#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "tilemap.h"
#include "camera.h"
#include "building.h"
#include "buildinglist.h"
#include "inputhandler.h"
#include "player.h"
#include "igm.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) override; 
private:
	std::shared_ptr<TileMap> tm;
	std::shared_ptr<Camera> cam;
	BuildingList* bl;
	InputHandler input;
	IGM* menu;
	Player* player;
	Entity* selectedEntity;

	float mouseX = 0, mouseY = 0;
	float hoverX = 0, hoverY = 0;
	float buildOffsetX = 0, buildOffsetY = 0;
};

#endif
