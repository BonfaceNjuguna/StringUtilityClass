#include "Game.h"
#include "../String.h"
#include <iostream>

// initialize the rooms vector
Game::Game() {
    rooms.push_back(new Room("You are in an empty room.\n"));
    rooms.push_back(new Room("You are in a small room.\n", new BoxOfDonuts(5)));
    rooms.push_back(new Room("You are in a large room.\n", new BoxOfPizza(8)));
    rooms.push_back(new Room("You are in a long room.\n", new BoxOfCandy(10)));
    rooms.push_back(new Room("You are in a wide room.\n", new BoxOfCookies(12)));
    currentRoom = rooms[0];
}

// Destructor
Game::~Game() {
    for (Room* room : rooms) {
        delete room;
    }
}

// Play method
void Game::Play() {
    String input;
    while (true) {
        // Describe the current room
        currentRoom->Describe();
        String command = "You can move by using the following commands\nmove north\nmove south\nmove east\nmove west\nYou can also use an item or quit.\nYou can also search for a spell - 'spell x' for example\nWhat would you like to do?\n";
        command.WriteToConsole();
        input.ReadFromConsole();

        // Convert input to lower case for case-insensitive comparison
        String lowerInput = input.ToLower();

        if (lowerInput.EqualTo("quit")) {
            break;
        }
        else if (lowerInput.EqualTo("move north")) {
            currentRoom = rooms[1];
        }
        else if (lowerInput.EqualTo("move south")) {
            currentRoom = rooms[2];
        }
        else if (lowerInput.EqualTo("move east")) {
            currentRoom = rooms[3];
        }
        else if (lowerInput.EqualTo("move west")) {
            currentRoom = rooms[4];
        }
        else if (lowerInput.EqualTo("start")) {
            currentRoom = rooms[0];
        }
        // Check if the player wants to use an item
        else if (lowerInput.EqualTo("use")) {
            Item* item = currentRoom->GetItem();
            if (item != nullptr) {
                item->Use();
            }
            else {
                String ("There is nothing to use.\n").WriteToConsole();
            }
        }
        // Check if the player knows a spell
        else if (lowerInput.Find("spell ") == 0) {
            String spell = lowerInput.Replace("spell ", "");
            player.CheckSpell(spell);
        }
        else {
            String ("Invalid command.\n").WriteToConsole();
        }
    }
}