#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "../shared.h"

class Move;
class Piece;

class Board {
    int boardRows = 8;
    int boardCols = 8;
    std::vector<std::vector<std::shared_ptr<Piece>>> board; //[col (letter)][row (int)]
    std::vector<std::shared_ptr<Piece>> alivePieces; 

    bool validMove(Piece piece, Position curPos, Position newPos) const;

    public:
        Board(); 
        ~Board();
        std::vector<std::vector<std::shared_ptr<Piece>>> getBoard() const;
        void changeBoard(Move move); //change state of board based on move

};

#endif

