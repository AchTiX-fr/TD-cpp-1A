#pragma once
#include <vector>
#include "ColorPattern.h"
#include "ColorPatternAnalyse.h"

class MasterMind
{
private:
	const int MAX_PROPOSALS = 10;

	ColorPattern secretPattern;
	std::vector<ColorPattern> proposals;

public:
	MasterMind();

	void newGame();

	void proposeColorPattern(const ColorPattern& colorScheme);

	const std::vector<ColorPattern>& getProposals() const;
	const ColorPattern& getSecretPattern() const;

	ColorPatternAnalyse analyseColorPattern(const ColorPattern& colorScheme) const;

	bool isWin() const;
	bool isLost() const;
};

