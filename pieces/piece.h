#include <string>
#include <vector>
#include "../shared.h"
#include "board.h"

#ifndef PIECE
#define PIECE

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
        std::vector<Position> nextPositions;
        Position currPos;
        bool firstMove = true;
        bool specialCapture;

        virtual void generateNextPositions(Board* board) = 0;
        std::vector<Position> allPosInDirection(Direction direction, Board* board);
        bool validateMove(Position newPos);
    public:
        Piece(Colour colour, char symbol, Position currPos, Distance dist, bool specialCapture);
        virtual Position getPos();
        virtual char getSymbol();
        virtual bool getSkipsTwo();
};

#endif
