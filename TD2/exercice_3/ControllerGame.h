#pragma once
#include "Controller.h"
#include "MasterMind.h"
#include "EditedColorPattern.h"

class ControllerGame: public Controller
{
private:
	MasterMind mastermind;
	EditedColorPattern editedColorPattern;

public:
	ControllerGame();

	void newGame();

	const MasterMind& getMasterMind() const;
	const EditedColorPattern& getEditedColorPattern();

	void moveToLeft();
	void moveToRight();
	void increaseEditedColor();
	void decreaseEditedColor();

	void validateProposal();
};

