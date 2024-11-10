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
    generateRooms();
}

Map::~Map() {
    for (auto room : rooms) {
        delete room;
    }
}

void Map::generateRooms() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            rooms[x * width + y] = new Room(x * width + y);
            if (x == 0) {
                if (y != 0) {
                    rooms[x * width + y]->connect(Direction::WEST, rooms[x * width + y - 1]);
                    rooms[x * width + y - 1]->connect(Direction::EAST, rooms[x * width + y]);
                }
            } else {
                rooms[x * width + y]-> connect(Direction::NORTH, rooms[(x - 1) * width + y]);
                rooms[(x - 1) * width + y]->connect(Direction::SOUTH, rooms[x * width + y]);
                if (y != 0) {
                    rooms[x * width + y]->connect(Direction::WEST, rooms[x * width + y - 1]);
                    rooms[x * width + y - 1]->connect(Direction::EAST, rooms[x * width + y]);
                }
            }
            srand(time(0));
            int randNum = rand() % (width * height - 1);
            if (randNum <= 12 && hazards < MAX_HAZARDS) {
                placeHazards(x, y);
            } else if (randNum <= 20 && weapons < MAX_WEAPONS) {
                placeWeapons(x, y);
            } else if (randNum <= 30 && mutantPlants == 0) {
                placeMutant(x, y);
            }
        }
    }
    if (hazards < MAX_HAZARDS) {
        int numHazards = 5;
        for (int i = 0; i < numHazards; i++) {
            getRandomEmptyRoom()->setHazard();
        }
    }
    if (mutantPlants == 0) {
        getRandomEmptyRoom()->setPlant();
    }
    if (weapons <= 1) {
        getRandomEmptyRoom()->setWeapon(weapons == 0);
    }
    getRandomEmptyRoom()->setPlayer();
}

void Map::placeHazards(int x, int y) {
    rooms[x * width + y]->setHazard();
    hazards++;
}

void Map::placeWeapons(int x, int y) {
    rooms[x * width + y]->setWeapon(weapons == 0);
    weapons++;
}

void Map::placeMutant(int x, int y) {
    rooms[x * width + y]->setPlant();
    mutantPlants++;
}

Room* Map::getRandomEmptyRoom() {
    do {
        srand(time(0));
        int randNum = rand() % (width * height - 1);
        if (rooms[randNum] -> isEmpty()) {
            return rooms[randNum];
        }
    }while (true);
}

void Map::display() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cout << getRoomAt(i, j)->getDisplayChar() << " ";
        }
        cout << endl;
    }

}

Room* Map::getRoomAt(int x, int y) const {
    if(x < 0 || x >= width || y < 0 || y >= height) {
        return nullptr;
    }
    return rooms[x * width + y];
}





