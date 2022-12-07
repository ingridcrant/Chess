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
        int count = 0;

        std::map<Position, MoveTypes> allPosInDirection(Direction direction, Move* lastMove, int rows, int cols, std::vector<std::vector<Piece*>> board, bool checkIfKingInCheck = true);
        // bool validateMove(Position newPos, Board* board, Move* lastMove);
        bool movePutsKingInCheck(std::vector<std::vector<Piece*>> board, Move* lastMove, int rows, int cols, Position newPos, bool checkIfKingInCheck = true);

    public:
        Piece(Colour colour, char symbol, Position currPos, Distance dist, bool specialCapture);
        virtual ~Piece() = default;
        virtual Position getPos();
        virtual Distance getDist();
        virtual char getSymbol();
        virtual bool getSkipsTwo();
        virtual bool getSpecialCapture();
        virtual bool getFirstMove();
        virtual std::vector<Direction> getDirections();
        virtual Colour getColour();
        virtual bool getInCheck();
        virtual void setInCheck(bool val);
        virtual void setSkipsTwo(bool val);
        virtual void setPos(Position pos);
        virtual void notFirstMove();
        virtual void incrementCount();
        virtual int getCount();
        virtual std::map<Position, MoveTypes> getNextPositions();
        virtual void generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck = true) = 0;
        virtual void setDirections(std::vector<Direction> dirs);
        virtual void setDistance(Distance d);
};

#endif
