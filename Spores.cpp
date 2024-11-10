//
// Created by zagrad on 10/28/2024.
//

#include "Spores.h"
#include "Game.h"
#include "Room.h"
#include "Gardener.h"



void Spores::interact(Game* game) {
    // Teleporting logic
    std::cout << "The spores transport you to a random room!" << std::endl;
    game->teleportGardener();
}