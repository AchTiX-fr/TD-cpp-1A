#include "ColorPattern.h"

ColorPattern::ColorPattern()
	: colors(COLOR_PATTERN_SIZE)
{
}

const Color& ColorPattern::operator[](size_t colorIndex) const
{
	return colors.at(colorIndex);
}

Color& ColorPattern::operator[](size_t colorIndex)
{
	return colors.at(colorIndex);
}

void ColorPattern::randomize()
{
	for (auto& color : colors)
		color.randomizeValue();
}

bool ColorPattern::operator==(const ColorPattern& colorPattern) const
{
	return std::equal(colors.begin(), colors.end(), colorPattern.colors.begin());
}

bool ColorPattern::operator!=(const ColorPattern& colorPattern) const
{
	return !(*this == colorPattern);
}

size_t ColorPattern::getSize() const
{
	return colors.size();
}

ColorPatternAnalyse ColorPattern::compare(const ColorPattern& colorPattern) const
{
	struct ColorPatternAnalyse information = { 0, 0 };

	for (size_t i = 0; i < getSize(); ++i)
	{
		if (colorPattern[i].getValue() == colors.at(i).getValue())
			++information.wellPlacedColors;
	}

	return information;
}