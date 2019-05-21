#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <map>
#include <string>
#include "entity.h"

class EntityManager {
public:
	~EntityManager() { entities.clear(); }
	void loadEntity(std::string key, Entity* entity) { entities[key] = entity; }
	Entity* getEntity(std::string key) { return entities[key]; }
private:
	std::map<std::string, Entity*> entities;
};


#endif