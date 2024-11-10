//
// Created by zagrad on 10/28/2024.
//

#include "AcidPool.h"
#include "Game.h"

void AcidPool::interact(Game* game) {
    // Game over logic
    std::cout << "You stepped into an acid pool! Game over!" << std::endl;
    game->endGame("You died in an acid pool.");
}
