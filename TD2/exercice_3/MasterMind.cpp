#include "MasterMind.h"

MasterMind::MasterMind()
	: secretPattern()
{
	newGame();
}

void MasterMind::newGame()
{
	proposals.clear();
	secretPattern.randomize();
}

void MasterMind::proposeColorPattern(const ColorPattern& colorScheme)
{
	proposals.push_back(colorScheme);
}

const std::vector<ColorPattern>& MasterMind::getProposals() const
{
	return proposals;
}

const ColorPattern& MasterMind::getSecretPattern() const
{
	return secretPattern;
}

ColorPatternAnalyse MasterMind::analyseColorPattern(const ColorPattern& colorScheme) const
{	
	return secretPattern.compare(colorScheme);
}

bool MasterMind::isWin() const
{
	return proposals.empty() == false && proposals.back() == secretPattern;
}

bool MasterMind::isLost() const
{
	return proposals.size() >= MAX_PROPOSALS && proposals.back() != secretPattern;
}