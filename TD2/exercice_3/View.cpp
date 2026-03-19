#include "View.h"

View::View(ControllerViews& controllerViews, ControllerGame& controllerGame, Console& console)
	: controllerViews(controllerViews), controllerGame(controllerGame), console(console), listeningKeyboard(false)
{
	controllerViews.registerView(*this);
	controllerGame.registerView(*this);
}

Console& View::getConsole() const
{
	return console;
}

ControllerViews& View::getControllerViews()
{
	return controllerViews;
}

ControllerGame& View::getControllerGame()
{
	return controllerGame;
}

void View::startListeningKeyboard()
{
	listeningKeyboard = true;
}

void View::stopListeningKeyboard()
{
	listeningKeyboard = false;
}

bool View::isListeningKeyboard()
{
	return listeningKeyboard;
}