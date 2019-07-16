#include "towncenter.h"

Towncenter::Towncenter(int towncenterID_) : Building(bitmap, 255, 287), towncenterID(towncenterID_) {
	stone = 300;
	gold = 0;
	wood = 300;
	food = 0;
}