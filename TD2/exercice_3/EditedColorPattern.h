#pragma once
#include "ColorPattern.h"

class EditedColorPattern
{
private:
	ColorPattern pattern;
	int editedColorIndex;

public:
	EditedColorPattern();

	void resetColors();

	void moveToLeft();
	void moveToRight();

	int getEditedColorIndex() const;
	const ColorPattern& getColorPattern() const;

	void increaseEditedColor();
	void decreaseEditedColor();
};

