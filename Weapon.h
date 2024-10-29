//
// Created by zagrad on 10/28/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "Direction.h"



class Weapon {
protected:
  char symbol;
  bool isCollected;
public:
  Weapon() : symbol('>'), isCollected(false) {}
  virtual ~Weapon();

  virtual bool use(Direction dir, class Game* game) = 0;
  char getSymbol() const {return symbol; }
  bool isPickedUp() const {return isCollected;}
  void pickUp() {isCollected = true;}

};



#endif //WEAPON_H
