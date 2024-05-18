#include "Game.h"
#include "../String.h"
#include <iostream>

// Constructor
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
        currentRoom->Describe();
        String command = "You can move by using the following commands\nmove north\nmove south\nmove east\nmove west\nYou can also use an item or quit.\nWhat would you like to do?";
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
        else if (lowerInput.EqualTo("use")) {
            Item* item = currentRoom->GetItem();
            if (item != nullptr) {
                item->Use();
            }
            else {
                String ("There is nothing to use.\n").WriteToConsole();
            }
        }
        else {
            String ("Invalid command.\n").WriteToConsole();
        }
    }
}