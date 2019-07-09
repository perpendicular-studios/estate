#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
enum ResourceType { FOOD, WOOD, STONE, MISC };

class Resource {
public:
	Resource(std::string name_, ResourceType type_, int yield_) : name(name_), type(type_), yield(yield_) { quantity = 0; }
	std::string getName() const { return name; }
	ResourceType getResourceType() const { return type; }
	int getYield() const { return yield; }
	int getQuantity() const { return quantity; }

	void addOne() { quantity++; }
	void subOne() { quantity--; }
private:
	std::string name;
	ResourceType type;
	int yield;
	int quantity;
};


#endif