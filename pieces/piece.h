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
        std::shared_ptr<Board> board;
        std::vector<Position> nextPositions;
        Position currPos;
        bool firstMove = true;
        bool specialCapture;
        
        std::vector<Position> allPosInDirection(Direction direction);
        virtual void generateNextPositions() = 0;
        bool validateMove(Position newPos);
    public:
        Piece(Colour colour, char symbol, std::shared_ptr<Board> board, Position currPos, Distance dist, bool specialCapture);
};

#endif
