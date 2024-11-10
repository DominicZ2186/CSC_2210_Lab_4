//
// Created by zagrad on 10/28/2024.
//

#ifndef MUTANTPLANT_H
#define MUTANTPLANT_H
#include "Game.h"
#include "Weapon.h"
#include <string>

class MutantPlant {
private:
  bool isAlive;
  char symbol;
  std::string clue;
 public:
    MutantPlant() : isAlive(true), symbol('M'),
         clue("You see a faint light/glow") {}

    void interact(Game* game);
    bool isDead() const { return !isAlive; }
    void takeHit(Weapon* weapon) { isAlive = false; }
    char getSymbol() const { return symbol; }
    std::string getClue() const { return clue; }

};



#endif //MUTANTPLANT_H
