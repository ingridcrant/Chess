#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <memory>
#include <vector>

class Move;

class Board {
    std::unique_ptr<Piece> board[8][8];
    std::vector<std::unique_ptr<Piece> > alivePieces;

    public:
        Board(); 
        std::unique_ptr<Piece>** getBoard();
        void changeBoard(Move move); //change state of board based on move
};

#endif

