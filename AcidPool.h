//
// Created by zagrad on 10/28/2024.
//

#ifndef ACIDPOOL_H
#define ACIDPOOL_H

#include "Hazard.h"
#include "Game.h"

/**
 * @class AcidPool
 * A hazard that ends the game if the player steps into it.
 */
class AcidPool : public Hazard {
public:
  /**
   * Constructs an AcidPool with a symbol and a clue.
   */
  AcidPool() : Hazard('@', "You smell something acidic, your lungs start to hurt.") {}

  /**
   * @brief Ends the game when the player interacts with the acid pool.
   * @param game Pointer to the Game instance.
   */
  void interact(Game* game) override;
};

#endif // ACIDPOOL_H
