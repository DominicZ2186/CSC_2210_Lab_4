//
// Created by zagrad on 10/28/2024.
//

#include "Map.h"

#include "AcidPool.h"
#include "Spores.h"
#include "Spray.h"

Map::Map(int width, int height) {
    this -> width = width;
    this -> height = height;
    rooms.resize(width * height);
    for(auto& room : rooms) {
        room = nullptr;
    }
}

void Map::generateRooms() {



}

void Map::placeHazards(int x, int y) {

}

void Map::placeWeapons(int x, int y) {

}

void Map::placeMutant(int x, int y) {

}

void Map::getRandomEmptyRoom() {

}

void Map::display() {
    string symbols[] = {".", ">", "?","@", "+", "!"};
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int randomNum = (rand() % 6) + 1;
            if(randomNum == 1) {
                cout << symbols[0] << " ";
            }
            else if(randomNum == 2) {
                cout << symbols[2] << " ";
            }
            else if(randomNum == 3) {
                cout << symbols[3] << " ";
            }
            else if(randomNum == 4) {
                cout << symbols[4] << " ";
            }
            else  {
                cout << symbols[5] << " ";
            }
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





