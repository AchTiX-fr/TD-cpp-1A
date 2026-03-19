#include "ControllerGame.h"

ControllerGame::ControllerGame()
	:Controller()
{
}

void ControllerGame::newGame()
{
	mastermind.newGame();
}

const MasterMind& ControllerGame::getMasterMind() const
{
	return mastermind;
}

const EditedColorPattern& ControllerGame::getEditedColorPattern()
{
	return editedColorPattern;
}

void ControllerGame::moveToLeft()
{
	editedColorPattern.moveToLeft();
	updateViews();
}

void ControllerGame::moveToRight()
{
	editedColorPattern.moveToRight();
	updateViews();
}

void ControllerGame::increaseEditedColor()
{
	editedColorPattern.increaseEditedColor();
	updateViews();
}

void ControllerGame::decreaseEditedColor()
{
	editedColorPattern.decreaseEditedColor();
	updateViews();
}

void ControllerGame::validateProposal()
{
	mastermind.proposeColorPattern(editedColorPattern.getColorPattern());
	editedColorPattern.resetColors();
	updateViews();
}