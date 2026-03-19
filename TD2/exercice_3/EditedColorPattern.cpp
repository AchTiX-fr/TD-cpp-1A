#include "EditedColorPattern.h"
#include "ColorValue.h"

EditedColorPattern::EditedColorPattern()
	: editedColorIndex(0)
{

}

void EditedColorPattern::resetColors()
{
	for (int iColor = 0; iColor < pattern.getSize(); ++iColor)
		pattern[iColor].setValue(ColorValue::RED);

	editedColorIndex = 0;
}

void EditedColorPattern::moveToLeft()
{
	if (editedColorIndex > 0)
		--editedColorIndex;
}

void EditedColorPattern::moveToRight()
{
	if (editedColorIndex < pattern.getSize() - 1)
		++editedColorIndex;
}

int EditedColorPattern::getEditedColorIndex() const
{
	return editedColorIndex;
}

const ColorPattern& EditedColorPattern::getColorPattern() const
{
	return pattern;
}

void EditedColorPattern::increaseEditedColor()
{
	pattern[editedColorIndex].increaseValue();
}

void EditedColorPattern::decreaseEditedColor()
{
	pattern[editedColorIndex].decreaseValue();
}