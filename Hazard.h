//
// Created by zagrad on 10/28/2024.
//

#ifndef HAZARD_H
#define HAZARD_H

#include "Game.h"
#include <string>

class Game;

class Hazard {
protected:
  char symbol;
  std::string clue;
public:
  Hazard(char sym, const std::string& c): symbol(sym), clue(c) {}

  virtual ~Hazard() = default;
  virtual void interact(Game* game) = 0;
  char getSymbol() const {return symbol; }
  std::string getClue() const {return clue;}

};



#endif //HAZARD_H
