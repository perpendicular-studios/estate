#include "entityloader.h"

EntityManager* EntityLoader::manager = new EntityManager();

EntityLoader::EntityLoader(TileMap * tm) {
	std::cout << "Loading Entities..." << std::endl;
	Entity * player = new Player(tm, Var::WIDTH / 2, Var::HEIGHT / 2, "player");
	Entity * castle = new Castle(tm, 0, 0, "castle");

	manager->loadEntity(player->getKey(), player);
	manager->loadEntity(castle->getKey(), castle);
	std::cout << "Finished Loading Entities." << std::endl;
}	

EntityLoader::~EntityLoader() {
	delete manager;
}