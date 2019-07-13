#include "castle.h"

Castle::Castle(int castleID_) : Building(bitmap), castleID(castleID_) {
	stone = 500;
	gold = 200;
	wood = 0;
	food = 0;
}
