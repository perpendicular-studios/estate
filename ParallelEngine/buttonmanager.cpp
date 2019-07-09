#include "buttonmanager.h"

void ButtonManager::addButton(Button* b) {
	buttonList.push_back(b);
}

void ButtonManager::clearButtons() {
	buttonList.clear();
}
