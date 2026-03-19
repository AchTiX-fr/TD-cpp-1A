#pragma once
#include "View.h"
#include "Console.h"
#include "ControllerViews.h"
#include "ControllerGame.h"
#include "ColorPatternAnalyse.h"

class ViewGame: public View
{
private:
	int displayRow;

	void display();
	void displaySecretPattern();
	void displayProposals();
	void displayEditedColorPattern(const EditedColorPattern& editedColorPattern);
	void displayColorPattern(const ColorPattern& colorPattern, bool hideColor = false);
	void displayColorPatternAnalyse(ColorPatternAnalyse colorPatternAnalyse);


	void waitForKeyPress();
	bool manageKeyPress(int keyCode);

public:
	ViewGame(ControllerViews& controllerViews, ControllerGame& controllerGame, Console& console);

	void update();
};

