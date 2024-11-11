#include <iostream>
#include "Game.h"
using namespace std;



int main() {
    char input;
    cout << "Would you like to play in debug mode? (Y)es or (N)o" << endl;
    do {
        cin >> input;
        if (input != 'y' && input != 'n') {
            cout << "Invalid input, please enter 'y' for yes or 'n' for no." << endl;
            cin.clear();
            cin.ignore();
        }
    } while (input != 'y' && input != 'n');
    input = tolower(input);
    bool debug;
    if (input == 'y') {
        debug = true;
    } else {
        debug = false;
    }
    Game* game = new Game(debug);
    game->play();
    delete game;
    return 0;
    }