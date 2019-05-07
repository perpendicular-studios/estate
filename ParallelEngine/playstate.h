#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
#include "player.h"

class PlayState : public State {
public:
	PlayState(GSM * gsm);
	void render() override;
	void update() override;
	void handleInput(ALLEGRO_KEYBOARD_STATE & ks) override;
private:
	Player * player;
};

#endif
