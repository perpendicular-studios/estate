#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <vector>
#include "button.h"

class ButtonManager {
public:
	void addButton(Button* b);
	void clearButtons();
	int size() { return buttonList.size(); }
	bool isClicked = false; 
	std::vector<Button*> getList() { return buttonList; };
	std::vector<Button*> buttonList;
};
#endif