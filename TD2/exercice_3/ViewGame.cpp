#include "ViewGame.h"
#include "KeyCode.h"

ViewGame::ViewGame(
	ControllerViews& controllerViews, 
	ControllerGame& controllerGame,
	Console& console
)
	: View(controllerViews, controllerGame, console), displayRow(0)
{
}

void ViewGame::update()
{
	if (getControllerViews().getActiveView() == ViewType::GAME)
	{
		getConsole().clear();

		display();

		if (!isListeningKeyboard())
		{
			startListeningKeyboard();
			waitForKeyPress();
		}
	}
}

void ViewGame::display()
{
	auto& mastermind = getControllerGame().getMasterMind();

	displayRow = 2;

	displaySecretPattern();

	displayProposals();

	if (mastermind.isLost())
		getConsole().writeTo("PERDU ! ", 5, displayRow);
	else if(mastermind.isWin())
		getConsole().writeTo("GAGNE ! ", 5, displayRow);
	else
		displayEditedColorPattern(getControllerGame().getEditedColorPattern());
}

void ViewGame::displaySecretPattern()
{
	auto& mastermind = getControllerGame().getMasterMind();

	displayColorPattern(mastermind.getSecretPattern(), !mastermind.isWin() && !mastermind.isLost());

}

void ViewGame::displayProposals()
{
	auto& mastermind = getControllerGame().getMasterMind();
	
	displayRow += 3;

	for (const auto& proposal: mastermind.getProposals())
	{
		displayColorPattern(proposal);
		displayColorPatternAnalyse(mastermind.analyseColorPattern(proposal));

		displayRow += 2;
	}
}

void ViewGame::displayColorPattern(const ColorPattern& colorPattern, bool hideColor)
{
	getConsole().moveCursorTo(5, displayRow);

	for (size_t iColor = 0; iColor < colorPattern.getSize(); ++iColor)
	{
		getConsole().write("\xB2 ", hideColor ? ColorValue::WHITE : colorPattern[iColor].getValue());
	}
}

void ViewGame::displayEditedColorPattern(const EditedColorPattern& editedColorPattern)
{
	displayColorPattern(editedColorPattern.getColorPattern());

	getConsole().writeTo("^", 5 + editedColorPattern.getEditedColorIndex() * 2, ++displayRow);
}

void ViewGame::displayColorPatternAnalyse(ColorPatternAnalyse colorPatternAnalyse)
{
	getConsole().write(
		"\t" + 
		std::to_string(colorPatternAnalyse.wellPlacedColors) + " OK / " +
		std::to_string(colorPatternAnalyse.wrongPlacedColors) + " a la mauvaise place (todo)"
	);
}

void ViewGame::waitForKeyPress()
{
	while(!manageKeyPress(getConsole().listen()));
}

bool ViewGame::manageKeyPress(int keyCode)
{
	switch (keyCode)
	{
		case KeyCode::KEY_LEFT: getControllerGame().moveToLeft(); break;
		case KeyCode::KEY_RIGHT: getControllerGame().moveToRight(); break;
		case KeyCode::KEY_UP: getControllerGame().increaseEditedColor(); break;
		case KeyCode::KEY_DOWN: getControllerGame().decreaseEditedColor(); break;
		case KeyCode::ENTER: 
			auto& mastermind = getControllerGame().getMasterMind();

			if (mastermind.isWin() || mastermind.isLost())
			{
				stopListeningKeyboard();
				getControllerViews().displayMenu();
				return true;
			}
			else
				getControllerGame().validateProposal();
			break;
	}

	return false;
}