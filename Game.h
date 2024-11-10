//
// Created by zagrad on 10/28/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Gardener.h"
#include <string>
#include <iostream>

class Gardener;
class Map;

/**
 * @class Game
 * @brief Manages the main game logic, including initialization, player actions, and game status.
 */
class Game {
private:
  Map* map;
  Gardener* gardener;
  bool gameOver;
  std::string gameOverMessage;
  bool debugMode;

public:
  /**
   * @brief Constructs a new Game instance.
   * @param debugMode Gives access to see the map if true.
   */
  Game(bool debugMode);

  /**
   * @brief Destructor for Game, responsible for freeing resources.
   */
  ~Game();

  /**
   * @brief Initializes the game, setting up the map and player.
   */
  void initialize();

  /**
   * @brief Runs the main game loop, processing player actions.
   */
  void play();

  /**
   * @brief Processes a single player command.
   * @param command The command character input by the player.
   */
  void processCommand(char command);

  /**
   * @brief Displays the current status of the game and player.
   */
  void displayStatus();

  /**
   * @brief Displays instructions and gameplay tips.
   */
  void displayHelp();

  /**
   * @brief Ends the game with a final message.
   * @param message The message to display upon game end.
   */
  void endGame(std::string message);

  /**
   * @brief Teleports the gardener to a random room on the map.
   */
  void teleportGardener();
};

#endif // GAME_H
