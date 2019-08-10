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
	void setSelectedEntity(Entity* e) { selectedEntity = e; }
private:
	std::shared_ptr<TileMap> tm;
	std::shared_ptr<Camera> cam;
	BuildingList* bl;
	InputHandler input;
	IGM* menu;
	Player* player;
	Entity* selectedEntity;

	Vector2f mapCoord, screenCoord;

	float mouseX = 0, mouseY = 0;
	float placingCoordX = 0, placingCoordY = 0;
};

#endif
