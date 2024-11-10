//
// Created by zagrad on 10/28/2024.
//

#include "Spores.h"
#include "Game.h"
#include "Room.h"
#include "Gardener.h"



void Spores::interact(Game* game) {
    //TODO: add dialogue here telling the player they have been teleported
    game->teleportGardener();
}