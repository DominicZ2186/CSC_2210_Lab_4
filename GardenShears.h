//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENSHEARS_H
#define GARDENSHEARS_H
#include "Direction.h"
#include "Game.h"
#include "Weapon.h"



class GardenShears: public Weapon {
 public:
    GardenShears() {}
    bool use(Direction dir, Game* game) override;
 };



#endif //GARDENSHEARS_H
