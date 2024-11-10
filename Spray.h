//
// Created by zagrad on 10/28/2024.
//

#ifndef SPRAY_H
#define SPRAY_H

#include "Weapon.h"

/**
 * @class Spray
 * @brief A weapon used by the gardener with limited charges to fight the mutant plant.
 *
 * Spray is represented by a symbol and can be used on a target room.
 */
class Spray : public Weapon {
public:
  /**
   * @brief Constructs a Spray weapon with a  symbol.
   */
  Spray() : Weapon('>') {}

  /**
   * @brief Uses the spray in a specified room, applying its effect to the target.
   * @param targetRoom The room where the spray is used.
   * @return True if the action is successful, otherwise false.
   */
  bool use(Room* targetRoom) override;
};

#endif // SPRAY_H
