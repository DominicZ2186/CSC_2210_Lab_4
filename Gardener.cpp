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
    this->inventory = {new Spray(), nullptr};
    this->sprayCharges = 2;
}

void Gardener::move(Direction direction, Game* game) {
    //have the logic to move the gardener based on direction.
    if (currentRoom->getExit(direction) != nullptr) {
        currentRoom->setPlayer();
        currentRoom = currentRoom->getExit(direction);
        if (currentRoom->hasHazard()) {
            currentRoom->getHazard()->interact(game);
        } else if(currentRoom->hasPlant()) {
            currentRoom->getPlant()->interact(game);
        } else if(currentRoom->hasWeapon()) {
            pickUpWeapon(currentRoom->getWeapon());
        }
        currentRoom->setPlayer();
    } else {
        std::cout << "You walked into a wall, maybe pick a different direction?" << std::endl;
    }
}

void Gardener::useWeapon(size_t index, Direction dir, Game *game) {
    Room* targetRoom = currentRoom->getExit(dir);
    if (index < inventory.size() && inventory[index] != nullptr && targetRoom != nullptr) {
        if (dynamic_cast<Spray*>(inventory[index])) {
            if (sprayCharges > 0) {
                sprayCharges--;
                if (inventory[index]->use(targetRoom)) {
                    game->endGame("With your spray bottle of herbicides you are able to exterminate the Mutant Plant!");
                } else {
                    std::cout << "You hit nothing" << std::endl;
                }
            } else {
                std::cout << "You have run out of herbicide within your spray bottle, "
                             "maybe you could find more..." << std::endl;
            }
        } else {
            if (inventory[index]->use(targetRoom)) {
                game->endGame("With your sharp garden shears you are able to cut down the Mutant Plant!");
            } else {
                std::cout << "You hit nothing" << std::endl;
            }
        }
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
        currentRoom->removeWeapon();
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