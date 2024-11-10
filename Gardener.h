//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENER_H
#define GARDENER_H

#include "Room.h"
#include "Weapon.h"
#include <vector>

class Room;
class Game;

/**
 * @class Gardener
 * @brief Represents the player character, able to move, use weapons, and interact
 * with rooms in the game.
 */
class Gardener {
private:
    Room* currentRoom;
    std::vector<Weapon*> inventory;
    char symbol;
    int sprayCharges;

public:
    /**
     * @brief Constructs a Gardener at a specified starting room.
     * @param startRoom The room where the gardener starts.
     */
    Gardener(Room* startRoom);

    /**
     * @brief Moves the gardener in a specified direction.
     * @param direction The direction to move.
     * @param game Pointer to the Game instance, for game-wide interactions.
     */
    void move(Direction direction, Game* game);

    /**
     * @brief Uses a weapon from the inventory in a specified direction.
     * @param weaponIndex The index of the weapon in the inventory.
     * @param direction The direction in which to use the weapon.
     * @param game Pointer to the Game instance.
     */
    void useWeapon(size_t weaponIndex, Direction direction, Game *game);

    /**
     * @brief Adds a weapon to the gardener's inventory.
     * @param weapon The weapon to add.
     */
    void pickUpWeapon(Weapon* weapon);

    /**
     * @brief Displays the contents of the gardener's inventory.
     */
    void displayInventory();

    /**
     * @brief Sets the gardener's current room.
     * @param room The room to set as the gardener's current location.
     */
    void setCurrentRoom(Room* room);

    Weapon *getWeaponAt(int index);

    /**
     * @brief Gets the gardener's current room.
     * @return Pointer to the current room of the gardener.
     */
    Room* getCurrentRoom() const;
};

#endif // GARDENER_H
