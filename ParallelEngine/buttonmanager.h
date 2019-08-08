#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <vector>
#include "button.h"
#include "menubutton.h"
#include "buildbutton.h"
#include "unitbutton.h"
#include "unitqueuebutton.h"

class ButtonManager {
public:

	void addButton(Button* b);
	void clearButtons();
	int size() { return buttonList.size(); }
	std::vector<Button*> getList() { return buttonList; };
	std::vector<Button*> buttonList;
};
#endif