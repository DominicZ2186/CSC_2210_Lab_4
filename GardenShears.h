//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENSHEARS_H
#define GARDENSHEARS_H

#include "Weapon.h"

/**
 * @class GardenShears
 * @brief A weapon used by the gardener with unlimited uses.
 *
 * Garden shear is used to kill the mutant plant.
 */
class GardenShears : public Weapon {
public:
    /**
     * @brief Constructs GardenShears with the symbol.
     */
    GardenShears() : Weapon('>') {}

    /**
     * @brief Uses the GardenShears in a specified room.
     * @param targetRoom The room where the shears are used.
     * @return True if the action is successful.
     */
    bool use(Room* targetRoom) override;
};

#endif // GARDENSHEARS_H
