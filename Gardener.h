//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENER_H
#define GARDENER_H
#include "Room.h"
#include "Weapon.h"
#include <vector>


class Room;
class Game;

class Gardener {
private:
    Room* currentRoom;
    std::vector<Weapon*> inventory;
    char symbol;
    int sprayCharges;
public:
    Gardener(Room* startRoom);
    void move(Direction direction, Game* game);
    void useWeapon(size_t weaponIndex, Direction direction, Game *game);
    void pickUpWeapon(Weapon*);
    void displayInventory();
    void setCurrentRoom(Room* room);
    Room *getCurrentRoom() const;
};



#endif //GARDENER_H
