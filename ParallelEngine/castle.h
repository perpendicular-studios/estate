#ifndef CASTLE_H
#define CASTLE_H

#include "building.h"

class Castle : public Building {
public:
	Castle();

private:
	int currGarrison, maxGarrison;
	int woodStored;

};

#endif 