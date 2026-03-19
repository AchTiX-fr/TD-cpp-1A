#pragma once
#include "ColorValue.h"




class Color
{
private:
	static const ColorValue MIN_COLOR_VALUE = ColorValue::RED;
	static const ColorValue MAX_COLOR_VALUE = ColorValue::CYAN;

	ColorValue value;

public:
	Color();

	ColorValue getValue() const;
	void setValue(ColorValue newValue);

	void increaseValue();
	void decreaseValue();
	void randomizeValue();

	bool operator==(const Color& colorScheme) const;
	bool operator!=(const Color& colorScheme) const;
};
