#pragma once
#include "FlapModule.h"
#include <vector>
#include <string>

class FlapDisplay
{
private : 
	std::vector<FlapModule> modules;

public :
	FlapDisplay(int size);
	void Message(std::string string);
	std::string currentDisplay();
	bool update();
};