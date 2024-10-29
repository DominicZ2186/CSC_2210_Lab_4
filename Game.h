//
// Created by zagrad on 10/28/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Gardener.h"
#include <string>

using namespace std;

class Game {
private:
  Map* map;
  Gardener* gardener;
  bool gameOver;
  string gameOverMessage;
  bool debugMode;
public:
  Game(bool debugMode);
  void initialize();
  void play();
  void processCommand(char command);
  void displayStatus();
  void displayHelp();
  void endGame(string message);
  void teleportGardener();
};



#endif //GAME_H