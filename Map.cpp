//
// Created by zagrad on 10/28/2024.
//

#include "Map.h"

#include "AcidPool.h"
#include "Spores.h"
#include "Spray.h"
using namespace std;

Map::Map(int width, int height) {
    this -> width = width;
    this -> height = height;
    this -> mutantPlants = 0;
    this ->hazards = 0;
    this -> weapons = 0;
    rooms.resize(width * height);
    for(auto& room : rooms) {
        room = nullptr;
    }
    generateRooms();
}

Map::~Map() {
    for(auto& room : rooms) {
        delete room;
    }
}


void Map::generateRooms() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
             int randNum = (rand() % (width * height)) + 1;
            if (randNum <= 12 && hazards < MAX_HAZARDS) {
                placeHazards(x, y);
            } else if(randNum <= 14 && weapons < MAX_WEAPONS) {
                placeWeapons(x, y);
            } else if(randNum == 15 && mutantPlants == 0) {
                placeMutant(x, y);
            } else {

            }
        }
    }
    //TODO: make sure that mutant plant && weapons are placed
    if (mutantPlants == 0) {

    }
    if (weapons <= 1) {

    }
}

void Map::placeHazards(int x, int y) {
    rooms[x][y].setHazard();
    hazards++;
}

void Map::placeWeapons(int x, int y) {
    rooms[x][y].setWeapon(weapons == 0);
    weapons++;
}

void Map::placeMutant(int x, int y) {
    rooms[x][y].setPlant();
    mutantPlants++;
}

Room* Map::getRandomEmptyRoom() {
    //TODO: make functionality
    return new Room(1);
}

void Map::display() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cout << rooms[i][j].getDisplayChar() << " ";
        }
        cout << endl;
    }

}

Room* Map::getRoomAt(int x, int y) const {
    if(x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr;
    }
    return rooms[y * width + x];
}





