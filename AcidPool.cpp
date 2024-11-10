//
// Created by zagrad on 10/28/2024.
//

#include "AcidPool.h"
#include "Game.h"
#include <iostream>

using namespace std;

void AcidPool::interact(Game* game) {
    game->endGame("As you enter this room, you are hit with a sharp burning "
            "pain that instantly engulfs your body. \n"
            "You had stepped into an acid pool and disintegrated.");
}
