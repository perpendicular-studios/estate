#ifndef MARKET_H
#define MARKET_H

#include "building.h"

class Market : public Building {
public:
	Market(int marketID);

	void drawBuildingWindow() override;

private:

	int marketID;
};

#endif 