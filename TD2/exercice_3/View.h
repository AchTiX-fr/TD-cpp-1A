#pragma once
#include "Console.h"
#include "ControllerViews.h"
#include "ControllerGame.h"

class View
{
private:
	Console& console;
	ControllerViews& controllerViews;
	ControllerGame& controllerGame;

	bool listeningKeyboard;

public:
	View(ControllerViews& controllerViews, ControllerGame& controllerGame, Console& console);

	Console& getConsole() const;
	ControllerViews& getControllerViews();
	ControllerGame& getControllerGame();

	void startListeningKeyboard();
	void stopListeningKeyboard();
	bool isListeningKeyboard();

	virtual void update() = 0;
};

