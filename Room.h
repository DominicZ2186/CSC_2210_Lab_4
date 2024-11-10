//
// Created by zagrad on 10/28/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "Hazard.h"
#include "Weapon.h"
#include "MutantPlant.h"

class Hazard;
class Weapon;
class MutantPlant;

class Room {
private:
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Hazard* hazard;
    Weapon* weapon;
    MutantPlant* plant;
    bool hasPlayer;
    int roomID;
public:
    Room(int roomID);
    ~Room();
    void connect(Direction direction, Room* room);
    Room* getExit(Direction direction);
    void setHazard();
    void setWeapon(bool hasShears);
    void setPlant();
    void getClues();
    char getDisplayChar();
    bool isEmpty() const;
    void setPlayer();
    bool hasHazard() const;
    Hazard* getHazard() const;
    bool hasWeapon() const;
    Weapon* getWeapon() const;
    bool hasPlant() const;
    MutantPlant* getPlant() const;
};



#endif //ROOM_H
