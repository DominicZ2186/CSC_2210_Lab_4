//
// Created by zagrad on 10/28/2024.
//

#ifndef ACIDPOOL_H
#define ACIDPOOL_H
#include "Hazard.h"
#include "Game.h"




class AcidPool: public Hazard {
public:
  AcidPool(): Hazard('@', "You smell something acidic, your lungs start to hurt.") {}
  void interact(Game* game) override;

};



#endif //ACIDPOOL_H
