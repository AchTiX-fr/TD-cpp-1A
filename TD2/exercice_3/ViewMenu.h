#pragma once
#include "View.h"
#include <vector>

class ViewMenu: public View
{
private:
	const std::vector<std::string> options = { "Nouvelle partie", "Quitter" };

	int selectedOptionIndex;

	void display();
	void displayTitle();
	void displayMenu();

	void waitForKeyPress();
	bool manageKeyPress(int keyCode);
	bool validateOption();

	void decreaseSelectedOptionIndex();
	void increaseSelectedOptionIndex();

public:
	ViewMenu(ControllerViews& controllerViews, ControllerGame& controllerGame, Console& console);

	void update();
};

