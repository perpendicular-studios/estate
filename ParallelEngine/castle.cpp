#include "castle.h"

Castle::Castle(int castleID_) : Building(bitmap, 607, 447), castleID(castleID_) {
	stone = 500;
	gold = 200;
	wood = 0;
	food = 0;
	width = 400;
	height = 352;
}
