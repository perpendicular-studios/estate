#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER
#include <vector>
#include "entity.h"

class EntityManager {
public:
	EntityManager() { idCounter = 0; }
	void addEntity(Entity * e) { 
		e->setid(idCounter);
		entitySet[idCounter] = e;
		idCounter++;
	}

	void removeEntity(Entity * e) {
		entitySet.erase(entitySet.begin() + e->getid());
		idCounter--;
	}

	Entity* getEntity(int id) {
		return entitySet[id];
	}
	
private:
	int idCounter;
	std::vector<Entity*> entitySet;
};
#endif