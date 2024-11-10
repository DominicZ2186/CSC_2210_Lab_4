//
// Created by zagrad on 10/28/2024.
//

#include "GardenShears.h"
#include "Game.h"
#include "Room.h"
#include "MutantPlant.h"
#include "Gardener.h"

bool GardenShears::use(Room* targetRoom) {
    if (targetRoom->hasPlant()) {
        return true;
    }
    return false;
}