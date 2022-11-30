#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "subject.h"
#include "../shared.h"
#include "../pieces/board.h"
#include "../players/player.h"

enum gameStatus{IN_PLAY, CHECK, CHECKMATE};

class Game : public Subject{
    std::unique_ptr<Board> board;
    std::vector<Move> pastMoves;
    Colour turn;
    std::vector<Player> players;
    gameStatus status;

    bool verifyProperSetup() const; //for at the end of customSetup

    public:
        explicit Game(std::unique_ptr<Board> board, Player & playerOne, Player & playerTwo);
        ~Game() = default;
        virtual Piece * getState(int col, int row) const; //get state of one square on the board
        void playGame(); //plays the game
        void customSetup(); //handles harness for custom game setup
};


#endif
