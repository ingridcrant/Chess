#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "subject.h"
#include "../shared.h"
#include "../pieces/board.h"
#include "../players/player.h"

enum gameStatus{IN_PLAY, CHECK, CHECKMATE};

class Game : public Subject {
    Board * board;
    std::vector<Move> pastMoves;
    Colour turn;
    std::vector<Player *> players;
    gameStatus status;

    bool verifyProperSetup() const; //for at the end of customSetup
    bool properColour(std::string colour) const;

    public:
        explicit Game(Board * board, Player * playerWhite, Player * playerBlack);
        ~Game() = default;
        virtual Piece * getState(int row, int col) const; //get state of one square on the board
        Colour playGame(bool draw); //plays the game and returns winner and passes in bool to determine if it's a draw
        void customSetup(); //handles harness for custom game setup
};


#endif
