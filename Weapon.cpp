//
// Created by zagrad on 10/28/2024.
//

#include "Weapon.h"

#include "Game.h"



char Weapon::getSymbol() const {
    return symbol;
}
bool Weapon::isPickedUp() const {
    return isCollected;
}
void Weapon::pickUp() {
    isCollected = true;
}

