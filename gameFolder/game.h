#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../shared.h"
#include "../pieces/board.h"

class Player;

enum gameStatus{IN_PLAY, CHECK, CHECKMATE};

class Game {
    Board board;
    std::vector<Move> pastMoves;
    Colour turn;
    std::vector<Player> players;
    gameStatus status;

    bool verifyProperSetup() const; //for at the end of customSetup

    public:
        Game();
        ~Game();
        void playGame(); //plays the game
        void customSetup(); //handles harness for custom game setup
};


#endif
