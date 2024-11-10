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

void Game::initialize(){
  this->map = new Map(6,6);
  this->gardener = new Gardener(map->getRandomEmptyRoom());
}

void Game::play(){
  while (gameOver == false) {
    //directions (n, s, e, w), w, m, q, and h
    cout << "Action: (M)ap, (N)orth, (S)outh, (E)ast, (W)est, (U)se Weapon, (H)elp, (Q)uit: " << endl;
    char action;
    cin >> action;
    processCommand(tolower(action));
  }
}

void Game::processCommand(char command){
  if (command == 'm'){
    map->display();
  } else if (command == 'h') {
    displayHelp();
  } else if (command == 'q') {
    endGame("Quitting Game");
  } else if(command == 'n') {
    gardener->move(Direction::NORTH);
  } else if(command == 's') {
    gardener->move(Direction::SOUTH);
  } else if(command == 'e') {
    gardener->move(Direction::EAST);
  } else if(command == 'w') {
    gardener->move(Direction::WEST);
  } else if(command == 'u'){
    cout << "which weapon would you like to use?" << endl;
    //gardener->displayInventory();
    char input;
    cin >> input;
    while (input != '1' || input != '2') {
      cout << "Invalid input, please enter the inventory index of your desired item" << endl;
      //gardener->displayInventory();
      cin >> input;
    }
    int weaponIndex = input;
    cout << "Item chosen, what direction would you like to use this item in? "
            "((N)orth, (S)outh, (E)ast, (W)est)" << endl;
    cin >> input;
    while (tolower(input) != 'n' || tolower(input) != 's'
      || tolower(input) != 'e' || tolower(input) != 'w') {
      cout << "Invalid input, please enter the direction you would like to use your item in "
              "((N)orth, (S)outh, (E)ast, (W)est)" << endl;
      cin >> input;
    }
    if (input == 'n') {
      gardener->useWeapon(weaponIndex, Direction::NORTH);
    } else if (input == 's') {
      gardener->useWeapon(weaponIndex, Direction::SOUTH);
    } else if (input == 'e') {
      gardener->useWeapon(weaponIndex, Direction::EAST);
    } else {
      gardener->useWeapon(weaponIndex, Direction::WEST);
    }
  }else {
    cout << "Invalid Action" << endl;
  }

}

void Game::displayStatus(){
  //TODO: need a method to get gardener's current room and then call getClues
  //gardener-> getCurrentRoom() -> getClues();
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
  //TODO: need a method to set gardener's current room to the new room
  //gardener-> setCurrentRoom(room);
}

