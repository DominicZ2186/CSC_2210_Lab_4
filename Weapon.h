//
// Created by zagrad on 10/28/2024.
//

#ifndef WEAPON_H
#define WEAPON_H

#include "Direction.h"
#include <string>

class Room;

/**
 * @class Weapon
 * @brief Base class for weapons that can be used by the gardener in the game.
 *
 * Each weapon has a symbol and can be collected or used in a specific room.
 */
class Weapon {
protected:
  char symbol;
  bool isCollected;

public:
  /**
   * @brief Constructs a Weapon with a specific symbol.
   * @param sym The symbol representing the weapon.
   */
  Weapon(char sym) : symbol(sym), isCollected(false) {}

  /**
   * @brief Virtual destructor for the Weapon class.
   */
  virtual ~Weapon() = default;

  /**
   * @brief Uses the weapon in a specified room.
   * @param targetRoom The room where the weapon is used.
   * @return True if the weapon was used successfully.
   */
  virtual bool use(Room* targetRoom) = 0;

  /**
   * @brief Gets the symbol representing the weapon.
   * @return The symbol of the weapon.
   */
  char getSymbol() const;

  /**
   * @brief Checks if the weapon has been picked up by the player.
   * @return True if the weapon is picked up, otherwise false.
   */
  bool isPickedUp() const;

  /**
   * @brief Marks the weapon as collected by the player.
   */
  void pickUp();
};

#endif // WEAPON_H
