//
// Created by zagrad on 10/28/2024.
//

#ifndef ACIDPOOL_H
#define ACIDPOOL_H
#include "Hazard.h";
#include "Game.h";




class AcidPool: public Hazard {
public:
public:
  AcidPool(): Hazard('@', "You smell something acidic") {}
  void interact(Game* game) override;

};



#endif //ACIDPOOL_H
