//
// Created by zagrad on 10/28/2024.
//

#include "Room.h"

#include "AcidPool.h"
#include "GardenShears.h"
#include "Spores.h"
#include "Spray.h"

Room::Room(int roomID){
  this->north = nullptr;
  this->south = nullptr;
  this->east = nullptr;
  this->west = nullptr;
  this->roomID = roomID;
  this->hazard = nullptr;
  this->weapon = nullptr;
  this->plant = nullptr;
  this->hasPlayer = false;
}

Room::~Room() {
  delete hazard;
  delete plant;
  delete weapon;
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

Room* Room::getExit(Direction direction) {
  if (direction == Direction::NORTH) {
    return north;
  } if (direction == Direction::SOUTH) {
    return south;
  } if (direction == Direction::EAST) {
    return east;
  }
  return west;
}

void Room::setHazard() {
  //TODO: fix seg fault caused by initialization of Hazards, Weapons, and MutantPlant
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
  this-> plant = new MutantPlant();
}

void Room::getClues() {
  //check north
  if (north != nullptr) {
    if (north->hazard != nullptr) {
      std::cout << north->hazard->getClue() <<" ";
    } else if (north->plant != nullptr) {
      std::cout << north->plant->getClue() << " ";
    }
  }
  //check south
  if (south != nullptr) {
    if (south->hazard != nullptr) {
      std::cout << south->hazard->getClue() << " ";
    } else if (south->plant != nullptr) {
      std::cout << south->plant->getClue() << " ";
    }
  }
  //check east
  if (east != nullptr) {
    if (east->hazard != nullptr) {
      std::cout << east->hazard->getClue() << " ";
    } else if (east->plant != nullptr) {
      std::cout << east->plant->getClue() << " ";
    }
  }
  //check west
  if (west != nullptr) {
    if (west->hazard != nullptr) {
      std::cout << west->hazard->getClue() << " ";
    } else if (west->plant != nullptr) {
      std::cout << west->plant->getClue() << " ";
    }
  }
  std::cout << std::endl;
}

char Room::getDisplayChar() {
  if (hazard) {
    return hazard->getSymbol();
  }
  if (plant) {
    return plant->getSymbol();
  }
  if (weapon) {
    return weapon->getSymbol();
  }
  if (hasPlayer) {
    return '+';
  }
  return '.';
}

bool Room::isEmpty() const{
  return hazard == nullptr && weapon == nullptr && plant == nullptr;
}

void Room::setPlayer() {
  hasPlayer = !hasPlayer;
}

bool Room::hasHazard() const {
  return hazard != nullptr;
}

bool Room::hasWeapon() const {
  return weapon != nullptr;
}

bool Room::hasPlant() const {
  return plant != nullptr;
}

Hazard* Room::getHazard() const {
  return hazard;
}

Weapon *Room::getWeapon() const {
  return weapon;
}

MutantPlant* Room::getPlant() const {
  return plant;
}