#include "MasterMindApp.h"

MasterMindApp::MasterMindApp()
	: viewMenu(controllerViews, controllerGame, console), viewGame(controllerViews, controllerGame, console)
{
	controllerViews.updateViews();
}
