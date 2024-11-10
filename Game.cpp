//
// Created by zagrad on 10/28/2024.
//

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(bool debugMode){
  this->debugMode = debugMode;
  this->gameOver = false;
  initialize();
}

Game::~Game() {
  delete map;
  delete gardener;
}

void Game::initialize(){
  this->map = new Map(6,6);
  this->gardener = new Gardener(map->getRandomEmptyRoom());
  gardener->setCurrentRoom(map->getRandomEmptyRoom());
}

void Game::play(){
  while (gameOver == false) {
    displayStatus();
    if (debugMode) {
      cout << "Action: (M)ap, (N)orth, (S)outh, (E)ast, (W)est, (U)se Weapon, (H)elp, (Q)uit: " << endl;
    } else {
      cout << "Action: (N)orth, (S)outh, (E)ast, (W)est, (U)se Weapon, (H)elp, (Q)uit: " << endl;
    }
    char action;
    cin >> action;
    processCommand(tolower(action));
  }
}

void Game::processCommand(char command){
  if (command == 'm') {
    if (debugMode) {
      map->display();
    } else {
      cout << "Map display is unavailable" << endl;
    }
  } else if (command == 'h') {
    displayHelp();
  } else if (command == 'q') {
    endGame("Quitting Game");
  } else if(command == 'n') {
    gardener->move(Direction::NORTH, this);
  } else if(command == 's') {
    gardener->move(Direction::SOUTH, this);
  } else if(command == 'e') {
    gardener->move(Direction::EAST, this);
  } else if(command == 'w') {
    gardener->move(Direction::WEST, this);
  } else if(command == 'u'){
    cout << "which weapon would you like to use?" << endl;
    gardener->displayInventory();
    int input;
    do {
      cin >> input;
      if (input != 1 && input != 2 ) {
        cout << "Invalid input, please enter the inventory index of the desired weapon to use" << endl;
        gardener->displayInventory();
        cin.clear();
        cin.ignore();
      }
      if (gardener-> getWeaponAt(input) == nullptr) {
        cout << "That inventory space is empty, maybe you could find something to fill it..." << endl;
        input = 3;
        cout << "Please enter the inventory index of the desired weapon to use" << endl;
        gardener->displayInventory();
      }
    } while (input != 1 && input != 2);
    int weaponIndex = input - 1;
    cout << "Item chosen, what direction would you like to use this item in? "
            "((N)orth, (S)outh, (E)ast, (W)est)" << endl;
    char direction;
    do {
      cin >> direction;
      direction = tolower(direction);
      if (direction != 'n' && direction != 's' && direction != 'e' && direction != 'w') {
        cout << "Invalid input, please enter a valid direction ((N)orth, (S)outh, (E)ast, (W)est)" << endl;
      }
    } while(direction != 'n' && direction != 's' && direction != 'e' && direction != 'w');
    if (direction == 'n') {
      gardener->useWeapon(weaponIndex, Direction::NORTH, this);
    } else if (direction == 's') {
      gardener->useWeapon(weaponIndex, Direction::SOUTH, this);
    } else if (direction == 'e') {
      gardener->useWeapon(weaponIndex, Direction::EAST, this);
    } else {
      gardener->useWeapon(weaponIndex, Direction::WEST, this);
    }
  }else {
    cout << "Invalid Action" << endl;
  }

}

void Game::displayStatus(){
  gardener-> getCurrentRoom() -> getClues();
}

void Game::displayHelp(){
  cout << "Description:" << endl << "Equipped with potent spray bottle of herbicides, "
          "venture deep into the garden to exterminate the hiding mutant plant." << endl <<
          "Use your keen senses to find useful items like the garden shears "
          "and avoid fatal hazards such as acid pools and spores" << endl;
  cout << endl << "Gameplay:" << endl << "1) Use the N, S, E, and W keys to move around the map in the "
          "directions of North, South, East, and West respectively." << endl <<
            "2) Use your spray bottle to try and eliminate the mutant plant, " << endl <<
            "however use it wisely as it has only a certain amount of uses unlike "
            "the garden shears which has unlimited uses" << endl <<
              "3) With each movement you are given clues that tell you "
              "about what lies in the rooms around you" << endl;
}

void Game::endGame(string message){
  cout << message << endl;
  gameOver = true;
}

void Game::teleportGardener(){
  Room *room = map->getRandomEmptyRoom();
  gardener-> setCurrentRoom(room);
}