//
// Created by zagrad on 10/28/2024.
//

#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

class Room;

/**
 * @class Map
 * @brief Represents the game's map, managing rooms, hazards, and weapons within the grid.
 */
class Map {
private:
    std::vector<Room*> rooms;
    int width, height;
    Room* getRoomAt(int x, int y) const;
    int const MAX_HAZARDS = 6;
    int const MAX_WEAPONS = 2;
    int mutantPlants;
    int hazards;
    int weapons;

public:
    /**
     * @brief Constructs a map with given dimensions.
     * @param width Width of the map (default is 6).
     * @param height Height of the map (default is 6).
     */
    Map(int width = 6, int height = 6);

    /**
     * @brief Destructor for the Map class.
     */
    ~Map();

    /**
     * @brief Generates the rooms and populates the map with hazards and weapons.
     */
    void generateRooms();

    /**
     * @brief Places a hazard in the specified room coordinates.
     * @param x The x-coordinate of the room.
     * @param y The y-coordinate of the room.
     */
    void placeHazards(int x, int y);

    /**
     * @brief Places a weapon in the specified room coordinates.
     * @param x The x-coordinate of the room.
     * @param y The y-coordinate of the room.
     */
    void placeWeapons(int x, int y);

    /**
     * @brief Places a mutant plant in the specified room coordinates.
     * @param x The x-coordinate of the room.
     * @param y The y-coordinate of the room.
     */
    void placeMutant(int x, int y);

    /**
     * @brief Gets a random empty room from the map.
     * @return Pointer to a random empty room.
     */
    Room* getRandomEmptyRoom();

    /**
     * @brief Displays the map's layout in the console.
     */
    void display();
};

#endif // MAP_H
