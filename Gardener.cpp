//
// Created by zagrad on 10/28/2024.
//

#include "Gardener.h"

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
