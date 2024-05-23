#pragma once
#include <vector>
#include "String.h"

class Player
{
private:
	std::vector<String> spells;

public:
	Player();
	bool KnowsSpell(const String& spell);
	void CheckSpell(const String& spell);
};