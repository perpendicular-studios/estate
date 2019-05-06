#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"
#include "entity.h"
class PlayState : public State {
public:
	PlayState(GSM * gsm);
	void render() override;
	void update() override;
	void handleInput(ALLEGRO_KEYBOARD_STATE & ks) override;
private:
	Entity * player;
};

#endif
