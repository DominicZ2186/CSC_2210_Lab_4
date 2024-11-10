//
// Created by zagrad on 10/28/2024.
//

#ifndef SPRAY_H
#define SPRAY_H
#include "Weapon.h"

class Spray: public Weapon {
public:
  Spray(): Weapon('>') {
  }

  bool use(Room* targetRoom) override;
};



#endif //SPRAY_H
