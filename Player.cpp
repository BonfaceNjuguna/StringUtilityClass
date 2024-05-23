#include "Player.h"
#include <algorithm>

Player::Player(){
	//initialize the vector with the spells
	spells = { "eclipse", "eruption", "frostbite", "levitate", "mirage", "petrify", "polymorph", "teleport", "thunderwave", "vortex" };
	std::sort(spells.begin(), spells.end());
}

bool Player::KnowsSpell(const String& spell) {
	//binary search
	int low = 0;
	int high = spells.size() - 1;

	while (low <= high) {
		//find the middle of the array
		int mid = low + (high - low) / 2;

		//check if the spell is in the middle
		if (spells[mid] == spell) {
			return true;
		}
		//check if the spell is in the left half
		else if (spells[mid] < spell) {
			low = mid + 1;
		}
		//check if the spell is in the right half
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