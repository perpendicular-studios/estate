#ifndef CASTLE_H
#define CASTLE_H

#include "building.h"

class Castle : public Building {
public:
	Castle(int castleID);

	void render() override;
	void update() override;

private:
	int currGarrison, maxGarrison;
	int woodStored;
	int castleID;

};

#endif 