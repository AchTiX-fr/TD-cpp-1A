#include "Color.h"
#include <random>

Color::Color()
	: value(ColorValue::RED)
{

}

ColorValue Color::getValue() const
{
	return value;
}

void Color::setValue(ColorValue newValue)
{
	value = newValue;
}

void Color::increaseValue()
{
	if (value == Color::MAX_COLOR_VALUE)
		value = Color::MIN_COLOR_VALUE;
	else
		value = static_cast<ColorValue>(static_cast<int>(value) + 1);
}

void Color::decreaseValue()
{
	if (value == Color::MIN_COLOR_VALUE)
		value = Color::MAX_COLOR_VALUE;
	else
		value = static_cast<ColorValue>(static_cast<int>(value) - 1);
}

void Color::randomizeValue()
{
	std::random_device device;
	std::mt19937 randomGenerator(device());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(Color::MIN_COLOR_VALUE, Color::MAX_COLOR_VALUE);

	value = static_cast<ColorValue>(distribution(randomGenerator));
}

bool Color::operator==(const Color& color) const
{
	return value == color.value;
}

bool Color::operator!=(const Color& color) const
{
	return !(*this == color);
}