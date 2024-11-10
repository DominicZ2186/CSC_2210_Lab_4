//
// Created by zagrad on 10/28/2024.
//

#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

class Room;

class Map {
private:
  std::vector<Room*> rooms;
  int width, height;
  Room* getRoomAt(int x, int y) const;
  int const MAX_HAZARDS = 12;
  int const MAX_WEAPONS = 2;
  int mutantPlants;
  int hazards;
  int weapons;
public:
  Map(int width = 6, int height= 6);

  ~Map();

  void generateRooms();
  void placeHazards(int x, int y);
  void placeWeapons(int x, int y);
  void placeMutant(int x, int y);
  Room* getRandomEmptyRoom();
  void display();
};



#endif //MAP_H
