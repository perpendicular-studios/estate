#ifndef TOWNCENTER_H
#define TOWNCENTER_H

#include "building.h"

class Towncenter : public Building {
public:
	Towncenter(int towncenterID);

	ALLEGRO_BITMAP* getBaseImg() override { return bitmap; }

private:
	int currGarrison, maxGarrison;
	int towncenterID;
	ALLEGRO_BITMAP* bitmap = AssetLoader::manager->getImage("towncenter");

};

#endif 