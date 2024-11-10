//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENER_H
#define GARDENER_H

#include "Room.h"
#include "Weapon.h"
#include <vector>

class Room;

class Gardener {
private:
    Room* currentRoom;
    std::vector<Weapon*> inventory;
    char symbol;
public:
    Gardener(Room* startRoom);
    void move(Direction direction);
    void useWeapon(size_t weaponIndex, Direction direction);
    void pickUpWeapon(Weapon*);
    void displayInverntory() const;
};



#endif //GARDENER_H
