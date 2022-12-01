#ifndef SHARED_H
#define SHARED_H

#include <string>

struct Position {
    int row;
    int col;
};

enum Direction { UP, DOWN, LEFT, RIGHT, LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL, KNIGHT_UP_LEFT, KNIGHT_UP_RIGHT, KNIGHT_DOWN_LEFT, KNIGHT_DOWN_RIGHT, KNIGHT_LEFT_DOWN, KNIGHT_LEFT_UP, KNIGHT_RIGHT_DOWN, KNIGHT_RIGHT_UP };
enum Distance { ONE, INFINITE };
enum Colour { WHITE, BLACK };

#include <string>
#include <memory>

class InvalidInput {
    std::string message;

    public:
        InvalidInput(std::string message);
        void printMessage() const;

};

class Move {
    Position curPos;
    Position newPos;
    bool promotion; //whether the pawn is getting promoted
    char promoteTo; //what the pawn is getting promoted to

    int alphaToNum(char c);
    void convertFormat(std::string str, int counter);
    bool validPiece(char c);

    public:
        Move(std::string input);
        Position getCurPos() const;
        Position getNewPos() const;
        bool getPromotion() const;
        char getPromoteTo() const;
};

#endif
