//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENSHEARS_H
#define GARDENSHEARS_H
#include "Direction.h"
#include "Weapon.h"



class GardenShears: public Weapon {
 public:
    GardenShears() : Weapon('>') {}
    bool use(Room* targetRoom) override;
 };



#endif //GARDENSHEARS_H
