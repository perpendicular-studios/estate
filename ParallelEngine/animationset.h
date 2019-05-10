
#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H

#include <map>
#include <string>
#include "animation.h"

class AnimationSet {
public:
	AnimationSet() {}
	~AnimationSet() {}
	void addAnimation(Animation* animation, std::string key) { animationSet[key] = animation; }
	void setAnimation(std::string key) { currentAnimation = animationSet[key]; }
	Animation* getCurrentAnimation() const { return currentAnimation; }

private:
	std::map<std::string, Animation*> animationSet;
	Animation* currentAnimation;
};

#endif