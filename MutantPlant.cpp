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
    game->endGame("Upon entering the next room you immediately spot "
            "the mutant plant which turned out to be the source of the faint light. \n"
            "You move to ready a weapon to exterminate this evil, "
            "but before you can grasp any tools you are restrained by various spiky vines. \n"
            "You have been caught by the mutant plant, there is no more hope for this garden.");
}

