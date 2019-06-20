#include "var.h"
int Var::uEntityID = 0;

int Var::getUniqueEntityID() {
	return uEntityID++;
}