#pragma once
#include "../String.h"
#include "Item.h"

class Room {
private:
    String description; // The description of the room
    Item* item; // The item in the room

public:
    Room(const String& _description, Item* _item = nullptr);

    void Describe(); // Describe the room
    Item* GetItem(); // Get the item in the room
};