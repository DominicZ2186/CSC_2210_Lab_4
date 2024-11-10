//
// Created by zagrad on 10/28/2024.
//

#include "Spray.h"
#include "Game.h"
#include "Room.h"
#include "MutantPlant.h"
#include "Gardener.h"

bool Spray::use(Direction dir, Game* game) {
    if (charges > 0) {
        charges--;
        // Logic to spray in the specified direction
        return true;
    }
    return false; // No charges left

}

