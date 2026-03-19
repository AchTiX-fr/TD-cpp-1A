#include "ControllerViews.h"
#include "View.h";

ControllerViews::ControllerViews()
	: activeView(ViewType::MENU)
{

}

void ControllerViews::displayGame()
{
	activeView = ViewType::GAME;
	updateViews();
}

void ControllerViews::displayMenu()
{
	activeView = ViewType::MENU;
	updateViews();
}

ViewType ControllerViews::getActiveView() const
{
	return activeView;
}