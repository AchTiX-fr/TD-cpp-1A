#include "FlapModule.h"
#include <string>

FlapModule::FlapModule()
{
	availableSigns.push_back(178);

	std::string symbol = " ABCDEFGHIJKLMNOPQRSTVWXYZ";
	for (int car = 0; car < symbol.length(); ++car)
	{
		availableSigns.push_back(symbol[car]);
	}

	signToDisplay = 178;

	currentSignIndex = 0;
}

unsigned char FlapModule::currentSign()
{
	return availableSigns[currentSignIndex];
}

void FlapModule::display(unsigned char value)
{
	for (int car = 0; car < availableSigns.size(); ++car)
	{
		if (value == availableSigns[car])
		{
			signToDisplay = value;
		}
	}
}

bool FlapModule::update()
{
	if (signToDisplay != availableSigns[currentSignIndex])
	{
		currentSignIndex += 1;
		return true;
	}
	return false;
}