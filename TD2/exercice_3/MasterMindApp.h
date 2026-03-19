#pragma once
#include "ControllerViews.h"
#include "ControllerGame.h"
#include "ViewMenu.h"
#include "ViewGame.h"

class MasterMindApp
{
private:
	ControllerViews controllerViews;
	ControllerGame controllerGame;
	ViewMenu viewMenu;
	ViewGame viewGame;

	Console console;

public:
	MasterMindApp();
};

