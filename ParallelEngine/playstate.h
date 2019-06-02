#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
#include "player.h"
#include "tilemap.h"
#include "camera.h"
#include "castle.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) override;
private:
	std::shared_ptr<TileMap> tm;
	std::shared_ptr<Camera> cam;
	std::map<std::string, std::shared_ptr<Building>> buildings;
	std::string buildingPlacing;
	bool placing = false;
};

#endif
