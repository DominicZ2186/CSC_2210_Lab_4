//
// Created by zagrad on 10/28/2024.
//

#ifndef SPORES_H
#define SPORES_H

#include "Hazard.h"



/**
 * @class Spores
 * @brief A hazard that teleports the player to a random room when encountered.
 *
 * Spores are represented by a symbol and provide a clue hinting at their presence.
 */
class Spores : public Hazard {
public:
  /**
   * @brief Constructs a Spores hazard with a specific symbol and clue.
   */
  Spores() : Hazard('!', "You notice sparkling spores drift in the air") {}

  /**
   * @brief Interacts with the player by teleporting them to a random room.
   * @param game Pointer to the Game instance.
   */
  void interact(Game* game) override;
};

#endif // SPORES_H
