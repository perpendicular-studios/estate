#ifndef CASTLE_H
#define CASTLE_H

#include "building.h"

class Castle : public Building {
public:
	Castle(int castleID);
	
	ALLEGRO_BITMAP* getBaseImg() override { return bitmap; }

private:
	int currGarrison, maxGarrison;
	int woodStored;
	int castleID;
	ALLEGRO_BITMAP* bitmap = AssetLoader::manager->getImage("castle");

};

#endif 