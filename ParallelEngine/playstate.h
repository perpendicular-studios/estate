#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
#include "player.h"
#include "tilemap.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	~PlayState();
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks, ALLEGRO_MOUSE_STATE & ms) override;
private:
	Player * player;
	TileMap * tm;
	Vector2i hover;
	ALLEGRO_BITMAP * hoverImage;
	bool blocked = false, canClick = false;
};

#endif
