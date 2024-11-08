//
// Created by zagrad on 10/28/2024.
//

#include "Room.h"

#include "AcidPool.h"
#include "GardenShears.h"
#include "Spores.h"
#include "Spray.h"

Room::Room(int roomID){
  this->roomID = roomID;
  this->north = nullptr;
  this->south = nullptr;
  this->east = nullptr;
  this->west = nullptr;
  this->hazard = nullptr;
  this->weapon = nullptr;

}

void Room::connect(Direction direction, Room* room){
  if (direction == Direction::NORTH) {
    this->north = room;
  } else if (direction == Direction::SOUTH) {
    this->south = room;
  } else if (direction == Direction::EAST) {
    this->east = room;
  } else if (direction == Direction::WEST) {
    this->west = room;
  }
}

Room Room::getExit(Direction direction) {
  return Room(roomID);
}

void Room::setHazard() {
  int randNum = (rand() % 2) + 1;
  if (randNum == 1) {
    this-> hazard = new Spores();
  } else {
    this-> hazard = new AcidPool();
  }
}

void Room::setWeapon(bool hasShears) {
  int randNum = (rand() % 2) + 1;
  if (randNum == 1 && !hasShears) {
    this-> weapon = new GardenShears();
  } else {
    this-> weapon = new Spray();
  }
}

void Room::setPlant() {

}

void Room::getClues() {

}

char Room::getDisplayChar() {
  return 'n';
}




