#include "Console.h"
#include <iostream>

/**
 * Clear the console
 */
void Console::clear()
{
	std::cout << "\033[2J" << std::flush;
	Console::moveTo(0, 0);
}

/**
 * Place the cursor on the line and column chosen by the user
 * @param x integer for the line (vertical)
 * @param y integer for the column (horizontal)
 */
void Console::moveTo(int x, int y)
{
	std::cout << "\033[" << x << ";" << y << "H" << std::flush;
}

/**
 * Write text at place chose by the user
 * @param x Horizontal position
 * @param y Vertical position
 * @param text The message to display
 */
void Console::textTo(int x, int y, std::string text)
{
	Console::moveTo(x, y);
	std::cout << text << std::flush;
}