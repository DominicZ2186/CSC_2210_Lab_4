//
// Created by zagrad on 10/28/2024.
//

#ifndef SPORES_H
#define SPORES_H
#include "Hazard.h"


class Spores: public Hazard {
public:
  Spores(): Hazard('!', "You notice Sparkling spores drift in the air") {}
  void interact(Game* game) override;

};

#endif //SPORES_H
