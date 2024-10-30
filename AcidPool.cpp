//
// Created by zagrad on 10/28/2024.
//

#include "AcidPool.h"
#include "Game.h"

void AcidPool::interact(Game* game) {
    game->endGame("You fall into an acid pool and die");
}
