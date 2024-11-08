//
// Created by zagrad on 10/28/2024.
//

#include "Game.h"
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
    //m, q, and h
    cout << "Action: (M)ap, (H)elp, (Q)uit: " << endl;
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
  } else {
    cout << "Invalid Action" << endl;
  }


}

void Game::displayStatus(){

}

void Game::displayHelp(){
  cout << "Description:" << endl << "Equipped with potent spray bottle of herbicides, "
          "venture deep into the garden to eliminate the hiding mutant plant." << endl <<
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

}

