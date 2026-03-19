#include "ViewMenu.h"
#include <vector>
#include "KeyCode.h"

ViewMenu::ViewMenu(ControllerViews& controllerViews, ControllerGame& controllerGame, Console& console)
	:View(controllerViews, controllerGame, console), selectedOptionIndex(0)
{
}

void ViewMenu::update()
{
	if (getControllerViews().getActiveView() == ViewType::MENU)
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

void ViewMenu::display()
{
	displayTitle();
	displayMenu();
}

void ViewMenu::displayTitle()
{
	getConsole().writeTo("* * * * * * * * * * * * *", 5, 5);
	getConsole().writeTo("*  M A S T E R M I N D  *", 5, 6);
	getConsole().writeTo("* * * * * * * * * * * * *", 5, 7);
}

void ViewMenu::displayMenu()
{
	for (int iOption = 0; iOption < options.size(); ++iOption)
	{
		getConsole().writeTo((iOption == selectedOptionIndex ? "[x] " : "[ ] ") + options.at(iOption), 5, 10 + iOption * 2);
	}

	getConsole().writeTo("", 5, 20);
}

void ViewMenu::increaseSelectedOptionIndex()
{
	if (options.empty())
		return;

	selectedOptionIndex = ++selectedOptionIndex;
	if (selectedOptionIndex > 1)
	{
		selectedOptionIndex = 1;
	}
	display();
}

void ViewMenu::decreaseSelectedOptionIndex()
{
	if (options.empty())
		return;

	selectedOptionIndex = --selectedOptionIndex;
	if (selectedOptionIndex < 0)
	{
		selectedOptionIndex = 0;
	}
	display();
}

void ViewMenu::waitForKeyPress()
{
	while(!manageKeyPress(getConsole().listen()));
}

bool ViewMenu::manageKeyPress(int keyCode)
{
	if (keyCode == KeyCode::KEY_UP)
		decreaseSelectedOptionIndex();
	else if (keyCode == KeyCode::KEY_DOWN)
		increaseSelectedOptionIndex();
	else if (keyCode == KeyCode::ENTER)
		return validateOption();
	

	return false;
}

bool ViewMenu::validateOption()
{
	switch (selectedOptionIndex)
	{
		case 0:
			getControllerGame().newGame();
			getControllerViews().displayGame();
			break;
		case 1: 
			return true;
	}

	return false;
}