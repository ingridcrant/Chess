// Move is a class that specfies a move (current position of piece to new position)
#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
    int curPos[1][1];
    int newPos[1][1];

    int alphaToNum(char c);

    public:
    Move(std::string input);
};


#endif

