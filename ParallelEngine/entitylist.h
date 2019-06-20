#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <vector>
#include "entity.h"

class EntityList {
public:
	// initialize new entity, adds to list.
	void addEntity(); 

private:
	std::vector<Entity> entityList;
};
#endif ENTITY_LIST_H