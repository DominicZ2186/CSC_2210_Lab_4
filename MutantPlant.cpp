//
// Created by zagrad on 10/28/2024.
//

#include "MutantPlant.h"
#include "Game.h"
#include "Room.h"
#include "Gardener.h"
#include <iostream>
using namespace std;

void MutantPlant::interact(Game* game) {
    game->endGame("OOPs, You just entered the room with the Mutant Plant. "
                  "You are eaten by the mutant plant, there is no hope for this\nbeautiful garden.\n");
}

