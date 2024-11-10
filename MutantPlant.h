//
// Created by zagrad on 10/28/2024.
//

#ifndef MUTANTPLANT_H
#define MUTANTPLANT_H

#include "Game.h"
#include "Weapon.h"
#include <string>

class Game;
class Weapon;

/**
 * @class MutantPlant
 * @brief Represents the mutant plant enemy in the game.
 *
 * The MutantPlant class defines the behavior of the plant, including interactions
 * with the player and response to attacks.
 */
class MutantPlant {
private:
    bool isAlive;
    char symbol;
    std::string clue;

public:
    /**
     * @brief Constructs a MutantPlant with a symbol and a clue.
     */
    MutantPlant() : isAlive(true), symbol('M'), clue("You see a faint light/glow") {}

    /**
     * @brief ends the game when entered into the room with the mutant plant.
     * @param game Pointer to the Game instance.
     */
    void interact(Game* game);

    /**
     * @brief Checks if the mutant plant is dead.
     * @return True if the mutant plant is dead, otherwise false.
     */
    bool isDead() const { return !isAlive; }

    /**
     * @brief takes a hit, marking it as dead.
     * @param weapon The weapon used to hit the plant.
     */
    void takeHit(Weapon* weapon) { isAlive = false; }

    /**
     * @brief Gets the symbol representing the mutant plant.
     * @return The mutant plant's symbol.
     */
    char getSymbol() const { return symbol; }

    /**
     * @brief Gets the clue indicating the mutant plant's presence.
     * @return The mutant plant's clue.
     */
    std::string getClue() const { return clue; }
};

#endif // MUTANTPLANT_H
