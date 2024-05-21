#include "Player.h"
#include <algorithm>

Player::Player(){
	spells = { "eclipse", "eruption", "frostbite", "levitate", "mirage", "petrify", "polymorph", "teleport", "thunderwave", "vortex" };
	std::sort(spells.begin(), spells.end());
}

bool Player::KnowsSpell(const String& spell) {
	//implement custom binary search
	int low = 0;
	int high = spells.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (spells[mid] == spell) {
			return true;
		}
		else if (spells[mid] < spell) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return false;
}

//check if the player knows a spell and print the result
void Player::CheckSpell(const String& spell) {
	if (KnowsSpell(spell)) {
		String("Player knows the spell \n").WriteToConsole();
	}
	else {
		String("Player does not know the spell \n").WriteToConsole();
	}
}