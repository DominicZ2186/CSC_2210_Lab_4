//
// Created by zagrad on 10/28/2024.
//

#include "Room.h"

Room::Room(int roomID){
  this->roomID = roomID;
}

void Room::connect(Direction direction, Room* room){

}

Room Room::getExit(Direction direction) {
  return Room(roomID);
}

void Room::setHazard() {

}

void Room::setWeapon() {

}

void Room::setPlant() {

}

void Room::getClues() {

}

char Room::getDisplayChar() {
  return 'n';
}




