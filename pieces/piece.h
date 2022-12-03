#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "../shared.h"
#include "board.h"
#include <map>

class InvalidDirection {
    std::string message;

    public:
        InvalidDirection(std::string message);
        void printMessage() const;

};

class Piece {
    protected:
        Colour colour;
        char symbol;
        Distance dist;
        std::vector<Direction> directions;
        std::map<Position, MoveTypes> nextPositions;
        Position currPos;
        bool firstMove = true;
        bool specialCapture;

        virtual void generateNextPositions(Board* board, Move lastMove) = 0;
        std::map<Position, MoveTypes> allPosInDirection(Direction direction, Move lastMove, Board* board);
        bool validateMove(Position newPos, Board* board, Move lastMove);
        bool movePutsKingInCheck(Board* board, Move lastMove, Position newPos);

    public:
        Piece(Colour colour, char symbol, Position currPos, Distance dist, bool specialCapture);
        virtual ~Piece() = default;
        virtual Position getPos();
        virtual char getSymbol();
        virtual bool getSkipsTwo();
        virtual Colour getColour();
        virtual bool getFirstMove();
        virtual bool getInCheck();
        virtual void setInCheck(bool val);
        virtual void setPos(Position pos);
        virtual std::map<Position, MoveTypes> getNextPositions();
};

#endif
