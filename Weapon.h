//
// Created by zagrad on 10/28/2024.
//


#ifndef WEAPON_H
#define WEAPON_H

#include "Direction.h"
#include <string>
class Room;

class Weapon {
protected:
  char symbol;
  bool isCollected;

public:
  Weapon(char sym) : symbol(sym), isCollected(false) {}
  virtual ~Weapon() = default;

  virtual bool use(Room* targetRoom) = 0;
  char getSymbol() const {
    return symbol;
  }
  bool isPickedUp() const {
    return isCollected;
  }
  void pickUp() {
    isCollected = true;
  }
};

#endif
