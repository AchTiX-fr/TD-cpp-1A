#include "Console.h"
#include <iostream>
#include <conio.h>

Console::Console()
{

}

void Console::write(const std::string& text, ColorValue color) const
{
	startColor(color);	
	std::cout << text;
	stopColor();
}

void Console::writeTo(const std::string& text, int x, int y, ColorValue color) const
{
	moveCursorTo(x, y);
	write(text, color);
}

void Console::clear() const
{
	printf("\033[2J");
}

void Console::moveCursorTo(int x, int y) const
{
	printf("\033[%d;%dH", y, x);
}

void Console::startColor(ColorValue color) const
{
	printf("\x1B[%dm", color);
}

void Console::stopColor() const
{
	printf("\033[0m");
}

int Console::listen()
{
	return _getch();
}