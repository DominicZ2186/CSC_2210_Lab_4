//
// Created by zagrad on 10/28/2024.
//

#ifndef SPRAY_H
#define SPRAY_H
#include "Weapon.h"



class Spray: public Weapon {
 private:
  int charges;
public:
  Spray(int initialCharges = 1): charges(initialCharges) {}
  bool use(Direction dir, Game* game) override;
  int getCharges() const {return charges;}

};



#endif //SPRAY_H
