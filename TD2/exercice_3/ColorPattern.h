#pragma once
#include <vector>
#include "Color.h"
#include "ColorPatternAnalyse.h"

class ColorPattern
{
private:
	const int COLOR_PATTERN_SIZE = 4;

	std::vector<Color> colors;
public:
	ColorPattern();

	const Color& operator[](size_t colorIndex) const;
	Color& operator[](size_t colorIndex);

	void randomize();

	bool operator==(const ColorPattern& colorScheme) const;
	bool operator!=(const ColorPattern& colorScheme) const;

	size_t getSize() const;

	ColorPatternAnalyse compare(const ColorPattern& colorScheme) const;
};

