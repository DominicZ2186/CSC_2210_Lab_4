//
// Created by zagrad on 10/28/2024.
//

#ifndef HAZARD_H
#define HAZARD_H

#include "Game.h"
#include <string>

class Game;

/**
 * @class Hazard
 * @brief Represents a dangerous element in the game that interacts with the player.
 *
 * Each Hazard has a symbol to represent it visually and a clue that provides
 * hints to the player about its presence.
 */
class Hazard {
protected:
  char symbol;
  std::string clue;

public:
  /**
   * @brief Constructs a Hazard with a symbol and a clue.
   * @param sym The symbol for the hazard.
   * @param c The clue indicating the hazard's presence.
   */
  Hazard(char sym, const std::string& c) : symbol(sym), clue(c) {}

  /**
   * @brief Virtual destructor for the Hazard class.
   */
  virtual ~Hazard() = default;

  /**
   * @brief Defines interaction behavior when the player encounters the hazard.
   * @param game Pointer to the Game instance.
   */
  virtual void interact(Game* game) = 0;

  /**
   * @brief Gets the symbol representing the hazard.
   * @return The hazard's symbol.
   */
  char getSymbol() const { return symbol; }

  /**
   * @brief Gets the clue associated with the hazard.
   * @return The hazard's clue.
   */
  std::string getClue() const { return clue; }
};

#endif // HAZARD_H
