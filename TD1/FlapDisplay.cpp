#include "FlapDisplay.h"

FlapDisplay::FlapDisplay(int size)
{
	modules.resize(size);
	
}

void FlapDisplay::Message(std::string string)
{
	for (int num_module = 0; num_module < modules.size(); ++num_module)
	{
		modules[num_module].display(string[num_module]);
	}
}

std::string FlapDisplay::currentDisplay()
{
	std::string string = "";
	for (int num_module = 0; num_module < modules.size(); ++num_module)
	{
		string += "[ ";
		string += modules[num_module].currentSign();
		string += " ] ";
	}
	return string;
}

bool FlapDisplay::update()
{
	bool move = false;
	for (int num_module = 0; num_module < modules.size(); ++num_module)
	{
		if (modules[num_module].update())
		{
			move = true;
		}
	}
	return move;
}