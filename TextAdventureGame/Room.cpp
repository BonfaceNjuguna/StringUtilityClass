#include "Room.h"
#include <iostream>

// Constructor
Room::Room(const String& _description, Item* _item) : description(_description), item(_item) {}

// Describe method
void Room::Describe() {
    description.WriteToConsole();
    if (item != nullptr) {
        item->Describe();
    }
}

// GetItem method
Item* Room::GetItem() {
    return item;
}