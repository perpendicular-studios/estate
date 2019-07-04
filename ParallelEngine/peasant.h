#ifndef PEASANT_H
#define PEASANT_H
#include "entity.h"
class Peasant : public Entity {
public:
	Peasant(std::shared_ptr<TileMap> tm);
	void render() override;
	void update() override;
private:
	AnimationSet animSet;
};

#endif