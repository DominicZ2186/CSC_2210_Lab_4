//
// Created by zagrad on 10/28/2024.
//

#include "Gardener.h"
#include <iostream>

#include "GardenShears.h"
#include "Spray.h"
using namespace std;

Gardener::Gardener(Room* startRoom) {
    this->symbol = '+';
    this->currentRoom = nullptr;
    this->inventory = {new Spray(), new GardenShears()};
    this->sprayCharges = 2;
}

void Gardener::move(Direction direction, Game* game) {
    //have the logic to move the gardener based on direction.
    currentRoom->setPlayer();
    currentRoom = currentRoom->getExit(direction);
    if (currentRoom->hasHazard()) {
        currentRoom->getHazard()->interact(game);
    }
    currentRoom->setPlayer();
}

void Gardener::useWeapon(size_t index, Direction dir, Game *game) {
    if (index < inventory.size() && inventory[index] != nullptr) {
        inventory[index]->use(dir, game);  //pass the game instance
    } else {
        std::cout << "Invalid weapon selection!\n";
    }
}



void Gardener::pickUpWeapon(Weapon *weapon) {
    if (weapon != nullptr) {
        weapon->pickUp();
        std::cout << "Picked up a " << (dynamic_cast<Spray*>(weapon) ? "Spray" : "Garden Shears") << "!\n";
        if (dynamic_cast<Spray*>(weapon)) {
            sprayCharges++;
        } else {
            inventory[1] = new GardenShears();
        }
    }
}

void Gardener::displayInventory() {
    std::cout << "Inventory:\n";
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] != nullptr) {
            if (dynamic_cast<Spray*>(inventory[i])) {
                std::cout << "Sprays (uses left: " << sprayCharges << ")\n";
            }
            if (dynamic_cast<GardenShears*>(inventory[i])) {
                std::cout << "Garden Shears (unlimited uses)\n";
            }
        }
    }
}

void Gardener::setCurrentRoom(Room *room) {
    this->currentRoom = room;
}

Room* Gardener::getCurrentRoom() const{
    return this->currentRoom;
}