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
    Piece * kingWhite = nullptr;
    Piece * kingBlack = nullptr;

    bool validMove(Piece* piece, Move* lastMove, Position curPos, Position newPos);
    void updateKingPointer(Position pos); //update king pointer is king was moved

    public:
        Board(); 
        ~Board() = default;
        int getRows();
        int getCols();
        Piece* getKingWhite();
        Piece* getKingBlack();
        Piece * getPieceAt(int row, int col) const;
        std::vector<std::vector<Piece*>> copyBoard() const;
        void resetBoard();
        void changeBoard(Move move, Move* lastMove); //change state of board based on move
        void changeBoard(Position pos); //for removing a piece from that position
        void changeBoard(char piece, Position pos); //for placing piece in that position
        void boardInCheck(Colour colour) const; //whether colour is in check
        bool boardInCheckmate(Colour colour) const;
        bool boardInStalemate(Colour colour) const;
        void generateAllMoves(Move* lastMove) const;
};

#endif

