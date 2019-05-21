#ifndef ENITITY_LOADER_H
#define ENTITY_LOADER_H
#include "entitymanager.h"
#include "player.h"
#include "castle.h"
#include <iostream>

class EntityLoader {
public:
	static EntityManager * manager;
	EntityLoader(TileMap * tm);
	~EntityLoader();
};


#endif