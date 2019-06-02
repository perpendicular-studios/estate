#include "var.h"
int Var::uniqueBuildingID = 0;

int Var::getUniqueBuildingID() {
	return uniqueBuildingID++;
}