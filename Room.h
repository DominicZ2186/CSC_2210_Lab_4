//
// Created by zagrad on 10/28/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "Hazard.h"
#include "Weapon.h"
#include "MutantPlant.h"

class Hazard;
class Weapon;
class MutantPlant;

/**
 * @class Room
 * @brief Represents a room in the game, which may contain hazards, weapons, or a mutant plant.
 *
 * Each room can be connected to adjacent rooms and contains information about its contents
 * and whether the player is present.
 */
class Room {
private:
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Hazard* hazard;
    Weapon* weapon;
    MutantPlant* plant;
    bool hasPlayer;
    int roomID;

public:
    /**
     * @brief Constructs a Room with a unique ID.
     * @param roomID The ID assigned to the room.
     */
    Room(int roomID);

    /**
     * @brief Destructor for Room.
     */
    ~Room();

    /**
     * @brief Connects this room to another room in the specified direction.
     * @param direction The direction to connect to.
     * @param room Pointer to the room to connect.
     */
    void connect(Direction direction, Room* room);

    /**
     * @brief Retrieves the room connected in the specified direction.
     * @param direction The direction to look in.
     * @return Pointer to the room in the specified direction, or nullptr if none.
     */
    Room* getExit(Direction direction);

    /**
     * @brief Adds a hazard to the room.
     */
    void setHazard();

    /**
     * @brief Adds a weapon to the room.
     * @param hasShears If true, the weapon is garden shears; otherwise, it's another type.
     */
    void setWeapon(bool hasShears);

    /**
     * @brief Removes the weapon from the room, if any.
     */
    void removeWeapon();

    /**
     * @brief Adds a mutant plant to the room.
     */
    void setPlant();

    /**
     * @brief Displays clues about nearby hazards or the mutant plant.
     */
    void getClues();

    /**
     * @brief Gets the character of the room for display purposes.
     * @return The character symbol representing the room's contents.
     */
    char getDisplayChar();

    /**
     * @brief Checks if the room is empty (no hazards, weapons, or plant).
     * @return True if the room is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Toggles the presence of the player in the room.
     */
    void setPlayer();

    /**
     * @brief Checks if the room contains a hazard.
     * @return True if there is a hazard, otherwise false.
     */
    bool hasHazard() const;

    /**
     * @brief Retrieves the hazard in the room.
     * @return Pointer to the hazard in the room.
     */
    Hazard* getHazard() const;

    /**
     * @brief Checks if the room contains a weapon.
     * @return True if there is a weapon, otherwise false.
     */
    bool hasWeapon() const;

    /**
     * @brief Retrieves the weapon in the room.
     * @return Pointer to the weapon in the room.
     */
    Weapon* getWeapon() const;

    /**
     * @brief Checks if the room contains a mutant plant.
     * @return True if there is a mutant plant, otherwise false.
     */
    bool hasPlant() const;

    /**
     * @brief Retrieves the mutant plant in the room.
     * @return Pointer to the mutant plant in the room.
     */
    MutantPlant* getPlant() const;
};

#endif // ROOM_H
