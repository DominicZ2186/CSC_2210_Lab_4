//
// Created by zagrad on 10/28/2024.
//

#include "Gardener.h"
#include <iostream>

#include "GardenShears.h"
#include "Spray.h"
using namespace std;

Gardener::Gardener(Room* startRoom) {
    this->currentRoom = nullptr;
    this->inventory = {nullptr, nullptr};
}

void Gardener::move(Direction direction) {

}

void Gardener::useWeapon(size_t weaponIndex, Direction direction) {

}


void Gardener::pickUpWeapon(Weapon *) {

}

void Gardener::displayInverntory() const {
    std::cout << "Inventory:\n";
    if (inventory.empty()) {
        std::cout << "  (Empty)\n";
    } else {
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << "  " << i + 1 << ". ";
            if (dynamic_cast<Spray*>(inventory[i])) {
                Spray* spray = dynamic_cast<Spray*>(inventory[i]);
                std::cout << "Spray (Charges: " << spray->getCharges() << ")\n";
            } else if (dynamic_cast<GardenShears*>(inventory[i])) {
                std::cout << "Garden Shears (Unlimited uses)\n";
            } else {
                std::cout << "Unknown Weapon\n";
            }
        }
    }
}

