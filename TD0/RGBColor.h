#pragma once
#include <string>

class RGBColor
{
private :
	unsigned char red;
	unsigned char green;
	unsigned char blue;

public : 
	RGBColor();
	RGBColor(unsigned char r, unsigned char g, unsigned char b);
	std::string toString();
};

