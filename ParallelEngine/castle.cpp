#include "castle.h"

Castle::Castle(int castleID_) : Building(tm), castleID(castleID_) {
	stone = 100;
	gold = 200;
}

void Castle::render() {};
void Castle::update() {};