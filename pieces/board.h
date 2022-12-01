#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "../shared.h"

class Move;
class Piece;

class InvalidMove {};

class Board {
    int boardRows = 8;
    int boardCols = 8;
    std::vector<std::vector<std::unique_ptr<Piece>>> board; //[col (letter)][row (int)]

    bool validMove(Piece * piece, Position curPos, Position newPos) const;

    public:
        Board(); 
        ~Board();
        int getRows();
        int getCols();
        Piece * getPieceAt(int col, int row) const;
        void changeBoard(Move move); //change state of board based on move

};

#endif

