#ifndef TOWNCENTER_H
#define TOWNCENTER_H

#include "building.h"

class Towncenter : public Building {
public:
	Towncenter(int towncenterID);

	void drawBuildingWindow() override;

private:
	int currGarrison, maxGarrison;
	int towncenterID;
};

#endif 