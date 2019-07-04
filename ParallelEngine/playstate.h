#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
#include "player.h"
#include "tilemap.h"
#include "camera.h"
#include "building.h"
#include "buildinglist.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) override;
private:
	std::shared_ptr<TileMap> tm;
	std::shared_ptr<Camera> cam;
	std::vector<std::shared_ptr<Entity>> entityList;
	BuildingList* bl;

	float mouseX = 0, mouseY = 0;
	float hoverX = 0, hoverY = 0;
	int prevMouseState = -1, currMouseState = -1;
};

#endif
