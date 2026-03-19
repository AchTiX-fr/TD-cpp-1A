#pragma once
#include <string>

class Console
{
public :
	void clear();
	void moveTo(int x, int y);
	void textTo(int x, int y, std::string text);
};