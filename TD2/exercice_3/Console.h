#pragma once
#include <string>
#include "ColorValue.h"

class Console
{
private:
	void startColor(ColorValue color) const;
	void stopColor() const;

public:
	Console();

	void moveCursorTo(int x, int y) const;

	void write(const std::string& text, ColorValue color = ColorValue::WHITE) const;
	void writeTo(const std::string& text, int x, int y, ColorValue color = ColorValue::WHITE) const;

	void clear() const;

	int listen();
};

