#include "RGBColor.h"
#include <string>


RGBColor::RGBColor()
{
	red = 0;
	green = 0;
	blue = 0;
}


RGBColor::RGBColor(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

std::string RGBColor::toString() 
{

	std::string str(1, static_cast<char>(red));
	std::string str1(1, static_cast<char>(green));
	std::string str2(1, static_cast<char>(blue));
	return "#" + str + str1 + str2;
}
