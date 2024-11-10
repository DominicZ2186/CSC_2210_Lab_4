#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
using namespace std;



int main() {
    Game* game = new Game(false);
    game->play();
    delete game;
    return 0;
    }