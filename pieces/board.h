#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "../shared.h"

class Move;
class Piece;

class Board {
    std::unique_ptr<Piece> board[8][8]; //[col (letter)][row (int)]
    std::vector<std::unique_ptr<Piece>> alivePieces;

    bool validMove(Piece piece, Position curPos, Position newPos) const;

    public:
        Board(); 
        ~Board();
        std::unique_ptr<Piece>** getBoard() const;
        void changeBoard(Move move); //change state of board based on move

};

#endif

