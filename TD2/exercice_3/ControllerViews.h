#pragma once
#include "ViewType.h"
#include "Controller.h"
#include <vector>

class View;

class ControllerViews: public Controller
{
private:
	ViewType activeView;

public:
	ControllerViews();

	void displayGame();
	void displayMenu();

	ViewType getActiveView() const;
};

