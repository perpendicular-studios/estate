#include "castle.h"

Castle::Castle(int castleID_) : Building(tm), castleID(castleID_) {
	stone = 500;
	gold = 200;
	wood = 0;
	food = 0;
}

void Castle::render() {};
void Castle::update() {};