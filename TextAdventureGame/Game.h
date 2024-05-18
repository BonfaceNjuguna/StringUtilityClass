#pragma once
#include <vector>
#include "Room.h"
#include "ItemType.h"

class Game {
private:
    Room* currentRoom; // The room the player is currently in
    std::vector<Room*> rooms; // All the rooms in the game

public:
    Game();
    ~Game();

    // The main game loop
    void Play();
};